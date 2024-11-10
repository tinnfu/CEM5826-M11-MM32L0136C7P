/***********************************************************************************************************************
    @file     reg_spi.h
    @author   VV TEAM
    @brief    This flie contains all the SPI's register and its field definition.
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

#ifndef __REG_SPI_H
#define __REG_SPI_H


/* Files includes ----------------------------------------------------------------------------------------------------*/
#include <core_cm0plus.h>



/**
  * @brief SPI Base Address Definition
  */
#define  SPI1_BASE                                 0x40013000                                       /*!<Base Address: 0x40013000*/
#define  SPI2_BASE                                 0x40003800                                       /*!<Base Address: 0x40003800*/

/**
  * @brief SPI Register Structure Definition
  */
typedef struct
{
    __IO uint32_t TXREG;                          /*!<SPI Transmission Data Register                 offset: 0x00*/
    __IO uint32_t RXREG;                          /*!<SPI Receipt Data Register                      offset: 0x04*/
    __IO uint32_t CSTAT;                          /*!<SPI Current Status Register                    offset: 0x08*/
    __IO uint32_t INTSTAT;                        /*!<SPI Interrupt Status Register                  offset: 0x0C*/
    __IO uint32_t INTEN;                          /*!<SPI Interrupt Enable Register                  offset: 0x10*/
    __IO uint32_t INTCLR;                         /*!<SPI Interrupt Clear Register                   offset: 0x14*/
    __IO uint32_t GCTL;                           /*!<SPI Global Control Register                    offset: 0x18*/
    __IO uint32_t CCTL;                           /*!<SPI Universal Control Register                 offset: 0x1C*/
    __IO uint32_t SPBRG;                          /*!<SPI Baud Rate Generator                        offset: 0x20*/
    __IO uint32_t RXDNR;                          /*!<SPI Receipt Data Number Register               offset: 0x24*/
    __IO uint32_t NSSR;                           /*!<SPI Slave Chip Selection Register              offset: 0x28*/
    __IO uint32_t EXTCTL;                         /*!<SPI Data Length Control Register               offset: 0x2C*/
    __IO uint32_t I2SCFGR;                        /*!<SPI I2S Configuration Register                 offset: 0x30*/
} SPI_TypeDef;

/**
  * @brief SPI type pointer Definition
  */
#define SPI1                                      ((SPI_TypeDef *)SPI1_BASE)
#define SPI2                                      ((SPI_TypeDef *)SPI2_BASE)

/**
  * @brief SPI_TXREG Register Bit Definition
  */
#define  SPI_TXREG_TXREG_Pos                      (0)
#define  SPI_TXREG_TXREG_Msk                      (0xFFFFFFFFU << SPI_TXREG_TXREG_Pos)              /*!<Transmission data registerValid data bit is controlled by DW8_32:DW8_32=0, only valid in low 8 bitDW8_32=1, TXREG[31:0] valid*/

/**
  * @brief SPI_RXREG Register Bit Definition
  */
#define  SPI_RXREG_RXREG_Pos                      (0)
#define  SPI_RXREG_RXREG_Msk                      (0xFFFFFFFFU << SPI_RXREG_RXREG_Pos)              /*!<Receipt data registerValid data bit is controlled by DW8_32.DW8_32=0:Only valid in low 8 bit DW8_32=1:RXREG[31:0] validNote: The register is readable, but not writable.*/

/**
  * @brief SPI_CSTAT Register Bit Definition
  */
