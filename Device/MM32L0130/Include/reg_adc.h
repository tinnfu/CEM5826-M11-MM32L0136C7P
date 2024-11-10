/***********************************************************************************************************************
    @file     reg_adc.h
    @author   VV TEAM
    @brief    This flie contains all the ADC's register and its field definition.
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

#ifndef __REG_ADC_H
#define __REG_ADC_H


/* Files includes ----------------------------------------------------------------------------------------------------*/
#include <core_cm0plus.h>



/**
  * @brief ADC Base Address Definition
  */
#define  ADC_BASE                                  0x40012400                                       /*!<Base Address: 0x40012400*/

/**
  * @brief ADC Register Structure Definition
  */
typedef struct
{
    __IO uint32_t ADDATA;                         /*!<ADC Data Register                              offset: 0x00*/
    __IO uint32_t ADCFG;                          /*!<ADC Configuration Register                     offset: 0x04*/
    __IO uint32_t ADCR;                           /*!<ADC Control Register                           offset: 0x08*/
    __IO uint32_t ADCHS;                          /*!<ADC Channel Selection Register                 offset: 0x0C*/
    __IO uint32_t ADCMPR;                         /*!<ADC Analog Watchdog Compare Register           offset: 0x10*/
    __IO uint32_t ADSTA;                          /*!<ADC Status Register                            offset: 0x14*/
    __IO uint32_t ADDR0;                          /*!<ADC Channel Data Register                      offset: 0x18*/
    __IO uint32_t ADDR1;                          /*!<ADC Channel Data Register                      offset: 0x1C*/
    __IO uint32_t ADDR2;                          /*!<ADC Channel Data Register                      offset: 0x20*/
    __IO uint32_t ADDR3;                          /*!<ADC Channel Data Register                      offset: 0x24*/
    __IO uint32_t ADDR4;                          /*!<ADC Channel Data Register                      offset: 0x28*/
    __IO uint32_t ADDR5;                          /*!<ADC Channel Data Register                      offset: 0x2C*/
    __IO uint32_t ADDR6;                          /*!<ADC Channel Data Register                      offset: 0x30*/
    __IO uint32_t ADDR7;                          /*!<ADC Channel Data Register                      offset: 0x34*/
    __IO uint32_t ADDR8;                          /*!<ADC Channel Data Register                      offset: 0x38*/
    __IO uint32_t ADDR9;                          /*!<ADC Channel Data Register                      offset: 0x3C*/
    __IO uint32_t ADDR10;                         /*!<ADC Channel Data Register                      offset: 0x40*/
    __IO uint32_t ADDR11;                         /*!<ADC Channel Data Register                      offset: 0x44*/
    __IO uint32_t ADDR12;                         /*!<ADC Channel Data Register                      offset: 0x48*/
    __IO uint32_t ADDR13;                         /*!<ADC Channel Data Register                      offset: 0x4C*/
    __IO uint32_t ADDR14;                         /*!<ADC Channel Data Register                      offset: 0x50*/
    __IO uint32_t ADDR15;                         /*!<ADC Channel Data Register                      offset: 0x54*/
    __IO uint32_t ADSTA_EXT;                      /*!<ADC Extended State Register                    offset: 0x58*/
    __IO uint32_t CHANY0;                         /*!<ADC Any Channel Selection Register 0           offset: 0x5C*/
    __IO uint32_t CHANY1;                         /*!<ADC Any Channel Selection Register 1           offset: 0x60*/
    __IO uint32_t ANY_CFG;                        /*!<ADC Any Channel Configuration Register         offset: 0x64*/
    __IO uint32_t ANY_CR;                         /*!<ADC Any Channel Control Register               offset: 0x68*/
    __IO uint32_t RESERVED0x06C[1];               /*!<                                               offset: 0x6c*/
    __IO uint32_t SMPR1;                          /*!<ADC Sample Configuration Register 1            offset: 0x70*/
    __IO uint32_t SMPR2;                          /*!<ADC Sample Configuration Register 2            offset: 0x74*/
    __IO uint32_t RESERVED0x078[1];               /*!<                                               offset: 0x78*/
    __IO uint32_t JOFR0;                          /*!<ADC Injected Channel Data Offset Register      offset: 0x7C*/
    __IO uint32_t JOFR1;                          /*!<ADC Injected Channel Data Offset Register      offset: 0x80*/
    __IO uint32_t JOFR2;                          /*!<ADC Injected Channel Data Offset Register      offset: 0x84*/
    __IO uint32_t JOFR3;                          /*!<ADC Injected Channel Data Offset Register      offset: 0x88*/
    __IO uint32_t JSQR;                           /*!<ADC Injected Sequence Register                 offset: 0x8C*/
    __IO uint32_t JADDATA;                        /*!<ADC Injected Data Register                     offset: 0x90*/
    __IO uint32_t RESERVED0x094[7];               /*!<                                               offset: 0x94~0xac*/
    __IO uint32_t JDR0;                           /*!<ADC Injected Channel Data Register             offset: 0xB0*/
    __IO uint32_t JDR1;                           /*!<ADC Injected Channel Data Register             offset: 0xB4*/
    __IO uint32_t JDR2;                           /*!<ADC Injected Channel Data Register             offset: 0xB8*/
    __IO uint32_t JDR3;                           /*!<ADC Injected Channel Data Register             offset: 0xBC*/
} ADC_TypeDef;

