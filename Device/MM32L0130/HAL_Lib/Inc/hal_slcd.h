/***********************************************************************************************************************
    @file     hal_slcd.h
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
#ifndef __HAL_SLCD_H
#define __HAL_SLCD_H



/* Files includes ------------------------------------------------------------*/
#include "mm32_device.h"

/* Exported types ------------------------------------------------------------*/

/* Exported constants --------------------------------------------------------*/

/** @defgroup SLCD_Exported_Constants
  * @{
  */

/**
  * @brief  SLCD Init structure definition
  */
typedef struct {
    uint32_t SLCD_Prescaler;
    uint32_t SLCD_Divider;
    uint32_t SLCD_Duty;
    uint32_t SLCD_Bias;
    uint32_t SLCD_VoltageSource;
} SLCD_InitTypeDef;


/** @defgroup SLCD_Prescaler
  * @{
  */
#define SLCD_Prescaler_1          (0x00U << SLCD_FCR_PS_Pos) /*!< CLKPS = SLCDCLK */
#define SLCD_Prescaler_2          (0x01U << SLCD_FCR_PS_Pos) /*!< CLKPS = SLCDCLK/2 */
#define SLCD_Prescaler_4          (0x02U << SLCD_FCR_PS_Pos) /*!< CLKPS = SLCDCLK/4 */
#define SLCD_Prescaler_8          (0x03U << SLCD_FCR_PS_Pos) /*!< CLKPS = SLCDCLK/8 */
#define SLCD_Prescaler_16         (0x04U << SLCD_FCR_PS_Pos) /*!< CLKPS = SLCDCLK/16 */
#define SLCD_Prescaler_32         (0x05U << SLCD_FCR_PS_Pos) /*!< CLKPS = SLCDCLK/32 */
#define SLCD_Prescaler_64         (0x06U << SLCD_FCR_PS_Pos) /*!< CLKPS = SLCDCLK/64 */
#define SLCD_Prescaler_128        (0x07U << SLCD_FCR_PS_Pos) /*!< CLKPS = SLCDCLK/128 */
#define SLCD_Prescaler_256        (0x08U << SLCD_FCR_PS_Pos) /*!< CLKPS = SLCDCLK/256 */
#define SLCD_Prescaler_512        (0x09U << SLCD_FCR_PS_Pos) /*!< CLKPS = SLCDCLK/512 */
#define SLCD_Prescaler_1024       (0x0AU << SLCD_FCR_PS_Pos) /*!< CLKPS = SLCDCLK/1024 */
#define SLCD_Prescaler_2048       (0x0BU << SLCD_FCR_PS_Pos) /*!< CLKPS = SLCDCLK/2048 */
#define SLCD_Prescaler_4096       (0x0CU << SLCD_FCR_PS_Pos) /*!< CLKPS = SLCDCLK/4096 */
#define SLCD_Prescaler_8192       (0x0DU << SLCD_FCR_PS_Pos) /*!< CLKPS = SLCDCLK/8192 */
#define SLCD_Prescaler_16384      (0x0EU << SLCD_FCR_PS_Pos) /*!< CLKPS = SLCDCLK/16384 */
#define SLCD_Prescaler_32768      (0x0FU << SLCD_FCR_PS_Pos) /*!< CLKPS = SLCDCLK/32768 */

/**
  * @}
  */


/** @defgroup SLCD_Divider
  * @{
  */
