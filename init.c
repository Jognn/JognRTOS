#include <stdint.h>

#define SRAM_BEGIN 0x20000000U
#define SRAM_SIZE (96U * 1024U)
#define SRAM_END ((SRAM_BEGIN) + (SRAM_SIZE))

#define STACK_START SRAM_END

// Symbols extracted from the linker script (stm32l476_ls.ld)
extern uint32_t _end_text;
extern uint32_t _start_data;
extern uint32_t _end_data;
extern uint32_t _start_bss;
extern uint32_t _end_bss;

void Reset_Handler();
void Default_Handler();

void NMI_Handler() 		        __attribute__((weak, alias("Default_Handler")));
void HardFault_Handler()   	    __attribute__((weak, alias("Default_Handler")));
void MemManage_Handler() 	    __attribute__((weak, alias("Default_Handler")));
void BusFault_Handler() 	    __attribute__((weak, alias("Default_Handler")));
void UsageFault_Handler() 	    __attribute__((weak, alias("Default_Handler")));
void SVCall_Handler()	        __attribute__((weak, alias("Default_Handler")));
void Debug_Handler()	        __attribute__((weak, alias("Default_Handler")));
void PendSV_Handler() 	        __attribute__((weak, alias("Default_Handler")));
void SysTick_Handler()	        __attribute__((weak, alias("Default_Handler")));
void WWDG_IRQ_Handler()	        __attribute__((weak, alias("Default_Handler")));
void PVD_PVM_IRQ_Handler()	    __attribute__((weak, alias("Default_Handler")));
void RTC_STAMP_IRQ_Handler()	__attribute__((weak, alias("Default_Handler")));
void RTC_WKUP_IRQ_Handler()	    __attribute__((weak, alias("Default_Handler")));
void Flash_IRQ_Handler()	    __attribute__((weak, alias("Default_Handler")));
void RCC_IRQ_Handler()	        __attribute__((weak, alias("Default_Handler")));
void EXTI0_IRQ_Handler()	    __attribute__((weak, alias("Default_Handler")));
void EXTI1_IRQ_Handler()	    __attribute__((weak, alias("Default_Handler")));
void EXTI2_IRQ_Handler()	    __attribute__((weak, alias("Default_Handler")));
void EXTI3_IRQ_Handler()	    __attribute__((weak, alias("Default_Handler")));
void EXTI4_IRQ_Handler()	    __attribute__((weak, alias("Default_Handler")));
void DMA1_CH1_IRQ_Handler()	    __attribute__((weak, alias("Default_Handler")));
void DMA1_CH2_IRQ_Handler()	    __attribute__((weak, alias("Default_Handler")));
void DMA1_CH3_IRQ_Handler()	    __attribute__((weak, alias("Default_Handler")));
void DMA1_CH4_IRQ_Handler()	    __attribute__((weak, alias("Default_Handler")));
void DMA1_CH5_IRQ_Handler()	    __attribute__((weak, alias("Default_Handler")));
void DMA1_CH6_IRQ_Handler()	    __attribute__((weak, alias("Default_Handler")));
void DMA1_CH7_IRQ_Handler()	    __attribute__((weak, alias("Default_Handler")));
void ADC1_2_IRQ_Handler()	    __attribute__((weak, alias("Default_Handler")));
void CAN1_TX_IRQ_Handler()	    __attribute__((weak, alias("Default_Handler")));
void CAN1_RX0_IRQ_Handler()	    __attribute__((weak, alias("Default_Handler")));
void CAN1_SCE_IRQ_Handler()	    __attribute__((weak, alias("Default_Handler")));
void EXTI9_5_IRQ_Handler()	    __attribute__((weak, alias("Default_Handler")));
void TIM1_BRK_IRQ_Handler()	    __attribute__((weak, alias("Default_Handler")));
void TIM1_UP_IRQ_Handler()	    __attribute__((weak, alias("Default_Handler")));
void TIM1_TRG_COM_IRQ_Handler()	__attribute__((weak, alias("Default_Handler")));
void TIM1_CC_IRQ_Handler()	    __attribute__((weak, alias("Default_Handler")));
void TIM2_IRQ_Handler()	        __attribute__((weak, alias("Default_Handler")));
void TIM3_IRQ_Handler()	        __attribute__((weak, alias("Default_Handler")));
void TIM4_IRQ_Handler()	        __attribute__((weak, alias("Default_Handler")));
void I2C1_EV_IRQ_Handler()	    __attribute__((weak, alias("Default_Handler")));
void I2C1_ER_IRQ_Handler()	    __attribute__((weak, alias("Default_Handler")));
void I2C2_EV_IRQ_Handler()	    __attribute__((weak, alias("Default_Handler")));
void I2C2_ER_IRQ_Handler()	    __attribute__((weak, alias("Default_Handler")));
void SPI1_IRQ_Handler()	        __attribute__((weak, alias("Default_Handler")));
void SPI2_IRQ_Handler()	        __attribute__((weak, alias("Default_Handler")));
void USART1_IRQ_Handler()	    __attribute__((weak, alias("Default_Handler")));
void USART2_IRQ_Handler()	    __attribute__((weak, alias("Default_Handler")));
void USART3_IRQ_Handler()	    __attribute__((weak, alias("Default_Handler")));
void EXTI15_10_IRQ_Handler()	__attribute__((weak, alias("Default_Handler")));
void RTC_ALARM_IRQ_Handler()	__attribute__((weak, alias("Default_Handler")));
void DFSDM1_FLT3_IRQ_Handler()	__attribute__((weak, alias("Default_Handler")));
void TIM8_BRK_IRQ_Handler()	    __attribute__((weak, alias("Default_Handler")));
void TIM8_UP_IRQ_Handler()	    __attribute__((weak, alias("Default_Handler")));
void TIM8_TRG_COM_IRQ_Handler()	__attribute__((weak, alias("Default_Handler")));
void TIM8_CC_IRQ_Handler()	    __attribute__((weak, alias("Default_Handler")));
void ADC3_IRQ_Handler()	        __attribute__((weak, alias("Default_Handler")));
void FMC_IRQ_Handler()	        __attribute__((weak, alias("Default_Handler")));
void SDMMC1_IRQ_Handler()	    __attribute__((weak, alias("Default_Handler")));
void TIM5_IRQ_Handler()	        __attribute__((weak, alias("Default_Handler")));
void SPI3_IRQ_Handler()	        __attribute__((weak, alias("Default_Handler")));
void UART4_IRQ_Handler()	    __attribute__((weak, alias("Default_Handler")));
void UART5_IRQ_Handler()	    __attribute__((weak, alias("Default_Handler")));
void TIM6_DACUNDER_IRQ_Handler()__attribute__((weak, alias("Default_Handler")));
void TIM7_IRQ_Handler()	        __attribute__((weak, alias("Default_Handler")));
void DMA2_CH1_IRQ_Handler()	    __attribute__((weak, alias("Default_Handler")));
void DMA2_CH2_IRQ_Handler()	    __attribute__((weak, alias("Default_Handler")));
void DMA2_CH3_IRQ_Handler()	    __attribute__((weak, alias("Default_Handler")));
void DMA2_CH4_IRQ_Handler()	    __attribute__((weak, alias("Default_Handler")));
void DMA2_CH5_IRQ_Handler()	    __attribute__((weak, alias("Default_Handler")));
void DFSDM1_FLT0_IRQ_Handler()	__attribute__((weak, alias("Default_Handler")));
void DFSDM1_FLT1_IRQ_Handler()	__attribute__((weak, alias("Default_Handler")));
void DFSDM1_FLT2_IRQ_Handler()	__attribute__((weak, alias("Default_Handler")));
void COMP_IRQ_Handler()	        __attribute__((weak, alias("Default_Handler")));
void LPTIM1_IRQ_Handler()	    __attribute__((weak, alias("Default_Handler")));
void LPTIM2_IRQ_Handler()	    __attribute__((weak, alias("Default_Handler")));
void OTG_FS_IRQ_Handler()	    __attribute__((weak, alias("Default_Handler")));
void DMA2_CH6_IRQ_Handler()	    __attribute__((weak, alias("Default_Handler")));
void DMA2_CH7_IRQ_Handler()	    __attribute__((weak, alias("Default_Handler")));
void LPUART1_IRQ_Handler()	    __attribute__((weak, alias("Default_Handler")));
void QUADSPI_IRQ_Handler()	    __attribute__((weak, alias("Default_Handler")));
void I2C3_EV_IRQ_Handler()	    __attribute__((weak, alias("Default_Handler")));
void I2C3_ER_IRQ_Handler()	    __attribute__((weak, alias("Default_Handler")));
void SAI1_IRQ_Handler()	        __attribute__((weak, alias("Default_Handler")));
void SAI2_IRQ_Handler()	        __attribute__((weak, alias("Default_Handler")));
void SWPMI1_IRQ_Handler()	    __attribute__((weak, alias("Default_Handler")));
void TSC_IRQ_Handler()	        __attribute__((weak, alias("Default_Handler")));
void LCD_IRQ_Handler()	        __attribute__((weak, alias("Default_Handler")));
void AES_IRQ_Handler()	        __attribute__((weak, alias("Default_Handler")));
void RNG_HASH_IRQ_Handler()	    __attribute__((weak, alias("Default_Handler")));
void FPU_IRQ_Handler()	        __attribute__((weak, alias("Default_Handler")));


