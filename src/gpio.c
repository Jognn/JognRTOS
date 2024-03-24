
#include "gpio.h"

#include "gpio_internal.h"
#include "sleep.h"


void gpio_init(const struct GpioPin pin, const enum GpioPinMode mode)
{
    if (pin.pinNumber > MAXIMAL_PIN_NUMBER)
    {
        return;
    }

    // TODO: Maybe whether it has been already enabled?
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
    volatile uint16_t* const outputDataRegister = (volatile uint16_t*) GPIO_A_BSRR_ADDR;
    *outputDataRegister |= (1 << pin.pinNumber);
}

void gpio_off(struct GpioPin pin)
{
    // TODO: We should probably check whether this pin is configured as OUTPUT
    volatile uint16_t* const outputDataRegister = (volatile uint16_t*) GPIO_A_BSRR_ADDR;
    *outputDataRegister &= ~(1 << pin.pinNumber);
}

void gpio_toggle(struct GpioPin pin)
{
    // TODO: Not really sure if this actually works...
    // TODO: We should probably check whether this pin is configured as OUTPUT
    volatile uint16_t* const outputDataRegister = (volatile uint16_t*) GPIO_A_BSRR_ADDR;
    *outputDataRegister ^= (1 << pin.pinNumber);
}