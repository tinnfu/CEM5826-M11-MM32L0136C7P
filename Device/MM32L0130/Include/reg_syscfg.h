/***********************************************************************************************************************
    @file     reg_syscfg.h
    @author   VV TEAM
    @brief    This flie contains all the SYSCFG's register and its field definition.
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

#ifndef __REG_SYSCFG_H
#define __REG_SYSCFG_H


/* Files includes ----------------------------------------------------------------------------------------------------*/
#include <core_cm0plus.h>



/**
  * @brief SYSCFG Base Address Definition
  */
#define  SYSCFG_BASE                               0x40010000                                       /*!<Base Address: 0x40010000*/

/**
  * @brief SYSCFG Register Structure Definition
  */
typedef struct
{
    __IO uint32_t CFGR;                           /*!<SYSCFG SYSCFG configuration register 1         offset: 0x00*/
    __IO uint32_t RESERVED0x004[1];               /*!<                                               offset: 0x4*/
    __IO uint32_t EXTICR1;                        /*!<SYSCFG SYSCFG external interrupt configuration register 1 offset: 0x08*/
    __IO uint32_t EXTICR2;                        /*!<SYSCFG SYSCFG external interrupt configuration register 2 offset: 0x0C*/
    __IO uint32_t EXTICR3;                        /*!<SYSCFG SYSCFG external interrupt configuration register 3 offset: 0x10*/
    __IO uint32_t EXTICR4;                        /*!<SYSCFG SYSCFG external interrupt configuration register 4 offset: 0x14*/
    __IO uint32_t PADHYS;                         /*!<SYSCFG SYSCFG PAD configuration register       offset: 0x18*/
    __IO uint32_t PDETCSR;                        /*!<SYSCFG SYSCFG power detect register            offset: 0x1C*/
} SYSCFG_TypeDef;

/**
  * @brief SYSCFG type pointer Definition
  */
#define SYSCFG                                    ((SYSCFG_TypeDef *)SYSCFG_BASE)

/**
  * @brief SYSCFG_CFGR Register Bit Definition
  */
#define  SYSCFG_CFGR_MEM_MODE_Pos                 (0)
#define  SYSCFG_CFGR_MEM_MODE_Msk                 (0x03U << SYSCFG_CFGR_MEM_MODE_Pos)               /*!<Memory selection Bit*/

/**
  * @brief SYSCFG_EXTICR1 Register Bit Definition
  */
#define  SYSCFG_EXTICR1_EXTIx_Pos                 (0)
#define  SYSCFG_EXTICR1_EXTIx_Msk                 (0xFFFFU << SYSCFG_EXTICR1_EXTIx_Pos)             /*!<EXTIx configuration(x=0 ,,,3)*/

/**
  * @brief SYSCFG_EXTICR2 Register Bit Definition
  */
#define  SYSCFG_EXTICR2_EXTIx_Pos                 (0)
#define  SYSCFG_EXTICR2_EXTIx_Msk                 (0xFFFFU << SYSCFG_EXTICR2_EXTIx_Pos)             /*!<EXTIx configuration(x=4 ,,,7)*/

/**
  * @brief SYSCFG_EXTICR3 Register Bit Definition
  */
#define  SYSCFG_EXTICR3_EXTIx_Pos                 (0)
#define  SYSCFG_EXTICR3_EXTIx_Msk                 (0xFFFFU << SYSCFG_EXTICR3_EXTIx_Pos)             /*!<EXTIx configuration(x=8 ,,,11)*/

/**
  * @brief SYSCFG_EXTICR4 Register Bit Definition
  */
#define  SYSCFG_EXTICR4_EXTIx_Pos                 (0)
#define  SYSCFG_EXTICR4_EXTIx_Msk                 (0xFFFFU << SYSCFG_EXTICR4_EXTIx_Pos)             /*!<EXTIx configuration(x=12 ,,,15)*/

/**
  * @brief SYSCFG_PADHYS Register Bit Definition
  */
#define  SYSCFG_PADHYS_I2C1_MODE_SEL_Pos          (16)
#define  SYSCFG_PADHYS_I2C1_MODE_SEL_Msk          (0x01U << SYSCFG_PADHYS_I2C1_MODE_SEL_Pos)        /*!<I2C1 port mode selection bit*/

/**
  * @brief SYSCFG_PDETCSR Register Bit Definition
  */
#define  SYSCFG_PDETCSR_PVDE_Pos                  (0)
#define  SYSCFG_PDETCSR_PVDE_Msk                  (0x01U << SYSCFG_PDETCSR_PVDE_Pos)                /*!<PVD enable bit*/
#define  SYSCFG_PDETCSR_PLS_Pos                   (1)
#define  SYSCFG_PDETCSR_PLS_Msk                   (0x0FU << SYSCFG_PDETCSR_PLS_Pos)                 /*!<PVD threshold voltage selection*/
#define  SYSCFG_PDETCSR_PVDO_Pos                  (5)
#define  SYSCFG_PDETCSR_PVDO_Msk                  (0x01U << SYSCFG_PDETCSR_PVDO_Pos)                /*!<PVD output status*/
#define  SYSCFG_PDETCSR_VBATDIV3_EN_Pos           (11)
#define  SYSCFG_PDETCSR_VBATDIV3_EN_Msk           (0x01U << SYSCFG_PDETCSR_VBATDIV3_EN_Pos)         /*!<VBATDIV3 enable bit*/


#endif

