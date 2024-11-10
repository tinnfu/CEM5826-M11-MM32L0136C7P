/***********************************************************************************************************************
    @file     reg_tim.h
    @author   VV TEAM
    @brief    This flie contains all the TIM's register and its field definition.
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

#ifndef __REG_TIM_H
#define __REG_TIM_H


/* Files includes ----------------------------------------------------------------------------------------------------*/
#include <core_cm0plus.h>



/**
  * @brief TIM Base Address Definition
  */
#define  TIM16_BASE                                0x40014400                                       /*!<Base Address: 0x40014400*/
#define  TIM17_BASE                                0x40014800                                       /*!<Base Address: 0x40014800*/
#define  TIM3_BASE                                 0x40000400                                       /*!<Base Address: 0x40000400*/
#define  TIM4_BASE                                 0x40000800                                       /*!<Base Address: 0x40000800*/

/**
  * @brief TIM Register Structure Definition
  */
typedef struct
{
    __IO uint32_t CR1;                            /*!<TIM Control Register 1                         offset: 0x00*/
    __IO uint32_t CR2;                            /*!<TIM Control Register 2                         offset: 0x04*/
    __IO uint32_t SMCR;                           /*!<TIM Slave Mode Control Register                offset: 0x08*/
    __IO uint32_t DIER;                           /*!<TIM DMA/Interrupt Enable Register (DMA is only suitable for the chip with built in DMA) offset: 0x0C*/
    __IO uint32_t SR;                             /*!<TIM Status Register                            offset: 0x10*/
    __IO uint32_t EGR;                            /*!<TIM Status Register                            offset: 0x14*/
    __IO uint32_t CCMR1;                          /*!<TIM Capture/Compare Mode Register 1            offset: 0x18*/
    __IO uint32_t CCMR2;                          /*!<TIM Capture/Compare Mode Register 2            offset: 0x1C*/
    __IO uint32_t CCER;                           /*!<TIM Capture/Compare Enable Register            offset: 0x20*/
    __IO uint32_t CNT;                            /*!<TIM Counter                                    offset: 0x24*/
    __IO uint32_t PSC;                            /*!<TIM Prescaler                                  offset: 0x28*/
    __IO uint32_t ARR;                            /*!<TIM Auto Reload Register                       offset: 0x2C*/
    __IO uint32_t RESERVED0x030[1];               /*!<                                               offset: 0x30*/
    __IO uint32_t CCR1;                           /*!<TIM Capture/Compare Register 1                 offset: 0x34*/
    __IO uint32_t CCR2;                           /*!<TIM Capture/Compare Register 2                 offset: 0x38*/
    __IO uint32_t CCR3;                           /*!<TIM Capture/Compare Register 3                 offset: 0x3C*/
    __IO uint32_t CCR4;                           /*!<TIM Capture/Compare Register 4                 offset: 0x40*/
    __IO uint32_t BDTR;                           /*!<TIM Break And Dead-Time Register               offset: 0x44*/
    __IO uint32_t DCR;                            /*!<TIM DMA Control Register (only suitable for the chip with built in DMA) offset: 0x48*/
    __IO uint32_t DMAR;                           /*!<TIM DMA Address Register Of Continuous Mode (only suitable for the chip with built in DMA) offset: 0x4C*/
    __IO uint32_t OR;                             /*!<TIM Input Option Register                      offset: 0x50*/
    __IO uint32_t RESERVED0x054[8];               /*!<                                               offset: 0x54~0x70*/
    __IO uint32_t BKINF;                          /*!<TIM Break Input Filter Register                offset: 0x74*/
} TIM_TypeDef;

/**
  * @brief TIM type pointer Definition
  */
#define TIM16                                     ((TIM_TypeDef *)TIM16_BASE)
#define TIM17                                     ((TIM_TypeDef *)TIM17_BASE)
#define TIM3                                      ((TIM_TypeDef *)TIM3_BASE)
#define TIM4                                      ((TIM_TypeDef *)TIM4_BASE)

/**
  * @brief TIM_CR1 Register Bit Definition
  */
