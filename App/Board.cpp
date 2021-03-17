#include "Board.h"

// Платные функции


void LED_Init(void){
    LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOA);
    LL_GPIO_InitTypeDef gpio;

    gpio.Pin = LL_GPIO_PIN_6 | LL_GPIO_PIN_7;
    gpio.Mode = LL_GPIO_MODE_OUTPUT;
    gpio.Speed = LL_GPIO_SPEED_FREQ_VERY_HIGH;
    gpio.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
    gpio.Pull = LL_GPIO_PULL_NO;
//    GPIO_InitStruct.Alternate = LL_GPIO_AF_5;
    LL_GPIO_Init(GPIOA, &gpio);
    // Default OFF
    LL_GPIO_SetOutputPin(GPIOA, LL_GPIO_PIN_6);
    LL_GPIO_SetOutputPin(GPIOA, LL_GPIO_PIN_7);

}

void LED_Switch( TLED_Num myNum , bool myState) {

    uint32_t pin;
    if (myNum == LEDD2) pin =  LL_GPIO_PIN_6;
    if (myNum == LEDD3) pin =  LL_GPIO_PIN_7;

    switch (myState) {
    case LED_ON:
        LL_GPIO_ResetOutputPin (GPIOA, pin);
        break;
    case LED_OFF:
        LL_GPIO_SetOutputPin(GPIOA, pin);
        break;
    case LED_TOGGLE:
        if (GPIOA->ODR & pin)
            LL_GPIO_ResetOutputPin(GPIOA, pin);
        else
            LL_GPIO_SetOutputPin  (GPIOA, pin);
        break;

    }
}