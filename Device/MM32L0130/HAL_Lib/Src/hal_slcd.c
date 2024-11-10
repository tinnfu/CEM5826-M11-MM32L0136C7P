/***********************************************************************************************************************
    @file     hal_slcd.c
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
#define _HAL_SLCD_C_

/* Files includes ------------------------------------------------------------*/
#include "hal_slcd.h"

/** @addtogroup MM32_Hardware_Abstract_Layer
  * @{
  */

/** @addtogroup SLCD_HAL
  * @{
  */

/** @addtogroup SLCD_Exported_Functions
  * @{
  */

/**
  * @brief  Deinitializes the SLCD peripheral registers to their default reset
  *         values.
  * @param  None
  * @retval None
  */
void SLCD_DeInit(void)
{
    uint32_t i = 0;
    uint32_t tmpreg = 0; 


    tmpreg = RCC->BDCR;
    for(i=0; i<30000; i++)
    {
        __NOP();
    }

    /* Enable SLCD reset state */
    tmpreg |= (0x01U << RCC_BDCR_LCDRST_Pos);

    RCC->BDCR = tmpreg;
    for(i=0; i<10000; i++)
    {
        __NOP();
    }

    /* Clear bit and SLCD from reset state */
    tmpreg &= ~(0x01U << RCC_BDCR_LCDRST_Pos);

    RCC->BDCR = tmpreg;
    for(i=0; i<10000; i++)
    {
        __NOP();
    }
}

/**
  * @brief  Initializes the SLCD peripheral according to the specified parameters
  *         in the init_struct.
  * @note   This function can be used only when the SLCD is disabled and SLCD clock is enable.
  * @param  init_struct: pointer to a SLCD_InitTypeDef structure that contains
  *         the configuration information for the specified SLCD peripheral.
  * @retval None
  */
void SLCD_Init(SLCD_InitTypeDef* init_struct)
{
    SLCD_Cmd(DISABLE);
    SLCD->FCR &= ~(SLCD_FCR_PS_Msk | SLCD_FCR_DIV_Msk);
    SLCD->FCR |= (init_struct->SLCD_Prescaler | init_struct->SLCD_Divider);

    SLCD_WaitForSynchro();

    SLCD->CR &= ~(SLCD_CR_DUTY_Msk | SLCD_CR_BIAS_Msk | SLCD_CR_VDDEN_Msk | SLCD_CR_REFEN_Msk);
    SLCD->CR |= (init_struct->SLCD_Duty | init_struct->SLCD_Bias);
    if(init_struct->SLCD_Bias != SLCD_Bias_Static) 
    {
        /* When the BIAS is 2'b11: static bias, CPMODE needs to be configured as the internal 
           charge pump disable. It doesn't support the internal charge pump up/down voltage 
           under static bias. */
        if(init_struct->SLCD_VoltageSource == SLCD_VoltSrcCapCharggUpLowRef) 
        {
            /* Bias voltage generation mode 1 - internal charge pump up voltage */
            SLCD_ChargePumpModeConfig(SLCD_ChargePump_2);
            SLCD_Internal_VddCmd(DISABLE);
            SLCD_InternalVrefCmd(ENABLE);
        }
        else if(init_struct->SLCD_VoltageSource == SLCD_VoltSrcCapCharggDownVdd) 
        {
            /* Bias voltage generation mode 2 - internal charge pump down voltage */
            SLCD_ChargePumpModeConfig(SLCD_ChargePump_3);
            SLCD_InternalVrefCmd(DISABLE);
            SLCD_Internal_VddCmd(ENABLE);
        }
        else if(init_struct->SLCD_VoltageSource == SLCD_VoltSrcCapCharggUpLowExt) 
        {
            /* Bias voltage generation mode 1 - internal charge pump up voltage */
            SLCD_ChargePumpModeConfig(SLCD_ChargePump_2);
            SLCD_Internal_VddCmd(DISABLE);
            SLCD_InternalVrefCmd(DISABLE);
        }
        else if(init_struct->SLCD_VoltageSource == SLCD_VoltSrcCapCharggDownHighExt) 
        {
            /* Bias voltage generation mode 2 - internal charge pump down voltage */
            SLCD_ChargePumpModeConfig(SLCD_ChargePump_3);
            SLCD_InternalVrefCmd(DISABLE);
            SLCD_Internal_VddCmd(DISABLE);
        }
    }
    else 
    {
        if(init_struct->SLCD_VoltageSource == SLCD_VoltSrcResDivion_Ext) 
        {
            /* internal charge pump closes, External resistor division with external Power */
            SLCD_ChargePumpModeConfig(SLCD_ChargePump_0);
            SLCD_Internal_VddCmd(DISABLE);
            SLCD_InternalVrefCmd(DISABLE);
        }
        else if(init_struct->SLCD_VoltageSource == SLCD_VoltSrcResDivion_Vdd) 
        {
            /* internal charge pump closes, External resistor division with internal VDD */
            SLCD_ChargePumpModeConfig(SLCD_ChargePump_0);
            SLCD_InternalVrefCmd(DISABLE);
            SLCD_Internal_VddCmd(ENABLE);
        }
    }
}

