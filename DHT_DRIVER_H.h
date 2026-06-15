#ifndef DHT11_DRIVER_H
#define DHT11_DRIVER_H

class DHT11Driver
{
public:
    void begin();
    float getTemperature();
    float getHumidity();
};

#endif