#define  SPI_CSTAT_TXEPT_Pos                      (0)
#define  SPI_CSTAT_TXEPT_Msk                      (0x01U << SPI_CSTAT_TXEPT_Pos)                    /*!<Transmission empty bit*/
#define  SPI_CSTAT_RXAVL_Pos                      (1)
#define  SPI_CSTAT_RXAVL_Msk                      (0x01U << SPI_CSTAT_RXAVL_Pos)                    /*!<Receipt valid byte data message bit When the receipt buffer receives a complete byte data, the bit is set.*/
#define  SPI_CSTAT_TXFULL_Pos                     (2)
#define  SPI_CSTAT_TXFULL_Msk                     (0x01U << SPI_CSTAT_TXFULL_Pos)                   /*!<Transmission buffer full flag bit*/
#define  SPI_CSTAT_RXAVL_4BYTE_Pos                (3)
#define  SPI_CSTAT_RXAVL_4BYTE_Msk                (0x01U << SPI_CSTAT_RXAVL_4BYTE_Pos)              /*!<Valid data in the receipt buffer reaches 4 byte flag bit*/
#define  SPI_CSTAT_TXFADDR_Pos                    (4)
#define  SPI_CSTAT_TXFADDR_Msk                    (0x0FU << SPI_CSTAT_TXFADDR_Pos)                  /*!<Number of valid byte in the transmission buffer*/
#define  SPI_CSTAT_RXFADDR_Pos                    (8)
#define  SPI_CSTAT_RXFADDR_Msk                    (0x0FU << SPI_CSTAT_RXFADDR_Pos)                  /*!<Number of valid byte in the current buffer*/
#define  SPI_CSTAT_BUSY_Pos                       (12)
#define  SPI_CSTAT_BUSY_Msk                       (0x01U << SPI_CSTAT_BUSY_Pos)                     /*!<Busy flag bitIndicate I2S or SPI transmission is ongoing*/
#define  SPI_CSTAT_CHSIDE_Pos                     (13)
#define  SPI_CSTAT_CHSIDE_Msk                     (0x01U << SPI_CSTAT_CHSIDE_Pos)                   /*!<Audio flag bit*/

/**
  * @brief SPI_INTSTAT Register Bit Definition
  */
#define  SPI_INTSTAT_TX_INTF_Pos                  (0)
#define  SPI_INTSTAT_TX_INTF_Msk                  (0x01U << SPI_INTSTAT_TX_INTF_Pos)                /*!<Transmission buffer empty interrupt flag bit (buffer is empty, can write TXREG)Auto set by the hardware, auto clear when the transmission buffer is not empty.*/
#define  SPI_INTSTAT_RX_INTF_Pos                  (1)
#define  SPI_INTSTAT_RX_INTF_Msk                  (0x01U << SPI_INTSTAT_RX_INTF_Pos)                /*!<Receipt data valid interrupt flag bitAuto set by the hardware, clear by writing INTCLR. RX_ICLR bit as '1'. When the receipt buffer receives a complete valid data.*/
#define  SPI_INTSTAT_UNDERRUN_INTF_Pos            (2)
#define  SPI_INTSTAT_UNDERRUN_INTF_Msk            (0x01U << SPI_INTSTAT_UNDERRUN_INTF_Pos)          /*!<SPI auxiliary mode underflow interrupt flag bit Auto set by the hardware, clear by writing INTCLR.UNDERRUN_ICLR bit as '1'.*/
#define  SPI_INTSTAT_RXOERR_INTF_Pos              (3)
#define  SPI_INTSTAT_RXOERR_INTF_Msk              (0x01U << SPI_INTSTAT_RXOERR_INTF_Pos)            /*!<Receipt overflow error interrupt flag bitAuto set by the hardware, clear by writing INTCLR. RXOERR_ICLR bit as '1'.*/
#define  SPI_INTSTAT_RXMATCH_INTF_Pos             (4)
#define  SPI_INTSTAT_RXMATCH_INTF_Msk             (0x01U << SPI_INTSTAT_RXMATCH_INTF_Pos)           /*!<Receipt specified byte interrupt flag bitAuto set by the hardware, clear by writing INTCLR.RXMATCH_ICLR bit as '1'.*/
#define  SPI_INTSTAT_RXFULL_INTF_Pos              (5)
#define  SPI_INTSTAT_RXFULL_INTF_Msk              (0x01U << SPI_INTSTAT_RXFULL_INTF_Pos)            /*!<Receipt buffer full interrupt flag bitAuto set by the hardware, clear by writing INTCLR. RXFULL_ICLR bit as '1'.*/
#define  SPI_INTSTAT_TXEPT_INTF_Pos               (6)
#define  SPI_INTSTAT_TXEPT_INTF_Msk               (0x01U << SPI_INTSTAT_TXEPT_INTF_Pos)             /*!<Transmission empty interrupt flag bit Auto set by the hardware, clear by writing the INTCLR. TXEPT_ICLR bit as '1'.*/
#define  SPI_INTSTAT_FRE_INTF_Pos                 (7)
#define  SPI_INTSTAT_FRE_INTF_Msk                 (0x01U << SPI_INTSTAT_FRE_INTF_Pos)               /*!<Frame transmission error interrupt flag bitIndicate I2S transmission protocol doesn't match (only valid in the slave mode)*/

