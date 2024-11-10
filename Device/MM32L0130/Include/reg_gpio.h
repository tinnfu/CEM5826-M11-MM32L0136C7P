/***********************************************************************************************************************
    @file     reg_gpio.h
    @author   VV TEAM
    @brief    This flie contains all the GPIO's register and its field definition.
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

#ifndef __REG_GPIO_H
#define __REG_GPIO_H


/* Files includes ----------------------------------------------------------------------------------------------------*/
#include <core_cm0plus.h>



/**
  * @brief GPIO Base Address Definition
  */
#define  GPIOA_BASE                                0x48000000                                       /*!<Base Address: 0x48000000*/
#define  GPIOB_BASE                                0x48000400                                       /*!<Base Address: 0x48000400*/
#define  GPIOC_BASE                                0x48000800                                       /*!<Base Address: 0x48000800*/
#define  GPIOD_BASE                                0x48000C00                                       /*!<Base Address: 0x48000C00*/
#define  GPIOH_BASE                                0x48001C00                                       /*!<Base Address: 0x48001C00*/

/**
  * @brief GPIO Register Structure Definition
  */
typedef struct
{
    __IO uint32_t CRL;                            /*!<GPIO Port configuration register low           offset: 0x00*/
    __IO uint32_t CRH;                            /*!<GPIO Port configuration register high          offset: 0x04*/
    __IO uint32_t IDR;                            /*!<GPIO Port input data register                  offset: 0x08*/
    __IO uint32_t ODR;                            /*!<GPIO Port output data register                 offset: 0x0C*/
    __IO uint32_t BSRR;                           /*!<GPIO Port bit set/reset register               offset: 0x10*/
    __IO uint32_t BRR;                            /*!<GPIO Port bit reset register                   offset: 0x14*/
    __IO uint32_t LCKR;                           /*!<GPIO Port configuration lock register          offset: 0x18*/
    __IO uint32_t DCR;                            /*!<GPIO Port output open drain control register   offset: 0x1C*/
    __IO uint32_t AFRL;                           /*!<GPIO Port alternate function register low      offset: 0x20*/
    __IO uint32_t AFRH;                           /*!<GPIO Port alternate function register high     offset: 0x24*/
} GPIO_TypeDef;

/**
  * @brief GPIO type pointer Definition
  */
#define GPIOA                                     ((GPIO_TypeDef *)GPIOA_BASE)
#define GPIOB                                     ((GPIO_TypeDef *)GPIOB_BASE)
#define GPIOC                                     ((GPIO_TypeDef *)GPIOC_BASE)
#define GPIOD                                     ((GPIO_TypeDef *)GPIOD_BASE)
#define GPIOH                                     ((GPIO_TypeDef *)GPIOH_BASE)

/**
  * @brief GPIO_CRL Register Bit Definition
  */
#define  GPIO_CRL_MODE0_Pos                       (0)
#define  GPIO_CRL_MODE0_Msk                       (0x03U << GPIO_CRL_MODE0_Pos)                     /*!<See MODE7*/
#define  GPIO_CRL_CNF0_Pos                        (2)
#define  GPIO_CRL_CNF0_Msk                        (0x03U << GPIO_CRL_CNF0_Pos)                      /*!<See CNF7*/
#define  GPIO_CRL_MODE1_Pos                       (4)
#define  GPIO_CRL_MODE1_Msk                       (0x03U << GPIO_CRL_MODE1_Pos)                     /*!<See MODE7*/
#define  GPIO_CRL_CNF1_Pos                        (6)
#define  GPIO_CRL_CNF1_Msk                        (0x03U << GPIO_CRL_CNF1_Pos)                      /*!<See CNF7*/
#define  GPIO_CRL_MODE2_Pos                       (8)
#define  GPIO_CRL_MODE2_Msk                       (0x03U << GPIO_CRL_MODE2_Pos)                     /*!<See MODE7*/
#define  GPIO_CRL_CNF2_Pos                        (10)
#define  GPIO_CRL_CNF2_Msk                        (0x03U << GPIO_CRL_CNF2_Pos)                      /*!<See CNF7*/
#define  GPIO_CRL_MODE3_Pos                       (12)
#define  GPIO_CRL_MODE3_Msk                       (0x03U << GPIO_CRL_MODE3_Pos)                     /*!<See MODE7*/
#define  GPIO_CRL_CNF3_Pos                        (14)
#define  GPIO_CRL_CNF3_Msk                        (0x03U << GPIO_CRL_CNF3_Pos)                      /*!<See CNF7*/
#define  GPIO_CRL_MODE4_Pos                       (16)
#define  GPIO_CRL_MODE4_Msk                       (0x03U << GPIO_CRL_MODE4_Pos)                     /*!<See MODE7*/
#define  GPIO_CRL_CNF4_Pos                        (18)
#define  GPIO_CRL_CNF4_Msk                        (0x03U << GPIO_CRL_CNF4_Pos)                      /*!<See CNF7*/
#define  GPIO_CRL_MODE5_Pos                       (20)
#define  GPIO_CRL_MODE5_Msk                       (0x03U << GPIO_CRL_MODE5_Pos)                     /*!<See MODE7*/
#define  GPIO_CRL_CNF5_Pos                        (22)
#define  GPIO_CRL_CNF5_Msk                        (0x03U << GPIO_CRL_CNF5_Pos)                      /*!<See CNF7*/
#define  GPIO_CRL_MODE6_Pos                       (24)
#define  GPIO_CRL_MODE6_Msk                       (0x03U << GPIO_CRL_MODE6_Pos)                     /*!<See MODE7*/
#define  GPIO_CRL_CNF6_Pos                        (26)
#define  GPIO_CRL_CNF6_Msk                        (0x03U << GPIO_CRL_CNF6_Pos)                      /*!<See CNF7*/
#define  GPIO_CRL_MODE7_Pos                       (28)
#define  GPIO_CRL_MODE7_Msk                       (0x03U << GPIO_CRL_MODE7_Pos)                     /*!<Set MODEy to 0 and port to input mode*/
#define  GPIO_CRL_CNF7_Pos                        (30)
#define  GPIO_CRL_CNF7_Msk                        (0x03U << GPIO_CRL_CNF7_Pos)                      /*!<Port configuration bits (y=7..0)*/

