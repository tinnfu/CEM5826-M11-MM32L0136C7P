;/***********************************************************************************************************************
;    @file     startup_mm32l0130_keil.s
;    @author   VV TEAM
;    @brief    THIS FILE PROVIDES ALL THE Device Startup File of MM32 Cortex-M
;              Core Device for ARM KEIL toolchain.
;  **********************************************************************************************************************
;    @attention
;
;    <h2><center>&copy; Copyright(c) <2023> <MindMotion></center></h2>
;
;      Redistribution and use in source and binary forms, with or without modification, are permitted provided that the
;    following conditions are met:
;    1. Redistributions of source code must retain the above copyright notice,
;       this list of conditions and the following disclaimer.
;    2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and
;       the following disclaimer in the documentation and/or other materials provided with the distribution.
;    3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse or
;       promote products derived from this software without specific prior written permission.
;
;      THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
;    INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
;    DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
;    SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
;    SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
;    WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
;    OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
;  *********************************************************************************************************************/


Stack_Size      EQU     0x00000400

                AREA    STACK, NOINIT, READWRITE, ALIGN=3
Stack_Mem       SPACE   Stack_Size
__initial_sp


; <h> Heap Configuration
;   <o>  Heap Size (in Bytes) <0x0-0xFFFFFFFF:8>
; </h>

Heap_Size       EQU     0x00000200

                AREA    HEAP, NOINIT, READWRITE, ALIGN=3
__heap_base
Heap_Mem        SPACE   Heap_Size
__heap_limit

                PRESERVE8
                THUMB


; Vector Table Mapped to Address 0 at Reset
                AREA    RESET, DATA, READONLY
                EXPORT  __Vectors
                EXPORT  __Vectors_End
                EXPORT  __Vectors_Size

__Vectors       DCD     __initial_sp                                            ;       Top of Stack                    |   0 0x0000
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
__Vectors_Size  EQU     __Vectors_End - __Vectors

                AREA    |.text|, CODE, READONLY

; Reset handler
Reset_Handler   PROC
                EXPORT  Reset_Handler                  [WEAK]
                IMPORT  __main
                IMPORT  SystemInit


                LDR     R0, =__initial_sp                                      ; set stack pointer
                MSR     MSP, R0

ApplicationStart
                LDR     R0, =SystemInit
                BLX     R0
                LDR     R0, =__main
                BX      R0
                ENDP

; Dummy Exception Handlers (infinite loops which can be modified)

NMI_Handler     PROC
                EXPORT  NMI_Handler                    [WEAK]
                B       .
                ENDP
HardFault_Handler\
                PROC
                EXPORT  HardFault_Handler              [WEAK]
                B       .
                ENDP
SVC_Handler     PROC
                EXPORT  SVC_Handler                    [WEAK]
                B       .
                ENDP
PendSV_Handler  PROC
                EXPORT  PendSV_Handler                 [WEAK]
                B       .
                ENDP
SysTick_Handler PROC
                EXPORT  SysTick_Handler                [WEAK]
                B       .
                ENDP

Default_Handler PROC

                EXPORT  WWDG_IWDG_IRQHandler           [WEAK]
                EXPORT  PVD_IRQHandler                 [WEAK]
                EXPORT  RTC_BKP_IRQHandler             [WEAK]
                EXPORT  FLASH_IRQHandler               [WEAK]
                EXPORT  RCC_IRQHandler                 [WEAK]
                EXPORT  EXTI0_1_IRQHandler             [WEAK]
                EXPORT  EXTI2_3_IRQHandler             [WEAK]
                EXPORT  EXTI4_15_IRQHandler            [WEAK]
                EXPORT  DMA_Channel1_IRQHandler        [WEAK]
                EXPORT  DMA_Channel2_3_IRQHandler      [WEAK]
                EXPORT  DMA_Channel4_5_IRQHandler      [WEAK]
                EXPORT  ADC_COMP_IRQHandler            [WEAK]
                EXPORT  TIM3_IRQHandler                [WEAK]
                EXPORT  LPUART_IRQHandler              [WEAK]
                EXPORT  LPTIMER_IRQHandler             [WEAK]
                EXPORT  TIM4_IRQHandler                [WEAK]
                EXPORT  TIM16_IRQHandler               [WEAK]
                EXPORT  TIM17_IRQHandler               [WEAK]
                EXPORT  I2C1_IRQHandler                [WEAK]
                EXPORT  SPI1_IRQHandler                [WEAK]
                EXPORT  SPI2_IRQHandler                [WEAK]
                EXPORT  UART1_IRQHandler               [WEAK]
                EXPORT  UART2_IRQHandler               [WEAK]
                EXPORT  SLCD_IRQHandler                [WEAK]

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

                B       .

                ENDP

                ALIGN

;*******************************************************************************
; User Stack and Heap initialization
;*******************************************************************************
                IF      :DEF:__MICROLIB

                EXPORT  __initial_sp
                EXPORT  __heap_base
                EXPORT  __heap_limit

                ELSE

                IMPORT  __use_two_region_memory
                EXPORT  __user_initial_stackheap

__user_initial_stackheap

                LDR     R0, = Heap_Mem
                LDR     R1, = (Stack_Mem + Stack_Size)
                LDR     R2, = (Heap_Mem +  Heap_Size)
                LDR     R3, = Stack_Mem
                BX      LR

                ALIGN

                ENDIF
                END

