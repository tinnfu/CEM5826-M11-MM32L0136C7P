/***********************************************************************************************************************
    @file     reg_iwdg.h
    @author   VV TEAM
    @brief    This flie contains all the IWDG's register and its field definition.
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

#ifndef __REG_IWDG_H
#define __REG_IWDG_H


/* Files includes ----------------------------------------------------------------------------------------------------*/
#include <core_cm0plus.h>



/**
  * @brief IWDG Base Address Definition
  */
#define  IWDG_BASE                                 0x40003000                                       /*!<Base Address: 0x40003000*/

/**
  * @brief IWDG Register Structure Definition
  */
typedef struct
{
    __IO uint32_t KR;                             /*!<IWDG Key register                              offset: 0x00*/
    __IO uint32_t PR;                             /*!<IWDG Prescaler register                        offset: 0x04*/
    __IO uint32_t RLR;                            /*!<IWDG Reload register                           offset: 0x08*/
    __IO uint32_t SR;                             /*!<IWDG Status register                           offset: 0x0C*/
    __IO uint32_t CR;                             /*!<IWDG Control register                          offset: 0x10*/
    __IO uint32_t IGEN;                           /*!<IWDG Interrupt generate register               offset: 0x14*/
    __IO uint32_t CNT;                            /*!<IWDG Counter register                          offset: 0x18*/
    __IO uint32_t PS;                             /*!<IWDG Prescaler counter register                offset: 0x1C*/
} IWDG_TypeDef;

/**
  * @brief IWDG type pointer Definition
  */
#define IWDG                                      ((IWDG_TypeDef *)IWDG_BASE)

/**
  * @brief IWDG_KR Register Bit Definition
  */
#define  IWDG_KR_KEY_Pos                          (0)
#define  IWDG_KR_KEY_Msk                          (0xFFFFU << IWDG_KR_KEY_Pos)                      /*!<Key value (write-only register)These bits must be written by software at regular intervals with 0XAAAA to feed the dog, otherwise a reset signal is generated to reset the system when the counter decrements to 0x0000.Writing 0x5555 by software may disable the protection and enable access to other configuration registers (IWDG_PR, IWDG_RLR, IWDG_CR (bit0), IWDG_IGEN).Writing 0xCCCC by software starts the watchdog.*/

/**
  * @brief IWDG_PR Register Bit Definition
  */
#define  IWDG_PR_PR_Pos                           (0)
#define  IWDG_PR_PR_Msk                           (0x07U << IWDG_PR_PR_Pos)                         /*!<Prescaler dividerThese bits are set to select the prescaler dividers of the LSI clock.To modify prescaler dividers, the protection should be disabled at first (write 0x5555 to IWDG_KE). After the prescaler dividers are updated, The PUV bit in the register becomes 0. At this time, the value read from this register is valid.*/

/**
  * @brief IWDG_RLR Register Bit Definition
  */
#define  IWDG_RLR_RL_Pos                          (0)
#define  IWDG_RLR_RL_Msk                          (0x0FFFU << IWDG_RLR_RL_Pos)                      /*!<Watchdog counter reload valueThese bits serve to define the reload value of the watchdog counter. This value will update to the counter each time the dog is fed (write 0xAAAA to IWDG_KR register). Subsequently, the watchdog counter counts down from this value. To modify the reload values, the protection should be disabled at first (write 0x5555 to IWDG_KR). After the reload values are updated, the RUV bit in the register becomes 0. At this time, the value read from this register is valid. The watchdog timeout period is a function of this reload value and the prescaler.*/

/**
  * @brief IWDG_SR Register Bit Definition
  */
#define  IWDG_SR_PVU_Pos                          (0)
#define  IWDG_SR_PVU_Msk                          (0x01U << IWDG_SR_PVU_Pos)                        /*!<Watchdog prescaler value updateThis bit is set when an update of the prescaler value is ongoing.*/
#define  IWDG_SR_RVU_Pos                          (1)
#define  IWDG_SR_RVU_Msk                          (0x01U << IWDG_SR_RVU_Pos)                        /*!<Watchdog counter reload value updateThis bit is set when an update of the reload value is ongoing.*/
#define  IWDG_SR_IVU_Pos                          (2)
#define  IWDG_SR_IVU_Msk                          (0x01U << IWDG_SR_IVU_Pos)                        /*!<Watchdog Interrupt Generate value updateThis bit is set by hardware to indicate that an update of the interrupt generate value is ongoing.*/
#define  IWDG_SR_UPDATE_Pos                       (3)
#define  IWDG_SR_UPDATE_Msk                       (0x01U << IWDG_SR_UPDATE_Pos)                     /*!<Watchdog reload value update flagThe UPDATE is set when 0XAAAA is written into the IWDG_KR register. It is cleared automatically when the watchdog counter is updated and the reload value is written into the counter.*/

/**
  * @brief IWDG_CR Register Bit Definition
  */
#define  IWDG_CR_IRQ_SEL_Pos                      (0)
#define  IWDG_CR_IRQ_SEL_Msk                      (0x01U << IWDG_CR_IRQ_SEL_Pos)                    /*!<IWDG overflow operation select*/
#define  IWDG_CR_IRQ_CLR_Pos                      (1)
#define  IWDG_CR_IRQ_CLR_Msk                      (0x01U << IWDG_CR_IRQ_CLR_Pos)                    /*!<IWDG interrupt clear*/

/**
  * @brief IWDG_IGEN Register Bit Definition
  */
#define  IWDG_IGEN_IGEN_Pos                       (0)
#define  IWDG_IGEN_IGEN_Msk                       (0x0FFFU << IWDG_IGEN_IGEN_Pos)                   /*!<IWDG Interrupt Generate valueThese bits serve to define the interrupt generate value of the watchdog. An interrupt is generated when the counter counts down until it reaches this value.The protection should be disabled before changing it*/

/**
  * @brief IWDG_CNT Register Bit Definition
  */
#define  IWDG_CNT_IWDG_CNT_Pos                    (0)
#define  IWDG_CNT_IWDG_CNT_Msk                    (0x0FFFU << IWDG_CNT_IWDG_CNT_Pos)                /*!<IWDG counter value*/

/**
  * @brief IWDG_PS Register Bit Definition
  */
#define  IWDG_PS_IWDG_PS_Pos                      (0)
#define  IWDG_PS_IWDG_PS_Msk                      (0xFFU << IWDG_PS_IWDG_PS_Pos)                    /*!<Value of the prescaler counter of the IWDG clock*/


#endif

