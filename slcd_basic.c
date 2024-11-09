/***********************************************************************************************************************
    @file    slcd_basic.c
    @author  FAE Team
    @date    28-Feb-2023
    @brief   THIS FILE PROVIDES ALL THE SYSTEM FUNCTIONS.
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

/* Define to prevent recursive inclusion */
#define _SLCD_BASIC_C_

/* Files include */
#include <stdio.h>
#include <string.h>
#include "platform.h"
#include "slcd_basic.h"

/**
  * @addtogroup MM32L0130_LibSamples
  * @{
  */

/**
  * @addtogroup SLCD
  * @{
  */

/**
  * @addtogroup SLCD_Basic
  * @{
  */

/* Private typedef ****************************************************************************************************/
typedef struct
{
    char    ch;
    uint8_t Data;
} SLCD_Code_TypeDef;

typedef struct
{
    GPIO_TypeDef *GPIOn;
    uint16_t      PINn;
    uint32_t      Line;
} SLCD_Line_TypeDef;

typedef struct
{
    GPIO_TypeDef   *GPIOn;
    uint16_t        PINn;
    uint32_t        Line;
    uint8_t         LineGroup;
    uint8_t         Mode;
} SLCD_IO_TypeDef;

/* Private define *****************************************************************************************************/

/* Private macro ******************************************************************************************************/
#define SLCD_COM_NUMBER     (4)
#define SLCD_SEG_NUMBER     (25)
#define SLCD_PIN_NUMBER     (SLCD_SEG_NUMBER + SLCD_COM_NUMBER)

/* Private variables **************************************************************************************************/
const SLCD_Code_TypeDef SLCD_CodeTable[38] =
{
    { ' ', 0x00 },
    { '0', 0x3F },
    { '1', 0x06 },
    { '2', 0x5B },
    { '3', 0x4F },
    { '4', 0x66 },
    { '5', 0x6D },
    { '6', 0x7D },
    { '7', 0x07 },
    { '8', 0x7F },
    { '9', 0x6F },
    { 'A', 0x77 },
    { 'b', 0x7C },
    { 'c', 0x58 },
    { 'C', 0x39 },
    { 'd', 0x5E },
    { 'E', 0x79 },
    { 'F', 0x71 },
    { 'g', 0x6F },
    { 'H', 0x76 },
    { 'h', 0x74 },
    { 'i', 0x04 },
    { 'I', 0x30 },
    { 'J', 0x1E },
    { 'l', 0x30 },
    { 'L', 0x38 },
    { 'n', 0x54 },
    { 'o', 0x5C },
    { 'O', 0x3F },
    { 'P', 0x73 },
    { 'q', 0x67 },
    { 'r', 0x50 },
    { 'S', 0x6D },
    { 't', 0x78 },
    { 'u', 0x1C },
    { 'U', 0x3E },
    { 'y', 0x6E },
    { '-', 0x40 },
};