#define SLCD_Divider_16      (0x00U << SLCD_FCR_DIV_Pos) /*!< SLCD frequency = CLKPS/16 */
#define SLCD_Divider_17      (0x01U << SLCD_FCR_DIV_Pos) /*!< SLCD frequency = CLKPS/17 */
#define SLCD_Divider_18      (0x02U << SLCD_FCR_DIV_Pos) /*!< SLCD frequency = CLKPS/18 */
#define SLCD_Divider_19      (0x03U << SLCD_FCR_DIV_Pos) /*!< SLCD frequency = CLKPS/19 */
#define SLCD_Divider_20      (0x04U << SLCD_FCR_DIV_Pos) /*!< SLCD frequency = CLKPS/20 */
#define SLCD_Divider_21      (0x05U << SLCD_FCR_DIV_Pos) /*!< SLCD frequency = CLKPS/21 */
#define SLCD_Divider_22      (0x06U << SLCD_FCR_DIV_Pos) /*!< SLCD frequency = CLKPS/22 */
#define SLCD_Divider_23      (0x07U << SLCD_FCR_DIV_Pos) /*!< SLCD frequency = CLKPS/23 */
#define SLCD_Divider_24      (0x08U << SLCD_FCR_DIV_Pos) /*!< SLCD frequency = CLKPS/24 */
#define SLCD_Divider_25      (0x09U << SLCD_FCR_DIV_Pos) /*!< SLCD frequency = CLKPS/25 */
#define SLCD_Divider_26      (0x0AU << SLCD_FCR_DIV_Pos) /*!< SLCD frequency = CLKPS/26 */
#define SLCD_Divider_27      (0x0BU << SLCD_FCR_DIV_Pos) /*!< SLCD frequency = CLKPS/27 */
#define SLCD_Divider_28      (0x0CU << SLCD_FCR_DIV_Pos) /*!< SLCD frequency = CLKPS/28 */
#define SLCD_Divider_29      (0x0DU << SLCD_FCR_DIV_Pos) /*!< SLCD frequency = CLKPS/29 */
#define SLCD_Divider_30      (0x0EU << SLCD_FCR_DIV_Pos) /*!< SLCD frequency = CLKPS/30 */
#define SLCD_Divider_31      (0x0FU << SLCD_FCR_DIV_Pos) /*!< SLCD frequency = CLKPS/31 */

/**
  * @}
  */


/** @defgroup SLCD_Duty
  * @{
  */
#define SLCD_Duty_Static    (0x00U << SLCD_CR_DUTY_Pos) /*!< Static duty */
#define SLCD_Duty_1_2       (0x01U << SLCD_CR_DUTY_Pos) /*!< 1/2 duty */
#define SLCD_Duty_1_3       (0x02U << SLCD_CR_DUTY_Pos) /*!< 1/3 duty */
#define SLCD_Duty_1_4       (0x03U << SLCD_CR_DUTY_Pos) /*!< 1/4 duty */
#define SLCD_Duty_1_6       (0x05U << SLCD_CR_DUTY_Pos) /*!< 1/6 duty */
#define SLCD_Duty_1_8       (0x07U << SLCD_CR_DUTY_Pos) /*!< 1/8 duty */

/**
  * @}
  */


/** @defgroup SLCD_Bias
  * @{
  */
#define SLCD_Bias_1_4        (0x00U << SLCD_CR_BIAS_Pos) /*!< 1/4 Bias */
#define SLCD_Bias_1_2        (0x01U << SLCD_CR_BIAS_Pos) /*!< 1/2 Bias */
#define SLCD_Bias_1_3        (0x02U << SLCD_CR_BIAS_Pos) /*!< 1/3 Bias */
#define SLCD_Bias_Static     (0x03U << SLCD_CR_BIAS_Pos) /*!< static */
/**
  * @}
  */


/** @defgroup SLCD_Bias
  * @{
  */
#define SLCD_ChargePump_0      (0x00U << SLCD_CR_CPMODE_Pos) /*!< Internal charge pump disable */
#define SLCD_ChargePump_1      (0x01U << SLCD_CR_CPMODE_Pos) /*!< Internal charge pump enable */
#define SLCD_ChargePump_2      (0x02U << SLCD_CR_CPMODE_Pos) /*!< Internal charge pump up voltage mode */
#define SLCD_ChargePump_3      (0x03U << SLCD_CR_CPMODE_Pos) /*!< Internal charge pump down voltage mode */
/**
  * @}
  */


/** @defgroup SLCD_Voltage_Source
  * @{
  */
#define SLCD_VoltSrcCapCharggUpLowExt     0 /*!< Enternal voltage source with charge up for the SLCD */
#define SLCD_VoltSrcCapCharggUpLowRef     1 /*!< Internal voltage vref   with charge up for the SLCD */
#define SLCD_VoltSrcCapCharggDownHighExt  2 /*!< Enternal voltage source with charge down for the SLCD */
#define SLCD_VoltSrcCapCharggDownVdd      3 /*!< Internal voltage VDD    with charge down for the SLCD */
#define SLCD_VoltSrcResDivion_Ext         4 /*!< Enternal voltage source with resistor division for the SLCD power */
#define SLCD_VoltSrcResDivion_Vdd         5 /*!< Internal voltage VDD    with resistor division for the SLCD power */
/**
  * @}
  */


