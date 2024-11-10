/***********************************************************************************************************************
    @file     reg_fgpio.h
    @author   VV TEAM
    @brief    This flie contains all the FGPIO's register and its field definition.
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

#ifndef __REG_FGPIO_H
#define __REG_FGPIO_H


/* Files includes ----------------------------------------------------------------------------------------------------*/
#include <core_cm0plus.h>



/**
  * @brief FGPIO Base Address Definition
  */
#define  FGPIOA_BASE                               0x50000000                                       /*!<Base Address: 0x50000000*/
#define  FGPIOB_BASE                               0x50000400                                       /*!<Base Address: 0x50000400*/
#define  FGPIOC_BASE                               0x50000800                                       /*!<Base Address: 0x50000800*/
#define  FGPIOD_BASE                               0x50000C00                                       /*!<Base Address: 0x50000C00*/
#define  FGPIOH_BASE                               0x50001C00                                       /*!<Base Address: 0x50001C00*/

/**
  * @brief FGPIO Register Structure Definition
  */
typedef struct
{
    __IO uint32_t RESERVED0x000[2];               /*!<                                               offset: 0x0~0x4*/
    __IO uint32_t IDR;                            /*!<FGPIO Port input data register                 offset: 0x08*/
    __IO uint32_t ODR;                            /*!<FGPIO Port output data register                offset: 0x0C*/
    __IO uint32_t BSRR;                           /*!<FGPIO Port bit set/reset register              offset: 0x10*/
    __IO uint32_t BRR;                            /*!<FGPIO Port bit reset register                  offset: 0x14*/
} FGPIO_TypeDef;

/**
  * @brief FGPIO type pointer Definition
  */
#define FGPIOA                                    ((FGPIO_TypeDef *)FGPIOA_BASE)
#define FGPIOB                                    ((FGPIO_TypeDef *)FGPIOB_BASE)
#define FGPIOC                                    ((FGPIO_TypeDef *)FGPIOC_BASE)
#define FGPIOD                                    ((FGPIO_TypeDef *)FGPIOD_BASE)
#define FGPIOH                                    ((FGPIO_TypeDef *)FGPIOH_BASE)

/**
  * @brief FGPIO_IDR Register Bit Definition
  */
#define  FGPIO_IDR_IDR0_Pos                       (0)
#define  FGPIO_IDR_IDR0_Msk                       (0x01U << FGPIO_IDR_IDR0_Pos)                     /*!<Port input data*/
#define  FGPIO_IDR_IDR1_Pos                       (1)
#define  FGPIO_IDR_IDR1_Msk                       (0x01U << FGPIO_IDR_IDR1_Pos)                     /*!<Port input data*/
#define  FGPIO_IDR_IDR2_Pos                       (2)
#define  FGPIO_IDR_IDR2_Msk                       (0x01U << FGPIO_IDR_IDR2_Pos)                     /*!<Port input data*/
#define  FGPIO_IDR_IDR3_Pos                       (3)
#define  FGPIO_IDR_IDR3_Msk                       (0x01U << FGPIO_IDR_IDR3_Pos)                     /*!<Port input data*/
#define  FGPIO_IDR_IDR4_Pos                       (4)
#define  FGPIO_IDR_IDR4_Msk                       (0x01U << FGPIO_IDR_IDR4_Pos)                     /*!<Port input data*/
#define  FGPIO_IDR_IDR5_Pos                       (5)
#define  FGPIO_IDR_IDR5_Msk                       (0x01U << FGPIO_IDR_IDR5_Pos)                     /*!<Port input data*/
#define  FGPIO_IDR_IDR6_Pos                       (6)
#define  FGPIO_IDR_IDR6_Msk                       (0x01U << FGPIO_IDR_IDR6_Pos)                     /*!<Port input data*/
#define  FGPIO_IDR_IDR7_Pos                       (7)
#define  FGPIO_IDR_IDR7_Msk                       (0x01U << FGPIO_IDR_IDR7_Pos)                     /*!<Port input data*/
#define  FGPIO_IDR_IDR8_Pos                       (8)
#define  FGPIO_IDR_IDR8_Msk                       (0x01U << FGPIO_IDR_IDR8_Pos)                     /*!<Port input data*/
#define  FGPIO_IDR_IDR9_Pos                       (9)
#define  FGPIO_IDR_IDR9_Msk                       (0x01U << FGPIO_IDR_IDR9_Pos)                     /*!<Port input data*/
#define  FGPIO_IDR_IDR10_Pos                      (10)
#define  FGPIO_IDR_IDR10_Msk                      (0x01U << FGPIO_IDR_IDR10_Pos)                    /*!<Port input data*/
#define  FGPIO_IDR_IDR11_Pos                      (11)
#define  FGPIO_IDR_IDR11_Msk                      (0x01U << FGPIO_IDR_IDR11_Pos)                    /*!<Port input data*/
#define  FGPIO_IDR_IDR12_Pos                      (12)
#define  FGPIO_IDR_IDR12_Msk                      (0x01U << FGPIO_IDR_IDR12_Pos)                    /*!<Port input data*/
#define  FGPIO_IDR_IDR13_Pos                      (13)
#define  FGPIO_IDR_IDR13_Msk                      (0x01U << FGPIO_IDR_IDR13_Pos)                    /*!<Port input data*/
#define  FGPIO_IDR_IDR14_Pos                      (14)
#define  FGPIO_IDR_IDR14_Msk                      (0x01U << FGPIO_IDR_IDR14_Pos)                    /*!<Port input data*/
#define  FGPIO_IDR_IDR15_Pos                      (15)
#define  FGPIO_IDR_IDR15_Msk                      (0x01U << FGPIO_IDR_IDR15_Pos)                    /*!<Port input data*/

