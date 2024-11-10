/***********************************************************************************************************************
    @file     hal_pwr.c
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
#define __HAL_PWR_C_

/* Files includes ------------------------------------------------------------*/
#include "hal_pwr.h"

/** @addtogroup MM32_Hardware_Abstract_Layer
  * @{
  */

/** @addtogroup PWR_HAL
  * @{
  */

/** @addtogroup PWR_Exported_Functions
  * @{
  */

/**
  * @brief  Deinitializes the PWR peripheral registers to their default reset
  * values.
  * @param  None.
  * @retval None.
  */
void PWR_DeInit(void)
{
    RCC_APB1PeriphResetCmd(RCC_APB1Periph_PWR, ENABLE);
    RCC_APB1PeriphResetCmd(RCC_APB1Periph_PWR, DISABLE);
}

/**
  * @brief  Enables or disables access to the RTC and backup registers.
  * @param  state: new state of the access to the RTC and backup
  *         registers. This parameter can be: ENABLE or DISABLE.
  * @retval None.
  */
void PWR_BackupAccessCmd(FunctionalState state)
{
    uint32_t i = 0;
    uint32_t tmpreg = 0; 

    tmpreg = RCC->BDCR;
    for(i=0; i<30000; i++)
    {
        __NOP();
    }

    (state) ? \
    (tmpreg |=  (0x01U << RCC_BDCR_DBP_Pos)) : \
    (tmpreg &= ~(0x01U << RCC_BDCR_DBP_Pos)) ;

    RCC->BDCR = tmpreg;
    for(i=0; i<10000; i++)
    {
        __NOP();
    }
}

/**
  * @brief  Enables or disables the WakeUp Pin functionality.
  * @param  pinx: slect wakeup pin
  *         This parameter can be one of the following values:
  * @arg    WAKEUP_PIN0
  * @arg    WAKEUP_PIN1
  * @arg    WAKEUP_PIN2
  * @arg    WAKEUP_PIN3
  * @arg    WAKEUP_PIN4
  * @arg    WAKEUP_PIN5
  * @param  state: new state of the WakeUp Pin functionality.
  *         This parameter can be: ENABLE or DISABLE.
  * @retval None.
  */
void PWR_WakeUpPinXCmd(uint8_t pin, FunctionalState state)
{
    (state) ? \
    (PWR->CR2 |=  pin) : \
    (PWR->CR2 &= ~pin);
}

/**
  * @brief  Enters SLEEP mode.
  * @param  regulator: specifies the regulator state in STOP mode.
  *         This parameter can be one of the following values:
  * @arg    PWR_Regulator_ON:  with regulator ON
  * @arg    PWR_Regulator_LowPower:  with regulator in low power mode.
  * @param  sleep_entry: Select Enter mode of SLEEP to execute related instructions
  *         This parameter can be one of the following values:
  * @arg    PWR_SLEEPNOW_WFI: enter SLEEPNOW mode with WFI instruction
  * @arg    PWR_SLEEPNOW_WFE: enter SLEEPNOW mode with WFE instruction
  * @arg    PWR_SLEEPONEXIT : enter SLEEPONEXIT mode with WFI instruction
  * @retval None.
  */
void PWR_EnterSLEEPMode(uint32_t regulator, uint32_t sleep_entry)
{
    MODIFY_REG(PWR->CR1, PWR_CR1_LPR_Msk, regulator);
    SCB->SCR &= ~SCB_SCR_SLEEPDEEP_Msk;
    if((sleep_entry == PWR_SLEEPNOW_WFE) || (sleep_entry == PWR_SLEEPNOW_WFI))
    {
        SCB->SCR &= SCB_SCR_SLEEPONEXIT_Msk;
        if(sleep_entry == PWR_SLEEPNOW_WFI)
        {
            __WFI();
        }
        else
        {
            __SEV();
            __WFE();
            __WFE();
        }
    }
    else if (sleep_entry == PWR_SLEEPONEXIT)
    {
        SCB->SCR |= SCB_SCR_SLEEPONEXIT_Msk;
		__WFI();
    }  
}

/**
  * @brief  Enters STOP mode.
  * @param  stop_mode: 
  *         This parameter can be one of the following values:
  * @arg    PWR_MODE_STOP:  
  * @arg    PWR_MODE_DEEPSTOP: 
  * @param  stop_entry: specifies if STOP mode in entered with WFI or  WFE instruction.
  *         This parameter can be one of the following values:
  * @arg    PWR_STOPEntry_WFI: enter STOP mode with WFI instruction
  * @arg    PWR_STOPEntry_WFE: enter STOP mode with WFE instruction
  * @retval None.
  */
void PWR_EnterSTOPMode(uint32_t stop_mode, uint32_t stop_entry)
{
	uint32_t tmpreg1 = 0;
    uint32_t tmpreg2 = 0;
	
    if (stop_mode == PWR_MODE_STOP)
    {
        PWR->CR1 &= ~PWR_CR1_LPDS_Msk;
        SCB->SCR |= SCB_SCR_SLEEPDEEP_Msk;
    }
    else
    {
        PWR->CR1 &= ~PWR_CR1_PDDS_Msk;
        PWR->CR1 |= PWR_CR1_LPDS_Msk;
        SCB->SCR |= SCB_SCR_SLEEPDEEP_Msk;
    }


    tmpreg1 = RCC->CFGR;
    tmpreg2 = FLASH->ACR;

    /* To ensure that the instruction is deterministic after awakening, turn off the prefetch function before stop. */
    RCC->CFGR &= ~(RCC_CFGR_HPRE_Msk | RCC_CFGR_SW_Msk);
    FLASH->ACR &= ~FLASH_ACR_LATENCY_Msk;

    FLASH->ACR &= ~FLASH_ACR_PRFTBE_Msk;
    while((FLASH->ACR & FLASH_ACR_PRFTBS_Msk) != 0)
    {
    }   

    if (stop_entry == PWR_STOPEntry_WFI)
    {
        __WFI();
    }
    else
    {
        __SEV();
        __WFE();
        __WFE();
    }

	SCB->SCR &= ~SCB_SCR_SLEEPDEEP_Msk;
	
    FLASH->ACR = tmpreg2 & FLASH_ACR_PRFTBE_Msk;
    FLASH->ACR = tmpreg2;
    RCC->CFGR = tmpreg1 & 0xFFFFFFF0;
}

/**
  * @brief  Enters STANDBY mode.
  * @param  None.
  * @retval None.
  */
void PWR_EnterSTANDBYMode(void)
{
    PWR->CR1 |= PWR_CR1_PDDS_Msk;
    SCB->SCR |= SCB_SCR_SLEEPDEEP_Msk;

#if defined(__CC_ARM)
    __force_stores();
#endif
    __WFI();
}


/**
  * @brief  Checks whether the specified PWR flag is set or not.
  * @param  flag: specifies the flag to check.
  *         This parameter can be one of the following values:
  * @arg    PWR_FLAG_SB: StandBy flag
  * @arg    PWR_FLAG_SD: Shutdown Flag
  * @retval The new state of PWR_FLAG (SET or RESET).
  */
FlagStatus PWR_GetFlagStatus(uint32_t flag)
{
    return (FlagStatus)(PWR->CSR & flag);
}

/**
  * @brief  Clears the PWR's pending flags.
  * @param  flag: specifies the flag to clear.
  *         This parameter can be one of the following values:
  * @arg    PWR_FLAG_SB: StandBy flag
  * @retval None.
  */
void PWR_ClearFlag(uint32_t flag)
{
    PWR->CR1 |= flag << 2;
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
