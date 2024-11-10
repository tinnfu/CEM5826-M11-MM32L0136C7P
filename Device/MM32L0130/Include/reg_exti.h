/***********************************************************************************************************************
    @file     reg_exti.h
    @author   VV TEAM
    @brief    This flie contains all the EXTI's register and its field definition.
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

#ifndef __REG_EXTI_H
#define __REG_EXTI_H


/* Files includes ----------------------------------------------------------------------------------------------------*/
#include <core_cm0plus.h>



/**
  * @brief EXTI Base Address Definition
  */
#define  EXTI_BASE                                 0x40010400                                       /*!<Base Address: 0x40010400*/

/**
  * @brief EXTI Register Structure Definition
  */
typedef struct
{
    __IO uint32_t IMR;                            /*!<EXTI Interrupt mask register                   offset: 0x00*/
    __IO uint32_t EMR;                            /*!<EXTI Event mask register                       offset: 0x04*/
    __IO uint32_t RTSR;                           /*!<EXTI Rising edge trigger selection register    offset: 0x08*/
    __IO uint32_t FTSR;                           /*!<EXTI Falling edge trigger selection register   offset: 0x0C*/
    __IO uint32_t SWIER;                          /*!<EXTI Software interrupt event register         offset: 0x10*/
    __IO uint32_t PR;                             /*!<EXTI Pending register                          offset: 0x14*/
} EXTI_TypeDef;

/**
  * @brief EXTI type pointer Definition
  */
#define EXTI                                      ((EXTI_TypeDef *)EXTI_BASE)

/**
  * @brief EXTI_IMR Register Bit Definition
  */
#define  EXTI_IMR_IMR0_Pos                        (0)
#define  EXTI_IMR_IMR0_Msk                        (0x01U << EXTI_IMR_IMR0_Pos)                      /*!<interrupt enable bit*/
#define  EXTI_IMR_IMR1_Pos                        (1)
#define  EXTI_IMR_IMR1_Msk                        (0x01U << EXTI_IMR_IMR1_Pos)                      /*!<interrupt enable bit*/
#define  EXTI_IMR_IMR2_Pos                        (2)
#define  EXTI_IMR_IMR2_Msk                        (0x01U << EXTI_IMR_IMR2_Pos)                      /*!<interrupt enable bit*/
#define  EXTI_IMR_IMR3_Pos                        (3)
#define  EXTI_IMR_IMR3_Msk                        (0x01U << EXTI_IMR_IMR3_Pos)                      /*!<interrupt enable bit*/
#define  EXTI_IMR_IMR4_Pos                        (4)
#define  EXTI_IMR_IMR4_Msk                        (0x01U << EXTI_IMR_IMR4_Pos)                      /*!<interrupt enable bit*/
#define  EXTI_IMR_IMR5_Pos                        (5)
#define  EXTI_IMR_IMR5_Msk                        (0x01U << EXTI_IMR_IMR5_Pos)                      /*!<interrupt enable bit*/
#define  EXTI_IMR_IMR6_Pos                        (6)
#define  EXTI_IMR_IMR6_Msk                        (0x01U << EXTI_IMR_IMR6_Pos)                      /*!<interrupt enable bit*/
#define  EXTI_IMR_IMR7_Pos                        (7)
#define  EXTI_IMR_IMR7_Msk                        (0x01U << EXTI_IMR_IMR7_Pos)                      /*!<interrupt enable bit*/
#define  EXTI_IMR_IMR8_Pos                        (8)
#define  EXTI_IMR_IMR8_Msk                        (0x01U << EXTI_IMR_IMR8_Pos)                      /*!<interrupt enable bit*/
#define  EXTI_IMR_IMR9_Pos                        (9)
#define  EXTI_IMR_IMR9_Msk                        (0x01U << EXTI_IMR_IMR9_Pos)                      /*!<interrupt enable bit*/
#define  EXTI_IMR_IMR10_Pos                       (10)
#define  EXTI_IMR_IMR10_Msk                       (0x01U << EXTI_IMR_IMR10_Pos)                     /*!<interrupt enable bit*/
#define  EXTI_IMR_IMR11_Pos                       (11)
#define  EXTI_IMR_IMR11_Msk                       (0x01U << EXTI_IMR_IMR11_Pos)                     /*!<interrupt enable bit*/
#define  EXTI_IMR_IMR12_Pos                       (12)
#define  EXTI_IMR_IMR12_Msk                       (0x01U << EXTI_IMR_IMR12_Pos)                     /*!<interrupt enable bit*/
#define  EXTI_IMR_IMR13_Pos                       (13)
#define  EXTI_IMR_IMR13_Msk                       (0x01U << EXTI_IMR_IMR13_Pos)                     /*!<interrupt enable bit*/
#define  EXTI_IMR_IMR14_Pos                       (14)
#define  EXTI_IMR_IMR14_Msk                       (0x01U << EXTI_IMR_IMR14_Pos)                     /*!<interrupt enable bit*/
#define  EXTI_IMR_IMR15_Pos                       (15)
#define  EXTI_IMR_IMR15_Msk                       (0x01U << EXTI_IMR_IMR15_Pos)                     /*!<interrupt enable bit*/
#define  EXTI_IMR_IMR16_Pos                       (16)
#define  EXTI_IMR_IMR16_Msk                       (0x01U << EXTI_IMR_IMR16_Pos)                     /*!<interrupt enable bit*/
#define  EXTI_IMR_IMR17_Pos                       (17)
#define  EXTI_IMR_IMR17_Msk                       (0x01U << EXTI_IMR_IMR17_Pos)                     /*!<interrupt enable bit*/
#define  EXTI_IMR_IMR18_Pos                       (18)
#define  EXTI_IMR_IMR18_Msk                       (0x01U << EXTI_IMR_IMR18_Pos)                     /*!<interrupt enable bit*/
#define  EXTI_IMR_IMR19_Pos                       (19)
#define  EXTI_IMR_IMR19_Msk                       (0x01U << EXTI_IMR_IMR19_Pos)                     /*!<interrupt enable bit*/
#define  EXTI_IMR_IMR20_Pos                       (20)
#define  EXTI_IMR_IMR20_Msk                       (0x01U << EXTI_IMR_IMR20_Pos)                     /*!<interrupt enable bit*/
#define  EXTI_IMR_IMR21_Pos                       (21)
#define  EXTI_IMR_IMR21_Msk                       (0x01U << EXTI_IMR_IMR21_Pos)                     /*!<interrupt enable bit*/
#define  EXTI_IMR_IMR22_Pos                       (22)
#define  EXTI_IMR_IMR22_Msk                       (0x01U << EXTI_IMR_IMR22_Pos)                     /*!<interrupt enable bit*/
#define  EXTI_IMR_IMR23_Pos                       (23)
#define  EXTI_IMR_IMR23_Msk                       (0x01U << EXTI_IMR_IMR23_Pos)                     /*!<interrupt enable bit*/
#define  EXTI_IMR_IMR24_Pos                       (24)
#define  EXTI_IMR_IMR24_Msk                       (0x01U << EXTI_IMR_IMR24_Pos)                     /*!<interrupt enable bit*/
#define  EXTI_IMR_IMR25_Pos                       (25)
#define  EXTI_IMR_IMR25_Msk                       (0x01U << EXTI_IMR_IMR25_Pos)                     /*!<interrupt enable bit*/
#define  EXTI_IMR_IMR26_Pos                       (26)
#define  EXTI_IMR_IMR26_Msk                       (0x01U << EXTI_IMR_IMR26_Pos)                     /*!<interrupt enable bit*/
#define  EXTI_IMR_IMR27_Pos                       (27)
#define  EXTI_IMR_IMR27_Msk                       (0x01U << EXTI_IMR_IMR27_Pos)                     /*!<interrupt enable bit*/
#define  EXTI_IMR_IMR28_Pos                       (28)
#define  EXTI_IMR_IMR28_Msk                       (0x01U << EXTI_IMR_IMR28_Pos)                     /*!<interrupt enable bit*/
#define  EXTI_IMR_IMR29_Pos                       (29)
#define  EXTI_IMR_IMR29_Msk                       (0x01U << EXTI_IMR_IMR29_Pos)                     /*!<interrupt enable bit*/
#define  EXTI_IMR_IMR30_Pos                       (30)
#define  EXTI_IMR_IMR30_Msk                       (0x01U << EXTI_IMR_IMR30_Pos)                     /*!<interrupt enable bit*/
#define  EXTI_IMR_IMR31_Pos                       (31)
#define  EXTI_IMR_IMR31_Msk                       (0x01U << EXTI_IMR_IMR31_Pos)                     /*!<interrupt enable bit*/