/**
  * @brief ADC type pointer Definition
  */
#define ADC                                       ((ADC_TypeDef *)ADC_BASE)

/**
  * @brief ADC_ADDATA Register Bit Definition
  */
#define  ADC_ADDATA_DATA_Pos                      (0)
#define  ADC_ADDATA_DATA_Msk                      (0xFFFFU << ADC_ADDATA_DATA_Pos)                  /*!<12-bit A/D conversion result from the current channel (Conversion Data)*/
#define  ADC_ADDATA_CHANNELSEL_Pos                (16)
#define  ADC_ADDATA_CHANNELSEL_Msk                (0x0FU << ADC_ADDATA_CHANNELSEL_Pos)              /*!<4 bits show the channel corresponding to the data in the current data register (Channel Selection)*/
#define  ADC_ADDATA_OVERRUN_Pos                   (20)
#define  ADC_ADDATA_OVERRUN_Msk                   (0x01U << ADC_ADDATA_OVERRUN_Pos)                 /*!<Data overrun flag (read-only)*/
#define  ADC_ADDATA_VALID_Pos                     (21)
#define  ADC_ADDATA_VALID_Msk                     (0x01U << ADC_ADDATA_VALID_Pos)                   /*!<Valid flag for data (read-only)*/

/**
  * @brief ADC_ADCFG Register Bit Definition
  */
#define  ADC_ADCFG_ADEN_Pos                       (0)
#define  ADC_ADCFG_ADEN_Msk                       (0x01U << ADC_ADCFG_ADEN_Pos)                     /*!<A/D conversion enable (ADC enable)*/
#define  ADC_ADCFG_AWDEN_Pos                      (1)
#define  ADC_ADCFG_AWDEN_Msk                      (0x01U << ADC_ADCFG_AWDEN_Pos)                    /*!<Analog watchdog enable on non-injected channels*/
#define  ADC_ADCFG_VTSEN_Pos                      (2)
#define  ADC_ADCFG_VTSEN_Msk                      (0x03U << ADC_ADCFG_VTSEN_Pos)                    /*!<Internal reference voltage and temperature sensor enable (Voltage Sensor and Temperature Sensor Enable)*/
#define  ADC_ADCFG_ADCPREH_Pos                    (4)
#define  ADC_ADCFG_ADCPREH_Msk                    (0x07U << ADC_ADCFG_ADCPREH_Pos)                  /*!<ADC Prescaler High Bits*/
#define  ADC_ADCFG_RSLTCTL_Pos                    (7)
#define  ADC_ADCFG_RSLTCTL_Msk                    (0x07U << ADC_ADCFG_RSLTCTL_Pos)                  /*!<ADC conversion data resolution selection*/
#define  ADC_ADCFG_ADCPREL_Pos                    (14)
#define  ADC_ADCFG_ADCPREL_Msk                    (0x01U << ADC_ADCFG_ADCPREL_Pos)                  /*!<ADC Prescaler Low Bits*/
#define  ADC_ADCFG_JAWDEN_Pos                     (16)
#define  ADC_ADCFG_JAWDEN_Msk                     (0x01U << ADC_ADCFG_JAWDEN_Pos)                   /*!<A/D Analog Watchdog Enable for Injected Channels*/

/**
  * @brief ADC_ADCR Register Bit Definition
  */
