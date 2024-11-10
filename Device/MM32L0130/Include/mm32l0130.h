/***********************************************************************************************************************
    @file     MM32L0130.h
    @author   VV TEAM
    @brief    THIS FILE CONTAINS ALL THE FUNCTIONS PROTOTYPES FOR THE SERIES OF
              MM32 FIRMWARE LIBRARY.
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


/* Define to prevent recursive inclusion -------------------------------------*/

#ifndef __MM32L0130_H
#define __MM32L0130_H

#ifdef __cplusplus
extern "C" {
#endif

#if defined(__CC_ARM)
#pragma anon_unions
#elif defined(__ICCARM__)
#pragma language=extended
#elif defined(__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050)
#pragma clang diagnostic ignored "-Wc11-extensions"
#pragma clang diagnostic ignored "-Wreserved-id-macro"
#elif defined(__GNUC__)
/* anonymous unions are enabled by default -----------------------------------*/
#else
#warning Not supported compiler type
#endif

extern void SystemInit(void);


/* MM32 Library version is V0.10 --------------------------------------------*/

#define __MM32_LIB_VERSION_MAIN                 (0x00U) /*!< [15:8] main version */
#define __MM32_LIB_VERSION_SUB                  (0x10U) /*!< [7:0]  sub version */
#define __MM32_LIB_VERSION               \
        ((__MM32_LIB_VERSION_MAIN << 8U) \
         | (__MM32_LIB_VERSION_SUB << 0U))

/* MM32 Library release date is 2024-09-27 -----------------------------------*/
#define __MM32_LIB_RELESE_YEARH                 (0x20U) /*!< [31:24] release year high */
#define __MM32_LIB_RELESE_YEARL                 (0x24U) /*!< [23:16] release year low */
#define __MM32_LIB_RELESE_MONTH                 (0x09U) /*!< [15:8]  release month */
#define __MM32_LIB_RELESE_DAY                   (0x27U) /*!< [7:0]   release day */
#define __MM32_LIB_RELESE_DATE              \
        ((__MM32_LIB_RELESE_YEARH << 24U)   \
         | (__MM32_LIB_RELESE_YEARL << 16U) \
         | (__MM32_LIB_RELESE_MONTH << 8U)  \
         | (__MM32_LIB_RELESE_DAY << 0U))

#define HSI_STARTUP_TIMEOUT                     (0x8000U) /*!< Time out for HSI start up. */
#define HSE_STARTUP_TIMEOUT                     (0x8000U) /*!< Time out for HSE start up. */


#ifdef  CUSTOM_HSE_VAL
#define HSE_VALUE                               (12000000U) /*!< Value of the External oscillator in Hz. */
#else
#define HSE_VALUE                               (8000000U) /*!< Value of the External oscillator in Hz. */
#endif

#define LSE_VALUE                               (32768U)        /*!< Value of the External low oscillator in Hz. */
#define HSI_VALUE                               (8000000U) /*!< Value of the Internal oscillator in Hz. */
#define LSI_VALUE                               (40000U) /*!< Value of the Internal oscillator in Hz. */


/**
  * @brief Configuration of the Cortex-Star Processor and Core Peripherals
  */


#define __MPU_PRESENT                       (0) /*!< Cortex-M0 does not provide a MPU present or not */
#ifndef __NVIC_PRIO_BITS
#define __NVIC_PRIO_BITS                    (2) /*!< Cortex-M0 uses 2 Bits for the Priority Levels */
/* #warning "__NVIC_PRIO_BITS not defined in device header file; using default!" */
#endif
#define __Vendor_SysTickConfig              (0) /*!< Set to 1 if different SysTick Config is used */

/**
  * @brief  MM32 MCU Interrupt Handle
  */
typedef enum IRQn {

    NonMaskableInt_IRQn                 = -14,                                  ///< 2 Non Maskable Interrupt
    HardFault_IRQn                      = -13,                                  ///< 3 Cortex-M0 Hard Fault Interrupt
    SVC_IRQn                            = -5,                                   ///< 11 Cortex-M0 SV Call Interrupt
    DebugMonitor_IRQn                   = -4,                                   ///< 12 Cortex-M0 Debug Monitor Interrupt
    PendSV_IRQn                         = -2,                                   ///< 14 Cortex-M0 Pend SV Interrupt
    SysTick_IRQn                        = -1,                                   ///< 15 Cortex-M0 System Tick Interrupt

    WWDG_IWDG_IRQn                      = 0,                                    ///< WatchDog Interrupt
    PVD_IRQn                            = 1,                                    ///< PVD through EXTI Line detect Interrupt
    RTC_BKP_IRQn                        = 2,                                    ///< BKP through EXTI Line Interrupt
    FLASH_IRQn                          = 3,                                    ///< FLASH Interrupt
    RCC_IRQn                            = 4,                                    ///< RCC Interrupt
    EXTI0_1_IRQn                        = 5,                                    ///< EXTI Line 0 and 1 Interrupts
    EXTI2_3_IRQn                        = 6,                                    ///< EXTI Line 2 and 3 Interrupts
    EXTI4_15_IRQn                       = 7,                                    ///< EXTI Line 4 to 15 Interrupts
    DMA_Channel1_IRQn                   = 9,                                    ///< DMA1 Channel 1 Interrupt
    DMA_Channel2_3_IRQn                 = 10,                                   ///< DMA1 Channel 2 and Channel 3 Interrupts
    DMA_Channel4_5_IRQn                 = 11,                                   ///< DMA1 Channel 4 and Channel 5 Interrupts
    ADC_COMP_IRQn                       = 12,                                   ///< ADC & COMP Interrupts
    TIM3_IRQn                           = 16,                                   ///< TIM3 Interrupt
    LPUART_IRQn                         = 17,                                   ///< LPUART Interrupt
    LPTIMER_IRQn                        = 18,                                   ///< LPTIM  Interrupt
    TIM4_IRQn                           = 19,                                   ///< TIM4 Interrupt
    TIM16_IRQn                          = 21,                                   ///< TIM16 Interrupt
    TIM17_IRQn                          = 22,                                   ///< TIM17 Interrupt
    I2C1_IRQn                           = 23,                                   ///< I2C1 Interrupt
    SPI1_IRQn                           = 25,                                   ///< SPI1 Interrupt
    SPI2_IRQn                           = 26,                                   ///< SPI1 Interrupt
    UART1_IRQn                          = 27,                                   ///< UART1 Interrupt
    UART2_IRQn                          = 28,                                   ///< UART2 Interrupt
    SLCD_IRQn                           = 30,                                   ///< SLCD  Interrupt
} IRQn_Type;


#include <core_cm0plus.h>
#include <stdint.h>
#include <stdbool.h>

extern uint32_t SystemCoreClock;

typedef int64_t                         s64;
typedef uint64_t                        u64;
typedef int32_t                         s32;
typedef int16_t                         s16;
typedef int8_t                          s8;

typedef const int32_t                   sc32; /*!< Read Only */
typedef const int16_t                   sc16; /*!< Read Only */
typedef const int8_t                    sc8;  /*!< Read Only */

typedef __IO int32_t                    vs32;
typedef __IO int16_t                    vs16;
typedef __IO int8_t                     vs8;

typedef __I int32_t                     vsc32; /*!< Read Only */
typedef __I int16_t                     vsc16; /*!< Read Only */
typedef __I int8_t                      vsc8;  /*!< Read Only */

typedef uint32_t                        u32;
typedef uint16_t                        u16;
typedef uint8_t                         u8;

typedef const uint32_t                  uc32; /*!< Read Only */
typedef const uint16_t                  uc16; /*!< Read Only */
typedef const uint8_t                   uc8;  /*!< Read Only */

typedef __IO uint32_t                   vu32;
typedef __IO uint16_t                   vu16;
typedef __IO uint8_t                    vu8;

typedef __I uint32_t                    vuc32; /*!< Read Only */
typedef __I uint16_t                    vuc16; /*!< Read Only */
typedef __I uint8_t                     vuc8;  /*!< Read Only */

typedef bool                            BOOL;

#ifndef NULL
#define NULL                            ((void *)0)
#endif

typedef enum
{
    RESET = 0,
    SET = !RESET
} FlagStatus, ITStatus;

typedef enum
{
    DISABLE = 0,
    ENABLE  = !DISABLE
} FunctionalState;

typedef enum
{
    ERROR = 0,
    SUCCESS = !ERROR
} ErrorStatus;

#define U8_MAX                  ((u8)255)
#define S8_MAX                  ((s8)127)
#define S8_MIN                  ((s8) - 128)
#define U16_MAX                 ((u16)65535u)
#define S16_MAX                 ((s16)32767)
#define S16_MIN                 ((s16) - 32768)
#define U32_MAX                 ((u32)4294967295uL)
#define S32_MAX                 ((s32)2147483647)
#define S32_MIN                 ((s32) - 2147483648uL)

#define MAX(a, b)             ((a) > (b) ? (a) : (b))
#define MIN(a, b)             ((a) < (b) ? (a) : (b))

#define SET_BIT(reg, bit)     ((reg) = (reg) | (bit))
#define CLEAR_BIT(reg, bit)   ((reg) = (reg) & (~(bit)))
#define READ_BIT(reg, bit)    ((reg) & (bit))
#define CLEAR_REG(reg)        ((reg) = (0x0))
#define WRITE_REG(reg, value) ((reg) = (value))
#define READ_REG(reg)         ((reg))
#define MODIFY_REG(reg, MASK_CLEAR, SET_BITS)                   \
        WRITE_REG((reg), (((READ_REG(reg)) & (~(MASK_CLEAR))) | \
                          ((SET_BITS)&(MASK_CLEAR))))

#ifndef LEFT_SHIFT_BIT
#define LEFT_SHIFT_BIT(x)     (1 << x)
#endif

#ifndef ARRAY_SIZE
#define ARRAY_SIZE(x)         (sizeof(x) / sizeof((x)[0]))
#endif

#define PERIPH_BASE             (0x40000000U) /*!< Peripheral base address in the alias region */
#define APB1PERIPH_BASE         (PERIPH_BASE + 0x00000000)
#define APB2PERIPH_BASE         (PERIPH_BASE + 0x00010000)
#define AHBPERIPH_BASE          (PERIPH_BASE + 0x00020000)

/**
  * @brief UID type pointer Definition
  */
#define UID_BASE                (0x1FFFF7E8U) /*!< Unique device ID register base address */

#include "reg_adc.h"
#include "reg_comp.h"
#include "reg_crcpoly.h"
#include "reg_dbg.h"
#include "reg_dma.h"
#include "reg_exti.h"
#include "reg_fgpio.h"
#include "reg_flash.h"
#include "reg_gpio.h"
#include "reg_i2c.h"
#include "reg_irm.h"
#include "reg_iwdg.h"
#include "reg_lptim.h"
#include "reg_lpuart.h"
#include "reg_pwr.h"
#include "reg_rcc.h"
#include "reg_rtc.h"
#include "reg_slcd.h"
#include "reg_spi.h"
#include "reg_syscfg.h"
#include "reg_tim.h"
#include "reg_uart.h"
#include "reg_wwdg.h"

#ifdef USE_STDPERIPH_DRIVER
#include "hal_conf.h"
#endif

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

/** --------------------------------------------------------------------------*/
#endif
/** --------------------------------------------------------------------------*/