/**
  * @brief EXTI_EMR Register Bit Definition
  */
#define  EXTI_EMR_EMR0_Pos                        (0)
#define  EXTI_EMR_EMR0_Msk                        (0x01U << EXTI_EMR_EMR0_Pos)                      /*!<event enable bit*/
#define  EXTI_EMR_EMR1_Pos                        (1)
#define  EXTI_EMR_EMR1_Msk                        (0x01U << EXTI_EMR_EMR1_Pos)                      /*!<event enable bit*/
#define  EXTI_EMR_EMR2_Pos                        (2)
#define  EXTI_EMR_EMR2_Msk                        (0x01U << EXTI_EMR_EMR2_Pos)                      /*!<event enable bit*/
#define  EXTI_EMR_EMR3_Pos                        (3)
#define  EXTI_EMR_EMR3_Msk                        (0x01U << EXTI_EMR_EMR3_Pos)                      /*!<event enable bit*/
#define  EXTI_EMR_EMR4_Pos                        (4)
#define  EXTI_EMR_EMR4_Msk                        (0x01U << EXTI_EMR_EMR4_Pos)                      /*!<event enable bit*/
#define  EXTI_EMR_EMR5_Pos                        (5)
#define  EXTI_EMR_EMR5_Msk                        (0x01U << EXTI_EMR_EMR5_Pos)                      /*!<event enable bit*/
#define  EXTI_EMR_EMR6_Pos                        (6)
#define  EXTI_EMR_EMR6_Msk                        (0x01U << EXTI_EMR_EMR6_Pos)                      /*!<event enable bit*/
#define  EXTI_EMR_EMR7_Pos                        (7)
#define  EXTI_EMR_EMR7_Msk                        (0x01U << EXTI_EMR_EMR7_Pos)                      /*!<event enable bit*/
#define  EXTI_EMR_EMR8_Pos                        (8)
#define  EXTI_EMR_EMR8_Msk                        (0x01U << EXTI_EMR_EMR8_Pos)                      /*!<event enable bit*/
#define  EXTI_EMR_EMR9_Pos                        (9)
#define  EXTI_EMR_EMR9_Msk                        (0x01U << EXTI_EMR_EMR9_Pos)                      /*!<event enable bit*/
#define  EXTI_EMR_EMR10_Pos                       (10)
#define  EXTI_EMR_EMR10_Msk                       (0x01U << EXTI_EMR_EMR10_Pos)                     /*!<event enable bit*/
#define  EXTI_EMR_EMR11_Pos                       (11)
#define  EXTI_EMR_EMR11_Msk                       (0x01U << EXTI_EMR_EMR11_Pos)                     /*!<event enable bit*/
#define  EXTI_EMR_EMR12_Pos                       (12)
#define  EXTI_EMR_EMR12_Msk                       (0x01U << EXTI_EMR_EMR12_Pos)                     /*!<event enable bit*/
#define  EXTI_EMR_EMR13_Pos                       (13)
#define  EXTI_EMR_EMR13_Msk                       (0x01U << EXTI_EMR_EMR13_Pos)                     /*!<event enable bit*/
#define  EXTI_EMR_EMR14_Pos                       (14)
#define  EXTI_EMR_EMR14_Msk                       (0x01U << EXTI_EMR_EMR14_Pos)                     /*!<event enable bit*/
#define  EXTI_EMR_EMR15_Pos                       (15)
#define  EXTI_EMR_EMR15_Msk                       (0x01U << EXTI_EMR_EMR15_Pos)                     /*!<event enable bit*/
#define  EXTI_EMR_EMR16_Pos                       (16)
#define  EXTI_EMR_EMR16_Msk                       (0x01U << EXTI_EMR_EMR16_Pos)                     /*!<event enable bit*/
#define  EXTI_EMR_EMR17_Pos                       (17)
#define  EXTI_EMR_EMR17_Msk                       (0x01U << EXTI_EMR_EMR17_Pos)                     /*!<event enable bit*/
#define  EXTI_EMR_EMR18_Pos                       (18)
#define  EXTI_EMR_EMR18_Msk                       (0x01U << EXTI_EMR_EMR18_Pos)                     /*!<event enable bit*/
#define  EXTI_EMR_EMR19_Pos                       (19)
#define  EXTI_EMR_EMR19_Msk                       (0x01U << EXTI_EMR_EMR19_Pos)                     /*!<event enable bit*/
#define  EXTI_EMR_EMR20_Pos                       (20)
#define  EXTI_EMR_EMR20_Msk                       (0x01U << EXTI_EMR_EMR20_Pos)                     /*!<event enable bit*/
#define  EXTI_EMR_EMR21_Pos                       (21)
#define  EXTI_EMR_EMR21_Msk                       (0x01U << EXTI_EMR_EMR21_Pos)                     /*!<event enable bit*/
#define  EXTI_EMR_EMR22_Pos                       (22)
#define  EXTI_EMR_EMR22_Msk                       (0x01U << EXTI_EMR_EMR22_Pos)                     /*!<event enable bit*/
#define  EXTI_EMR_EMR23_Pos                       (23)
#define  EXTI_EMR_EMR23_Msk                       (0x01U << EXTI_EMR_EMR23_Pos)                     /*!<event enable bit*/
#define  EXTI_EMR_EMR24_Pos                       (24)
#define  EXTI_EMR_EMR24_Msk                       (0x01U << EXTI_EMR_EMR24_Pos)                     /*!<event enable bit*/
#define  EXTI_EMR_EMR25_Pos                       (25)
#define  EXTI_EMR_EMR25_Msk                       (0x01U << EXTI_EMR_EMR25_Pos)                     /*!<event enable bit*/
#define  EXTI_EMR_EMR26_Pos                       (26)
#define  EXTI_EMR_EMR26_Msk                       (0x01U << EXTI_EMR_EMR26_Pos)                     /*!<event enable bit*/
#define  EXTI_EMR_EMR27_Pos                       (27)
#define  EXTI_EMR_EMR27_Msk                       (0x01U << EXTI_EMR_EMR27_Pos)                     /*!<event enable bit*/
#define  EXTI_EMR_EMR28_Pos                       (28)
#define  EXTI_EMR_EMR28_Msk                       (0x01U << EXTI_EMR_EMR28_Pos)                     /*!<event enable bit*/
#define  EXTI_EMR_EMR29_Pos                       (29)
#define  EXTI_EMR_EMR29_Msk                       (0x01U << EXTI_EMR_EMR29_Pos)                     /*!<event enable bit*/
#define  EXTI_EMR_EMR30_Pos                       (30)
#define  EXTI_EMR_EMR30_Msk                       (0x01U << EXTI_EMR_EMR30_Pos)                     /*!<event enable bit*/
#define  EXTI_EMR_EMR31_Pos                       (31)
#define  EXTI_EMR_EMR31_Msk                       (0x01U << EXTI_EMR_EMR31_Pos)                     /*!<event enable bit*/

