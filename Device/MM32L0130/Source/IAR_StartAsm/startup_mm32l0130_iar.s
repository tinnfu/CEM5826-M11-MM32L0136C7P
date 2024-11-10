; ////////////////////////////////////////////////////////////////////////////////
; /// @file     startup_mm32_iar.s
; /// @author   VV TEAM
; /// @brief    THIS FILE PROVIDES ALL THE Device Startup File of MM32 Cortex-M
; ///           Core Device for ARM KEIL toolchain.
; ////////////////////////////////////////////////////////////////////////////////
; /// @attention
; ///
; /// THE EXISTING FIRMWARE IS ONLY FOR REFERENCE, WHICH IS DESIGNED TO PROVIDE
; /// CUSTOMERS WITH CODING INFORMATION ABOUT THEIR PRODUCTS SO THEY CAN SAVE
; /// TIME. THEREFORE, MINDMOTION SHALL NOT BE LIABLE FOR ANY DIRECT, INDIRECT OR
; /// CONSEQUENTIAL DAMAGES ABOUT ANY CLAIMS ARISING OUT OF THE CONTENT OF SUCH
; /// HARDWARE AND/OR THE USE OF THE CODING INFORMATION CONTAINED HEREIN IN
; /// CONNECTION WITH PRODUCTS MADE BY CUSTOMERS.
; ///
; /// <H2><CENTER>&COPY; COPYRIGHT MINDMOTION </CENTER></H2>
; //////////////////////////////////////////////////////////////////////////////
;
; Amount of memory (in bytes) allocated for Stack
; Tailor this value to your application needs
; <h> Stack Configuration
;   <o> Stack Size (in Bytes) <0x0-0xFFFFFFFF:8>
; </h>

                MODULE  ?cstartup

                                                                                ;; Forward declaration of sections.
                SECTION CSTACK:DATA:NOROOT(3)

                SECTION .intvec:CODE:NOROOT(2)

                EXTERN  __iar_program_start
                EXTERN  SystemInit
                PUBLIC  __vector_table
                PUBLIC  __vector_table_0x1c
                PUBLIC  __Vectors
                PUBLIC  __Vectors_End
                PUBLIC  __Vectors_Size

                DATA
__vector_table
                DCD     sfe(CSTACK)                                             ;       Top of Stack                    |   0 0x0000
                DCD     Reset_Handler                                           ;       Reset Handler                   |   1 0x0004
                DCD     NMI_Handler                                             ; -14   NMI Handler                     |   2 0x0008
                DCD     HardFault_Handler                                       ; -13   Hard Fault Handler              |   3 0x000C
                DCD     0                                                       ; -12   Reserved                        |   4 0x0010
                DCD     0                                                       ; -11   Reserved                        |   5 0x0014
                DCD     0                                                       ; -10   Reserved                        |   6 0x0018
__vector_table_0x1c
                DCD     0                                                       ;  -9   Reserved                        |   7 0x001C
                DCD     0                                                       ;  -8   Reserved                        |   8 0x0020
                DCD     0                                                       ;  -7   Reserved                        |   9 0x0024
                DCD     0                                                       ;  -6   Reserved                        |  10 0x0028
                DCD     SVC_Handler                                             ;  -5   SVCall Handler                  |  11 0x002C
                DCD     0                                                       ;  -4   Reserved                        |  12 0x0030
                DCD     0                                                       ;  -3   Reserved                        |  13 0x0034
                DCD     PendSV_Handler                                          ;  -2   PendSV Handler                  |  14 0x0038
                DCD     SysTick_Handler                                         ;  -1   SysTick Handler                 |  15 0x003C

                ; External Interrupts
                DCD     WWDG_IWDG_IRQHandler                                    ;   0   Window Watchdog EXTI 21         |  16 0x0040
                DCD     PVD_IRQHandler                                          ;   1   PVD through EXTI 16             |  17 0x0044
                DCD     RTC_BKP_IRQHandler                                      ;   2   RTC through EXTI 17 & Tamper    |  18 0x0048
                DCD     FLASH_IRQHandler                                        ;   3   FLASH                           |  19 0x004C
                DCD     RCC_IRQHandler                                          ;   4   RCC                             |  20 0x0050
                DCD     EXTI0_1_IRQHandler                                      ;   5   EXTI Line 0 and 1               |  21 0x0054
                DCD     EXTI2_3_IRQHandler                                      ;   6   EXTI Line 2 and 3               |  22 0x0058
                DCD     EXTI4_15_IRQHandler                                     ;   7   EXTI Line 4 to 15               |  23 0x005C
                DCD     0                                                       ;   8   Reserved                        |  24 0x0060
                DCD     DMA_Channel1_IRQHandler                                 ;   9   DMA1 Channel 1                  |  25 0x0064
                DCD     DMA_Channel2_3_IRQHandler                               ;  10   DMA1 Channel 2 and Channel 3    |  26 0x0068
                DCD     DMA_Channel4_5_IRQHandler                               ;  11   DMA1 Channel 4 and Channel 5    |  27 0x006C
                DCD     ADC_COMP_IRQHandler                                     ;  12   ADC1 & COMP EXTI 19             |  28 0x0070
                DCD     0                                                       ;  13   Reserved                        |  29 0x0074
                DCD     0                                                       ;  14   Reserved                        |  30 0x0078
                DCD     0                                                       ;  15   Reserved                        |  31 0x007C
                DCD     TIM3_IRQHandler                                         ;  16   TIM3                            |  32 0x0080
                DCD     LPUART_IRQHandler                                       ;  17   LPUART1 EXTI 22                 |  33 0x0084
                DCD     LPTIMER_IRQHandler                                      ;  18   LPTIMER1 EXTI 23                |  34 0x0088
                DCD     TIM4_IRQHandler                                         ;  19   TIM4                            |  35 0x008C
                DCD     0                                                       ;  20   Reserved                        |  36 0x0090
                DCD     TIM16_IRQHandler                                        ;  21   TIM16                           |  37 0x0094
                DCD     TIM17_IRQHandler                                        ;  22   TIM17                           |  38 0x0098
                DCD     I2C1_IRQHandler                                         ;  23   I2C1 EXTI 24                    |  39 0x009C
                DCD     0                                                       ;  24   Reserved                        |  40 0x00A0
                DCD     SPI1_IRQHandler                                         ;  25   SPI1                            |  41 0x00A4
                DCD     SPI2_IRQHandler                                         ;  26   SPI2                            |  42 0x00A8
                DCD     UART1_IRQHandler                                        ;  27   UART1 EXTI 25                   |  43 0x00AC
                DCD     UART2_IRQHandler                                        ;  28   UART2 EXTI 26                   |  44 0x00B0
                DCD     0                                                       ;  29   Reserved                        |  45 0x00B4
                DCD     SLCD_IRQHandler                                         ;  30   Segment LCD                     |  46 0x00B8
                DCD     0                                                       ;  31   Reserved                        |  47 0x00BC

                                                                                ; Total Cortex-M0 32 Interrupts are setting
