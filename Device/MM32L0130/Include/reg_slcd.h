/***********************************************************************************************************************
    @file     reg_slcd.h
    @author   VV TEAM
    @brief    This flie contains all the SLCD's register and its field definition.
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

#ifndef __REG_SLCD_H
#define __REG_SLCD_H


/* Files includes ----------------------------------------------------------------------------------------------------*/
#include <core_cm0plus.h>



/**
  * @brief SLCD Base Address Definition
  */
#define  SLCD_BASE                                 0x40009400                                       /*!<Base Address: 0x40009400*/

/**
  * @brief SLCD Register Structure Definition
  */
typedef struct {
    __IO uint32_t CR;                                                           /*!< Control register,                               offset: 0x00 */
    __IO uint32_t FCR;                                                          /*!< Frame control register,                         offset: 0x04 */
    __IO uint32_t SR;                                                           /*!< Status register,                                offset: 0x08 */
    __IO uint32_t CLRR;                                                         /*!< Status clear register,                          offset: 0x0C */
    __IO uint32_t BLKR0;                                                        /*!< Blinking control register 0,                    offset: 0x10 */
    __IO uint32_t BLKR1;                                                        /*!< Blinking control register 1,                    offset: 0x14 */
    __IO uint32_t BLKR2;                                                        /*!< Blinking control register 2,                    offset: 0x18 */
    __IO uint32_t BLKR3;                                                        /*!< Blinking control register 3,                    offset: 0x1C */
    __IO uint32_t IOENR0;                                                       /*!< IO enable register 0,                           offset: 0x20 */
    __IO uint32_t IOENR1;                                                       /*!< IO enable register 1,                           offset: 0x24 */
    __IO uint32_t RESERVED0x28;                                                 /*!< Reserved                                        offset: 0x28 */
    __IO uint32_t RESERVED0x2C;                                                 /*!< Reserved                                        offset: 0x2C */
    __IO uint32_t CFGR0;                                                        /*!< COM/SEG configuration register 0,               offset: 0x30 */
    __IO uint32_t CFGR1;                                                        /*!< COM/SEG configuration register 1,               offset: 0x34 */
    __IO uint32_t IDXR0;                                                        /*!< COM index register 0,                           offset: 0x38 */
    __IO uint32_t IDXR1;                                                        /*!< COM index register 1,                           offset: 0x3C */
    union {
        __IO uint32_t DR[16];                                                   /*!< Display data registers                          offset: 0x40~0x7C */
        struct {
            __IO uint32_t DR0;                                                  /*!< Display data register 0,                        offset: 0x40 */
            __IO uint32_t DR1;                                                  /*!< Display data register 1,                        offset: 0x44 */
            __IO uint32_t DR2;                                                  /*!< Display data register 2,                        offset: 0x48 */
            __IO uint32_t DR3;                                                  /*!< Display data register 3,                        offset: 0x4C */
            __IO uint32_t DR4;                                                  /*!< Display data register 4,                        offset: 0x50 */
            __IO uint32_t DR5;                                                  /*!< Display data register 5,                        offset: 0x54 */
            __IO uint32_t DR6;                                                  /*!< Display data register 6,                        offset: 0x58 */
            __IO uint32_t DR7;                                                  /*!< Display data register 7,                        offset: 0x5C */
            __IO uint32_t DR8;                                                  /*!< Display data register 8,                        offset: 0x60 */
            __IO uint32_t DR9;                                                  /*!< Display data register 9,                        offset: 0x64 */
            __IO uint32_t DR10;                                                 /*!< Display data register 10,                       offset: 0x68 */
            __IO uint32_t DR11;                                                 /*!< Display data register 11,                       offset: 0x6C */
            __IO uint32_t DR12;                                                 /*!< Display data register 12,                       offset: 0x70 */
            __IO uint32_t DR13;                                                 /*!< Display data register 13,                       offset: 0x74 */
            __IO uint32_t DR14;                                                 /*!< Display data register 14,                       offset: 0x78 */
            __IO uint32_t DR15;                                                 /*!< Display data register 15,                       offset: 0x7C */
        };
    };
} SLCD_TypeDef;

/**
  * @brief SLCD type pointer Definition
  */
