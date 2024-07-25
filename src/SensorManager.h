#ifndef SENSOR_MANAGER_H
#define SENSOR_MANAGER_H

#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>

class SensorManager {
public:
    SensorManager(uint8_t pin, uint8_t type);
    void begin();
    float readTemperature();
    float readHumidity();

private:
    DHT dht;
};

#endif // SENSOR_MANAGER_H
