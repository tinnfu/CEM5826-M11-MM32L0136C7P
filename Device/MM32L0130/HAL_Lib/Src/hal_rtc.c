/***********************************************************************************************************************
    @file     hal_rtc.c
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

/* Files includes ------------------------------------------------------------*/
#include "hal_rtc.h"

/** @addtogroup MM32_Hardware_Abstract_Layer
  * @{
  */


/**
  * @brief  Enters the RTC Initialization mode.
  * @param  None
  * @retval An ErrorStatus enumeration value:
  *          - SUCCESS: RTC is in Init mode
  *          - ERROR: RTC is not in Init mode
  */
ErrorStatus RTC_EnterInitMode(void)
{
    __IO uint32_t initcounter = 0x00;
    ErrorStatus status = ERROR;
    uint32_t initstatus = 0x00;

    /* Check if the Initialization mode is set */
    if ((RTC->ISR & RTC_ISR_INITF_Msk) == (uint32_t)RESET) 
    {
        /* Set the Initialization mode */
        RTC->ISR |= (0x01U << RTC_ISR_INIT_Pos);

        /* Wait till RTC is in INIT state and if Time out is reached exit */
        do {
            initstatus = RTC->ISR & RTC_ISR_INITF_Msk;
            initcounter++;
        } while((initcounter != INITMODE_TIMEOUT) && (initstatus == 0x00));

        if ((RTC->ISR & RTC_ISR_INITF_Msk) != (uint32_t)RESET)
        {
            status = SUCCESS;
        }
        else
        {
            status = ERROR;
        }
    }
    else 
    {
        status = SUCCESS;
    }

    return (status);
}

/**
  * @brief  Deinitializes the RTC registers to their default reset values.
  * @note   This function doesn't reset the RTC Clock source and RTC Backup Data
  *         registers.
  * @param  None
  * @retval An ErrorStatus enumeration value:
  *          - SUCCESS: RTC registers are deinitialized
  *          - ERROR: RTC registers are not deinitialized
  */
ErrorStatus RTC_DeInit(void)
{
    __IO uint32_t wutcounter = 0x00;
    uint32_t wutwfstatus = 0x00;
    ErrorStatus status = ERROR;

    /* Set Initialization mode */
    if (RTC_EnterInitMode() == ERROR) 
    {
        status = ERROR;
    }
    else 
    {
        /* Reset TR, DR and CR registers */
        RTC->TR = (uint32_t)0x00000000;
        RTC->DR = (uint32_t)0x00002101;
        /* Reset All CR bits except CR[2:0] */
        RTC->CR &= (uint32_t)0x00000007;

        /* Wait till RTC WUTWF flag is set and if Time out is reached exit */
        do {
            wutwfstatus = RTC->ISR & RTC_ISR_WUTWF_Msk;
            wutcounter++;
        } while((wutcounter != INITMODE_TIMEOUT) && (wutwfstatus == 0x00));

        if ((RTC->ISR & RTC_ISR_WUTWF_Msk) == RESET) 
        {
            status = ERROR;
        }
        else 
        {
            /* Reset all RTC CR register bits */
            RTC->CR &= (uint32_t)0x00000000;
            RTC->WUTR = (uint32_t)0x0000FFFF;
            RTC->PRER = (uint32_t)0x007F00FF;
            RTC->ALARMAR = (uint32_t)0x00000000;
            RTC->SHIFTR = (uint32_t)0x00000000;
            RTC->CALR = (uint32_t)0x00000000;
            RTC->ALARMASSR = (uint32_t)0x00000000;

            /* Reset ISR register and exit initialization mode */
            RTC->ISR = (uint32_t)0x00000000;

            /* Reset Tamper and alternate functions configuration register */
            RTC->TAMPCR = 0x00000000;

            if(RTC_WaitForSynchro() == ERROR) 
            {
                status = ERROR;
            }
            else 
            {
                status = SUCCESS;
            }
        }
    }
    return status;
}

/**
  * @brief  Converts a 2 digit decimal to BCD format.
  * @param  Value: Byte to be converted.
  * @retval Converted byte
  */
static uint8_t RTC_ByteToBcd2(uint8_t value)
{
    return (((value / 10) << 4) + (value % 10));
}

/**
  * @brief  Convert from 2 digit BCD to Binary.
  * @param  Value: BCD value to be converted.
  * @retval Converted word
  */
static uint8_t RTC_Bcd2ToByte(uint8_t value)
{
    return ((uint8_t)((value >> 4) * 10 + (value & 0x0F)));
}



/**
  * @brief  Fills each init_struct member with its default value.
  * @param  init_struct: pointer to a RTC_InitTypeDef structure which will be
  *         initialized.
  * @retval None
  */
void RTC_StructInit(RTC_InitTypeDef* init_struct)
{
    /* Initialize the RTC_InitTypeDef member to default value */
    init_struct->RTC_HourFormat = RTC_HourFormat_24;
    init_struct->RTC_AsynchPrediv = (uint32_t)0x7F;
    init_struct->RTC_SynchPrediv = (uint32_t)0xFF;
}

/**
  * @brief  Initializes the RTC registers according to the specified parameters
  *         in init_struct.
  * @param  init_struct: pointer to a RTC_InitTypeDef structure that contains
  *         the configuration information for the RTC peripheral.
  * @retval An ErrorStatus enumeration value:
  *          - SUCCESS: RTC registers are initialized
  *          - ERROR: RTC registers are not initialized
  */
ErrorStatus RTC_Init(RTC_InitTypeDef* init_struct)
{
    ErrorStatus status = ERROR;

    /* Set Initialization mode */
    if (RTC_EnterInitMode() == ERROR) 
    {
        status = ERROR;
    }
    else 
    {
        /* Clear RTC CR FMT Bit */
        RTC->CR &= ((uint32_t)(~(RTC_CR_FMT_Msk)));
        /* Set RTC_CR register */
        RTC->CR |=  ((uint32_t)(init_struct->RTC_HourFormat));
        /* Configure the RTC PRER */
        RTC->PRER = (uint32_t)(((init_struct->RTC_SynchPrediv) << RTC_PRER_PREDIV_S_Pos) & RTC_PRER_PREDIV_S_Msk);
        RTC->PRER |= (uint32_t)(((init_struct->RTC_AsynchPrediv) << RTC_PRER_PREDIV_A_Pos) & RTC_PRER_PREDIV_A_Msk);
        /* Exit Initialization mode */
        RTC_ExitInitMode();
        status = SUCCESS;
    }
    return status;
}

/**
  * @brief  Initializes the RTC registers according to the specified parameters
  *         in init_struct.
  * @param  init_struct: pointer to a RTC_LSEConfig_TypeDef structure that contains
  *         the configuration information for the RTC peripheral.

  * @retval An ErrorStatus enumeration value:
  *          - SUCCESS: RTC registers are initialized
  *          - ERROR: RTC registers are not initialized
  */
ErrorStatus RTC_LSEConfig(RTC_LSEConfig_TypeDef* config_struct)
{
    ErrorStatus status = ERROR;
    uint32_t temp = 0;

    if(READ_BIT(RCC->BDCR, RCC_BDCR_LSEON_Msk) != RESET) 
    {
        return status;
    }
    /* Set RTC_LSE_CFG register */
    temp = (uint32_t)(((uint32_t)config_struct->RTC_LSE_TemperatureCompensation)   | \
                 ((uint32_t)config_struct->RTC_LSE_OutputEnhancement)         | \
                 ((uint32_t)config_struct->RTC_LSE_ResistorFeedbackMode)      | \
                 ((uint32_t)config_struct->RTC_LSE_BiasCurrentLevel)          | \
                 ((uint32_t)config_struct->RTC_LSE_AutoGain));
    RTC->LSE_CFG = temp;
    return SUCCESS;
}

/**
  * @brief  Exits the RTC output in remap mode.
  * @param  remap_mode: Select remap mode.
  * @retval None
  */
void RTC_OutputPinRemap(uint32_t remap_mode)
{
    MODIFY_REG(RTC->OR, RTC_OR_REMAP_Msk, remap_mode);
}

/**
  * @brief  Exits the RTC Initialization mode.
  * @note   When the initialization sequence is complete, the calendar restarts
  *         counting after 4 RTCCLK cycles.
  * @param  None
  * @retval None
  */
void RTC_ExitInitMode(void)
{
    /* Exit Initialization mode */
    RTC->ISR &= (uint32_t)~RTC_ISR_INIT_Msk;
}

/**
  * @brief  Waits until the RTC Time and Date registers (RTC_TR and RTC_DR) are
  *         synchronized with RTC APB clock.
  * @note   To read the calendar through the shadow registers after Calendar
  *         initialization, calendar update or after wakeup from low power modes
  *         the software must first clear the RSF flag.
  *         The software must then wait until it is set again before reading
  *         the calendar, which means that the calendar registers have been
  *         correctly copied into the RTC_TR and RTC_DR shadow registers.
  * @param  None
  * @retval An ErrorStatus enumeration value:
  *          - SUCCESS: RTC registers are synchronised
  *          - ERROR: RTC registers are not synchronised
  */
ErrorStatus RTC_WaitForSynchro(void)
{
    ErrorStatus status = ERROR;
    __IO uint32_t synchrocounter = 0;
    uint32_t synchrostatus = 0x00;

    /* Clear RSF flag */
    RTC->ISR &= (uint32_t)RTC_RSF_MASK;

    /* Wait the registers to be synchronised */
    do{
        synchrostatus = RTC->ISR & RTC_ISR_RSF_Msk;
        synchrocounter++;
    } while((synchrocounter != SYNCHRO_TIMEOUT) && (synchrostatus == 0x00));

    if ((RTC->ISR & RTC_ISR_RSF_Msk) != RESET) 
    {
        status = SUCCESS;
    }
    else 
    {
        status = ERROR;
    }
    return (status);
}