#define SLCD                                      ((SLCD_TypeDef *)SLCD_BASE)

/**
  * @brief SLCD_CR Register Bit Definition
  */
#define  SLCD_CR_LCDEN_Pos                        (0)
#define  SLCD_CR_LCDEN_Msk                        (0x01U << SLCD_CR_LCDEN_Pos)                      /*!<SLCD module enable*/
#define  SLCD_CR_LPEN_Pos                         (1)
#define  SLCD_CR_LPEN_Msk                         (0x01U << SLCD_CR_LPEN_Pos)                       /*!<Low power drive waveform enable*/
#define  SLCD_CR_DUTY_Pos                         (2)
#define  SLCD_CR_DUTY_Msk                         (0x07U << SLCD_CR_DUTY_Pos)                       /*!<Duty cycle mode selection*/
#define  SLCD_CR_BIAS_Pos                         (5)
#define  SLCD_CR_BIAS_Msk                         (0x03U << SLCD_CR_BIAS_Pos)                       /*!<Bias mode selection*/
#define  SLCD_CR_CPMODE_Pos                       (7)
#define  SLCD_CR_CPMODE_Msk                       (0x03U << SLCD_CR_CPMODE_Pos)                     /*!<Charge pump mode selection*/
#define  SLCD_CR_REFEN_Pos                        (9)
#define  SLCD_CR_REFEN_Msk                        (0x01U << SLCD_CR_REFEN_Pos)                      /*!<Internal voltage reference enable*/
#define  SLCD_CR_VDDEN_Pos                        (10)
#define  SLCD_CR_VDDEN_Msk                        (0x01U << SLCD_CR_VDDEN_Pos)                      /*!<Internal VDD as SLCD power enable*/

/**
  * @brief SLCD_FCR Register Bit Definition
  */
#define  SLCD_FCR_LCDIE_Pos                       (0)
#define  SLCD_FCR_LCDIE_Msk                       (0x01U << SLCD_FCR_LCDIE_Pos)                     /*!<LCD module interrupt enable*/
#define  SLCD_FCR_EOFIE_Pos                       (1)
#define  SLCD_FCR_EOFIE_Msk                       (0x01U << SLCD_FCR_EOFIE_Pos)                     /*!<End of frame interrupt enable*/
#define  SLCD_FCR_BLKIE_Pos                       (2)
#define  SLCD_FCR_BLKIE_Msk                       (0x01U << SLCD_FCR_BLKIE_Pos)                     /*!<Blinking interrupt enable*/
#define  SLCD_FCR_SOFF_Pos                        (3)
#define  SLCD_FCR_SOFF_Msk                        (0x01U << SLCD_FCR_SOFF_Pos)                      /*!<Close all SEGs*/
#define  SLCD_FCR_CC_Pos                          (4)
#define  SLCD_FCR_CC_Msk                          (0x0FU << SLCD_FCR_CC_Pos)                        /*!<Contrast controlSelect the max. Bias voltage (under 1/4, 1/3 or 1/2 bias mode, respectively V4/V3/V2). Under 1/2 bias mode, in case of CC[3] is set, this bit won't be active. For example, if CC is configured as 4'b1100 under 1/2 bias mode, the actually active configuration is 4'b0100.*/
#define  SLCD_FCR_DEAD_Pos                        (8)
#define  SLCD_FCR_DEAD_Msk                        (0x07U << SLCD_FCR_DEAD_Pos)                      /*!<Dead insertionInsert the dead zone between two frames; when inserting dead zone, SEG and COM signal voltage is zero.*/
#define  SLCD_FCR_BLINK_Pos                       (11)
#define  SLCD_FCR_BLINK_Msk                       (0x03U << SLCD_FCR_BLINK_Pos)                     /*!<Blinking mode selection*/
#define  SLCD_FCR_BLINKF_Pos                      (13)
#define  SLCD_FCR_BLINKF_Msk                      (0x07U << SLCD_FCR_BLINKF_Pos)                    /*!<Blinking division*/
#define  SLCD_FCR_DIV_Pos                         (16)
#define  SLCD_FCR_DIV_Msk                         (0x0FU << SLCD_FCR_DIV_Pos)                       /*!<SLCD clock division*/
#define  SLCD_FCR_PS_Pos                          (20)
#define  SLCD_FCR_PS_Msk                          (0x0FU << SLCD_FCR_PS_Pos)                        /*!<SLCD clock prescaler*/
#define  SLCD_FCR_CPDIV_Pos                       (24)
#define  SLCD_FCR_CPDIV_Msk                       (0x07U << SLCD_FCR_CPDIV_Pos)                     /*!<Charge pump clock division*/
#define  SLCD_FCR_DRLC_Pos                        (27)
#define  SLCD_FCR_DRLC_Msk                        (0x01U << SLCD_FCR_DRLC_Pos)                      /*!<SLCD_DR [7:0] data clear*/
#define  SLCD_FCR_DRHC_Pos                        (28)
#define  SLCD_FCR_DRHC_Msk                        (0x01U << SLCD_FCR_DRHC_Pos)                      /*!<SLCD_DR [15:8] data clear*/
#define  SLCD_FCR_DRSEL_Pos                       (29)
#define  SLCD_FCR_DRSEL_Msk                       (0x01U << SLCD_FCR_DRSEL_Pos)                     /*!<Display register selectionUnder the static, 1/2, 1/3, 1/4 duty cycle mode, SLCD_DR [15:8] may act as the backup display register. DRSEL bit is used to select whether the display content comes from SLCD_DR[7:0] or SLCD_DR [15:8].*/
#define  SLCD_FCR_DMAEN_Pos                       (30)
#define  SLCD_FCR_DMAEN_Msk                       (0x01U << SLCD_FCR_DMAEN_Pos)                     /*!<DMA transfer enableThe end of frame flag may be used as the trigger signal of DMA transfer*/