/**
  * @brief  Fills each init_struct member with its default value.
  * @param  init_struct: pointer to a SLCD_InitTypeDef structure which will
  *         be initialized.
  * @retval None
  */
void SLCD_StructInit(SLCD_InitTypeDef* init_struct)
{
    /* Reset SLCD init structure parameters values */
    init_struct->SLCD_Prescaler = SLCD_Prescaler_16;
    init_struct->SLCD_Divider = SLCD_Divider_16;
    init_struct->SLCD_Duty = SLCD_Duty_1_4;
    init_struct->SLCD_Bias = SLCD_Bias_1_3;
    init_struct->SLCD_VoltageSource = SLCD_VoltSrcCapCharggUpLowRef;
}

/**
  * @brief  Enables or disables the SLCD Controller.
  * @param  state: new state of the specified peripheral clock.
  *         This parameter can be: ENABLE or DISABLE.
  * @retval None.
  */
void SLCD_Cmd(FunctionalState state)
{
    (state == ENABLE) ?                          \
    (SLCD->CR |= (0x01U << SLCD_CR_LCDEN_Pos)) : \
    (SLCD->CR &= ~(0x01U << SLCD_CR_LCDEN_Pos));
}

/**
  * @brief  Waits until the SLCD FCR register is synchronized in the SLCDCLK domain.
  *         This function must be called after any write operation to SLCD_FCR register.
  * @param  None
  * @retval None
  */
void SLCD_WaitForSynchro(void)
{
    while ((SLCD->SR & SLCD_SR_FCRSF_Msk) == (uint32_t)RESET)    
    {
    }
}

/**
  * @brief  Low power drive waveform enable or disable.
  * @param  state: new state of the low power drive waveform.
  *   This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
void SLCD_LowPowerDriveCmd(FunctionalState state)
{
    (state) ?                                   \
    (SLCD->CR |= (0x01U << SLCD_CR_LPEN_Pos)) : \
    (SLCD->CR &= ~(0x01U << SLCD_CR_LPEN_Pos));
}

/**
  * @brief  Internal VDD enable or disable.
  * @param  state: new state of the internal VDD.
  *   This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
void SLCD_Internal_VddCmd(FunctionalState state)
{
    (state) ?                                    \
    (SLCD->CR |= (0x01U << SLCD_CR_VDDEN_Pos)) : \
    (SLCD->CR &= ~(0x01U << SLCD_CR_VDDEN_Pos));
}

/**
  * @brief  Internal voltage reference enable or disable.
  * @param  state: new state of the internal voltage reference.
  *   This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
void SLCD_InternalVrefCmd(FunctionalState state)
{
    (state) ?                                    \
    (SLCD->CR |= (0x01U << SLCD_CR_REFEN_Pos)) : \
    (SLCD->CR &= ~(0x01U << SLCD_CR_REFEN_Pos));
}

/**
  * @brief  Configures the SLCD charge pump mode.
  * @param  SLCD_ChargePump: specifies the SLCD charge pump mode.
  *         This parameter can be one of the following values:
  *     @arg SLCD_ChargePump_0
  *     @arg SLCD_ChargePump_1
  *     @arg SLCD_ChargePump_2
  *     @arg SLCD_ChargePump_3
  * @retval None
  */
void SLCD_ChargePumpModeConfig(uint32_t SLCD_ChargePump)
{
    MODIFY_REG(SLCD->CR, SLCD_CR_CPMODE_Msk, SLCD_ChargePump);
}

