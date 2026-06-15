#include <Arduino.h>
#include "CONFIG_H.h"
#include "PIRDRIVER_H.h"


void PIRDriver::begin()
{
    pinMode(PIR_PIN, INPUT);
}

int PIRDriver::getMotionStatus()
{
    return digitalRead(PIR_PIN);
}