#define  ADC_ADCR_EOSIE_Pos                       (0)
#define  ADC_ADCR_EOSIE_Msk                       (0x01U << ADC_ADCR_EOSIE_Pos)                     /*!<Interrupt Enable for End of Sequence on non-injected channels*/
#define  ADC_ADCR_AWDIE_Pos                       (1)
#define  ADC_ADCR_AWDIE_Msk                       (0x01U << ADC_ADCR_AWDIE_Pos)                     /*!<Interrupt Enable of Analog Watchdog*/
#define  ADC_ADCR_TRGEN_Pos                       (2)
#define  ADC_ADCR_TRGEN_Msk                       (0x01U << ADC_ADCR_TRGEN_Pos)                     /*!<External Hardware Trigger Sources Enable*/
#define  ADC_ADCR_DMAEN_Pos                       (3)
#define  ADC_ADCR_DMAEN_Msk                       (0x01U << ADC_ADCR_DMAEN_Pos)                     /*!<Direct Memory Access Enable*/
#define  ADC_ADCR_TRGSELL_Pos                     (4)
#define  ADC_ADCR_TRGSELL_Msk                     (0x07U << ADC_ADCR_TRGSELL_Pos)                   /*!<External Trigger sources Select for Low bitsTRGSEL={TRGSELH,TRGSELL}ADC selects external trigger source TRGSEL:*/
#define  ADC_ADCR_ADST_Pos                        (8)
#define  ADC_ADCR_ADST_Msk                        (0x01U << ADC_ADCR_ADST_Pos)                      /*!<A/D conversion start*/
#define  ADC_ADCR_ADMD_Pos                        (9)
#define  ADC_ADCR_ADMD_Msk                        (0x03U << ADC_ADCR_ADMD_Pos)                      /*!<A/D conversion mode (ADC Mode)*/
#define  ADC_ADCR_ALIGN_Pos                       (11)
#define  ADC_ADCR_ALIGN_Msk                       (0x01U << ADC_ADCR_ALIGN_Pos)                     /*!<Data Alignment style*/
#define  ADC_ADCR_CMPCH_Pos                       (12)
#define  ADC_ADCR_CMPCH_Msk                       (0x0FU << ADC_ADCR_CMPCH_Pos)                     /*!<Compare Channel Selection For Analog Watchdog*/
#define  ADC_ADCR_SCANDIR_Pos                     (16)
#define  ADC_ADCR_SCANDIR_Msk                     (0x01U << ADC_ADCR_SCANDIR_Pos)                   /*!<ADC Channel Scan DirectionOnly valid for normal channel conversion*/
#define  ADC_ADCR_TRGSELH_Pos                     (17)
#define  ADC_ADCR_TRGSELH_Msk                     (0x03U << ADC_ADCR_TRGSELH_Pos)                   /*!<External Trigger Sources Select For High Bits*/
#define  ADC_ADCR_TRGSHIFT_Pos                    (19)
#define  ADC_ADCR_TRGSHIFT_Msk                    (0x07U << ADC_ADCR_TRGSHIFT_Pos)                  /*!<External Trigger Sources Shift For SampleAfter a trigger event is generated, the sampling starts after a delay of N PCLK2 clock cycles (N=1, 2, 3,,,).*/
#define  ADC_ADCR_TRG_EDGE_Pos                    (24)
#define  ADC_ADCR_TRG_EDGE_Msk                    (0x03U << ADC_ADCR_TRG_EDGE_Pos)                  /*!<Trigger Sources Edge Selection*/
#define  ADC_ADCR_EOSMPIE_Pos                     (26)
#define  ADC_ADCR_EOSMPIE_Msk                     (0x01U << ADC_ADCR_EOSMPIE_Pos)                   /*!<Interrupt Enable for End of Sample*/
#define  ADC_ADCR_EOCIE_Pos                       (27)
#define  ADC_ADCR_EOCIE_Msk                       (0x01U << ADC_ADCR_EOCIE_Pos)                     /*!<Interrupt Enable for End of Conversion*/

/**
  * @brief ADC_ADCHS Register Bit Definition
  */
