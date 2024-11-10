/***********************************************************************************************************************
    @file     reg_rcc.h
    @author   VV TEAM
    @brief    This flie contains all the RCC's register and its field definition.
  **********************************************************************************************************************
    @attention

    <h2><center>&copy; Copyright(c) <2023> <MindMotion></center></h2>

      Redistribution and use in source and binary forms, with or without modification, are permitted provided that the
    following conditions are met:
    1. Redistributions of source code must retain the above copyright notice,
       this list of conditions and the following disclaimer.
    2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and
       the following disclaimer in the documentation and/or other materials provided with the distribution.
    3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse or
       promote products derived from this software without specific prior written permission.

      THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
    INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
    DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
    SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
    SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
    WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
    OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *********************************************************************************************************************/

/* Define to prevent recursive inclusion -----------------------------------------------------------------------------*/

#ifndef __REG_RCC_H
#define __REG_RCC_H


/* Files includes ----------------------------------------------------------------------------------------------------*/
#include <core_cm0plus.h>



/**
  * @brief RCC Base Address Definition
  */
#define  RCC_BASE                                  0x40021000                                       /*!<Base Address: 0x40021000*/

/**
  * @brief RCC Register Structure Definition
  */
typedef struct
{
    __IO uint32_t CR;                             /*!<RCC Clock Control Register                     offset: 0x00*/
    __IO uint32_t CFGR;                           /*!<RCC Clock Configuration Register               offset: 0x04*/
    __IO uint32_t CIR;                            /*!<RCC Clock Interrupt Register                   offset: 0x08*/
    __IO uint32_t APB2RSTR;                       /*!<RCC APB2 Peripheral Reset Register             offset: 0x0C*/
    __IO uint32_t APB1RSTR;                       /*!<RCC APB1 Peripheral Reset Register             offset: 0x10*/
    __IO uint32_t AHBENR;                         /*!<RCC AHB Peripheral Clock Enable Register       offset: 0x14*/
    __IO uint32_t APB2ENR;                        /*!<RCC APB2 Peripheral Clock Enable Register      offset: 0x18*/
    __IO uint32_t APB1ENR;                        /*!<RCC APB1Peripheral Clock Enable Register       offset: 0x1C*/
    __IO uint32_t BDCR;                           /*!<RCC Backup Domain Control Register             offset: 0x20*/
    __IO uint32_t CSR;                            /*!<RCC Control Status Register                    offset: 0x24*/
    __IO uint32_t AHBRSTR;                        /*!<RCC AHB Peripheral Reset Register              offset: 0x28*/
    __IO uint32_t CFGR2;                          /*!<RCC Clock Configuration Register 2             offset: 0x2C*/
    __IO uint32_t RESERVED0x030[4];               /*!<                                               offset: 0x30~0x3c*/
    __IO uint32_t SYSCFGR;                        /*!<RCC System Configuration Register              offset: 0x40*/
    __IO uint32_t RESERVED0x044[3];               /*!<                                               offset: 0x44~0x4c*/
    __IO uint32_t PLLCFGR;                        /*!<RCC PLL Configuration Register                 offset: 0x50*/
} RCC_TypeDef;

/**
  * @brief RCC type pointer Definition
  */
#define RCC                                       ((RCC_TypeDef *)RCC_BASE)

/**
  * @brief RCC_CR Register Bit Definition
  */
