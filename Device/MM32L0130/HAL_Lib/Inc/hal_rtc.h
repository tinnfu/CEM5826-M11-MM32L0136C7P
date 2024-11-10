/***********************************************************************************************************************
    @file     hal_rtc.h
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
#ifndef __HAL_RTC_H
#define __HAL_RTC_H


/* Files includes ------------------------------------------------------------*/
#include "mm32_device.h"

/** @addtogroup MM32_Hardware_Abstract_Layer
  * @{
  */

/** @defgroup RTC_HAL
  * @brief RTC HAL modules
  * @{
  */

/* Masks Definition */
#define RTC_TR_RESERVED_MASK    ((uint32_t)0x007F7F7F)
#define RTC_DR_RESERVED_MASK    ((uint32_t)0x00FFFF3F)
#define RTC_TSTR_RESERVED_MASK  ((uint32_t)0x007F7F7F)
#define RTC_TSDR_RESERVED_MASK  ((uint32_t)0x00FFFF3F)
#define RTC_INIT_MASK           ((uint32_t)0xFFFFFFFF)
#define RTC_RSF_MASK            ((uint32_t)0xFFFFFF5F)


#define INITMODE_TIMEOUT         ((uint32_t) 0x00010000)
#define SYNCHRO_TIMEOUT          ((uint32_t) 0x00020000)
#define RECALPF_TIMEOUT          ((uint32_t) 0x00020000)
#define SHPF_TIMEOUT             ((uint32_t) 0x00001000)


/** @defgroup RTC_Exported_Types
  * @{
  */


/**
  * @brief  RTC Init structures definition
  */
typedef struct 
{
    uint32_t RTC_HourFormat;
    uint32_t RTC_AsynchPrediv;
    uint32_t RTC_SynchPrediv;
} RTC_InitTypeDef;

/**
  * @brief  RTC Init structures definition
  */
typedef struct 
{
    uint32_t    RTC_LSE_TemperatureCompensation;
    uint32_t    RTC_LSE_OutputEnhancement;
    uint32_t    RTC_LSE_ResistorFeedbackMode;
    uint32_t    RTC_LSE_BiasCurrentLevel;
    uint32_t    RTC_LSE_AutoGain;
} RTC_LSEConfig_TypeDef;

/**
  * @brief  RTC Time structure definition
  */
typedef struct 
{
    uint8_t RTC_Hours;              /*!< RTC Time Hour. Range 0-12 based RTC_HourFormat_12, range 0-23 based RTC_HourFormat_24 */
    uint8_t RTC_Minutes;            /*!< RTC Time Minutes. Range 0-59 */
    uint8_t RTC_Seconds;            /*!< RTC Time Seconds. Range 0-59 */
    uint32_t RTC_H12;               /*!< RTC AM/PM Time. Selected between RTC_HourFormat_12 and RTC_HourFormat_24 */
} RTC_TimeTypeDef;


/**
  * @brief  RTC Date structure definition
  */
typedef struct 
{
    uint8_t RTC_WeekDay;                                                     /*!< RTC Date WeekDay.@ref RTC_WeekDay_Definitions */
    uint8_t RTC_Month;                                                       /*!< RTC Date Month (in BCD format).@ref RTC_Month_Date_Definitions */
    uint8_t RTC_Date;                                                        /*!< RTC Date. Value in the 1-31 range. */
    uint8_t RTC_Year;                                                        /*!< RTC Date Year. Value in the 0-99 range. */
} RTC_DateTypeDef;

/**
  * @brief  RTC Alarm structure definition
  */
typedef struct 
{
    RTC_TimeTypeDef  RTC_AlarmTime;     /*!< RTC Alarm Time members */
    uint32_t  RTC_AlarmMask;               /*!< RTC Alarm Mask Type value */
    uint32_t  RTC_AlarmDateWeekDaySel;     /*!< RTC Alarm is on Date or WeekDay a value */
    uint8_t   RTC_AlarmDateWeekDay;        /*!< RTC Alarm Date/WeekDay */
} RTC_AlarmTypeDef;


/**
  * @brief RTC_Hour_Formats
  */
#define RTC_HourFormat_24     (0x00U << RTC_CR_FMT_Pos) 
#define RTC_HourFormat_12     (0x01U << RTC_CR_FMT_Pos) 

/**
  * @brief RTC_LSE_TemperatureCompensation
  */