/** @defgroup SLCD_DeadTime
  * @{
  */
#define SLCD_DeadTime_0     (0x00U << SLCD_FCR_DEAD_Pos) /*!< No dead Time insert */
#define SLCD_DeadTime_1     (0x01U << SLCD_FCR_DEAD_Pos) /*!< Insert 1 Phase */
#define SLCD_DeadTime_2     (0x02U << SLCD_FCR_DEAD_Pos) /*!< Insert 2 Phase */
#define SLCD_DeadTime_3     (0x03U << SLCD_FCR_DEAD_Pos) /*!< Insert 3 Phase */
#define SLCD_DeadTime_4     (0x04U << SLCD_FCR_DEAD_Pos) /*!< Insert 4 Phase */
#define SLCD_DeadTime_5     (0x05U << SLCD_FCR_DEAD_Pos) /*!< Insert 5 Phase */
#define SLCD_DeadTime_6     (0x06U << SLCD_FCR_DEAD_Pos) /*!< Insert 6 Phase */
#define SLCD_DeadTime_7     (0x07U << SLCD_FCR_DEAD_Pos) /*!< Insert 7 Phase */
/**
  * @}
  */

/** @defgroup SLCD_BlinkMode
  * @{
  */
#define SLCD_BlinkMode_Off                 (0x00U << SLCD_FCR_BLINK_Pos) /*!< No blinking */
#define SLCD_BlinkMode_Corrspond_SEG_COM   (0x01U << SLCD_FCR_BLINK_Pos) /*!< Blink the corresponding COM and SEG of SLCD_BLKR register */
#define SLCD_BlinkMode_AllSEG_AllCOM       (0x02U << SLCD_FCR_BLINK_Pos) /*!< All SEGs and COMs blink Switch the display content between SLCD_DR and SLCD_DR */
#define SLCD_BlinkMode_Switch              (0x03U << SLCD_FCR_BLINK_Pos) /*!< Blink switch between DR[7:0] and DR[15:8] */
/**
  * @}
  */


/** @defgroup SLCD_BlinkFrequency
  * @{
  */
#define SLCD_BlinkFrequency_Div8        (0x00U << SLCD_FCR_BLINKF_Pos) /*!< DIV_CLK/32   for Blinking division */
#define SLCD_BlinkFrequency_Div16       (0x01U << SLCD_FCR_BLINKF_Pos) /*!< DIV_CLK/64   for Blinking division */
#define SLCD_BlinkFrequency_Div32       (0x02U << SLCD_FCR_BLINKF_Pos) /*!< DIV_CLK/128  for Blinking division */
#define SLCD_BlinkFrequency_Div64       (0x03U << SLCD_FCR_BLINKF_Pos) /*!< DIV_CLK/256  for Blinking division */
#define SLCD_BlinkFrequency_Div128      (0x04U << SLCD_FCR_BLINKF_Pos) /*!< DIV_CLK/512  for Blinking division */
#define SLCD_BlinkFrequency_Div256      (0x05U << SLCD_FCR_BLINKF_Pos) /*!< DIV_CLK/1024 for Blinking division */
#define SLCD_BlinkFrequency_Div512      (0x06U << SLCD_FCR_BLINKF_Pos) /*!< DIV_CLK/2048 for Blinking division */
#define SLCD_BlinkFrequency_Div1024     (0x07U << SLCD_FCR_BLINKF_Pos) /*!< DIV_CLK/4096 for Blinking division */
/**
  * @}
  */


/** @defgroup SLCD_ChargePumpClockDiv
  * @{
  */
#define SLCD_ChargePumpClock_Div32     (0x00U << SLCD_FCR_CPDIV_Pos) /*!< SLCD_CLK/8    for Charge pump clock division */
#define SLCD_ChargePumpClock_Div64     (0x01U << SLCD_FCR_CPDIV_Pos) /*!< SLCD_CLK/16   for Charge pump clock division */
#define SLCD_ChargePumpClock_Div128    (0x02U << SLCD_FCR_CPDIV_Pos) /*!< SLCD_CLK/32   for Charge pump clock division */
#define SLCD_ChargePumpClock_Div256    (0x03U << SLCD_FCR_CPDIV_Pos) /*!< SLCD_CLK/64   for Charge pump clock division */
#define SLCD_ChargePumpClock_Div512    (0x04U << SLCD_FCR_CPDIV_Pos) /*!< SLCD_CLK/128  for Charge pump clock division */
#define SLCD_ChargePumpClock_Div1024   (0x05U << SLCD_FCR_CPDIV_Pos) /*!< SLCD_CLK/256  for Charge pump clock division */
#define SLCD_ChargePumpClock_Div2048   (0x06U << SLCD_FCR_CPDIV_Pos) /*!< SLCD_CLK/512  for Charge pump clock division */
#define SLCD_ChargePumpClock_Div4096   (0x07U << SLCD_FCR_CPDIV_Pos) /*!< SLCD_CLK/1024 for Charge pump clock division */

