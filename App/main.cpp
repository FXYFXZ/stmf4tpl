// Lets make brand new PRJ!!!!

#include "Main.h"
#include "Board.h"

#include "stm32f4xx_hal.h"
#include "stm32f4xx_ll_rcc.h"


void InitGPIO(void);
void MCO_Out(void);
void HAL_GPIO_Init(void);



int main() {
    InitGPIO();
    LED_Init();
    MCO_Out();
   // LED_Switch(LEDD2, LED_ON);
   // LED_Switch(LEDD3, LED_ON);


    while(true);
}



void InitGPIO(void){




}

// Как у нас с частотой?
void MCO_Out(void){
    LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOA);

    LL_GPIO_InitTypeDef gpio;
    gpio.Pin = LL_GPIO_PIN_8;
    gpio.Mode = LL_GPIO_MODE_ALTERNATE;
    gpio.Speed = LL_GPIO_SPEED_FREQ_VERY_HIGH;
    gpio.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
    gpio.Pull = LL_GPIO_PULL_NO;
    gpio.Alternate = LL_GPIO_AF_0;
    LL_GPIO_Init(GPIOA, &gpio);

    HAL_RCC_MCOConfig(RCC_MCO1, RCC_MCO2SOURCE_SYSCLK, RCC_MCODIV_4);






}


void HAL_GPIO_Init(void){
}