/**
  * @brief  Get the SLCD config charge pump mode.
  * @param  None
  * @retval
  *          SLCD_ChargePump_0
  *          SLCD_ChargePump_1
  *          SLCD_ChargePump_2
  *          SLCD_ChargePump_3
  */
uint32_t SLCD_GetChargePumpMode(void)
{
    return (SLCD->CR & SLCD_CR_CPMODE_Msk);
}

/**
  * @brief  Configures the SLCD dead time.
  * @param  SLCD_DeadTime: specifies the SLCD dead time.
  *         This parameter can be one of the following values:
  *     @arg SLCD_DeadTime_0: No dead Time
  *     @arg SLCD_DeadTime_1: 1 Phase insert
  *     @arg SLCD_DeadTime_2: 2 Phase insert
  *     @arg SLCD_DeadTime_3: 3 Phase insert
  *     @arg SLCD_DeadTime_4: 4 Phase insert
  *     @arg SLCD_DeadTime_5: 5 Phase insert
  *     @arg SLCD_DeadTime_6: 6 Phase insert
  *     @arg SLCD_DeadTime_7: 7 Phase insert
  * @retval None
  */
void SLCD_DeadTimeConfig(uint32_t SLCD_DeadTime)
{
    MODIFY_REG(SLCD->FCR, SLCD_FCR_DEAD_Msk, SLCD_DeadTime);
}

/**
  * @brief  Configures the SLCD Blink mode and Blink frequency.
  * @param  SLCD_BlinkMode: specifies the SLCD blink mode.
  *   This parameter can be one of the following values:
  *     @arg SLCD_BlinkMode_Off
  *     @arg SLCD_BlinkMode_Corrspond_SEG_COM
  *     @arg SLCD_BlinkMode_AllSEG_AllCOM
  *     @arg SLCD_BlinkMode_Switch
  * @param  SLCD_BlinkFrequency: specifies the SLCD blink frequency.
  *   This parameter can be one of the following values:
  *     @arg SLCD_BlinkFrequency_Div32
  *     @arg SLCD_BlinkFrequency_Div64
  *     @arg SLCD_BlinkFrequency_Div128
  *     @arg SLCD_BlinkFrequency_Div256
  *     @arg SLCD_BlinkFrequency_Div512
  *     @arg SLCD_BlinkFrequency_Div1024
  *     @arg SLCD_BlinkFrequency_Div2048
  *     @arg SLCD_BlinkFrequency_Div4096
  * @retval None
  */
void SLCD_BlinkConfig(uint32_t SLCD_BlinkMode, uint32_t SLCD_BlinkFrequency)
{
    MODIFY_REG(SLCD->FCR, SLCD_FCR_BLINK_Msk | SLCD_FCR_BLINKF_Msk, SLCD_BlinkMode | SLCD_BlinkFrequency);
}

/**
  * @brief  Configures the SLCD charge pump clock division.
  * @param  SLCD_ChargePumpDiv: specifies the SLCD charge pump clock division.
  *         This parameter can be one of the following values:
  *     @arg SLCD_ChargePumpClock_Div32
  *     @arg SLCD_ChargePumpClock_Div64
  *     @arg SLCD_ChargePumpClock_Div128
  *     @arg SLCD_ChargePumpClock_Div256
  *     @arg SLCD_ChargePumpClock_Div512
  *     @arg SLCD_ChargePumpClock_Div1024
  *     @arg SLCD_ChargePumpClock_Div2048
  *     @arg SLCD_ChargePumpClock_Div4096
  * @retval None
  */
void SLCD_ChargePumpClockDivConfig(uint32_t SLCD_ChargePumpDiv)
{
    MODIFY_REG(SLCD->FCR, SLCD_FCR_CPDIV_Msk, SLCD_ChargePumpDiv);
}