/**
  * @brief SLCD_SR Register Bit Definition
  */
#define  SLCD_SR_ENS_Pos                          (0)
#define  SLCD_SR_ENS_Msk                          (0x01U << SLCD_SR_ENS_Pos)                        /*!<SLCD enable flag SLCD controller status. When the LCDEN bit of SLCD_CR is set, this register is set. When the SLCD_CR LCDEN is reset, wait for the end of current display frame, and the status bit can only be reset.*/
#define  SLCD_SR_EOF_Pos                          (1)
#define  SLCD_SR_EOF_Msk                          (0x01U << SLCD_SR_EOF_Pos)                        /*!<End of frame flagAt the end of each display frame, the hardware sets the register. Setting the EOFC bit of SLCD_CLRR register will reset the register.*/
#define  SLCD_SR_BLKF_Pos                         (2)
#define  SLCD_SR_BLKF_Msk                         (0x01U << SLCD_SR_BLKF_Pos)                       /*!<Blinking cycle flagOnce the blinking mode opens, when the display content toggles twice, the hardware sets the register. Setting the BLKFC bit of SLCD_CLRR register will reset the register.*/
#define  SLCD_SR_DRSS_Pos                         (3)
#define  SLCD_SR_DRSS_Msk                         (0x01U << SLCD_SR_DRSS_Pos)                       /*!<Display data register indicationIndicate that the current display content is fromSLCD_DR [7:0] or SLCD_DR [15:8]. It's only active under the static, 1/2, 1/3 and 1/4 duty cycle mode;it's cleared under the 1/6 and 1/8 duty cycle mode*/
#define  SLCD_SR_FCRSF_Pos                        (5)
#define  SLCD_SR_FCRSF_Msk                        (0x01U << SLCD_SR_FCRSF_Pos)                      /*!<FCR register synchronization flag The software updates SLCD_FCR clock domain on the APB bus. When these values are updated to the LCD display clock domain, the hardware sets this register.When the software updates SLCD_FCR value, the hardware will reset this register.*/

/**
  * @brief SLCD_CLRR Register Bit Definition
  */
#define  SLCD_CLRR_EOFC_Pos                       (1)
#define  SLCD_CLRR_EOFC_Msk                       (0x01U << SLCD_CLRR_EOFC_Pos)                     /*!<Clear the end of frame flagThe software sets the register. Clear the SLCD_SR EOF bit. Writing 0 doesn't have any meaning.*/
#define  SLCD_CLRR_BLKFC_Pos                      (2)
#define  SLCD_CLRR_BLKFC_Msk                      (0x01U << SLCD_CLRR_BLKFC_Pos)                    /*!<Clear the blinking cycle flagThe software sets the register. Clear the SLCD_SR BLKF bit. Writing 0 doesn't have any meaning.*/

