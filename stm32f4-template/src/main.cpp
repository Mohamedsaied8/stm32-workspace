/*
 * This is an stm32f4 template program
 */

/* stm32f4_discovery.h is located in Utilities/STM32F4-Discovery
 * and defines the GPIO Pins where the leds are connected.
 * Including this header also includes stm32f4xx.h and
 * stm32f4xx_conf.h, which includes stm32f4xx_gpio.h
 */
#include "led.h"
extern "C"
{
#include "stm32f4_discovery.h"
#include "stm32f4xx_conf.h"
}
void WaitMS();
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
    LED leds;
    while (1)
    {
        if((GPIO_ReadInputData(GPIOA)&(1<<0))==1)
        {
            WaitMS();   	
            leds.LEDS_ON();
            WaitMS();
      
        }
        else
        {
            leds.LEDS_OFF();
        }
     // GPIOD->ODR = 0xF000;
    }

    return 0; // never returns actually
}

void WaitMS()
{
       for(int i=0;i<10000;i++)
            __asm("nop");
}