#define RTC_LSE_TC_None       (0x00U << RTC_LSE_CFG_LSE_TC_Pos)
#define RTC_LSE_TC_Weak       (0x01U << RTC_LSE_CFG_LSE_TC_Pos)
#define RTC_LSE_TC_Normal     (0x02U << RTC_LSE_CFG_LSE_TC_Pos)
#define RTC_LSE_TC_Strong     (0x03U << RTC_LSE_CFG_LSE_TC_Pos)

/**
  * @brief RTC_LSE_OutputEnhance
  */
#define RTC_LSE_OutputEnhance_Reset   (0x00U << RTC_LSE_CFG_LSE_OUTENH_Msk_Pos)
#define RTC_LSE_OutputEnhance_Set     (0x01U << RTC_LSE_CFG_LSE_OUTENH_Msk_Pos)

/**
  * @brief RTC_LSE_FeedbackResistor
  */
#define RTC_LSE_FeedbackResistorMode0  (0x00U << RTC_LSE_CFG_LSE_RFB_SEL_Pos)
#define RTC_LSE_FeedbackResistorMode1  (0x01U << RTC_LSE_CFG_LSE_RFB_SEL_Pos)
#define RTC_LSE_FeedbackResistorMode2  (0x02U << RTC_LSE_CFG_LSE_RFB_SEL_Pos)
#define RTC_LSE_FeedbackResistorMode3  (0x03U << RTC_LSE_CFG_LSE_RFB_SEL_Pos)

/**
  * @brief RTC_LSE_AutoGain
  */
#define RTC_LSE_AutoGain_Reset         (0x00U << RTC_LSE_CFG_LSE_AAC_Pos)
#define RTC_LSE_AutoGain_Set           (0x01U << RTC_LSE_CFG_LSE_AAC_Pos)

/**
  * @brief RTC_Format
  */
#define RTC_Format_BIN                   0x00U
#define RTC_Format_BCD                   0x01U

/**
  * @brief RTC_AM_PM_status
  */
#define RTC_H12_AM                     (0x00U << RTC_CR_FMT_Pos)   
#define RTC_H12_PM                     (0x01U << RTC_CR_FMT_Pos)   

/**
  * @brief RTC_AlarmsEnable
  */
#define RTC_Alarm_None             (0x00U << RTC_CR_ALRAE_Pos)
#define RTC_Alarm_A                (0x01U << RTC_CR_ALRAE_Pos)

/**
  * @brief RTC_RTC_AlarmMask
  */
#define RTC_AlarmMask_None            (0x01U)
#define RTC_AlarmMask_DateWeekDay     (0x01U << RTC_ALARMAR_MSK4_Pos)
#define RTC_AlarmMask_Hours           (0x01U << RTC_ALARMAR_MSK3_Pos)
#define RTC_AlarmMask_Minutes         (0x01U << RTC_ALARMAR_MSK2_Pos)
#define RTC_AlarmMask_Seconds         (0x01U << RTC_ALARMAR_MSK1_Pos)
#define RTC_AlarmMask_All             (RTC_AlarmMask_DateWeekDay | RTC_AlarmMask_Hours | RTC_AlarmMask_Minutes | RTC_AlarmMask_Seconds)

/**
  * @brief RTC_AM_PM_status
  */
#define RTC_AlarmDateWeekDaySel_Date     (0x00U << RTC_ALARMAR_WDSEL_Pos)
#define RTC_AlarmDateWeekDaySel_WeekDay  (0x01U << RTC_ALARMAR_WDSEL_Pos)


/**
  * @brief RTC_AlarmSubSecondMask
  */