#define  TIM_CR1_CEN_Pos                          (0)
#define  TIM_CR1_CEN_Msk                          (0x01U << TIM_CR1_CEN_Pos)                        /*!<Counter enable*/
#define  TIM_CR1_UDIS_Pos                         (1)
#define  TIM_CR1_UDIS_Msk                         (0x01U << TIM_CR1_UDIS_Pos)                       /*!<Update disable*/
#define  TIM_CR1_URS_Pos                          (2)
#define  TIM_CR1_URS_Msk                          (0x01U << TIM_CR1_URS_Pos)                        /*!<Update request source*/
#define  TIM_CR1_OPM_Pos                          (3)
#define  TIM_CR1_OPM_Msk                          (0x01U << TIM_CR1_OPM_Pos)                        /*!<one-pulse mode*/
#define  TIM_CR1_DIR_Pos                          (4)
#define  TIM_CR1_DIR_Msk                          (0x01U << TIM_CR1_DIR_Pos)                        /*!<Count direction*/
#define  TIM_CR1_CMS_Pos                          (5)
#define  TIM_CR1_CMS_Msk                          (0x03U << TIM_CR1_CMS_Pos)                        /*!<Center alignment mode selection*/
#define  TIM_CR1_ARPE_Pos                         (7)
#define  TIM_CR1_ARPE_Msk                         (0x01U << TIM_CR1_ARPE_Pos)                       /*!<Auto reload preload enable*/
#define  TIM_CR1_APRE_Pos                         (7)
#define  TIM_CR1_APRE_Msk                         (0x01U << TIM_CR1_APRE_Pos)                       /*!<Auto reload preload enable*/
#define  TIM_CR1_CKD_Pos                          (8)
#define  TIM_CR1_CKD_Msk                          (0x03U << TIM_CR1_CKD_Pos)                        /*!<Clock division*/

/**
  * @brief TIM_CR2 Register Bit Definition
  */
#define  TIM_CR2_CCPC_Pos                         (0)
#define  TIM_CR2_CCPC_Msk                         (0x01U << TIM_CR2_CCPC_Pos)                       /*!<Capture/compare preloaded control bit*/
#define  TIM_CR2_CCUS_Pos                         (2)
#define  TIM_CR2_CCUS_Msk                         (0x01U << TIM_CR2_CCUS_Pos)                       /*!<Capture/compare control update selection*/
#define  TIM_CR2_CCDS_Pos                         (3)
#define  TIM_CR2_CCDS_Msk                         (0x01U << TIM_CR2_CCDS_Pos)                       /*!<DMA request source selection*/
#define  TIM_CR2_MMS_Pos                          (4)
#define  TIM_CR2_MMS_Msk                          (0x07U << TIM_CR2_MMS_Pos)                        /*!<Master mode selection*/
#define  TIM_CR2_TI1S_Pos                         (7)
#define  TIM_CR2_TI1S_Msk                         (0x01U << TIM_CR2_TI1S_Pos)                       /*!<TI1 selection*/
#define  TIM_CR2_OIS1_Pos                         (8)
#define  TIM_CR2_OIS1_Msk                         (0x01U << TIM_CR2_OIS1_Pos)                       /*!<(Output idle state 1) (OC1 output)*/
#define  TIM_CR2_OIS1N_Pos                        (9)
#define  TIM_CR2_OIS1N_Msk                        (0x01U << TIM_CR2_OIS1N_Pos)                      /*!<(Output idle state 1) (OC1N output)*/

/**
  * @brief TIM_SMCR Register Bit Definition
  */
#define  TIM_SMCR_SMS_Pos                         (0)
#define  TIM_SMCR_SMS_Msk                         (0x07U << TIM_SMCR_SMS_Pos)                       /*!<Slave mode selection*/
#define  TIM_SMCR_OCCS_Pos                        (3)
#define  TIM_SMCR_OCCS_Msk                        (0x01U << TIM_SMCR_OCCS_Pos)                      /*!<Timer compare output signal(OCxREF) clear selection*/
#define  TIM_SMCR_TS_Pos                          (4)
#define  TIM_SMCR_TS_Msk                          (0x07U << TIM_SMCR_TS_Pos)                        /*!<Trigger selection*/
#define  TIM_SMCR_MSM_Pos                         (7)
#define  TIM_SMCR_MSM_Msk                         (0x01U << TIM_SMCR_MSM_Pos)                       /*!<Master/slave mode*/
#define  TIM_SMCR_ETF_Pos                         (8)
#define  TIM_SMCR_ETF_Msk                         (0x0FU << TIM_SMCR_ETF_Pos)                       /*!<External trigger filter*/
#define  TIM_SMCR_ETPS_Pos                        (12)
#define  TIM_SMCR_ETPS_Msk                        (0x03U << TIM_SMCR_ETPS_Pos)                      /*!<External trigger prescaler*/
#define  TIM_SMCR_ECE_Pos                         (14)
#define  TIM_SMCR_ECE_Msk                         (0x01U << TIM_SMCR_ECE_Pos)                       /*!<External clock enable*/
#define  TIM_SMCR_ETP_Pos                         (15)
#define  TIM_SMCR_ETP_Msk                         (0x01U << TIM_SMCR_ETP_Pos)                       /*!<External trigger polarity*/