/**
  * @}
  */

/** @defgroup SLCD Contrast control
  * @{
  */

#define SLCD_Contrast_Level_0      (0x00U << SLCD_FCR_CC_Pos) /*!< 2.64V */
#define SLCD_Contrast_Level_1      (0x01U << SLCD_FCR_CC_Pos) /*!< 2.76V */
#define SLCD_Contrast_Level_2      (0x02U << SLCD_FCR_CC_Pos) /*!< 2.88V */
#define SLCD_Contrast_Level_3      (0x03U << SLCD_FCR_CC_Pos) /*!< 3.00V */
#define SLCD_Contrast_Level_4      (0x04U << SLCD_FCR_CC_Pos) /*!< 3.12V */
#define SLCD_Contrast_Level_5      (0x05U << SLCD_FCR_CC_Pos) /*!< 3.24V */
#define SLCD_Contrast_Level_6      (0x06U << SLCD_FCR_CC_Pos) /*!< 3.36V */
#define SLCD_Contrast_Level_7      (0x07U << SLCD_FCR_CC_Pos) /*!< 3.48V */
#define SLCD_Contrast_Level_8      (0x08U << SLCD_FCR_CC_Pos) /*!< 3.96V */
#define SLCD_Contrast_Level_9      (0x09U << SLCD_FCR_CC_Pos) /*!< 4.14V */
#define SLCD_Contrast_Level_10     (0x0AU << SLCD_FCR_CC_Pos) /*!< 4.32V */
#define SLCD_Contrast_Level_11     (0x0BU << SLCD_FCR_CC_Pos) /*!< 4.50V */
#define SLCD_Contrast_Level_12     (0x0CU << SLCD_FCR_CC_Pos) /*!< 4.68V */
#define SLCD_Contrast_Level_13     (0x0DU << SLCD_FCR_CC_Pos) /*!< 4.86V */
#define SLCD_Contrast_Level_14     (0x0EU << SLCD_FCR_CC_Pos) /*!< 5.04V */
#define SLCD_Contrast_Level_15     (0x0FU << SLCD_FCR_CC_Pos) /*!< 5.22V */

/**
  * @}
  */

/** @defgroup SLCD IO Config
  * @{
  */
#define SLCD_IOConfigNone      0    /*!< None */
#define SLCD_IOConfigSEG       2    /*!< SEG */
#define SLCD_IOConfigCOM       3    /*!< COM */

/**
  * @}
  */

/** @defgroup SLCD IO OFFSET
  * @{
  */