/**
  * @brief SPI_INTEN Register Bit Definition
  */
#define  SPI_INTEN_TX_IEN_Pos                     (0)
#define  SPI_INTEN_TX_IEN_Msk                     (0x01U << SPI_INTEN_TX_IEN_Pos)                   /*!<Transmission buffer empty interrupt enable bit*/
#define  SPI_INTEN_RX_IEN_Pos                     (1)
#define  SPI_INTEN_RX_IEN_Msk                     (0x01U << SPI_INTEN_RX_IEN_Pos)                   /*!<Receipt data interrupt enable bit*/
#define  SPI_INTEN_UNDERRUN_IEN_Pos               (2)
#define  SPI_INTEN_UNDERRUN_IEN_Msk               (0x01U << SPI_INTEN_UNDERRUN_IEN_Pos)             /*!<SPI auxiliary mode underflow interrupt enable bit*/
#define  SPI_INTEN_RXOERR_IEN_Pos                 (3)
#define  SPI_INTEN_RXOERR_IEN_Msk                 (0x01U << SPI_INTEN_RXOERR_IEN_Pos)               /*!<Receipt overflow error interrupt enable bit*/
#define  SPI_INTEN_RXMATCH_IEN_Pos                (4)
#define  SPI_INTEN_RXMATCH_IEN_Msk                (0x01U << SPI_INTEN_RXMATCH_IEN_Pos)              /*!<Receipt specified byte interrupt enable bit*/
#define  SPI_INTEN_RXFULL_IEN_Pos                 (5)
#define  SPI_INTEN_RXFULL_IEN_Msk                 (0x01U << SPI_INTEN_RXFULL_IEN_Pos)               /*!<Receipt buffer full interrupt enable bit*/
#define  SPI_INTEN_TXEPT_IEN_Pos                  (6)
#define  SPI_INTEN_TXEPT_IEN_Msk                  (0x01U << SPI_INTEN_TXEPT_IEN_Pos)                /*!<Transmission empty interrupt enable bit*/
#define  SPI_INTEN_FRE_IEN_Pos                    (7)
#define  SPI_INTEN_FRE_IEN_Msk                    (0x01U << SPI_INTEN_FRE_IEN_Pos)                  /*!<Frame transmission error interrupt enable(FRE_IEN):*/

/**
  * @brief SPI_INTCLR Register Bit Definition
  */
#define  SPI_INTCLR_TX_ICLR_Pos                   (0)
#define  SPI_INTCLR_TX_ICLR_Msk                   (0x01U << SPI_INTCLR_TX_ICLR_Pos)                 /*!<Transmission buffer empty interrupt clear bit*/
#define  SPI_INTCLR_RX_ICLR_Pos                   (1)
#define  SPI_INTCLR_RX_ICLR_Msk                   (0x01U << SPI_INTCLR_RX_ICLR_Pos)                 /*!<Receipt interrupt clear bit*/
#define  SPI_INTCLR_UNDERRUN_ICLR_Pos             (2)
#define  SPI_INTCLR_UNDERRUN_ICLR_Msk             (0x01U << SPI_INTCLR_UNDERRUN_ICLR_Pos)           /*!<SPI auxiliary mode underflow interrupt clear bit*/
#define  SPI_INTCLR_RXOERR_ICLR_Pos               (3)
#define  SPI_INTCLR_RXOERR_ICLR_Msk               (0x01U << SPI_INTCLR_RXOERR_ICLR_Pos)             /*!<Receipt overflow error interrupt clear bit*/
#define  SPI_INTCLR_RXMATCH_ICLR_Pos              (4)
#define  SPI_INTCLR_RXMATCH_ICLR_Msk              (0x01U << SPI_INTCLR_RXMATCH_ICLR_Pos)            /*!<Receipt specified byte interrupt clear bit*/
#define  SPI_INTCLR_RXFULL_ICLR_Pos               (5)
#define  SPI_INTCLR_RXFULL_ICLR_Msk               (0x01U << SPI_INTCLR_RXFULL_ICLR_Pos)             /*!<Receipt buffer full interrupt clear bit*/
#define  SPI_INTCLR_TXEPT_ICLR_Pos                (6)
#define  SPI_INTCLR_TXEPT_ICLR_Msk                (0x01U << SPI_INTCLR_TXEPT_ICLR_Pos)              /*!<Transmission empty interrupt clear bi*/
#define  SPI_INTCLR_FRE_ICLR_Pos                  (7)
#define  SPI_INTCLR_FRE_ICLR_Msk                  (0x01U << SPI_INTCLR_FRE_ICLR_Pos)                /*!<Frame transmission error interrupt clear:*/