/**
  * @brief TIM_DIER Register Bit Definition
  */
#define  TIM_DIER_UIE_Pos                         (0)
#define  TIM_DIER_UIE_Msk                         (0x01U << TIM_DIER_UIE_Pos)                       /*!<Enable update interrupt*/
#define  TIM_DIER_CC1IE_Pos                       (1)
#define  TIM_DIER_CC1IE_Msk                       (0x01U << TIM_DIER_CC1IE_Pos)                     /*!<Enable capture/compare 1 interrupt*/
#define  TIM_DIER_CC2IE_Pos                       (2)
#define  TIM_DIER_CC2IE_Msk                       (0x01U << TIM_DIER_CC2IE_Pos)                     /*!<Enable capture/compare 2 interrupt*/
#define  TIM_DIER_CC3IE_Pos                       (3)
#define  TIM_DIER_CC3IE_Msk                       (0x01U << TIM_DIER_CC3IE_Pos)                     /*!<Enable capture/compare 3 interrupt*/
#define  TIM_DIER_CC4IE_Pos                       (4)
#define  TIM_DIER_CC4IE_Msk                       (0x01U << TIM_DIER_CC4IE_Pos)                     /*!<Enable capture/compare 4 interrupt*/
#define  TIM_DIER_COMIE_Pos                       (5)
#define  TIM_DIER_COMIE_Msk                       (0x01U << TIM_DIER_COMIE_Pos)                     /*!<Enable COM interrupt*/
#define  TIM_DIER_TIE_Pos                         (6)
#define  TIM_DIER_TIE_Msk                         (0x01U << TIM_DIER_TIE_Pos)                       /*!<Trigger interrupt enable*/
#define  TIM_DIER_BIE_Pos                         (7)
#define  TIM_DIER_BIE_Msk                         (0x01U << TIM_DIER_BIE_Pos)                       /*!<Break interrupt enable*/
#define  TIM_DIER_UDE_Pos                         (8)
#define  TIM_DIER_UDE_Msk                         (0x01U << TIM_DIER_UDE_Pos)                       /*!<Update DMA request enable*/
#define  TIM_DIER_CC1DE_Pos                       (9)
#define  TIM_DIER_CC1DE_Msk                       (0x01U << TIM_DIER_CC1DE_Pos)                     /*!<Capture/compare 1 DMA request enable*/
#define  TIM_DIER_CC2DE_Pos                       (10)
#define  TIM_DIER_CC2DE_Msk                       (0x01U << TIM_DIER_CC2DE_Pos)                     /*!<Capture/Compare 2 DMA request enable*/
#define  TIM_DIER_CC3DE_Pos                       (11)
#define  TIM_DIER_CC3DE_Msk                       (0x01U << TIM_DIER_CC3DE_Pos)                     /*!<Capture/compare 3 DMA request enable*/
#define  TIM_DIER_CC4DE_Pos                       (12)
#define  TIM_DIER_CC4DE_Msk                       (0x01U << TIM_DIER_CC4DE_Pos)                     /*!<Capture/compare 4 DMA request enable*/
#define  TIM_DIER_TDE_Pos                         (14)
#define  TIM_DIER_TDE_Msk                         (0x01U << TIM_DIER_TDE_Pos)                       /*!<Trigger DMA request enable*/

/**
  * @brief TIM_SR Register Bit Definition
  */
