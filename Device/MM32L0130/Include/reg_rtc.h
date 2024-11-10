/***********************************************************************************************************************
    @file     reg_rtc.h
    @author   VV TEAM
    @brief    This flie contains all the RTC's register and its field definition.
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

/* Define to prevent recursive inclusion -----------------------------------------------------------------------------*/

#ifndef __REG_RTC_H
#define __REG_RTC_H


/* Files includes ----------------------------------------------------------------------------------------------------*/
#include <core_cm0plus.h>



/**
  * @brief RTC Base Address Definition
  */
#define  RTC_BASE                                  0x40002800                                       /*!<Base Address: 0x40002800*/

/**
  * @brief RTC Register Structure Definition
  */
typedef struct
{
    __IO uint32_t TR;                             /*!<RTC RTC time register                          offset: 0x00*/
    __IO uint32_t DR;                             /*!<RTC RTC date register                          offset: 0x04*/
    __IO uint32_t CR;                             /*!<RTC RTC control register                       offset: 0x08*/
    __IO uint32_t ISR;                            /*!<RTC RTC initial and status register            offset: 0x0C*/
    __IO uint32_t PRER;                           /*!<RTC RTC division register                      offset: 0x10*/
    __IO uint32_t WUTR;                           /*!<RTC RTC wake up register                       offset: 0x14*/
    __IO uint32_t LSE_CFG;                        /*!<RTC RTC LSE configuration register             offset: 0x18*/
    __IO uint32_t ALARMAR;                        /*!<RTC RTC alarm clock A register                 offset: 0x1C*/
    __IO uint32_t OR;                             /*!<RTC RTC output control register                offset: 0x20*/
    __IO uint32_t SSR;                            /*!<RTC RTC subsecond register                     offset: 0x24*/
    __IO uint32_t TSTR;                           /*!<RTC RTC timestamp time register                offset: 0x28*/
    __IO uint32_t TSDR;                           /*!<RTC RTC timestamp date register                offset: 0x2C*/
    __IO uint32_t TSSR;                           /*!<RTC RTC timestamp subsecond register           offset: 0x30*/
    __IO uint32_t CALR;                           /*!<RTC RTC calibration register                   offset: 0x34*/
    __IO uint32_t SHIFTR;                         /*!<RTC RTC shift control register                 offset: 0x38*/
    __IO uint32_t ALARMASSR;                      /*!<RTC RTC alarm clock A subsecond register       offset: 0x3C*/
    __IO uint32_t TAMPCR;                         /*!<RTC RTC tamper register                        offset: 0x40*/
    __IO uint32_t RESERVED0x044[3];               /*!<                                               offset: 0x44~0x4c*/
    __IO uint32_t BKP0R;                          /*!<RTC BKP backup register                        offset: 0x50*/
    __IO uint32_t BKP1R;                          /*!<RTC BKP backup register                        offset: 0x54*/
    __IO uint32_t BKP2R;                          /*!<RTC BKP backup register                        offset: 0x58*/
    __IO uint32_t BKP3R;                          /*!<RTC BKP backup register                        offset: 0x5C*/
    __IO uint32_t BKP4R;                          /*!<RTC BKP backup register                        offset: 0x60*/
} RTC_TypeDef;

/**
  * @brief RTC type pointer Definition
  */
#define RTC                                       ((RTC_TypeDef *)RTC_BASE)

/**
  * @brief RTC_TR Register Bit Definition
  */
#define  RTC_TR_SU_Pos                            (0)
#define  RTC_TR_SU_Msk                            (0x0FU << RTC_TR_SU_Pos)                          /*!<Units of seconds*/
#define  RTC_TR_ST_Pos                            (4)
#define  RTC_TR_ST_Msk                            (0x07U << RTC_TR_ST_Pos)                          /*!<Tens of seconds*/
#define  RTC_TR_MNU_Pos                           (8)
#define  RTC_TR_MNU_Msk                           (0x0FU << RTC_TR_MNU_Pos)                         /*!<Units of minutes*/
#define  RTC_TR_MNT_Pos                           (12)
#define  RTC_TR_MNT_Msk                           (0x07U << RTC_TR_MNT_Pos)                         /*!<Tens of minutes*/
#define  RTC_TR_HU_Pos                            (16)
#define  RTC_TR_HU_Msk                            (0x0FU << RTC_TR_HU_Pos)                          /*!<Units of hours*/
#define  RTC_TR_HT_Pos                            (20)
#define  RTC_TR_HT_Msk                            (0x03U << RTC_TR_HT_Pos)                          /*!<Tens of hours*/
#define  RTC_TR_PM_Pos                            (22)
#define  RTC_TR_PM_Msk                            (0x01U << RTC_TR_PM_Pos)                          /*!<0:24 hour format*/