#define  ADC_ADCHS_CHEN0_Pos                      (0)
#define  ADC_ADCHS_CHEN0_Msk                      (0x01U << ADC_ADCHS_CHEN0_Pos)                    /*!<Analog Input Channel 0 Enable*/
#define  ADC_ADCHS_CHEN1_Pos                      (1)
#define  ADC_ADCHS_CHEN1_Msk                      (0x01U << ADC_ADCHS_CHEN1_Pos)                    /*!<Analog Input Channel 1 Enable*/
#define  ADC_ADCHS_CHEN2_Pos                      (2)
#define  ADC_ADCHS_CHEN2_Msk                      (0x01U << ADC_ADCHS_CHEN2_Pos)                    /*!<Analog Input Channel 2 Enable*/
#define  ADC_ADCHS_CHEN3_Pos                      (3)
#define  ADC_ADCHS_CHEN3_Msk                      (0x01U << ADC_ADCHS_CHEN3_Pos)                    /*!<Analog Input Channel 3 Enable*/
#define  ADC_ADCHS_CHEN4_Pos                      (4)
#define  ADC_ADCHS_CHEN4_Msk                      (0x01U << ADC_ADCHS_CHEN4_Pos)                    /*!<Analog Input Channel 4 Enable*/
#define  ADC_ADCHS_CHEN5_Pos                      (5)
#define  ADC_ADCHS_CHEN5_Msk                      (0x01U << ADC_ADCHS_CHEN5_Pos)                    /*!<Analog Input Channel 5 Enable*/
#define  ADC_ADCHS_CHEN6_Pos                      (6)
#define  ADC_ADCHS_CHEN6_Msk                      (0x01U << ADC_ADCHS_CHEN6_Pos)                    /*!<Analog Input Channel 6 Enable*/
#define  ADC_ADCHS_CHEN7_Pos                      (7)
#define  ADC_ADCHS_CHEN7_Msk                      (0x01U << ADC_ADCHS_CHEN7_Pos)                    /*!<Analog Input Channel 7 Enable*/
#define  ADC_ADCHS_CHEN8_Pos                      (8)
#define  ADC_ADCHS_CHEN8_Msk                      (0x01U << ADC_ADCHS_CHEN8_Pos)                    /*!<Analog Input Channel 8 Enable*/
#define  ADC_ADCHS_CHEN9_Pos                      (9)
#define  ADC_ADCHS_CHEN9_Msk                      (0x01U << ADC_ADCHS_CHEN9_Pos)                    /*!<Analog Input Channel 9 Enable*/
#define  ADC_ADCHS_CHEN10_Pos                     (10)
#define  ADC_ADCHS_CHEN10_Msk                     (0x01U << ADC_ADCHS_CHEN10_Pos)                   /*!<Analog Input Channel 10 Enable*/
#define  ADC_ADCHS_CHEN11_Pos                     (11)
#define  ADC_ADCHS_CHEN11_Msk                     (0x01U << ADC_ADCHS_CHEN11_Pos)                   /*!<Analog Input Channel 11 Enable*/
#define  ADC_ADCHS_CHEN12_Pos                     (12)
#define  ADC_ADCHS_CHEN12_Msk                     (0x01U << ADC_ADCHS_CHEN12_Pos)                   /*!<Analog Input Channel 12 Enable*/
#define  ADC_ADCHS_CHEN13_Pos                     (13)
#define  ADC_ADCHS_CHEN13_Msk                     (0x01U << ADC_ADCHS_CHEN13_Pos)                   /*!<Analog Input Channel 13 Enable*/
#define  ADC_ADCHS_CHEN14_Pos                     (14)
#define  ADC_ADCHS_CHEN14_Msk                     (0x01U << ADC_ADCHS_CHEN14_Pos)                   /*!<Analog Input Channel 14 Enable*/
#define  ADC_ADCHS_CHEN15_Pos                     (15)
#define  ADC_ADCHS_CHEN15_Msk                     (0x01U << ADC_ADCHS_CHEN15_Pos)                   /*!<Temperature Sensor or Voltage Sensor Enable*/

/**
  * @brief ADC_ADCMPR Register Bit Definition
  */
#define  ADC_ADCMPR_CMPLDATA_Pos                  (0)
#define  ADC_ADCMPR_CMPLDATA_Msk                  (0x0FFFU << ADC_ADCMPR_CMPLDATA_Pos)              /*!<Compare Low Threshold Data For Analog Watchdog*/
#define  ADC_ADCMPR_CMPHDATA_Pos                  (16)
#define  ADC_ADCMPR_CMPHDATA_Msk                  (0x0FFFU << ADC_ADCMPR_CMPHDATA_Pos)              /*!<Compare High Threshold Data For Analog Watchdog*/

/**
  * @brief ADC_ADSTA Register Bit Definition
  */
#define  ADC_ADSTA_EOSIF_Pos                      (0)
#define  ADC_ADSTA_EOSIF_Msk                      (0x01U << ADC_ADSTA_EOSIF_Pos)                    /*!<1: A/D conversion complete*/
#define  ADC_ADSTA_AWDIF_Pos                      (1)
#define  ADC_ADSTA_AWDIF_Msk                      (0x01U << ADC_ADSTA_AWDIF_Pos)                    /*!<End of Sequential Conversion FlagThis bit is set by hardware at the end of sequential conversion, and cleared by software.*/
#define  ADC_ADSTA_BUSY_Pos                       (2)
#define  ADC_ADSTA_BUSY_Msk                       (0x01U << ADC_ADSTA_BUSY_Pos)                     /*!<Non-Injected Conversion Busy/Idle*/
#define  ADC_ADSTA_CHANNEL_Pos                    (4)
#define  ADC_ADSTA_CHANNEL_Msk                    (0x0FU << ADC_ADSTA_CHANNEL_Pos)                  /*!<Current Convert Channel*/
#define  ADC_ADSTA_VALID_Pos                      (8)
#define  ADC_ADSTA_VALID_Msk                      (0x0FFFU << ADC_ADSTA_VALID_Pos)                  /*!<Valid flag for channel 0 to channel 11 (Valid Flag)*/
#define  ADC_ADSTA_OVERRUN_Pos                    (20)
#define  ADC_ADSTA_OVERRUN_Msk                    (0x0FFFU << ADC_ADSTA_OVERRUN_Pos)                /*!<Data overrun flag for channel 0 to channel 11 (Overrun Flag)*/

/**
  * @brief ADC_ADDR Register Bit Definition
  */