#define  TIM_SR_UIF_Pos                           (0)
#define  TIM_SR_UIF_Msk                           (0x01U << TIM_SR_UIF_Pos)                         /*!<Update interrupt flag*/
#define  TIM_SR_CC1IF_Pos                         (1)
#define  TIM_SR_CC1IF_Msk                         (0x01U << TIM_SR_CC1IF_Pos)                       /*!<Capture/compare 1 interrupt flag*/
#define  TIM_SR_CC2IF_Pos                         (2)
#define  TIM_SR_CC2IF_Msk                         (0x01U << TIM_SR_CC2IF_Pos)                       /*!<Capture/compare 2 interrupt flag*/
#define  TIM_SR_CC3IF_Pos                         (3)
#define  TIM_SR_CC3IF_Msk                         (0x01U << TIM_SR_CC3IF_Pos)                       /*!<Capture/compare 3 interrupt flag*/
#define  TIM_SR_CC4IF_Pos                         (4)
#define  TIM_SR_CC4IF_Msk                         (0x01U << TIM_SR_CC4IF_Pos)                       /*!<Capture/compare 4 interrupt flag*/
#define  TIM_SR_COMIF_Pos                         (5)
#define  TIM_SR_COMIF_Msk                         (0x01U << TIM_SR_COMIF_Pos)                       /*!<COM interrupt flag*/
#define  TIM_SR_TIF_Pos                           (6)
#define  TIM_SR_TIF_Msk                           (0x01U << TIM_SR_TIF_Pos)                         /*!<Trigger interrupt flag*/
#define  TIM_SR_BIF_Pos                           (7)
#define  TIM_SR_BIF_Msk                           (0x01U << TIM_SR_BIF_Pos)                         /*!<Break interrupt flag*/
#define  TIM_SR_CC1OF_Pos                         (9)
#define  TIM_SR_CC1OF_Msk                         (0x01U << TIM_SR_CC1OF_Pos)                       /*!<Capture/compare 1 over capture flag*/
#define  TIM_SR_CC2OF_Pos                         (10)
#define  TIM_SR_CC2OF_Msk                         (0x01U << TIM_SR_CC2OF_Pos)                       /*!<Capture/compare 2 over capture flag*/
#define  TIM_SR_CC3OF_Pos                         (11)
#define  TIM_SR_CC3OF_Msk                         (0x01U << TIM_SR_CC3OF_Pos)                       /*!<Capture/compare 3 over capture flag*/
#define  TIM_SR_CC4OF_Pos                         (12)
#define  TIM_SR_CC4OF_Msk                         (0x01U << TIM_SR_CC4OF_Pos)                       /*!<Capture/compare 4 over capture flag*/

/**
  * @brief TIM_EGR Register Bit Definition
  */
#define  TIM_EGR_UG_Pos                           (0)
#define  TIM_EGR_UG_Msk                           (0x01U << TIM_EGR_UG_Pos)                         /*!<Update event generation*/
#define  TIM_EGR_CC1G_Pos                         (1)
#define  TIM_EGR_CC1G_Msk                         (0x01U << TIM_EGR_CC1G_Pos)                       /*!<Capture/compare 1 generation*/
#define  TIM_EGR_CC2G_Pos                         (2)
#define  TIM_EGR_CC2G_Msk                         (0x01U << TIM_EGR_CC2G_Pos)                       /*!<Capture/compare 2 generation*/
#define  TIM_EGR_CC3G_Pos                         (3)
#define  TIM_EGR_CC3G_Msk                         (0x01U << TIM_EGR_CC3G_Pos)                       /*!<Capture/compare 3 generation*/
#define  TIM_EGR_CC4G_Pos                         (4)
#define  TIM_EGR_CC4G_Msk                         (0x01U << TIM_EGR_CC4G_Pos)                       /*!<Capture/compare 4 generation*/
#define  TIM_EGR_COMG_Pos                         (5)
#define  TIM_EGR_COMG_Msk                         (0x01U << TIM_EGR_COMG_Pos)                       /*!<Capture/compare control update generation*/
#define  TIM_EGR_TG_Pos                           (6)
#define  TIM_EGR_TG_Msk                           (0x01U << TIM_EGR_TG_Pos)                         /*!<Trigger generation*/
#define  TIM_EGR_BG_Pos                           (7)
#define  TIM_EGR_BG_Msk                           (0x01U << TIM_EGR_BG_Pos)                         /*!<Break generation*/

/**
  * @brief TIM_CCMR1 Register Bit Definition
  */

