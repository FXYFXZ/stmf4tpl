// Lets make brand new PRJ!!!!

#include "Main.h"

#include "stm32f4xx_ll_gpio.h"
#include "stm32f4xx_ll_bus.h"


void InitGPIO(void);


int main() {
    InitGPIO();
    while(true);
}



void InitGPIO(void){
// Светодиод

    LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOA);
    LL_GPIO_InitTypeDef gpio;

    gpio.Pin = LL_GPIO_PIN_6;
    gpio.Mode = LL_GPIO_MODE_OUTPUT;
    gpio.Speed = LL_GPIO_SPEED_FREQ_VERY_HIGH;
    gpio.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
    gpio.Pull = LL_GPIO_PULL_NO;
//    GPIO_InitStruct.Alternate = LL_GPIO_AF_5;
    LL_GPIO_Init(GPIOA, &gpio);


    LL_GPIO_SetOutputPin(GPIOA, LL_GPIO_PIN_6);




}
