/***********************************************************************************************************************
    @file     hal_fgpio.h
    @author   VV TEAM
    @brief    THIS FILE CONTAINS ALL THE FUNCTIONS PROTOTYPES FOR THE UART
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
#ifndef __HAL_FGPIO_H
#define __HAL_FGPIO_H
#ifdef __cplusplus
extern "C" {
#endif

/* Files includes ------------------------------------------------------------*/
#include "mm32_device.h"

/** @addtogroup MM32_Hardware_Abstract_Layer
  * @{
  */

/** @defgroup FGPIO_HAL
  * @brief FGPIO HAL modules
  * @{
  */

/** @defgroup FGPIO_Exported_Types
  * @{
  */
#define FGPIO_Pin_0       (0x0001U) /*!< Pin 0 selected */
#define FGPIO_Pin_1       (0x0002U) /*!< Pin 1 selected */
#define FGPIO_Pin_2       (0x0004U) /*!< Pin 2 selected */
#define FGPIO_Pin_3       (0x0008U) /*!< Pin 3 selected */
#define FGPIO_Pin_4       (0x0010U) /*!< Pin 4 selected */
#define FGPIO_Pin_5       (0x0020U) /*!< Pin 5 selected */
#define FGPIO_Pin_6       (0x0040U) /*!< Pin 6 selected */
#define FGPIO_Pin_7       (0x0080U) /*!< Pin 7 selected */
#define FGPIO_Pin_8       (0x0100U) /*!< Pin 8 selected */
#define FGPIO_Pin_9       (0x0200U) /*!< Pin 9 selected */
#define FGPIO_Pin_10      (0x0400U) /*!< Pin 10 selected */
#define FGPIO_Pin_11      (0x0800U) /*!< Pin 11 selected */
#define FGPIO_Pin_12      (0x1000U) /*!< Pin 12 selected */
#define FGPIO_Pin_13      (0x2000U) /*!< Pin 13 selected */
#define FGPIO_Pin_14      (0x4000U) /*!< Pin 14 selected */
#define FGPIO_Pin_15      (0x8000U) /*!< Pin 15 selected */
#define FGPIO_Pin_All     (0xFFFFU) /*!< All pins selected */
/**
  * @}
  */


/**
  * @brief  Bit_SET and Bit_RESET
  */
#define FGPIO_Bit_RESET   0x00   /*!< bit reset */
#define FGPIO_Bit_SET     0x01   /*!< bit set */
/**
  * @}
  */


/** @defgroup FGPIO_Exported_Functions
  * @{
  */
void FGPIO_Write(FGPIO_TypeDef* fgpio, uint16_t value);
void FGPIO_WriteBit(FGPIO_TypeDef* fgpio, uint16_t pin, uint8_t value);
void FGPIO_SetBits(FGPIO_TypeDef* fgpio, uint16_t pin);
void FGPIO_ResetBits(FGPIO_TypeDef* fgpio, uint16_t pin);
uint16_t FGPIO_ReadInputData(FGPIO_TypeDef* fgpio);
uint8_t FGPIO_ReadInputDataBit(FGPIO_TypeDef* gpio, uint16_t pin);
uint16_t FGPIO_ReadOutputData(FGPIO_TypeDef* fgpio);
uint8_t FGPIO_ReadOutputDataBit(FGPIO_TypeDef* fgpio, uint16_t pin);


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
#endif /* __HAL_FGPIO_H ------------------------------------------------------*/
/** --------------------------------------------------------------------------*/