#define  ADC_ADDR_DATA_Pos                        (0)
#define  ADC_ADDR_DATA_Msk                        (0xFFFFU << ADC_ADDR_DATA_Pos)                    /*!<12-bit A/D conversion result from the channel n (Conversion Data)The alignment style is selected via software.*/
#define  ADC_ADDR_OVERRUN_Pos                     (20)
#define  ADC_ADDR_OVERRUN_Msk                     (0x01U << ADC_ADDR_OVERRUN_Pos)                   /*!<Data overrun flag (read-only)*/
#define  ADC_ADDR_VALID_Pos                       (21)
#define  ADC_ADDR_VALID_Msk                       (0x01U << ADC_ADDR_VALID_Pos)                     /*!<Valid flag (read-only)*/

/**
  * @brief ADC_ADSTA_EXT Register Bit Definition
  */
#define  ADC_ADSTA_EXT_VALID_Pos                  (0)
#define  ADC_ADSTA_EXT_VALID_Msk                  (0x0FU << ADC_ADSTA_EXT_VALID_Pos)                /*!<Valid flag for channel (Valid Flag)*/
#define  ADC_ADSTA_EXT_OVERRUN_Pos                (4)
#define  ADC_ADSTA_EXT_OVERRUN_Msk                (0x0FU << ADC_ADSTA_EXT_OVERRUN_Pos)              /*!<Data overrun flag for channel (Overrun Flag)*/
#define  ADC_ADSTA_EXT_EOSMPIF_Pos                (16)
#define  ADC_ADSTA_EXT_EOSMPIF_Msk                (0x01U << ADC_ADSTA_EXT_EOSMPIF_Pos)              /*!<End of Sample FlagThis bit is set by hardware at the end of sampling, and cleared by software.*/
#define  ADC_ADSTA_EXT_EOCIF_Pos                  (17)
#define  ADC_ADSTA_EXT_EOCIF_Msk                  (0x01U << ADC_ADSTA_EXT_EOCIF_Pos)                /*!<End of Conversion FlagThis bit is set by hardware at the end of conversion, and cleared by software.*/
#define  ADC_ADSTA_EXT_JEOSMPIF_Pos               (18)
#define  ADC_ADSTA_EXT_JEOSMPIF_Msk               (0x01U << ADC_ADSTA_EXT_JEOSMPIF_Pos)             /*!<End of Injected Sample FlagThis bit is set by hardware at the end of sampling, and cleared by software.*/
#define  ADC_ADSTA_EXT_JEOCIF_Pos                 (19)
#define  ADC_ADSTA_EXT_JEOCIF_Msk                 (0x01U << ADC_ADSTA_EXT_JEOCIF_Pos)               /*!<End of Injected Conversion FlagThis bit is set by hardware at the end of conversion, and cleared by software.*/
#define  ADC_ADSTA_EXT_JEOSIF_Pos                 (20)
#define  ADC_ADSTA_EXT_JEOSIF_Msk                 (0x01U << ADC_ADSTA_EXT_JEOSIF_Pos)               /*!<End of Injected Sequence FlagThis bit is set by hardware at the end of sequential conversion, and cleared by software.*/
#define  ADC_ADSTA_EXT_JBUSY_Pos                  (21)
#define  ADC_ADSTA_EXT_JBUSY_Msk                  (0x01U << ADC_ADSTA_EXT_JBUSY_Pos)                /*!<Injected Conversion Busy/Idle Flag*/

/**
  * @brief ADC_CHANY0 Register Bit Definition
  */
#define  ADC_CHANY0_CHANY_SEL0_Pos                (0)
#define  ADC_CHANY0_CHANY_SEL0_Msk                (0x0FU << ADC_CHANY0_CHANY_SEL0_Pos)              /*!<0th Conversion Select for Any Channel sequence*/
#define  ADC_CHANY0_CHANY_SEL1_Pos                (4)
#define  ADC_CHANY0_CHANY_SEL1_Msk                (0x0FU << ADC_CHANY0_CHANY_SEL1_Pos)              /*!<1th Conversion Select for Any Channel sequence*/
#define  ADC_CHANY0_CHANY_SEL2_Pos                (8)
#define  ADC_CHANY0_CHANY_SEL2_Msk                (0x0FU << ADC_CHANY0_CHANY_SEL2_Pos)              /*!<2th Conversion Select for Any Channel sequence*/
#define  ADC_CHANY0_CHANY_SEL3_Pos                (12)
#define  ADC_CHANY0_CHANY_SEL3_Msk                (0x0FU << ADC_CHANY0_CHANY_SEL3_Pos)              /*!<3th Conversion Select for Any Channel sequence*/
#define  ADC_CHANY0_CHANY_SEL4_Pos                (16)
#define  ADC_CHANY0_CHANY_SEL4_Msk                (0x0FU << ADC_CHANY0_CHANY_SEL4_Pos)              /*!<4th Conversion Select for Any Channel sequence*/
#define  ADC_CHANY0_CHANY_SEL5_Pos                (20)
#define  ADC_CHANY0_CHANY_SEL5_Msk                (0x0FU << ADC_CHANY0_CHANY_SEL5_Pos)              /*!<5th Conversion Select for Any Channel sequence*/
#define  ADC_CHANY0_CHANY_SEL6_Pos                (24)
#define  ADC_CHANY0_CHANY_SEL6_Msk                (0x0FU << ADC_CHANY0_CHANY_SEL6_Pos)              /*!<6th Conversion Select for Any Channel sequence*/
#define  ADC_CHANY0_CHANY_SEL7_Pos                (28)
#define  ADC_CHANY0_CHANY_SEL7_Msk                (0x0FU << ADC_CHANY0_CHANY_SEL7_Pos)              /*!<7th Conversion Select for Any Channel sequence*/

