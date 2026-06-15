#include <Arduino.h>
#include "LOGGER_H.h"

void Logger::begin()
{
    Serial.begin(115200);

    // CSV header for ML dataset
    //Serial.println("time,temp,humidity,light,motion,mode");
}

void Logger::log(SensorManager &sensorManager, EnergyManager &energyManager)
{
    // 1. Timestamp
    unsigned long timeStamp = millis();

    // 2. Sensor data snapshot
    float temp = sensorManager.getTemperature();
    float hum  = sensorManager.getHumidity();
    int light  = sensorManager.getLight();
    int motion = sensorManager.getMotion();

    // 3. System mode
    EnergyManager::SystemMode mode = energyManager.getMode();

    // 4. Convert enum → numeric label (important for ML)
    int modeValue;

    switch (mode)
    {
        case EnergyManager::ENERGY_SAVING:
            modeValue = 0;
            break;

        case EnergyManager::IDLE:
            modeValue = 1;
            break;

        case EnergyManager::ACTIVE:
        default:
            modeValue = 2;
            break;
    }

    // 5. CSV output (single line)
    //Serial.print(timeStamp);
    //Serial.print(",");
    //Serial.print(temp);
    //Serial.print(",");
    //Serial.print(hum);
    //Serial.print(",");
    //Serial.print(light);
    //Serial.print(",");
    //Serial.print(motion);
    //Serial.print(",");
    //Serial.println(modeValue);
}