/**
  * @brief RTC_DR Register Bit Definition
  */
#define  RTC_DR_DU_Pos                            (0)
#define  RTC_DR_DU_Msk                            (0x0FU << RTC_DR_DU_Pos)                          /*!<Units of dates*/
#define  RTC_DR_DT_Pos                            (4)
#define  RTC_DR_DT_Msk                            (0x03U << RTC_DR_DT_Pos)                          /*!<Tens of dates*/
#define  RTC_DR_MU_Pos                            (8)
#define  RTC_DR_MU_Msk                            (0x0FU << RTC_DR_MU_Pos)                          /*!<Units of months*/
#define  RTC_DR_MT_Pos                            (12)
#define  RTC_DR_MT_Msk                            (0x01U << RTC_DR_MT_Pos)                          /*!<Tens of months*/
#define  RTC_DR_WDU_Pos                           (13)
#define  RTC_DR_WDU_Msk                           (0x07U << RTC_DR_WDU_Pos)                         /*!<Week day unit*/
#define  RTC_DR_YU_Pos                            (16)
#define  RTC_DR_YU_Msk                            (0x0FU << RTC_DR_YU_Pos)                          /*!<Units of years*/
#define  RTC_DR_YT_Pos                            (20)
#define  RTC_DR_YT_Msk                            (0x0FU << RTC_DR_YT_Pos)                          /*!<Tens of years*/

/**
  * @brief RTC_CR Register Bit Definition
  */
#define  RTC_CR_WUCKSEL_Pos                       (0)
#define  RTC_CR_WUCKSEL_Msk                       (0x07U << RTC_CR_WUCKSEL_Pos)                     /*!<Wake up clock selection*/
#define  RTC_CR_TSEDGE_Pos                        (4)
#define  RTC_CR_TSEDGE_Msk                        (0x01U << RTC_CR_TSEDGE_Pos)                      /*!<Active edge of timestamp event*/
#define  RTC_CR_BYPSHAD_Pos                       (5)
#define  RTC_CR_BYPSHAD_Msk                       (0x01U << RTC_CR_BYPSHAD_Pos)                     /*!<Bypass shadow register*/
#define  RTC_CR_FMT_Pos                           (6)
#define  RTC_CR_FMT_Msk                           (0x01U << RTC_CR_FMT_Pos)                         /*!<Hour format*/
#define  RTC_CR_ALRAE_Pos                         (7)
#define  RTC_CR_ALRAE_Msk                         (0x01U << RTC_CR_ALRAE_Pos)                       /*!<Alarm clock A enable*/
#define  RTC_CR_WUTE_Pos                          (10)
#define  RTC_CR_WUTE_Msk                          (0x01U << RTC_CR_WUTE_Pos)                        /*!<Wake up timer enable*/
#define  RTC_CR_TSE_Pos                           (11)
#define  RTC_CR_TSE_Msk                           (0x01U << RTC_CR_TSE_Pos)                         /*!<Timestamp enable*/
#define  RTC_CR_TSIE_Pos                          (12)
#define  RTC_CR_TSIE_Msk                          (0x01U << RTC_CR_TSIE_Pos)                        /*!<Timestamp interrupt enable*/
#define  RTC_CR_WUTIE_Pos                         (13)
#define  RTC_CR_WUTIE_Msk                         (0x01U << RTC_CR_WUTIE_Pos)                       /*!<Wake up timer interrupt enable*/
#define  RTC_CR_ALRAIE_Pos                        (14)
#define  RTC_CR_ALRAIE_Msk                        (0x01U << RTC_CR_ALRAIE_Pos)                      /*!<Alarm clock A interrupt enable*/
#define  RTC_CR_ADD1H_Pos                         (16)
#define  RTC_CR_ADD1H_Msk                         (0x01U << RTC_CR_ADD1H_Pos)                       /*!<0: This bit is inactive*/
#define  RTC_CR_SUB1H_Pos                         (17)
#define  RTC_CR_SUB1H_Msk                         (0x01U << RTC_CR_SUB1H_Pos)                       /*!<0: This bit is inactive*/
#define  RTC_CR_BKP_Pos                           (18)
#define  RTC_CR_BKP_Msk                           (0x01U << RTC_CR_BKP_Pos)                         /*!<BKP record summer time operation*/
#define  RTC_CR_OSEL_Pos                          (19)
#define  RTC_CR_OSEL_Msk                          (0x03U << RTC_CR_OSEL_Pos)                        /*!<Output flag selection*/
#define  RTC_CR_COSEL_Pos                         (21)
#define  RTC_CR_COSEL_Msk                         (0x01U << RTC_CR_COSEL_Pos)                       /*!<COSEL: Calibration output selection*/
#define  RTC_CR_COE_Pos                           (22)
#define  RTC_CR_COE_Msk                           (0x01U << RTC_CR_COE_Pos)                         /*!<COE: Calibration output enable*/
#define  RTC_CR_POL_Pos                           (23)
#define  RTC_CR_POL_Msk                           (0x01U << RTC_CR_POL_Pos)                         /*!<POL: Output polarity Configure the polarity of RTC_ALARM output*/