/**
  * @brief  Configures the SLCD Contrast.
  * @param  SLCD_Contrast: specifies the SLCD Contrast.
  *   This parameter can be one of the following values:
  *     @arg SLCD_Contrast_Level_0
  *     @arg SLCD_Contrast_Level_1
  *     @arg SLCD_Contrast_Level_2
  *     @arg SLCD_Contrast_Level_3
  *     @arg SLCD_Contrast_Level_4
  *     @arg SLCD_Contrast_Level_5
  *     @arg SLCD_Contrast_Level_6
  *     @arg SLCD_Contrast_Level_7
  *     @arg SLCD_Contrast_Level_8
  *     @arg SLCD_Contrast_Level_9
  *     @arg SLCD_Contrast_Level_10
  *     @arg SLCD_Contrast_Level_11
  *     @arg SLCD_Contrast_Level_12
  *     @arg SLCD_Contrast_Level_13
  *     @arg SLCD_Contrast_Level_14
  *     @arg SLCD_Contrast_Level_15
  * @retval None
  */
void SLCD_ContrastConfig(uint32_t SLCD_Contrast)
{
    MODIFY_REG(SLCD->FCR, SLCD_FCR_CC_Msk, SLCD_Contrast);
}

/**
  * @brief  Enables or disables the SLCD DMA interface.
  * @param  state: new state of the DMA Request sources, it can be: ENABLE or DISABLE.
  * @retval None.
  */
void SLCD_DMACmd(FunctionalState state)
{
    (state) ?                                      \
    (SLCD->FCR |= (0x01U << SLCD_FCR_DMAEN_Pos)) : \
    (SLCD->FCR &= ~(0x01U << SLCD_FCR_DMAEN_Pos));
}

/**
  * @brief  Enables or disables the SLCD Display register selection.
  * @param  state: new state of the  SLCD Display register selection, it can be: ENABLE or DISABLE.
  * @retval None.
  */
void SLCD_Display_register_selection(FunctionalState state)
{
    (state) ?                                      \
    (SLCD->FCR |= (0x01U << SLCD_FCR_DRSEL_Pos)) : \
    (SLCD->FCR &= ~(0x01U << SLCD_FCR_DRSEL_Pos));
}

/**
  * @brief  Writes a word in the specific SLCD RAM.
  * @param  offset: specifies the SLCD Contrast.
  *   This parameter can be one of the following values(0 to 15)
  * @param  data: specifies SLCD Data Value to be written.
  * @retval None
  */
void SLCD_Write(uint32_t offset, uint32_t data)
{
    /* Copy data bytes to RAM register */
    SLCD->DR[offset & 0xF] = (uint32_t)data;
}

/**
  * @brief  Checks whether the specified SLCD flag is set or not.
  * @param  flag: specifies the flag to check.
  *   This parameter can be one of the following values:
  *     @arg SLCD_FLAG_ENS
  *     @arg SLCD_FLAG_EOF
  *     @arg SLCD_FLAG_BLKF
  *     @arg SLCD_FLAG_DRSS
  *     @arg SLCD_FLAG_FCRSF
  *       This flag is set by hardware.
  * @retval The new state of flag (SET or RESET).
  */
FlagStatus SLCD_GetFlagStatus(uint32_t flag)
{
    return ((SLCD->SR & flag) ? SET : RESET);
}

/**
  * @brief  Clears the SLCD's pending flags.
  * @param  flag: specifies the flag to clear.
  *   This parameter can be any combination of the following values:
  *     @arg SLCD_STATUS_CLEAR_EOFC: Start of Frame Interrupt
  *     @arg SLCD_STATUS_CLEAR_BLKC: Update Display Done Interrupt
  * @retval None
  */
void SLCD_ClearFlag(uint32_t flag)
{
    /* Clear SLCD flag */
    SLCD->CLRR = flag;
}

/**
  * @brief  Enables or disables the specified SLCD interrupts.
  * @param  it: specifies the SLCD interrupts sources to be enabled or disabled.
  *   This parameter can be any combination of the following values:
  *     @arg SLCD_IT_EOFIE: Start of Frame Interrupt
  *     @arg SLCD_IT_BLKIE: Update Display Done Interrupt
  * @param state: new state of the specified SLCD interrupts.
  *   This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
void SLCD_ITConfig(uint32_t it, FunctionalState state)
{
    (state) ?                                  \
    (SLCD->FCR |= (it | SLCD_FCR_LCDIE_Msk)) : \
    (SLCD->FCR &= ~(it | SLCD_FCR_LCDIE_Msk));
}

/**
  * @brief  Checks whether the specified RTC interrupt has occurred or not.
  * @param  it: specifies the SLCD interrupts sources to check.
  *   This parameter can be one of the following values:
  *     @arg SLCD_IT_STATUS_EOFS: Start of Frame Interrupt
  *     @arg SLCD_IT_STATUS_BLKS: Update Display Done Interrupt.
  *     @note If the device is in STOP mode (PCLK not provided) UDD will not
  *          generate an interrupt even if UDDIE = 1.
  *          If the display is not enabled the UDD interrupt will never occur.
  * @retval The new state of the it (SET or RESET).
  */