const SLCD_Line_TypeDef SLCD_LineTable[] =
{
    { GPIOC, GPIO_Pin_13, SLCD_L0  },
    { GPIOD, GPIO_Pin_7,  SLCD_L1  },
    { GPIOB, GPIO_Pin_9,  SLCD_L2  },
    { GPIOB, GPIO_Pin_8,  SLCD_L3  },
    { GPIOC, GPIO_Pin_12, SLCD_L4  },
    { GPIOC, GPIO_Pin_11, SLCD_L5  },
    { GPIOC, GPIO_Pin_10, SLCD_L6  },
    { GPIOA, GPIO_Pin_15, SLCD_L7  },
    { GPIOD, GPIO_Pin_3,  SLCD_L8  },
    { GPIOD, GPIO_Pin_2,  SLCD_L9  },
    { GPIOA, GPIO_Pin_12, SLCD_L10 },
    { GPIOA, GPIO_Pin_11, SLCD_L11 },
    { GPIOA, GPIO_Pin_10, SLCD_L12 },
    { GPIOA, GPIO_Pin_9,  SLCD_L13 },
    { GPIOA, GPIO_Pin_8,  SLCD_L14 },
    { GPIOC, GPIO_Pin_9,  SLCD_L15 },
    { GPIOC, GPIO_Pin_8,  SLCD_L16 },
    { GPIOC, GPIO_Pin_7,  SLCD_L17 },
    { GPIOC, GPIO_Pin_6,  SLCD_L18 },
    { GPIOB, GPIO_Pin_15, SLCD_L19 },
    { GPIOB, GPIO_Pin_14, SLCD_L20 },
    { GPIOB, GPIO_Pin_13, SLCD_L21 },
    { GPIOB, GPIO_Pin_12, SLCD_L22 },
    { GPIOB, GPIO_Pin_11, SLCD_L23 },
    { GPIOB, GPIO_Pin_10, SLCD_L24 },
    { GPIOB, GPIO_Pin_2,  SLCD_L25 },
    { GPIOB, GPIO_Pin_1,  SLCD_L26 },
    { GPIOB, GPIO_Pin_0,  SLCD_L27 },
    { GPIOC, GPIO_Pin_5,  SLCD_L28 },
    { GPIOC, GPIO_Pin_4,  SLCD_L29 },
    { GPIOA, GPIO_Pin_7,  SLCD_L30 },
    { GPIOA, GPIO_Pin_6,  SLCD_L31 },
    { GPIOA, GPIO_Pin_5,  SLCD_L32 },
    { GPIOA, GPIO_Pin_4,  SLCD_L33 },
    { GPIOD, GPIO_Pin_5,  SLCD_L34 },
    { GPIOD, GPIO_Pin_4,  SLCD_L35 },
    { GPIOA, GPIO_Pin_3,  SLCD_L36 },
    { GPIOA, GPIO_Pin_2,  SLCD_L37 },
    { GPIOA, GPIO_Pin_1,  SLCD_L38 },
    { GPIOA, GPIO_Pin_0,  SLCD_L39 },
    { GPIOC, GPIO_Pin_3,  SLCD_L40 },
    { GPIOC, GPIO_Pin_2,  SLCD_L41 },
    { GPIOC, GPIO_Pin_1,  SLCD_L42 },
    { GPIOC, GPIO_Pin_0,  SLCD_L43 },
    { GPIOH, GPIO_Pin_0,  SLCD_L44 },
    { GPIOH, GPIO_Pin_0,  SLCD_L45 },
    { GPIOH, GPIO_Pin_0,  SLCD_L46 },
    { GPIOH, GPIO_Pin_0,  SLCD_L47 },
    { GPIOH, GPIO_Pin_0,  SLCD_L48 },
    { GPIOH, GPIO_Pin_0,  SLCD_L49 },
    { GPIOH, GPIO_Pin_0,  SLCD_L50 },
    { GPIOH, GPIO_Pin_0,  SLCD_L51 },
    { GPIOH, GPIO_Pin_0,  SLCD_L52 },
    { GPIOH, GPIO_Pin_0,  SLCD_L53 },
    { GPIOH, GPIO_Pin_0,  SLCD_L54 },
    { GPIOH, GPIO_Pin_0,  SLCD_L55 },
    { GPIOH, GPIO_Pin_0,  SLCD_L56 },
    { GPIOH, GPIO_Pin_0,  SLCD_L57 },
    { GPIOD, GPIO_Pin_6,  SLCD_L58 },
    { GPIOB, GPIO_Pin_3,  SLCD_L59 },
    { GPIOB, GPIO_Pin_4,  SLCD_L60 },
    { GPIOB, GPIO_Pin_5,  SLCD_L61 },
    { GPIOB, GPIO_Pin_6,  SLCD_L62 },
    { GPIOB, GPIO_Pin_7,  SLCD_L63 },
};