#define  RCC_CR_HSION_Pos                         (0)
#define  RCC_CR_HSION_Msk                         (0x01U << RCC_CR_HSION_Pos)                       /*!<Internal High-speed Clock Enable*/
#define  RCC_CR_HSIRDY_Pos                        (1)
#define  RCC_CR_HSIRDY_Msk                        (0x01U << RCC_CR_HSIRDY_Pos)                      /*!<Internal High-speed Clock Ready Flag*/
#define  RCC_CR_HSISEL_Pos                        (3)
#define  RCC_CR_HSISEL_Msk                        (0x01U << RCC_CR_HSISEL_Pos)                      /*!<HSI Clock Source Select*/
#define  RCC_CR_HSELPFBYP_Pos                     (4)
#define  RCC_CR_HSELPFBYP_Msk                     (0x01U << RCC_CR_HSELPFBYP_Pos)                   /*!<The Enable Signal Output Directly by LPF Input Signal*/
#define  RCC_CR_HSELPFSEL_Pos                     (5)
#define  RCC_CR_HSELPFSEL_Msk                     (0x01U << RCC_CR_HSELPFSEL_Pos)                   /*!<LPF Filter Mode Control*/
#define  RCC_CR_HSEDEGLITCHBYP_Pos                (6)
#define  RCC_CR_HSEDEGLITCHBYP_Msk                (0x01U << RCC_CR_HSEDEGLITCHBYP_Pos)              /*!<Deburring Circuit Bypass Control Bit*/
#define  RCC_CR_HSEDEGLITCHSEL_Pos                (7)
#define  RCC_CR_HSEDEGLITCHSEL_Msk                (0x01U << RCC_CR_HSEDEGLITCHSEL_Pos)              /*!<Deburring Width Control Bit*/
#define  RCC_CR_HSEOUTPUTSEL_Pos                  (8)
#define  RCC_CR_HSEOUTPUTSEL_Msk                  (0x01U << RCC_CR_HSEOUTPUTSEL_Pos)                /*!<Output Mode Selector*/
#define  RCC_CR_HSEDR_Pos                         (9)
#define  RCC_CR_HSEDR_Msk                         (0x03U << RCC_CR_HSEDR_Pos)                       /*!<HSE Driver Ability*/
#define  RCC_CR_HSIDIV_Pos                        (11)
#define  RCC_CR_HSIDIV_Msk                        (0x07U << RCC_CR_HSIDIV_Pos)                      /*!<HSIDIV: Internal high-speed clock division factor*/
#define  RCC_CR_HSEON_Pos                         (16)
#define  RCC_CR_HSEON_Msk                         (0x01U << RCC_CR_HSEON_Pos)                       /*!<External High-speed Clock Enable*/
#define  RCC_CR_HSERDY_Pos                        (17)
#define  RCC_CR_HSERDY_Msk                        (0x01U << RCC_CR_HSERDY_Pos)                      /*!<External High-speed Clock Ready Flag*/
#define  RCC_CR_HSEBYP_Pos                        (18)
#define  RCC_CR_HSEBYP_Msk                        (0x01U << RCC_CR_HSEBYP_Pos)                      /*!<External High-speed Clock Bypass*/
#define  RCC_CR_CSSHSON_Pos                       (19)
#define  RCC_CR_CSSHSON_Msk                       (0x01U << RCC_CR_CSSHSON_Pos)                     /*!<Clock Security System High Souce Enable*/
#define  RCC_CR_CSSLSON_Pos                       (20)
#define  RCC_CR_CSSLSON_Msk                       (0x01U << RCC_CR_CSSLSON_Pos)                     /*!<Clock Security System Low Souce Enable*/
#define  RCC_CR_HSEAACSEL_Pos                     (21)
#define  RCC_CR_HSEAACSEL_Msk                     (0x01U << RCC_CR_HSEAACSEL_Pos)                   /*!<HSE Amplitude Auto Calibration Select*/
#define  RCC_CR_HSEIB_Pos                         (22)
#define  RCC_CR_HSEIB_Msk                         (0x03U << RCC_CR_HSEIB_Pos)                       /*!<HSE Current Mode Select*/
#define  RCC_CR_PLLON_Pos                         (24)
#define  RCC_CR_PLLON_Msk                         (0x01U << RCC_CR_PLLON_Pos)                       /*!<PLL Enable*/
#define  RCC_CR_PLLRDY_Pos                        (25)
#define  RCC_CR_PLLRDY_Msk                        (0x01U << RCC_CR_PLLRDY_Pos)                      /*!<PLL Clock Ready Flag*/

/**
  * @brief RCC_CFGR Register Bit Definition
  */
#define  RCC_CFGR_SW_Pos                          (0)
#define  RCC_CFGR_SW_Msk                          (0x03U << RCC_CFGR_SW_Pos)                        /*!<System Clock Switch*/
#define  RCC_CFGR_SWS_Pos                         (2)
#define  RCC_CFGR_SWS_Msk                         (0x03U << RCC_CFGR_SWS_Pos)                       /*!<System Clock Switch Status*/
#define  RCC_CFGR_HPRE_Pos                        (4)
#define  RCC_CFGR_HPRE_Msk                        (0x0FU << RCC_CFGR_HPRE_Pos)                      /*!<AHB prescaler coefficient*/
#define  RCC_CFGR_PPRE1_Pos                       (8)
#define  RCC_CFGR_PPRE1_Msk                       (0x07U << RCC_CFGR_PPRE1_Pos)                     /*!<APB1 prescaler coefficient*/
#define  RCC_CFGR_PPRE2_Pos                       (11)
#define  RCC_CFGR_PPRE2_Msk                       (0x07U << RCC_CFGR_PPRE2_Pos)                     /*!<APB2 prescaler coefficient*/
#define  RCC_CFGR_MCO_Pos                         (24)
#define  RCC_CFGR_MCO_Msk                         (0x07U << RCC_CFGR_MCO_Pos)                       /*!<Micro Controller Clock Output*/

/**
  * @brief RCC_CIR Register Bit Definition
  */