/**
  * @brief RTC_ISR Register Bit Definition
  */
#define  RTC_ISR_ALRAWF_Pos                       (0)
#define  RTC_ISR_ALRAWF_Msk                       (0x01U << RTC_ISR_ALRAWF_Pos)                     /*!<Alarm clock A write flag*/
#define  RTC_ISR_WUTWF_Pos                        (2)
#define  RTC_ISR_WUTWF_Msk                        (0x01U << RTC_ISR_WUTWF_Pos)                      /*!<Wake up timer write flag*/
#define  RTC_ISR_SHPF_Pos                         (3)
#define  RTC_ISR_SHPF_Msk                         (0x01U << RTC_ISR_SHPF_Pos)                       /*!<Shift operation flag*/
#define  RTC_ISR_INITS_Pos                        (4)
#define  RTC_ISR_INITS_Msk                        (0x01U << RTC_ISR_INITS_Pos)                      /*!<Initializing status flag*/
#define  RTC_ISR_RSF_Pos                          (5)
#define  RTC_ISR_RSF_Msk                          (0x01U << RTC_ISR_RSF_Pos)                        /*!<Register synchronization flag*/
#define  RTC_ISR_INITF_Pos                        (6)
#define  RTC_ISR_INITF_Msk                        (0x01U << RTC_ISR_INITF_Pos)                      /*!<It is cleared when the prescaler value update operation is completed (takes up to 5 oscillator cycles at 40KHz).The prescaler value can be updated only when PVU bit is cleared.*/
#define  RTC_ISR_INIT_Pos                         (7)
#define  RTC_ISR_INIT_Msk                         (0x01U << RTC_ISR_INIT_Pos)                       /*!<Initializing mode*/
#define  RTC_ISR_ALRAF_Pos                        (8)
#define  RTC_ISR_ALRAF_Msk                        (0x01U << RTC_ISR_ALRAF_Pos)                      /*!<Alarm clock occurrence flagThe current time/date is consistent with the alarm clock register, the flag is set by hardware, and cleared by software.*/
#define  RTC_ISR_WUTF_Pos                         (10)
#define  RTC_ISR_WUTF_Msk                         (0x01U << RTC_ISR_WUTF_Pos)                       /*!<Wake up unit flagWhen the wake up auto reload counter counts to 0, the flag is set by hardware, and cleared by software.*/
#define  RTC_ISR_TSF_Pos                          (11)
#define  RTC_ISR_TSF_Msk                          (0x01U << RTC_ISR_TSF_Pos)                        /*!<Timestamp event flagIn case of timestamp event, the flag is set by hardware, and cleared by software.*/
#define  RTC_ISR_TSOVF_Pos                        (12)
#define  RTC_ISR_TSOVF_Msk                        (0x01U << RTC_ISR_TSOVF_Pos)                      /*!<Timestamp overflow flagIn case of timestamp event when the TSF is set, the flag is set by hardware, and cleared by software.*/