/**
  * @brief SLCD_BLKR0 Register Bit Definition
  */
#define  SLCD_BLKR0_SEGIDX0_Pos                   (0)
#define  SLCD_BLKR0_SEGIDX0_Msk                   (0x3FU << SLCD_BLKR0_SEGIDX0_Pos)                 /*!<Blinking SEG0 index*/
#define  SLCD_BLKR0_COMIDX0_Pos                   (8)
#define  SLCD_BLKR0_COMIDX0_Msk                   (0x07U << SLCD_BLKR0_COMIDX0_Pos)                 /*!<Blinking COM0 index*/
#define  SLCD_BLKR0_IDXEN0_Pos                    (15)
#define  SLCD_BLKR0_IDXEN0_Msk                    (0x01U << SLCD_BLKR0_IDXEN0_Pos)                  /*!<Blinking index 0 enable*/
#define  SLCD_BLKR0_SEGIDX1_Pos                   (16)
#define  SLCD_BLKR0_SEGIDX1_Msk                   (0x3FU << SLCD_BLKR0_SEGIDX1_Pos)                 /*!<Blinking SEG1 index*/
#define  SLCD_BLKR0_COMIDX1_Pos                   (24)
#define  SLCD_BLKR0_COMIDX1_Msk                   (0x07U << SLCD_BLKR0_COMIDX1_Pos)                 /*!<Blinking COM1 index*/
#define  SLCD_BLKR0_IDXEN1_Pos                    (31)
#define  SLCD_BLKR0_IDXEN1_Msk                    (0x01U << SLCD_BLKR0_IDXEN1_Pos)                  /*!<Blinking index 1 enable*/

/**
  * @brief SLCD_BLKR1 Register Bit Definition
  */
#define  SLCD_BLKR1_SEGIDX2_Pos                   (0)
#define  SLCD_BLKR1_SEGIDX2_Msk                   (0x3FU << SLCD_BLKR1_SEGIDX2_Pos)                 /*!<Blinking SEG2 index*/
#define  SLCD_BLKR1_COMIDX2_Pos                   (8)
#define  SLCD_BLKR1_COMIDX2_Msk                   (0x07U << SLCD_BLKR1_COMIDX2_Pos)                 /*!<Blinking COM2 index*/
#define  SLCD_BLKR1_IDXEN2_Pos                    (15)
#define  SLCD_BLKR1_IDXEN2_Msk                    (0x01U << SLCD_BLKR1_IDXEN2_Pos)                  /*!<Blinking index 2 enable*/
#define  SLCD_BLKR1_SEGIDX3_Pos                   (16)
#define  SLCD_BLKR1_SEGIDX3_Msk                   (0x3FU << SLCD_BLKR1_SEGIDX3_Pos)                 /*!<Blinking SEG3 index*/
#define  SLCD_BLKR1_COMIDX3_Pos                   (24)
#define  SLCD_BLKR1_COMIDX3_Msk                   (0x07U << SLCD_BLKR1_COMIDX3_Pos)                 /*!<Blinking COM3 index*/
#define  SLCD_BLKR1_IDXEN3_Pos                    (31)
#define  SLCD_BLKR1_IDXEN3_Msk                    (0x01U << SLCD_BLKR1_IDXEN3_Pos)                  /*!<Blinking index 3 enable*/

/**
  * @brief SLCD_BLKR2 Register Bit Definition
  */
