#include <Arduino.h>
#include "CONFIG_H.h"
#include "LDRDRIVER_H.h"

void LDRDriver::begin()
{
    pinMode(LDR_PIN, INPUT);
}

int LDRDriver::getLightLevel()
{
    long sum = 0;

    for (int i = 0; i < 10; i++)
    {
        sum += analogRead(LDR_PIN);
        delay(2);
    }

    return sum / 10;
}
