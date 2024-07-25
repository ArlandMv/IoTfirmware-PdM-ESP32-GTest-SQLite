#include <WiFi.h>
//#include <WiFiClientSecure.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <ArduinoJson.h>
#include <HTTPClient.h>
#include "secrets.h"

#define DHTPIN 4       // Pin connected to the DHT sensor
#define DHTTYPE DHT22  // DHT11 or DHT22

const char* ssid = "ingenieria";    //"your_SSID";
const char* password = "iping2024"; //"your_PASSWORD";

// SUPABASE DETAILS
//const char* supabaseUrl = "https://abc...supabase.co/rest/v1/iot_data";
//const char* apikey = YOUR_API_KEY;
const char* supabaseUrl = API_URL;
const char* apikey = API_KEY;
const int port = 443; //Use 80 or 443 for HTTPS, but here we are using HTTP
const char* endpoint = "/rest/v1/iot_data"; //reformat out of URL

// GLOBAL INSTANCES
DHT dht (DHTPIN,DHTTYPE);
//SensorManager sensorManager(DHTPIN, DHTTYPE);
//WiFiManager wifiManager(ssid, password);
//ApiClient apiClient();
// Initialize WiFi and HTTP client
WiFiClient wifi;  //WiFiClientSecure wifiSecure;
HTTPClient client; //HttpClient client = HttpClient(wifi, supabaseUrl, port);

// VARIABLES
unsigned long previousMillis = 0;
const long interval = 5000; // 10min 600000
// json values
String macAddress;
float temperature = 22.5;
float humidity = 60.5;
String message;

// DECLARATIONS 
void connectToWiFi();
void getDummyData(float &humidity, float &temperature);
String createJSONPayload(const char* deviceTag, float temperature, float humidity);
void sendSensorData(String payload);
//void sendSensorData(HttpClient& client, const char* endpoint, const char* apiKey);

void setup() {
    Serial.begin(115200);
     connectToWiFi();
     //wifiSecure.setFingerprint(fingerprint); // Set the SSL fingerprint
    //dht.setup(pinDHT,DHTesp::DHTTYPE);
    //sensorManager.begin();
    //wifiManager.connect();
    macAddress = WiFi.macAddress();
    Serial.print("macAddress: ");
    Serial.println(macAddress);
}

void loop() {
    unsigned long currentMillis = millis();
    bool requestInProgress = false;
    message="";
    // ( interval && !requestInProgress)
    if (currentMillis - previousMillis >= interval) {
        previousMillis = currentMillis;
        Serial.print("currentMillis: ");
        Serial.println(currentMillis);

        //float humidity = sensorManager.readHumidity();
        //float temperature = sensorManager.readTemperature();
        getDummyData(humidity,temperature);
        //humidity = dht.readHumidity();
        //temperature = dht.readTemperature();

        if (isnan(humidity) || isnan(temperature)) {
            Serial.println("Failed to read from DHT sensor!");
            message="Failed to read from DHT sensor!";
            return;
        }
        Serial.print("Humidity: ");
        Serial.print(humidity);
        Serial.print(" %\t");
        Serial.print("Temperature: ");
        Serial.print(temperature);
        Serial.println(" *C");

        //apiClient.sendData(temperature, humidity);
        String json = createJSONPayload("device_test", temperature, humidity);
        Serial.print("Payload: ");
        Serial.println(json);
        sendSensorData(json); // Send sensor data to Supabase
    }
}

// DEFINITIONS
void sendSensorData(String payload) {
    if(WiFi.status()!= WL_CONNECTED){
        Serial.println("wifi error");
    }
    client.begin(supabaseUrl); //API_URL
    client.addHeader("apikey", apikey);

    int statusCode = client.POST(payload);
    Serial.print("Status code: ");
    Serial.println(statusCode);
    client.end();

    /*int statusCode = client.responseStatusCode();
    String response = client.responseBody();*/
}

String createJSONPayload(const char* deviceTag, float temperature, float humidity) {
    StaticJsonDocument<200> jsonDoc;
    jsonDoc["device_tag"] = deviceTag;
    jsonDoc["temperature"] = temperature;
    jsonDoc["humidity"] = humidity;

    char jsonBuffer[256];
    serializeJson(jsonDoc, jsonBuffer);

    return String(jsonBuffer);
}

void getDummyData(float &humidity, float &temperature) {
    float variacion = random(-1, 2);
    temperature += variacion;
    humidity +=  variacion;
}

void connectToWiFi() {
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
        Serial.println("Connecting to WiFi...");
    }
    Serial.println("Connected to WiFi");
}