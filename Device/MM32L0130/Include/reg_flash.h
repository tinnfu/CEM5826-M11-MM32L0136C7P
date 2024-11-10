/***********************************************************************************************************************
    @file     reg_flash.h
    @author   VV TEAM
    @brief    This flie contains all the FLASH's register and its field definition.
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

#ifndef __REG_FLASH_H
#define __REG_FLASH_H


/* Files includes ----------------------------------------------------------------------------------------------------*/
#include <core_cm0plus.h>



/**
  * @brief FLASH Base Address Definition
  */
#define  FLASH_BASE                                0x40022000                                       /*!<Base Address: 0x40022000*/

/**
  * @brief FLASH Register Structure Definition
  */
typedef struct
{
    __IO uint32_t ACR;                            /*!<FLASH Flash access control register            offset: 0x00*/
    __IO uint32_t KEYR;                           /*!<FLASH FPEC key register                        offset: 0x04*/
    __IO uint32_t OPTKEYR;                        /*!<FLASH Flash OPTKEY register                    offset: 0x08*/
    __IO uint32_t SR;                             /*!<FLASH Flash status register                    offset: 0x0C*/
    __IO uint32_t CR;                             /*!<FLASH Flash control register                   offset: 0x10*/
    __IO uint32_t AR;                             /*!<FLASH Flash address register                   offset: 0x14*/
    __IO uint32_t RESERVED0x018[1];               /*!<                                               offset: 0x18*/
    __IO uint32_t OBR;                            /*!<FLASH Option byte register                     offset: 0x1C*/
    __IO uint32_t WRPR;                           /*!<FLASH Write protection register                offset: 0x20*/
} FLASH_TypeDef;

/**
  * @brief FLASH type pointer Definition
  */
#define FLASH                                     ((FLASH_TypeDef *)FLASH_BASE)

/**
  * @brief FLASH_ACR Register Bit Definition
  */
#define  FLASH_ACR_LATENCY_Pos                    (0)
#define  FLASH_ACR_LATENCY_Msk                    (0x07U << FLASH_ACR_LATENCY_Pos)                  /*!<Latency*/
#define  FLASH_ACR_PRFTBE_Pos                     (4)
#define  FLASH_ACR_PRFTBE_Msk                     (0x01U << FLASH_ACR_PRFTBE_Pos)                   /*!<Prefetch buffer enable*/
#define  FLASH_ACR_PRFTBS_Pos                     (5)
#define  FLASH_ACR_PRFTBS_Msk                     (0x01U << FLASH_ACR_PRFTBS_Pos)                   /*!<Prefetch buffer status*/

/**
  * @brief FLASH_KEYR Register Bit Definition
  */
#define  FLASH_KEYR_FKEYR_Pos                     (0)
#define  FLASH_KEYR_FKEYR_Msk                     (0xFFFFFFFFU << FLASH_KEYR_FKEYR_Pos)             /*!<FPEC Flash key*/

/**
  * @brief FLASH_OPTKEYR Register Bit Definition
  */
#define  FLASH_OPTKEYR_OPTKEYR_Pos                (0)
#define  FLASH_OPTKEYR_OPTKEYR_Msk                (0xFFFFFFFFU << FLASH_OPTKEYR_OPTKEYR_Pos)        /*!<Option byte key*/

/**
  * @brief FLASH_SR Register Bit Definition
  */
#define  FLASH_SR_BSY_Pos                         (0)
#define  FLASH_SR_BSY_Msk                         (0x01U << FLASH_SR_BSY_Pos)                       /*!<Busy*/
#define  FLASH_SR_PGERR_Pos                       (2)
#define  FLASH_SR_PGERR_Msk                       (0x01U << FLASH_SR_PGERR_Pos)                     /*!<Programming error*/
#define  FLASH_SR_WRPRTERR_Pos                    (4)
#define  FLASH_SR_WRPRTERR_Msk                    (0x01U << FLASH_SR_WRPRTERR_Pos)                  /*!<Write protection error*/
#define  FLASH_SR_EOP_Pos                         (5)
#define  FLASH_SR_EOP_Msk                         (0x01U << FLASH_SR_EOP_Pos)                       /*!<End of operation*/

/**
  * @brief FLASH_CR Register Bit Definition
  */
