/***********************************************************************************************************************
    @file     hal_irm.h
    @author   VV TEAM
    @brief    THIS FILE CONTAINS ALL THE FUNCTIONS PROTOTYPES FOR THE IRM
              FIRMWARE LIBRARY.
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
#ifndef __HAL_IRM_H
#define __HAL_IRM_H

#ifdef __cplusplus
extern "C" {
#endif

/* Files includes ------------------------------------------------------------*/
#include "mm32_device.h"

/** @addtogroup MM32_Hardware_Abstract_Layer
  * @{
  */

/** @defgroup IRM_HAL
  * @brief IRM HAL modules
  * @{
  */

/** @defgroup IRM_Exported_Types
  * @{
  */

/**
  * @brief  IRM Init structures definition
  */
typedef struct {
    uint32_t IRM_Polarity;
    uint32_t IRM_Modulation;
    uint32_t IRM_DataSelectSource;
    uint32_t IRM_Channel1ClockSource;
    uint32_t IRM_Channel2ClockSource;
} IRM_InitTypeDef;

/**
  * @brief IRM_Format
  */
#define IRM_Polarity_Normal             (0x00U << IRM_CR_PSEL_Pos)                       
#define IRM_Polarity_Inverted           (0x01U << IRM_CR_PSEL_Pos)                    

/**
  * @brief IRM_Format
  */
#define IRM_Modulation_ASK_PSK          (0x00U << IRM_CR_MSEL_Pos)                               
#define IRM_Modulation_FSK              (0x01U << IRM_CR_MSEL_Pos)                          


/**
  * @brief IRM_DataSelectSourceTypeDef
  */
#define IRM_DataSource_DR               (0x00U << IRM_CR_DSEL_Pos) 
#define IRM_DataSource_UART1_TX         (0x01U << IRM_CR_DSEL_Pos) 
#define IRM_DataSource_UART2_TX         (0x02U << IRM_CR_DSEL_Pos) 
#define IRM_DataSource_LPUART1_TX       (0x03U << IRM_CR_DSEL_Pos) 


/**
  * @brief IRM_Channel1ClockSource
  */
#define IRM_Channel1ClockSource_KeepLow    (0x00U << IRM_CR_CH1SEL_Pos)
#define IRM_Channel1ClockSource_KeepHigh   (0x01U << IRM_CR_CH1SEL_Pos)
#define IRM_Channel1ClockSource_TIM3OC1    (0x02U << IRM_CR_CH1SEL_Pos)
#define IRM_Channel1ClockSource_TIM4OC1    (0x03U << IRM_CR_CH1SEL_Pos)
#define IRM_Channel1ClockSource_TIM16OC1   (0x06U << IRM_CR_CH1SEL_Pos)
#define IRM_Channel1ClockSource_TIM17OC1   (0x07U << IRM_CR_CH1SEL_Pos)


/**
  * @brief IRM_Channel2ClockSource
  */
#define IRM_Channel2ClockSource_KeepLow    (0x00U << IRM_CR_CH2SEL_Pos)
#define IRM_Channel2ClockSource_KeepHigh   (0x01U << IRM_CR_CH2SEL_Pos)
#define IRM_Channel2ClockSource_TIM3OC1    (0x02U << IRM_CR_CH2SEL_Pos)
#define IRM_Channel2ClockSource_TIM4OC1    (0x03U << IRM_CR_CH2SEL_Pos)
#define IRM_Channel2ClockSource_TIM16OC1   (0x06U << IRM_CR_CH2SEL_Pos)
#define IRM_Channel2ClockSource_TIM17OC1   (0x07U << IRM_CR_CH2SEL_Pos)

/**
  * @}
  */


/** @defgroup IRM_Exported_Functions
  * @{
  */

void IRM_DeInit(void);
void IRM_StructInit(IRM_InitTypeDef* init_struct);
ErrorStatus IRM_Init(IRM_InitTypeDef* init_struct);
void IRM_StartCmd(FunctionalState state);
FunctionalState IRM_GetStartCmdStatus(void);
void IRM_SetIRMData(bool bdata);
bool IRM_GetIRMData(void);




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
#endif /* __HAL_IRM_H --------------------------------------------------------*/
/** --------------------------------------------------------------------------*/