/**
  * @brief SPI_GCTL Register Bit Definition
  */
#define  SPI_GCTL_SPIEN_Pos                       (0)
#define  SPI_GCTL_SPIEN_Msk                       (0x01U << SPI_GCTL_SPIEN_Pos)                     /*!<SPI/I2S selection bit*/
#define  SPI_GCTL_INTEN_Pos                       (1)
#define  SPI_GCTL_INTEN_Msk                       (0x01U << SPI_GCTL_INTEN_Pos)                     /*!<SPI/I2S interrupt enable bit*/
#define  SPI_GCTL_MODE_Pos                        (2)
#define  SPI_GCTL_MODE_Msk                        (0x01U << SPI_GCTL_MODE_Pos)                      /*!<Host mode bit*/
#define  SPI_GCTL_TXEN_Pos                        (3)
#define  SPI_GCTL_TXEN_Msk                        (0x01U << SPI_GCTL_TXEN_Pos)                      /*!<Transmission enable bit*/
#define  SPI_GCTL_RXEN_Pos                        (4)
#define  SPI_GCTL_RXEN_Msk                        (0x01U << SPI_GCTL_RXEN_Pos)                      /*!<Receipt enable bit*/
#define  SPI_GCTL_DMAMODE_Pos                     (9)
#define  SPI_GCTL_DMAMODE_Msk                     (0x01U << SPI_GCTL_DMAMODE_Pos)                   /*!<DMA mode selection bit*/
#define  SPI_GCTL_NSS_Pos                         (10)
#define  SPI_GCTL_NSS_Msk                         (0x01U << SPI_GCTL_NSS_Pos)                       /*!<NSS output in the hardware or software control master mode*/
#define  SPI_GCTL_DW8_32_Pos                      (11)
#define  SPI_GCTL_DW8_32_Msk                      (0x01U << SPI_GCTL_DW8_32_Pos)                    /*!<Transmission and receipt data register valid data selection*/
#define  SPI_GCTL_PAD_SEL_Pos                     (13)
#define  SPI_GCTL_PAD_SEL_Msk                     (0x1FU << SPI_GCTL_PAD_SEL_Pos)                   /*!<PAD0,PAD1,PAD2,PAD3 respectively correspond to SCK, MOSI, NSS and MISO pins of pins. Mapping change of signal SCL, MOSI, NSS, MISO and PAD:PAD_SEL SCL MOSI NSS MISO*/

/**
  * @brief SPI_CCTL Register Bit Definition
  */
#define  SPI_CCTL_CPHA_Pos                        (0)
#define  SPI_CCTL_CPHA_Msk                        (0x01U << SPI_CCTL_CPHA_Pos)                      /*!<Clock phase selection bit*/
#define  SPI_CCTL_CPOL_Pos                        (1)
#define  SPI_CCTL_CPOL_Msk                        (0x01U << SPI_CCTL_CPOL_Pos)                      /*!<Clock polarity flag bit*/
#define  SPI_CCTL_LSBFE_Pos                       (2)
#define  SPI_CCTL_LSBFE_Msk                       (0x01U << SPI_CCTL_LSBFE_Pos)                     /*!<LSBFE:LSB front enable bit*/
#define  SPI_CCTL_SPILEN_Pos                      (3)
#define  SPI_CCTL_SPILEN_Msk                      (0x01U << SPI_CCTL_SPILEN_Pos)                    /*!<SPI data width bitThis bit works after DW8_32 setting (DW8_32 =0); this bit should be kept as 1 during DW8_32=1.*/
#define  SPI_CCTL_RXEDGE_Pos                      (4)
#define  SPI_CCTL_RXEDGE_Msk                      (0x01U << SPI_CCTL_RXEDGE_Pos)                    /*!<Receipt data sampling clock edge selection bit (master mode)*/
#define  SPI_CCTL_TXEDGE_Pos                      (5)
#define  SPI_CCTL_TXEDGE_Msk                      (0x01U << SPI_CCTL_TXEDGE_Pos)                    /*!<Transmission data phase bit adjustment (slave mode)*/
#define  SPI_CCTL_CPHASEL_Pos                     (6)
#define  SPI_CCTL_CPHASEL_Msk                     (0x01U << SPI_CCTL_CPHASEL_Pos)                   /*!<CPHA polarity inversion selection*/