const char SLCD_NAME_Table[SLCD_COM_NUMBER][SLCD_SEG_NUMBER][4] =
{
    { "1D ", "DP1", "2D ", "DP2", "3D ", "DP3", "4D ", "C1 ", "C2 ", "W5 ", "L1 ", "5F ", "5A ", "6F ", "6A ", "7F ", "7A ", "S4 ", "S5 ", "8F ",
      "8A ", "9F ", "9A ", "10F", "10A" },
    { "1E ", "1C ", "2E ", "2C ", "3E ", "3C ", "4E ", "4C ", "C3 ", "W4 ", "L2 ", "5G ", "5B ", "6G ", "6B ", "7G ", "7B ", "S3 ", "S6 ", "8G ",
      "8B ", "9G ", "9B ", "10G", "10B" },
    { "1G ", "1B ", "2G ", "2B ", "3G ", "3B ", "4G ", "4B ", "T1 ", "W3 ", "L3 ", "5E ", "5C ", "6E ", "6C ", "7E ", "7C ", "S2 ", "S7 ", "8E ",
      "8C ", "9E ", "9C ", "10E", "10C" },
    { "1F ", "1A ", "2F ", "2A ", "3F ", "3A ", "4F ", "4A ", "W1 ", "W2 ", "L4 ", "5D ", "DP5", "6D ", "DP6", "7D ", "DP7", "S1 ", "S8 ", "8D ",
      "DP8", "9D ", "DP9", "10D", "S9 " },
};

SLCD_IO_TypeDef SLCD_SCH[SLCD_PIN_NUMBER] =
{
    { GPIOB, GPIO_Pin_8,  0, 0, SLCD_IOConfigSEG }, /* PB8  : SLCD_D0   */
    { GPIOA, GPIO_Pin_15, 0, 0, SLCD_IOConfigSEG }, /* PA15 : SLCD_D1   */
    { GPIOC, GPIO_Pin_10, 0, 0, SLCD_IOConfigSEG }, /* PC10 : SLCD_D2   */
    { GPIOC, GPIO_Pin_11, 0, 0, SLCD_IOConfigSEG }, /* PC11 : SLCD_D3   */
    { GPIOC, GPIO_Pin_12, 0, 0, SLCD_IOConfigSEG }, /* PC12 : SLCD_D4   */
    { GPIOD, GPIO_Pin_6,  0, 0, SLCD_IOConfigSEG }, /* PD6  : SLCD_D5   */
    { GPIOB, GPIO_Pin_1,  0, 0, SLCD_IOConfigSEG }, /* PB1  : SLCD_D6   */
    { GPIOB, GPIO_Pin_0,  0, 0, SLCD_IOConfigSEG }, /* PB0  : SLCD_D7   */
    { GPIOA, GPIO_Pin_7,  0, 0, SLCD_IOConfigSEG }, /* PA7  : SLCD_D8   */
    { GPIOA, GPIO_Pin_6,  0, 0, SLCD_IOConfigSEG }, /* PA6  : SLCD_D9   */
    { GPIOD, GPIO_Pin_5,  0, 0, SLCD_IOConfigSEG }, /* PD5  : SLCD_D10  */

    { GPIOD, GPIO_Pin_3,  0, 0, SLCD_IOConfigSEG }, /* PD3  : SLCD_D11  */
    { GPIOD, GPIO_Pin_2,  0, 0, SLCD_IOConfigSEG }, /* PD2  : SLCD_D12  */
    { GPIOA, GPIO_Pin_12, 0, 0, SLCD_IOConfigSEG }, /* PA12 : SLCD_D13  */
    { GPIOA, GPIO_Pin_11, 0, 0, SLCD_IOConfigSEG }, /* PA11 : SLCD_D14  */
    { GPIOC, GPIO_Pin_9,  0, 0, SLCD_IOConfigSEG }, /* PC9  : SLCD_D15  */
    { GPIOC, GPIO_Pin_8,  0, 0, SLCD_IOConfigSEG }, /* PC8  : SLCD_D16  */
    { GPIOC, GPIO_Pin_7,  0, 0, SLCD_IOConfigSEG }, /* PC7  : SLCD_D17  */
    { GPIOC, GPIO_Pin_6,  0, 0, SLCD_IOConfigSEG }, /* PC6  : SLCD_D18  */
    { GPIOB, GPIO_Pin_14, 0, 0, SLCD_IOConfigSEG }, /* PB14 : SLCD_D19  */
    { GPIOB, GPIO_Pin_15, 0, 0, SLCD_IOConfigSEG }, /* PB15 : SLCD_D20  */
    { GPIOB, GPIO_Pin_12, 0, 0, SLCD_IOConfigSEG }, /* PB12 : SLCD_D21  */
    { GPIOB, GPIO_Pin_13, 0, 0, SLCD_IOConfigSEG }, /* PB13 : SLCD_D22  */
    { GPIOC, GPIO_Pin_5,  0, 0, SLCD_IOConfigSEG }, /* PC5  : SLCD_D23  */
    { GPIOC, GPIO_Pin_4,  0, 0, SLCD_IOConfigSEG }, /* PC4  : SLCD_D24  */

    { GPIOD, GPIO_Pin_4,  0, 0, SLCD_IOConfigCOM }, /* PD4  : SLCD_COM0 */
    { GPIOC, GPIO_Pin_3,  0, 0, SLCD_IOConfigCOM }, /* PC3  : SLCD_COM1 */
    { GPIOC, GPIO_Pin_13, 0, 0, SLCD_IOConfigCOM }, /* PC13 : SLCD_COM2 */
    { GPIOD, GPIO_Pin_7,  0, 0, SLCD_IOConfigCOM }, /* PD7  : SLCD_COM3 */
};