ITStatus SLCD_GetITStatus(uint32_t it)
{
    return ((SLCD->SR & it) ? SET : RESET);
}

/**
  * @brief  Clears the SLCD's interrupt pending bits.
  * @param  enum_it: specifies the interrupt pending bit to clear.
  *   This parameter can be any combination of the following values:
  *     @arg SLCD_IT_CLEAR_EOFC: Start of Frame Interrupt
  *     @arg SLCD_IT_CLEAR_BLKC: Update Display Done Interrupt
  * @retval None
  */
void SLCD_ClearITPendingBit(uint32_t it)
{
    /* Clear the SLCD interrupt pending bit */
    SLCD->CLRR = it;
}

/**
  * @brief  the SLCD's IO Pin Config as SEG, COM or None.
  * @param  SLCD_IOConfig_TypeDef: specifies the 64 SEG/COM/NONE config.
  *   This parameter can be referred by below sample:
  *     @arg sample
  *         SLCD_IOConfig_TypeDef SEGorCOM[MAX_SLCD_PIN_NUMBER] = {
  *             SLCD_IOConfigSEG,   //SLCD_L0      0        SEG
  *             SLCD_IOConfigCOM,   //SLCD_L1      1        COM
  *             SLCD_IOConfigSEG,   //SLCD_L2      2        SEG
  *             SLCD_IOConfigCOM,   //SLCD_L3      3        COM
  *             SLCD_IOConfigSEG,   //SLCD_L4      4        SEG
  *             SLCD_IOConfigCOM,   //SLCD_L5      5        COM
  *             SLCD_IOConfigSEG,   //SLCD_L6      6        SEG
  *             SLCD_IOConfigCOM,   //SLCD_L7      7        COM
  *             SLCD_IOConfigSEG,   //SLCD_L8      8        SEG
  *             SLCD_IOConfigSEG,   //SLCD_L9      9        SEG
  *             SLCD_IOConfigSEG,   //SLCD_L10     10       SEG
  *             SLCD_IOConfigSEG,   //SLCD_L11     11       SEG
  *             SLCD_IOConfigSEG,   //SLCD_L12     12       SEG
  *             SLCD_IOConfigSEG,   //SLCD_L13     13       SEG
  *             SLCD_IOConfigSEG,   //SLCD_L14     14       SEG
  *             SLCD_IOConfigSEG,   //SLCD_L15     15       SEG
  *             SLCD_IOConfigSEG,   //SLCD_L16     16       SEG
  *             SLCD_IOConfigSEG,   //SLCD_L17     17       SEG
  *             SLCD_IOConfigSEG,   //SLCD_L18     18       SEG
  *             SLCD_IOConfigNone,  //SLCD_L19
  *             SLCD_IOConfigNone,  //SLCD_L20
  *             SLCD_IOConfigNone,  //SLCD_L21
  *             SLCD_IOConfigNone,  //SLCD_L22
  *             SLCD_IOConfigNone,  //SLCD_L23
  *             SLCD_IOConfigNone,  //SLCD_L24
  *             SLCD_IOConfigSEG,   //SLCD_L25      25      SEG
  *             SLCD_IOConfigSEG,   //SLCD_L26      26      SEG
  *             SLCD_IOConfigSEG,   //SLCD_L27      27      SEG
  *             SLCD_IOConfigSEG,   //SLCD_L28      28      SEG
  *             SLCD_IOConfigSEG,   //SLCD_L29      29      SEG
  *             SLCD_IOConfigSEG,   //SLCD_L30      30      SEG
  *             SLCD_IOConfigSEG,   //SLCD_L31      31      SEG
  *             SLCD_IOConfigSEG,   //SLCD_L32      32      SEG
  *             SLCD_IOConfigSEG,   //SLCD_L33      33      SEG
  *             SLCD_IOConfigSEG,   //SLCD_L34      34      SEG
  *             SLCD_IOConfigSEG,   //SLCD_L35      35      SEG
  *             SLCD_IOConfigSEG,   //SLCD_L36      36      SEG
  *             SLCD_IOConfigSEG,   //SLCD_L37      37      SEG
  *             SLCD_IOConfigSEG,   //SLCD_L38      38      SEG
  *             SLCD_IOConfigSEG,   //SLCD_L39      39      SEG
  *             SLCD_IOConfigNone,  //SLCD_L40
  *             SLCD_IOConfigSEG,   //SLCD_L41      41      SEG
  *             SLCD_IOConfigNone,  //SLCD_L42
  *             SLCD_IOConfigNone,  //SLCD_L43
  *             SLCD_IOConfigNone,  //SLCD_L44
  *             SLCD_IOConfigNone,  //SLCD_L45
  *             SLCD_IOConfigNone,  //SLCD_L46
  *             SLCD_IOConfigNone,  //SLCD_L47
  *             SLCD_IOConfigNone,  //SLCD_L48
  *             SLCD_IOConfigNone,  //SLCD_L49
  *             SLCD_IOConfigNone,  //SLCD_L50
  *             SLCD_IOConfigNone,  //SLCD_L51
  *             SLCD_IOConfigNone,  //SLCD_L52
  *             SLCD_IOConfigNone,  //SLCD_L53
  *             SLCD_IOConfigNone,  //SLCD_L54
  *             SLCD_IOConfigNone,  //SLCD_L55
  *             SLCD_IOConfigNone,  //SLCD_L56
  *             SLCD_IOConfigNone,  //SLCD_L57
  *             SLCD_IOConfigNone,  //SLCD_L58
  *             SLCD_IOConfigNone,  //SLCD_L59
  *             SLCD_IOConfigNone,  //SLCD_L60
  *             SLCD_IOConfigNone,  //SLCD_L61
  *             SLCD_IOConfigNone,  //SLCD_L62
  *             SLCD_IOConfigNone   //SLCD_L63
  *         };
  * @retval None
  */
