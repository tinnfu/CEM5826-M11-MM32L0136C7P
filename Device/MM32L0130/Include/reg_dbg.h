/***********************************************************************************************************************
    @file     reg_dbg.h
    @author   VV TEAM
    @brief    This flie contains all the DBG's register and its field definition.
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

#ifndef __REG_DBG_H
#define __REG_DBG_H


/* Files includes ----------------------------------------------------------------------------------------------------*/
#include <core_cm0plus.h>



/**
  * @brief DBG Base Address Definition
  */
#define  DBG_BASE                                  0x40013400                                       /*!<Base Address: 0x40013400*/

/**
  * @brief DBG Register Structure Definition
  */
typedef struct
{
    __IO uint32_t IDCODE;                         /*!<DBG DBG ID encode register                     offset: 0x00*/
    __IO uint32_t CR;                             /*!<DBG DBG control register                       offset: 0x04*/
} DBG_TypeDef;

/**
  * @brief DBG type pointer Definition
  */
#define DBG                                       ((DBG_TypeDef *)DBG_BASE)

/**
  * @brief DBG_IDCODE Register Bit Definition
  */
#define  DBG_IDCODE_DEV_ID_Pos                    (0)
#define  DBG_IDCODE_DEV_ID_Msk                    (0xFFFFFFFFU << DBG_IDCODE_DEV_ID_Pos)            /*!<Device IdentifierRead only register, always read as reset value*/

/**
  * @brief DBG_CR Register Bit Definition
  */
#define  DBG_CR_DBG_SLEEP_Pos                     (0)
#define  DBG_CR_DBG_SLEEP_Msk                     (0x01U << DBG_CR_DBG_SLEEP_Pos)                   /*!<Debug sleep mode*/
#define  DBG_CR_DBG_STOP_Pos                      (1)
#define  DBG_CR_DBG_STOP_Msk                      (0x01U << DBG_CR_DBG_STOP_Pos)                    /*!<Debug stop mode*/
#define  DBG_CR_DBG_STANDBY_Pos                   (2)
#define  DBG_CR_DBG_STANDBY_Msk                   (0x01U << DBG_CR_DBG_STANDBY_Pos)                 /*!<Debug standby mode*/
#define  DBG_CR_DBG_STOP_FOR_LDO_Pos              (3)
#define  DBG_CR_DBG_STOP_FOR_LDO_Msk              (0x01U << DBG_CR_DBG_STOP_FOR_LDO_Pos)            /*!<Debug stop mode LDO status*/
#define  DBG_CR_DBG_SHUTDWN_Pos                   (4)
#define  DBG_CR_DBG_SHUTDWN_Msk                   (0x01U << DBG_CR_DBG_SHUTDWN_Pos)                 /*!<Debug shutdown mode*/
#define  DBG_CR_DBG_IWDG_STOP_Pos                 (8)
#define  DBG_CR_DBG_IWDG_STOP_Msk                 (0x01U << DBG_CR_DBG_IWDG_STOP_Pos)               /*!<Independent watchdog stops workThis bit is not related to whether the core enters the debug status*/
#define  DBG_CR_DBG_WWDG_STOP_Pos                 (9)
#define  DBG_CR_DBG_WWDG_STOP_Msk                 (0x01U << DBG_CR_DBG_WWDG_STOP_Pos)               /*!<The debug window watchdog stops work when the core enters the debug mode*/
#define  DBG_CR_DBG_TIM3_STOP_Pos                 (12)
#define  DBG_CR_DBG_TIM3_STOP_Msk                 (0x01U << DBG_CR_DBG_TIM3_STOP_Pos)               /*!<TIM3 stops work when the core enters the debug mode*/
#define  DBG_CR_DBG_TIM4_STOP_Pos                 (13)
#define  DBG_CR_DBG_TIM4_STOP_Msk                 (0x01U << DBG_CR_DBG_TIM4_STOP_Pos)               /*!<TIM4 stops work when the core enters the debug mode*/
#define  DBG_CR_DBG_TIM16_STOP_Pos                (16)
#define  DBG_CR_DBG_TIM16_STOP_Msk                (0x01U << DBG_CR_DBG_TIM16_STOP_Pos)              /*!<TIM16 stops work when the core enters the debug mode*/
#define  DBG_CR_DBG_TIM17_STOP_Pos                (17)
#define  DBG_CR_DBG_TIM17_STOP_Msk                (0x01U << DBG_CR_DBG_TIM17_STOP_Pos)              /*!<TIM17 stops work when the core enters the debug mode*/
#define  DBG_CR_DBG_LPTIMER_STOP_Pos              (20)
#define  DBG_CR_DBG_LPTIMER_STOP_Msk              (0x01U << DBG_CR_DBG_LPTIMER_STOP_Pos)            /*!<LPTIMER stops work when the core enters the debug mode*/


#endif