/**
  * @brief GPIO_CRH Register Bit Definition
  */
#define  GPIO_CRH_MODE8_Pos                       (0)
#define  GPIO_CRH_MODE8_Msk                       (0x03U << GPIO_CRH_MODE8_Pos)                     /*!<See MODE15*/
#define  GPIO_CRH_CNF8_Pos                        (2)
#define  GPIO_CRH_CNF8_Msk                        (0x03U << GPIO_CRH_CNF8_Pos)                      /*!<See CNF15*/
#define  GPIO_CRH_MODE9_Pos                       (4)
#define  GPIO_CRH_MODE9_Msk                       (0x03U << GPIO_CRH_MODE9_Pos)                     /*!<See MODE15*/
#define  GPIO_CRH_CNF9_Pos                        (6)
#define  GPIO_CRH_CNF9_Msk                        (0x03U << GPIO_CRH_CNF9_Pos)                      /*!<See CNF15*/
#define  GPIO_CRH_MODE10_Pos                      (8)
#define  GPIO_CRH_MODE10_Msk                      (0x03U << GPIO_CRH_MODE10_Pos)                    /*!<See MODE15*/
#define  GPIO_CRH_CNF10_Pos                       (10)
#define  GPIO_CRH_CNF10_Msk                       (0x03U << GPIO_CRH_CNF10_Pos)                     /*!<See CNF15*/
#define  GPIO_CRH_MODE11_Pos                      (12)
#define  GPIO_CRH_MODE11_Msk                      (0x03U << GPIO_CRH_MODE11_Pos)                    /*!<See MODE15*/
#define  GPIO_CRH_CNF11_Pos                       (14)
#define  GPIO_CRH_CNF11_Msk                       (0x03U << GPIO_CRH_CNF11_Pos)                     /*!<See CNF15*/
#define  GPIO_CRH_MODE12_Pos                      (16)
#define  GPIO_CRH_MODE12_Msk                      (0x03U << GPIO_CRH_MODE12_Pos)                    /*!<See MODE15*/
#define  GPIO_CRH_CNF12_Pos                       (18)
#define  GPIO_CRH_CNF12_Msk                       (0x03U << GPIO_CRH_CNF12_Pos)                     /*!<See CNF15*/
#define  GPIO_CRH_MODE13_Pos                      (20)
#define  GPIO_CRH_MODE13_Msk                      (0x03U << GPIO_CRH_MODE13_Pos)                    /*!<See MODE15*/
#define  GPIO_CRH_CNF13_Pos                       (22)
#define  GPIO_CRH_CNF13_Msk                       (0x03U << GPIO_CRH_CNF13_Pos)                     /*!<See CNF15*/
#define  GPIO_CRH_MODE14_Pos                      (24)
#define  GPIO_CRH_MODE14_Msk                      (0x03U << GPIO_CRH_MODE14_Pos)                    /*!<See MODE15*/
#define  GPIO_CRH_CNF14_Pos                       (26)
#define  GPIO_CRH_CNF14_Msk                       (0x03U << GPIO_CRH_CNF14_Pos)                     /*!<See CNF15*/
#define  GPIO_CRH_MODE15_Pos                      (28)
#define  GPIO_CRH_MODE15_Msk                      (0x03U << GPIO_CRH_MODE15_Pos)                    /*!<Set MODEy to 0 and port to input mode*/
#define  GPIO_CRH_CNF15_Pos                       (30)
#define  GPIO_CRH_CNF15_Msk                       (0x03U << GPIO_CRH_CNF15_Pos)                     /*!<Port configuration bits (y=7..0)*/