/**
  * @brief  Enables or Disables the Bypass Shadow feature.
  * @note   When the Bypass Shadow is enabled the calendar value are taken
  *         directly from the Calendar counter.
  * @param  state: new state of the Bypass Shadow feature.
  *         This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
void RTC_BypassShadowCmd(FunctionalState state)
{
    (state) ? \
    (RTC->CR |=  (0x01U << RTC_CR_BYPSHAD_Pos)) : \
    (RTC->CR &= ~(0x01U << RTC_CR_BYPSHAD_Pos));
}

/** @defgroup RTC_Group2 Time and Date configuration functions
  * @brief   Time and Date configuration functions
  *
  *
  *  ===============================================================================
  *                  ##### Time and Date configuration functions #####
  *  ===============================================================================
  *
  *  [..] This section provide functions allowing to program and read the RTC Calendar
  *       (Time and Date).
  *
  *
  * @brief  Set the RTC current time.
  * @param  RTC_Format: specifies the format of the entered parameters.
  *          This parameter can be  one of the following values:
  *            @arg RTC_Format_BIN:  Binary data format
  *            @arg RTC_Format_BCD:  BCD data format
  * @param  RTC_TimeStruct: pointer to a RTC_TimeTypeDef structure that contains
  *                        the time configuration information for the RTC.
  * @retval An ErrorStatus enumeration value:
  *          - SUCCESS: RTC Time register is configured
  *          - ERROR: RTC Time register is not configured
  */
ErrorStatus RTC_SetTime(uint32_t RTC_Format, RTC_TimeTypeDef* RTC_TimeStruct)
{

    ErrorStatus status = ERROR;
    uint8_t TempHours;
    uint8_t TempMinutes;
    uint8_t TempSeconds;
    uint32_t tmpreg = 0;

    if (RTC_Format == RTC_Format_BIN) {
        TempHours   = RTC_TimeStruct->RTC_Hours;
        TempMinutes = RTC_TimeStruct->RTC_Minutes;
        TempSeconds = RTC_TimeStruct->RTC_Seconds;
    }
    else {
        TempHours   = RTC_Bcd2ToByte(RTC_TimeStruct->RTC_Hours);
        TempMinutes = RTC_Bcd2ToByte(RTC_TimeStruct->RTC_Minutes);
        TempSeconds = RTC_Bcd2ToByte(RTC_TimeStruct->RTC_Seconds);
    }
    if(!(((TempMinutes) <= 59) && ((TempSeconds) <= 59))) 
    {
        return status;
    }
    if ((RTC->CR & RTC_CR_FMT_Msk) != (uint32_t)RESET) 
    {
        if(!((TempHours > 0) && (TempHours <= 12))) {
            return status;
        }
    }
    else 
    {
        if(!((TempHours) <= 23)) 
        {
            return status;
        }
        RTC_TimeStruct->RTC_H12 = RTC_H12_AM;
    }
    status = SUCCESS;
    if (RTC_Format != RTC_Format_BIN)
    {
        tmpreg = (uint32_t)(((uint32_t)(RTC_TimeStruct->RTC_Hours) << 16) | \
                       ((uint32_t)(RTC_TimeStruct->RTC_Minutes) << 8) | \
                       ((uint32_t)RTC_TimeStruct->RTC_Seconds) | \
                       ((uint32_t)(RTC_TimeStruct->RTC_H12) << 16));
    }
    else 
    {
        tmpreg = (uint32_t)(((uint32_t)RTC_ByteToBcd2(RTC_TimeStruct->RTC_Hours) << 16) | \
                       ((uint32_t)RTC_ByteToBcd2(RTC_TimeStruct->RTC_Minutes) << 8) | \
                       ((uint32_t)RTC_ByteToBcd2(RTC_TimeStruct->RTC_Seconds)) | \
                       (((uint32_t)RTC_TimeStruct->RTC_H12) << 16));
    }

    /* Set Initialization mode */
    if (RTC_EnterInitMode() == ERROR) 
    {
        status = ERROR;
    }
    else 
    {
        /* Set the RTC_TR register */
        RTC->TR = (uint32_t)(tmpreg & RTC_TR_RESERVED_MASK);

        /* Exit Initialization mode */
        RTC_ExitInitMode();

        /* If  RTC_CR_BYPSHAD bit = 0, wait for synchro else this check is not needed */
        if ((RTC->CR & RTC_CR_BYPSHAD_Msk) == RESET) {
            if(RTC_WaitForSynchro() == ERROR) {
                status = ERROR;
            }
            else {
                status = SUCCESS;
            }
        }
        else {
            status = SUCCESS;
        }
    }

    return status;
}

/**
  * @brief  Fills each RTC_TimeStruct member with its default value
  *         (Time = 00h:00min:00sec).
  * @param  RTC_TimeStruct: pointer to a RTC_TimeTypeDef structure which will be
  *         initialized.
  * @retval None
  */
void RTC_TimeStructInit(RTC_TimeTypeDef* RTC_TimeStruct)
{
    /* Time = 00h:00min:00sec */
    RTC_TimeStruct->RTC_H12 = RTC_H12_AM;
    RTC_TimeStruct->RTC_Hours = 1;
    RTC_TimeStruct->RTC_Minutes = 0;
    RTC_TimeStruct->RTC_Seconds = 0;
}

/**
  * @brief  Get the RTC current Time.
  * @param  RTC_Format: specifies the format of the returned parameters.
  *          This parameter can be  one of the following values:
  *            @arg RTC_Format_BIN:  Binary data format
  *            @arg RTC_Format_BCD:  BCD data format
  * @param  RTC_TimeStruct: pointer to a RTC_TimeTypeDef structure that will
  *                        contain the returned current time configuration.
  * @retval None
  */
void RTC_GetTime(uint32_t RTC_Format, RTC_TimeTypeDef* RTC_TimeStruct)
{
    uint32_t tmpreg = 0;

    /* Get the RTC_TR register */
    tmpreg = (uint32_t)(RTC->TR & RTC_TR_RESERVED_MASK);

    /* Fill the structure fields with the read parameters */
    RTC_TimeStruct->RTC_Hours = (uint8_t)((tmpreg & (RTC_TR_HT_Msk | RTC_TR_HU_Msk)) >> 16);
    RTC_TimeStruct->RTC_Minutes = (uint8_t)((tmpreg & (RTC_TR_MNT_Msk | RTC_TR_MNU_Msk)) >> 8);
    RTC_TimeStruct->RTC_Seconds = (uint8_t)(tmpreg & (RTC_TR_ST_Msk | RTC_TR_SU_Msk));
    RTC_TimeStruct->RTC_H12 = (uint32_t)((tmpreg & (RTC_TR_PM_Msk)) >> 16);

    /* Check the input parameters format */
    if (RTC_Format == RTC_Format_BIN) 
    {
        /* Convert the structure parameters to Binary format */
        RTC_TimeStruct->RTC_Hours = (uint8_t)RTC_Bcd2ToByte(RTC_TimeStruct->RTC_Hours);
        RTC_TimeStruct->RTC_Minutes = (uint8_t)RTC_Bcd2ToByte(RTC_TimeStruct->RTC_Minutes);
        RTC_TimeStruct->RTC_Seconds = (uint8_t)RTC_Bcd2ToByte(RTC_TimeStruct->RTC_Seconds);
    }
}

/**
  * @brief  Gets the RTC current Calendar Sub seconds value.
  * @note   This function freeze the Time and Date registers after reading the
  *         SSR register.
  * @param  None
  * @retval RTC current Calendar Sub seconds value.
  */
uint32_t RTC_GetSubSecond(void)
{
    uint32_t tmpreg = 0;
    __IO uint32_t readdr;
    /* Get sub seconds values from the correspondent registers */
    tmpreg = (uint32_t)(RTC->SSR);

    /* Read DR register to unfroze calendar registers */
    readdr = RTC->DR;/* (void) (RTC->DR); */

    return (tmpreg);
}

/**
  * @brief  Set the RTC current date.
  * @param  RTC_Format: specifies the format of the entered parameters.
  *          This parameter can be  one of the following values:
  *            @arg RTC_Format_BIN:  Binary data format
  *            @arg RTC_Format_BCD:  BCD data format
  * @param  RTC_DateStruct: pointer to a RTC_DateTypeDef structure that contains
  *                         the date configuration information for the RTC.
  * @retval An ErrorStatus enumeration value:
  *          - SUCCESS: RTC Date register is configured
  *          - ERROR: RTC Date register is not configured
  */