#define  FLASH_CR_PG_Pos                          (0)
#define  FLASH_CR_PG_Msk                          (0x01U << FLASH_CR_PG_Pos)                        /*!<Programming*/
#define  FLASH_CR_PER_Pos                         (1)
#define  FLASH_CR_PER_Msk                         (0x01U << FLASH_CR_PER_Pos)                       /*!<Page erase*/
#define  FLASH_CR_MER_Pos                         (2)
#define  FLASH_CR_MER_Msk                         (0x01U << FLASH_CR_MER_Pos)                       /*!<Mass erase*/
#define  FLASH_CR_OPTPG_Pos                       (4)
#define  FLASH_CR_OPTPG_Msk                       (0x01U << FLASH_CR_OPTPG_Pos)                     /*!<Option byte programming*/
#define  FLASH_CR_OPTER_Pos                       (5)
#define  FLASH_CR_OPTER_Msk                       (0x01U << FLASH_CR_OPTER_Pos)                     /*!<Option byte erase*/
#define  FLASH_CR_STRT_Pos                        (6)
#define  FLASH_CR_STRT_Msk                        (0x01U << FLASH_CR_STRT_Pos)                      /*!<Start*/
#define  FLASH_CR_LOCK_Pos                        (7)
#define  FLASH_CR_LOCK_Msk                        (0x01U << FLASH_CR_LOCK_Pos)                      /*!<Lock*/
#define  FLASH_CR_OPTWRE_Pos                      (9)
#define  FLASH_CR_OPTWRE_Msk                      (0x01U << FLASH_CR_OPTWRE_Pos)                    /*!<Option byte write enable*/

/**
  * @brief FLASH_AR Register Bit Definition
  */
#define  FLASH_AR_FAR_Pos                         (0)
#define  FLASH_AR_FAR_Msk                         (0xFFFFFFFFU << FLASH_AR_FAR_Pos)                 /*!<Flash Address*/

/**
  * @brief FLASH_OBR Register Bit Definition
  */
#define  FLASH_OBR_OPTERR_Pos                     (0)
#define  FLASH_OBR_OPTERR_Msk                     (0x01U << FLASH_OBR_OPTERR_Pos)                   /*!<Option byte error*/
#define  FLASH_OBR_RDPRT_Pos                      (1)
#define  FLASH_OBR_RDPRT_Msk                      (0x01U << FLASH_OBR_RDPRT_Pos)                    /*!<Read protection level status*/
#define  FLASH_OBR_WDG_SW_Pos                     (2)
#define  FLASH_OBR_WDG_SW_Msk                     (0x01U << FLASH_OBR_WDG_SW_Pos)                   /*!<Select watchdog event*/
#define  FLASH_OBR_nRST_STOP_Pos                  (3)
#define  FLASH_OBR_nRST_STOP_Msk                  (0x01U << FLASH_OBR_nRST_STOP_Pos)                /*!<Reset event in stop mode*/
#define  FLASH_OBR_nRST_STDBY_Pos                 (4)
#define  FLASH_OBR_nRST_STDBY_Msk                 (0x01U << FLASH_OBR_nRST_STDBY_Pos)               /*!<Reset event in standby mode*/
#define  FLASH_OBR_nRST_SHDN_Pos                  (5)
#define  FLASH_OBR_nRST_SHDN_Msk                  (0x01U << FLASH_OBR_nRST_SHDN_Pos)                /*!<Reset event in shutdown mode*/
#define  FLASH_OBR_nBOOT1_Pos                     (6)
#define  FLASH_OBR_nBOOT1_Msk                     (0x01U << FLASH_OBR_nBOOT1_Pos)                   /*!<nBOOT1*/
#define  FLASH_OBR_Data0_Pos                      (10)
#define  FLASH_OBR_Data0_Msk                      (0xFFU << FLASH_OBR_Data0_Pos)                    /*!<Data0*/
#define  FLASH_OBR_Data1_Pos                      (18)
#define  FLASH_OBR_Data1_Msk                      (0xFFU << FLASH_OBR_Data1_Pos)                    /*!<Data1*/

/**
  * @brief FLASH_WRPR Register Bit Definition
  */
#define  FLASH_WRPR_WRP_Pos                       (0)
#define  FLASH_WRPR_WRP_Msk                       (0xFFFFU << FLASH_WRPR_WRP_Pos)                   /*!<Write protect*/


#endif

