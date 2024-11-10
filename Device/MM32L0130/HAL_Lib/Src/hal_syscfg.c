/***********************************************************************************************************************
    @file     hal_syscfg.c
    @author   VV TEAM
    @brief    THIS FILE PROVIDES ALL THE FLASH FIRMWARE FUNCTIONS.
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

/* Includes ------------------------------------------------------------------*/
#include "hal_syscfg.h"

/** @addtogroup StdPeriph_Driver
  * @{
  */

/** @defgroup SYSCFG
  * @brief SYSCFG driver modules
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/** @defgroup SYSCFG_Private_Functions
  * @{
  */

/** @defgroup SYSCFG_Group1 SYSCFG Initialization and Configuration functions
  *  @brief   SYSCFG Initialization and Configuration functions
  *
   @verbatim
   ===============================================================================
  ##### SYSCFG Initialization and Configuration functions #####
   ===============================================================================

   @endverbatim
  * @{
  */

/**
  * @brief  Deinitializes the SYSCFG registers to their default reset values.
  * @param  None
  * @retval None
  */
void SYSCFG_DeInit(void)
{
    /* Set EXTICRx registers to reset value */
    SYSCFG->EXTICR1 = 0;
    SYSCFG->EXTICR2 = 0;
    SYSCFG->EXTICR3 = 0;
    SYSCFG->EXTICR4 = 0;
}

/**
  * @brief  Selects the GPIO pin used as EXTI Line.
  * @param  port_source_gpio: EXTI_PortSourceGPIOx .
  * @param  pin_source: EXTI_PinSourcex.
  * @retval None.
  */
void SYSCFG_EXTILineConfig(uint8_t port_source_gpio, uint8_t pin_source)
{
    uint32_t tmp = 0x00;

    tmp = ((uint32_t)0x0F) << (0x04 * (pin_source & (uint8_t)0x03));

    if ((pin_source >> 0x02) == 0)
    {
        SYSCFG->EXTICR1 &= ~tmp;
        SYSCFG->EXTICR1 |= (((uint32_t)port_source_gpio) << (0x04 * (pin_source & (uint8_t)0x03)));
    }
    else if ((pin_source >> 0x02) == 1)
    {
        SYSCFG->EXTICR2 &= ~tmp;
        SYSCFG->EXTICR2 |= (((uint32_t)port_source_gpio) << (0x04 * (pin_source & (uint8_t)0x03)));
    }
    else if ((pin_source >> 0x02) == 2)
    {
        SYSCFG->EXTICR3 &= ~tmp;
        SYSCFG->EXTICR3 |= (((uint32_t)port_source_gpio) << (0x04 * (pin_source & (uint8_t)0x03)));
    }
    else if ((pin_source >> 0x02) == 3)
    {
        SYSCFG->EXTICR4 &= ~tmp;
        SYSCFG->EXTICR4 |= (((uint32_t)port_source_gpio) << (0x04 * (pin_source & (uint8_t)0x03)));
    }
}

/**
  * @brief  Config I2C port mode.
  * @param  port_mode: SYSCFG_I2CPort_OD or SYSCFG_I2CPort_PP .
  * @retval None.
  */
void SYSCFG_I2CPortConfig(uint32_t port_mode)
{
    MODIFY_REG(SYSCFG->PADHYS, SYSCFG_PADHYS_I2C1_MODE_SEL_Msk, port_mode);
}


/**
  * @brief  Enables or disables the Power Voltage Detector(PVD).
  * @param  state: new state of the PVD.
  *         This parameter can be: ENABLE or DISABLE.
  * @retval None.
  */
void SYSCFG_PVDCmd(FunctionalState state)
{
    (state) ?                                                 \
    (SYSCFG->PDETCSR |= (0x01U << SYSCFG_PDETCSR_PVDE_Pos)) : \
    (SYSCFG->PDETCSR &= ~(0x01U << SYSCFG_PDETCSR_PVDE_Pos));
}

/**
  * @brief  Configures the voltage threshold detected by the Power Voltage
  *         Detector(PVD).
  * @param  pvd_level: specifies the PVD detection level
  *         This parameter can be one of the following values:
  * @arg    SYSCFG_PVDLevel_1V8   : PVD detection level set to 1.8V
  * @arg    SYSCFG_PVDLevel_2V1   : PVD detection level set to 2.1V
  * @arg    SYSCFG_PVDLevel_2V4   : PVD detection level set to 2.4V
  * @arg    SYSCFG_PVDLevel_2V7   : PVD detection level set to 2.7V
  * @arg    SYSCFG_PVDLevel_3V0   : PVD detection level set to 3.0V
  * @arg    SYSCFG_PVDLevel_3V3   : PVD detection level set to 3.3V
  * @arg    SYSCFG_PVDLevel_3V6   : PVD detection level set to 3.6V
  * @arg    SYSCFG_PVDLevel_3V9   : PVD detection level set to 3.9V
  * @arg    SYSCFG_PVDLevel_4V2   : PVD detection level set to 4.2V
  * @arg    SYSCFG_PVDLevel_4V5   : PVD detection level set to 4.5V
  * @arg    SYSCFG_PVDLevel_4V8   : PVD detection level set to 4.8V
  * @retval None.
  */
void SYSCFG_PVDLevelConfig(uint32_t pvd_level)
{
    MODIFY_REG(SYSCFG->PDETCSR, SYSCFG_PDETCSR_PLS_Msk, pvd_level);
}

/**
  * @brief  Checks whether the specified PWR flag is set or not.
  * @param  flag: specifies the flag to check.
  *         This parameter can be one of the following values:
  * @arg    SYSCFG_FLAG_PVDO: PVD Output
  * @retval The new state of PWR_FLAG (SET or RESET).
  */
FlagStatus SYSCFG_GetPVDOFlagStatus(uint32_t flag)
{
    return ((FlagStatus)(SYSCFG->PDETCSR & flag));
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

/**
  * @}
  */

/**
  * @}
  */