/**
  * @brief EXTI_RTSR Register Bit Definition
  */
#define  EXTI_RTSR_TR0_Pos                        (0)
#define  EXTI_RTSR_TR0_Msk                        (0x01U << EXTI_RTSR_TR0_Pos)                      /*!<interrupt or event trigger polarity*/
#define  EXTI_RTSR_TR1_Pos                        (1)
#define  EXTI_RTSR_TR1_Msk                        (0x01U << EXTI_RTSR_TR1_Pos)                      /*!<interrupt or event trigger polarity*/
#define  EXTI_RTSR_TR2_Pos                        (2)
#define  EXTI_RTSR_TR2_Msk                        (0x01U << EXTI_RTSR_TR2_Pos)                      /*!<interrupt or event trigger polarity*/
#define  EXTI_RTSR_TR3_Pos                        (3)
#define  EXTI_RTSR_TR3_Msk                        (0x01U << EXTI_RTSR_TR3_Pos)                      /*!<interrupt or event trigger polarity*/
#define  EXTI_RTSR_TR4_Pos                        (4)
#define  EXTI_RTSR_TR4_Msk                        (0x01U << EXTI_RTSR_TR4_Pos)                      /*!<interrupt or event trigger polarity*/
#define  EXTI_RTSR_TR5_Pos                        (5)
#define  EXTI_RTSR_TR5_Msk                        (0x01U << EXTI_RTSR_TR5_Pos)                      /*!<interrupt or event trigger polarity*/
#define  EXTI_RTSR_TR6_Pos                        (6)
#define  EXTI_RTSR_TR6_Msk                        (0x01U << EXTI_RTSR_TR6_Pos)                      /*!<interrupt or event trigger polarity*/
#define  EXTI_RTSR_TR7_Pos                        (7)
#define  EXTI_RTSR_TR7_Msk                        (0x01U << EXTI_RTSR_TR7_Pos)                      /*!<interrupt or event trigger polarity*/
#define  EXTI_RTSR_TR8_Pos                        (8)
#define  EXTI_RTSR_TR8_Msk                        (0x01U << EXTI_RTSR_TR8_Pos)                      /*!<interrupt or event trigger polarity*/
#define  EXTI_RTSR_TR9_Pos                        (9)
#define  EXTI_RTSR_TR9_Msk                        (0x01U << EXTI_RTSR_TR9_Pos)                      /*!<interrupt or event trigger polarity*/
#define  EXTI_RTSR_TR10_Pos                       (10)
#define  EXTI_RTSR_TR10_Msk                       (0x01U << EXTI_RTSR_TR10_Pos)                     /*!<interrupt or event trigger polarity*/
#define  EXTI_RTSR_TR11_Pos                       (11)
#define  EXTI_RTSR_TR11_Msk                       (0x01U << EXTI_RTSR_TR11_Pos)                     /*!<interrupt or event trigger polarity*/
#define  EXTI_RTSR_TR12_Pos                       (12)
#define  EXTI_RTSR_TR12_Msk                       (0x01U << EXTI_RTSR_TR12_Pos)                     /*!<interrupt or event trigger polarity*/
#define  EXTI_RTSR_TR13_Pos                       (13)
#define  EXTI_RTSR_TR13_Msk                       (0x01U << EXTI_RTSR_TR13_Pos)                     /*!<interrupt or event trigger polarity*/
#define  EXTI_RTSR_TR14_Pos                       (14)
#define  EXTI_RTSR_TR14_Msk                       (0x01U << EXTI_RTSR_TR14_Pos)                     /*!<interrupt or event trigger polarity*/
#define  EXTI_RTSR_TR15_Pos                       (15)
#define  EXTI_RTSR_TR15_Msk                       (0x01U << EXTI_RTSR_TR15_Pos)                     /*!<interrupt or event trigger polarity*/
#define  EXTI_RTSR_TR16_Pos                       (16)
#define  EXTI_RTSR_TR16_Msk                       (0x01U << EXTI_RTSR_TR16_Pos)                     /*!<interrupt or event trigger polarity*/
#define  EXTI_RTSR_TR17_Pos                       (17)
#define  EXTI_RTSR_TR17_Msk                       (0x01U << EXTI_RTSR_TR17_Pos)                     /*!<interrupt or event trigger polarity*/
#define  EXTI_RTSR_TR18_Pos                       (18)
#define  EXTI_RTSR_TR18_Msk                       (0x01U << EXTI_RTSR_TR18_Pos)                     /*!<interrupt or event trigger polarity*/
#define  EXTI_RTSR_TR19_Pos                       (19)
#define  EXTI_RTSR_TR19_Msk                       (0x01U << EXTI_RTSR_TR19_Pos)                     /*!<interrupt or event trigger polarity*/
#define  EXTI_RTSR_TR20_Pos                       (20)
#define  EXTI_RTSR_TR20_Msk                       (0x01U << EXTI_RTSR_TR20_Pos)                     /*!<interrupt or event trigger polarity*/
#define  EXTI_RTSR_TR21_Pos                       (21)
#define  EXTI_RTSR_TR21_Msk                       (0x01U << EXTI_RTSR_TR21_Pos)                     /*!<interrupt or event trigger polarity*/
#define  EXTI_RTSR_TR22_Pos                       (22)
#define  EXTI_RTSR_TR22_Msk                       (0x01U << EXTI_RTSR_TR22_Pos)                     /*!<interrupt or event trigger polarity*/
#define  EXTI_RTSR_TR23_Pos                       (23)
#define  EXTI_RTSR_TR23_Msk                       (0x01U << EXTI_RTSR_TR23_Pos)                     /*!<interrupt or event trigger polarity*/
#define  EXTI_RTSR_TR24_Pos                       (24)
#define  EXTI_RTSR_TR24_Msk                       (0x01U << EXTI_RTSR_TR24_Pos)                     /*!<interrupt or event trigger polarity*/
#define  EXTI_RTSR_TR25_Pos                       (25)
#define  EXTI_RTSR_TR25_Msk                       (0x01U << EXTI_RTSR_TR25_Pos)                     /*!<interrupt or event trigger polarity*/
#define  EXTI_RTSR_TR26_Pos                       (26)
#define  EXTI_RTSR_TR26_Msk                       (0x01U << EXTI_RTSR_TR26_Pos)                     /*!<interrupt or event trigger polarity*/
#define  EXTI_RTSR_TR27_Pos                       (27)
#define  EXTI_RTSR_TR27_Msk                       (0x01U << EXTI_RTSR_TR27_Pos)                     /*!<interrupt or event trigger polarity*/
#define  EXTI_RTSR_TR28_Pos                       (28)
#define  EXTI_RTSR_TR28_Msk                       (0x01U << EXTI_RTSR_TR28_Pos)                     /*!<interrupt or event trigger polarity*/
#define  EXTI_RTSR_TR29_Pos                       (29)
#define  EXTI_RTSR_TR29_Msk                       (0x01U << EXTI_RTSR_TR29_Pos)                     /*!<interrupt or event trigger polarity*/
#define  EXTI_RTSR_TR30_Pos                       (30)
#define  EXTI_RTSR_TR30_Msk                       (0x01U << EXTI_RTSR_TR30_Pos)                     /*!<interrupt or event trigger polarity*/
#define  EXTI_RTSR_TR31_Pos                       (31)
#define  EXTI_RTSR_TR31_Msk                       (0x01U << EXTI_RTSR_TR31_Pos)                     /*!<interrupt or event trigger polarity*/