/**
  * @brief RTC_PRER Register Bit Definition
  */
#define  RTC_PRER_PREDIV_S_Pos                    (0)
#define  RTC_PRER_PREDIV_S_Msk                    (0x7FFFU << RTC_PRER_PREDIV_S_Pos)                /*!<Synchronous prescaler coefficient*/
#define  RTC_PRER_PREDIV_A_Pos                    (16)
#define  RTC_PRER_PREDIV_A_Msk                    (0x7FU << RTC_PRER_PREDIV_A_Pos)                  /*!<Asynchronous prescaler coefficient*/

/**
  * @brief RTC_WUTR Register Bit Definition
  */
#define  RTC_WUTR_WUTRL_Pos                       (0)
#define  RTC_WUTR_WUTRL_Msk                       (0xFFFFU << RTC_WUTR_WUTRL_Pos)                   /*!<Wake up auto reload value bit*/
#define  RTC_WUTR_WUTRH_Pos                       (16)
#define  RTC_WUTR_WUTRH_Msk                       (0x01U << RTC_WUTR_WUTRH_Pos)                     /*!<Configure WUCKSEL[2] =1. This bit is always set. It's cleared under other conditions.*/

/**
  * @brief RTC_LSE_CFG Register Bit Definition
  */
#define  RTC_LSE_CFG_LSE_TC_Pos                   (0)
#define  RTC_LSE_CFG_LSE_TC_Msk                   (0x03U << RTC_LSE_CFG_LSE_TC_Pos)                 /*!<LSE high temperature leakage compensation mode:*/
#define  RTC_LSE_CFG_LSE_OUTENH_Pos               (2)
#define  RTC_LSE_CFG_LSE_OUTENH_Msk               (0x01U << RTC_LSE_CFG_LSE_OUTENH_Pos)             /*!<0: Normal mode*/
#define  RTC_LSE_CFG_LSE_DR_Pos                   (4)
#define  RTC_LSE_CFG_LSE_DR_Msk                   (0x03U << RTC_LSE_CFG_LSE_DR_Pos)                 /*!<LSE_DR: LSE drive capacity selection 00 to 11: Drive capacity up*/
#define  RTC_LSE_CFG_LSE_RFB_SEL_Pos              (6)
#define  RTC_LSE_CFG_LSE_RFB_SEL_Msk              (0x03U << RTC_LSE_CFG_LSE_RFB_SEL_Pos)            /*!<LSE_RFB_SEL: LSE feedback resistance selection*/
#define  RTC_LSE_CFG_LSE_IB_Pos                   (8)
#define  RTC_LSE_CFG_LSE_IB_Msk                   (0x03U << RTC_LSE_CFG_LSE_IB_Pos)                 /*!<LSE_IB: LSE bias current regulation00 to 11: bias current regulation up*/
#define  RTC_LSE_CFG_LSE_AAC_Pos                  (10)
#define  RTC_LSE_CFG_LSE_AAC_Msk                  (0x01U << RTC_LSE_CFG_LSE_AAC_Pos)                /*!<Auto gain regulation*/

/**
  * @brief RTC_ALARMAR Register Bit Definition
  */