#define RTC_AlarmSubSecondMask_All       (0x00U << RTC_ALARMASSR_MASKSS_Pos)     /*!<  0: Do not compare the subsecond of alarm clock A. */
#define RTC_AlarmSubSecondMask_SS14_1    (0x01U << RTC_ALARMASSR_MASKSS_Pos)     /*!<  1: SSC[ 0] bit for time match, the other bits are ignored. */
#define RTC_AlarmSubSecondMask_SS14_2    (0x02U << RTC_ALARMASSR_MASKSS_Pos)     /*!<  2: SSC[ 1: 0] bit for subsecond match, the other bits are ignored. */
#define RTC_AlarmSubSecondMask_SS14_3    (0x03U << RTC_ALARMASSR_MASKSS_Pos)     /*!<  3: SSC[ 2: 0] bit for subsecond match, the other bits are ignored. */
#define RTC_AlarmSubSecondMask_SS14_4    (0x04U << RTC_ALARMASSR_MASKSS_Pos)     /*!<  4: SSC[ 3: 0] bit for subsecond match, the other bits are ignored. */
#define RTC_AlarmSubSecondMask_SS14_5    (0x05U << RTC_ALARMASSR_MASKSS_Pos)     /*!<  5: SSC[ 4: 0] bit for subsecond match, the other bits are ignored. */
#define RTC_AlarmSubSecondMask_SS14_6    (0x06U << RTC_ALARMASSR_MASKSS_Pos)     /*!<  6: SSC[ 5: 0] bit for subsecond match, the other bits are ignored. */
#define RTC_AlarmSubSecondMask_SS14_7    (0x07U << RTC_ALARMASSR_MASKSS_Pos)     /*!<  7: SSC[ 6: 0] bit for subsecond match, the other bits are ignored. */
#define RTC_AlarmSubSecondMask_SS14_8    (0x08U << RTC_ALARMASSR_MASKSS_Pos)     /*!<  8: SSC[ 7: 0] bit for subsecond match, the other bits are ignored. */
#define RTC_AlarmSubSecondMask_SS14_9    (0x09U << RTC_ALARMASSR_MASKSS_Pos)     /*!<  9: SSC[ 8: 0] bit for subsecond match, the other bits are ignored. */
#define RTC_AlarmSubSecondMask_SS14_10   (0x0AU << RTC_ALARMASSR_MASKSS_Pos)     /*!< 10: SSC[ 9: 0] bit for subsecond match, the other bits are ignored. */
#define RTC_AlarmSubSecondMask_SS14_11   (0x0BU << RTC_ALARMASSR_MASKSS_Pos)     /*!< 11: SSC[10: 0] bit for subsecond match, the other bits are ignored. */
#define RTC_AlarmSubSecondMask_SS14_12   (0x0CU << RTC_ALARMASSR_MASKSS_Pos)     /*!< 12: SSC[11: 0] bit for subsecond match, the other bits are ignored. */
#define RTC_AlarmSubSecondMask_SS14_13   (0x0DU << RTC_ALARMASSR_MASKSS_Pos)     /*!< 13: SSC[12: 0] bit for subsecond match, the other bits are ignored. */
#define RTC_AlarmSubSecondMask_SS14      (0x0EU << RTC_ALARMASSR_MASKSS_Pos)     /*!< 14: SSC[13: 0] bit for subsecond match, the other bits are ignored. */
#define RTC_AlarmSubSecondMask_None      (0x0FU << RTC_ALARMASSR_MASKSS_Pos)     /*!< 15: SSC[14: 0] bit for subsecond match, the other bits are ignored. */




/**
  * @brief RTC_WakeUpClock
  */
#define RTC_WakeUpClock_RTCCLK_Div16     (0x00U << RTC_CR_WUCKSEL_Pos)
#define RTC_WakeUpClock_RTCCLK_Div8      (0x01U << RTC_CR_WUCKSEL_Pos)
#define RTC_WakeUpClock_RTCCLK_Div4      (0x02U << RTC_CR_WUCKSEL_Pos)
#define RTC_WakeUpClock_RTCCLK_Div2      (0x03U << RTC_CR_WUCKSEL_Pos)
#define RTC_WakeUpClock_CK_SPRE_16bits   (0x04U << RTC_CR_WUCKSEL_Pos)
#define RTC_WakeUpClock_CK_SPRE_17bits   (0x06U << RTC_CR_WUCKSEL_Pos)


/**
  * @brief RTC_DayAddOneHour
  */
#define RTC_DayLightSaving_SUB1H         (0x01U << RTC_CR_SUB1H_Pos)
#define RTC_DayLightSaving_ADD1H         (0x01U << RTC_CR_WUTIE_Pos)

/**
  * @brief RTC_StoreOperation
  */

#define RTC_StoreOperation_Reset         (0x00U << RTC_CR_BKP_Pos)
#define RTC_StoreOperation_Set           (0x01U << RTC_CR_BKP_Pos)


/**
  * @brief RTC_Output_selection
  */
#define RTC_Output_Disable               (0x00U << RTC_CR_OSEL_Pos)
#define RTC_Output_AlarmA                (0x01U << RTC_CR_OSEL_Pos)
#define RTC_Output_WakeUp                (0x02U << RTC_CR_OSEL_Pos)

