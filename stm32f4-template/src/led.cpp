extern "C"
{
#include "stm32f4_discovery.h"
#include "stm32f4xx_conf.h"
}
#include "led.h"
LED::LED()
{
    Init_LED();
    LEDS_OFF();
}

void LED::LEDS_ON()
{
    GPIO_Write(GPIOD,0xF000);

}
void LED::LEDS_OFF()
{
    GPIO_Write(GPIOD,0x0000);
}

void LED::Init_LED()
 {
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
}