ErrorStatus RTC_SetDate(uint8_t RTC_Format, RTC_DateTypeDef* RTC_DateStruct)
{
    uint32_t tmpreg = 0;
    ErrorStatus status = ERROR;
    uint8_t TempWeekDay;
    uint8_t TempMonth;
    uint8_t TempDate;
    uint8_t TempYear;
    if ((RTC_Format == RTC_Format_BIN) && ((RTC_DateStruct->RTC_Month & 0x10) == 0x10)) 
    {
        RTC_DateStruct->RTC_Month = (RTC_DateStruct->RTC_Month & ((uint32_t)(~(0x10)))) + 0x0A;
    }
    if (RTC_Format == RTC_Format_BIN) 
    {
        TempYear  = RTC_DateStruct->RTC_Year;
        TempMonth = RTC_DateStruct->RTC_Month;
        TempDate  = RTC_DateStruct->RTC_Date;
    }
    else 
    {
        TempYear  = RTC_Bcd2ToByte(RTC_DateStruct->RTC_Year);
        TempMonth = RTC_Bcd2ToByte(RTC_DateStruct->RTC_Month);
        TempDate  = RTC_Bcd2ToByte(RTC_DateStruct->RTC_Date);
    }
    TempWeekDay = RTC_DateStruct->RTC_WeekDay;

    if(!(((TempYear) <= 99) && \
            ((TempMonth) >= 1) && ((TempMonth) <= 12) && \
            ((TempDate) >= 1)  && ((TempDate) <= 31) &&  \
            ((TempWeekDay) >= 1) && ((TempWeekDay) <= 7))) 
    {
        return status;
    }
    status = SUCCESS;
    /* Check the input parameters format */
    if (RTC_Format != RTC_Format_BIN) 
    {
        tmpreg = ((((uint32_t)RTC_DateStruct->RTC_Year) << 16) | \
                  (((uint32_t)RTC_DateStruct->RTC_Month) << 8) | \
                  ((uint32_t)RTC_DateStruct->RTC_Date) | \
                  (((uint32_t)RTC_DateStruct->RTC_WeekDay) << 13));
    }
    else 
    {
        tmpreg = (((uint32_t)RTC_ByteToBcd2(RTC_DateStruct->RTC_Year) << 16) | \
                  ((uint32_t)RTC_ByteToBcd2(RTC_DateStruct->RTC_Month) << 8) | \
                  ((uint32_t)RTC_ByteToBcd2(RTC_DateStruct->RTC_Date)) | \
                  ((uint32_t)RTC_DateStruct->RTC_WeekDay << 13));
    }
    /* Set Initialization mode */
    if (RTC_EnterInitMode() == ERROR) 
    {
        status = ERROR;
    }
    else 
    {
        /* Set the RTC_DR register */
        RTC->DR = (uint32_t)(tmpreg & RTC_DR_RESERVED_MASK);

        /* Exit Initialization mode */
        RTC_ExitInitMode();

        /* If  RTC_CR_BYPSHAD bit = 0, wait for synchro else this check is not needed */
        if ((RTC->CR & RTC_CR_BYPSHAD_Msk) == RESET) 
        {
            if(RTC_WaitForSynchro() == ERROR) 
            {
                status = ERROR;
            }
            else {
                status = SUCCESS;
            }
        }
        else 
        {
            status = SUCCESS;
        }
    }
    return status;
}

/**
  * @brief  Fills each RTC_DateStruct member with its default value
  *         (Monday, January 01 xx00).
  * @param  RTC_DateStruct: pointer to a RTC_DateTypeDef structure which will be
  *         initialized.
  * @retval None
  */
void RTC_DateStructInit(RTC_DateTypeDef* RTC_DateStruct)
{
    /* Monday, January 01 xx00, Monday = 1, January = 1 */
    RTC_DateStruct->RTC_WeekDay = 1;
    RTC_DateStruct->RTC_Date = 1;
    RTC_DateStruct->RTC_Month = 1;
    RTC_DateStruct->RTC_Year = 0;
}

/**
  * @brief  Get the RTC current date.
  * @param  RTC_Format: specifies the format of the returned parameters.
  *          This parameter can be one of the following values:
  *            @arg RTC_Format_BIN: Binary data format
  *            @arg RTC_Format_BCD: BCD data format
  * @param RTC_DateStruct: pointer to a RTC_DateTypeDef structure that will
  *                        contain the returned current date configuration.
  * @retval None
  */
void RTC_GetDate(uint8_t RTC_Format, RTC_DateTypeDef* RTC_DateStruct)
{
    uint32_t tmpreg = 0;

    tmpreg = (uint32_t)(RTC->DR & RTC_DR_RESERVED_MASK);

    /* Fill the structure fields with the read parameters */
    RTC_DateStruct->RTC_Year = (uint8_t)((tmpreg & (RTC_DR_YT_Msk | RTC_DR_YU_Msk)) >> 16);
    RTC_DateStruct->RTC_Month = (uint8_t)((tmpreg & (RTC_DR_MT_Msk | RTC_DR_MU_Msk)) >> 8);
    RTC_DateStruct->RTC_Date = (uint8_t)(tmpreg & (RTC_DR_DT_Msk | RTC_DR_DU_Msk));
    RTC_DateStruct->RTC_WeekDay = (uint8_t)((tmpreg & (RTC_DR_WDU_Msk)) >> 13);

    /* Check the input parameters format */
    if (RTC_Format == RTC_Format_BIN)
    {
        /* Convert the structure parameters to Binary format */
        RTC_DateStruct->RTC_Year = (uint8_t)RTC_Bcd2ToByte(RTC_DateStruct->RTC_Year);
        RTC_DateStruct->RTC_Month = (uint8_t)RTC_Bcd2ToByte(RTC_DateStruct->RTC_Month);
        RTC_DateStruct->RTC_Date = (uint8_t)RTC_Bcd2ToByte(RTC_DateStruct->RTC_Date);
    }
}

/** @defgroup RTC_Group3 Alarms configuration functions
  * @brief   Alarms (Alarm A) configuration functions
  *
  *
  * ===============================================================================
  *         ##### Alarms A and B configuration functions #####
  * ===============================================================================
  *
  * [..] This section provide functions allowing to program and read the RTC Alarms.
  */

/**
  * @brief  Set the specified RTC Alarm.
  * @note   The Alarm register can only be written when the corresponding Alarm
  *         is disabled (Use the RTC_AlarmCmd(DISABLE)).
  * @param  RTC_Format: specifies the format of the returned parameters.
  *          This parameter can be one of the following values:
  *            @arg RTC_Format_BIN: Binary data format
  *            @arg RTC_Format_BCD: BCD data format
  * @param  RTC_Alarm: specifies the alarm to be configured.
  *          This parameter can be one of the following values:
  *            @arg RTC_Alarm_A: to select Alarm A
  * @param  RTC_AlarmStruct: pointer to a RTC_AlarmTypeDef structure that
  *                          contains the alarm configuration parameters.
  * @retval None
  */
ErrorStatus RTC_SetAlarm(uint8_t RTC_Format, uint32_t RTC_Alarm, RTC_AlarmTypeDef* RTC_AlarmStruct)
{
    uint32_t tmpreg = 0;
    ErrorStatus status = ERROR;

    uint8_t TempHours;
    uint8_t TempMinutes;
    uint8_t TempSeconds;
    uint8_t TempDateWeekValue;

    if (RTC_Format == RTC_Format_BIN) 
    {
        TempHours   = RTC_AlarmStruct->RTC_AlarmTime.RTC_Hours;
        TempMinutes = RTC_AlarmStruct->RTC_AlarmTime.RTC_Minutes;
        TempSeconds = RTC_AlarmStruct->RTC_AlarmTime.RTC_Seconds;
        TempDateWeekValue = RTC_AlarmStruct->RTC_AlarmDateWeekDay;
    }
    else 
    {
        TempHours   = RTC_Bcd2ToByte(RTC_AlarmStruct->RTC_AlarmTime.RTC_Hours);
        TempMinutes = RTC_Bcd2ToByte(RTC_AlarmStruct->RTC_AlarmTime.RTC_Minutes);
        TempSeconds = RTC_Bcd2ToByte(RTC_AlarmStruct->RTC_AlarmTime.RTC_Seconds);
        TempDateWeekValue = RTC_Bcd2ToByte(RTC_AlarmStruct->RTC_AlarmDateWeekDay);
    }
    if(!(((TempMinutes) <= 59) && ((TempSeconds) <= 59))) 
    {
        return status;
    }
    if ((RTC->CR & RTC_CR_FMT_Msk) != (uint32_t)RESET) 
    {
        if(!((TempHours > 0) && (TempHours <= 12))) 
        {
            return status;
        }
    }
    else 
    {
        if(!((TempHours) <= 23)) 
        {
            return status;
        }
        RTC_AlarmStruct->RTC_AlarmTime.RTC_H12 = RTC_H12_AM;
    }

    if(RTC_AlarmStruct->RTC_AlarmDateWeekDaySel == RTC_AlarmDateWeekDaySel_Date) 
    {
        if(!((TempDateWeekValue > 0) && (TempDateWeekValue <= 31))) 
        {
            return status;
        }
    }
    else 
    {
        if(!((TempDateWeekValue > 0) && (TempDateWeekValue <= 7))) 
        {
            return status;
        }
    }
    status = SUCCESS;

    /* Check the input parameters format */
    if (RTC_Format != RTC_Format_BIN) 
    {
        tmpreg = (((uint32_t)(RTC_AlarmStruct->RTC_AlarmTime.RTC_Hours) << 16) | \
                  ((uint32_t)(RTC_AlarmStruct->RTC_AlarmTime.RTC_Minutes) << 8) | \
                  ((uint32_t)RTC_AlarmStruct->RTC_AlarmTime.RTC_Seconds) | \
                  ((uint32_t)(RTC_AlarmStruct->RTC_AlarmTime.RTC_H12) << 16) | \
                  ((uint32_t)(RTC_AlarmStruct->RTC_AlarmDateWeekDay) << 24) | \
                  ((uint32_t)RTC_AlarmStruct->RTC_AlarmDateWeekDaySel) | \
                  ((uint32_t)RTC_AlarmStruct->RTC_AlarmMask));
    }
    else
    {
        tmpreg = (((uint32_t)RTC_ByteToBcd2(RTC_AlarmStruct->RTC_AlarmTime.RTC_Hours) << 16) | \
                  ((uint32_t)RTC_ByteToBcd2(RTC_AlarmStruct->RTC_AlarmTime.RTC_Minutes) << 8) | \
                  ((uint32_t)RTC_ByteToBcd2(RTC_AlarmStruct->RTC_AlarmTime.RTC_Seconds)) | \
                  ((uint32_t)(RTC_AlarmStruct->RTC_AlarmTime.RTC_H12) << 16) | \
                  ((uint32_t)RTC_ByteToBcd2(RTC_AlarmStruct->RTC_AlarmDateWeekDay) << 24) | \
                  ((uint32_t)RTC_AlarmStruct->RTC_AlarmDateWeekDaySel) | \
                  ((uint32_t)RTC_AlarmStruct->RTC_AlarmMask));
    }

    /* Configure the Alarm register */
    if (RTC_Alarm == RTC_Alarm_A) 
    {
        RTC->ALARMAR = (uint32_t)tmpreg;
    }

    return status;
}