#define  RTC_ALARMAR_SU_Pos                       (0)
#define  RTC_ALARMAR_SU_Msk                       (0x0FU << RTC_ALARMAR_SU_Pos)                     /*!<Units of seconds*/
#define  RTC_ALARMAR_ST_Pos                       (4)
#define  RTC_ALARMAR_ST_Msk                       (0x07U << RTC_ALARMAR_ST_Pos)                     /*!<Tens of seconds*/
#define  RTC_ALARMAR_MSK1_Pos                     (7)
#define  RTC_ALARMAR_MSK1_Msk                     (0x01U << RTC_ALARMAR_MSK1_Pos)                   /*!<Alarm clock second mask bit*/
#define  RTC_ALARMAR_MNU_Pos                      (8)
#define  RTC_ALARMAR_MNU_Msk                      (0x0FU << RTC_ALARMAR_MNU_Pos)                    /*!<Units of minutes*/
#define  RTC_ALARMAR_MNT_Pos                      (12)
#define  RTC_ALARMAR_MNT_Msk                      (0x07U << RTC_ALARMAR_MNT_Pos)                    /*!<Tens of minutes*/
#define  RTC_ALARMAR_MSK2_Pos                     (15)
#define  RTC_ALARMAR_MSK2_Msk                     (0x01U << RTC_ALARMAR_MSK2_Pos)                   /*!<Alarm clock minute mask bit*/
#define  RTC_ALARMAR_HU_Pos                       (16)
#define  RTC_ALARMAR_HU_Msk                       (0x0FU << RTC_ALARMAR_HU_Pos)                     /*!<Units of hours*/
#define  RTC_ALARMAR_HT_Pos                       (20)
#define  RTC_ALARMAR_HT_Msk                       (0x03U << RTC_ALARMAR_HT_Pos)                     /*!<Tens of hours*/
#define  RTC_ALARMAR_PM_Pos                       (22)
#define  RTC_ALARMAR_PM_Msk                       (0x01U << RTC_ALARMAR_PM_Pos)                     /*!<0: 24 hour format*/
#define  RTC_ALARMAR_MSK3_Pos                     (23)
#define  RTC_ALARMAR_MSK3_Msk                     (0x01U << RTC_ALARMAR_MSK3_Pos)                   /*!<Alarm clock hour mask bit*/
#define  RTC_ALARMAR_DU_Pos                       (24)
#define  RTC_ALARMAR_DU_Msk                       (0x0FU << RTC_ALARMAR_DU_Pos)                     /*!<Units of date*/
#define  RTC_ALARMAR_DT_Pos                       (28)
#define  RTC_ALARMAR_DT_Msk                       (0x03U << RTC_ALARMAR_DT_Pos)                     /*!<Tens of date*/
#define  RTC_ALARMAR_WDSEL_Pos                    (30)
#define  RTC_ALARMAR_WDSEL_Msk                    (0x01U << RTC_ALARMAR_WDSEL_Pos)                  /*!<Alarm clock date or week day selection bit*/
#define  RTC_ALARMAR_MSK4_Pos                     (31)
#define  RTC_ALARMAR_MSK4_Msk                     (0x01U << RTC_ALARMAR_MSK4_Pos)                   /*!<Alarm clock date or week day mask bit*/

/**
  * @brief RTC_OR Register Bit Definition
  */
#define  RTC_OR_REMAP_Pos                         (0)
#define  RTC_OR_REMAP_Msk                         (0x01U << RTC_OR_REMAP_Pos)                       /*!<remap=0:In case OSEL!=0: RTC_ALARM outputs to PC13 In case of OSEL=0 and COE ='1': RTC_CALIB outputs to PC13 remap=1:In case of OSEL!=0 and COE =0: RTC_ALARM outputs to PB14 or PA8In case of OSEL=0 and COE =1: RTC_CALIB outputs to PB14 or PA8In case of OSEL!=0 and COE =1: RTC_CALIB outputs to PB14 or PA8 and RTC_ALARM outputs to PC13.*/

/**
  * @brief RTC_SSR Register Bit Definition
  */
#define  RTC_SSR_SS_Pos                           (0)
#define  RTC_SSR_SS_Msk                           (0x7FFFU << RTC_SSR_SS_Pos)                       /*!<SS is the value of synchronous prescaler counter. Subsecond calculation formula:Subsecond value=(PREDIV_S–SS)/(PREDIV_S+1)*/

/**
  * @brief RTC_TSTR Register Bit Definition
  */