/**
  * @brief GPIO_IDR Register Bit Definition
  */
#define  GPIO_IDR_IDR0_Pos                        (0)
#define  GPIO_IDR_IDR0_Msk                        (0x01U << GPIO_IDR_IDR0_Pos)                      /*!<Port input data*/
#define  GPIO_IDR_IDR1_Pos                        (1)
#define  GPIO_IDR_IDR1_Msk                        (0x01U << GPIO_IDR_IDR1_Pos)                      /*!<Port input data*/
#define  GPIO_IDR_IDR2_Pos                        (2)
#define  GPIO_IDR_IDR2_Msk                        (0x01U << GPIO_IDR_IDR2_Pos)                      /*!<Port input data*/
#define  GPIO_IDR_IDR3_Pos                        (3)
#define  GPIO_IDR_IDR3_Msk                        (0x01U << GPIO_IDR_IDR3_Pos)                      /*!<Port input data*/
#define  GPIO_IDR_IDR4_Pos                        (4)
#define  GPIO_IDR_IDR4_Msk                        (0x01U << GPIO_IDR_IDR4_Pos)                      /*!<Port input data*/
#define  GPIO_IDR_IDR5_Pos                        (5)
#define  GPIO_IDR_IDR5_Msk                        (0x01U << GPIO_IDR_IDR5_Pos)                      /*!<Port input data*/
#define  GPIO_IDR_IDR6_Pos                        (6)
#define  GPIO_IDR_IDR6_Msk                        (0x01U << GPIO_IDR_IDR6_Pos)                      /*!<Port input data*/
#define  GPIO_IDR_IDR7_Pos                        (7)
#define  GPIO_IDR_IDR7_Msk                        (0x01U << GPIO_IDR_IDR7_Pos)                      /*!<Port input data*/
#define  GPIO_IDR_IDR8_Pos                        (8)
#define  GPIO_IDR_IDR8_Msk                        (0x01U << GPIO_IDR_IDR8_Pos)                      /*!<Port input data*/
#define  GPIO_IDR_IDR9_Pos                        (9)
#define  GPIO_IDR_IDR9_Msk                        (0x01U << GPIO_IDR_IDR9_Pos)                      /*!<Port input data*/
#define  GPIO_IDR_IDR10_Pos                       (10)
#define  GPIO_IDR_IDR10_Msk                       (0x01U << GPIO_IDR_IDR10_Pos)                     /*!<Port input data*/
#define  GPIO_IDR_IDR11_Pos                       (11)
#define  GPIO_IDR_IDR11_Msk                       (0x01U << GPIO_IDR_IDR11_Pos)                     /*!<Port input data*/
#define  GPIO_IDR_IDR12_Pos                       (12)
#define  GPIO_IDR_IDR12_Msk                       (0x01U << GPIO_IDR_IDR12_Pos)                     /*!<Port input data*/
#define  GPIO_IDR_IDR13_Pos                       (13)
#define  GPIO_IDR_IDR13_Msk                       (0x01U << GPIO_IDR_IDR13_Pos)                     /*!<Port input data*/
#define  GPIO_IDR_IDR14_Pos                       (14)
#define  GPIO_IDR_IDR14_Msk                       (0x01U << GPIO_IDR_IDR14_Pos)                     /*!<Port input data*/
#define  GPIO_IDR_IDR15_Pos                       (15)
#define  GPIO_IDR_IDR15_Msk                       (0x01U << GPIO_IDR_IDR15_Pos)                     /*!<Port input data*/

/**
  * @brief GPIO_ODR Register Bit Definition
  */