/* Private functions **************************************************************************************************/

/***********************************************************************************************************************
  * @brief
  * @note   none
  * @param  none
  * @retval none
  *********************************************************************************************************************/
void SLCD_Clear(uint8_t Mode)
{
    uint8_t i = 0;

    if (0 != Mode)
    {
        for (i = 0; i < 16; i++)
        {
            SLCD->DR[i] = 0xFFFFFFFF;
        }
    }
    else
    {
        for (i = 0; i < 16; i++)
        {
            SLCD->DR[i] = 0x00000000;
        }
    }
}

/***********************************************************************************************************************
  * @brief
  * @note   none
  * @param  none
  * @retval none
  *********************************************************************************************************************/
void SLCD_WriteBit(uint8_t COMn, uint32_t SEGn, uint32_t Group, uint8_t State)
{
    uint8_t Index = COMn * 2 + Group;

    if (State)
    {
        SLCD->DR[Index] |= SEGn;
    }
    else
    {
        SLCD->DR[Index] &= ~SEGn;
    }
}

/***********************************************************************************************************************
  * @brief
  * @note   none
  * @param  none
  * @retval none
  *********************************************************************************************************************/
uint8_t SLCD_SearchCode(char ch)
{
    uint8_t i = 0;

    for (i = 0; i < 38; i++)
    {
        if (ch == SLCD_CodeTable[i].ch)
        {
            return (SLCD_CodeTable[i].Data);
        }
    }

    return (0xFF);
}

/***********************************************************************************************************************
  * @brief
  * @note   none
  * @param  none
  * @retval none
  *********************************************************************************************************************/
void SLCD_SearchName(char *str, uint8_t *COMn, uint8_t *SEGn)
{
    uint8_t i = 0, j = 0;

    for (i = 0; i < SLCD_COM_NUMBER; i++)
    {
        for (j = 0; j < SLCD_SEG_NUMBER; j++)
        {
            if (strcmp(str, SLCD_NAME_Table[i][j]) == 0)
            {
                *COMn = i;
                *SEGn = j;
                return;
            }
        }
    }

    *COMn = 0xFF;
    *SEGn = 0xFF;
}

/***********************************************************************************************************************
  * @brief
  * @note   none
  * @param  none
  * @retval none
  *********************************************************************************************************************/
void SLCD_DisplayNumber1(uint8_t Index, char ch, uint8_t Point)
{
    char TAB[4][8][4] =
    {
        { "1A ", "1B ", "1C ", "1D ", "1E ", "1F ", "1G ", "DP1" },
        { "2A ", "2B ", "2C ", "2D ", "2E ", "2F ", "2G ", "DP2" },
        { "3A ", "3B ", "3C ", "3D ", "3E ", "3F ", "3G ", "DP3" },
        { "4A ", "4B ", "4C ", "4D ", "4E ", "4F ", "4G ", "   " },
    };
    uint8_t COMn = 0xFF, SEGn = 0xFF;
    uint8_t Code = SLCD_SearchCode(ch);
    uint8_t i    = 0;

    if (Code != 0xFF)
    {
        for (i = 0; i < 7; i++)
        {
            SLCD_SearchName(TAB[Index][i], &COMn, &SEGn);

            if ((COMn != 0xFF) && (SEGn != 0xFF))
            {
                SLCD_WriteBit(COMn, SLCD_SCH[SEGn].Line, SLCD_SCH[SEGn].LineGroup, (Code >> i) & 0x01);
            }
        }

        SLCD_SearchName(TAB[Index][7], &COMn, &SEGn);

        if ((COMn != 0xFF) && (SEGn != 0xFF))
        {
            SLCD_WriteBit(COMn, SLCD_SCH[SEGn].Line, SLCD_SCH[SEGn].LineGroup, Point);
        }
    }
}