/* CCMR1_OUTPUT */
#define  TIM_CCMR1_CC1S_Pos                       (0)
#define  TIM_CCMR1_CC1S_Msk                       (0x03U << TIM_CCMR1_CC1S_Pos)                     /*!<Channel 1 capture/compare selection*/
#define  TIM_CCMR1_OC1FE_Pos                      (2)
#define  TIM_CCMR1_OC1FE_Msk                      (0x01U << TIM_CCMR1_OC1FE_Pos)                    /*!<Channel 1 output compare quick enable*/

/* CCMR1_INPUT */
#define  TIM_CCMR1_IC1PSC_Pos                     (2)
#define  TIM_CCMR1_IC1PSC_Msk                     (0x03U << TIM_CCMR1_IC1PSC_Pos)                   /*!<Channel 1 input/capture prescaler*/

/* CCMR1_OUTPUT */
#define  TIM_CCMR1_OC1PE_Pos                      (3)
#define  TIM_CCMR1_OC1PE_Msk                      (0x01U << TIM_CCMR1_OC1PE_Pos)                    /*!<Channel 1 output compare preload enable*/
#define  TIM_CCMR1_OC1M_Pos                       (4)
#define  TIM_CCMR1_OC1M_Msk                       (0x07U << TIM_CCMR1_OC1M_Pos)                     /*!<Channel 1 output compare mode*/

/* CCMR1_INPUT */
#define  TIM_CCMR1_IC1F_Pos                       (4)
#define  TIM_CCMR1_IC1F_Msk                       (0x0FU << TIM_CCMR1_IC1F_Pos)                     /*!<Channel 1 input capture filter*/

/* CCMR1_OUTPUT */
#define  TIM_CCMR1_OC1CE_Pos                      (7)
#define  TIM_CCMR1_OC1CE_Msk                      (0x01U << TIM_CCMR1_OC1CE_Pos)                    /*!<Channel 1 capture/compare clear enable*/
#define  TIM_CCMR1_CC2S_Pos                       (8)
#define  TIM_CCMR1_CC2S_Msk                       (0x03U << TIM_CCMR1_CC2S_Pos)                     /*!<Channel 2 capture/compare 2 selection*/
#define  TIM_CCMR1_OC2FE_Pos                      (10)
#define  TIM_CCMR1_OC2FE_Msk                      (0x01U << TIM_CCMR1_OC2FE_Pos)                    /*!<Channel 2 output and compare quick enable*/

/* CCMR1_INPUT */
#define  TIM_CCMR1_IC2PSC_Pos                     (10)
#define  TIM_CCMR1_IC2PSC_Msk                     (0x03U << TIM_CCMR1_IC2PSC_Pos)                   /*!<Input/capture 2 prescaler*/

/* CCMR1_OUTPUT */
#define  TIM_CCMR1_OC2PE_Pos                      (11)
#define  TIM_CCMR1_OC2PE_Msk                      (0x01U << TIM_CCMR1_OC2PE_Pos)                    /*!<Channel 2 output and compare preload enable*/
#define  TIM_CCMR1_OC2M_Pos                       (12)
#define  TIM_CCMR1_OC2M_Msk                       (0x07U << TIM_CCMR1_OC2M_Pos)                     /*!<Channel 2 output and compare mode*/

/* CCMR1_INPUT */
#define  TIM_CCMR1_IC2F_Pos                       (12)
#define  TIM_CCMR1_IC2F_Msk                       (0x0FU << TIM_CCMR1_IC2F_Pos)                     /*!<Input capture 2 filter*/

/* CCMR1_OUTPUT */
#define  TIM_CCMR1_OC2CE_Pos                      (15)
#define  TIM_CCMR1_OC2CE_Msk                      (0x01U << TIM_CCMR1_OC2CE_Pos)                    /*!<Channel 2 output and compare clear enable*/

/**
  * @brief TIM_CCMR2 Register Bit Definition
  */

/* CCMR2_OUTPUT */
#define  TIM_CCMR2_CC3S_Pos                       (0)
#define  TIM_CCMR2_CC3S_Msk                       (0x03U << TIM_CCMR2_CC3S_Pos)                     /*!<Channel 3 capture/compare selection*/
#define  TIM_CCMR2_OC3FE_Pos                      (2)
#define  TIM_CCMR2_OC3FE_Msk                      (0x01U << TIM_CCMR2_OC3FE_Pos)                    /*!<Channel 3 output compare quick enable*/