/**
  * @brief EXTI_FTSR Register Bit Definition
  */
#define  EXTI_FTSR_TR0_Pos                        (0)
#define  EXTI_FTSR_TR0_Msk                        (0x01U << EXTI_FTSR_TR0_Pos)                      /*!<interrupt or event trigger polarity*/
#define  EXTI_FTSR_TR1_Pos                        (1)
#define  EXTI_FTSR_TR1_Msk                        (0x01U << EXTI_FTSR_TR1_Pos)                      /*!<interrupt or event trigger polarity*/
#define  EXTI_FTSR_TR2_Pos                        (2)
#define  EXTI_FTSR_TR2_Msk                        (0x01U << EXTI_FTSR_TR2_Pos)                      /*!<interrupt or event trigger polarity*/
#define  EXTI_FTSR_TR3_Pos                        (3)
#define  EXTI_FTSR_TR3_Msk                        (0x01U << EXTI_FTSR_TR3_Pos)                      /*!<interrupt or event trigger polarity*/
#define  EXTI_FTSR_TR4_Pos                        (4)
#define  EXTI_FTSR_TR4_Msk                        (0x01U << EXTI_FTSR_TR4_Pos)                      /*!<interrupt or event trigger polarity*/
#define  EXTI_FTSR_TR5_Pos                        (5)
#define  EXTI_FTSR_TR5_Msk                        (0x01U << EXTI_FTSR_TR5_Pos)                      /*!<interrupt or event trigger polarity*/
#define  EXTI_FTSR_TR6_Pos                        (6)
#define  EXTI_FTSR_TR6_Msk                        (0x01U << EXTI_FTSR_TR6_Pos)                      /*!<interrupt or event trigger polarity*/
#define  EXTI_FTSR_TR7_Pos                        (7)
#define  EXTI_FTSR_TR7_Msk                        (0x01U << EXTI_FTSR_TR7_Pos)                      /*!<interrupt or event trigger polarity*/
#define  EXTI_FTSR_TR8_Pos                        (8)
#define  EXTI_FTSR_TR8_Msk                        (0x01U << EXTI_FTSR_TR8_Pos)                      /*!<interrupt or event trigger polarity*/
#define  EXTI_FTSR_TR9_Pos                        (9)
#define  EXTI_FTSR_TR9_Msk                        (0x01U << EXTI_FTSR_TR9_Pos)                      /*!<interrupt or event trigger polarity*/
#define  EXTI_FTSR_TR10_Pos                       (10)
#define  EXTI_FTSR_TR10_Msk                       (0x01U << EXTI_FTSR_TR10_Pos)                     /*!<interrupt or event trigger polarity*/
#define  EXTI_FTSR_TR11_Pos                       (11)
#define  EXTI_FTSR_TR11_Msk                       (0x01U << EXTI_FTSR_TR11_Pos)                     /*!<interrupt or event trigger polarity*/
#define  EXTI_FTSR_TR12_Pos                       (12)
#define  EXTI_FTSR_TR12_Msk                       (0x01U << EXTI_FTSR_TR12_Pos)                     /*!<interrupt or event trigger polarity*/
#define  EXTI_FTSR_TR13_Pos                       (13)
#define  EXTI_FTSR_TR13_Msk                       (0x01U << EXTI_FTSR_TR13_Pos)                     /*!<interrupt or event trigger polarity*/
#define  EXTI_FTSR_TR14_Pos                       (14)
#define  EXTI_FTSR_TR14_Msk                       (0x01U << EXTI_FTSR_TR14_Pos)                     /*!<interrupt or event trigger polarity*/
#define  EXTI_FTSR_TR15_Pos                       (15)
#define  EXTI_FTSR_TR15_Msk                       (0x01U << EXTI_FTSR_TR15_Pos)                     /*!<interrupt or event trigger polarity*/
#define  EXTI_FTSR_TR16_Pos                       (16)
#define  EXTI_FTSR_TR16_Msk                       (0x01U << EXTI_FTSR_TR16_Pos)                     /*!<interrupt or event trigger polarity*/
#define  EXTI_FTSR_TR17_Pos                       (17)
#define  EXTI_FTSR_TR17_Msk                       (0x01U << EXTI_FTSR_TR17_Pos)                     /*!<interrupt or event trigger polarity*/
#define  EXTI_FTSR_TR18_Pos                       (18)
#define  EXTI_FTSR_TR18_Msk                       (0x01U << EXTI_FTSR_TR18_Pos)                     /*!<interrupt or event trigger polarity*/
#define  EXTI_FTSR_TR19_Pos                       (19)
#define  EXTI_FTSR_TR19_Msk                       (0x01U << EXTI_FTSR_TR19_Pos)                     /*!<interrupt or event trigger polarity*/
#define  EXTI_FTSR_TR20_Pos                       (20)
#define  EXTI_FTSR_TR20_Msk                       (0x01U << EXTI_FTSR_TR20_Pos)                     /*!<interrupt or event trigger polarity*/
#define  EXTI_FTSR_TR21_Pos                       (21)
#define  EXTI_FTSR_TR21_Msk                       (0x01U << EXTI_FTSR_TR21_Pos)                     /*!<interrupt or event trigger polarity*/
#define  EXTI_FTSR_TR22_Pos                       (22)
#define  EXTI_FTSR_TR22_Msk                       (0x01U << EXTI_FTSR_TR22_Pos)                     /*!<interrupt or event trigger polarity*/
#define  EXTI_FTSR_TR23_Pos                       (23)
#define  EXTI_FTSR_TR23_Msk                       (0x01U << EXTI_FTSR_TR23_Pos)                     /*!<interrupt or event trigger polarity*/
#define  EXTI_FTSR_TR24_Pos                       (24)
#define  EXTI_FTSR_TR24_Msk                       (0x01U << EXTI_FTSR_TR24_Pos)                     /*!<interrupt or event trigger polarity*/
#define  EXTI_FTSR_TR25_Pos                       (25)
#define  EXTI_FTSR_TR25_Msk                       (0x01U << EXTI_FTSR_TR25_Pos)                     /*!<interrupt or event trigger polarity*/
#define  EXTI_FTSR_TR26_Pos                       (26)
#define  EXTI_FTSR_TR26_Msk                       (0x01U << EXTI_FTSR_TR26_Pos)                     /*!<interrupt or event trigger polarity*/
#define  EXTI_FTSR_TR27_Pos                       (27)
#define  EXTI_FTSR_TR27_Msk                       (0x01U << EXTI_FTSR_TR27_Pos)                     /*!<interrupt or event trigger polarity*/
#define  EXTI_FTSR_TR28_Pos                       (28)
#define  EXTI_FTSR_TR28_Msk                       (0x01U << EXTI_FTSR_TR28_Pos)                     /*!<interrupt or event trigger polarity*/
#define  EXTI_FTSR_TR29_Pos                       (29)
#define  EXTI_FTSR_TR29_Msk                       (0x01U << EXTI_FTSR_TR29_Pos)                     /*!<interrupt or event trigger polarity*/
#define  EXTI_FTSR_TR30_Pos                       (30)
#define  EXTI_FTSR_TR30_Msk                       (0x01U << EXTI_FTSR_TR30_Pos)                     /*!<interrupt or event trigger polarity*/
#define  EXTI_FTSR_TR31_Pos                       (31)
#define  EXTI_FTSR_TR31_Msk                       (0x01U << EXTI_FTSR_TR31_Pos)                     /*!<interrupt or event trigger polarity*/

