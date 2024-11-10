/***********************************************************************************************************************
    @file     SYSTEM_MM32L0130.C
    @author   VV TEAM
    @brief    THIS FILE PROVIDES ALL THE SYSTEM FUNCTIONS.
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

/* Files includes ------------------------------------------------------------*/
#include "mm32_device.h"

/**
  * @}
  */

/*
 *  Only one of SYSCLK_HSI_XXMHz and SYSCLK_HSE_XXMHz can be defined at a time.
 *  When HSI(HSI_VALUE =  8MHz) is used as the clock source, SYSCLK_HSI_XXMHz is used.
 *  When HSE(HSE_VALUE = 12MHz) is used as the clock source, SYSCLK_HSE_XXMHz is used.
 *  Whichever one is used, its value must be greater than or equal to 40MHz.
 *  If it is less than 40MHz, HSI or HSE will be used as the system clock.
 */
#define SYSCLK_HSI_XXMHz                48000000 /* default:48MHz, can be set as 40M or others */
//#define SYSCLK_HSI_XXMHz                40000000 
//#define SYSCLK_HSI_XXMHz                8000000 

//#define SYSCLK_HSE_XXMHz                48000000 /* default:48MHz, can be set as 40M or others */
//#define SYSCLK_HSE_XXMHz                40000000 
//#define SYSCLK_HSE_XXMHz                8000000 


#if defined (SYSCLK_HSI_XXMHz) && (SYSCLK_HSI_XXMHz >= 40000000U)
    uint32_t SystemCoreClock = SYSCLK_HSI_XXMHz;
#elif defined (SYSCLK_HSI_XXMHz) && (SYSCLK_HSI_XXMHz < 40000000U)
    uint32_t SystemCoreClock = HSI_VALUE;
#elif defined (SYSCLK_HSE_XXMHz) && (SYSCLK_HSE_XXMHz >= 40000000U)
    uint32_t SystemCoreClock = SYSCLK_HSE_XXMHz;
#elif defined (SYSCLK_HSE_XXMHz) && (SYSCLK_HSE_XXMHz < 40000000U)
    uint32_t SystemCoreClock = HSE_VALUE;
#endif

#define RCC_CFGR_HPRE_DIV1              (0x00U << RCC_CFGR_HPRE_Pos)
#define RCC_CFGR_HPRE_DIV2              (0x08U << RCC_CFGR_HPRE_Pos)
#define RCC_CFGR_HPRE_DIV4              (0x09U << RCC_CFGR_HPRE_Pos)
#define RCC_CFGR_HPRE_DIV8              (0x0AU << RCC_CFGR_HPRE_Pos)
#define RCC_CFGR_HPRE_DIV16             (0x0BU << RCC_CFGR_HPRE_Pos)
#define RCC_CFGR_HPRE_DIV64             (0x0CU << RCC_CFGR_HPRE_Pos)
#define RCC_CFGR_HPRE_DIV128            (0x0DU << RCC_CFGR_HPRE_Pos)
#define RCC_CFGR_HPRE_DIV256            (0x0EU << RCC_CFGR_HPRE_Pos)
#define RCC_CFGR_HPRE_DIV512            (0x0FU << RCC_CFGR_HPRE_Pos)

#define RCC_CFGR_PPRE1_DIV1             (0x00U << RCC_CFGR_PPRE1_Pos)
#define RCC_CFGR_PPRE1_DIV2             (0x04U << RCC_CFGR_PPRE1_Pos)
#define RCC_CFGR_PPRE1_DIV4             (0x05U << RCC_CFGR_PPRE1_Pos)
#define RCC_CFGR_PPRE1_DIV8             (0x06U << RCC_CFGR_PPRE1_Pos)
#define RCC_CFGR_PPRE1_DIV16            (0x07U << RCC_CFGR_PPRE1_Pos)

#define RCC_CFGR_PPRE2_DIV1             (0x00U << RCC_CFGR_PPRE2_Pos)
#define RCC_CFGR_PPRE2_DIV2             (0x04U << RCC_CFGR_PPRE2_Pos)
#define RCC_CFGR_PPRE2_DIV4             (0x05U << RCC_CFGR_PPRE2_Pos)
#define RCC_CFGR_PPRE2_DIV8             (0x06U << RCC_CFGR_PPRE2_Pos)
#define RCC_CFGR_PPRE2_DIV16            (0x07U << RCC_CFGR_PPRE2_Pos)