void SLCD_IO_Config(uint8_t* seg_com)
{
    uint8_t i, shfitnumber;
    uint32_t tempCFGR0 = 0, tempCFGR1 = 0, tempIOENR0 = 0, tempIOENR1 = 0;

    for(i = 0; i < MAX_SLCD_PIN_NUMBER; i++) 
    {
        if(i < (MAX_SLCD_PIN_NUMBER / 2)) 
        {
            shfitnumber = i & 0x1F;
            if(seg_com[i] == SLCD_IOConfigCOM) 
            {
                tempCFGR0  |= 1 << shfitnumber;
                tempIOENR0 |= 1 << shfitnumber;
            }
            else if(seg_com[i] == SLCD_IOConfigSEG) 
            {
                tempIOENR0 |= 1 << shfitnumber;
            }
        }
        else 
        {
            shfitnumber = i & 0x1F;
            if(seg_com[i] == SLCD_IOConfigCOM) 
            {
                tempCFGR1  |= 1 << shfitnumber;
                tempIOENR1 |= 1 << shfitnumber;
            }
            else if(seg_com[i] == SLCD_IOConfigSEG) 
            {
                tempIOENR1 |= 1 << shfitnumber;
            }
        }
    }

    if(((SLCD->CR & SLCD_CR_CPMODE_Msk) == SLCD_ChargePump_2) || ((SLCD->CR & SLCD_CR_CPMODE_Msk) == SLCD_ChargePump_3)) 
    {
        tempIOENR1 &= ~(SLCD_L63 | SLCD_L62);
    }
    if((SLCD->CR & SLCD_CR_BIAS_Msk) == SLCD_Bias_1_4) 
    {
        tempIOENR1 &= ~(SLCD_L61 | SLCD_L60 | SLCD_L59 | SLCD_L58);
    }
    else if((SLCD->CR & SLCD_CR_BIAS_Msk) == SLCD_Bias_1_3) 
    {
        tempIOENR1 &= ~(SLCD_L61 | SLCD_L60 | SLCD_L59);
    }
    else if((SLCD->CR & SLCD_CR_BIAS_Msk) == SLCD_Bias_1_2) 
    {
        tempIOENR1 &= ~(SLCD_L61 | SLCD_L60);
    }
    else 
    {
        tempIOENR1 &= ~(SLCD_L61);
    }

    SLCD->CFGR0 = tempCFGR0;
    SLCD->CFGR1 = tempCFGR1;
    SLCD->IOENR0 = tempIOENR0;
    SLCD->IOENR1 = tempIOENR1;
}

