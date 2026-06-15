#include <Wire.h>
#include "OLED_DRIVER_H.h"

void OLEDDriver::begin()
{
    if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C))
    {
        while (1); // stop if OLED fails
    }

    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(WHITE);
}

void OLEDDriver::update(SensorManager &sm, EnergyManager &em)
{
    display.clearDisplay();

    // -------------------------
    // LINE 1: TEMP + HUMIDITY
    // -------------------------
    display.setCursor(0, 0);
    display.print("T:");
    display.print(sm.getTemperature());
    display.print(" H:");
    display.print(sm.getHumidity());

    // -------------------------
    // LINE 2: LIGHT
    // -------------------------
    display.setCursor(0, 16);
    display.print("Light: ");
    display.print(sm.getLight());

    // -------------------------
    // LINE 3: MOTION
    // -------------------------
    display.setCursor(0, 32);
    display.print("Motion: ");
    display.print(sm.getMotion());

    // -------------------------
    // LINE 4: MODE (MAIN OUTPUT)
    // -------------------------
    display.setCursor(0, 48);

    switch (em.getMode())
    {
        case EnergyManager::ACTIVE:
            display.print("MODE: ACTIVE");
            break;

        case EnergyManager::IDLE:
            display.print("MODE: IDLE");
            break;

        case EnergyManager::ENERGY_SAVING:
            display.print("MODE: SAVE");
            break;
    }

    display.display();
}