#define  RCC_CIR_LSIRDYF_Pos                      (0)
#define  RCC_CIR_LSIRDYF_Msk                      (0x01U << RCC_CIR_LSIRDYF_Pos)                    /*!<LSI Ready Interrupt Flag*/
#define  RCC_CIR_LSERDYF_Pos                      (1)
#define  RCC_CIR_LSERDYF_Msk                      (0x01U << RCC_CIR_LSERDYF_Pos)                    /*!<LSERDYF: LSE Ready Interrupt Flag*/
#define  RCC_CIR_HSIRDYF_Pos                      (2)
#define  RCC_CIR_HSIRDYF_Msk                      (0x01U << RCC_CIR_HSIRDYF_Pos)                    /*!<HSI Ready Interrupt Flag*/
#define  RCC_CIR_HSERDYF_Pos                      (3)
#define  RCC_CIR_HSERDYF_Msk                      (0x01U << RCC_CIR_HSERDYF_Pos)                    /*!<HSE Ready Interrupt Flag*/
#define  RCC_CIR_PLLRDYF_Pos                      (4)
#define  RCC_CIR_PLLRDYF_Msk                      (0x01U << RCC_CIR_PLLRDYF_Pos)                    /*!<PLL Ready Interrupt Flag*/
#define  RCC_CIR_CSSLSF_Pos                       (6)
#define  RCC_CIR_CSSLSF_Msk                       (0x01U << RCC_CIR_CSSLSF_Pos)                     /*!<Clock Security System Low Source Interrupt Flag*/
#define  RCC_CIR_CSSHSF_Pos                       (7)
#define  RCC_CIR_CSSHSF_Msk                       (0x01U << RCC_CIR_CSSHSF_Pos)                     /*!<Clock Security System High Source Interrupt Flag*/
#define  RCC_CIR_LSIRDYIE_Pos                     (8)
#define  RCC_CIR_LSIRDYIE_Msk                     (0x01U << RCC_CIR_LSIRDYIE_Pos)                   /*!<LSI Ready Interrupt Enable*/
#define  RCC_CIR_LSERDYIE_Pos                     (9)
#define  RCC_CIR_LSERDYIE_Msk                     (0x01U << RCC_CIR_LSERDYIE_Pos)                   /*!<LSERDYIE: LSE Ready Interrupt Enable*/
#define  RCC_CIR_HSIRDYIE_Pos                     (10)
#define  RCC_CIR_HSIRDYIE_Msk                     (0x01U << RCC_CIR_HSIRDYIE_Pos)                   /*!<HSI Ready Interrupt Enable*/
#define  RCC_CIR_HSERDYIE_Pos                     (11)
#define  RCC_CIR_HSERDYIE_Msk                     (0x01U << RCC_CIR_HSERDYIE_Pos)                   /*!<HSE Ready Interrupt Enable*/
#define  RCC_CIR_PLLRDYIE_Pos                     (12)
#define  RCC_CIR_PLLRDYIE_Msk                     (0x01U << RCC_CIR_PLLRDYIE_Pos)                   /*!<PLL Ready Interrupt Enable*/
#define  RCC_CIR_LSIRDYC_Pos                      (16)
#define  RCC_CIR_LSIRDYC_Msk                      (0x01U << RCC_CIR_LSIRDYC_Pos)                    /*!<LSI Ready Interrupt Clear*/
#define  RCC_CIR_LSERDYC_Pos                      (17)
#define  RCC_CIR_LSERDYC_Msk                      (0x01U << RCC_CIR_LSERDYC_Pos)                    /*!<LSERDYC: LSE Ready Interrupt Clear*/
#define  RCC_CIR_HSIRDYC_Pos                      (18)
#define  RCC_CIR_HSIRDYC_Msk                      (0x01U << RCC_CIR_HSIRDYC_Pos)                    /*!<HSI Ready Interrupt Clear*/
#define  RCC_CIR_HSERDYC_Pos                      (19)
#define  RCC_CIR_HSERDYC_Msk                      (0x01U << RCC_CIR_HSERDYC_Pos)                    /*!<HSE Ready Interrupt Clear*/
#define  RCC_CIR_PLLRDYC_Pos                      (20)
#define  RCC_CIR_PLLRDYC_Msk                      (0x01U << RCC_CIR_PLLRDYC_Pos)                    /*!<PLL Ready Interrupt Clear*/
#define  RCC_CIR_CSSLSC_Pos                       (22)
#define  RCC_CIR_CSSLSC_Msk                       (0x01U << RCC_CIR_CSSLSC_Pos)                     /*!<Clock Security System Low Source Interrupt Clear*/
#define  RCC_CIR_CSSHSC_Pos                       (23)
#define  RCC_CIR_CSSHSC_Msk                       (0x01U << RCC_CIR_CSSHSC_Pos)                     /*!<Clock Security System High Source Interrupt Clear*/

/**
  * @brief RCC_APB2RSTR Register Bit Definition
  */