/**
  * @brief RTC_Output_selection
  */
#define RTC_OutputPolarity_High          (0x00U << RTC_CR_POL_Pos)
#define RTC_OutputPolarity_Low           (0x01U << RTC_CR_POL_Pos)


/**
  * @brief RTC_CalibOutput
  */
#define RTC_CalibOutput_512Hz            (0x00U << RTC_CR_COSEL_Pos)
#define RTC_CalibOutput_1Hz              (0x01U << RTC_CR_COSEL_Pos)


/**
  * @brief RTC_CalibPlusPulses
  */
#define RTC_CalibPlusPulses_Set          (0x00U << RTC_CALR_CALP_Pos)
#define RTC_CalibPlusPulses_Reset        (0x01U << RTC_CALR_CALP_Pos)


/**
  * @brief RTC_TimeStampEdge
  */
#define RTC_TimeStampEdge_Rising         (0x00U << RTC_CR_TSEDGE_Pos)
#define RTC_TimeStampEdge_Falling        (0x01U << RTC_CR_TSEDGE_Pos)

/**
  * @brief RTC_Tamper
  */
#define RTC_Tamper_1                     (0x01U << RTC_TAMPCR_TAMP1E_Pos) 
#define RTC_Tamper_2                     (0x01U << RTC_TAMPCR_TAMP2E_Pos) 

/**
  * @brief RTC_TamperTrigger
  */
#define RTC_TamperTrigger_RisingEdge     (0x00U)
#define RTC_TamperTrigger_FallingEdge    (0x01U)


#define RTC_BKP_DR0                      (0x00U)
#define RTC_BKP_DR1                      (0x01U)
#define RTC_BKP_DR2                      (0x02U)
#define RTC_BKP_DR3                      (0x03U)
#define RTC_BKP_DR4                      (0x04U)


/**
  * @brief RTC_ShiftAdd1S
  */
#define RTC_ShiftAdd1S_Reset             (0x00U << RTC_SHIFTER_ADD1S_Pos) 
#define RTC_ShiftAdd1S_Set               (0x01U << RTC_SHIFTER_ADD1S_Pos) 


/**
  * @brief RTC_flags_define
  */
#define RTC_FLAG_ALRAWF        (0x00U)
#define RTC_FLAG_WUTWF         (0x01U)
#define RTC_FLAG_SHPF          (0x02U)
#define RTC_FLAG_INITS         (0x03U)
#define RTC_FLAG_INITF         (0x04U)
#define RTC_FLAG_ALRAF         (0x05U)
#define RTC_FLAG_WUTF          (0x06U)
#define RTC_FLAG_TSF           (0x07U)
#define RTC_FLAG_TSOVF         (0x08U)
#define RTC_FLAG_TAMP1F        (0x09U)
#define RTC_FLAG_TAMP2F        (0x0AU)

/**
  * @brief RTC_IT
  */
#define RTC_IT_TS              (0x00U)
#define RTC_IT_WUT             (0x01U)
#define RTC_IT_ALRA            (0x02U)
#define RTC_IT_TAMP1           (0x03U)
#define RTC_IT_TAMP2           (0x04U)




/**
  * @brief RTC_Month
  */
#define RTC_Month_January                (0x01)
#define RTC_Month_February               (0x02)
#define RTC_Month_March                  (0x03)
#define RTC_Month_April                  (0x04)
#define RTC_Month_May                    (0x05)
#define RTC_Month_June                   (0x06)
#define RTC_Month_July                   (0x07)
#define RTC_Month_August                 (0x08)
#define RTC_Month_September              (0x09)
#define RTC_Month_October                (0x10)                             
#define RTC_Month_November               (0x11)                             
#define RTC_Month_December               (0x12)                             


/**
  * @brief RTC_WeekDay
  */
#define RTC_Weekday_Monday               (0x01)
#define RTC_Weekday_Tuesday              (0x02)
#define RTC_Weekday_Wednesday            (0x03)
#define RTC_Weekday_Thursday             (0x04)
#define RTC_Weekday_Friday               (0x05)
#define RTC_Weekday_Saturday             (0x06)
#define RTC_Weekday_Sunday               (0x07)



/**
  * @}
  */




/** @defgroup RTC_Exported_Functions
  * @{
  */
