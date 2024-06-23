#ifndef JOGNRTOS_ARM_CMSIS_H
#define JOGNRTOS_ARM_CMSIS_H

#include <stdint.h>


static inline __attribute__((always_inline)) uint32_t __get_CONTROL(void)
{
    uint32_t controlRegisterValue;
    asm volatile ("MRS %[control_value], CONTROL" : [control_value] "=r" (controlRegisterValue) : );
    return controlRegisterValue;
}

static inline __attribute__((always_inline)) void __set_CONTROL(uint32_t newControlValue)
{
    asm volatile ("MSR CONTROL, %[new_control]" : : [new_control] "r" (newControlValue));
}

static inline __attribute__((always_inline)) void __set_PSP(uint32_t pspValue)
{
    asm volatile ("MSR PSP, %[new_psp]" : : [new_psp] "r" (pspValue));
}



#endif //JOGNRTOS_ARM_CMSIS_H