/**
  * @brief EXTI_SWIER Register Bit Definition
  */
#define  EXTI_SWIER_SWIER0_Pos                    (0)
#define  EXTI_SWIER_SWIER0_Msk                    (0x01U << EXTI_SWIER_SWIER0_Pos)                  /*!<software interrupt or event enable*/
#define  EXTI_SWIER_SWIER1_Pos                    (1)
#define  EXTI_SWIER_SWIER1_Msk                    (0x01U << EXTI_SWIER_SWIER1_Pos)                  /*!<software interrupt or event enable*/
#define  EXTI_SWIER_SWIER2_Pos                    (2)
#define  EXTI_SWIER_SWIER2_Msk                    (0x01U << EXTI_SWIER_SWIER2_Pos)                  /*!<software interrupt or event enable*/
#define  EXTI_SWIER_SWIER3_Pos                    (3)
#define  EXTI_SWIER_SWIER3_Msk                    (0x01U << EXTI_SWIER_SWIER3_Pos)                  /*!<software interrupt or event enable*/
#define  EXTI_SWIER_SWIER4_Pos                    (4)
#define  EXTI_SWIER_SWIER4_Msk                    (0x01U << EXTI_SWIER_SWIER4_Pos)                  /*!<software interrupt or event enable*/
#define  EXTI_SWIER_SWIER5_Pos                    (5)
#define  EXTI_SWIER_SWIER5_Msk                    (0x01U << EXTI_SWIER_SWIER5_Pos)                  /*!<software interrupt or event enable*/
#define  EXTI_SWIER_SWIER6_Pos                    (6)
#define  EXTI_SWIER_SWIER6_Msk                    (0x01U << EXTI_SWIER_SWIER6_Pos)                  /*!<software interrupt or event enable*/
#define  EXTI_SWIER_SWIER7_Pos                    (7)
#define  EXTI_SWIER_SWIER7_Msk                    (0x01U << EXTI_SWIER_SWIER7_Pos)                  /*!<software interrupt or event enable*/
#define  EXTI_SWIER_SWIER8_Pos                    (8)
#define  EXTI_SWIER_SWIER8_Msk                    (0x01U << EXTI_SWIER_SWIER8_Pos)                  /*!<software interrupt or event enable*/
#define  EXTI_SWIER_SWIER9_Pos                    (9)
#define  EXTI_SWIER_SWIER9_Msk                    (0x01U << EXTI_SWIER_SWIER9_Pos)                  /*!<software interrupt or event enable*/
#define  EXTI_SWIER_SWIER10_Pos                   (10)
#define  EXTI_SWIER_SWIER10_Msk                   (0x01U << EXTI_SWIER_SWIER10_Pos)                 /*!<software interrupt or event enable*/
#define  EXTI_SWIER_SWIER11_Pos                   (11)
#define  EXTI_SWIER_SWIER11_Msk                   (0x01U << EXTI_SWIER_SWIER11_Pos)                 /*!<software interrupt or event enable*/
#define  EXTI_SWIER_SWIER12_Pos                   (12)
#define  EXTI_SWIER_SWIER12_Msk                   (0x01U << EXTI_SWIER_SWIER12_Pos)                 /*!<software interrupt or event enable*/
#define  EXTI_SWIER_SWIER13_Pos                   (13)
#define  EXTI_SWIER_SWIER13_Msk                   (0x01U << EXTI_SWIER_SWIER13_Pos)                 /*!<software interrupt or event enable*/
#define  EXTI_SWIER_SWIER14_Pos                   (14)
#define  EXTI_SWIER_SWIER14_Msk                   (0x01U << EXTI_SWIER_SWIER14_Pos)                 /*!<software interrupt or event enable*/
#define  EXTI_SWIER_SWIER15_Pos                   (15)
#define  EXTI_SWIER_SWIER15_Msk                   (0x01U << EXTI_SWIER_SWIER15_Pos)                 /*!<software interrupt or event enable*/
#define  EXTI_SWIER_SWIER16_Pos                   (16)
#define  EXTI_SWIER_SWIER16_Msk                   (0x01U << EXTI_SWIER_SWIER16_Pos)                 /*!<software interrupt or event enable*/
#define  EXTI_SWIER_SWIER17_Pos                   (17)
#define  EXTI_SWIER_SWIER17_Msk                   (0x01U << EXTI_SWIER_SWIER17_Pos)                 /*!<software interrupt or event enable*/
#define  EXTI_SWIER_SWIER18_Pos                   (18)
#define  EXTI_SWIER_SWIER18_Msk                   (0x01U << EXTI_SWIER_SWIER18_Pos)                 /*!<software interrupt or event enable*/
#define  EXTI_SWIER_SWIER19_Pos                   (19)
#define  EXTI_SWIER_SWIER19_Msk                   (0x01U << EXTI_SWIER_SWIER19_Pos)                 /*!<software interrupt or event enable*/
#define  EXTI_SWIER_SWIER20_Pos                   (20)
#define  EXTI_SWIER_SWIER20_Msk                   (0x01U << EXTI_SWIER_SWIER20_Pos)                 /*!<software interrupt or event enable*/
#define  EXTI_SWIER_SWIER21_Pos                   (21)
#define  EXTI_SWIER_SWIER21_Msk                   (0x01U << EXTI_SWIER_SWIER21_Pos)                 /*!<software interrupt or event enable*/
#define  EXTI_SWIER_SWIER22_Pos                   (22)
#define  EXTI_SWIER_SWIER22_Msk                   (0x01U << EXTI_SWIER_SWIER22_Pos)                 /*!<software interrupt or event enable*/
#define  EXTI_SWIER_SWIER23_Pos                   (23)
#define  EXTI_SWIER_SWIER23_Msk                   (0x01U << EXTI_SWIER_SWIER23_Pos)                 /*!<software interrupt or event enable*/
#define  EXTI_SWIER_SWIER24_Pos                   (24)
#define  EXTI_SWIER_SWIER24_Msk                   (0x01U << EXTI_SWIER_SWIER24_Pos)                 /*!<software interrupt or event enable*/
#define  EXTI_SWIER_SWIER25_Pos                   (25)
#define  EXTI_SWIER_SWIER25_Msk                   (0x01U << EXTI_SWIER_SWIER25_Pos)                 /*!<software interrupt or event enable*/
#define  EXTI_SWIER_SWIER26_Pos                   (26)
#define  EXTI_SWIER_SWIER26_Msk                   (0x01U << EXTI_SWIER_SWIER26_Pos)                 /*!<software interrupt or event enable*/
#define  EXTI_SWIER_SWIER27_Pos                   (27)
#define  EXTI_SWIER_SWIER27_Msk                   (0x01U << EXTI_SWIER_SWIER27_Pos)                 /*!<software interrupt or event enable*/
#define  EXTI_SWIER_SWIER28_Pos                   (28)
#define  EXTI_SWIER_SWIER28_Msk                   (0x01U << EXTI_SWIER_SWIER28_Pos)                 /*!<software interrupt or event enable*/
#define  EXTI_SWIER_SWIER29_Pos                   (29)
#define  EXTI_SWIER_SWIER29_Msk                   (0x01U << EXTI_SWIER_SWIER29_Pos)                 /*!<software interrupt or event enable*/
#define  EXTI_SWIER_SWIER30_Pos                   (30)
#define  EXTI_SWIER_SWIER30_Msk                   (0x01U << EXTI_SWIER_SWIER30_Pos)                 /*!<software interrupt or event enable*/
#define  EXTI_SWIER_SWIER31_Pos                   (31)
#define  EXTI_SWIER_SWIER31_Msk                   (0x01U << EXTI_SWIER_SWIER31_Pos)                 /*!<software interrupt or event enable*/

