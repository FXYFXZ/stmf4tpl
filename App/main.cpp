// Lets make brand new PRJ!!!!

#include "Main.h"
#include "Board.h"

#include "stm32f4xx_hal.h"
#include "stm32f4xx_ll_rcc.h"



uint32_t RCC_GetSystemClockFreq(void);


void InitGPIO(void);
void MCO_Out(void);
void HAL_GPIO_Init(void);




void SetMyClock(void){

    RCC_OscInitTypeDef RCC_OscInitStruct;
    RCC_ClkInitTypeDef RCC_ClkInitStruct;
    __PWR_CLK_ENABLE();
    __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

    RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
    RCC_OscInitStruct.HSEState = RCC_HSE_ON;
    RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
    RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
    RCC_OscInitStruct.PLL.PLLM = 8; // i'm using 8 MHz crystal
    RCC_OscInitStruct.PLL.PLLN = 192;
    RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2; // ((25/M)*N)/P = 96 MHz
    RCC_OscInitStruct.PLL.PLLQ = 4;
    HAL_RCC_OscConfig(&RCC_OscInitStruct);

    RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_SYSCLK|RCC_CLOCKTYPE_PCLK1
    |RCC_CLOCKTYPE_PCLK2;
    RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
    RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
    RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
    RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;
    HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_3);

//    HAL_SYSTICK_Config(HAL_RCC_GetHCLKFreq()/1000);
//    HAL_SYSTICK_CLKSourceConfig(SYSTICK_CLKSOURCE_HCLK);
}



int main() {
    InitGPIO();
    LED_Init();
    MCO_Out();
    LED_Switch(LEDD2, LED_ON);
   // LED_Switch(LEDD3, LED_ON);

//    HAL_RCC_ClockConfig();

    SetMyClock();

 //   uint32_t clk =   RCC_GetSystemClockFreq();
 //   if (clk > 16000000) LED_Switch(LEDD3, LED_ON);


    while(true);
}



void InitGPIO(void){




}

// Как у нас с частотой?
void MCO_Out(void){
    LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOA);
    LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOC);
//    LL_GPIO_InitTypeDef gpio;
//    gpio.Pin = LL_GPIO_PIN_9;
//    gpio.Mode = LL_GPIO_MODE_ALTERNATE;
//    gpio.Speed = LL_GPIO_SPEED_FREQ_VERY_HIGH;
//    gpio.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
//    gpio.Pull = LL_GPIO_PULL_NO;
//    gpio.Alternate = LL_GPIO_AF_0;
//    LL_GPIO_Init(GPIOA, &gpio);

    HAL_RCC_MCOConfig(RCC_MCO2, RCC_MCO2SOURCE_PLLCLK, RCC_MCODIV_5);
  //  HAL_RCC_MCOConfig(RCC_MCO2, RCC_MCO1SOURCE_PLLCLK, RCC_MCODIV_5);


 //   HAL_RCC_MCOConfig(RCC_MCO2, RCC_MCO2SOURCE_SYSCLK, RCC_MCODIV_5);




}


void HAL_GPIO_Init(void){
}