uint32_t const isr_table[] __attribute__((section(".interrupt_vector_table"))) = {
	STACK_START, // Stack address
	(uint32_t) &Reset_Handler,
	(uint32_t) &NMI_Handler,
	(uint32_t) &HardFault_Handler,
	(uint32_t) &MemManage_Handler,
	(uint32_t) &BusFault_Handler,
	(uint32_t) &UsageFault_Handler,
    0,
    0,
    0,
    0,
    (uint32_t) &SVCall_Handler,
	(uint32_t) &Debug_Handler,
    0,
	(uint32_t) &PendSV_Handler,
	(uint32_t) &SysTick_Handler,
    (uint32_t) &WWDG_IRQ_Handler,
    (uint32_t) &PVD_PVM_IRQ_Handler,
	(uint32_t) &RTC_STAMP_IRQ_Handler,
	(uint32_t) &RTC_WKUP_IRQ_Handler,
	(uint32_t) &Flash_IRQ_Handler,
    (uint32_t) &RCC_IRQ_Handler,
    (uint32_t) &EXTI0_IRQ_Handler,
    (uint32_t) &EXTI1_IRQ_Handler,
    (uint32_t) &EXTI2_IRQ_Handler,
    (uint32_t) &EXTI3_IRQ_Handler,
    (uint32_t) &EXTI4_IRQ_Handler,
    (uint32_t) &DMA1_CH1_IRQ_Handler,
    (uint32_t) &DMA1_CH2_IRQ_Handler,
    (uint32_t) &DMA1_CH3_IRQ_Handler,
    (uint32_t) &DMA1_CH4_IRQ_Handler,
    (uint32_t) &DMA1_CH5_IRQ_Handler,
    (uint32_t) &DMA1_CH6_IRQ_Handler,
    (uint32_t) &DMA1_CH7_IRQ_Handler,
    (uint32_t) &ADC1_2_IRQ_Handler,
    (uint32_t) &CAN1_TX_IRQ_Handler,
    (uint32_t) &CAN1_RX0_IRQ_Handler,
    (uint32_t) &CAN1_SCE_IRQ_Handler,
    (uint32_t) &EXTI9_5_IRQ_Handler,
    (uint32_t) &TIM1_BRK_IRQ_Handler,
    (uint32_t) &TIM1_UP_IRQ_Handler,
    (uint32_t) &TIM1_TRG_COM_IRQ_Handler,
    (uint32_t) &TIM1_CC_IRQ_Handler,
    (uint32_t) &TIM2_IRQ_Handler,
    (uint32_t) &TIM3_IRQ_Handler,
    (uint32_t) &TIM4_IRQ_Handler,
    (uint32_t) &I2C1_EV_IRQ_Handler,
    (uint32_t) &I2C1_ER_IRQ_Handler,
    (uint32_t) &I2C2_EV_IRQ_Handler,
    (uint32_t) &I2C2_ER_IRQ_Handler,
    (uint32_t) &SPI1_IRQ_Handler,
    (uint32_t) &SPI2_IRQ_Handler,
    (uint32_t) &USART1_IRQ_Handler,
    (uint32_t) &USART2_IRQ_Handler,
    (uint32_t) &USART3_IRQ_Handler,
    (uint32_t) &EXTI15_10_IRQ_Handler,
    (uint32_t) &RTC_ALARM_IRQ_Handler,
    (uint32_t) &DFSDM1_FLT3_IRQ_Handler,
    (uint32_t) &TIM8_BRK_IRQ_Handler,
    (uint32_t) &TIM8_UP_IRQ_Handler,
    (uint32_t) &TIM8_TRG_COM_IRQ_Handler,
    (uint32_t) &TIM8_CC_IRQ_Handler,
    (uint32_t) &ADC3_IRQ_Handler,
    (uint32_t) &FMC_IRQ_Handler,
    (uint32_t) &SDMMC1_IRQ_Handler,
    (uint32_t) &TIM5_IRQ_Handler,
    (uint32_t) &SPI3_IRQ_Handler,
    (uint32_t) &UART4_IRQ_Handler,
    (uint32_t) &UART5_IRQ_Handler,
    (uint32_t) &TIM6_DACUNDER_IRQ_Handler,
    (uint32_t) &TIM7_IRQ_Handler,
    (uint32_t) &DMA2_CH1_IRQ_Handler,
    (uint32_t) &DMA2_CH2_IRQ_Handler,
    (uint32_t) &DMA2_CH3_IRQ_Handler,
    (uint32_t) &DMA2_CH4_IRQ_Handler,
    (uint32_t) &DMA2_CH5_IRQ_Handler,
    (uint32_t) &DFSDM1_FLT0_IRQ_Handler,
    (uint32_t) &DFSDM1_FLT1_IRQ_Handler,
    (uint32_t) &DFSDM1_FLT2_IRQ_Handler,
    (uint32_t) &COMP_IRQ_Handler,
    (uint32_t) &LPTIM1_IRQ_Handler,
    (uint32_t) &LPTIM2_IRQ_Handler,
    (uint32_t) &OTG_FS_IRQ_Handler,
    (uint32_t) &DMA2_CH6_IRQ_Handler,
    (uint32_t) &DMA2_CH7_IRQ_Handler,
    (uint32_t) &LPUART1_IRQ_Handler,
    (uint32_t) &QUADSPI_IRQ_Handler,
    (uint32_t) &I2C3_EV_IRQ_Handler,
    (uint32_t) &I2C3_ER_IRQ_Handler,
    (uint32_t) &SAI1_IRQ_Handler,
    (uint32_t) &SAI2_IRQ_Handler,
    (uint32_t) &SWPMI1_IRQ_Handler,
    (uint32_t) &TSC_IRQ_Handler,
    (uint32_t) &LCD_IRQ_Handler,
    (uint32_t) &AES_IRQ_Handler,
    (uint32_t) &RNG_HASH_IRQ_Handler,
    (uint32_t) &FPU_IRQ_Handler,
};

void Default_Handler(void)
{
	while(1);
}

// main function declaration
int main(void);

void Reset_Handler(void)
{
    /*
     * 1) Copy .data section to RAM
     * 2) Init the .bss section to zero in RAM
     * 3) Call init function of std library
     * 4) Call main
     */

    // 1) Copy .data to RAM
    uint32_t const dataSectionSize = (uint32_t) &_end_data - (uint32_t) &_start_data;
    uint8_t *flashPtr = (uint8_t *) &_end_text;
    uint8_t *ramPtr = (uint8_t *) &_start_data;
    for(uint32_t i = 0; i < dataSectionSize; ++i)
    {
        *ramPtr = *flashPtr;
        ++ramPtr;
        ++flashPtr;
    }

    // 2) Init the .bss section
    uint32_t const bssSectionSize = (uint32_t) &_end_bss - (uint32_t) &_start_bss;
    uint8_t *bssPointer = (uint8_t *) &_end_bss;
    for(uint32_t i = 0; i < bssSectionSize; ++i)
    {
        *bssPointer = 0;
        ++bssPointer;
    }

    // 3) Call init function of std
    // TO DO

    // 4) Call main
    main();
}

