#ifndef SENSOR_MANAGER_H
#define SENSOR_MANAGER_H

#include "TYPES_H.h"
#include "DHT11_DRIVER_H.h"
#include "LDRDRIVER_H.h"
#include "PIRDRIVER_H.h"

class SensorManager
{
public:
    void begin();
    void update();

    float getTemperature();
    float getHumidity();
    int getLight();
    int getMotion();

private:
    DHT11Driver dht;
    LDRDriver ldr;
    PIRDriver pir;

    SensorData sensorData;   
};

#endif