/**
  * @brief ADC_CHANY1 Register Bit Definition
  */
#define  ADC_CHANY1_CHANY_SEL8_Pos                (0)
#define  ADC_CHANY1_CHANY_SEL8_Msk                (0x0FU << ADC_CHANY1_CHANY_SEL8_Pos)              /*!<8th Conversion Select for Any Channel sequence*/
#define  ADC_CHANY1_CHANY_SEL9_Pos                (4)
#define  ADC_CHANY1_CHANY_SEL9_Msk                (0x0FU << ADC_CHANY1_CHANY_SEL9_Pos)              /*!<9th Conversion Select for Any Channel sequence*/
#define  ADC_CHANY1_CHANY_SEL10_Pos               (8)
#define  ADC_CHANY1_CHANY_SEL10_Msk               (0x0FU << ADC_CHANY1_CHANY_SEL10_Pos)             /*!<10th Conversion Select for Any Channel sequence*/
#define  ADC_CHANY1_CHANY_SEL11_Pos               (12)
#define  ADC_CHANY1_CHANY_SEL11_Msk               (0x0FU << ADC_CHANY1_CHANY_SEL11_Pos)             /*!<11th Conversion Select for Any Channel sequence*/
#define  ADC_CHANY1_CHANY_SEL12_Pos               (16)
#define  ADC_CHANY1_CHANY_SEL12_Msk               (0x0FU << ADC_CHANY1_CHANY_SEL12_Pos)             /*!<12th Conversion Select for Any Channel sequence*/
#define  ADC_CHANY1_CHANY_SEL13_Pos               (20)
#define  ADC_CHANY1_CHANY_SEL13_Msk               (0x0FU << ADC_CHANY1_CHANY_SEL13_Pos)             /*!<13th Conversion Select for Any Channel sequence*/
#define  ADC_CHANY1_CHANY_SEL14_Pos               (24)
#define  ADC_CHANY1_CHANY_SEL14_Msk               (0x0FU << ADC_CHANY1_CHANY_SEL14_Pos)             /*!<14th Conversion Select for Any Channel sequence*/
#define  ADC_CHANY1_CHANY_SEL15_Pos               (28)
#define  ADC_CHANY1_CHANY_SEL15_Msk               (0x0FU << ADC_CHANY1_CHANY_SEL15_Pos)             /*!<15th Conversion Select for Any Channel sequence*/

/**
  * @brief ADC_ANY_CFG Register Bit Definition
  */
#define  ADC_ANY_CFG_CHANY_NUM_Pos                (0)
#define  ADC_ANY_CFG_CHANY_NUM_Msk                (0x0FU << ADC_ANY_CFG_CHANY_NUM_Pos)              /*!<Number of Any Channel Mode:*/

/**
  * @brief ADC_ANY_CR Register Bit Definition
  */