#define  GPIO_ODR_ODR0_Pos                        (0)
#define  GPIO_ODR_ODR0_Msk                        (0x01U << GPIO_ODR_ODR0_Pos)                      /*!<Port output data*/
#define  GPIO_ODR_ODR1_Pos                        (1)
#define  GPIO_ODR_ODR1_Msk                        (0x01U << GPIO_ODR_ODR1_Pos)                      /*!<Port output data*/
#define  GPIO_ODR_ODR2_Pos                        (2)
#define  GPIO_ODR_ODR2_Msk                        (0x01U << GPIO_ODR_ODR2_Pos)                      /*!<Port output data*/
#define  GPIO_ODR_ODR3_Pos                        (3)
#define  GPIO_ODR_ODR3_Msk                        (0x01U << GPIO_ODR_ODR3_Pos)                      /*!<Port output data*/
#define  GPIO_ODR_ODR4_Pos                        (4)
#define  GPIO_ODR_ODR4_Msk                        (0x01U << GPIO_ODR_ODR4_Pos)                      /*!<Port output data*/
#define  GPIO_ODR_ODR5_Pos                        (5)
#define  GPIO_ODR_ODR5_Msk                        (0x01U << GPIO_ODR_ODR5_Pos)                      /*!<Port output data*/
#define  GPIO_ODR_ODR6_Pos                        (6)
#define  GPIO_ODR_ODR6_Msk                        (0x01U << GPIO_ODR_ODR6_Pos)                      /*!<Port output data*/
#define  GPIO_ODR_ODR7_Pos                        (7)
#define  GPIO_ODR_ODR7_Msk                        (0x01U << GPIO_ODR_ODR7_Pos)                      /*!<Port output data*/
#define  GPIO_ODR_ODR8_Pos                        (8)
#define  GPIO_ODR_ODR8_Msk                        (0x01U << GPIO_ODR_ODR8_Pos)                      /*!<Port output data*/
#define  GPIO_ODR_ODR9_Pos                        (9)
#define  GPIO_ODR_ODR9_Msk                        (0x01U << GPIO_ODR_ODR9_Pos)                      /*!<Port output data*/
#define  GPIO_ODR_ODR10_Pos                       (10)
#define  GPIO_ODR_ODR10_Msk                       (0x01U << GPIO_ODR_ODR10_Pos)                     /*!<Port output data*/
#define  GPIO_ODR_ODR11_Pos                       (11)
#define  GPIO_ODR_ODR11_Msk                       (0x01U << GPIO_ODR_ODR11_Pos)                     /*!<Port output data*/
#define  GPIO_ODR_ODR12_Pos                       (12)
#define  GPIO_ODR_ODR12_Msk                       (0x01U << GPIO_ODR_ODR12_Pos)                     /*!<Port output data*/
#define  GPIO_ODR_ODR13_Pos                       (13)
#define  GPIO_ODR_ODR13_Msk                       (0x01U << GPIO_ODR_ODR13_Pos)                     /*!<Port output data*/
#define  GPIO_ODR_ODR14_Pos                       (14)
#define  GPIO_ODR_ODR14_Msk                       (0x01U << GPIO_ODR_ODR14_Pos)                     /*!<Port output data*/
#define  GPIO_ODR_ODR15_Pos                       (15)
#define  GPIO_ODR_ODR15_Msk                       (0x01U << GPIO_ODR_ODR15_Pos)                     /*!<Port output data*/

/**
  * @brief GPIO_BSRR Register Bit Definition
  */