/* CCMR2_INPUT */
#define  TIM_CCMR2_IC3PSC_Pos                     (2)
#define  TIM_CCMR2_IC3PSC_Msk                     (0x03U << TIM_CCMR2_IC3PSC_Pos)                   /*!<Channel 3 input/capture prescaler*/

/* CCMR2_OUTPUT */
#define  TIM_CCMR2_OC3PE_Pos                      (3)
#define  TIM_CCMR2_OC3PE_Msk                      (0x01U << TIM_CCMR2_OC3PE_Pos)                    /*!<Channel 3 output compare preload enable*/
#define  TIM_CCMR2_OC3M_Pos                       (4)
#define  TIM_CCMR2_OC3M_Msk                       (0x07U << TIM_CCMR2_OC3M_Pos)                     /*!<Channel 3 output compare mode*/

/* CCMR2_INPUT */
#define  TIM_CCMR2_IC3F_Pos                       (4)
#define  TIM_CCMR2_IC3F_Msk                       (0x0FU << TIM_CCMR2_IC3F_Pos)                     /*!<Channel 3 input capture filter*/

/* CCMR2_OUTPUT */
#define  TIM_CCMR2_OC3CE_Pos                      (7)
#define  TIM_CCMR2_OC3CE_Msk                      (0x01U << TIM_CCMR2_OC3CE_Pos)                    /*!<Channel 3 output compare clear enable*/
#define  TIM_CCMR2_CC4S_Pos                       (8)
#define  TIM_CCMR2_CC4S_Msk                       (0x03U << TIM_CCMR2_CC4S_Pos)                     /*!<Channel 4 capture/compare selection*/
#define  TIM_CCMR2_OC4FE_Pos                      (10)
#define  TIM_CCMR2_OC4FE_Msk                      (0x01U << TIM_CCMR2_OC4FE_Pos)                    /*!<Refer to OC3PE description*/

/* CCMR2_INPUT */
#define  TIM_CCMR2_IC4PSC_Pos                     (10)
#define  TIM_CCMR2_IC4PSC_Msk                     (0x03U << TIM_CCMR2_IC4PSC_Pos)                   /*!<Input/capture 4 prescaler*/

/* CCMR2_OUTPUT */
#define  TIM_CCMR2_OC4PE_Pos                      (11)
#define  TIM_CCMR2_OC4PE_Msk                      (0x01U << TIM_CCMR2_OC4PE_Pos)                    /*!<Channel 4 output compare preload enable*/
#define  TIM_CCMR2_OC4M_Pos                       (12)
#define  TIM_CCMR2_OC4M_Msk                       (0x07U << TIM_CCMR2_OC4M_Pos)                     /*!<Channel 4 output compare mode*/

/* CCMR2_INPUT */
#define  TIM_CCMR2_IC4F_Pos                       (12)
#define  TIM_CCMR2_IC4F_Msk                       (0x0FU << TIM_CCMR2_IC4F_Pos)                     /*!<Input capture 4 filter*/

/* CCMR2_OUTPUT */
#define  TIM_CCMR2_OC4CE_Pos                      (15)
#define  TIM_CCMR2_OC4CE_Msk                      (0x01U << TIM_CCMR2_OC4CE_Pos)                    /*!<Channel 4 output compare clear enable*/

/**
  * @brief TIM_CCER Register Bit Definition
  */