/**
  * @brief  Fills each RTC_AlarmStruct member with its default value
  *         (Time = 00h:00mn:00sec / Date = 1st day of the month/Mask =
  *         all fields are masked).
  * @param  RTC_AlarmStruct: pointer to a @ref RTC_AlarmTypeDef structure which
  *         will be initialized.
  * @retval None
  */
void RTC_AlarmStructInit(RTC_AlarmTypeDef* RTC_AlarmStruct)
{
    /* Alarm Time Settings : Time = 00h:00mn:00sec */
    RTC_AlarmStruct->RTC_AlarmTime.RTC_H12 = RTC_H12_AM;
    RTC_AlarmStruct->RTC_AlarmTime.RTC_Hours = 1;
    RTC_AlarmStruct->RTC_AlarmTime.RTC_Minutes = 0;
    RTC_AlarmStruct->RTC_AlarmTime.RTC_Seconds = 0;

    /* Alarm Date Settings : Date = 1st day of the month */
    RTC_AlarmStruct->RTC_AlarmDateWeekDaySel = RTC_AlarmDateWeekDaySel_Date;
    RTC_AlarmStruct->RTC_AlarmDateWeekDay = 1;

    /* Alarm Masks Settings : Mask =  all fields are not masked */
    RTC_AlarmStruct->RTC_AlarmMask = RTC_AlarmMask_None;
}

/**
  * @brief  Get the RTC Alarm value and masks.
  * @param  RTC_Format: specifies the format of the output parameters.
  *          This parameter can be one of the following values:
  *            @arg RTC_Format_BIN: Binary data format
  *            @arg RTC_Format_BCD: BCD data format
  * @param  RTC_Alarm: specifies the alarm to be read.
  *          This parameter can be one of the following values:
  *            @arg RTC_Alarm_A: to select Alarm A
  * @param  RTC_AlarmStruct: pointer to a RTC_AlarmTypeDef structure that will
  *                          contains the output alarm configuration values.
  * @retval None
  */
void RTC_GetAlarm(uint8_t RTC_Format, uint32_t RTC_Alarm, RTC_AlarmTypeDef* RTC_AlarmStruct)
{
    uint32_t tmpreg = 0;

    /* Get the RTC_ALRMxR register */
    if (RTC_Alarm == RTC_Alarm_A) {
        tmpreg = (uint32_t)(RTC->ALARMAR);
    }

    /* Fill the structure with the read parameters */
    RTC_AlarmStruct->RTC_AlarmTime.RTC_Hours = (uint32_t)((tmpreg & (RTC_ALARMAR_HT_Msk | RTC_ALARMAR_HU_Msk)) >> 16);
    RTC_AlarmStruct->RTC_AlarmTime.RTC_Minutes = (uint32_t)((tmpreg & (RTC_ALARMAR_MNT_Msk | RTC_ALARMAR_MNU_Msk)) >> 8);
    RTC_AlarmStruct->RTC_AlarmTime.RTC_Seconds = (uint32_t)(tmpreg & (RTC_ALARMAR_ST_Msk | RTC_ALARMAR_SU_Msk));
    RTC_AlarmStruct->RTC_AlarmTime.RTC_H12 = (uint32_t)((tmpreg & RTC_ALARMAR_PM_Msk) >> 16);
    RTC_AlarmStruct->RTC_AlarmDateWeekDay = (uint32_t)((tmpreg & (RTC_ALARMAR_DT_Msk | RTC_ALARMAR_DU_Msk)) >> 24);
    RTC_AlarmStruct->RTC_AlarmDateWeekDaySel = (uint32_t)(tmpreg & RTC_ALARMAR_WDSEL_Msk);
    RTC_AlarmStruct->RTC_AlarmMask = (uint32_t)(tmpreg & ((uint32_t)RTC_AlarmMask_All));

    if (RTC_Format == RTC_Format_BIN) 
    {
        RTC_AlarmStruct->RTC_AlarmTime.RTC_Hours = RTC_Bcd2ToByte(RTC_AlarmStruct->RTC_AlarmTime.RTC_Hours);
        RTC_AlarmStruct->RTC_AlarmTime.RTC_Minutes = RTC_Bcd2ToByte(RTC_AlarmStruct->RTC_AlarmTime.RTC_Minutes);
        RTC_AlarmStruct->RTC_AlarmTime.RTC_Seconds = RTC_Bcd2ToByte(RTC_AlarmStruct->RTC_AlarmTime.RTC_Seconds);
        RTC_AlarmStruct->RTC_AlarmDateWeekDay = RTC_Bcd2ToByte(RTC_AlarmStruct->RTC_AlarmDateWeekDay);
    }
}

/**
  * @brief  Enables or disables the specified RTC Alarm.
  * @param  RTC_Alarm: specifies the alarm to be configured.
  *          This parameter can be any combination of the following values:
  *            @arg RTC_Alarm_A: to select Alarm A
  * @param  state: new state of the specified alarm.
  *          This parameter can be: ENABLE or DISABLE.
  * @retval An ErrorStatus enumeration value:
  *          - SUCCESS: RTC Alarm is enabled/disabled
  *          - ERROR: RTC Alarm is not enabled/disabled
  */
ErrorStatus RTC_AlarmCmd(uint32_t RTC_Alarm, FunctionalState state)
{
    __IO uint32_t alarmcounter = 0x00;
    uint32_t alarmstatus = 0x00;
    ErrorStatus status = ERROR;
    if (RTC_Alarm == RTC_Alarm_A) {
        /* Configure the Alarm state */
        if (state != DISABLE) 
        {
            RTC->CR |= (uint32_t)RTC_CR_ALRAE_Msk;

            status = SUCCESS;
        }
        else 
        {
            /* Disable the Alarm in RTC_CR register */
            RTC->CR &= (uint32_t)(~RTC_CR_ALRAE_Msk);

            /* Wait till RTC ALRxWF flag is set and if Time out is reached exit */
            do {
                alarmstatus = RTC->ISR & (RTC_ISR_ALRAWF_Msk);
                alarmcounter++;
            } while((alarmcounter != INITMODE_TIMEOUT) && (alarmstatus == 0x00));

            if ((RTC->ISR & (RTC_ISR_ALRAWF_Msk)) == RESET) 
            {
                status = ERROR;
            }
            else 
            {
                status = SUCCESS;
            }
        }
    }

    return status;
}

/**
  * @brief  Configure the RTC AlarmA/B Sub seconds value and mask.*
  * @note   This function is performed only when the Alarm is disabled.
  * @param  RTC_Alarm: specifies the alarm to be configured.
  *   This parameter can be one of the following values:
  *     @arg RTC_Alarm_A: to select Alarm A
  * @param  RTC_AlarmSubSecondValue: specifies the Sub seconds value.
  *   This parameter can be a value from 0 to 0x00007FFF.
  * @param  RTC_AlarmSubSecondMask:  specifies the Sub seconds Mask.
  *     @arg RTC_AlarmSubSecondMask_All    : All Alarm SS fields are masked.
  *                                          There is no comparison on sub seconds for Alarm.
  *     @arg RTC_AlarmSubSecondMask_SS14_1 : SS[14:1] are don't care in Alarm comparison.
  *                                          Only SS[0] is compared
  *     @arg RTC_AlarmSubSecondMask_SS14_2 : SS[14:2] are don't care in Alarm comparison.
  *                                          Only SS[1:0] are compared
  *     @arg RTC_AlarmSubSecondMask_SS14_3 : SS[14:3] are don't care in Alarm comparison.
  *                                          Only SS[2:0] are compared
  *     @arg RTC_AlarmSubSecondMask_SS14_4 : SS[14:4] are don't care in Alarm comparison.
  *                                          Only SS[3:0] are compared
  *     @arg RTC_AlarmSubSecondMask_SS14_5 : SS[14:5] are don't care in Alarm comparison.
  *                                          Only SS[4:0] are compared
  *     @arg RTC_AlarmSubSecondMask_SS14_6 : SS[14:6] are don't care in Alarm comparison.
  *                                          Only SS[5:0] are compared
  *     @arg RTC_AlarmSubSecondMask_SS14_7 : SS[14:7] are don't care in Alarm comparison.
  *                                          Only SS[6:0] are compared
  *     @arg RTC_AlarmSubSecondMask_SS14_8 : SS[14:8] are don't care in Alarm comparison.
  *                                          Only SS[7:0] are compared
  *     @arg RTC_AlarmSubSecondMask_SS14_9 : SS[14:9] are don't care in Alarm comparison.
  *                                          Only SS[8:0] are compared
  *     @arg RTC_AlarmSubSecondMask_SS14_10: SS[14:10] are don't care in Alarm comparison.
  *                                          Only SS[9:0] are compared
  *     @arg RTC_AlarmSubSecondMask_SS14_11: SS[14:11] are don't care in Alarm comparison.
  *                                          Only SS[10:0] are compared
  *     @arg RTC_AlarmSubSecondMask_SS14_12: SS[14:12] are don't care in Alarm comparison.
  *                                          Only SS[11:0] are compared
  *     @arg RTC_AlarmSubSecondMask_SS14_13: SS[14:13] are don't care in Alarm comparison.
  *                                          Only SS[12:0] are compared
  *     @arg RTC_AlarmSubSecondMask_SS14   : SS[14] is don't care in Alarm comparison.
  *                                          Only SS[13:0] are compared
  *     @arg RTC_AlarmSubSecondMask_None   : SS[14:0] are compared and must match
  *                                          to activate alarm
  * @retval None
  */