/***********************************************************************************************************************
  * @brief
  * @note   none
  * @param  none
  * @retval none
  *********************************************************************************************************************/
void SLCD_DisplayNumber2(uint8_t Index, char ch, uint8_t Point)
{
    char TAB[6][8][4] =
    {
        { "5A ", "5B ", "5C ", "5D ", "5E ", "5F ", "5G ", "DP5" },
        { "6A ", "6B ", "6C ", "6D ", "6E ", "6F ", "6G ", "DP6" },
        { "7A ", "7B ", "7C ", "7D ", "7E ", "7F ", "7G ", "DP7" },
        { "8A ", "8B ", "8C ", "8D ", "8E ", "8F ", "8G ", "DP8" },
        { "9A ", "9B ", "9C ", "9D ", "9E ", "9F ", "9G ", "DP9" },
        { "10A", "10B", "10C", "10D", "10E", "10F", "10G", "   " },
    };
    uint8_t COMn = 0xFF, SEGn = 0xFF;
    uint8_t Code = SLCD_SearchCode(ch);
    uint8_t i    = 0;

    if (Code != 0xFF)
    {
        for (i = 0; i < 7; i++)
        {
            SLCD_SearchName(TAB[Index][i], &COMn, &SEGn);

            if ((COMn != 0xFF) && (SEGn != 0xFF))
            {
                SLCD_WriteBit(COMn, SLCD_SCH[SEGn].Line, SLCD_SCH[SEGn].LineGroup, (Code >> i) & 0x01);
            }
        }

        SLCD_SearchName(TAB[Index][7], &COMn, &SEGn);

        if ((COMn != 0xFF) && (SEGn != 0xFF))
        {
            SLCD_WriteBit(COMn, SLCD_SCH[SEGn].Line, SLCD_SCH[SEGn].LineGroup, Point);
        }
    }
}

/***********************************************************************************************************************
  * @brief
  * @note   none
  * @param  none
  * @retval none
  *********************************************************************************************************************/
void SLCD_DisplayTool(void)
{
    static uint8_t State = 0;
    char TAB[4] = "T1 ";
    uint8_t COMn = 0xFF, SEGn = 0xFF;

    SLCD_SearchName(TAB, &COMn, &SEGn);

    if ((COMn != 0xFF) && (SEGn != 0xFF))
    {
        SLCD_WriteBit(COMn, SLCD_SCH[SEGn].Line, SLCD_SCH[SEGn].LineGroup, State);
    }

    State = (State + 1) % 2;
}

/***********************************************************************************************************************
  * @brief
  * @note   none
  * @param  none
  * @retval none
  *********************************************************************************************************************/
void SLCD_ConfigureSEGoCOM(void)
{
    uint8_t i = 0, j = 0;
    uint8_t SLCD_IOConfigTable[MAX_SLCD_PIN_NUMBER];

    memset(SLCD_IOConfigTable, SLCD_IOConfigNone, MAX_SLCD_PIN_NUMBER);

    for (i = 0; i < MAX_SLCD_PIN_NUMBER; i++)
    {
        for (j = 0; j < SLCD_PIN_NUMBER; j++)
        {
            if ((SLCD_LineTable[i].GPIOn == SLCD_SCH[j].GPIOn) && (SLCD_LineTable[i].PINn == SLCD_SCH[j].PINn))
            {
                SLCD_IOConfigTable[i] = SLCD_SCH[j].Mode;

                SLCD_SCH[j].Line = SLCD_LineTable[i].Line;

                if (i > 31)
                {
                    SLCD_SCH[j].LineGroup = 1;
                }
                else
                {
                    SLCD_SCH[j].LineGroup = 0;
                }
            }
        }
    }

    SLCD_IO_Config(SLCD_IOConfigTable);
}

/***********************************************************************************************************************
  * @brief
  * @note   none
  * @param  none
  * @retval none
  *********************************************************************************************************************/
