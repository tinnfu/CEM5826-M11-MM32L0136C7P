/***********************************************************************************************************************
    @file     reg_crcpoly.h
    @author   VV TEAM
    @brief    This flie contains all the CRCPOLY's register and its field definition.
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

#ifndef __REG_CRCPOLY_H
#define __REG_CRCPOLY_H


/* Files includes ----------------------------------------------------------------------------------------------------*/
#include <core_cm0plus.h>



/**
  * @brief CRCPOLY Base Address Definition
  */
#define  CRCPOLY_BASE                              0x40023000                                       /*!<Base Address: 0x40023000*/

/**
  * @brief CRCPOLY Register Structure Definition
  */
typedef struct
{
    __IO uint32_t DR;                             /*!<CRCPOLY CRC data register                      offset: 0x00*/
    __IO uint32_t IDR;                            /*!<CRCPOLY CRC independent data register          offset: 0x04*/
    __IO uint32_t CR;                             /*!<CRCPOLY CRC control register                   offset: 0x08*/
    __IO uint32_t IVR;                            /*!<CRCPOLY CRC initial value register             offset: 0x0C*/
    __IO uint32_t PR;                             /*!<CRCPOLY CRC polynomial register                offset: 0x10*/
} CRCPOLY_TypeDef;

/**
  * @brief CRCPOLY type pointer Definition
  */
#define CRCPOLY                                   ((CRCPOLY_TypeDef *)CRCPOLY_BASE)

/**
  * @brief CRCPOLY_DR Register Bit Definition
  */
#define  CRCPOLY_DR_DR_Pos                        (0)
#define  CRCPOLY_DR_DR_Msk                        (0xFFFFFFFFU << CRCPOLY_DR_DR_Pos)                /*!<Data register*/

/**
  * @brief CRCPOLY_IDR Register Bit Definition
  */
#define  CRCPOLY_IDR_IDR_Pos                      (0)
#define  CRCPOLY_IDR_IDR_Msk                      (0xFFFFFFFFU << CRCPOLY_IDR_IDR_Pos)              /*!<General-purpose 32-bit data register*/

/**
  * @brief CRCPOLY_CR Register Bit Definition
  */
#define  CRCPOLY_CR_RST_Pos                       (0)
#define  CRCPOLY_CR_RST_Msk                       (0x01U << CRCPOLY_CR_RST_Pos)                     /*!<Reset CRC calculation unit*/
#define  CRCPOLY_CR_RI_Pos                        (1)
#define  CRCPOLY_CR_RI_Msk                        (0x01U << CRCPOLY_CR_RI_Pos)                      /*!<Reverse input*/
#define  CRCPOLY_CR_BEI_Pos                       (4)
#define  CRCPOLY_CR_BEI_Msk                       (0x01U << CRCPOLY_CR_BEI_Pos)                     /*!<Big-endian /little-endian selection for input*/
#define  CRCPOLY_CR_BEO_Pos                       (5)
#define  CRCPOLY_CR_BEO_Msk                       (0x01U << CRCPOLY_CR_BEO_Pos)                     /*!<Big-endian /little-endian selection for output*/
#define  CRCPOLY_CR_RO_Pos                        (6)
#define  CRCPOLY_CR_RO_Msk                        (0x01U << CRCPOLY_CR_RO_Pos)                      /*!<Reverse output*/
#define  CRCPOLY_CR_PWIDTH_Pos                    (14)
#define  CRCPOLY_CR_PWIDTH_Msk                    (0x03U << CRCPOLY_CR_PWIDTH_Pos)                  /*!<Polynomial width*/

/**
  * @brief CRCPOLY_IVR Register Bit Definition
  */
#define  CRCPOLY_IVR_IVR_Pos                      (0)
#define  CRCPOLY_IVR_IVR_Msk                      (0xFFFFFFFFU << CRCPOLY_IVR_IVR_Pos)              /*!<Initial value register*/

/**
  * @brief CRCPOLY_PR Register Bit Definition
  */
#define  CRCPOLY_PR_PR_Pos                        (0)
#define  CRCPOLY_PR_PR_Msk                        (0xFFFFFFFFU << CRCPOLY_PR_PR_Pos)                /*!<Polynomial register*/


#endif