#define  RTC_TSTR_SU_Pos                          (0)
#define  RTC_TSTR_SU_Msk                          (0x0FU << RTC_TSTR_SU_Pos)                        /*!<Units of seconds*/
#define  RTC_TSTR_ST_Pos                          (4)
#define  RTC_TSTR_ST_Msk                          (0x07U << RTC_TSTR_ST_Pos)                        /*!<Tens of seconds*/
#define  RTC_TSTR_MNU_Pos                         (8)
#define  RTC_TSTR_MNU_Msk                         (0x0FU << RTC_TSTR_MNU_Pos)                       /*!<Units of minutes*/
#define  RTC_TSTR_MNT_Pos                         (12)
#define  RTC_TSTR_MNT_Msk                         (0x07U << RTC_TSTR_MNT_Pos)                       /*!<Tens of minutes*/
#define  RTC_TSTR_HU_Pos                          (16)
#define  RTC_TSTR_HU_Msk                          (0x0FU << RTC_TSTR_HU_Pos)                        /*!<Units of hours*/
#define  RTC_TSTR_HT_Pos                          (20)
#define  RTC_TSTR_HT_Msk                          (0x03U << RTC_TSTR_HT_Pos)                        /*!<Tens of hours*/
#define  RTC_TSTR_PM_Pos                          (22)
#define  RTC_TSTR_PM_Msk                          (0x01U << RTC_TSTR_PM_Pos)                        /*!<0: 24 hour format*/

/**
  * @brief RTC_TSDR Register Bit Definition
  */
#define  RTC_TSDR_DU_Pos                          (0)
#define  RTC_TSDR_DU_Msk                          (0x0FU << RTC_TSDR_DU_Pos)                        /*!<Units of date*/
#define  RTC_TSDR_DT_Pos                          (4)
#define  RTC_TSDR_DT_Msk                          (0x03U << RTC_TSDR_DT_Pos)                        /*!<Tens of date*/
#define  RTC_TSDR_MU_Pos                          (8)
#define  RTC_TSDR_MU_Msk                          (0x0FU << RTC_TSDR_MU_Pos)                        /*!<Units of months*/
#define  RTC_TSDR_MT_Pos                          (12)
#define  RTC_TSDR_MT_Msk                          (0x01U << RTC_TSDR_MT_Pos)                        /*!<Tens of months*/
#define  RTC_TSDR_WDU_Pos                         (13)
#define  RTC_TSDR_WDU_Msk                         (0x07U << RTC_TSDR_WDU_Pos)                       /*!<Week day unit*/
#define  RTC_TSDR_YU_Pos                          (16)
#define  RTC_TSDR_YU_Msk                          (0x0FU << RTC_TSDR_YU_Pos)                        /*!<Units of years*/
#define  RTC_TSDR_YT_Pos                          (20)
#define  RTC_TSDR_YT_Msk                          (0x0FU << RTC_TSDR_YT_Pos)                        /*!<Tens of yearsSubsecond value=(PREDIV_S–SS)/(PREDIV_S+1)*/

/**
  * @brief RTC_TSSR Register Bit Definition
  */
#define  RTC_TSSR_SS_Pos                          (0)
#define  RTC_TSSR_SS_Msk                          (0x7FFFU << RTC_TSSR_SS_Pos)                      /*!<Subsecond valueIn case of timestamp event, record the value of synchronous prescaler counter.*/

/**
  * @brief RTC_CALR Register Bit Definition
  */
#define  RTC_CALR_CALM_Pos                        (0)
#define  RTC_CALR_CALM_Msk                        (0x01FFU << RTC_CALR_CALM_Pos)                    /*!<The number of pulse masked within 220 RTC clock pulseThe crystal resonator for compensation is greater than the actual value*/
#define  RTC_CALR_CALP_Pos                        (15)
#define  RTC_CALR_CALP_Msk                        (0x01U << RTC_CALR_CALP_Pos)                      /*!<Frequency increase 488.5 ppm*/

/**
  * @brief RTC_SHIFTR Register Bit Definition
  */
#define  RTC_SHIFTR_SUBFS_Pos                     (0)
#define  RTC_SHIFTR_SUBFS_Msk                     (0x7FFFU << RTC_SHIFTR_SUBFS_Pos)                 /*!<Reduce subsecond value*/
#define  RTC_SHIFTR_ADD1S_Pos                     (16)
#define  RTC_SHIFTR_ADD1S_Msk                     (0x01U << RTC_SHIFTR_ADD1S_Pos)                   /*!<Increase 1s*/

/**
  * @brief RTC_ALARMASSR Register Bit Definition
  */
