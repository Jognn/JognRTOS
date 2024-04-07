#ifndef JOGNRTOS_GPIO_H
#define JOGNRTOS_GPIO_H

#include <stdint.h>


enum GpioPort
{
    PORT_A = 0,
    PORT_B,
    PORT_C,
    PORT_D,
    PORT_E,
    PORT_F,
    PORT_G,
    PORT_H
};

struct GpioPin
{
    enum GpioPort gpioPort;
    uint16_t pinNumber;
};

enum GpioMode
{
    INPUT = 0,
    OUTPUT = 1,
    ALTERNATE_FUNCTION = 2,
    ANALOG = 3
};


void gpio_init(struct GpioPin pin, enum GpioMode mode);

void gpio_on(struct GpioPin pin);

void gpio_off(struct GpioPin pin);

void gpio_toggle(struct GpioPin pin);


#endif //JOGNRTOS_GPIO_H