/**
  * @brief SPI_SPBRG Register Bit Definition
  */
#define  SPI_SPBRG_SPBRG_Pos                      (0)
#define  SPI_SPBRG_SPBRG_Msk                      (0xFFFFU << SPI_SPBRG_SPBRG_Pos)                  /*!<SPI baud rate control register for baud rateBaud rate formula:Baud rate = Fpclk/SPBRG(Fpclk is APB clock frequency)Note: Don't write 0 and 1 in the register.*/

/**
  * @brief SPI_RXDNR Register Bit Definition
  */
#define  SPI_RXDNR_RXDNR_Pos                      (0)
#define  SPI_RXDNR_RXDNR_Msk                      (0xFFFFU << SPI_RXDNR_RXDNR_Pos)                  /*!<The register is used to hold a count of to be received in the next receipt processNote: The register value is valid when SPI is in the host receipt mode. The default value is 1.The register value changes by MCU write value, and don't write the '0' value in the register.*/

/**
  * @brief SPI_NSSR Register Bit Definition
  */
#define  SPI_NSSR_NSS_Pos                         (0)
#define  SPI_NSSR_NSS_Msk                         (0x01U << SPI_NSSR_NSS_Pos)                       /*!<The chip selection output signal in the master mode. Low valid, the bit is invalid in the slave mode*/

/**
  * @brief SPI_EXTCTL Register Bit Definition
  */
#define  SPI_EXTCTL_EXTLEN_Pos                    (0)
#define  SPI_EXTCTL_EXTLEN_Msk                    (0x1FU << SPI_EXTCTL_EXTLEN_Pos)                  /*!<Control SPI data length*/

/**
  * @brief SPI_I2SCFGR Register Bit Definition
  */
#define  SPI_I2SCFGR_CHLEN_Pos                    (0)
#define  SPI_I2SCFGR_CHLEN_Msk                    (0x01U << SPI_I2SCFGR_CHLEN_Pos)                  /*!<Audio length (data bit number contained in each audio)*/
#define  SPI_I2SCFGR_DATLEN_Pos                   (1)
#define  SPI_I2SCFGR_DATLEN_Msk                   (0x03U << SPI_I2SCFGR_DATLEN_Pos)                 /*!<Data length*/
#define  SPI_I2SCFGR_I2SSTD_Pos                   (4)
#define  SPI_I2SCFGR_I2SSTD_Msk                   (0x03U << SPI_I2SCFGR_I2SSTD_Pos)                 /*!<I2S standard*/
#define  SPI_I2SCFGR_PCMSYNC_Pos                  (6)
#define  SPI_I2SCFGR_PCMSYNC_Msk                  (0x01U << SPI_I2SCFGR_PCMSYNC_Pos)                /*!<PCM standard frame sync mode*/
#define  SPI_I2SCFGR_SPI_I2S_Pos                  (10)
#define  SPI_I2SCFGR_SPI_I2S_Msk                  (0x01U << SPI_I2SCFGR_SPI_I2S_Pos)                /*!<Module function selection*/
#define  SPI_I2SCFGR_MCKOE_Pos                    (11)
#define  SPI_I2SCFGR_MCKOE_Msk                    (0x01U << SPI_I2SCFGR_MCKOE_Pos)                  /*!<MCK clock output enable*/
#define  SPI_I2SCFGR_I2SDIV_Pos                   (16)
#define  SPI_I2SCFGR_I2SDIV_Msk                   (0x01FFU << SPI_I2SCFGR_I2SDIV_Pos)               /*!<I2S prescaler division factor*/

//Add it manually. This definition is not available in UM.20230721
#define SPI_I2SCFGR_MCKSEL_Pos                    (12)
#define SPI_I2SCFGR_MCKSEL_Msk                    (0x01U << SPI_I2SCFGR_MCKSEL_Pos)       /*!<  MCK output signal selection */
#define SPI_I2SCFGR_HDSEL_Pos                     (13)
#define SPI_I2SCFGR_HDSEL_Msk                     (0x01U << SPI_I2SCFGR_HDSEL_Pos)        /*!<  I2S full duplex, half duplex options */



#endif