#define  GPIO_BSRR_BS0_Pos                        (0)
#define  GPIO_BSRR_BS0_Msk                        (0x01U << GPIO_BSRR_BS0_Pos)                      /*!<Port Set bit*/
#define  GPIO_BSRR_BS1_Pos                        (1)
#define  GPIO_BSRR_BS1_Msk                        (0x01U << GPIO_BSRR_BS1_Pos)                      /*!<Port Set bit*/
#define  GPIO_BSRR_BS2_Pos                        (2)
#define  GPIO_BSRR_BS2_Msk                        (0x01U << GPIO_BSRR_BS2_Pos)                      /*!<Port Set bit*/
#define  GPIO_BSRR_BS3_Pos                        (3)
#define  GPIO_BSRR_BS3_Msk                        (0x01U << GPIO_BSRR_BS3_Pos)                      /*!<Port Set bit*/
#define  GPIO_BSRR_BS4_Pos                        (4)
#define  GPIO_BSRR_BS4_Msk                        (0x01U << GPIO_BSRR_BS4_Pos)                      /*!<Port Set bit*/
#define  GPIO_BSRR_BS5_Pos                        (5)
#define  GPIO_BSRR_BS5_Msk                        (0x01U << GPIO_BSRR_BS5_Pos)                      /*!<Port Set bit*/
#define  GPIO_BSRR_BS6_Pos                        (6)
#define  GPIO_BSRR_BS6_Msk                        (0x01U << GPIO_BSRR_BS6_Pos)                      /*!<Port Set bit*/
#define  GPIO_BSRR_BS7_Pos                        (7)
#define  GPIO_BSRR_BS7_Msk                        (0x01U << GPIO_BSRR_BS7_Pos)                      /*!<Port Set bit*/
#define  GPIO_BSRR_BS8_Pos                        (8)
#define  GPIO_BSRR_BS8_Msk                        (0x01U << GPIO_BSRR_BS8_Pos)                      /*!<Port Set bit*/
#define  GPIO_BSRR_BS9_Pos                        (9)
#define  GPIO_BSRR_BS9_Msk                        (0x01U << GPIO_BSRR_BS9_Pos)                      /*!<Port Set bit*/
#define  GPIO_BSRR_BS10_Pos                       (10)
#define  GPIO_BSRR_BS10_Msk                       (0x01U << GPIO_BSRR_BS10_Pos)                     /*!<Port Set bit*/
#define  GPIO_BSRR_BS11_Pos                       (11)
#define  GPIO_BSRR_BS11_Msk                       (0x01U << GPIO_BSRR_BS11_Pos)                     /*!<Port Set bit*/
#define  GPIO_BSRR_BS12_Pos                       (12)
#define  GPIO_BSRR_BS12_Msk                       (0x01U << GPIO_BSRR_BS12_Pos)                     /*!<Port Set bit*/
#define  GPIO_BSRR_BS13_Pos                       (13)
#define  GPIO_BSRR_BS13_Msk                       (0x01U << GPIO_BSRR_BS13_Pos)                     /*!<Port Set bit*/
#define  GPIO_BSRR_BS14_Pos                       (14)
#define  GPIO_BSRR_BS14_Msk                       (0x01U << GPIO_BSRR_BS14_Pos)                     /*!<Port Set bit*/
#define  GPIO_BSRR_BS15_Pos                       (15)
#define  GPIO_BSRR_BS15_Msk                       (0x01U << GPIO_BSRR_BS15_Pos)                     /*!<Port Set bit*/
#define  GPIO_BSRR_BR0_Pos                        (16)
#define  GPIO_BSRR_BR0_Msk                        (0x01U << GPIO_BSRR_BR0_Pos)                      /*!<Port Reset bit*/
#define  GPIO_BSRR_BR1_Pos                        (17)
#define  GPIO_BSRR_BR1_Msk                        (0x01U << GPIO_BSRR_BR1_Pos)                      /*!<Port Reset bit*/
#define  GPIO_BSRR_BR2_Pos                        (18)
#define  GPIO_BSRR_BR2_Msk                        (0x01U << GPIO_BSRR_BR2_Pos)                      /*!<Port Reset bit*/
#define  GPIO_BSRR_BR3_Pos                        (19)
#define  GPIO_BSRR_BR3_Msk                        (0x01U << GPIO_BSRR_BR3_Pos)                      /*!<Port Reset bit*/
#define  GPIO_BSRR_BR4_Pos                        (20)
#define  GPIO_BSRR_BR4_Msk                        (0x01U << GPIO_BSRR_BR4_Pos)                      /*!<Port Reset bit*/
#define  GPIO_BSRR_BR5_Pos                        (21)
#define  GPIO_BSRR_BR5_Msk                        (0x01U << GPIO_BSRR_BR5_Pos)                      /*!<Port Reset bit*/
#define  GPIO_BSRR_BR6_Pos                        (22)
#define  GPIO_BSRR_BR6_Msk                        (0x01U << GPIO_BSRR_BR6_Pos)                      /*!<Port Reset bit*/
#define  GPIO_BSRR_BR7_Pos                        (23)
#define  GPIO_BSRR_BR7_Msk                        (0x01U << GPIO_BSRR_BR7_Pos)                      /*!<Port Reset bit*/
#define  GPIO_BSRR_BR8_Pos                        (24)
#define  GPIO_BSRR_BR8_Msk                        (0x01U << GPIO_BSRR_BR8_Pos)                      /*!<Port Reset bit*/
#define  GPIO_BSRR_BR9_Pos                        (25)
#define  GPIO_BSRR_BR9_Msk                        (0x01U << GPIO_BSRR_BR9_Pos)                      /*!<Port Reset bit*/
#define  GPIO_BSRR_BR10_Pos                       (26)
#define  GPIO_BSRR_BR10_Msk                       (0x01U << GPIO_BSRR_BR10_Pos)                     /*!<Port Reset bit*/
#define  GPIO_BSRR_BR11_Pos                       (27)
#define  GPIO_BSRR_BR11_Msk                       (0x01U << GPIO_BSRR_BR11_Pos)                     /*!<Port Reset bit*/
#define  GPIO_BSRR_BR12_Pos                       (28)
#define  GPIO_BSRR_BR12_Msk                       (0x01U << GPIO_BSRR_BR12_Pos)                     /*!<Port Reset bit*/
#define  GPIO_BSRR_BR13_Pos                       (29)
#define  GPIO_BSRR_BR13_Msk                       (0x01U << GPIO_BSRR_BR13_Pos)                     /*!<Port Reset bit*/
#define  GPIO_BSRR_BR14_Pos                       (30)
#define  GPIO_BSRR_BR14_Msk                       (0x01U << GPIO_BSRR_BR14_Pos)                     /*!<Port Reset bit*/
#define  GPIO_BSRR_BR15_Pos                       (31)
#define  GPIO_BSRR_BR15_Msk                       (0x01U << GPIO_BSRR_BR15_Pos)                     /*!<Port Reset bit*/

/**
  * @brief GPIO_BRR Register Bit Definition
  */