#define  SLCD_BLKR2_SEGIDX4_Pos                   (0)
#define  SLCD_BLKR2_SEGIDX4_Msk                   (0x3FU << SLCD_BLKR2_SEGIDX4_Pos)                 /*!<Blinking SEG4 index*/
#define  SLCD_BLKR2_COMIDX4_Pos                   (8)
#define  SLCD_BLKR2_COMIDX4_Msk                   (0x07U << SLCD_BLKR2_COMIDX4_Pos)                 /*!<Blinking COM4 index*/
#define  SLCD_BLKR2_IDXEN4_Pos                    (15)
#define  SLCD_BLKR2_IDXEN4_Msk                    (0x01U << SLCD_BLKR2_IDXEN4_Pos)                  /*!<Blinking index 4 enable*/
#define  SLCD_BLKR2_SEGIDX5_Pos                   (16)
#define  SLCD_BLKR2_SEGIDX5_Msk                   (0x3FU << SLCD_BLKR2_SEGIDX5_Pos)                 /*!<Blinking SEG5 index*/
#define  SLCD_BLKR2_COMIDX5_Pos                   (24)
#define  SLCD_BLKR2_COMIDX5_Msk                   (0x07U << SLCD_BLKR2_COMIDX5_Pos)                 /*!<Blinking COM5 index*/
#define  SLCD_BLKR2_IDXEN5_Pos                    (31)
#define  SLCD_BLKR2_IDXEN5_Msk                    (0x01U << SLCD_BLKR2_IDXEN5_Pos)                  /*!<Blinking index 5 enable*/

/**
  * @brief SLCD_BLKR3 Register Bit Definition
  */
#define  SLCD_BLKR3_SEGIDX6_Pos                   (0)
#define  SLCD_BLKR3_SEGIDX6_Msk                   (0x3FU << SLCD_BLKR3_SEGIDX6_Pos)                 /*!<Blinking SEG6 index*/
#define  SLCD_BLKR3_COMIDX6_Pos                   (8)
#define  SLCD_BLKR3_COMIDX6_Msk                   (0x07U << SLCD_BLKR3_COMIDX6_Pos)                 /*!<Blinking COM6 index*/
#define  SLCD_BLKR3_IDXEN6_Pos                    (15)
#define  SLCD_BLKR3_IDXEN6_Msk                    (0x01U << SLCD_BLKR3_IDXEN6_Pos)                  /*!<Blinking index 6 enable*/
#define  SLCD_BLKR3_SEGIDX7_Pos                   (16)
#define  SLCD_BLKR3_SEGIDX7_Msk                   (0x3FU << SLCD_BLKR3_SEGIDX7_Pos)                 /*!<Blinking SEG7 index*/
#define  SLCD_BLKR3_COMIDX7_Pos                   (24)
#define  SLCD_BLKR3_COMIDX7_Msk                   (0x07U << SLCD_BLKR3_COMIDX7_Pos)                 /*!<Blinking COM7 index*/
#define  SLCD_BLKR3_IDXEN7_Pos                    (31)
#define  SLCD_BLKR3_IDXEN7_Msk                    (0x01U << SLCD_BLKR3_IDXEN7_Pos)                  /*!<Blinking index 7 enable*/

/**
  * @brief SLCD_IOENR0 Register Bit Definition
  */
#define  SLCD_IOENR0_IOENR0_Pos                   (0)
#define  SLCD_IOENR0_IOENR0_Msk                   (0xFFFFFFFFU << SLCD_IOENR0_IOENR0_Pos)           /*!<IO enable control corresponding to the low 32 bit SLCD pin.*/

/**
  * @brief SLCD_IOENR1 Register Bit Definition
  */
#define  SLCD_IOENR1_IOENR1_Pos                   (0)
#define  SLCD_IOENR1_IOENR1_Msk                   (0xFFFFFFFFU << SLCD_IOENR1_IOENR1_Pos)           /*!<IO enable control corresponding to the high 32 bit SLCD pin.*/

/**
  * @brief SLCD_CFGR0 Register Bit Definition
  */
#define  SLCD_CFGR0_CFG0_Pos                      (0)
#define  SLCD_CFGR0_CFG0_Msk                      (0xFFFFFFFFU << SLCD_CFGR0_CFG0_Pos)              /*!<SEG/COM selection control corresponding to the low 32 bit SLCD pin.*/

/**
  * @brief SLCD_CFGR1 Register Bit Definition
  */
#define  SLCD_CFGR1_CFG0_Pos                      (0)
#define  SLCD_CFGR1_CFG0_Msk                      (0xFFFFFFFFU << SLCD_CFGR1_CFG0_Pos)              /*!<SEG/COM selection control corresponding to the high 32 bit SLCD pin.*/