void SLCD_ConfigureCOMnIDX(void)
{
    uint8_t i = 0, j = 0, k = 0;
    uint8_t SCLD_COM_IndexTable[COM_INDEX_MAX];

    for (i = 0; i < COM_INDEX_MAX; i++)
    {
        SCLD_COM_IndexTable[i] = 50 + i;
    }

    i = 0;

    for (j = 0; j < SLCD_PIN_NUMBER; j++)
    {
        if (SLCD_IOConfigCOM == SLCD_SCH[j].Mode)
        {
            for (k = 0; k < MAX_SLCD_PIN_NUMBER; k++)
            {
                if ((SLCD_LineTable[k].GPIOn == SLCD_SCH[j].GPIOn) && (SLCD_LineTable[k].PINn == SLCD_SCH[j].PINn))
                {
                    SCLD_COM_IndexTable[i++] = k;
                }
            }
        }
    }

    SLCD_COM_IndexInit(SCLD_COM_IndexTable);
}

/***********************************************************************************************************************
  * @brief
  * @note   none
  * @param  none
  * @retval none
  *********************************************************************************************************************/
void SLCD_ConfigureBlinkEN(void)
{
    uint8_t SCLD_BLINK_IndexTable[COM_INDEX_MAX * BLINK_INDEX_STEP] =
    {
        1, 0, 0,                       /* BLINK_Index0 is Enable, BLINK_Index0 point to COM0 and SEG0 */
        1, 1, 1,                       /* BLINK_Index1 is Enable, BLINK_Index1 point to COM1 and SEG1 */
        1, 2, 2,                       /* BLINK_Index2 is Enable, BLINK_Index2 point to COM2 and SEG2 */
        1, 3, 3,                       /* BLINK_Index3 is Enable, BLINK_Index3 point to COM3 and SEG3 */
        1, 4, 4,                       /* BLINK_Index4 is Enable, BLINK_Index4 point to COM4 and SEG4 */
        1, 5, 5,                       /* BLINK_Index5 is Enable, BLINK_Index5 point to COM5 and SEG5 */
        1, 6, 6,                       /* BLINK_Index6 is Enable, BLINK_Index6 point to COM6 and SEG6 */
        1, 7, 7,                       /* BLINK_Index7 is Enable, BLINK_Index7 point to COM7 and SEG7 */
    };

    SLCD_BlinkConfig(SLCD_BlinkMode_Off, SLCD_BlinkFrequency_Div512);

    SLCD_BLINK_IndexInit(SCLD_BLINK_IndexTable);
}

/***********************************************************************************************************************
  * @brief
  * @note   none
  * @param  none
  * @retval none
  *********************************************************************************************************************/