#define  RTC_ALARMASSR_SS_Pos                     (0)
#define  RTC_ALARMASSR_SS_Msk                     (0x7FFFU << RTC_ALARMASSR_SS_Pos)                 /*!<Alarm clock subsecond value, used for comparing with the synchronous prescaler counter*/
#define  RTC_ALARMASSR_MASKSS_Pos                 (16)
#define  RTC_ALARMASSR_MASKSS_Msk                 (0x0FU << RTC_ALARMASSR_MASKSS_Pos)               /*!<Max. valid bit when the mask starts from this bit.*/

/**
  * @brief RTC_TAMPCR Register Bit Definition
  */
#define  RTC_TAMPCR_TAMP1E_Pos                    (0)
#define  RTC_TAMPCR_TAMP1E_Msk                    (0x01U << RTC_TAMPCR_TAMP1E_Pos)                  /*!<TAMP1 tamper enable*/
#define  RTC_TAMPCR_TAMP1IE_Pos                   (1)
#define  RTC_TAMPCR_TAMP1IE_Msk                   (0x01U << RTC_TAMPCR_TAMP1IE_Pos)                 /*!<TAMP1 tamper interrupt enable*/
#define  RTC_TAMPCR_TAMP1TRG_Pos                  (2)
#define  RTC_TAMPCR_TAMP1TRG_Msk                  (0x01U << RTC_TAMPCR_TAMP1TRG_Pos)                /*!<TAMP1 tamper valid edge selection*/
#define  RTC_TAMPCR_TAMP1F_Pos                    (3)
#define  RTC_TAMPCR_TAMP1F_Msk                    (0x01U << RTC_TAMPCR_TAMP1F_Pos)                  /*!<TAMP1 tamper flag When the active tamper event is detected on TAMP1 pin, the flag is set by hardware, and cleared by software.*/
#define  RTC_TAMPCR_TAMPTS_Pos                    (4)
#define  RTC_TAMPCR_TAMPTS_Msk                    (0x01U << RTC_TAMPCR_TAMPTS_Pos)                  /*!<Activate timestamp in case of tamper detection event*/
#define  RTC_TAMPCR_TAMP2E_Pos                    (5)
#define  RTC_TAMPCR_TAMP2E_Msk                    (0x01U << RTC_TAMPCR_TAMP2E_Pos)                  /*!<TAMP2 tamper enable*/
#define  RTC_TAMPCR_TAMP2IE_Pos                   (6)
#define  RTC_TAMPCR_TAMP2IE_Msk                   (0x01U << RTC_TAMPCR_TAMP2IE_Pos)                 /*!<TAMP2 tamper interrupt enable*/
#define  RTC_TAMPCR_TAMP2TRG_Pos                  (7)
#define  RTC_TAMPCR_TAMP2TRG_Msk                  (0x01U << RTC_TAMPCR_TAMP2TRG_Pos)                /*!<TAMP2 tamper valid edge selection*/
#define  RTC_TAMPCR_TAMP2F_Pos                    (8)
#define  RTC_TAMPCR_TAMP2F_Msk                    (0x01U << RTC_TAMPCR_TAMP2F_Pos)                  /*!<TAMP2 tamper flagWhen the active tamper event is detected on TAMP2 pin, the flag is set by hardware, and cleared by software.*/
#define  RTC_TAMPCR_TAMP1IF_Pos                   (9)
#define  RTC_TAMPCR_TAMP1IF_Msk                   (0x01U << RTC_TAMPCR_TAMP1IF_Pos)                 /*!<Tamper event 1 interrupt flag. The flag is set by hardware, and cleared by software.*/
#define  RTC_TAMPCR_TAMP2IF_Pos                   (10)
#define  RTC_TAMPCR_TAMP2IF_Msk                   (0x01U << RTC_TAMPCR_TAMP2IF_Pos)                 /*!<Tamper event 2 interrupt flag. The flag is set by hardware, and cleared by software.*/

/**
  * @brief RTC_BKPR Register Bit Definition
  */
#define  RTC_BKPR_BKP_Pos                         (0)
#define  RTC_BKPR_BKP_Msk                         (0xFFFFFFFFU << RTC_BKPR_BKP_Pos)                 /*!<When the device works in the low power mode, the content of these registers keeps active. In case of tamper detection event, the register will be reset. In case of TAMP1F=1 or TAMP2F=1, the register remains reset.*/


#endif

