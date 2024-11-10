/***********************************************************************************************************************
    @file     hal_dmamux.c
    @author   VV TEAM
    @brief    THIS FILE PROVIDES ALL THE DMAMUX FIRMWARE FUNCTIONS.
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
#define _HAL_DMAMUX_C_

/* Files includes ------------------------------------------------------------*/
#include "hal_dmamux.h"

/** @addtogroup MM32_Hardware_Abstract_Layer
  * @{
  */

/** @addtogroup DMA_HAL
  * @{
  */


/**
  * @brief  Writes DMA config to the specified DMA port.
  * @param  enum_config: specifies the pin config for the relative function.
  * @retval ErrorStatus (SUCCESS or ERROR).
  */
ErrorStatus DMA_DecodeDmaIrqNumber(DMA_Channel_TypeDef* channel, IRQn_Type* get_irq_number)
{
    ErrorStatus result = ERROR;
    uint8_t i, j;
    DMA_Channel_TypeDef* vdma_channel[][DMA_ChanMaxNumber] = 
    {
        { DMA_Channel1, DMA_Channel2, DMA_Channel3, DMA_Channel4, DMA_Channel5 }
    };

    IRQn_Type vdma_irq[][DMA_ChanMaxNumber] = 
    {
        { DMA_Channel1_IRQn, DMA_Channel2_3_IRQn, DMA_Channel2_3_IRQn, DMA_Channel4_5_IRQn, DMA_Channel4_5_IRQn }
    };

    for(j = 0; j < DMA_ModuleMaxNumber; j++) 
    {
        for(i = 0; i < DMA_ChanMaxNumber; i++) 
        {
            if(channel == vdma_channel[j][i]) 
            {
                *get_irq_number = vdma_irq[j][i];
                result = SUCCESS;
                break;
            }
        }
        if(result == SUCCESS) 
        {
            break;
        }
    }

    return result;
}

/**
  * @brief  Set the DMA Channeln's DMA MUX value for target DMA trigger.
  * @param  channel : select the DMA Channel.
  * @param  muxvalue : DMA MUX trigger source selection value .
  *    @arg  DMA_MUX_ADC       
  *    @arg  DMA_MUX_I2C1_RX    
  *    @arg  DMA_MUX_I2C1_TX    
  *    @arg  DMA_MUX_LPUART1_RX 
  *    @arg  DMA_MUX_LPUART1_TX 
  *    @arg  DMA_MUX_SLCD_FRM   
  *    @arg  DMA_MUX_SPI1_RX    
  *    @arg  DMA_MUX_SPI1_TX    
  *    @arg  DMA_MUX_SPI2_RX    
  *    @arg  DMA_MUX_SPI2_TX    
  *    @arg  DMA_MUX_TIM16_CH1  
  *    @arg  DMA_MUX_TIM16_UP   
  *    @arg  DMA_MUX_TIM17_CH1  
  *    @arg  DMA_MUX_TIM17_UP   
  *    @arg  DMA_MUX_TIM3_CH1   
  *    @arg  DMA_MUX_TIM3_CH2   
  *    @arg  DMA_MUX_TIM3_CH3   
  *    @arg  DMA_MUX_TIM3_CH4   
  *    @arg  DMA_MUX_TIM3_TRIG  
  *    @arg  DMA_MUX_TIM3_UP    
  *    @arg  DMA_MUX_TIM4_CH1   
  *    @arg  DMA_MUX_TIM4_CH2   
  *    @arg  DMA_MUX_TIM4_CH3   
  *    @arg  DMA_MUX_TIM4_CH4   
  *    @arg  DMA_MUX_TIM4_TRIG  
  *    @arg  DMA_MUX_TIM4_UP    
  *    @arg  DMA_MUX_UART1_RX   
  *    @arg  DMA_MUX_UART1_TX   
  *    @arg  DMA_MUX_UART2_RX   
  *    @arg  DMA_MUX_UART2_TX   
  * @retval None.
  */
void DMA_SetChannelMuxSource(DMA_Channel_TypeDef* channel, uint32_t muxvalue)
{
    if(channel == DMA_Channel1)
    {
        MODIFY_REG(DMA->CHSEL0, DMA_CHSEL0_CH1SEL_Msk, muxvalue<<0);
    }
    else if(channel == DMA_Channel2)
    {
        MODIFY_REG(DMA->CHSEL0, DMA_CHSEL0_CH2SEL_Msk, muxvalue<<8);
    }
    else if(channel == DMA_Channel3)
    {
        MODIFY_REG(DMA->CHSEL0, DMA_CHSEL0_CH3SEL_Msk, muxvalue<<16);
    }
    else if(channel == DMA_Channel4)
    {
        MODIFY_REG(DMA->CHSEL0, DMA_CHSEL0_CH4SEL_Msk, muxvalue<<24);
    }
    else if(channel == DMA_Channel5)
    {
        MODIFY_REG(DMA->CHSEL1, DMA_CHSEL1_CH5SEL_Msk, muxvalue<<0);
    }
    else if(channel == DMA_Channel6)
    {
        MODIFY_REG(DMA->CHSEL1, DMA_CHSEL1_CH6SEL_Msk, muxvalue<<8);
    }
    else if(channel == DMA_Channel7)
    {
        MODIFY_REG(DMA->CHSEL1, DMA_CHSEL1_CH7SEL_Msk, muxvalue<<16);
    }
}
    

/**
  * @brief  get ChannelMuxSource.
  * @param  channel : select the DMA Channel.
  * @retval DMA MUX trigger source value .
  */
uint32_t DMA_GetChannelMuxSource(DMA_Channel_TypeDef* channel)
{
    uint32_t retvalue;

    if(channel == DMA_Channel1)
    {
        retvalue = ((DMA->CHSEL0 & DMA_CHSEL0_CH1SEL_Msk) >> 0);
    }
    else if(channel == DMA_Channel2)
    {
        retvalue = ((DMA->CHSEL0 & DMA_CHSEL0_CH2SEL_Msk) >> 8);
    }
    else if(channel == DMA_Channel3)
    {
        retvalue = ((DMA->CHSEL0 & DMA_CHSEL0_CH3SEL_Msk) >> 16);
    }
    else if(channel == DMA_Channel4)
    {
        retvalue = ((DMA->CHSEL0 & DMA_CHSEL0_CH4SEL_Msk) >> 24);
    }
    else if(channel == DMA_Channel5)
    {
        retvalue = ((DMA->CHSEL1 & DMA_CHSEL1_CH5SEL_Msk) >> 0);
    }
    else if(channel == DMA_Channel6)
    {
        retvalue = ((DMA->CHSEL1 & DMA_CHSEL1_CH6SEL_Msk) >> 8);
    }
    else if(channel == DMA_Channel7)
    {
        retvalue = ((DMA->CHSEL1 & DMA_CHSEL1_CH7SEL_Msk) >> 16);
    }

    return retvalue; 
}

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

