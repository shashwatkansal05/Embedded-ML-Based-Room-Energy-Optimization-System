#ifndef ENERGY_MANAGER_H
#define ENERGY_MANAGER_H

#include "SENSOR_MANAGER_H.h"

class EnergyManager
{
public:
    enum SystemMode
    {
        ENERGY_SAVING,
        IDLE,
        ACTIVE
    };

    void begin();
    void update(SensorManager &sensorManager);
    SystemMode getMode();

private:
    SystemMode currentMode;
};

#endif
