#include "gpio.h"

#include "gpio_internal.h"


static void primitive_sleep(unsigned iterations)
{
    for (unsigned i = 0; i < iterations; ++i);
}

void gpio_init(const struct GpioPin pin, const enum GpioMode mode)
{
    if (pin.pinNumber > MAXIMAL_PIN_NUMBER)
    {
        return;
    }

    volatile uint32_t* const rccAhbRegister = (volatile uint32_t*) (RCC_AHB2_ENR_ADDR);
    *rccAhbRegister |= 1 << 0;
    primitive_sleep(5);

    volatile uint32_t* const gpioModeRegister = (volatile uint32_t*) GPIO_A_MODER_ADDR;
    uint32_t currentRegisterValue = *gpioModeRegister;
    currentRegisterValue &= ~(3 << pin.pinNumber * 2);
    currentRegisterValue |= (mode << (pin.pinNumber * 2));

    *gpioModeRegister = currentRegisterValue;
}

void gpio_on(struct GpioPin pin)
{
    // TODO: We should probably check whether this pin is configured as OUTPUT
    volatile uint16_t* const outputDataRegister = (uint16_t*) GPIO_A_OUTPUT_DATA_ADDR;
    *outputDataRegister |= (1 << pin.pinNumber);
}

void gpio_off(struct GpioPin pin)
{
    // TODO: We should probably check whether this pin is configured as OUTPUT
    volatile uint16_t* const outputDataRegister = (uint16_t*) GPIO_A_OUTPUT_DATA_ADDR;
    *outputDataRegister &= ~(1 << pin.pinNumber);
}

void gpio_toggle(struct GpioPin pin)
{
    // TODO: We should probably check whether this pin is configured as OUTPUT
    volatile uint16_t* const outputDataRegister = (uint16_t*) GPIO_A_OUTPUT_DATA_ADDR;
    *outputDataRegister ^= (1 << pin.pinNumber);
}