#define  RCC_APB2RSTR_SYSCFG_Pos                  (0)
#define  RCC_APB2RSTR_SYSCFG_Msk                  (0x01U << RCC_APB2RSTR_SYSCFG_Pos)                /*!<SYSCFG Reset*/
#define  RCC_APB2RSTR_ADC_Pos                     (9)
#define  RCC_APB2RSTR_ADC_Msk                     (0x01U << RCC_APB2RSTR_ADC_Pos)                   /*!<ADC Reset*/
#define  RCC_APB2RSTR_SPI1_Pos                    (12)
#define  RCC_APB2RSTR_SPI1_Msk                    (0x01U << RCC_APB2RSTR_SPI1_Pos)                  /*!<SPI1 Reset*/
#define  RCC_APB2RSTR_UART1_Pos                   (14)
#define  RCC_APB2RSTR_UART1_Msk                   (0x01U << RCC_APB2RSTR_UART1_Pos)                 /*!<UART1 Reset*/
#define  RCC_APB2RSTR_COMP_Pos                    (15)
#define  RCC_APB2RSTR_COMP_Msk                    (0x01U << RCC_APB2RSTR_COMP_Pos)                  /*!<Comparator reset*/
#define  RCC_APB2RSTR_TIM16_Pos                   (17)
#define  RCC_APB2RSTR_TIM16_Msk                   (0x01U << RCC_APB2RSTR_TIM16_Pos)                 /*!<TIM16 Reset*/
#define  RCC_APB2RSTR_TIM17_Pos                   (18)
#define  RCC_APB2RSTR_TIM17_Msk                   (0x01U << RCC_APB2RSTR_TIM17_Pos)                 /*!<TIM17 Reset*/
#define  RCC_APB2RSTR_DBG_Pos                     (22)
#define  RCC_APB2RSTR_DBG_Msk                     (0x01U << RCC_APB2RSTR_DBG_Pos)                   /*!<DBG Reset*/
#define  RCC_APB2RSTR_LPTIM_Pos                   (30)
#define  RCC_APB2RSTR_LPTIM_Msk                   (0x01U << RCC_APB2RSTR_LPTIM_Pos)                 /*!<LPTIM reset*/
#define  RCC_APB2RSTR_LPUART_Pos                  (31)
#define  RCC_APB2RSTR_LPUART_Msk                  (0x01U << RCC_APB2RSTR_LPUART_Pos)                /*!<LPUART reset*/

/**
  * @brief RCC_APB1RSTR Register Bit Definition
  */
#define  RCC_APB1RSTR_TIM3_Pos                    (1)
#define  RCC_APB1RSTR_TIM3_Msk                    (0x01U << RCC_APB1RSTR_TIM3_Pos)                  /*!<TIM3 Reset*/
#define  RCC_APB1RSTR_TIM4_Pos                    (2)
#define  RCC_APB1RSTR_TIM4_Msk                    (0x01U << RCC_APB1RSTR_TIM4_Pos)                  /*!<TIM4 Reset*/
#define  RCC_APB1RSTR_IRM_Pos                     (10)
#define  RCC_APB1RSTR_IRM_Msk                     (0x01U << RCC_APB1RSTR_IRM_Pos)                   /*!<Infrared Modulator Reset*/
#define  RCC_APB1RSTR_WWDG_Pos                    (11)
#define  RCC_APB1RSTR_WWDG_Msk                    (0x01U << RCC_APB1RSTR_WWDG_Pos)                  /*!<Window Watchdog Reset*/
#define  RCC_APB1RSTR_SPI2_Pos                    (14)
#define  RCC_APB1RSTR_SPI2_Msk                    (0x01U << RCC_APB1RSTR_SPI2_Pos)                  /*!<SPI2 Reset*/
#define  RCC_APB1RSTR_UART2_Pos                   (17)
#define  RCC_APB1RSTR_UART2_Msk                   (0x01U << RCC_APB1RSTR_UART2_Pos)                 /*!<UART2 Reset*/
#define  RCC_APB1RSTR_I2C1_Pos                    (21)
#define  RCC_APB1RSTR_I2C1_Msk                    (0x01U << RCC_APB1RSTR_I2C1_Pos)                  /*!<2C1 Reset*/
#define  RCC_APB1RSTR_PWR_Pos                     (28)
#define  RCC_APB1RSTR_PWR_Msk                     (0x01U << RCC_APB1RSTR_PWR_Pos)                   /*!<Power Interface Reset*/

/**
  * @brief RCC_AHBENR Register Bit Definition
  */
