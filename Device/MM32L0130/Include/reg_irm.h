/***********************************************************************************************************************
    @file     reg_irm.h
    @author   VV TEAM
    @brief    This flie contains all the IRM's register and its field definition.
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

#ifndef __REG_IRM_H
#define __REG_IRM_H


/* Files includes ----------------------------------------------------------------------------------------------------*/
#include <core_cm0plus.h>



/**
  * @brief IRM Base Address Definition
  */
#define  IRM_BASE                                  0x40009000                                       /*!<Base Address: 0x40009000*/

/**
  * @brief IRM Register Structure Definition
  */
typedef struct
{
    __IO uint32_t CR;                             /*!<IRM IRM control register                       offset: 0x00*/
    __IO uint32_t DR;                             /*!<IRM IRM data register                          offset: 0x04*/
} IRM_TypeDef;

/**
  * @brief IRM type pointer Definition
  */
#define IRM                                       ((IRM_TypeDef *)IRM_BASE)

/**
  * @brief IRM_CR Register Bit Definition
  */
#define  IRM_CR_IRSTART_Pos                       (0)
#define  IRM_CR_IRSTART_Msk                       (0x01U << IRM_CR_IRSTART_Pos)                     /*!<IR modulation start*/
#define  IRM_CR_PSEL_Pos                          (1)
#define  IRM_CR_PSEL_Msk                          (0x01U << IRM_CR_PSEL_Pos)                        /*!<Polarity selection*/
#define  IRM_CR_MSEL_Pos                          (2)
#define  IRM_CR_MSEL_Msk                          (0x01U << IRM_CR_MSEL_Pos)                        /*!<Modulation selection*/
#define  IRM_CR_DSEL_Pos                          (4)
#define  IRM_CR_DSEL_Msk                          (0x03U << IRM_CR_DSEL_Pos)                        /*!<Data selection*/
#define  IRM_CR_CH1SEL_Pos                        (8)
#define  IRM_CR_CH1SEL_Msk                        (0x07U << IRM_CR_CH1SEL_Pos)                      /*!<Channel 1 selection*/
#define  IRM_CR_CH2SEL_Pos                        (12)
#define  IRM_CR_CH2SEL_Msk                        (0x07U << IRM_CR_CH2SEL_Pos)                      /*!<Channel 2 selection*/

/**
  * @brief IRM_DR Register Bit Definition
  */
#define  IRM_DR_DATA_Pos                          (0)
#define  IRM_DR_DATA_Msk                          (0x01U << IRM_DR_DATA_Pos)                        /*!<IRM data*/


#endif