#define RCC_CFGR_SW_HSI                 (0x00U << RCC_CFGR_SW_Pos)         
#define RCC_CFGR_SW_HSE                 (0x01U << RCC_CFGR_SW_Pos)         
#define RCC_CFGR_SW_PLL                 (0x02U << RCC_CFGR_SW_Pos)         
#define RCC_CFGR_SW_LSI                 (0x03U << RCC_CFGR_SW_Pos)  

#define RCC_CFGR_SWS_HSI                (0x00U << RCC_CFGR_SWS_Pos)         
#define RCC_CFGR_SWS_HSE                (0x01U << RCC_CFGR_SWS_Pos)         
#define RCC_CFGR_SWS_PLL                (0x02U << RCC_CFGR_SWS_Pos)           
#define RCC_CFGR_SWS_LSI                (0x03U << RCC_CFGR_SWS_Pos)           
       

/**
  * @brief  use to return the pll_div & pll_mul.
  * @param  pllclkSourceFrq : PLL source clock frquency;
  *         pllclkFrq : Target PLL clock frquency;
  *         pll_mul : PLL factor PLL  Multiplication Factor
  *         pll_div : PLL factor PLL Divide Factor
  * @retval amount of error
  */
uint32_t AutoCalPllFactor(uint32_t pllclkSourceFrq, uint32_t pllclkFrq, uint8_t *pll_mul, uint8_t *pll_div)
{
    uint32_t mul_temp, div_temp, mul_max, div_max;
    uint32_t tempFrq = 0;
    uint32_t minDiff = pllclkFrq;
    uint8_t  flag    = 0;

    mul_max = RCC_PLLCFGR_PLLMUL_Msk >> RCC_PLLCFGR_PLLMUL_Pos;
    div_max = RCC_PLLCFGR_PLLDIV_Msk >> RCC_PLLCFGR_PLLDIV_Pos;

    for (div_temp = 1; div_temp <= div_max; div_temp += 2)
    {
        for (mul_temp = 0; mul_temp <= mul_max; mul_temp++)
        {
            tempFrq = pllclkSourceFrq / (div_temp + 1) * (mul_temp + 1);
            tempFrq = (tempFrq > pllclkFrq) ? (tempFrq - pllclkFrq) : (pllclkFrq - tempFrq);

            if (minDiff > tempFrq)
            {
                minDiff = tempFrq;
                *pll_mul   = mul_temp;
                *pll_div   = div_temp;
            }

            if (minDiff == 0)
            {
                flag = 1;
                break;
            }
        }

        if (flag != 0)
        {
            break;
        }
    }

    return (minDiff);
}

/**
  * @brief  Configures the System clock frequency, HCLK, PCLK2 and PCLK1 prescalers.
  * @param  None
  * @retval None
  */