#define  RCC_AHBENR_DMA_Pos                       (0)
#define  RCC_AHBENR_DMA_Msk                       (0x01U << RCC_AHBENR_DMA_Pos)                     /*!<DMA clock enable*/
#define  RCC_AHBENR_SRAM_Pos                      (2)
#define  RCC_AHBENR_SRAM_Msk                      (0x01U << RCC_AHBENR_SRAM_Pos)                    /*!<SRAM Clock Enable*/
#define  RCC_AHBENR_FLASH_Pos                     (4)
#define  RCC_AHBENR_FLASH_Msk                     (0x01U << RCC_AHBENR_FLASH_Pos)                   /*!<FLASH Clock Enable*/
#define  RCC_AHBENR_CRC_Pos                       (6)
#define  RCC_AHBENR_CRC_Msk                       (0x01U << RCC_AHBENR_CRC_Pos)                     /*!<CRC Clock Enable*/
#define  RCC_AHBENR_GPIOA_Pos                     (17)
#define  RCC_AHBENR_GPIOA_Msk                     (0x01U << RCC_AHBENR_GPIOA_Pos)                   /*!<GPIOA Clock Enable*/
#define  RCC_AHBENR_GPIOB_Pos                     (18)
#define  RCC_AHBENR_GPIOB_Msk                     (0x01U << RCC_AHBENR_GPIOB_Pos)                   /*!<GPIOB Clock Enable*/
#define  RCC_AHBENR_GPIOC_Pos                     (19)
#define  RCC_AHBENR_GPIOC_Msk                     (0x01U << RCC_AHBENR_GPIOC_Pos)                   /*!<GPIOC Clock Enable*/
#define  RCC_AHBENR_GPIOD_Pos                     (20)
#define  RCC_AHBENR_GPIOD_Msk                     (0x01U << RCC_AHBENR_GPIOD_Pos)                   /*!<GPIOD Clock Enable*/
#define  RCC_AHBENR_GPIOH_Pos                     (24)
#define  RCC_AHBENR_GPIOH_Msk                     (0x01U << RCC_AHBENR_GPIOH_Pos)                   /*!<GPIOH Clock Enable*/

/**
  * @brief RCC_APB2ENR Register Bit Definition
  */
#define  RCC_APB2ENR_SYSCFG_Pos                   (0)
#define  RCC_APB2ENR_SYSCFG_Msk                   (0x01U << RCC_APB2ENR_SYSCFG_Pos)                 /*!<SYSCFG Clock Enable*/
#define  RCC_APB2ENR_ADC_Pos                      (9)
#define  RCC_APB2ENR_ADC_Msk                      (0x01U << RCC_APB2ENR_ADC_Pos)                    /*!<ADC Clock Enable*/
#define  RCC_APB2ENR_SPI1_Pos                     (12)
#define  RCC_APB2ENR_SPI1_Msk                     (0x01U << RCC_APB2ENR_SPI1_Pos)                   /*!<SPI1 Clock Enable*/
#define  RCC_APB2ENR_UART1_Pos                    (14)
#define  RCC_APB2ENR_UART1_Msk                    (0x01U << RCC_APB2ENR_UART1_Pos)                  /*!<UART1 Clock Enable*/
#define  RCC_APB2ENR_COMP_Pos                     (15)
#define  RCC_APB2ENR_COMP_Msk                     (0x01U << RCC_APB2ENR_COMP_Pos)                   /*!<Comparator Clock Enable*/
#define  RCC_APB2ENR_TIM16_Pos                    (17)
#define  RCC_APB2ENR_TIM16_Msk                    (0x01U << RCC_APB2ENR_TIM16_Pos)                  /*!<TIM16 Clock Enable*/
#define  RCC_APB2ENR_TIM17_Pos                    (18)
#define  RCC_APB2ENR_TIM17_Msk                    (0x01U << RCC_APB2ENR_TIM17_Pos)                  /*!<TIM17 Clock Enable*/
#define  RCC_APB2ENR_DBG_Pos                      (22)
#define  RCC_APB2ENR_DBG_Msk                      (0x01U << RCC_APB2ENR_DBG_Pos)                    /*!<DBG Clock Enable*/
#define  RCC_APB2ENR_EXTI_Pos                     (29)
#define  RCC_APB2ENR_EXTI_Msk                     (0x01U << RCC_APB2ENR_EXTI_Pos)                   /*!<EXTI Clock Enable*/
#define  RCC_APB2ENR_LPTIM_Pos                    (30)
#define  RCC_APB2ENR_LPTIM_Msk                    (0x01U << RCC_APB2ENR_LPTIM_Pos)                  /*!<LPTIM Clock Enable*/
#define  RCC_APB2ENR_LPUART_Pos                   (31)
#define  RCC_APB2ENR_LPUART_Msk                   (0x01U << RCC_APB2ENR_LPUART_Pos)                 /*!<LPUART Clock Enable*/

/**
  * @brief RCC_APB1ENR Register Bit Definition
  */