/**
  * @brief SLCD_IDXR0 Register Bit Definition
  */
#define  SLCD_IDXR0_COM0IDX_Pos                   (0)
#define  SLCD_IDXR0_COM0IDX_Msk                   (0x3FU << SLCD_IDXR0_COM0IDX_Pos)                 /*!<COM0 indexConfigure No. COM0IDX SLCD pin as COM0*/
#define  SLCD_IDXR0_COM1IDX_Pos                   (8)
#define  SLCD_IDXR0_COM1IDX_Msk                   (0x3FU << SLCD_IDXR0_COM1IDX_Pos)                 /*!<COM1 indexConfigure No. COM1IDX SLCD pin as COM1*/
#define  SLCD_IDXR0_COM2IDX_Pos                   (16)
#define  SLCD_IDXR0_COM2IDX_Msk                   (0x3FU << SLCD_IDXR0_COM2IDX_Pos)                 /*!<COM2 indexConfigure No. COM2IDX SLCD pin as COM2*/
#define  SLCD_IDXR0_COM3IDX_Pos                   (24)
#define  SLCD_IDXR0_COM3IDX_Msk                   (0x3FU << SLCD_IDXR0_COM3IDX_Pos)                 /*!<COM3 indexConfigure No. COM3IDX SLCD pin as COM3*/

/**
  * @brief SLCD_IDXR1 Register Bit Definition
  */
#define  SLCD_IDXR1_COM4IDX_Pos                   (0)
#define  SLCD_IDXR1_COM4IDX_Msk                   (0x3FU << SLCD_IDXR1_COM4IDX_Pos)                 /*!<COM4 indexConfigure No. COM4IDX SLCD pin as COM4*/
#define  SLCD_IDXR1_COM5IDX_Pos                   (8)
#define  SLCD_IDXR1_COM5IDX_Msk                   (0x3FU << SLCD_IDXR1_COM5IDX_Pos)                 /*!<COM5 indexConfigure No. COM5IDX SLCD pin as COM5*/
#define  SLCD_IDXR1_COM6IDX_Pos                   (16)
#define  SLCD_IDXR1_COM6IDX_Msk                   (0x3FU << SLCD_IDXR1_COM6IDX_Pos)                 /*!<COM6 indexConfigure No. COM6IDX SLCD pin as COM6*/
#define  SLCD_IDXR1_COM7IDX_Pos                   (24)
#define  SLCD_IDXR1_COM7IDX_Msk                   (0x3FU << SLCD_IDXR1_COM7IDX_Pos)                 /*!<COM7 indexConfigure No. COM7IDX SLCD pin as COM7*/

/**
  * @brief SLCD_DR0 Register Bit Definition
  */
#define  SLCD_DR0_SLCD_DR0_Pos                    (0)
#define  SLCD_DR0_SLCD_DR0_Msk                    (0xFFFFFFFFU << SLCD_DR0_SLCD_DR0_Pos)            /*!<Low 32 bit display data corresponding to COM0*/

/**
  * @brief SLCD_DR1 Register Bit Definition
  */
#define  SLCD_DR1_SLCD_DR1_Pos                    (0)
#define  SLCD_DR1_SLCD_DR1_Msk                    (0xFFFFFFFFU << SLCD_DR1_SLCD_DR1_Pos)            /*!<High 32 bit display data corresponding to COM0*/

/**
  * @brief SLCD_DR2 Register Bit Definition
  */
#define  SLCD_DR2_SLCD_DR2_Pos                    (0)
#define  SLCD_DR2_SLCD_DR2_Msk                    (0xFFFFFFFFU << SLCD_DR2_SLCD_DR2_Pos)            /*!<Low 32 bit display data corresponding to COM1*/

/**
  * @brief SLCD_DR3 Register Bit Definition
  */
#define  SLCD_DR3_SLCD_DR3_Pos                    (0)
#define  SLCD_DR3_SLCD_DR3_Msk                    (0xFFFFFFFFU << SLCD_DR3_SLCD_DR3_Pos)            /*!<High 32 bit display data corresponding to COM1*/

/**
  * @brief SLCD_DR4 Register Bit Definition
  */