void SLCD_Configure(void)
{
    SLCD_InitTypeDef SLCD_InitStructure;
    uint32_t SLCD_ClockFreq   = 0;
    uint32_t SLCD_Prescaler   = SLCD_Prescaler_16;
    uint32_t SLCD_Divider     = SLCD_Divider_16;
    uint8_t  SLCD_ClockSource = 0;

    RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA, ENABLE);
    RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOB, ENABLE);
    RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOC, ENABLE);
    RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOD, ENABLE);

    RCC_APB1PeriphClockCmd(RCC_APB1Periph_PWR | RCC_APB1Periph_BKP, ENABLE);
    PWR_BackupAccessCmd(ENABLE);

    switch (SLCD_ClockSource)
    {
        case 0:                        /* LSI */
            RCC_LSICmd(ENABLE);

            RCC_LSICLKConfig(RCC_LSICLKSource_40KHz);

            while (RESET == RCC_GetFlagStatus(RCC_FLAG_LSIRDY))
            {
                __NOP();
            }

            RCC_APB1PeriphClockCmd(RCC_APB1Periph_LCD, ENABLE);

            SLCD_DeInit();

            RCC_SLCDCLKConfig(RCC_SLCDCLKSource_LSI);
            break;

        case 1:                        /* LSE */
            RCC_LSEConfig(RCC_LSE_ON);

            while (RESET == RCC_GetFlagStatus(RCC_FLAG_LSERDY))
            {
                __NOP();
            }

            RCC_APB1PeriphClockCmd(RCC_APB1Periph_LCD, ENABLE);

            SLCD_DeInit();

            RCC_SLCDCLKConfig(RCC_SLCDCLKSource_LSE);
            break;

        case 2:                        /* HSI(1MHz)/DIV1 -> 1MHz */
            RCC_HSIConfig(RCC_HSI_1M);

            RCC_APB1PeriphClockCmd(RCC_APB1Periph_LCD, ENABLE);

            SLCD_DeInit();

            RCC_SLCDCLKConfig(RCC_SLCDCLKSource_HSI_Div1);
            break;

        case 3:                        /* HSI(8MHz)/DIV8 -> 1MHz */
            RCC_HSIConfig(RCC_HSI_8M);

            RCC_APB1PeriphClockCmd(RCC_APB1Periph_LCD, ENABLE);

            SLCD_DeInit();

            RCC_SLCDCLKConfig(RCC_SLCDCLKSource_HSI_Div8);
            break;

        default:
            break;
    }

    SLCD_ClockFreq = RCC_GetSlcdClockFreq();

    printf("\r\nSLCD_ClockFreq : %dHz\r\n", SLCD_ClockFreq);

    if (SLCD_ClockFreq == 0)
    {
        return;
    }
    else if (SLCD_ClockFreq == 32768UL)
    {
        SLCD_Prescaler = SLCD_Prescaler_2;
        SLCD_Divider   = SLCD_Divider_16;
    }
    else if (SLCD_ClockFreq == 40000UL)
    {
        SLCD_Prescaler = SLCD_Prescaler_2;
        SLCD_Divider   = SLCD_Divider_20;
    }
    else if (SLCD_ClockFreq == 1000000UL)
    {
        SLCD_Prescaler = SLCD_Prescaler_64;
        SLCD_Divider   = SLCD_Divider_16;
    }

    SLCD_StructInit(&SLCD_InitStructure);
    SLCD_InitStructure.SLCD_Prescaler     = SLCD_Prescaler;
    SLCD_InitStructure.SLCD_Divider       = SLCD_Divider;
    SLCD_InitStructure.SLCD_Duty          = SLCD_Duty_1_4;
    SLCD_InitStructure.SLCD_Bias          = SLCD_Bias_1_3;
    SLCD_InitStructure.SLCD_VoltageSource = SLCD_VoltSrcCapCharggDownVdd;
    SLCD_Init(&SLCD_InitStructure);

    SLCD_ConfigureSEGoCOM();

    SLCD_ConfigureCOMnIDX();

    SLCD_ChargePumpClockDivConfig(SLCD_ChargePumpClock_Div1024);
    SLCD_LowPowerDriveCmd(DISABLE);
    SLCD_DeadTimeConfig(SLCD_DeadTime_0);

    SLCD_Cmd(ENABLE);

    SLCD_Clear(1);
    PLATFORM_DelayMS(1000);
    SLCD_Clear(0);

    SLCD_ConfigureBlinkEN();
}

/***********************************************************************************************************************
  * @brief
  * @note   none
  * @param  none
  * @retval none
  *********************************************************************************************************************/
void SLCD_Basic_Sample(void)
{
    static uint32_t Number1  = 0;
    static uint32_t Number2  = 0;
    static uint32_t Counter  = 0;
    char   Buffer[10];
    uint8_t i = 0;

    printf("\r\nTest %s", __FUNCTION__);

    SLCD_Configure();

    while (1)
    {
        Number2 = (Number2 + 1) % 1000000;

        sprintf(Buffer, "%d", Number2);

        for (i = 0; i < strlen(Buffer); i++)
        {
            SLCD_DisplayNumber2(6 - strlen(Buffer) + i, Buffer[i], 0);
        }

        Counter++;

        if ((Counter % 3) == 0)
        {
            SLCD_DisplayTool();
        }

        if ((Counter % 10) == 0)
        {
            Number1 = (Number1 + 1) % 10000;

            sprintf(Buffer, "%d", Number1);

            for (i = 0; i < strlen(Buffer); i++)
            {
                SLCD_DisplayNumber1(4 - strlen(Buffer) + i, Buffer[i], 0);
            }
        }

        PLATFORM_LED_Toggle(LED1);
        PLATFORM_DelayMS(100);
    }
}

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

/********************************************** (C) Copyright MindMotion **********************************************/