void RTC_AlarmSubSecondConfig(uint32_t RTC_Alarm, uint32_t RTC_AlarmSubSecondValue, uint32_t RTC_AlarmSubSecondMask)
{
    uint32_t tmpreg = 0;

    /* Configure the Alarm A Sub Second registers */
    tmpreg = (uint32_t)((uint32_t)(RTC_AlarmSubSecondValue & (RTC_ALARMASSR_SS_Msk)) | (uint32_t)(RTC_AlarmSubSecondMask));
    if (RTC_Alarm == RTC_Alarm_A)
    {
        /* Configure the Alarm A Sub Second register */
        RTC->ALARMASSR = tmpreg;
    }
}

/**
  * @brief  Gets the RTC Alarm Sub seconds value.
  * @param  RTC_Alarm: specifies the alarm to be read.
  *   This parameter can be one of the following values:
  *     @arg RTC_Alarm_A: to select Alarm A
  * @param  None
  * @retval RTC Alarm Sub seconds value.
  */
uint32_t RTC_GetAlarmSubSecond(uint32_t RTC_Alarm)
{
    uint32_t tmpreg = 0;

    /* Get the RTC_ALRMxR register */
    if (RTC_Alarm == RTC_Alarm_A) 
    {
        tmpreg = (uint32_t)((RTC->ALARMASSR) & (RTC_ALARMASSR_SS_Msk));
    }

    return (tmpreg);
}

/** @defgroup RTC_Group4 WakeUp Timer configuration functions
  * @brief   WakeUp Timer configuration functions
  *
  *
  * ===============================================================================
  *                 ##### WakeUp Timer configuration functions #####
  * ===============================================================================
  *
  * [..] This section provide functions allowing to program and read the RTC WakeUp.
  */

/**
  * @brief  Configures the RTC Wakeup clock source.
  * @note   The WakeUp Clock source can only be changed when the RTC WakeUp is disabled (Use the RTC_WakeUpCmd(DISABLE)).
  * @param  RTC_WakeUpClock: Wakeup Clock source.
  *            @arg RTC_WakeUpClock_RTCCLK_Div16  : RTC Wakeup Counter Clock = RTCCLK/16
  *            @arg RTC_WakeUpClock_RTCCLK_Div8   : RTC Wakeup Counter Clock = RTCCLK/8
  *            @arg RTC_WakeUpClock_RTCCLK_Div4   : RTC Wakeup Counter Clock = RTCCLK/4
  *            @arg RTC_WakeUpClock_RTCCLK_Div2   : RTC Wakeup Counter Clock = RTCCLK/2
  *            @arg RTC_WakeUpClock_CK_SPRE_16bits: RTC Wakeup Counter Clock = CK_SPRE
  *            @arg RTC_WakeUpClock_CK_SPRE_17bits: RTC Wakeup Counter Clock = CK_SPRE
  * @retval None
  */
void RTC_WakeUpClockConfig(uint32_t RTC_WakeUpClock)
{
    /* Clear the Wakeup Timer clock source bits in CR register */
    RTC->CR &= (uint32_t)(~RTC_CR_WUCKSEL_Msk);
    /* Configure the clock source */
    RTC->CR |= (uint32_t)RTC_WakeUpClock;
}

/**
  * @brief  Configures the RTC Wakeup counter.
  * @note   The RTC WakeUp counter can only be written when the RTC WakeUp
  *         is disabled (Use the RTC_WakeUpCmd(DISABLE)).
  * @param  RTC_WakeUpCounter: specifies the WakeUp counter.
  *          This parameter can be a value from 0x0000 to 0xFFFF.
  * @retval None
  */
void RTC_SetWakeUpCounter(uint32_t RTC_WakeUpCounter)
{
    /* Configure the Wakeup Timer counter */
    RTC->WUTR = (uint32_t)(RTC_WakeUpCounter & (RTC_WUTR_WUTRL_Msk | RTC_WUTR_WUTRH_Msk));
}

/**
  * @brief  Returns the RTC WakeUp timer counter value.
  * @param  None
  * @retval The RTC WakeUp Counter value.
  */
uint32_t RTC_GetWakeUpCounter(void)
{
    /* Get the counter value */
    return ((uint32_t)(RTC->WUTR & (RTC_WUTR_WUTRL_Msk | RTC_WUTR_WUTRH_Msk)));
}

/**
  * @brief  Enables or Disables the RTC WakeUp timer.
  * @param  state: new state of the WakeUp timer.
  *          This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
ErrorStatus RTC_WakeUpCmd(FunctionalState state)
{
    __IO uint32_t wutcounter = 0x00;
    uint32_t wutwfstatus = 0x00;
    ErrorStatus status = ERROR;

    if (state != DISABLE) 
    {
        /* Enable the Wakeup Timer */
        RTC->CR |= (uint32_t)RTC_CR_WUTE_Msk;
        status = SUCCESS;
    }
    else 
    {
        /* Disable the Wakeup Timer */
        RTC->CR &= (uint32_t)~RTC_CR_WUTE_Msk;
        /* Wait till RTC WUTWF flag is set and if Time out is reached exit */
        do {
            wutwfstatus = RTC->ISR & RTC_ISR_WUTWF_Msk;
            wutcounter++;
        } while((wutcounter != INITMODE_TIMEOUT) && (wutwfstatus == 0x00));

        if ((RTC->ISR & RTC_ISR_WUTWF_Msk) == RESET)
        {
            status = ERROR;
        }
        else 
        {
            status = SUCCESS;
        }
    }

    return status;
}

/** @defgroup RTC_Group5 Daylight Saving configuration functions
  * @brief   Daylight Saving configuration functions
  *
  *
  * ===============================================================================
  *              ##### Daylight Saving configuration functions #####
  * ===============================================================================
  *
  * [..] This section provide functions allowing to configure the RTC DayLight Saving.
  */

/**
  * @brief  Adds or substract one hour from the current time.
  * @param  RTC_DayLightSaveOperation: the value of hour modify.
  *          This parameter can be one of the following values:
  *            @arg RTC_DayLightSaving_SUB1H: Substract one hour (winter time)
  *            @arg RTC_DayLightSaving_ADD1H: Add one hour (summer time)
  * @param  RTC_StoreOperation: Specifies the value to be written in the BCK bit
  *                            in CR register to store the operation.
  *          This parameter can be one of the following values:
  *            @arg RTC_StoreOperation_Reset: BCK Bit Reset
  *            @arg RTC_StoreOperation_Set: BCK Bit Set
  * @retval None
  */
void RTC_DayLightSavingConfig(uint32_t RTC_DayLightSaving, uint32_t RTC_StoreOperation)
{
    /* Clear the bits to be configured */
    RTC->CR &= (uint32_t)(~(RTC_CR_BKP_Msk));
    /* Configure the RTC_CR register */
    RTC->CR |= ((uint32_t)RTC_DayLightSaving) | ((uint32_t)RTC_StoreOperation);
}

/**
  * @brief  Returns the RTC Day Light Saving stored operation.
  * @param  None
  * @retval RTC Day Light Saving stored operation.
  *          - RTC_StoreOperation_Reset
  *          - RTC_StoreOperation_Set
  */
uint32_t RTC_GetStoreOperation(void)
{
    return (RTC->CR & RTC_CR_BKP_Msk);
}

/** @defgroup RTC_Group6 Output pin Configuration function
  * @brief   Output pin Configuration function
  *
  *
  * ===============================================================================
  *                 ##### Output pin Configuration function #####
  * ===============================================================================
  * [..] This section provide functions allowing to configure the RTC Output source.
 */

/**
  * @brief  Configures the RTC output source (AFO_ALARM).
  * @param  RTC_Output: Specifies which signal will be routed to the RTC output.
  *          This parameter can be one of the following values:
  *            @arg RTC_Output_Disable: No output selected
  *            @arg RTC_Output_AlarmA: signal of AlarmA mapped to output
  *            @arg RTC_Output_WakeUp: signal of WakeUp mapped to output
  * @param  RTC_OutputPolarity: Specifies the polarity of the output signal.
  *          This parameter can be one of the following:
  *            @arg RTC_OutputPolarity_High: The output pin is high when the
  *                                 ALRAF/WUTF is high (depending on OSEL)
  *            @arg RTC_OutputPolarity_Low: The output pin is low when the
  *                                 ALRAF/WUTF is high (depending on OSEL)
  * @retval None
  */
void RTC_OutputConfig(uint32_t RTC_Output, uint32_t RTC_OutputPolarity)
{
    /* Clear the bits to be configured */
    RTC->CR &= (uint32_t)~(RTC_CR_OSEL_Msk | RTC_CR_POL_Msk);
    /* Configure the output selection and polarity */
    RTC->CR |= (uint32_t)(RTC_Output) | (uint32_t)(RTC_OutputPolarity);
}