#define  RCC_APB1ENR_TIM3_Pos                     (1)
#define  RCC_APB1ENR_TIM3_Msk                     (0x01U << RCC_APB1ENR_TIM3_Pos)                   /*!<TIM3 Clock Enable*/
#define  RCC_APB1ENR_TIM4_Pos                     (2)
#define  RCC_APB1ENR_TIM4_Msk                     (0x01U << RCC_APB1ENR_TIM4_Pos)                   /*!<TIM4 Clock Enable*/
#define  RCC_APB1ENR_IRM_Pos                      (10)
#define  RCC_APB1ENR_IRM_Msk                      (0x01U << RCC_APB1ENR_IRM_Pos)                    /*!<Infrared Module Clock Enable*/
#define  RCC_APB1ENR_WWDG_Pos                     (11)
#define  RCC_APB1ENR_WWDG_Msk                     (0x01U << RCC_APB1ENR_WWDG_Pos)                   /*!<Window Watchdog Clock Enable*/
#define  RCC_APB1ENR_SPI2_Pos                     (14)
#define  RCC_APB1ENR_SPI2_Msk                     (0x01U << RCC_APB1ENR_SPI2_Pos)                   /*!<SPI2 Clock Enable*/
#define  RCC_APB1ENR_UART2_Pos                    (17)
#define  RCC_APB1ENR_UART2_Msk                    (0x01U << RCC_APB1ENR_UART2_Pos)                  /*!<UART2 Clock Enable*/
#define  RCC_APB1ENR_I2C1_Pos                     (21)
#define  RCC_APB1ENR_I2C1_Msk                     (0x01U << RCC_APB1ENR_I2C1_Pos)                   /*!<I2C1 Clock Enable*/
#define  RCC_APB1ENR_BKP_Pos                      (24)
#define  RCC_APB1ENR_BKP_Msk                      (0x01U << RCC_APB1ENR_BKP_Pos)                    /*!<BKP Clock Enable*/
#define  RCC_APB1ENR_PWR_Pos                      (28)
#define  RCC_APB1ENR_PWR_Msk                      (0x01U << RCC_APB1ENR_PWR_Pos)                    /*!<Power Clock Enable*/
#define  RCC_APB1ENR_LCD_Pos                      (29)
#define  RCC_APB1ENR_LCD_Msk                      (0x01U << RCC_APB1ENR_LCD_Pos)                    /*!<LCD Clock Enable*/
#define  RCC_APB1ENR_IWDG_Pos                     (30)
#define  RCC_APB1ENR_IWDG_Msk                     (0x01U << RCC_APB1ENR_IWDG_Pos)                   /*!<IWDG Clock Enable*/
#define  RCC_APB1ENR_RTC_Pos                      (31)
#define  RCC_APB1ENR_RTC_Msk                      (0x01U << RCC_APB1ENR_RTC_Pos)                    /*!<RTC Clock Enable*/

/**
  * @brief RCC_BDCR Register Bit Definition
  */
#define  RCC_BDCR_LSEON_Pos                       (0)
#define  RCC_BDCR_LSEON_Msk                       (0x01U << RCC_BDCR_LSEON_Pos)                     /*!<External Low-speed Oscillator Enable*/
#define  RCC_BDCR_LSERDY_Pos                      (1)
#define  RCC_BDCR_LSERDY_Msk                      (0x01U << RCC_BDCR_LSERDY_Pos)                    /*!<External Low-speed Oscillator Ready*/
#define  RCC_BDCR_LSEBYP_Pos                      (2)
#define  RCC_BDCR_LSEBYP_Msk                      (0x01U << RCC_BDCR_LSEBYP_Pos)                    /*!<External Low-speed Oscillator Bypass*/
#define  RCC_BDCR_LCDSEL_Pos                      (6)
#define  RCC_BDCR_LCDSEL_Msk                      (0x03U << RCC_BDCR_LCDSEL_Pos)                    /*!<LCD clock source selection is set as the clock source by software to select LCD. Once LCD clock source is selected, it cannot be changed unless the backup domain is reset. LCDRST bit can be used to reset them.*/
#define  RCC_BDCR_RTCSEL_Pos                      (8)
#define  RCC_BDCR_RTCSEL_Msk                      (0x03U << RCC_BDCR_RTCSEL_Pos)                    /*!<RTC Clock Source Selection*/
#define  RCC_BDCR_RTCEN_Pos                       (15)
#define  RCC_BDCR_RTCEN_Msk                       (0x01U << RCC_BDCR_RTCEN_Pos)                     /*!<RTC Clock Enable*/
#define  RCC_BDCR_RTCRST_Pos                      (16)
#define  RCC_BDCR_RTCRST_Msk                      (0x01U << RCC_BDCR_RTCRST_Pos)                    /*!<RTC/BKP software reset*/
#define  RCC_BDCR_LCDRST_Pos                      (17)
#define  RCC_BDCR_LCDRST_Msk                      (0x01U << RCC_BDCR_LCDRST_Pos)                    /*!<LCD software reset*/
#define  RCC_BDCR_DBP_Pos                         (24)
#define  RCC_BDCR_DBP_Msk                         (0x01U << RCC_BDCR_DBP_Pos)                       /*!<Remove write protection from the backup domain. After reset, the backup register is protected against accidental writing. This bit is set to allow being written to these registers.*/

/**
  * @brief RCC_CSR Register Bit Definition
  */
