#include "gpio/gpio.h"
#include "thread.h"


uint8_t thread1Stack[1024];

void runGreenLed(void)
{
    const struct GpioPin gpioPinA4 = {.gpioPort = PORT_A, .pinNumber = 4};
    gpio_init(gpioPinA4, OUTPUT);
    gpio_on(gpioPinA4);

    thread_sleep(1000);
    gpio_toggle(gpioPinA4);
}

//uint8_t thread2Stack[1024];
//
//void runRedLed(void)
//{
//    const struct GpioPin gpioPinA1 = {.gpioPort = PORT_A, .pinNumber = 1};
//    gpio_init(gpioPinA1, OUTPUT);
//    gpio_on(gpioPinA1);
//
//    gpio_toggle(gpioPinA1);
//    thread_sleep(1000);
//}

int main(void)
{
    thread_create(thread1Stack, sizeof(thread1Stack), 1, &runGreenLed);
//    thread_create(thread2Stack, sizeof(thread2Stack), &runRedLed);

    return 0;
}