#define  GPIO_BRR_BR0_Pos                         (0)
#define  GPIO_BRR_BR0_Msk                         (0x01U << GPIO_BRR_BR0_Pos)                       /*!<Port Reset bit*/
#define  GPIO_BRR_BR1_Pos                         (1)
#define  GPIO_BRR_BR1_Msk                         (0x01U << GPIO_BRR_BR1_Pos)                       /*!<Port Reset bit*/
#define  GPIO_BRR_BR2_Pos                         (2)
#define  GPIO_BRR_BR2_Msk                         (0x01U << GPIO_BRR_BR2_Pos)                       /*!<Port Reset bit*/
#define  GPIO_BRR_BR3_Pos                         (3)
#define  GPIO_BRR_BR3_Msk                         (0x01U << GPIO_BRR_BR3_Pos)                       /*!<Port Reset bit*/
#define  GPIO_BRR_BR4_Pos                         (4)
#define  GPIO_BRR_BR4_Msk                         (0x01U << GPIO_BRR_BR4_Pos)                       /*!<Port Reset bit*/
#define  GPIO_BRR_BR5_Pos                         (5)
#define  GPIO_BRR_BR5_Msk                         (0x01U << GPIO_BRR_BR5_Pos)                       /*!<Port Reset bit*/
#define  GPIO_BRR_BR6_Pos                         (6)
#define  GPIO_BRR_BR6_Msk                         (0x01U << GPIO_BRR_BR6_Pos)                       /*!<Port Reset bit*/
#define  GPIO_BRR_BR7_Pos                         (7)
#define  GPIO_BRR_BR7_Msk                         (0x01U << GPIO_BRR_BR7_Pos)                       /*!<Port Reset bit*/
#define  GPIO_BRR_BR8_Pos                         (8)
#define  GPIO_BRR_BR8_Msk                         (0x01U << GPIO_BRR_BR8_Pos)                       /*!<Port Reset bit*/
#define  GPIO_BRR_BR9_Pos                         (9)
#define  GPIO_BRR_BR9_Msk                         (0x01U << GPIO_BRR_BR9_Pos)                       /*!<Port Reset bit*/
#define  GPIO_BRR_BR10_Pos                        (10)
#define  GPIO_BRR_BR10_Msk                        (0x01U << GPIO_BRR_BR10_Pos)                      /*!<Port Reset bit*/
#define  GPIO_BRR_BR11_Pos                        (11)
#define  GPIO_BRR_BR11_Msk                        (0x01U << GPIO_BRR_BR11_Pos)                      /*!<Port Reset bit*/
#define  GPIO_BRR_BR12_Pos                        (12)
#define  GPIO_BRR_BR12_Msk                        (0x01U << GPIO_BRR_BR12_Pos)                      /*!<Port Reset bit*/
#define  GPIO_BRR_BR13_Pos                        (13)
#define  GPIO_BRR_BR13_Msk                        (0x01U << GPIO_BRR_BR13_Pos)                      /*!<Port Reset bit*/
#define  GPIO_BRR_BR14_Pos                        (14)
#define  GPIO_BRR_BR14_Msk                        (0x01U << GPIO_BRR_BR14_Pos)                      /*!<Port Reset bit*/
#define  GPIO_BRR_BR15_Pos                        (15)
#define  GPIO_BRR_BR15_Msk                        (0x01U << GPIO_BRR_BR15_Pos)                      /*!<Port Reset bit*/

/**
  * @brief GPIO_LCKR Register Bit Definition
  */
