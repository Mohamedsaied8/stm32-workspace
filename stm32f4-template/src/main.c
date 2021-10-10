/*
 * This is an stm32f4 template program
 */

/* stm32f4_discovery.h is located in Utilities/STM32F4-Discovery
 * and defines the GPIO Pins where the leds are connected.
 * Including this header also includes stm32f4xx.h and
 * stm32f4xx_conf.h, which includes stm32f4xx_gpio.h
 */
#include "stm32f4_discovery.h"
#include "stm32f4xx_conf.h"
//#include "D:/work/stm32_workspace/STM32F4-Discovery_FW_V1.1.0/Libraries/STM32F4xx_StdPeriph_Driver/inc/stm32f4xx_gpio.h"

/* Main function, the entry point of this program.
 * The main function is called from the startup code in file
 * Libraries/CMSIS/ST/STM32F4xx/Source/Templates/TrueSTUDIO/startup_stm32f4xx.s
 * (line 101)
 */
int main(void)
{
    //RCC->AHB1ENR |= 1;	//clock to GPIOA
   // RCC->AHB1ENR |= 1<<3;	//Clocks for GPIOD
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);
    //GPIOD->MODER |= 0x55000000;	//Bits 12..15 are output
    GPIO_InitTypeDef gpioLeds, gpioButton;
    gpioLeds.GPIO_Pin = GPIO_Pin_15 | GPIO_Pin_14 |GPIO_Pin_13 | GPIO_Pin_12;
    gpioLeds.GPIO_Mode = GPIO_Mode_OUT;
   // GPIO_Init_Port.GPIO_OType = GPIO_OType_PP;
    gpioLeds.GPIO_Speed = GPIO_Speed_100MHz;
    GPIO_Init(GPIOD,&gpioLeds);
    gpioButton.GPIO_Pin = GPIO_Pin_0;
    gpioButton.GPIO_Mode = GPIO_Mode_IN;
    GPIO_Init(GPIOA,&gpioButton);
    while (1)
    {
        if((GPIO_ReadInputData(GPIOA)&(1<<0))==1)
        {
            for(int i=0;i<1000;i++)
             	__asm("nop");
         GPIO_Write(GPIOD,0x8000);
         for(int i=0;i<10000;i++)
             	__asm("nop");

        // WaitMs(1000);

        }
        else{
            GPIO_Write(GPIOD,0x1000);
        }
     // GPIOD->ODR = 0xF000;
    }

    return 0; // never returns actually
}