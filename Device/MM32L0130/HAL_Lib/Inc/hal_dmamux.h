/***********************************************************************************************************************
    @file     hal_dmamux.h
    @author   VV TEAM
    @brief    THIS FILE CONTAINS ALL THE FUNCTIONS PROTOTYPES FOR THE DMA
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
#ifndef __HAL_DMAMUX_H
#define __HAL_DMAMUX_H
#ifdef __cplusplus
extern "C" {
#endif

/* Files includes ------------------------------------------------------------*/
#include "mm32_device.h"

/** @addtogroup MM32_Hardware_Abstract_Layer
  * @{
  */

/** @defgroup DMAMUX_HAL
  * @brief DMAMUX HAL modules
  * @{
  */

/** @defgroup DMAMUX_Exported_Types
  * @{
  */


#define DMA_ModuleMaxNumber             (0x01U)
#define DMA_ChanMaxNumber               (0x05U)

/**
  * @brief DMA_MUX_Source definition
  */
#define DMA_MUX_ADC                    (0x00U)                                 /*!< DMA_MUX_ADC */
#define DMA_MUX_I2C1_RX                (0x17U)                                 /*!< DMA_MUX_I2C1_RX */
#define DMA_MUX_I2C1_TX                (0x16U)                                 /*!< DMA_MUX_I2C1_TX */
#define DMA_MUX_LPUART_RX              (0x0FU)                                 /*!< DMA_MUX_LPUART_RX */
#define DMA_MUX_LPUART_TX              (0x0EU)                                 /*!< DMA_MUX_LPUART_TX */
#define DMA_MUX_SLCD_FRM               (0x30U)                                 /*!< DMA_MUX_SLCD_FRM */
#define DMA_MUX_SPI1_RX                (0x02U)                                 /*!< DMA_MUX_SPI1_RX */
#define DMA_MUX_SPI1_TX                (0x03U)                                 /*!< DMA_MUX_SPI1_TX */
#define DMA_MUX_SPI2_RX                (0x04U)                                 /*!< DMA_MUX_SPI2_RX */
#define DMA_MUX_SPI2_TX                (0x05U)                                 /*!< DMA_MUX_SPI2_TX */
#define DMA_MUX_TIM16_CH1              (0x27U)                                 /*!< DMA_MUX_TIM16_CH1 */
#define DMA_MUX_TIM16_UP               (0x26U)                                 /*!< DMA_MUX_TIM16_UP */
#define DMA_MUX_TIM17_CH1              (0x29U)                                 /*!< DMA_MUX_TIM17_CH1 */
#define DMA_MUX_TIM17_UP               (0x28U)                                 /*!< DMA_MUX_TIM17_UP */
#define DMA_MUX_TIM3_CH1               (0x1CU)                                 /*!< DMA_MUX_TIM3_CH1 */
#define DMA_MUX_TIM3_CH2               (0x1DU)                                 /*!< DMA_MUX_TIM3_CH2 */
#define DMA_MUX_TIM3_CH3               (0x1EU)                                 /*!< DMA_MUX_TIM3_CH3 */
#define DMA_MUX_TIM3_CH4               (0x1FU)                                 /*!< DMA_MUX_TIM3_CH4 */
#define DMA_MUX_TIM3_TRIG              (0x1BU)                                 /*!< DMA_MUX_TIM3_TRIG */
#define DMA_MUX_TIM3_UP                (0x1AU)                                 /*!< DMA_MUX_TIM3_UP */
#define DMA_MUX_TIM4_CH1               (0x22U)                                 /*!< DMA_MUX_TIM4_CH1 */
#define DMA_MUX_TIM4_CH2               (0x23U)                                 /*!< DMA_MUX_TIM4_CH2 */
#define DMA_MUX_TIM4_CH3               (0x24U)                                 /*!< DMA_MUX_TIM4_CH3 */
#define DMA_MUX_TIM4_CH4               (0x25U)                                 /*!< DMA_MUX_TIM4_CH4 */
#define DMA_MUX_TIM4_TRIG              (0x21U)                                 /*!< DMA_MUX_TIM4_TRIG */
#define DMA_MUX_TIM4_UP                (0x20U)                                 /*!< DMA_MUX_TIM4_UP */
#define DMA_MUX_UART1_RX               (0x0BU)                                 /*!< DMA_MUX_UART1_RX */
#define DMA_MUX_UART1_TX               (0x0AU)                                 /*!< DMA_MUX_UART1_TX */
#define DMA_MUX_UART2_RX               (0x0DU)                                 /*!< DMA_MUX_UART2_RX */
#define DMA_MUX_UART2_TX               (0x0CU)                                 /*!< DMA_MUX_UART2_TX */




/**
  * @}
  */



/** @defgroup DMAMUX_Exported_Functions
  * @{
  */

ErrorStatus DMA_DecodeDmaIrqNumber(DMA_Channel_TypeDef* channel, IRQn_Type* get_irq_number);
void DMA_SetChannelMuxSource(DMA_Channel_TypeDef* channel, uint32_t muxvalue);
uint32_t DMA_GetChannelMuxSource(DMA_Channel_TypeDef* channel);


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
#endif /* __HAL_DMAMUX_H --------------------------------------------------------*/
/** --------------------------------------------------------------------------*/
