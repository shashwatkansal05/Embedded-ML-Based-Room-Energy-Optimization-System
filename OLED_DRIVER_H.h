#ifndef OLED_DRIVER_H
#define OLED_DRIVER_H

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#include "SENSOR_MANAGER_H.h"
#include "ENERGY_MANAGER_H.h"

class OLEDDriver
{
public:
    void begin();
    void update(SensorManager &sensorManager, EnergyManager &energyManager);

private:
    Adafruit_SSD1306 display = Adafruit_SSD1306(128, 64, &Wire, -1);
};

#endif