ErrorStatus RTC_EnterInitMode(void);
ErrorStatus RTC_DeInit(void);
void RTC_StructInit(RTC_InitTypeDef* init_struct);
ErrorStatus RTC_Init(RTC_InitTypeDef* init_struct);
ErrorStatus RTC_LSEConfig(RTC_LSEConfig_TypeDef* config_struct);
void RTC_OutputPinRemap(uint32_t remap_mode);
void RTC_ExitInitMode(void);
ErrorStatus RTC_WaitForSynchro(void);
void RTC_BypassShadowCmd(FunctionalState state);
ErrorStatus RTC_SetTime(uint32_t RTC_Format, RTC_TimeTypeDef* RTC_TimeStruct);
void RTC_TimeStructInit(RTC_TimeTypeDef* RTC_TimeStruct);
void RTC_GetTime(uint32_t RTC_Format, RTC_TimeTypeDef* RTC_TimeStruct);
uint32_t RTC_GetSubSecond(void);
ErrorStatus RTC_SetDate(uint8_t RTC_Format, RTC_DateTypeDef* RTC_DateStruct);
void RTC_DateStructInit(RTC_DateTypeDef* RTC_DateStruct);
void RTC_GetDate(uint8_t RTC_Format, RTC_DateTypeDef* RTC_DateStruct);
ErrorStatus RTC_SetAlarm(uint8_t RTC_Format, uint32_t RTC_Alarm, RTC_AlarmTypeDef* RTC_AlarmStruct);
void RTC_AlarmStructInit(RTC_AlarmTypeDef* RTC_AlarmStruct);
void RTC_GetAlarm(uint8_t RTC_Format, uint32_t RTC_Alarm, RTC_AlarmTypeDef* RTC_AlarmStruct);
ErrorStatus RTC_AlarmCmd(uint32_t RTC_Alarm, FunctionalState state);
void RTC_AlarmSubSecondConfig(uint32_t RTC_Alarm, uint32_t RTC_AlarmSubSecondValue, uint32_t RTC_AlarmSubSecondMask);
uint32_t RTC_GetAlarmSubSecond(uint32_t RTC_Alarm);
void RTC_WakeUpClockConfig(uint32_t RTC_WakeUpClock);
void RTC_SetWakeUpCounter(uint32_t RTC_WakeUpCounter);
uint32_t RTC_GetWakeUpCounter(void);
ErrorStatus RTC_WakeUpCmd(FunctionalState state);
void RTC_DayLightSavingConfig(uint32_t RTC_DayLightSaving, uint32_t RTC_StoreOperation);
uint32_t RTC_GetStoreOperation(void);
void RTC_OutputConfig(uint32_t RTC_Output, uint32_t RTC_OutputPolarity);
void RTC_CalibOutputCmd(FunctionalState state);
void RTC_CalibOutputConfig(uint32_t RTC_CalibOutput);
ErrorStatus RTC_CalibConfig(uint32_t RTC_CalibPlusPulses, uint32_t RTC_CalibMinusPulsesValue);
void RTC_TimeStampCmd(uint32_t RTC_TimeStampEdge, FunctionalState state);
void RTC_GetTimeStamp(uint8_t RTC_Format, RTC_TimeTypeDef* RTC_StampTimeStruct,
                         RTC_DateTypeDef* RTC_StampDateStruct);
uint32_t RTC_GetTimeStampSubSecond(void);
void RTC_TamperTriggerConfig(uint32_t RTC_Tamper, uint32_t RTC_TamperTrigger);
void RTC_TamperCmd(uint32_t RTC_Tamper, FunctionalState state);
void RTC_TimeStampOnTamperDetectionCmd(FunctionalState state);
void RTC_WriteBackupRegister(uint8_t BKP_DR_x, uint32_t u32data);
uint32_t RTC_ReadBackupRegister(uint8_t RTC_BKP_DR);
ErrorStatus RTC_SynchroShiftConfig(uint32_t RTC_ShiftAdd1S, uint32_t RTC_ShiftSubFS);
FlagStatus RTC_GetFlagStatus(uint32_t RTC_FLAG);
void RTC_ClearFlag(uint32_t RTC_FLAG);
void RTC_ITConfig(uint32_t RTC_IT, FunctionalState state);
ITStatus RTC_GetITStatus(uint32_t RTC_IT);
void RTC_ClearITPendingBit(uint32_t RTC_IT);

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */




#endif