#define MAX_SLCD_PIN_NUMBER             64
#define SLCD_L0                         (0x01UL <<  0)
#define SLCD_L1                         (0x01UL <<  1)
#define SLCD_L2                         (0x01UL <<  2)
#define SLCD_L3                         (0x01UL <<  3)
#define SLCD_L4                         (0x01UL <<  4)
#define SLCD_L5                         (0x01UL <<  5)
#define SLCD_L6                         (0x01UL <<  6)
#define SLCD_L7                         (0x01UL <<  7)
#define SLCD_L8                         (0x01UL <<  8)
#define SLCD_L9                         (0x01UL <<  9)
#define SLCD_L10                        (0x01UL << 10)
#define SLCD_L11                        (0x01UL << 11)
#define SLCD_L12                        (0x01UL << 12)
#define SLCD_L13                        (0x01UL << 13)
#define SLCD_L14                        (0x01UL << 14)
#define SLCD_L15                        (0x01UL << 15)
#define SLCD_L16                        (0x01UL << 16)
#define SLCD_L17                        (0x01UL << 17)
#define SLCD_L18                        (0x01UL << 18)
#define SLCD_L19                        (0x01UL << 19)
#define SLCD_L20                        (0x01UL << 20)
#define SLCD_L21                        (0x01UL << 21)
#define SLCD_L22                        (0x01UL << 22)
#define SLCD_L23                        (0x01UL << 23)
#define SLCD_L24                        (0x01UL << 24)
#define SLCD_L25                        (0x01UL << 25)
#define SLCD_L26                        (0x01UL << 26)
#define SLCD_L27                        (0x01UL << 27)
#define SLCD_L28                        (0x01UL << 28)
#define SLCD_L29                        (0x01UL << 29)
#define SLCD_L30                        (0x01UL << 30)
#define SLCD_L31                        (0x01UL << 31)
#define SLCD_L32                        (0x01UL << 0 )
#define SLCD_L33                        (0x01UL << 1 )
#define SLCD_L34                        (0x01UL << 2 )
#define SLCD_L35                        (0x01UL << 3 )
#define SLCD_L36                        (0x01UL << 4 )
#define SLCD_L37                        (0x01UL << 5 )
#define SLCD_L38                        (0x01UL << 6 )
#define SLCD_L39                        (0x01UL << 7 )
#define SLCD_L40                        (0x01UL << 8 )
#define SLCD_L41                        (0x01UL << 9 )
#define SLCD_L42                        (0x01UL << 10)
#define SLCD_L43                        (0x01UL << 11)
#define SLCD_L44                        (0x01UL << 12)
#define SLCD_L45                        (0x01UL << 13)
#define SLCD_L46                        (0x01UL << 14)
#define SLCD_L47                        (0x01UL << 15)
#define SLCD_L48                        (0x01UL << 16)
#define SLCD_L49                        (0x01UL << 17)
#define SLCD_L50                        (0x01UL << 18)
#define SLCD_L51                        (0x01UL << 19)
#define SLCD_L52                        (0x01UL << 20)
#define SLCD_L53                        (0x01UL << 21)
#define SLCD_L54                        (0x01UL << 22)
#define SLCD_L55                        (0x01UL << 23)
#define SLCD_L56                        (0x01UL << 24)
#define SLCD_L57                        (0x01UL << 25)
#define SLCD_L58                        (0x01UL << 26)
#define SLCD_L59                        (0x01UL << 27)
#define SLCD_L60                        (0x01UL << 28)
#define SLCD_L61                        (0x01UL << 29)
#define SLCD_L62                        (0x01UL << 30)
#define SLCD_L63                        (0x01UL << 31)
/**
  * @}
  */


/** @defgroup INDEX Macro
  * @{
  */
#define COM_INDEX_MAX                   8
#define BLINK_INDEX_STEP                3
/**
  * @}
  */


/** @defgroup SLCD flag
  * @{
  */
#define SLCD_FLAG_ENS         (0x01U << SLCD_SR_ENS_Pos) 
#define SLCD_FLAG_EOF         (0x01U << SLCD_SR_EOF_Pos)  
#define SLCD_FLAG_BLKF        (0x01U << SLCD_SR_BLKF_Pos) 
#define SLCD_FLAG_DRSS        (0x01U << SLCD_SR_DRSS_Pos) 
#define SLCD_FLAG_FCRSF       (0x01U << SLCD_SR_FCRSF_Pos)
/**
  * @}
  */


/** @defgroup SLCD_Interrupts Clear bit
  * @{
  */
#define SLCD_STATUS_CLEAR_EOFC     (0x01U << SLCD_CLRR_EOFC_Pos) 
#define SLCD_STATUS_CLEAR_BLKC     (0x01U << SLCD_CLRR_BLKFC_Pos)
/**
  * @}
  */


/** @defgroup SLCD_Interrupts Enalbe
  * @{
  */
#define    SLCD_IT_EOFIE       (0x01U << SLCD_FCR_EOFIE_Pos)  
#define    SLCD_IT_BLKIE       (0x01U << SLCD_FCR_BLKIE_Pos)
/**
  * @}
  */


/** @defgroup SLCD_Interrupts status bit
  * @{
  */
#define SLCD_IT_STATUS_EOFS    (0x01U << SLCD_SR_EOF_Pos) 
#define SLCD_IT_STATUS_BLKS    (0x01U << SLCD_SR_BLKF_Pos)
/**
  * @}
  */