static void SetSysClockToDefine(void)
{
    __IO uint32_t  tn, tm, StartUpCounter = 0, ClkSrcStatus = 1;
    uint8_t pll_mul, pll_div;
    uint32_t temp = 0, i = 0;

#ifdef SYSCLK_HSE_XXMHz
    /* HSE Current Mode Select */
    RCC->CR &= ~RCC_CR_HSEIB_Msk;

    if (HSE_VALUE >= 12000000)
    {
        RCC->CR |= (0x03 << RCC_CR_HSEIB_Pos);
    }
    else
    {
        RCC->CR |= (0x01 << RCC_CR_HSEIB_Pos);
    }

    /* Enable HSE */
    RCC->CR |= (0x01U << RCC_CR_HSEON_Pos);

    /* Wait till HSE is ready and if Time out is reached exit */
    do
    {
        ClkSrcStatus = RCC->CR & RCC_CR_HSERDY_Msk;
        StartUpCounter++;
    }
    while((ClkSrcStatus == 0) && (StartUpCounter != HSE_STARTUP_TIMEOUT));

    if ((RCC->CR & RCC_CR_HSERDY_Msk) != RESET)
    {
        ClkSrcStatus = (uint32_t)0x01;
    }
    else
    {
        ClkSrcStatus = (uint32_t)0x00;
    }

    SystemCoreClock = SYSCLK_HSE_XXMHz;

    /* Config PLL clock source*/
    RCC->PLLCFGR |= (0x01U << RCC_PLLCFGR_PLLSRC_Pos);

    /* calculate PLL factor*/
    AutoCalPllFactor(HSE_VALUE, SystemCoreClock, &pll_mul, &pll_div);

    /* set PLL CP Current Control Signals */
    RCC->PLLCFGR &= ~RCC_PLLCFGR_PLL_ICTRL_Msk;
    if(HSE_VALUE >= 8000000)
    {
        RCC->PLLCFGR |= (0x03 << RCC_PLLCFGR_PLL_ICTRL_Pos);
    }
    else 
    {
        RCC->PLLCFGR |= (0x01 << RCC_PLLCFGR_PLL_ICTRL_Pos);
    }
#else
    /* Enable HSI */
    RCC->CR |= (0x01U << RCC_CR_HSION_Pos);

    /* Wait till HSI is ready and if Time out is reached exit */
    do
    {
        ClkSrcStatus = RCC->CR & RCC_CR_HSIRDY_Msk;
        StartUpCounter++;
    }
    while((ClkSrcStatus == 0) && (StartUpCounter != HSI_STARTUP_TIMEOUT));

    if ((RCC->CR & RCC_CR_HSIRDY_Msk) != RESET)
    {
        ClkSrcStatus = (uint32_t)0x01;
    }
    else
    {
        ClkSrcStatus = (uint32_t)0x00;
    }

    SystemCoreClock = SYSCLK_HSI_XXMHz;

    /* Config PLL clock source*/
    RCC->PLLCFGR &= ~(0x01U << RCC_PLLCFGR_PLLSRC_Pos);

    /* calculate PLL factor*/
    AutoCalPllFactor(HSI_VALUE, SystemCoreClock, &pll_mul, &pll_div);

    /* set PLL CP Current Control Signals */
    RCC->PLLCFGR &= ~RCC_PLLCFGR_PLL_ICTRL_Msk;
    if(HSI_VALUE >= 8000000)
    {
        RCC->PLLCFGR |= (0x03 << RCC_PLLCFGR_PLL_ICTRL_Pos);
    }
    else 
    {
        RCC->PLLCFGR |= (0x01 << RCC_PLLCFGR_PLL_ICTRL_Pos);
    }
#endif

    if (ClkSrcStatus == (uint32_t)0x01)
    {
        FLASH->ACR &= ~FLASH_ACR_LATENCY_Msk;
        FLASH->ACR |= (0x01U << FLASH_ACR_PRFTBE_Pos);
        temp = (SystemCoreClock - 1) / 24000000;

        if (temp > 1)
        {
            temp = 1;
        }
        FLASH->ACR |= temp;


        /* HCLK = SYSCLK/8 */
        temp      = RCC->CFGR;
        temp     &= ~RCC_CFGR_HPRE_Msk;
        temp     |= RCC_CFGR_HPRE_DIV8;
        RCC->CFGR = temp;

        /* PCLK2 = HCLK */
        temp      = RCC->CFGR;
        temp     &= ~RCC_CFGR_PPRE2_Msk;
        temp     |= RCC_CFGR_PPRE2_DIV1;
        RCC->CFGR = temp;

        /* PCLK1 = HCLK */
        temp      = RCC->CFGR;
        temp     &= ~RCC_CFGR_PPRE1_Msk;
        temp     |= RCC_CFGR_PPRE1_DIV1;
        RCC->CFGR = temp;

#if defined (SYSCLK_HSI_XXMHz) && (SYSCLK_HSI_XXMHz < 40000000U)
        /* Select HSI as system clock source */
        RCC->CFGR &= ~RCC_CFGR_SW_Msk;
        RCC->CFGR |= RCC_CFGR_SW_HSI;

#elif defined (SYSCLK_HSE_XXMHz) && (SYSCLK_HSE_XXMHz < 40000000U)
        /* Select HSE as system clock source */
        RCC->CFGR &= ~RCC_CFGR_SW_Msk;
        RCC->CFGR |= RCC_CFGR_SW_HSE;
#else
        /* configuration PLL */
        RCC->PLLCFGR &= ~RCC_PLLCFGR_PLLPDIV_Msk;
        RCC->PLLCFGR &= ~RCC_PLLCFGR_PLLMUL_Msk;
        RCC->PLLCFGR &= ~RCC_PLLCFGR_PLLDIV_Msk;

        RCC->PLLCFGR |= ((pll_mul << RCC_PLLCFGR_PLLMUL_Pos) | (pll_div << RCC_PLLCFGR_PLLDIV_Pos));

        /* Enable PLL */
        RCC->CR |= (0x01U << RCC_CR_PLLON_Pos) ;

        /* Wait till PLL is ready */
        while ((RCC->CR & RCC_CR_PLLRDY_Msk) == 0)
        {
            __ASM("nop");                  /* __NOP(); */
        }

        /* Select PLL as system clock source */
        RCC->CFGR &= ~RCC_CFGR_SW_Msk;
        RCC->CFGR |=  RCC_CFGR_SW_PLL;

        /* Wait till PLL is used as system clock source */
        while ((RCC->CFGR & RCC_CFGR_SWS_Msk) != RCC_CFGR_SWS_PLL)
        {
            __ASM("nop");                  /* __NOP(); */
        }
#endif


        for (i = 0; i < 1000; i++)
        {
            __ASM("nop");
        }

        /* HCLK = SYSCLK/4 */
        temp      = RCC->CFGR;
        temp     &= ~RCC_CFGR_HPRE_Msk;
        temp     |= RCC_CFGR_HPRE_DIV4;
        RCC->CFGR = temp;

        for (i = 0; i < 1000; i++)
        {
            __ASM("nop");
        }

        /* HCLK = SYSCLK/2 */
        temp      = RCC->CFGR;
        temp     &= ~RCC_CFGR_HPRE_Msk;
        temp     |= RCC_CFGR_HPRE_DIV2;
        RCC->CFGR = temp;

        for (i = 0; i < 1000; i++)
        {
            __ASM("nop");
        }

        /* HCLK = SYSCLK */
        temp      = RCC->CFGR;
        temp     &= ~RCC_CFGR_HPRE_Msk;
        temp     |= RCC_CFGR_HPRE_DIV1;
        RCC->CFGR = temp;

        for (i = 0; i < 1000; i++)
        {
            __ASM("nop");
        }
    }
    else
    {
        /* If HSE not ready within the given time, the program will stop here.
           User can add here some code to deal with this error */
        while (1)
        {
            /* please check Whether the crystal oscillator starts*/
        }
    }
}