/** @defgroup RTC_Group7 Digital Calibration configuration functions
  * @brief   Calibration configuration functions
  *
  * ===============================================================================
  *              ##### Digital Calibration configuration functions #####
  * ===============================================================================
  *
  *
  * @brief  Enables or disables the RTC clock to be output through the relative pin.
  * @param  state: new state of the digital calibration Output.
  *          This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
void RTC_CalibOutputCmd(FunctionalState state)
{
    state ? (RTC->CR |= (uint32_t)RTC_CR_COE_Msk ) : (RTC->CR &= (uint32_t)~RTC_CR_COE_Msk);
}

/**
  * @brief  Configure the Calibration Pinout (RTC_CALIB) Selection (1Hz or 512Hz).
  * @param  RTC_CalibOutput : Select the Calibration output Selection .
  *   This parameter can be one of the following values:
  *     @arg RTC_CalibOutput_512Hz: A signal has a regular waveform at 512Hz.
  *     @arg RTC_CalibOutput_1Hz  : A signal has a regular waveform at 1Hz.
  * @retval None
  */
void RTC_CalibOutputConfig(uint32_t RTC_CalibOutput)
{
    MODIFY_REG(RTC->CR, RTC_CR_COSEL_Msk, (uint32_t)RTC_CalibOutput);
}

/**
  * @brief  Configures the  Calibration Settings.
  * @param  RTC_CalibPlusPulses : Select to Set or reset the CALP bit.
  *   This parameter can be one of the following values:
  *     @arg RTC_CalibPlusPulses_Set  : Add one RTCCLK pulse every 2**11 pulses.
  *     @arg RTC_CalibPlusPulses_Reset: No RTCCLK pulses are added.
  * @param  RTC_CalibMinusPulsesValue: Select the value of CALM[8:0] bits.
  *   This parameter can be one any value from 0 to 0x000001FF.
  * @retval An ErrorStatus enumeration value:
  *          - SUCCESS: RTC Calib registers are configured
  *          - ERROR: RTC Calib registers are not configured
  */
ErrorStatus RTC_CalibConfig(uint32_t RTC_CalibPlusPulses, uint32_t RTC_CalibMinusPulsesValue)
{
    ErrorStatus status = ERROR;

    if (RTC_CalibMinusPulsesValue <= RTC_CALR_CALM_Msk) 
    {
        RTC->CALR = (uint32_t)((uint32_t)RTC_CalibPlusPulses | (((uint32_t)RTC_CalibMinusPulsesValue) & ((uint32_t)0x1FF)));
        status = SUCCESS;
    }
    return status;
}

/** @defgroup RTC_Group8 TimeStamp configuration functions
  * @brief   TimeStamp configuration functions
  * ===============================================================================
  *                 ##### TimeStamp configuration functions #####
  * ===============================================================================
  *
  *
  * @brief  Enables or Disables the RTC TimeStamp functionality with the
  *         specified time stamp pin stimulating edge.
  * @param  RTC_TimeStampEdge: Specifies the pin edge on which the TimeStamp is
  *         activated.
  *          This parameter can be one of the following:
  *            @arg RTC_TimeStampEdge_Rising: the Time stamp event occurs on the rising
  *                                    edge of the related pin.
  *            @arg RTC_TimeStampEdge_Falling: the Time stamp event occurs on the
  *                                     falling edge of the related pin.
  * @param  state: new state of the TimeStamp.
  *          This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
void RTC_TimeStampCmd(uint32_t RTC_TimeStampEdge, FunctionalState state)
{
    uint32_t tmpreg = 0;

    /* Get the RTC_CR register and clear the bits to be configured */
    tmpreg = (uint32_t)(RTC->CR & (uint32_t)~(RTC_CR_TSEDGE_Msk | RTC_CR_TSE_Msk));
    /* Get the new configuration */
    if (state != DISABLE) {
        tmpreg |= (uint32_t)(RTC_TimeStampEdge | RTC_CR_TSE_Msk);
    }
    else {
        tmpreg |= (uint32_t)(RTC_TimeStampEdge);
    }
    /* Configure the Time Stamp TSEDGE and Enable bits */
    RTC->CR = (uint32_t)tmpreg;
}

/**
  * @brief  Get the RTC TimeStamp value and masks.
  * @param  RTC_Format: specifies the format of the output parameters.
  *          This parameter can be one of the following values:
  *            @arg RTC_Format_BIN: Binary data format
  *            @arg RTC_Format_BCD: BCD data format
  * @param RTC_StampTimeStruct: pointer to a RTC_TimeTypeDef structure that will
  *                             contains the TimeStamp time values.
  * @param RTC_StampDateStruct: pointer to a RTC_DateTypeDef structure that will
  *                             contains the TimeStamp date values.
  * @retval None
  */
void RTC_GetTimeStamp(uint8_t RTC_Format, RTC_TimeTypeDef* RTC_StampTimeStruct,
                         RTC_DateTypeDef* RTC_StampDateStruct)
{
    uint32_t tmptime = 0, tmpdate = 0;

    /* Get the TimeStamp time and date registers values */
    tmptime = (uint32_t)(RTC->TSTR & RTC_TSTR_RESERVED_MASK);
    tmpdate = (uint32_t)(RTC->TSDR & RTC_TSDR_RESERVED_MASK);

    /* Fill the Time structure fields with the read parameters */
    RTC_StampTimeStruct->RTC_Hours = (uint8_t)((tmptime & (RTC_TSTR_HT_Msk | RTC_TSTR_HU_Msk)) >> RTC_TSTR_HU_Pos);
    RTC_StampTimeStruct->RTC_Minutes = (uint8_t)((tmptime & (RTC_TSTR_MNT_Msk | RTC_TSTR_MNU_Msk)) >> RTC_TSTR_MNU_Pos);
    RTC_StampTimeStruct->RTC_Seconds = (uint8_t)((tmptime & (RTC_TSTR_ST_Msk | RTC_TSTR_SU_Msk)) >> RTC_TSTR_SU_Pos);
    if( (tmptime & (RTC_TSTR_PM_Msk)) != RESET) 
    {
        RTC_StampTimeStruct->RTC_H12 = RTC_H12_PM;
    }
    else 
    {
        RTC_StampTimeStruct->RTC_H12 = RTC_H12_AM;
    }

    /* Fill the Date structure fields with the read parameters */
    RTC_StampDateStruct->RTC_Year     = (uint8_t)((tmpdate & (RTC_TSDR_YT_Msk | RTC_TSDR_YU_Msk)) >> RTC_TSDR_YU_Pos);
    RTC_StampDateStruct->RTC_Month    = (uint8_t)((tmpdate & (RTC_TSDR_MT_Msk | RTC_TSDR_MU_Msk)) >> RTC_TSDR_MU_Pos);
    RTC_StampDateStruct->RTC_Date     = (uint8_t)((tmpdate & (RTC_TSDR_DT_Msk | RTC_TSDR_DU_Msk)) >> RTC_TSDR_DU_Pos);
    RTC_StampDateStruct->RTC_WeekDay  = (uint8_t)((tmpdate & (RTC_TSDR_WDU_Msk)) >> RTC_TSDR_WDU_Pos);

    /* Check the input parameters format */
    if (RTC_Format == RTC_Format_BIN) 
    {
        /* Convert the Time structure parameters to Binary format */
        RTC_StampTimeStruct->RTC_Hours = (uint8_t)RTC_Bcd2ToByte(RTC_StampTimeStruct->RTC_Hours);
        RTC_StampTimeStruct->RTC_Minutes = (uint8_t)RTC_Bcd2ToByte(RTC_StampTimeStruct->RTC_Minutes);
        RTC_StampTimeStruct->RTC_Seconds = (uint8_t)RTC_Bcd2ToByte(RTC_StampTimeStruct->RTC_Seconds);

        /* Convert the Date structure parameters to Binary format */
        RTC_StampDateStruct->RTC_Year  = (uint8_t)RTC_Bcd2ToByte(RTC_StampDateStruct->RTC_Year);
        RTC_StampDateStruct->RTC_Month = (uint8_t)RTC_Bcd2ToByte(RTC_StampDateStruct->RTC_Month);
        RTC_StampDateStruct->RTC_Date = (uint8_t)RTC_Bcd2ToByte(RTC_StampDateStruct->RTC_Date);
        RTC_StampDateStruct->RTC_WeekDay = (uint8_t)RTC_Bcd2ToByte(RTC_StampDateStruct->RTC_WeekDay);
    }
}

/**
  * @brief  Get the RTC timestamp Sub seconds value.
  * @param  None
  * @retval RTC current timestamp Sub seconds value.
  */
uint32_t RTC_GetTimeStampSubSecond(void)
{
    /* Get timestamp sub seconds values from the correspondent registers */
    return (uint32_t)(RTC->TSSR);
}

/** @defgroup RTC_Group9 Tampers configuration functions
  * @brief   Tampers configuration functions
  * ===============================================================================
  *                 ##### Tampers configuration functions #####
  * ===============================================================================
  */
/**
  * @brief  Configures the select Tamper pin edge.
  * @param  RTC_Tamper: Selected tamper pin.
  *          This parameter can be RTC_Tamper_1 or RTC_Tamper 2
  * @param  RTC_TamperTrigger: Specifies the trigger on the tamper pin that
  *         stimulates tamper event.
  *   This parameter can be one of the following values:
  *     @arg RTC_TamperTrigger_RisingEdge: Rising Edge of the tamper pin causes tamper event.
  *     @arg RTC_TamperTrigger_FallingEdge: Falling Edge of the tamper pin causes tamper event.
  * @retval None
  */
void RTC_TamperTriggerConfig(uint32_t RTC_Tamper, uint32_t RTC_TamperTrigger)
{
    if( RTC_Tamper_1 == RTC_Tamper ) 
    {
        if(RTC_TamperTrigger == RTC_TamperTrigger_RisingEdge) 
        {
            RTC->TAMPCR &= ~RTC_TAMPCR_TAMP1TRG_Msk;
        }
        else
        {
            RTC->TAMPCR |= RTC_TAMPCR_TAMP1TRG_Msk;
        }
    }
    else if( RTC_Tamper_2 == RTC_Tamper ) 
    {
        if(RTC_TamperTrigger == RTC_TamperTrigger_RisingEdge) 
        {
            RTC->TAMPCR &= ~RTC_TAMPCR_TAMP2TRG_Msk;
        }
        else 
        {
            RTC->TAMPCR |= RTC_TAMPCR_TAMP2TRG_Msk;
        }
    }
}

