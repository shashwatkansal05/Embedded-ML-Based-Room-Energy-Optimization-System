#include "DHT11_DRIVER_H.h"
#include "CONFIG_H.h"

#include <DHT.h>

static DHT dht(DHT_PIN, DHT11);

void DHT11Driver::begin()
{
    dht.begin();
}

float DHT11Driver::getTemperature()
{
    return dht.readTemperature();
}

float DHT11Driver::getHumidity()
{
    return dht.readHumidity();
}