#define  SLCD_DR4_SLCD_DR4_Pos                    (0)
#define  SLCD_DR4_SLCD_DR4_Msk                    (0xFFFFFFFFU << SLCD_DR4_SLCD_DR4_Pos)            /*!<Low 32 bit display data corresponding to COM2*/

/**
  * @brief SLCD_DR5 Register Bit Definition
  */
#define  SLCD_DR5_SLCD_DR5_Pos                    (0)
#define  SLCD_DR5_SLCD_DR5_Msk                    (0xFFFFFFFFU << SLCD_DR5_SLCD_DR5_Pos)            /*!<High 32 bit display data corresponding to COM2*/

/**
  * @brief SLCD_DR6 Register Bit Definition
  */
#define  SLCD_DR6_SLCD_DR6_Pos                    (0)
#define  SLCD_DR6_SLCD_DR6_Msk                    (0xFFFFFFFFU << SLCD_DR6_SLCD_DR6_Pos)            /*!<Low 32 bit display data corresponding to COM3*/

/**
  * @brief SLCD_DR7 Register Bit Definition
  */
#define  SLCD_DR7_SLCD_DR7_Pos                    (0)
#define  SLCD_DR7_SLCD_DR7_Msk                    (0xFFFFFFFFU << SLCD_DR7_SLCD_DR7_Pos)            /*!<High 32 bit display data corresponding to COM3*/

/**
  * @brief SLCD_DR8 Register Bit Definition
  */
#define  SLCD_DR8_SLCD_DR8_Pos                    (0)
#define  SLCD_DR8_SLCD_DR8_Msk                    (0xFFFFFFFFU << SLCD_DR8_SLCD_DR8_Pos)            /*!<Low 32 bit display data corresponding to COM4*/

/**
  * @brief SLCD_DR9 Register Bit Definition
  */
#define  SLCD_DR9_SLCD_DR9_Pos                    (0)
#define  SLCD_DR9_SLCD_DR9_Msk                    (0xFFFFFFFFU << SLCD_DR9_SLCD_DR9_Pos)            /*!<High 32 bit display data corresponding to COM4*/

/**
  * @brief SLCD_DR10 Register Bit Definition
  */
#define  SLCD_DR10_SLCD_DR10_Pos                  (0)
#define  SLCD_DR10_SLCD_DR10_Msk                  (0xFFFFFFFFU << SLCD_DR10_SLCD_DR10_Pos)          /*!<Low 32 bit display data corresponding to COM5*/

/**
  * @brief SLCD_DR11 Register Bit Definition
  */
#define  SLCD_DR11_SLCD_DR11_Pos                  (0)
#define  SLCD_DR11_SLCD_DR11_Msk                  (0xFFFFFFFFU << SLCD_DR11_SLCD_DR11_Pos)          /*!<High 32 bit display data corresponding to COM5*/

/**
  * @brief SLCD_DR12 Register Bit Definition
  */
#define  SLCD_DR12_SLCD_DR12_Pos                  (0)
#define  SLCD_DR12_SLCD_DR12_Msk                  (0xFFFFFFFFU << SLCD_DR12_SLCD_DR12_Pos)          /*!<Low 32 bit display data corresponding to COM6*/

/**
  * @brief SLCD_DR13 Register Bit Definition
  */
#define  SLCD_DR13_SLCD_DR13_Pos                  (0)
#define  SLCD_DR13_SLCD_DR13_Msk                  (0xFFFFFFFFU << SLCD_DR13_SLCD_DR13_Pos)          /*!<High 32 bit display data corresponding to COM6*/

/**
  * @brief SLCD_DR14 Register Bit Definition
  */
#define  SLCD_DR14_SLCD_DR14_Pos                  (0)
#define  SLCD_DR14_SLCD_DR14_Msk                  (0xFFFFFFFFU << SLCD_DR14_SLCD_DR14_Pos)          /*!<Low 32 bit display data corresponding to COM7*/

/**
  * @brief SLCD_DR15 Register Bit Definition
  */
#define  SLCD_DR15_SLCD_DR15_Pos                  (0)
#define  SLCD_DR15_SLCD_DR15_Msk                  (0xFFFFFFFFU << SLCD_DR15_SLCD_DR15_Pos)          /*!<High 32 bit display data corresponding to COM7*/


#endif