/**
  * @brief  Enables or Disables the Tamper detection.
  * @param  RTC_Tamper: Selected tamper pin.
  *          This parameter can be RTC_Tamper_1 or RTC_Tamper_2
  * @param  state: new state of the tamper pin.
  *          This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
void RTC_TamperCmd(uint32_t RTC_Tamper, FunctionalState state)
{
    state ? (RTC->TAMPCR |= (uint32_t)RTC_Tamper) : (RTC->TAMPCR &= (uint32_t)~RTC_Tamper);
}

/**
  * @brief  Enables or Disables the TimeStamp on Tamper Detection Event.
  * @note   The timestamp is valid even the TSE bit in tamper control register
  *         is reset.
  * @param  state: new state of the timestamp on tamper event.
  *         This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
void RTC_TimeStampOnTamperDetectionCmd(FunctionalState state)
{
    state ? \
    (RTC->TAMPCR |=  (0x01U << RTC_TAMPCR_TAMPTS_Pos)) : \
    (RTC->TAMPCR &= ~(0x01U << RTC_TAMPCR_TAMPTS_Pos));
}

/** @defgroup RTC_Group10 Backup Data Registers configuration functions
  * @brief   Backup Data Registers configuration functions
  *
  *  ===============================================================================
  *              ##### Backup Data Registers configuration functions #####
  *  ===============================================================================
  */
/**
  * @brief  Writes a data in a specified RTC Backup data register.
  * @param  BKP_DR_x: RTC Backup data Register number.
  *          This parameter can be: RTC_BKP_DRx where x can be from 0 to 4 to
  *                          specify the register.
  * @param  u32data: Data to be written in the specified RTC Backup data register.
  * @retval None
  */
void RTC_WriteBackupRegister(uint8_t BKP_DR_x, uint32_t u32data)
{
    if(BKP_DR_x == RTC_BKP_DR0)
    {
        RTC->BKP0R = u32data;
    }
    else if(BKP_DR_x == RTC_BKP_DR1)
    {
        RTC->BKP1R = u32data;
    }    
    else if(BKP_DR_x == RTC_BKP_DR2)
    {
        RTC->BKP2R = u32data;
    }  
    else if(BKP_DR_x == RTC_BKP_DR3)
    {
        RTC->BKP3R = u32data;
    }  
}

/**
  * @brief  Reads data from the specified RTC Backup data Register.
  * @param  BKP_DR_x: RTC Backup data Register number.
  *          This parameter can be: RTC_BKP_DRx where x can be from 0 to 4 to
  *                          specify the register.
  * @retval None
  */
uint32_t RTC_ReadBackupRegister(uint8_t BKP_DR_x)
{
    uint32_t tmpreg = 0;

    if(BKP_DR_x == RTC_BKP_DR0)
    {
        tmpreg = RTC->BKP0R;
    }
    else if(BKP_DR_x == RTC_BKP_DR1)
    {
        tmpreg = RTC->BKP1R;
    }    
    else if(BKP_DR_x == RTC_BKP_DR2)
    {
        tmpreg = RTC->BKP2R;
    }  
    else if(BKP_DR_x == RTC_BKP_DR3)
    {
        tmpreg = RTC->BKP3R;
    } 

    return  tmpreg;
}

/** @defgroup RTC_Group12 Shift control synchronisation functions
  * @brief   Shift control synchronisation functions
  *
  * ===============================================================================
  *              ##### Shift control synchronisation functions #####
  * ===============================================================================
  */
/**
  * @brief  Configures the Synchronization Shift Control Settings.
  * @param  RTC_ShiftAdd1S : Select to add or not 1 second to the time Calendar.
  *   This parameter can be one of the following values :
  *     @arg RTC_ShiftAdd1S_Set  : Add one second to the clock calendar.
  *     @arg RTC_ShiftAdd1S_Reset: No effect.
  * @param  RTC_ShiftSubFS: Select the number of Second Fractions to Substitute.
  *         This parameter can be one any value from 0 to 0x7FFF.
  * @retval An ErrorStatus enumeration value:
  *          - SUCCESS: RTC Shift registers are configured
  *          - ERROR: RTC Shift registers are not configured
  */
ErrorStatus RTC_SynchroShiftConfig(uint32_t RTC_ShiftAdd1S, uint32_t RTC_ShiftSubFS)
{
    ErrorStatus status = ERROR;
    uint32_t shpfcount = 0;

    while(1) 
    {
        if ((RTC->ISR & RTC_ISR_SHPF_Msk) != RESET) 
        {
            shpfcount++;
            if(shpfcount >= SHPF_TIMEOUT) 
            {
                status = ERROR;
                break;
            }
        }
        else 
        {
            /* Configure the Shift settings */
            RTC->SHIFTR = RTC_ShiftSubFS | ((uint32_t)(RTC_ShiftAdd1S));
            status = RTC_WaitForSynchro();
            break;
        }
    }

    return (status);
}

/** @defgroup RTC_Group13 Interrupts and flags management functions
  * @brief   Interrupts and flags management functions
  *
  * ===============================================================================
  *              ##### Interrupts and flags management functions #####
  * ===============================================================================
  * [..] All RTC interrupts are connected to the EXTI controller.
  *
  *   (+) To enable the RTC Alarm interrupt, the following sequence is required:
  *       (++) Configure and enable the EXTI Line 17 in interrupt mode and select
  *            the rising edge sensitivity using the EXTI_Init() function.
  *       (++) Configure and enable the RTC_Alarm IRQ channel in the NVIC using the
  *            NVIC_Init() function.
  *       (++) Configure the RTC to generate RTC alarms (Alarm A) using
  *            the RTC_SetAlarm() and RTC_AlarmCmd() functions.
  *
  *   (+) To enable the RTC Wakeup interrupt, the following sequence is required:
  *       (++) Configure and enable the EXTI Line 22 in interrupt mode and select the
  *            rising edge sensitivity using the EXTI_Init() function.
  *       (++) Configure and enable the RTC_WKUP IRQ channel in the NVIC using the
  *            NVIC_Init() function.
  *       (++) Configure the RTC to generate the RTC wakeup timer event using the
  *            RTC_WakeUpClockConfig(), RTC_SetWakeUpCounter() and RTC_WakeUpCmd()
  *            functions.
  *
  *   (+) To enable the RTC Tamper interrupt, the following sequence is required:
  *       (++) Configure and enable the EXTI Line 21 in interrupt mode and select
  *            the rising edge sensitivity using the EXTI_Init() function.
  *       (++) Configure and enable the TAMP_STAMP IRQ channel in the NVIC using the
  *            NVIC_Init() function.
  *       (++) Configure the RTC to detect the RTC tamper event using the
  *            RTC_TamperTriggerConfig() and RTC_TamperCmd() functions.
  *
  *   (+) To enable the RTC TimeStamp interrupt, the following sequence is required:
  *       (++) Configure and enable the EXTI Line 21 in interrupt mode and select the
  *            rising edge sensitivity using the EXTI_Init() function.
  *       (++) Configure and enable the TAMP_STAMP IRQ channel in the NVIC using the
  *            NVIC_Init() function.
  *       (++) Configure the RTC to detect the RTC time stamp event using the
  *            RTC_TimeStampCmd() functions.
  */
/**
  * @brief  Checks whether the specified RTC flag is set or not.
  * @param  RTC_FLAG: specifies the flag to check.
  *          This parameter can be one of the following values:
  *            @arg RTC_FLAG_ALRAWF: Alarm A write flag
  *            @arg RTC_FLAG_WUTWF: WakeUp Timer Write flag
  *            @arg RTC_FLAG_SHPF: Shift operation pending flag.
  *            @arg RTC_FLAG_INITS: Registers Configured flag
  *            @arg RTC_FLAG_INITF: Initialization mode flag
  *            @arg RTC_FLAG_ALRAF: Alarm A flag
  *            @arg RTC_FLAG_WUTF: WakeUp Timer flag
  *            @arg RTC_FLAG_TSF: Time Stamp event flag
  *            @arg RTC_FLAG_TSOVF: Time Stamp OverFlow flag
  *            @arg RTC_FLAG_TAMP1F: Tamper 1 event flag
  *            @arg RTC_FLAG_TAMP2F: Tamper 1 event flag
  * @retval The new state of RTC_FLAG (SET or RESET).
  */
FlagStatus RTC_GetFlagStatus(uint32_t RTC_FLAG)
{
    FlagStatus bitstatus = RESET;
    uint32_t tmpreg = 0;

    switch(RTC_FLAG) 
    {
        case RTC_FLAG_ALRAWF:
            tmpreg = (uint32_t)(RTC->ISR & RTC_ISR_ALRAWF_Msk  );
        case RTC_FLAG_WUTWF :
            tmpreg = (uint32_t)(RTC->ISR & RTC_ISR_WUTWF_Msk   );
        case RTC_FLAG_SHPF  :
            tmpreg = (uint32_t)(RTC->ISR & RTC_ISR_SHPF_Msk    );
        case RTC_FLAG_INITS :
            tmpreg = (uint32_t)(RTC->ISR & RTC_ISR_INITS_Msk   );
        case RTC_FLAG_INITF :
            tmpreg = (uint32_t)(RTC->ISR & RTC_ISR_INITF_Msk   );
        case RTC_FLAG_ALRAF :
            tmpreg = (uint32_t)(RTC->ISR & RTC_ISR_ALRAF_Msk   );
        case RTC_FLAG_WUTF  :
            tmpreg = (uint32_t)(RTC->ISR & RTC_ISR_WUTF_Msk    );
        case RTC_FLAG_TSF   :
            tmpreg = (uint32_t)(RTC->ISR & RTC_ISR_TSF_Msk     );
        case RTC_FLAG_TSOVF :
            tmpreg = (uint32_t)(RTC->ISR & RTC_ISR_TSOVF_Msk   );
        case RTC_FLAG_TAMP1F:
            tmpreg = (uint32_t)(RTC->TAMPCR & RTC_TAMPCR_TAMP1IF_Msk   );
        case RTC_FLAG_TAMP2F:
            tmpreg = (uint32_t)(RTC->TAMPCR & RTC_TAMPCR_TAMP2IF_Msk   );
        default:
            tmpreg = 0;
    }
    /* Return the status of the flag */
    if (tmpreg != (uint32_t)RESET)
    {
        bitstatus = SET;
    }
    else
    {
        bitstatus = RESET;
    }
    return bitstatus;
}