/**
  * @brief FGPIO_ODR Register Bit Definition
  */
#define  FGPIO_ODR_ODR0_Pos                       (0)
#define  FGPIO_ODR_ODR0_Msk                       (0x01U << FGPIO_ODR_ODR0_Pos)                     /*!<Port output data*/
#define  FGPIO_ODR_ODR1_Pos                       (1)
#define  FGPIO_ODR_ODR1_Msk                       (0x01U << FGPIO_ODR_ODR1_Pos)                     /*!<Port output data*/
#define  FGPIO_ODR_ODR2_Pos                       (2)
#define  FGPIO_ODR_ODR2_Msk                       (0x01U << FGPIO_ODR_ODR2_Pos)                     /*!<Port output data*/
#define  FGPIO_ODR_ODR3_Pos                       (3)
#define  FGPIO_ODR_ODR3_Msk                       (0x01U << FGPIO_ODR_ODR3_Pos)                     /*!<Port output data*/
#define  FGPIO_ODR_ODR4_Pos                       (4)
#define  FGPIO_ODR_ODR4_Msk                       (0x01U << FGPIO_ODR_ODR4_Pos)                     /*!<Port output data*/
#define  FGPIO_ODR_ODR5_Pos                       (5)
#define  FGPIO_ODR_ODR5_Msk                       (0x01U << FGPIO_ODR_ODR5_Pos)                     /*!<Port output data*/
#define  FGPIO_ODR_ODR6_Pos                       (6)
#define  FGPIO_ODR_ODR6_Msk                       (0x01U << FGPIO_ODR_ODR6_Pos)                     /*!<Port output data*/
#define  FGPIO_ODR_ODR7_Pos                       (7)
#define  FGPIO_ODR_ODR7_Msk                       (0x01U << FGPIO_ODR_ODR7_Pos)                     /*!<Port output data*/
#define  FGPIO_ODR_ODR8_Pos                       (8)
#define  FGPIO_ODR_ODR8_Msk                       (0x01U << FGPIO_ODR_ODR8_Pos)                     /*!<Port output data*/
#define  FGPIO_ODR_ODR9_Pos                       (9)
#define  FGPIO_ODR_ODR9_Msk                       (0x01U << FGPIO_ODR_ODR9_Pos)                     /*!<Port output data*/
#define  FGPIO_ODR_ODR10_Pos                      (10)
#define  FGPIO_ODR_ODR10_Msk                      (0x01U << FGPIO_ODR_ODR10_Pos)                    /*!<Port output data*/
#define  FGPIO_ODR_ODR11_Pos                      (11)
#define  FGPIO_ODR_ODR11_Msk                      (0x01U << FGPIO_ODR_ODR11_Pos)                    /*!<Port output data*/
#define  FGPIO_ODR_ODR12_Pos                      (12)
#define  FGPIO_ODR_ODR12_Msk                      (0x01U << FGPIO_ODR_ODR12_Pos)                    /*!<Port output data*/
#define  FGPIO_ODR_ODR13_Pos                      (13)
#define  FGPIO_ODR_ODR13_Msk                      (0x01U << FGPIO_ODR_ODR13_Pos)                    /*!<Port output data*/
#define  FGPIO_ODR_ODR14_Pos                      (14)
#define  FGPIO_ODR_ODR14_Msk                      (0x01U << FGPIO_ODR_ODR14_Pos)                    /*!<Port output data*/
#define  FGPIO_ODR_ODR15_Pos                      (15)
#define  FGPIO_ODR_ODR15_Msk                      (0x01U << FGPIO_ODR_ODR15_Pos)                    /*!<Port output data*/