#define  RCC_CSR_LSION_Pos                        (0)
#define  RCC_CSR_LSION_Msk                        (0x01U << RCC_CSR_LSION_Pos)                      /*!<Internal Low-speed Oscillator Enable*/
#define  RCC_CSR_LSIRDY_Pos                       (1)
#define  RCC_CSR_LSIRDY_Msk                       (0x01U << RCC_CSR_LSIRDY_Pos)                     /*!<Internal Low-speed Oscillator Ready*/
#define  RCC_CSR_LSISEL_Pos                       (2)
#define  RCC_CSR_LSISEL_Msk                       (0x03U << RCC_CSR_LSISEL_Pos)                     /*!<LSI Clock Frequency Select Bit*/
#define  RCC_CSR_LSCLKSEL_Pos                     (4)
#define  RCC_CSR_LSCLKSEL_Msk                     (0x01U << RCC_CSR_LSCLKSEL_Pos)                   /*!<LSCLK Clock Source Select Bit*/
#define  RCC_CSR_LSIOE_Pos                        (5)
#define  RCC_CSR_LSIOE_Msk                        (0x01U << RCC_CSR_LSIOE_Pos)                      /*!<LSI Output Enable*/
#define  RCC_CSR_PVDRSTEN_Pos                     (6)
#define  RCC_CSR_PVDRSTEN_Msk                     (0x01U << RCC_CSR_PVDRSTEN_Pos)                   /*!<PVD Reset Enable*/
#define  RCC_CSR_LOCKUPEN_Pos                     (7)
#define  RCC_CSR_LOCKUPEN_Msk                     (0x01U << RCC_CSR_LOCKUPEN_Pos)                   /*!<CPU Lockup Reset Enable*/
#define  RCC_CSR_PVDRSTF_Pos                      (22)
#define  RCC_CSR_PVDRSTF_Msk                      (0x01U << RCC_CSR_PVDRSTF_Pos)                    /*!<PVD Reset Flag*/
#define  RCC_CSR_LOCKUPF_Pos                      (23)
#define  RCC_CSR_LOCKUPF_Msk                      (0x01U << RCC_CSR_LOCKUPF_Pos)                    /*!<CPU Lockup Reset Flag*/
#define  RCC_CSR_RMVF_Pos                         (24)
#define  RCC_CSR_RMVF_Msk                         (0x01U << RCC_CSR_RMVF_Pos)                       /*!<Remove Reset Flag*/
#define  RCC_CSR_PINRSTF_Pos                      (26)
#define  RCC_CSR_PINRSTF_Msk                      (0x01U << RCC_CSR_PINRSTF_Pos)                    /*!<PIN Reset Flag*/
#define  RCC_CSR_PORRSTF_Pos                      (27)
#define  RCC_CSR_PORRSTF_Msk                      (0x01U << RCC_CSR_PORRSTF_Pos)                    /*!<POR/PDR Reset Flag*/
#define  RCC_CSR_SFTRSTF_Pos                      (28)
#define  RCC_CSR_SFTRSTF_Msk                      (0x01U << RCC_CSR_SFTRSTF_Pos)                    /*!<Software Reset Flag*/
#define  RCC_CSR_IWDGRSTF_Pos                     (29)
#define  RCC_CSR_IWDGRSTF_Msk                     (0x01U << RCC_CSR_IWDGRSTF_Pos)                   /*!<Independent Watchdog Reset Flag*/
#define  RCC_CSR_WWDGRSTF_Pos                     (30)
#define  RCC_CSR_WWDGRSTF_Msk                     (0x01U << RCC_CSR_WWDGRSTF_Pos)                   /*!<Window Watchdog Reset Flag*/
#define  RCC_CSR_LPWRRSTF_Pos                     (31)
#define  RCC_CSR_LPWRRSTF_Msk                     (0x01U << RCC_CSR_LPWRRSTF_Pos)                   /*!<Low Power Reset Flag*/

/**
  * @brief RCC_AHBRSTR Register Bit Definition
  */
#define  RCC_AHBRSTR_DMA_Pos                      (0)
#define  RCC_AHBRSTR_DMA_Msk                      (0x01U << RCC_AHBRSTR_DMA_Pos)                    /*!<DMA Reset*/
#define  RCC_AHBRSTR_CRC_Pos                      (6)
#define  RCC_AHBRSTR_CRC_Msk                      (0x01U << RCC_AHBRSTR_CRC_Pos)                    /*!<CRC Reset*/
#define  RCC_AHBRSTR_GPIOA_Pos                    (17)
#define  RCC_AHBRSTR_GPIOA_Msk                    (0x01U << RCC_AHBRSTR_GPIOA_Pos)                  /*!<GPIOA Reset*/
#define  RCC_AHBRSTR_GPIOB_Pos                    (18)
#define  RCC_AHBRSTR_GPIOB_Msk                    (0x01U << RCC_AHBRSTR_GPIOB_Pos)                  /*!<GPIOB Reset*/
#define  RCC_AHBRSTR_GPIOC_Pos                    (19)
#define  RCC_AHBRSTR_GPIOC_Msk                    (0x01U << RCC_AHBRSTR_GPIOC_Pos)                  /*!<GPIOC Reset*/
#define  RCC_AHBRSTR_GPIOD_Pos                    (20)
#define  RCC_AHBRSTR_GPIOD_Msk                    (0x01U << RCC_AHBRSTR_GPIOD_Pos)                  /*!<GPIOD Reset*/
#define  RCC_AHBRSTR_GPIOH_Pos                    (24)
#define  RCC_AHBRSTR_GPIOH_Msk                    (0x01U << RCC_AHBRSTR_GPIOH_Pos)                  /*!<GPIOH Reset*/