/**
  * @brief  Clears the RTC's pending flags.
  * @param  RTC_FLAG: specifies the RTC flag to clear.
  *          This parameter can be any combination of the following values:
  *            @arg RTC_FLAG_TSOVF: Time Stamp Overflow flag
  *            @arg RTC_FLAG_TSF: Time Stamp event flag
  *            @arg RTC_FLAG_WUTF: WakeUp Timer flag
  *            @arg RTC_FLAG_ALRAF: Alarm A flag
  *            @arg RTC_FLAG_TAMP1F: Tamper 1 event flag
  *            @arg RTC_FLAG_TAMP2F: Tamper 2 event flag
  * @retval None
  */
void RTC_ClearFlag(uint32_t RTC_FLAG)
{
    switch(RTC_FLAG) 
    {
        case RTC_FLAG_TSOVF :
            RTC->ISR    = (uint32_t)(RTC->ISR    & (~RTC_ISR_TSOVF_Msk      ));
            break;
        case RTC_FLAG_TSF   :
            RTC->ISR    = (uint32_t)(RTC->ISR    & (~RTC_ISR_TSF_Msk        ));
            break;
        case RTC_FLAG_WUTF  :
            RTC->ISR    = (uint32_t)(RTC->ISR    & (~RTC_ISR_WUTF_Msk       ));
            break;
        case RTC_FLAG_ALRAF :
            RTC->ISR    = (uint32_t)(RTC->ISR    & (~RTC_ISR_ALRAF_Msk      ));
            break;
        case RTC_FLAG_TAMP1F:
            RTC->TAMPCR = (uint32_t)(RTC->TAMPCR & (~RTC_TAMPCR_TAMP1IF_Msk ));
            break;
        case RTC_FLAG_TAMP2F:
            RTC->TAMPCR = (uint32_t)(RTC->TAMPCR & (~RTC_TAMPCR_TAMP2IF_Msk ));
            break;
        default:
            break;
    }
}

/**
  * @brief  Enables or disables the specified RTC interrupts.
  * @param  RTC_IT: specifies the RTC interrupt sources to be enabled or disabled.
  *          This parameter can be any combination of the following values:
  *            @arg RTC_IT_TS:  Time Stamp interrupt mask
  *            @arg RTC_IT_WUT:  WakeUp Timer interrupt mask
  *            @arg RTC_IT_ALRA:  Alarm A interrupt mask
  *            @arg RTC_IT_TAMP1: Tamper event interrupt mask
  *            @arg RTC_IT_TAMP2: Tamper event interrupt mask
  * @param  state: new state of the specified RTC interrupts.
  *          This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
void RTC_ITConfig(uint32_t RTC_IT, FunctionalState state)
{
    if (state != DISABLE) 
    {
        if( RTC_IT_TS == RTC_IT)
        {
            RTC->CR |= RTC_CR_TSIE_Msk;
        }
        else if( RTC_IT_WUT == RTC_IT) 
        {
            RTC->CR |= RTC_CR_WUTIE_Msk;
        }
        else if( RTC_IT_ALRA == RTC_IT) 
        {
            RTC->CR |= RTC_CR_ALRAIE_Msk;
        }
        else if( RTC_IT_TAMP1 == RTC_IT) 
        {
            RTC->TAMPCR |= RTC_TAMPCR_TAMP1IE_Msk;
        }
        else if( RTC_IT_TAMP2 == RTC_IT) 
        {
            RTC->TAMPCR |= RTC_TAMPCR_TAMP2IE_Msk;
        }
    }
    else 
    {
        if( RTC_IT_TS == RTC_IT) 
        {
            RTC->CR &= ~RTC_CR_TSIE_Msk;
        }
        else if( RTC_IT_WUT == RTC_IT) 
        {
            RTC->CR &= ~RTC_CR_WUTIE_Msk;
        }
        else if( RTC_IT_ALRA == RTC_IT) 
        {
            RTC->CR &= ~RTC_CR_ALRAIE_Msk;
        }
        else if( RTC_IT_TAMP1 == RTC_IT) 
        {
            RTC->TAMPCR &= ~RTC_TAMPCR_TAMP1IE_Msk;
        }
        else if( RTC_IT_TAMP2 == RTC_IT) 
        {
            RTC->TAMPCR &= ~RTC_TAMPCR_TAMP2IE_Msk;
        }
    }
}

/**
  * @brief  Checks whether the specified RTC interrupt has occurred or not.
  * @param  RTC_IT: specifies the RTC interrupt source to check.
  *          This parameter can be one of the following values:
  *            @arg RTC_IT_TS: Time Stamp interrupt
  *            @arg RTC_IT_WUT: WakeUp Timer interrupt
  *            @arg RTC_IT_ALRA: Alarm A interrupt
  *            @arg RTC_IT_TAMP1: Tamper 1 event interrupt
  *            @arg RTC_IT_TAMP2: Tamper 2 event interrupt
  * @retval The new state of RTC_IT (SET or RESET).
  */
ITStatus RTC_GetITStatus(uint32_t RTC_IT)
{
    ITStatus bitstatus = RESET;
    uint32_t tmpreg = 0;
    uint32_t enablestatus = 0;

    if( RTC_IT_TS == RTC_IT) 
    {
        enablestatus = (uint32_t)(RTC->CR & RTC_CR_TSIE_Msk);
        tmpreg = (uint32_t)((RTC->ISR & (uint32_t)(RTC_ISR_TSF_Msk)));
    }
    else if( RTC_IT_WUT == RTC_IT)
    {
        enablestatus = (uint32_t)(RTC->CR & RTC_CR_WUTIE_Msk);
        tmpreg = (uint32_t)((RTC->ISR & (uint32_t)(RTC_ISR_WUTF_Msk)));
    }
    else if( RTC_IT_ALRA == RTC_IT) 
    {
        enablestatus = (uint32_t)(RTC->CR & RTC_CR_ALRAIE_Msk);
        tmpreg = (uint32_t)((RTC->ISR & (uint32_t)(RTC_ISR_ALRAF_Msk)));
    }
    else if( RTC_IT_TAMP1 == RTC_IT) 
    {
        enablestatus = (uint32_t)(RTC->TAMPCR & RTC_TAMPCR_TAMP1IE_Msk);
        tmpreg = (uint32_t)(RTC->TAMPCR & RTC_TAMPCR_TAMP1IF_Msk);
    }
    else if( RTC_IT_TAMP2 == RTC_IT)
    {
        enablestatus = (uint32_t)(RTC->TAMPCR & RTC_TAMPCR_TAMP2IE_Msk);
        tmpreg = (uint32_t)(RTC->TAMPCR & RTC_TAMPCR_TAMP2IF_Msk);
    }
    /* Get the status of the Interrupt */
    if ((enablestatus != (uint32_t)RESET) && (tmpreg != (uint32_t)RESET)) 
    {
        bitstatus = SET;
    }
    else {
        bitstatus = RESET;
    }
    return bitstatus;
}

/**
  * @brief  Clears the RTC's interrupt pending bits.
  * @param  RTC_IT: specifies the RTC interrupt pending bit to clear.
  *          This parameter can be any combination of the following values:
  *            @arg RTC_IT_TS: Time Stamp interrupt
  *            @arg RTC_IT_WUT: WakeUp Timer interrupt
  *            @arg RTC_IT_ALRA: Alarm A interrupt
  *            @arg RTC_IT_TAMP1: Tamper 1 event interrupt
  *            @arg RTC_IT_TAMP2: Tamper 2 event interrupt
  * @retval None
  */
void RTC_ClearITPendingBit(uint32_t RTC_IT)
{

    if( RTC_IT_TS == RTC_IT) 
    {
        RTC->ISR = (uint32_t)((RTC->ISR & (uint32_t)(~RTC_ISR_TSF_Msk)));
    }
    else if( RTC_IT_WUT == RTC_IT) 
    {
        RTC->ISR = (uint32_t)((RTC->ISR & (uint32_t)(~RTC_ISR_WUTF_Msk)));
    }
    else if( RTC_IT_ALRA == RTC_IT) 
    {
        RTC->ISR = (uint32_t)((RTC->ISR & (uint32_t)(~RTC_ISR_ALRAF_Msk)));
    }
    else if( RTC_IT_TAMP1 == RTC_IT) 
    {
        RTC->TAMPCR = (uint32_t)(RTC->TAMPCR & (uint32_t)(~RTC_TAMPCR_TAMP1IF_Msk));
    }
    else if( RTC_IT_TAMP2 == RTC_IT) 
    {
        RTC->TAMPCR = (uint32_t)(RTC->TAMPCR & (uint32_t)(~RTC_TAMPCR_TAMP2IF_Msk)) ;
    }
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