/**
  * @brief  Setup the microcontroller system Initialize the Embedded Flash Interface, 
  *         the PLL and update the SystemCoreClock variable.
  * @note   This function should be used only after reset.
  * @param  None
  * @retval None
  */
void SystemInit(void)
{

    /* Set HSION bit */
    RCC->CR |= (0x01U << RCC_CR_HSION_Pos);

    /* Reset SW, HPRE, PPRE1, PPRE2 and MCO bits */
    RCC->CFGR &= ~RCC_CFGR_SW_Msk;
    RCC->CFGR &= ~RCC_CFGR_HPRE_Msk;
    RCC->CFGR &= ~RCC_CFGR_PPRE1_Msk;
    RCC->CFGR &= ~RCC_CFGR_PPRE2_Msk;
    RCC->CFGR &= ~RCC_CFGR_MCO_Msk;

    /* Reset HSEON, CSSON and PLLON bits */
    RCC->CR &= ~RCC_CR_HSEON_Msk;
    RCC->CR &= ~RCC_CR_CSSHSON_Msk;
    RCC->CR &= ~RCC_CR_CSSLSON_Msk;
    RCC->CR &= ~RCC_CR_PLLON_Msk;

    /* Reset HSEBYP bit */
    RCC->CR &= ~RCC_CR_HSEBYP_Msk;

    /* Reset PLLSRC, PLLPDIV, PLLMUL, PLLDIV bits */
    RCC->PLLCFGR &= ~RCC_PLLCFGR_PLLSRC_Msk;
    RCC->PLLCFGR &= ~RCC_PLLCFGR_PLLPDIV_Msk;
    RCC->PLLCFGR &= ~RCC_PLLCFGR_PLLMUL_Msk;
    RCC->PLLCFGR &= ~RCC_PLLCFGR_PLLDIV_Msk;

    /* Disable all interrupts and clear pending bits */
    RCC->CIR = 0xFFFFFFFF; 
    RCC->CIR = 0; 

    /* Configure the System clock frequency, HCLK, PCLK2 and PCLK1 prescalers */
    /* Configure the Flash Latency cycles and enable prefetch buffer */
    SetSysClockToDefine();
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

