#include <stdint.h>


#define PROCESSOR_CLOCK (4000000U)
#define PROCESSOR_EXTERNAL_CLOCK (PROCESSOR_CLOCK/8)

#define SYST_CSR 0xE000E010 // SysTick control and Status Register
#define SYST_RVR 0xE000E014 // SysTick Reload Value Register
#define SYST_CVR 0xE000E018 // SysTick Current Value Register
#define SYST_CALIB 0xE000E01C // Systick Calibration Value Register


static volatile unsigned systickCounter = 0;

void SysTick_Handler(void)
{
    ++systickCounter;
}


void systick_init(unsigned systick_hz)
{
    volatile uint32_t* const systickRvr = (uint32_t*) SYST_RVR;
    const uint32_t reloadValue = (PROCESSOR_EXTERNAL_CLOCK / systick_hz) - 1;
    *systickRvr |= reloadValue;

    volatile uint32_t* const systickCvr = (uint32_t*) SYST_CVR;
    *systickCvr &= ~0x00FFFFFF;

    volatile uint32_t* const systickCsr = (uint32_t*) SYST_CSR;
    // Use external clock
    *systickCsr |= ~(1 << 2);
    // Enable the SysTick exception
    *systickCsr |= (1 << 1);
    // Enable the counter
    *systickCsr |= (1 << 0);
}


void systick_sleep(unsigned milliseconds)
{
    const unsigned endCounter = systickCounter + milliseconds;
    while (systickCounter < endCounter);
}