#define  GPIO_LCKR_LCK0_Pos                       (0)
#define  GPIO_LCKR_LCK0_Msk                       (0x01U << GPIO_LCKR_LCK0_Pos)                     /*!<Lock bit*/
#define  GPIO_LCKR_LCK1_Pos                       (1)
#define  GPIO_LCKR_LCK1_Msk                       (0x01U << GPIO_LCKR_LCK1_Pos)                     /*!<Lock bit*/
#define  GPIO_LCKR_LCK2_Pos                       (2)
#define  GPIO_LCKR_LCK2_Msk                       (0x01U << GPIO_LCKR_LCK2_Pos)                     /*!<Lock bit*/
#define  GPIO_LCKR_LCK3_Pos                       (3)
#define  GPIO_LCKR_LCK3_Msk                       (0x01U << GPIO_LCKR_LCK3_Pos)                     /*!<Lock bit*/
#define  GPIO_LCKR_LCK4_Pos                       (4)
#define  GPIO_LCKR_LCK4_Msk                       (0x01U << GPIO_LCKR_LCK4_Pos)                     /*!<Lock bit*/
#define  GPIO_LCKR_LCK5_Pos                       (5)
#define  GPIO_LCKR_LCK5_Msk                       (0x01U << GPIO_LCKR_LCK5_Pos)                     /*!<Lock bit*/
#define  GPIO_LCKR_LCK6_Pos                       (6)
#define  GPIO_LCKR_LCK6_Msk                       (0x01U << GPIO_LCKR_LCK6_Pos)                     /*!<Lock bit*/
#define  GPIO_LCKR_LCK7_Pos                       (7)
#define  GPIO_LCKR_LCK7_Msk                       (0x01U << GPIO_LCKR_LCK7_Pos)                     /*!<Lock bit*/
#define  GPIO_LCKR_LCK8_Pos                       (8)
#define  GPIO_LCKR_LCK8_Msk                       (0x01U << GPIO_LCKR_LCK8_Pos)                     /*!<Lock bit*/
#define  GPIO_LCKR_LCK9_Pos                       (9)
#define  GPIO_LCKR_LCK9_Msk                       (0x01U << GPIO_LCKR_LCK9_Pos)                     /*!<Lock bit*/
#define  GPIO_LCKR_LCK10_Pos                      (10)
#define  GPIO_LCKR_LCK10_Msk                      (0x01U << GPIO_LCKR_LCK10_Pos)                    /*!<Lock bit*/
#define  GPIO_LCKR_LCK11_Pos                      (11)
#define  GPIO_LCKR_LCK11_Msk                      (0x01U << GPIO_LCKR_LCK11_Pos)                    /*!<Lock bit*/
#define  GPIO_LCKR_LCK12_Pos                      (12)
#define  GPIO_LCKR_LCK12_Msk                      (0x01U << GPIO_LCKR_LCK12_Pos)                    /*!<Lock bit*/
#define  GPIO_LCKR_LCK13_Pos                      (13)
#define  GPIO_LCKR_LCK13_Msk                      (0x01U << GPIO_LCKR_LCK13_Pos)                    /*!<Lock bit*/
#define  GPIO_LCKR_LCK14_Pos                      (14)
#define  GPIO_LCKR_LCK14_Msk                      (0x01U << GPIO_LCKR_LCK14_Pos)                    /*!<Lock bit*/
#define  GPIO_LCKR_LCK15_Pos                      (15)
#define  GPIO_LCKR_LCK15_Msk                      (0x01U << GPIO_LCKR_LCK15_Pos)                    /*!<Lock bit*/
#define  GPIO_LCKR_LCKK_Pos                       (16)
#define  GPIO_LCKR_LCKK_Msk                       (0x01U << GPIO_LCKR_LCKK_Pos)                     /*!<Lock key*/

/**
  * @brief GPIO_DCR Register Bit Definition
  */
#define  GPIO_DCR_PX0_Pos                         (0)
#define  GPIO_DCR_PX0_Msk                         (0x03U << GPIO_DCR_PX0_Pos)                       /*!<PX:*/
#define  GPIO_DCR_PX1_Pos                         (2)
#define  GPIO_DCR_PX1_Msk                         (0x03U << GPIO_DCR_PX1_Pos)                       /*!<PX:*/
#define  GPIO_DCR_PX2_Pos                         (4)
#define  GPIO_DCR_PX2_Msk                         (0x03U << GPIO_DCR_PX2_Pos)                       /*!<PX:*/
#define  GPIO_DCR_PX3_Pos                         (6)
#define  GPIO_DCR_PX3_Msk                         (0x03U << GPIO_DCR_PX3_Pos)                       /*!<PX:*/
#define  GPIO_DCR_PX4_Pos                         (8)
#define  GPIO_DCR_PX4_Msk                         (0x03U << GPIO_DCR_PX4_Pos)                       /*!<PX:*/
#define  GPIO_DCR_PX5_Pos                         (10)
#define  GPIO_DCR_PX5_Msk                         (0x03U << GPIO_DCR_PX5_Pos)                       /*!<PX:*/
#define  GPIO_DCR_PX6_Pos                         (12)
#define  GPIO_DCR_PX6_Msk                         (0x03U << GPIO_DCR_PX6_Pos)                       /*!<PX:*/
#define  GPIO_DCR_PX7_Pos                         (14)
#define  GPIO_DCR_PX7_Msk                         (0x03U << GPIO_DCR_PX7_Pos)                       /*!<PX:*/
#define  GPIO_DCR_PX8_Pos                         (16)
#define  GPIO_DCR_PX8_Msk                         (0x03U << GPIO_DCR_PX8_Pos)                       /*!<PX:*/
#define  GPIO_DCR_PX9_Pos                         (18)
#define  GPIO_DCR_PX9_Msk                         (0x03U << GPIO_DCR_PX9_Pos)                       /*!<PX:*/
#define  GPIO_DCR_PX10_Pos                        (20)
#define  GPIO_DCR_PX10_Msk                        (0x03U << GPIO_DCR_PX10_Pos)                      /*!<PX:*/
#define  GPIO_DCR_PX11_Pos                        (22)
#define  GPIO_DCR_PX11_Msk                        (0x03U << GPIO_DCR_PX11_Pos)                      /*!<PX:*/
#define  GPIO_DCR_PX12_Pos                        (24)
#define  GPIO_DCR_PX12_Msk                        (0x03U << GPIO_DCR_PX12_Pos)                      /*!<PX:*/
#define  GPIO_DCR_PX13_Pos                        (26)
#define  GPIO_DCR_PX13_Msk                        (0x03U << GPIO_DCR_PX13_Pos)                      /*!<PX:*/
#define  GPIO_DCR_PX14_Pos                        (28)
#define  GPIO_DCR_PX14_Msk                        (0x03U << GPIO_DCR_PX14_Pos)                      /*!<PX:*/
#define  GPIO_DCR_PX15_Pos                        (30)
#define  GPIO_DCR_PX15_Msk                        (0x03U << GPIO_DCR_PX15_Pos)                      /*!<PX:*/