/** @defgroup SLCD_Interrupts Clear bit
  * @{
  */
#define SLCD_IT_CLEAR_EOFC   (0x01U << SLCD_CLRR_EOFC_Pos)  
#define SLCD_IT_CLEAR_BLKC   (0x01U << SLCD_CLRR_BLKFC_Pos) 
/**
  * @}
  */


/** @defgroup SLCD_RAMRegister
  * @{
  */
#define SLCD_RAMRegister_0              ((uint32_t)0x00000000)                       /*!< SLCD RAM Register 0 */
#define SLCD_RAMRegister_1              ((uint32_t)0x00000001)                       /*!< SLCD RAM Register 1 */
#define SLCD_RAMRegister_2              ((uint32_t)0x00000002)                       /*!< SLCD RAM Register 2 */
#define SLCD_RAMRegister_3              ((uint32_t)0x00000003)                       /*!< SLCD RAM Register 3 */
#define SLCD_RAMRegister_4              ((uint32_t)0x00000004)                       /*!< SLCD RAM Register 4 */
#define SLCD_RAMRegister_5              ((uint32_t)0x00000005)                       /*!< SLCD RAM Register 5 */
#define SLCD_RAMRegister_6              ((uint32_t)0x00000006)                       /*!< SLCD RAM Register 6 */
#define SLCD_RAMRegister_7              ((uint32_t)0x00000007)                       /*!< SLCD RAM Register 7 */
#define SLCD_RAMRegister_8              ((uint32_t)0x00000008)                       /*!< SLCD RAM Register 8 */
#define SLCD_RAMRegister_9              ((uint32_t)0x00000009)                       /*!< SLCD RAM Register 9 */
#define SLCD_RAMRegister_10             ((uint32_t)0x0000000A)                       /*!< SLCD RAM Register 10 */
#define SLCD_RAMRegister_11             ((uint32_t)0x0000000B)                       /*!< SLCD RAM Register 11 */
#define SLCD_RAMRegister_12             ((uint32_t)0x0000000C)                       /*!< SLCD RAM Register 12 */
#define SLCD_RAMRegister_13             ((uint32_t)0x0000000D)                       /*!< SLCD RAM Register 13 */
#define SLCD_RAMRegister_14             ((uint32_t)0x0000000E)                       /*!< SLCD RAM Register 14 */
#define SLCD_RAMRegister_15             ((uint32_t)0x0000000F)                       /*!< SLCD RAM Register 15 */

/**
  * @}
  */



/**
  * @}
  */


/** @defgroup SLCD_Exported_Functions
  * @{
  */
void SLCD_DeInit(void);

/* Initialization and Configuration functions */
void SLCD_Init(SLCD_InitTypeDef* init_struct);
void SLCD_StructInit(SLCD_InitTypeDef* init_struct);
void SLCD_Cmd(FunctionalState state);
void SLCD_WaitForSynchro(void);
void SLCD_LowPowerDriveCmd(FunctionalState state);
void SLCD_Internal_VddCmd(FunctionalState state);
void SLCD_InternalVrefCmd(FunctionalState state);
void SLCD_ChargePumpModeConfig(uint32_t SLCD_ChargePump);
uint32_t SLCD_GetChargePumpMode(void);
void SLCD_DeadTimeConfig(uint32_t SLCD_DeadTime);
void SLCD_BlinkConfig(uint32_t SLCD_BlinkMode, uint32_t SLCD_BlinkFrequency);
void SLCD_ContrastConfig(uint32_t SLCD_Contrast);

/* SLCD RAM memory write functions */
void SLCD_Write(uint32_t offset, uint32_t data);
void SLCD_UpdateDisplayRequest(void);

/* Flags management functions */
void SLCD_ClearFlag(uint32_t flag);
FlagStatus SLCD_GetFlagStatus(uint32_t flag);
/* Interrupts management functions */
void SLCD_ITConfig(uint32_t it, FunctionalState state);
void SLCD_ClearITPendingBit(uint32_t it);
ITStatus SLCD_GetITStatus(uint32_t it);
void SLCD_IO_Config(uint8_t* seg_com);
void SLCD_COM_IndexInit(uint8_t* pcom_index);
void SLCD_BLINK_IndexInit(uint8_t* blink_index);
void SLCD_ChargePumpClockDivConfig(uint32_t SLCD_ChargePumpDiv);


#endif

