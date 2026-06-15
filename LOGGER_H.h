#ifndef LOGGER_H
#define LOGGER_H

#include "SENSOR_MANAGER_H.h"
#include "ENERGY_MANAGER_H.h"

class Logger
{
public:
    void begin();
    void log(SensorManager &sensorManager, EnergyManager &energyManager);
};

#endif