/**
  * @brief  The SLCD's COM mapping index.
  * @param  pcom_index: specifies the 7 COM index.
  *   This parameter can be referred by below sample:
  *     @arg sample
  *         uint8_t SCLD_COM_Index[COM_INDEX_MAX] = {
  *             7,  //COM0 point to SLCD_L7
  *             5,  //COM1 point to SLCD_L5
  *             3,  //COM2 point to SLCD_L3
  *             1,  //COM3 point to SLCD_L1
  *             54, //COM4 point to SLCD_L54
  *             55, //COM5 point to SLCD_L55
  *             56, //COM6 point to SLCD_L56
  *             57, //COM7 point to SLCD_L57
  *         };
  * @retval None
  */
void SLCD_COM_IndexInit(uint8_t* pcom_index)
{
    uint8_t i;
    uint32_t tempdata = 0, temp_com_index0 = 0, temp_com_index1;

    for(i = 0; i < COM_INDEX_MAX; i++) 
    {
        tempdata = (uint32_t)((*pcom_index) & 0x3F);
        pcom_index++;
        if(i < 4) 
        {
            temp_com_index0 |= tempdata << ((i & 0x03) * 8);
        }
        else 
        {
            temp_com_index1 |= tempdata << ((i & 0x03) * 8);
        }
    }
    SLCD->IDXR0 = temp_com_index0;
    SLCD->IDXR1 = temp_com_index1;
}

/**
  * @brief  the SLCD's BLINK is Enable or Disable, BLINK map to which COM and SEG.
  * @param  blink_index: specifies the 8 BLINK config(ENABLE, COM, SEG).
  *   This parameter can be referred by below sample:
  *     @arg sample
  *         uint8_t SCLD_BLINK_Index[COM_INDEX_MAX * BLINK_INDEX_STEP] = {
  *             1, 0, 0,  //BLINK_Index0 is Enable, BLINK_Index0 point to COM0 and SEG0
  *             1, 1, 1,  //BLINK_Index1 is Enable, BLINK_Index1 point to COM1 and SEG1
  *             1, 2, 2,  //BLINK_Index2 is Enable, BLINK_Index2 point to COM2 and SEG2
  *             1, 3, 3,  //BLINK_Index3 is Enable, BLINK_Index3 point to COM3 and SEG3
  *             1, 4, 4,  //BLINK_Index4 is Enable, BLINK_Index4 point to COM4 and SEG4
  *             1, 5, 5,  //BLINK_Index5 is Enable, BLINK_Index5 point to COM5 and SEG5
  *             1, 6, 6,  //BLINK_Index6 is Enable, BLINK_Index6 point to COM6 and SEG6
  *             1, 7, 7,  //BLINK_Index7 is Enable, BLINK_Index7 point to COM7 and SEG7
  *         };
  * @retval None
  */
void SLCD_BLINK_IndexInit(uint8_t* blink_index)
{
    uint8_t i;
    uint32_t tempdata = 0;
    uint32_t tempbuf[COM_INDEX_MAX];

    for(i = 0; i < COM_INDEX_MAX; i++) 
    {
        tempdata = 0;
        tempdata |= ((uint32_t)((*(blink_index + i * BLINK_INDEX_STEP + 0)) & 0x01)) << 15;
        tempdata |= ((uint32_t)((*(blink_index + i * BLINK_INDEX_STEP + 1)) & 0x07)) << 8;
        tempdata |= ((uint32_t)((*(blink_index + i * BLINK_INDEX_STEP + 2)) & 0x3F)) << 0;
        tempbuf[i] = tempdata;
    }

    SLCD->BLKR0 = ((tempbuf[1]) << 16) | tempbuf[0];
    SLCD->BLKR1 = ((tempbuf[3]) << 16) | tempbuf[2];
    SLCD->BLKR2 = ((tempbuf[5]) << 16) | tempbuf[4];
    SLCD->BLKR3 = ((tempbuf[7]) << 16) | tempbuf[6];
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

