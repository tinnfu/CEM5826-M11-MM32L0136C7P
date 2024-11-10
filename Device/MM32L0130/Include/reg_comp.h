/***********************************************************************************************************************
    @file     reg_comp.h
    @author   VV TEAM
    @brief    This flie contains all the COMP's register and its field definition.
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

#ifndef __REG_COMP_H
#define __REG_COMP_H


/* Files includes ----------------------------------------------------------------------------------------------------*/
#include <core_cm0plus.h>



/**
  * @brief COMP Base Address Definition
  */
#define  COMP_BASE                                 0x40013C00                                       /*!<Base Address: 0x40013C00*/

/**
  * @brief COMP Register Structure Definition
  */
typedef struct
{
    __IO uint32_t COMP1CSR;                       /*!<COMP COMP x (x=1) control and status register  offset: 0x00*/
    __IO uint32_t RESERVED0x004[5];               /*!<                                               offset: 0x4~0x14*/
    __IO uint32_t CRV;                            /*!<COMP COMP external reference voltage register  offset: 0x18*/
    __IO uint32_t COMP1POLL;                      /*!<COMP COMP x (x=1) polling register             offset: 0x1C*/
} COMP_TypeDef;

/**
  * @brief COMP type pointer Definition
  */
#define COMP                                      ((COMP_TypeDef *)COMP_BASE)

/**
  * @brief COMP_COMP1CSR Register Bit Definition
  */
#define  COMP_COMP1CSR_EN_Pos                     (0)
#define  COMP_COMP1CSR_EN_Msk                     (0x01U << COMP_COMP1CSR_EN_Pos)                   /*!<Comparator x EnableThis bit switches ON/OFF the comparator.*/
#define  COMP_COMP1CSR_MODE_Pos                   (2)
#define  COMP_COMP1CSR_MODE_Msk                   (0x03U << COMP_COMP1CSR_MODE_Pos)                 /*!<Comparator x ModeThese bits control the operating mode of the comparator x and allows to adjust the speed/consumption.*/
#define  COMP_COMP1CSR_INM_SEL_Pos                (4)
#define  COMP_COMP1CSR_INM_SEL_Msk                (0x07U << COMP_COMP1CSR_INM_SEL_Pos)              /*!<Comparator x Negative Input SelectionThese bits allows to select the source connected to the negative input end of the comparator x.*/
#define  COMP_COMP1CSR_INP_SEL_Pos                (7)
#define  COMP_COMP1CSR_INP_SEL_Msk                (0x03U << COMP_COMP1CSR_INP_SEL_Pos)              /*!<Comparator x Positive Input SelectionThese bits allows to select the source connected to the positive input end of the comparator x.*/
#define  COMP_COMP1CSR_OUT_SEL_Pos                (10)
#define  COMP_COMP1CSR_OUT_SEL_Msk                (0x0FU << COMP_COMP1CSR_OUT_SEL_Pos)              /*!<Comparator x Output SelectionThese bits select the destination of the comparator x output.*/
#define  COMP_COMP1CSR_POL_Pos                    (15)
#define  COMP_COMP1CSR_POL_Msk                    (0x01U << COMP_COMP1CSR_POL_Pos)                  /*!<Comparator x Output PolarityThis bit is used to select the comparator x output polarity*/
#define  COMP_COMP1CSR_HYST_Pos                   (16)
#define  COMP_COMP1CSR_HYST_Msk                   (0x03U << COMP_COMP1CSR_HYST_Pos)                 /*!<Comparator x HysteresisThese bits control the comparator x hysteresis level.*/
#define  COMP_COMP1CSR_OFLT_Pos                   (18)
#define  COMP_COMP1CSR_OFLT_Msk                   (0x07U << COMP_COMP1CSR_OFLT_Pos)                 /*!<Comparator x Output Filter PeriodThese bits control the comparator x output filter period. When the comparator output signal is shorter than the filter period width, it is considered as invalid to be filtered out, otherwise it is considered as valid. n indicates the number of Polling Wait Cycle configured with COMPx_CSR -> PERIOD.*/
#define  COMP_COMP1CSR_OUT_ANA_SEL_Pos            (29)
#define  COMP_COMP1CSR_OUT_ANA_SEL_Msk            (0x01U << COMP_COMP1CSR_OUT_ANA_SEL_Pos)          /*!<Comparator x output source selection*/
#define  COMP_COMP1CSR_OUT_Pos                    (30)
#define  COMP_COMP1CSR_OUT_Msk                    (0x01U << COMP_COMP1CSR_OUT_Pos)                  /*!<Comparator x Output This bit indicates the comparator x output state.*/
#define  COMP_COMP1CSR_LOCK_Pos                   (31)
#define  COMP_COMP1CSR_LOCK_Msk                   (0x01U << COMP_COMP1CSR_LOCK_Pos)                 /*!<Comparator Register LockThis bit is write-once. It is set by software. It can be cleared by a system reset. Once set, it allows to have all control bits of comparator x as read-only.*/

/**
  * @brief COMP_CRV Register Bit Definition
  */
#define  COMP_CRV_CRV_SEL_Pos                     (0)
#define  COMP_CRV_CRV_SEL_Msk                     (0x3FU << COMP_CRV_CRV_SEL_Pos)                   /*!<Comparator Reference Voltage Select*/
#define  COMP_CRV_CRV_SRC_Pos                     (12)
#define  COMP_CRV_CRV_SRC_Msk                     (0x01U << COMP_CRV_CRV_SRC_Pos)                   /*!<Comparator Reference Voltage Source Select*/
#define  COMP_CRV_CRV_EN_Pos                      (15)
#define  COMP_CRV_CRV_EN_Msk                      (0x01U << COMP_CRV_CRV_EN_Pos)                    /*!<Comparator Reference Voltage Enable*/

/**
  * @brief COMP_COMP1POLL Register Bit Definition
  */
#define  COMP_COMP1POLL_POLL_EN_Pos               (0)
#define  COMP_COMP1POLL_POLL_EN_Msk               (0x01U << COMP_COMP1POLL_POLL_EN_Pos)             /*!<Comparator Polling Enable*/
#define  COMP_COMP1POLL_POLL_CH_Pos               (1)
#define  COMP_COMP1POLL_POLL_CH_Msk               (0x01U << COMP_COMP1POLL_POLL_CH_Pos)             /*!<Comparator Polling Channel*/
#define  COMP_COMP1POLL_FIXN_Pos                  (2)
#define  COMP_COMP1POLL_FIXN_Msk                  (0x01U << COMP_COMP1POLL_FIXN_Pos)                /*!<Polling Negative Input Fix*/
#define  COMP_COMP1POLL_PERIOD_Pos                (4)
#define  COMP_COMP1POLL_PERIOD_Msk                (0x07U << COMP_COMP1POLL_PERIOD_Pos)              /*!<Polling Wait CycleSwitch to the next polling channel every n PCLK2 cycles.*/
#define  COMP_COMP1POLL_POUT_Pos                  (8)
#define  COMP_COMP1POLL_POUT_Msk                  (0x07U << COMP_COMP1POLL_POUT_Pos)                /*!<Polling OutputThis bit is read-only. It reflects the polling channel output state. POUT[0] corresponds to channel 1. POUT[1] corresponds to channel 2. POUT[2] corresponds to channel 3.*/


#endif

