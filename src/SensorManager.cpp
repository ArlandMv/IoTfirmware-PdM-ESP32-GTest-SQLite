#include "SensorManager.h"

SensorManager::SensorManager(uint8_t pin, uint8_t type) : dht(pin, type) {}

void SensorManager::begin() {
    dht.begin();
}

float SensorManager::readTemperature() {
    return dht.readTemperature();
}

float SensorManager::readHumidity() {
    return dht.readHumidity();
}
