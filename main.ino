#include <Arduino.h>

#include "CONFIG_H.h"
#include "SENSOR_MANAGER_H.h"
#include "ENERGY_MANAGER_H.h"
#include "OLED_DRIVER_H.h"
#include "SCHEDULER_H.h"
#include "LOGGER_H.h"


SensorManager sensorManager;
EnergyManager energyManager;
OLEDDriver oled;
Scheduler scheduler;
Logger logger;

void setup()
{
    Serial.begin(115200);

   
    pinMode(GREEN_LED, OUTPUT);
    digitalWrite(GREEN_LED, LOW);

   
    sensorManager.begin();
    energyManager.begin();
    oled.begin();
    scheduler.begin();
    logger.begin();
}


void loop()
{
    // 1. Update sensors
    sensorManager.update();

    // 2. Run energy decision logic
    energyManager.update(sensorManager);

    // 3. Get system mode
    EnergyManager::SystemMode mode = energyManager.getMode();

    // -------------------------
    // LED CONTROL (FINAL FIX)
    // -------------------------
    if (mode == EnergyManager::ACTIVE)
    {
        digitalWrite(GREEN_LED, HIGH);
    }
    else if (mode == EnergyManager::IDLE)
    {
        digitalWrite(GREEN_LED, HIGH);
    }
    else // ENERGY_SAVING
    {
        digitalWrite(GREEN_LED, LOW);
    }

    // 4. OLED display update
    oled.update(sensorManager, energyManager);

    // 5. Logging
    logger.log(sensorManager, energyManager);

    // 6. Scheduler tasks
    scheduler.run(sensorManager, logger, energyManager);

    
    delay(200);
}