/**
  * @brief RCC_CFGR2 Register Bit Definition
  */
#define  RCC_CFGR2_LPUARTCLKSEL_Pos               (0)
#define  RCC_CFGR2_LPUARTCLKSEL_Msk               (0x03U << RCC_CFGR2_LPUARTCLKSEL_Pos)             /*!<LPUART clock source selection*/
#define  RCC_CFGR2_APB1_CLK_HV_PRE_Pos            (16)
#define  RCC_CFGR2_APB1_CLK_HV_PRE_Msk            (0x0FU << RCC_CFGR2_APB1_CLK_HV_PRE_Pos)          /*!<APB1_HV Output Clock Division Factor*/
#define  RCC_CFGR2_MCOPRE_Pos                     (20)
#define  RCC_CFGR2_MCOPRE_Msk                     (0x0FU << RCC_CFGR2_MCOPRE_Pos)                   /*!<MCOPRE: MCO Clock Prescaler Factor*/
#define  RCC_CFGR2_LPTIMCLKSEL_Pos                (29)
#define  RCC_CFGR2_LPTIMCLKSEL_Msk                (0x03U << RCC_CFGR2_LPTIMCLKSEL_Pos)              /*!<LPTIM clock source selection*/

/**
  * @brief RCC_SYSCFG Register Bit Definition
  */
#define  RCC_SYSCFG_PROG_CHECK_EN_Pos             (0)
#define  RCC_SYSCFG_PROG_CHECK_EN_Msk             (0x01U << RCC_SYSCFG_PROG_CHECK_EN_Pos)           /*!<Check whether the data in Flash is 0xFF when writing Flash*/
#define  RCC_SYSCFG_HSE_RFB_SEL_Pos               (8)
#define  RCC_SYSCFG_HSE_RFB_SEL_Msk               (0x03U << RCC_SYSCFG_HSE_RFB_SEL_Pos)             /*!<HSE_RFB_SEL: Feedback Resistor Selection.*/
#define  RCC_SYSCFG_HSELPFEN_Pos                  (14)
#define  RCC_SYSCFG_HSELPFEN_Msk                  (0x01U << RCC_SYSCFG_HSELPFEN_Pos)                /*!<External Crystal Low-pass Filter Enable*/

/**
  * @brief RCC_PLLCFGR Register Bit Definition
  */
#define  RCC_PLLCFGR_PLLSRC_Pos                   (0)
#define  RCC_PLLCFGR_PLLSRC_Msk                   (0x01U << RCC_PLLCFGR_PLLSRC_Pos)                 /*!<PLL Entry Clock Source Selection*/
#define  RCC_PLLCFGR_PLLXTPRE_Pos                 (1)
#define  RCC_PLLCFGR_PLLXTPRE_Msk                 (0x01U << RCC_PLLCFGR_PLLXTPRE_Pos)               /*!<Division selection when HSE clock is used as PLL input*/
#define  RCC_PLLCFGR_PLL_ICTRL_Pos                (2)
#define  RCC_PLLCFGR_PLL_ICTRL_Msk                (0x03U << RCC_PLLCFGR_PLL_ICTRL_Pos)              /*!<PLL CP Current Control Signals*/
#define  RCC_PLLCFGR_PLL_LDS_Pos                  (4)
#define  RCC_PLLCFGR_PLL_LDS_Msk                  (0x03U << RCC_PLLCFGR_PLL_LDS_Pos)                /*!<PLL Lock Detector Accuracy Select*/
#define  RCC_PLLCFGR_PLLDIV_Pos                   (8)
#define  RCC_PLLCFGR_PLLDIV_Msk                   (0x07U << RCC_PLLCFGR_PLLDIV_Pos)                 /*!<PLL Divide Factor*/
#define  RCC_PLLCFGR_PLLMUL_Pos                   (16)
#define  RCC_PLLCFGR_PLLMUL_Msk                   (0xFFU << RCC_PLLCFGR_PLLMUL_Pos)                 /*!<PLL Multiplication Factor*/
#define  RCC_PLLCFGR_PLLPDIV_Pos                  (29)
#define  RCC_PLLCFGR_PLLPDIV_Msk                  (0x07U << RCC_PLLCFGR_PLLPDIV_Pos)                /*!<PLL Pre-divider Factor*/


#endif

