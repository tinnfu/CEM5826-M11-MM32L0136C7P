/***********************************************************************************************************************
    @file     hal_irm.c
    @author   VV TEAM
    @brief    THIS FILE PROVIDES ALL THE IRM FIRMWARE FUNCTIONS.
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
#define _HAL_IRM_C_

/* Files includes ------------------------------------------------------------*/
#include "hal_irm.h"

/** @addtogroup MM32_Hardware_Abstract_Layer
  * @{
  */

/** @addtogroup IRM_HAL
  * @{
  */

/** @addtogroup IRM_Exported_Functions
  * @{
  */

/* Includes ------------------------------------------------------------------*/

/** @addtogroup HAL_Driver
  * @{
  */

/** @defgroup IRM
  * @brief IRM driver modules
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/

/* Private functions ---------------------------------------------------------*/

/** @defgroup IRM_Private_Functions
  * @{
  */

/** @defgroup IRM_Group1 Initialization and Configuration functions
  * @brief   Initialization and Configuration functions
  */

/** --------------------------------------------------------------------------*/
/*             Initialization and Configuration functions---------------------*/
/** --------------------------------------------------------------------------*/

/**
  * @brief  Deinitializes the IRM registers to their default reset values.
  * @note   This function doesn't reset the IRM Clock source and IRM Backup Data
  *         registers.
  * @param  None
  * @retval None
  */
void IRM_DeInit(void)
{
    RCC_APB1PeriphResetCmd(RCC_APB1Periph_IRM, ENABLE);
    RCC_APB1PeriphResetCmd(RCC_APB1Periph_IRM, DISABLE);
}

/**
  * @brief  Fills each IRM_InitStruct member with its default value.
  * @param  IRM_InitStruct: pointer to a IRM_InitTypeDef structure which will be
  *         initialized.
  * @retval None
  */
void IRM_StructInit(IRM_InitTypeDef* init_struct)
{
    init_struct->IRM_Polarity            = IRM_Polarity_Normal;
    init_struct->IRM_Modulation          = IRM_Modulation_ASK_PSK;
    init_struct->IRM_DataSelectSource    = IRM_DataSource_DR;
    init_struct->IRM_Channel1ClockSource = IRM_Channel1ClockSource_KeepLow;
    init_struct->IRM_Channel2ClockSource = IRM_Channel2ClockSource_KeepLow;
}

/**
  * @brief  Initializes the IRM registers according to the specified parameters
  *         in IRM_InitStruct.
  * @param  IRM_InitStruct: pointer to a IRM_InitTypeDef structure that contains
  *         the configuration information for the IRM peripheral.
  * @note   The IRM Prescaler register is write protected and can be written in
  *         IRM Modulation is in stop mode only.
  * @retval An ErrorStatus enumeration value:
  *          - SUCCESS: IRM registers are initialized
  *          - ERROR: IRM registers are not initialized
  */
ErrorStatus IRM_Init(IRM_InitTypeDef* init_struct)
{
    ErrorStatus status = ERROR;

    if(RESET == (IRM->CR & (0x01U << IRM_CR_IRSTART_Pos))) 
    {
        IRM->CR = (init_struct->IRM_Polarity              | \
                   init_struct->IRM_Modulation            | \
                   init_struct->IRM_DataSelectSource      | \
                   init_struct->IRM_Channel1ClockSource   | \
                   init_struct->IRM_Channel2ClockSource );

        status = SUCCESS;
    }
    return status;
}

/**
  * @brief  Enables or disables the IRM transmit.
  * @param  NewState: new state of the start command.
  *          This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
void IRM_StartCmd(FunctionalState state)
{
    (state) ? \
    (IRM->CR |=  (0x01U << IRM_CR_IRSTART_Pos)) : \
    (IRM->CR &= ~(0x01U << IRM_CR_IRSTART_Pos));
}

/**
  * @brief  Returns the IRM Send Bit.
  * @param  None
  * @retval The last Bit value.
  */
FunctionalState IRM_GetStartCmdStatus(void)
{
    return ((IRM->CR & (0x01U << IRM_CR_IRSTART_Pos)) ? ENABLE : DISABLE);
}

/**
  * @brief  Set IRM Send Bit.
  * @param  bdata: specifies the bit which will be transmitted
  * @retval None.
  */
void IRM_SetIRMData(bool bdata)
{
    IRM->DR = (uint32_t)bdata;
}

/**
  * @brief  Returns the IRM Send Bit.
  * @param  None
  * @retval The last Bit value.
  */
bool IRM_GetIRMData(void)
{
    return ((0 == IRM->DR) ? false : true);
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