/**
  * @brief GPIO_AFRL Register Bit Definition
  */
#define  GPIO_AFRL_AFR0_Pos                       (0)
#define  GPIO_AFRL_AFR0_Msk                       (0x0FU << GPIO_AFRL_AFR0_Pos)                     /*!<Port x alternate function bit, which can be accessed by software to configure the function.*/
#define  GPIO_AFRL_AFR1_Pos                       (4)
#define  GPIO_AFRL_AFR1_Msk                       (0x0FU << GPIO_AFRL_AFR1_Pos)                     /*!<Port x alternate function bit, which can be accessed by software to configure the function.*/
#define  GPIO_AFRL_AFR2_Pos                       (8)
#define  GPIO_AFRL_AFR2_Msk                       (0x0FU << GPIO_AFRL_AFR2_Pos)                     /*!<Port x alternate function bit, which can be accessed by software to configure the function.*/
#define  GPIO_AFRL_AFR3_Pos                       (12)
#define  GPIO_AFRL_AFR3_Msk                       (0x0FU << GPIO_AFRL_AFR3_Pos)                     /*!<Port x alternate function bit, which can be accessed by software to configure the function.*/
#define  GPIO_AFRL_AFR4_Pos                       (16)
#define  GPIO_AFRL_AFR4_Msk                       (0x0FU << GPIO_AFRL_AFR4_Pos)                     /*!<Port x alternate function bit, which can be accessed by software to configure the function.*/
#define  GPIO_AFRL_AFR5_Pos                       (20)
#define  GPIO_AFRL_AFR5_Msk                       (0x0FU << GPIO_AFRL_AFR5_Pos)                     /*!<Port x alternate function bit, which can be accessed by software to configure the function.*/
#define  GPIO_AFRL_AFR6_Pos                       (24)
#define  GPIO_AFRL_AFR6_Msk                       (0x0FU << GPIO_AFRL_AFR6_Pos)                     /*!<Port x alternate function bit, which can be accessed by software to configure the function.*/
#define  GPIO_AFRL_AFR7_Pos                       (28)
#define  GPIO_AFRL_AFR7_Msk                       (0x0FU << GPIO_AFRL_AFR7_Pos)                     /*!<Port x alternate function bit, which can be accessed by software to configure the function.*/

/**
  * @brief GPIO_AFRH Register Bit Definition
  */
#define  GPIO_AFRH_AFR8_Pos                       (0)
#define  GPIO_AFRH_AFR8_Msk                       (0x0FU << GPIO_AFRH_AFR8_Pos)                     /*!<Port x alternate function bit, which can be accessed by software to configure the function.*/
#define  GPIO_AFRH_AFR9_Pos                       (4)
#define  GPIO_AFRH_AFR9_Msk                       (0x0FU << GPIO_AFRH_AFR9_Pos)                     /*!<Port x alternate function bit, which can be accessed by software to configure the function.*/
#define  GPIO_AFRH_AFR10_Pos                      (8)
#define  GPIO_AFRH_AFR10_Msk                      (0x0FU << GPIO_AFRH_AFR10_Pos)                    /*!<Port x alternate function bit, which can be accessed by software to configure the function.*/
#define  GPIO_AFRH_AFR11_Pos                      (12)
#define  GPIO_AFRH_AFR11_Msk                      (0x0FU << GPIO_AFRH_AFR11_Pos)                    /*!<Port x alternate function bit, which can be accessed by software to configure the function.*/
#define  GPIO_AFRH_AFR12_Pos                      (16)
#define  GPIO_AFRH_AFR12_Msk                      (0x0FU << GPIO_AFRH_AFR12_Pos)                    /*!<Port x alternate function bit, which can be accessed by software to configure the function.*/
#define  GPIO_AFRH_AFR13_Pos                      (20)
#define  GPIO_AFRH_AFR13_Msk                      (0x0FU << GPIO_AFRH_AFR13_Pos)                    /*!<Port x alternate function bit, which can be accessed by software to configure the function.*/
#define  GPIO_AFRH_AFR14_Pos                      (24)
#define  GPIO_AFRH_AFR14_Msk                      (0x0FU << GPIO_AFRH_AFR14_Pos)                    /*!<Port x alternate function bit, which can be accessed by software to configure the function.*/
#define  GPIO_AFRH_AFR15_Pos                      (28)
#define  GPIO_AFRH_AFR15_Msk                      (0x0FU << GPIO_AFRH_AFR15_Pos)                    /*!<Port x alternate function bit, which can be accessed by software to configure the function.*/


#endif