__Vectors_End

__Vectors       EQU     __vector_table
__Vectors_Size  EQU     __Vectors_End - __Vectors



                THUMB

; Reset Handler

                PUBWEAK Reset_Handler
                SECTION .text:CODE:REORDER:NOROOT(2)
Reset_Handler

                LDR     R0, =SystemInit
                BLX     R0
                LDR     R0, =__iar_program_start
                BX      R0

                PUBWEAK NMI_Handler
                PUBWEAK HardFault_Handler
                PUBWEAK SVC_Handler
                PUBWEAK PendSV_Handler
                PUBWEAK SysTick_Handler
                PUBWEAK WWDG_IWDG_IRQHandler
                PUBWEAK PVD_IRQHandler
                PUBWEAK RTC_BKP_IRQHandler
                PUBWEAK FLASH_IRQHandler
                PUBWEAK RCC_IRQHandler
                PUBWEAK EXTI0_1_IRQHandler
                PUBWEAK EXTI2_3_IRQHandler
                PUBWEAK EXTI4_15_IRQHandler
                PUBWEAK DMA_Channel1_IRQHandler
                PUBWEAK DMA_Channel2_3_IRQHandler
                PUBWEAK DMA_Channel4_5_IRQHandler
                PUBWEAK ADC_COMP_IRQHandler
                PUBWEAK TIM3_IRQHandler
                PUBWEAK LPUART_IRQHandler
                PUBWEAK LPTIMER_IRQHandler
                PUBWEAK TIM4_IRQHandler
                PUBWEAK TIM16_IRQHandler
                PUBWEAK TIM17_IRQHandler
                PUBWEAK I2C1_IRQHandler
                PUBWEAK SPI1_IRQHandler
                PUBWEAK SPI2_IRQHandler
                PUBWEAK UART1_IRQHandler
                PUBWEAK UART2_IRQHandler
                PUBWEAK SLCD_IRQHandler

                SECTION .text:CODE:REORDER:NOROOT(1)




NMI_Handler
HardFault_Handler
SVC_Handler
PendSV_Handler
SysTick_Handler
WWDG_IWDG_IRQHandler
PVD_IRQHandler
RTC_BKP_IRQHandler
FLASH_IRQHandler
RCC_IRQHandler
EXTI0_1_IRQHandler
EXTI2_3_IRQHandler
EXTI4_15_IRQHandler
DMA_Channel1_IRQHandler
DMA_Channel2_3_IRQHandler
DMA_Channel4_5_IRQHandler
ADC_COMP_IRQHandler
TIM3_IRQHandler
LPUART_IRQHandler
LPTIMER_IRQHandler
TIM4_IRQHandler
TIM16_IRQHandler
TIM17_IRQHandler
I2C1_IRQHandler
SPI1_IRQHandler
SPI2_IRQHandler
UART1_IRQHandler
UART2_IRQHandler
SLCD_IRQHandler


Default_Handler
                B       .
                END

