#include "ENERGY_MANAGER_H.h"

void EnergyManager::begin()
{
    currentMode = IDLE;
}

void EnergyManager::update(SensorManager &sm)
{
    float temp = sm.getTemperature();
    float humidity  = sm.getHumidity();
    int light  = sm.getLight();
    int motion = sm.getMotion();

    // -------------------------
    // ZONE 1: VERY LOW LIGHT (DARK ROOM)
    // -------------------------
    if (light <= 1147)
    {
        if (motion == 0)
        {
            currentMode = ENERGY_SAVING;
        }
        else
        {
            currentMode = ACTIVE;
        }
    }

    // -------------------------
    // ZONE 2: MEDIUM LIGHT
    // -------------------------
    else if (light <= 2048)
    {
        if (motion == 1)
        {
            currentMode = ACTIVE;
        }
        else
        {
            currentMode = IDLE;
        }
    }

    // -------------------------
    // ZONE 3: VERY BRIGHT ROOM
    // -------------------------
    else
    {
        if (humidity > 63.7)
        {
            currentMode = IDLE;
        }
        else if (motion == 0)
        {
            currentMode = ENERGY_SAVING;
        }
        else
        {
            currentMode = IDLE;
        }
    }
}

EnergyManager::SystemMode EnergyManager::getMode()
{
    return currentMode;
}