#define  ADC_ANY_CR_CHANY_MDEN_Pos                (0)
#define  ADC_ANY_CR_CHANY_MDEN_Msk                (0x01U << ADC_ANY_CR_CHANY_MDEN_Pos)              /*!<Any Channel Mode Enable:*/
#define  ADC_ANY_CR_JCEN_Pos                      (1)
#define  ADC_ANY_CR_JCEN_Msk                      (0x01U << ADC_ANY_CR_JCEN_Pos)                    /*!<Conversion Enable for Injected Channels*/
#define  ADC_ANY_CR_JEOSMPIE_Pos                  (2)
#define  ADC_ANY_CR_JEOSMPIE_Msk                  (0x01U << ADC_ANY_CR_JEOSMPIE_Pos)                /*!<Interrupt Enable for JEOSAMP*/
#define  ADC_ANY_CR_JEOCIE_Pos                    (3)
#define  ADC_ANY_CR_JEOCIE_Msk                    (0x01U << ADC_ANY_CR_JEOCIE_Pos)                  /*!<Interrupt Enable for JEOC*/
#define  ADC_ANY_CR_JEOSIE_Pos                    (4)
#define  ADC_ANY_CR_JEOSIE_Msk                    (0x01U << ADC_ANY_CR_JEOSIE_Pos)                  /*!<Interrupt Enable for JEOS*/
#define  ADC_ANY_CR_JAUTO_Pos                     (5)
#define  ADC_ANY_CR_JAUTO_Msk                     (0x01U << ADC_ANY_CR_JAUTO_Pos)                   /*!<Automatic Injected Conversion*/
#define  ADC_ANY_CR_JADST_Pos                     (6)
#define  ADC_ANY_CR_JADST_Msk                     (0x01U << ADC_ANY_CR_JADST_Pos)                   /*!<ADC Start for Injected Channels:enable JCEN first*/
#define  ADC_ANY_CR_JTRGEN_Pos                    (7)
#define  ADC_ANY_CR_JTRGEN_Msk                    (0x01U << ADC_ANY_CR_JTRGEN_Pos)                  /*!<External Hardware Trigger Enable For Injected Channels*/
#define  ADC_ANY_CR_JTRGSEL_Pos                   (8)
#define  ADC_ANY_CR_JTRGSEL_Msk                   (0x1FU << ADC_ANY_CR_JTRGSEL_Pos)                 /*!<ADC External Trigger Sources Selection For Injected Channel*/
#define  ADC_ANY_CR_JTRGSHIFT_Pos                 (13)
#define  ADC_ANY_CR_JTRGSHIFT_Msk                 (0x07U << ADC_ANY_CR_JTRGSHIFT_Pos)               /*!<External Trigger Shift Sample for Injected ChannelsAfter a trigger signal is generated, the sampling starts after a delay of N PCLK2 clock cycles.In case of trigger scan, the sampling in the rest channels starts immediately after the last sampling is complete.*/
#define  ADC_ANY_CR_JTRG_EDGE_Pos                 (16)
#define  ADC_ANY_CR_JTRG_EDGE_Msk                 (0x03U << ADC_ANY_CR_JTRG_EDGE_Pos)               /*!<External Trigger sources Edge Selection for Injected Channels*/

/**
  * @brief ADC_SMPR1 Register Bit Definition
  */
#define  ADC_SMPR1_SAMP0_Pos                      (0)
#define  ADC_SMPR1_SAMP0_Msk                      (0x0FU << ADC_SMPR1_SAMP0_Pos)                    /*!<Sample Time Selection*/
#define  ADC_SMPR1_SAMP1_Pos                      (4)
#define  ADC_SMPR1_SAMP1_Msk                      (0x0FU << ADC_SMPR1_SAMP1_Pos)                    /*!<Sample Time Selection*/
#define  ADC_SMPR1_SAMP2_Pos                      (8)
#define  ADC_SMPR1_SAMP2_Msk                      (0x0FU << ADC_SMPR1_SAMP2_Pos)                    /*!<Sample Time Selection*/
#define  ADC_SMPR1_SAMP3_Pos                      (12)
#define  ADC_SMPR1_SAMP3_Msk                      (0x0FU << ADC_SMPR1_SAMP3_Pos)                    /*!<Sample Time Selection*/
#define  ADC_SMPR1_SAMP4_Pos                      (16)
#define  ADC_SMPR1_SAMP4_Msk                      (0x0FU << ADC_SMPR1_SAMP4_Pos)                    /*!<Sample Time Selection*/
#define  ADC_SMPR1_SAMP5_Pos                      (20)
#define  ADC_SMPR1_SAMP5_Msk                      (0x0FU << ADC_SMPR1_SAMP5_Pos)                    /*!<Sample Time Selection*/
#define  ADC_SMPR1_SAMP6_Pos                      (24)
#define  ADC_SMPR1_SAMP6_Msk                      (0x0FU << ADC_SMPR1_SAMP6_Pos)                    /*!<Sample Time Selection*/
#define  ADC_SMPR1_SAMP7_Pos                      (28)
#define  ADC_SMPR1_SAMP7_Msk                      (0x0FU << ADC_SMPR1_SAMP7_Pos)                    /*!<Sample Time SelectionThese bits are used to independently select the sample time of each channel. In a sample cycle, the channel selection bit should remain unchanged.*/

/**
  * @brief ADC_SMPR2 Register Bit Definition
  */
