/***********************************************************************************************************************
    @file     hal_fgpio.c
    @author   VV TEAM
    @brief    THIS FILE PROVIDES ALL THE UART FIRMWARE FUNCTIONS.
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
#include "hal_fgpio.h"

/**
  * @brief  Writes data to all FGPIO port pins.
  * @param  fgpio: select the FGPIO peripheral.
  * @param  value: specifies the value to be written to the port output data
  *         register.
  * @retval None.
  */
void FGPIO_Write(FGPIO_TypeDef* fgpio, uint16_t value)
{
    fgpio->ODR = value;
}

/**
  * @brief  Sets or clears the selected FGPIO port pin.
  * @param  fgpio: Select the FGPIO peripheral.
  * @param  pin: Specifies the port bit to be written.
  *         This parameter can be one of FGPIO_Pin_x where x can be (0..15).
  * @param  value: Specifies the value to be written to the selected bit.
  *         This parameter can be one of the BitAction enum values:
  * @arg    FGPIO_Bit_RESET: Clear the port pin
  * @arg    FGPIO_Bit_SET: Set the port pin
  * @retval None.
  */
void FGPIO_WriteBit(FGPIO_TypeDef* fgpio, uint16_t pin, uint8_t value)
{
    (value) ?             \
    (fgpio->BSRR = pin) : \
    (fgpio->BRR = pin);
}

/**
  * @brief  Sets the selected FGPIO port pin.
  * @param  fgpio: Select the FGPIO peripheral.
  * @param  pin: Specifies the port bit to be written.
  *         This parameter can be one of FGPIO_Pin_x where x can be (0..15).
  * @retval None.
  */
void FGPIO_SetBits(FGPIO_TypeDef* fgpio, uint16_t pin)
{
    fgpio->BSRR = pin;
}

/**
  * @brief  Clears the selected FGPIO port bit.
  * @param  fgpio: Select the FGPIO peripheral.
  * @param  pin: Specifies the port bit to be written.
  *         This parameter can be one of GPIO_Pin_x where x can be (0..15).
  * @retval None.
  */
void FGPIO_ResetBits(FGPIO_TypeDef* fgpio, uint16_t pin)
{
    fgpio->BRR = pin;
}

/**
  * @brief  Reads all FGPIO port pins input data.
  * @param  fgpio: select the FGPIO peripheral.
  * @retval FGPIO port input data value.
  */
uint16_t FGPIO_ReadInputData(FGPIO_TypeDef* fgpio)
{
    return (fgpio->IDR);
}

/**
  * @brief  Reads the input data of specified FGPIO port pin.
  * @param  fgpio: select the FGPIO peripheral.
  * @param  pin:  specifies the port pin to be read.
  *         This parameter can be FGPIO_Pin_x where x can be (0..15).
  * @retval The input port pin value.
  */
uint8_t FGPIO_ReadInputDataBit(FGPIO_TypeDef* gpio, uint16_t pin)
{
    return ((gpio->IDR & pin) ? FGPIO_Bit_SET : FGPIO_Bit_RESET);
}

/**
  * @brief  Reads all FGPIO port pins output data.
  * @param  fgpio: select the FGPIO peripheral.
  * @retval FGPIO port output data value.
  */
uint16_t FGPIO_ReadOutputData(FGPIO_TypeDef* fgpio)
{
    return (fgpio->ODR);
}

/**
  * @brief  Reads the output data of specified FGPIO port pin.
  * @param  fgpio: select the FGPIO peripheral.
  * @param  pin:  specifies the port bit to be read.
  *         This parameter can be FGPIO_Pin_x where x can be (0..15).
  * @retval The output port pin value.
  */
uint8_t FGPIO_ReadOutputDataBit(FGPIO_TypeDef* fgpio, uint16_t pin)
{
    return ((fgpio->ODR & pin) ? FGPIO_Bit_SET : FGPIO_Bit_RESET);
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



