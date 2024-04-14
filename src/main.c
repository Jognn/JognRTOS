#include "systick.h"
#include "gpio/gpio.h"


int main(void)
{
    systick_init(1000);

    const struct GpioPin gpioPinA4 = {.gpioPort = PORT_A, .pinNumber = 4};
    gpio_init(gpioPinA4, OUTPUT);
    gpio_on(gpioPinA4);

    const struct GpioPin gpioPinA1 = {.gpioPort = PORT_A, .pinNumber = 1};
    gpio_init(gpioPinA1, OUTPUT);
    gpio_on(gpioPinA1);

    while (1)
    {
        systick_sleep(1000);
        gpio_toggle(gpioPinA4);
        gpio_toggle(gpioPinA1);
    }
    return 0;
}