#define  TIM_CCER_CC1E_Pos                        (0)
#define  TIM_CCER_CC1E_Msk                        (0x01U << TIM_CCER_CC1E_Pos)                      /*!<Channel 1 input/capture output enable*/
#define  TIM_CCER_CC1P_Pos                        (1)
#define  TIM_CCER_CC1P_Msk                        (0x01U << TIM_CCER_CC1P_Pos)                      /*!<Channel 1 input/capture output polarity*/
#define  TIM_CCER_CC1NE_Pos                       (2)
#define  TIM_CCER_CC1NE_Msk                       (0x01U << TIM_CCER_CC1NE_Pos)                     /*!<Channel 1 input/capture complementary output enable*/
#define  TIM_CCER_CC1NP_Pos                       (3)
#define  TIM_CCER_CC1NP_Msk                       (0x01U << TIM_CCER_CC1NP_Pos)                     /*!<Channel 1 input/capture complementary output polarity*/
#define  TIM_CCER_CC2E_Pos                        (4)
#define  TIM_CCER_CC2E_Msk                        (0x01U << TIM_CCER_CC2E_Pos)                      /*!<Channel 2 input/capture output enable*/
#define  TIM_CCER_CC2P_Pos                        (5)
#define  TIM_CCER_CC2P_Msk                        (0x01U << TIM_CCER_CC2P_Pos)                      /*!<Channel 2 input capture output polarity*/
#define  TIM_CCER_CC2NP_Pos                       (7)
#define  TIM_CCER_CC2NP_Msk                       (0x01U << TIM_CCER_CC2NP_Pos)                     /*!<Channel 2 input/capture complementary output polarity*/
#define  TIM_CCER_CC3E_Pos                        (8)
#define  TIM_CCER_CC3E_Msk                        (0x01U << TIM_CCER_CC3E_Pos)                      /*!<Channel 3 input/capture output enable*/
#define  TIM_CCER_CC3P_Pos                        (9)
#define  TIM_CCER_CC3P_Msk                        (0x01U << TIM_CCER_CC3P_Pos)                      /*!<Channel 3 input capture output polarity*/
#define  TIM_CCER_CC3NP_Pos                       (11)
#define  TIM_CCER_CC3NP_Msk                       (0x01U << TIM_CCER_CC3NP_Pos)                     /*!<Channel 3 input/capture complementary output polarity*/
#define  TIM_CCER_CC4E_Pos                        (12)
#define  TIM_CCER_CC4E_Msk                        (0x01U << TIM_CCER_CC4E_Pos)                      /*!<Channel 4 capture/compare enable*/
#define  TIM_CCER_CC4P_Pos                        (13)
#define  TIM_CCER_CC4P_Msk                        (0x01U << TIM_CCER_CC4P_Pos)                      /*!<Channel 4 capture/compare output polarity*/
#define  TIM_CCER_CC4NP_Pos                       (15)
#define  TIM_CCER_CC4NP_Msk                       (0x01U << TIM_CCER_CC4NP_Pos)                     /*!<Channel 4 input/capture complementary output polarity*/

/**
  * @brief TIM_CNT Register Bit Definition
  */
#define  TIM_CNT_CNT_Pos                          (0)
#define  TIM_CNT_CNT_Msk                          (0xFFFFU << TIM_CNT_CNT_Pos)                      /*!<Counter value*/

/**
  * @brief TIM_PSC Register Bit Definition
  */
#define  TIM_PSC_PSC_Pos                          (0)
#define  TIM_PSC_PSC_Msk                          (0xFFFFU << TIM_PSC_PSC_Pos)                      /*!<Prescaler value*/

/**
  * @brief TIM_ARR Register Bit Definition
  */
#define  TIM_ARR_ARR_Pos                          (0)
#define  TIM_ARR_ARR_Msk                          (0xFFFFU << TIM_ARR_ARR_Pos)                      /*!<Auto reload value*/

/**
  * @brief TIM_CCR1 Register Bit Definition
  */
#define  TIM_CCR1_CCR1_Pos                        (0)
#define  TIM_CCR1_CCR1_Msk                        (0xFFFFU << TIM_CCR1_CCR1_Pos)                    /*!<Channel 1 capture/compare value*/

/**
  * @brief TIM_CCR2 Register Bit Definition
  */
#define  TIM_CCR2_CCR2_Pos                        (0)
#define  TIM_CCR2_CCR2_Msk                        (0xFFFFU << TIM_CCR2_CCR2_Pos)                    /*!<Channel 2 capture/compare value*/

/**
  * @brief TIM_CCR3 Register Bit Definition
  */
#define  TIM_CCR3_CCR3_Pos                        (0)
#define  TIM_CCR3_CCR3_Msk                        (0xFFFFU << TIM_CCR3_CCR3_Pos)                    /*!<Channel 3 capture/compare value*/

/**
  * @brief TIM_CCR4 Register Bit Definition
  */
#define  TIM_CCR4_CCR4_Pos                        (0)
#define  TIM_CCR4_CCR4_Msk                        (0xFFFFU << TIM_CCR4_CCR4_Pos)                    /*!<Channel 4 capture/compare value*/

