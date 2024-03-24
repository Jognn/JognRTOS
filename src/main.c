
#include "gpio.h"
#include "sleep.h"


int sanity_flag;

int main(void)
{
    const struct GpioPin gpioPin = {.gpioPort = PORT_A, .pinNumber = 4};
    gpio_init(gpioPin, OUTPUT);
    gpio_on(gpioPin);

    sanity_flag = 102;
    while (1)
    {
    }
    return 0;
}