/**
  * @brief FGPIO_BSRR Register Bit Definition
  */
#define  FGPIO_BSRR_BS0_Pos                       (0)
#define  FGPIO_BSRR_BS0_Msk                       (0x01U << FGPIO_BSRR_BS0_Pos)                     /*!<Port Set bit*/
#define  FGPIO_BSRR_BS1_Pos                       (1)
#define  FGPIO_BSRR_BS1_Msk                       (0x01U << FGPIO_BSRR_BS1_Pos)                     /*!<Port Set bit*/
#define  FGPIO_BSRR_BS2_Pos                       (2)
#define  FGPIO_BSRR_BS2_Msk                       (0x01U << FGPIO_BSRR_BS2_Pos)                     /*!<Port Set bit*/
#define  FGPIO_BSRR_BS3_Pos                       (3)
#define  FGPIO_BSRR_BS3_Msk                       (0x01U << FGPIO_BSRR_BS3_Pos)                     /*!<Port Set bit*/
#define  FGPIO_BSRR_BS4_Pos                       (4)
#define  FGPIO_BSRR_BS4_Msk                       (0x01U << FGPIO_BSRR_BS4_Pos)                     /*!<Port Set bit*/
#define  FGPIO_BSRR_BS5_Pos                       (5)
#define  FGPIO_BSRR_BS5_Msk                       (0x01U << FGPIO_BSRR_BS5_Pos)                     /*!<Port Set bit*/
#define  FGPIO_BSRR_BS6_Pos                       (6)
#define  FGPIO_BSRR_BS6_Msk                       (0x01U << FGPIO_BSRR_BS6_Pos)                     /*!<Port Set bit*/
#define  FGPIO_BSRR_BS7_Pos                       (7)
#define  FGPIO_BSRR_BS7_Msk                       (0x01U << FGPIO_BSRR_BS7_Pos)                     /*!<Port Set bit*/
#define  FGPIO_BSRR_BS8_Pos                       (8)
#define  FGPIO_BSRR_BS8_Msk                       (0x01U << FGPIO_BSRR_BS8_Pos)                     /*!<Port Set bit*/
#define  FGPIO_BSRR_BS9_Pos                       (9)
#define  FGPIO_BSRR_BS9_Msk                       (0x01U << FGPIO_BSRR_BS9_Pos)                     /*!<Port Set bit*/
#define  FGPIO_BSRR_BS10_Pos                      (10)
#define  FGPIO_BSRR_BS10_Msk                      (0x01U << FGPIO_BSRR_BS10_Pos)                    /*!<Port Set bit*/
#define  FGPIO_BSRR_BS11_Pos                      (11)
#define  FGPIO_BSRR_BS11_Msk                      (0x01U << FGPIO_BSRR_BS11_Pos)                    /*!<Port Set bit*/
#define  FGPIO_BSRR_BS12_Pos                      (12)
#define  FGPIO_BSRR_BS12_Msk                      (0x01U << FGPIO_BSRR_BS12_Pos)                    /*!<Port Set bit*/
#define  FGPIO_BSRR_BS13_Pos                      (13)
#define  FGPIO_BSRR_BS13_Msk                      (0x01U << FGPIO_BSRR_BS13_Pos)                    /*!<Port Set bit*/
#define  FGPIO_BSRR_BS14_Pos                      (14)
#define  FGPIO_BSRR_BS14_Msk                      (0x01U << FGPIO_BSRR_BS14_Pos)                    /*!<Port Set bit*/
#define  FGPIO_BSRR_BS15_Pos                      (15)
#define  FGPIO_BSRR_BS15_Msk                      (0x01U << FGPIO_BSRR_BS15_Pos)                    /*!<Port Set bit*/
#define  FGPIO_BSRR_BR0_Pos                       (16)
#define  FGPIO_BSRR_BR0_Msk                       (0x01U << FGPIO_BSRR_BR0_Pos)                     /*!<Port Reset bit*/
#define  FGPIO_BSRR_BR1_Pos                       (17)
#define  FGPIO_BSRR_BR1_Msk                       (0x01U << FGPIO_BSRR_BR1_Pos)                     /*!<Port Reset bit*/
#define  FGPIO_BSRR_BR2_Pos                       (18)
#define  FGPIO_BSRR_BR2_Msk                       (0x01U << FGPIO_BSRR_BR2_Pos)                     /*!<Port Reset bit*/
#define  FGPIO_BSRR_BR3_Pos                       (19)
#define  FGPIO_BSRR_BR3_Msk                       (0x01U << FGPIO_BSRR_BR3_Pos)                     /*!<Port Reset bit*/
#define  FGPIO_BSRR_BR4_Pos                       (20)
#define  FGPIO_BSRR_BR4_Msk                       (0x01U << FGPIO_BSRR_BR4_Pos)                     /*!<Port Reset bit*/
#define  FGPIO_BSRR_BR5_Pos                       (21)
#define  FGPIO_BSRR_BR5_Msk                       (0x01U << FGPIO_BSRR_BR5_Pos)                     /*!<Port Reset bit*/
#define  FGPIO_BSRR_BR6_Pos                       (22)
#define  FGPIO_BSRR_BR6_Msk                       (0x01U << FGPIO_BSRR_BR6_Pos)                     /*!<Port Reset bit*/
#define  FGPIO_BSRR_BR7_Pos                       (23)
#define  FGPIO_BSRR_BR7_Msk                       (0x01U << FGPIO_BSRR_BR7_Pos)                     /*!<Port Reset bit*/
#define  FGPIO_BSRR_BR8_Pos                       (24)
#define  FGPIO_BSRR_BR8_Msk                       (0x01U << FGPIO_BSRR_BR8_Pos)                     /*!<Port Reset bit*/
#define  FGPIO_BSRR_BR9_Pos                       (25)
#define  FGPIO_BSRR_BR9_Msk                       (0x01U << FGPIO_BSRR_BR9_Pos)                     /*!<Port Reset bit*/
#define  FGPIO_BSRR_BR10_Pos                      (26)
#define  FGPIO_BSRR_BR10_Msk                      (0x01U << FGPIO_BSRR_BR10_Pos)                    /*!<Port Reset bit*/
#define  FGPIO_BSRR_BR11_Pos                      (27)
#define  FGPIO_BSRR_BR11_Msk                      (0x01U << FGPIO_BSRR_BR11_Pos)                    /*!<Port Reset bit*/
#define  FGPIO_BSRR_BR12_Pos                      (28)
#define  FGPIO_BSRR_BR12_Msk                      (0x01U << FGPIO_BSRR_BR12_Pos)                    /*!<Port Reset bit*/
#define  FGPIO_BSRR_BR13_Pos                      (29)
#define  FGPIO_BSRR_BR13_Msk                      (0x01U << FGPIO_BSRR_BR13_Pos)                    /*!<Port Reset bit*/
#define  FGPIO_BSRR_BR14_Pos                      (30)
#define  FGPIO_BSRR_BR14_Msk                      (0x01U << FGPIO_BSRR_BR14_Pos)                    /*!<Port Reset bit*/
#define  FGPIO_BSRR_BR15_Pos                      (31)
#define  FGPIO_BSRR_BR15_Msk                      (0x01U << FGPIO_BSRR_BR15_Pos)                    /*!<Port Reset bit*/

