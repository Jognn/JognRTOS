#include "io_stuff.h"


int a;
int x = 2;

void wait(unsigned iterations)
{
    for(unsigned i = 0; i < iterations; ++i);
}

int main(void)
{
    /*
     * Turning on the LED A04
     *
     * After each device reset, all peripheral clocks are disabled (except for the SRAM1/2 and
       Flash memory interface). Before using a peripheral you have to enable its clock in the
       RCC_AHBxENR and the RCC_APBxENR registers.

       Each peripheral clock can be enabled by the xxxxEN bit of the RCC_AHBxENR,
       RCC_APBxENRy registers.

     * 1) Enable the AHB2 clock (no AHP clock to be enabled, right?)
     * 2) Wait two clock cycles before setting the pin?
     *
     *
     * 3)
     *
     */

	x = 100+2;
    a = 1;

    volatile uint32_t* changeRCCAhbRegister = (volatile uint32_t*)(RCC_AHB2_ENR_ADDR);
    *changeRCCAhbRegister |= 1 << 0;
    wait(10);

    volatile uint32_t* changeModeRegister = (volatile uint32_t*)GPIO_A_MODER_ADDR;
    *changeModeRegister &= ~(1 << 9);

    volatile uint16_t* const outputDataRegister = (volatile uint16_t *)GPIO_A_BSRR_ADDR;
    *outputDataRegister = 1 << 4;

    while(1)
	{

    }
	return 0;
}