#define  ADC_SMPR2_SAMP8_Pos                      (0)
#define  ADC_SMPR2_SAMP8_Msk                      (0x0FU << ADC_SMPR2_SAMP8_Pos)                    /*!<Sample Time Selection*/
#define  ADC_SMPR2_SAMP9_Pos                      (4)
#define  ADC_SMPR2_SAMP9_Msk                      (0x0FU << ADC_SMPR2_SAMP9_Pos)                    /*!<Sample Time Selection*/
#define  ADC_SMPR2_SAMP10_Pos                     (8)
#define  ADC_SMPR2_SAMP10_Msk                     (0x0FU << ADC_SMPR2_SAMP10_Pos)                   /*!<Sample Time Selection*/
#define  ADC_SMPR2_SAMP11_Pos                     (12)
#define  ADC_SMPR2_SAMP11_Msk                     (0x0FU << ADC_SMPR2_SAMP11_Pos)                   /*!<Sample Time Selection*/
#define  ADC_SMPR2_SAMP12_Pos                     (16)
#define  ADC_SMPR2_SAMP12_Msk                     (0x0FU << ADC_SMPR2_SAMP12_Pos)                   /*!<Sample Time Selection*/
#define  ADC_SMPR2_SAMP13_Pos                     (20)
#define  ADC_SMPR2_SAMP13_Msk                     (0x0FU << ADC_SMPR2_SAMP13_Pos)                   /*!<Sample Time Selection*/
#define  ADC_SMPR2_SAMP14_Pos                     (24)
#define  ADC_SMPR2_SAMP14_Msk                     (0x0FU << ADC_SMPR2_SAMP14_Pos)                   /*!<Sample Time Selection*/
#define  ADC_SMPR2_SAMP15_Pos                     (28)
#define  ADC_SMPR2_SAMP15_Msk                     (0x0FU << ADC_SMPR2_SAMP15_Pos)                   /*!<Sample Time SelectionThese bits are used to independently select the sample time of each channel. In a sample cycle, the channel selection bit should remain unchanged.*/

/**
  * @brief ADC_JOFR Register Bit Definition
  */
#define  ADC_JOFR_JOFFSET_Pos                     (0)
#define  ADC_JOFR_JOFFSET_Msk                     (0x0FFFU << ADC_JOFR_JOFFSET_Pos)                 /*!<Data Offset Register for 12-bit AD Injected Channel n*/

/**
  * @brief ADC_JSQR Register Bit Definition
  */
#define  ADC_JSQR_JSQ0_Pos                        (0)
#define  ADC_JSQR_JSQ0_Msk                        (0x1FU << ADC_JSQR_JSQ0_Pos)                      /*!<0th Conversion for Injected Sequence*/
#define  ADC_JSQR_JSQ1_Pos                        (5)
#define  ADC_JSQR_JSQ1_Msk                        (0x1FU << ADC_JSQR_JSQ1_Pos)                      /*!<1th Conversion for Injected Sequence*/
#define  ADC_JSQR_JSQ2_Pos                        (10)
#define  ADC_JSQR_JSQ2_Msk                        (0x1FU << ADC_JSQR_JSQ2_Pos)                      /*!<2th Conversion for Injected Sequence*/
#define  ADC_JSQR_JSQ3_Pos                        (15)
#define  ADC_JSQR_JSQ3_Msk                        (0x1FU << ADC_JSQR_JSQ3_Pos)                      /*!<3th Conversion for Injected Sequence*/
#define  ADC_JSQR_JNUM_Pos                        (20)
#define  ADC_JSQR_JNUM_Msk                        (0x03U << ADC_JSQR_JNUM_Pos)                      /*!<Channel Number for Injected Sequence*/

/**
  * @brief ADC_JADDATA Register Bit Definition
  */
#define  ADC_JADDATA_JDATA_Pos                    (0)
#define  ADC_JADDATA_JDATA_Msk                    (0xFFFFU << ADC_JADDATA_JDATA_Pos)                /*!<12-bit A/D conversion result of current injected channel.The alignment style is selected via software.*/
#define  ADC_JADDATA_JCHANNELSEL_Pos              (16)
#define  ADC_JADDATA_JCHANNELSEL_Msk              (0x0FU << ADC_JADDATA_JCHANNELSEL_Pos)            /*!<4 bits show the injected channel corresponding to the current data (Injected Channel Selection)*/
#define  ADC_JADDATA_JOVERRUN_Pos                 (21)
#define  ADC_JADDATA_JOVERRUN_Msk                 (0x01U << ADC_JADDATA_JOVERRUN_Pos)               /*!<Overrun Flag for Injected Channels (read-only)*/
#define  ADC_JADDATA_JVALID_Pos                   (22)
#define  ADC_JADDATA_JVALID_Msk                   (0x01U << ADC_JADDATA_JVALID_Pos)                 /*!<Valid Flag for Injected Channels (read-only)*/

/**
  * @brief ADC_JDR Register Bit Definition
  */
#define  ADC_JDR_JDATA_Pos                        (0)
#define  ADC_JDR_JDATA_Msk                        (0xFFFFU << ADC_JDR_JDATA_Pos)                    /*!<Conversion result of A/D injected channel n The alignment style is selected via software. Please refer to the data alignment section.*/
#define  ADC_JDR_JOVERRUN_Pos                     (21)
#define  ADC_JDR_JOVERRUN_Msk                     (0x01U << ADC_JDR_JOVERRUN_Pos)                   /*!<Overrun Flag for Injected Channels*/
#define  ADC_JDR_JVALID_Pos                       (22)
#define  ADC_JDR_JVALID_Msk                       (0x01U << ADC_JDR_JVALID_Pos)                     /*!<Valid Flag for Injected Channels*/


#endif