/**
  * @brief FGPIO_BRR Register Bit Definition
  */
#define  FGPIO_BRR_BR0_Pos                        (0)
#define  FGPIO_BRR_BR0_Msk                        (0x01U << FGPIO_BRR_BR0_Pos)                      /*!<Port Reset bit*/
#define  FGPIO_BRR_BR1_Pos                        (1)
#define  FGPIO_BRR_BR1_Msk                        (0x01U << FGPIO_BRR_BR1_Pos)                      /*!<Port Reset bit*/
#define  FGPIO_BRR_BR2_Pos                        (2)
#define  FGPIO_BRR_BR2_Msk                        (0x01U << FGPIO_BRR_BR2_Pos)                      /*!<Port Reset bit*/
#define  FGPIO_BRR_BR3_Pos                        (3)
#define  FGPIO_BRR_BR3_Msk                        (0x01U << FGPIO_BRR_BR3_Pos)                      /*!<Port Reset bit*/
#define  FGPIO_BRR_BR4_Pos                        (4)
#define  FGPIO_BRR_BR4_Msk                        (0x01U << FGPIO_BRR_BR4_Pos)                      /*!<Port Reset bit*/
#define  FGPIO_BRR_BR5_Pos                        (5)
#define  FGPIO_BRR_BR5_Msk                        (0x01U << FGPIO_BRR_BR5_Pos)                      /*!<Port Reset bit*/
#define  FGPIO_BRR_BR6_Pos                        (6)
#define  FGPIO_BRR_BR6_Msk                        (0x01U << FGPIO_BRR_BR6_Pos)                      /*!<Port Reset bit*/
#define  FGPIO_BRR_BR7_Pos                        (7)
#define  FGPIO_BRR_BR7_Msk                        (0x01U << FGPIO_BRR_BR7_Pos)                      /*!<Port Reset bit*/
#define  FGPIO_BRR_BR8_Pos                        (8)
#define  FGPIO_BRR_BR8_Msk                        (0x01U << FGPIO_BRR_BR8_Pos)                      /*!<Port Reset bit*/
#define  FGPIO_BRR_BR9_Pos                        (9)
#define  FGPIO_BRR_BR9_Msk                        (0x01U << FGPIO_BRR_BR9_Pos)                      /*!<Port Reset bit*/
#define  FGPIO_BRR_BR10_Pos                       (10)
#define  FGPIO_BRR_BR10_Msk                       (0x01U << FGPIO_BRR_BR10_Pos)                     /*!<Port Reset bit*/
#define  FGPIO_BRR_BR11_Pos                       (11)
#define  FGPIO_BRR_BR11_Msk                       (0x01U << FGPIO_BRR_BR11_Pos)                     /*!<Port Reset bit*/
#define  FGPIO_BRR_BR12_Pos                       (12)
#define  FGPIO_BRR_BR12_Msk                       (0x01U << FGPIO_BRR_BR12_Pos)                     /*!<Port Reset bit*/
#define  FGPIO_BRR_BR13_Pos                       (13)
#define  FGPIO_BRR_BR13_Msk                       (0x01U << FGPIO_BRR_BR13_Pos)                     /*!<Port Reset bit*/
#define  FGPIO_BRR_BR14_Pos                       (14)
#define  FGPIO_BRR_BR14_Msk                       (0x01U << FGPIO_BRR_BR14_Pos)                     /*!<Port Reset bit*/
#define  FGPIO_BRR_BR15_Pos                       (15)
#define  FGPIO_BRR_BR15_Msk                       (0x01U << FGPIO_BRR_BR15_Pos)                     /*!<Port Reset bit*/


#endif