/**
  * @brief EXTI_PR Register Bit Definition
  */
#define  EXTI_PR_PR0_Pos                          (0)
#define  EXTI_PR_PR0_Msk                          (0x01U << EXTI_PR_PR0_Pos)                        /*!<trigger pending bit*/
#define  EXTI_PR_PR1_Pos                          (1)
#define  EXTI_PR_PR1_Msk                          (0x01U << EXTI_PR_PR1_Pos)                        /*!<trigger pending bit*/
#define  EXTI_PR_PR2_Pos                          (2)
#define  EXTI_PR_PR2_Msk                          (0x01U << EXTI_PR_PR2_Pos)                        /*!<trigger pending bit*/
#define  EXTI_PR_PR3_Pos                          (3)
#define  EXTI_PR_PR3_Msk                          (0x01U << EXTI_PR_PR3_Pos)                        /*!<trigger pending bit*/
#define  EXTI_PR_PR4_Pos                          (4)
#define  EXTI_PR_PR4_Msk                          (0x01U << EXTI_PR_PR4_Pos)                        /*!<trigger pending bit*/
#define  EXTI_PR_PR5_Pos                          (5)
#define  EXTI_PR_PR5_Msk                          (0x01U << EXTI_PR_PR5_Pos)                        /*!<trigger pending bit*/
#define  EXTI_PR_PR6_Pos                          (6)
#define  EXTI_PR_PR6_Msk                          (0x01U << EXTI_PR_PR6_Pos)                        /*!<trigger pending bit*/
#define  EXTI_PR_PR7_Pos                          (7)
#define  EXTI_PR_PR7_Msk                          (0x01U << EXTI_PR_PR7_Pos)                        /*!<trigger pending bit*/
#define  EXTI_PR_PR8_Pos                          (8)
#define  EXTI_PR_PR8_Msk                          (0x01U << EXTI_PR_PR8_Pos)                        /*!<trigger pending bit*/
#define  EXTI_PR_PR9_Pos                          (9)
#define  EXTI_PR_PR9_Msk                          (0x01U << EXTI_PR_PR9_Pos)                        /*!<trigger pending bit*/
#define  EXTI_PR_PR10_Pos                         (10)
#define  EXTI_PR_PR10_Msk                         (0x01U << EXTI_PR_PR10_Pos)                       /*!<trigger pending bit*/
#define  EXTI_PR_PR11_Pos                         (11)
#define  EXTI_PR_PR11_Msk                         (0x01U << EXTI_PR_PR11_Pos)                       /*!<trigger pending bit*/
#define  EXTI_PR_PR12_Pos                         (12)
#define  EXTI_PR_PR12_Msk                         (0x01U << EXTI_PR_PR12_Pos)                       /*!<trigger pending bit*/
#define  EXTI_PR_PR13_Pos                         (13)
#define  EXTI_PR_PR13_Msk                         (0x01U << EXTI_PR_PR13_Pos)                       /*!<trigger pending bit*/
#define  EXTI_PR_PR14_Pos                         (14)
#define  EXTI_PR_PR14_Msk                         (0x01U << EXTI_PR_PR14_Pos)                       /*!<trigger pending bit*/
#define  EXTI_PR_PR15_Pos                         (15)
#define  EXTI_PR_PR15_Msk                         (0x01U << EXTI_PR_PR15_Pos)                       /*!<trigger pending bit*/
#define  EXTI_PR_PR16_Pos                         (16)
#define  EXTI_PR_PR16_Msk                         (0x01U << EXTI_PR_PR16_Pos)                       /*!<trigger pending bit*/
#define  EXTI_PR_PR17_Pos                         (17)
#define  EXTI_PR_PR17_Msk                         (0x01U << EXTI_PR_PR17_Pos)                       /*!<trigger pending bit*/
#define  EXTI_PR_PR18_Pos                         (18)
#define  EXTI_PR_PR18_Msk                         (0x01U << EXTI_PR_PR18_Pos)                       /*!<trigger pending bit*/
#define  EXTI_PR_PR19_Pos                         (19)
#define  EXTI_PR_PR19_Msk                         (0x01U << EXTI_PR_PR19_Pos)                       /*!<trigger pending bit*/
#define  EXTI_PR_PR20_Pos                         (20)
#define  EXTI_PR_PR20_Msk                         (0x01U << EXTI_PR_PR20_Pos)                       /*!<trigger pending bit*/
#define  EXTI_PR_PR21_Pos                         (21)
#define  EXTI_PR_PR21_Msk                         (0x01U << EXTI_PR_PR21_Pos)                       /*!<trigger pending bit*/
#define  EXTI_PR_PR22_Pos                         (22)
#define  EXTI_PR_PR22_Msk                         (0x01U << EXTI_PR_PR22_Pos)                       /*!<trigger pending bit*/
#define  EXTI_PR_PR23_Pos                         (23)
#define  EXTI_PR_PR23_Msk                         (0x01U << EXTI_PR_PR23_Pos)                       /*!<trigger pending bit*/
#define  EXTI_PR_PR24_Pos                         (24)
#define  EXTI_PR_PR24_Msk                         (0x01U << EXTI_PR_PR24_Pos)                       /*!<trigger pending bit*/
#define  EXTI_PR_PR25_Pos                         (25)
#define  EXTI_PR_PR25_Msk                         (0x01U << EXTI_PR_PR25_Pos)                       /*!<trigger pending bit*/
#define  EXTI_PR_PR26_Pos                         (26)
#define  EXTI_PR_PR26_Msk                         (0x01U << EXTI_PR_PR26_Pos)                       /*!<trigger pending bit*/
#define  EXTI_PR_PR27_Pos                         (27)
#define  EXTI_PR_PR27_Msk                         (0x01U << EXTI_PR_PR27_Pos)                       /*!<trigger pending bit*/
#define  EXTI_PR_PR28_Pos                         (28)
#define  EXTI_PR_PR28_Msk                         (0x01U << EXTI_PR_PR28_Pos)                       /*!<trigger pending bit*/
#define  EXTI_PR_PR29_Pos                         (29)
#define  EXTI_PR_PR29_Msk                         (0x01U << EXTI_PR_PR29_Pos)                       /*!<trigger pending bit*/
#define  EXTI_PR_PR30_Pos                         (30)
#define  EXTI_PR_PR30_Msk                         (0x01U << EXTI_PR_PR30_Pos)                       /*!<trigger pending bit*/
#define  EXTI_PR_PR31_Pos                         (31)
#define  EXTI_PR_PR31_Msk                         (0x01U << EXTI_PR_PR31_Pos)                       /*!<trigger pending bit*/


#endif