/**
  * @brief TIM_BDTR Register Bit Definition
  */
#define  TIM_BDTR_DTG_Pos                         (0)
#define  TIM_BDTR_DTG_Msk                         (0xFFU << TIM_BDTR_DTG_Pos)                       /*!<Dead-time generator setup adjustment*/
#define  TIM_BDTR_LOCK_Pos                        (8)
#define  TIM_BDTR_LOCK_Msk                        (0x03U << TIM_BDTR_LOCK_Pos)                      /*!<Lock configuration*/
#define  TIM_BDTR_OSSI_Pos                        (10)
#define  TIM_BDTR_OSSI_Msk                        (0x01U << TIM_BDTR_OSSI_Pos)                      /*!<Off state selection in the idle mode*/
#define  TIM_BDTR_OSSR_Pos                        (11)
#define  TIM_BDTR_OSSR_Msk                        (0x01U << TIM_BDTR_OSSR_Pos)                      /*!<Off state selection in the run mode*/
#define  TIM_BDTR_BKE_Pos                         (12)
#define  TIM_BDTR_BKE_Msk                         (0x01U << TIM_BDTR_BKE_Pos)                       /*!<Break function enable*/
#define  TIM_BDTR_BKP_Pos                         (13)
#define  TIM_BDTR_BKP_Msk                         (0x01U << TIM_BDTR_BKP_Pos)                       /*!<Break input polarity*/
#define  TIM_BDTR_AOE_Pos                         (14)
#define  TIM_BDTR_AOE_Msk                         (0x01U << TIM_BDTR_AOE_Pos)                       /*!<Auto output enable*/
#define  TIM_BDTR_MOE_Pos                         (15)
#define  TIM_BDTR_MOE_Msk                         (0x01U << TIM_BDTR_MOE_Pos)                       /*!<Main output enable*/

/**
  * @brief TIM_DCR Register Bit Definition
  */
#define  TIM_DCR_DBA_Pos                          (0)
#define  TIM_DCR_DBA_Msk                          (0x1FU << TIM_DCR_DBA_Pos)                        /*!<DMA base address*/
#define  TIM_DCR_DBL_Pos                          (8)
#define  TIM_DCR_DBL_Msk                          (0x1FU << TIM_DCR_DBL_Pos)                        /*!<DMA continuous transmission length*/

/**
  * @brief TIM_DMAR Register Bit Definition
  */
#define  TIM_DMAR_DMAB_Pos                        (0)
#define  TIM_DMAR_DMAB_Msk                        (0xFFFFU << TIM_DMAR_DMAB_Pos)                    /*!<DMA register for burst accesses*/

/**
  * @brief TIM_OR Register Bit Definition
  */
#define  TIM_OR_ETR_RMP_Pos                       (0)
#define  TIM_OR_ETR_RMP_Msk                       (0x03U << TIM_OR_ETR_RMP_Pos)                     /*!<ETR remap*/
#define  TIM_OR_TI4_RMP_Pos                       (6)                                               
#define  TIM_OR_TI4_RMP_Msk                       (0x03U << TIM_OR_TI4_RMP_Pos)                     /*!<TI4 remap*/
/**
  * @brief TIM_BKINF Register Bit Definition
  */
#define  TIM_BKINF_BKINFE_Pos                     (0)
#define  TIM_BKINF_BKINFE_Msk                     (0x01U << TIM_BKINF_BKINFE_Pos)                   /*!<Break input filter enable*/
#define  TIM_BKINF_BKINF_Pos                      (1)
#define  TIM_BKINF_BKINF_Msk                      (0x0FU << TIM_BKINF_BKINF_Pos)                    /*!<Break input filter*/
#define  TIM_BKINF_IOBKIN_SEL_Pos                 (6)
#define  TIM_BKINF_IOBKIN_SEL_Msk                 (0x01U << TIM_BKINF_IOBKIN_SEL_Pos)               /*!<IO break input channel selects*/
#define  TIM_BKINF_COMPBKIN_SEL_Pos               (7)
#define  TIM_BKINF_COMPBKIN_SEL_Msk               (0x01U << TIM_BKINF_COMPBKIN_SEL_Pos)             /*!<COMP break input channel selects*/


#endif

