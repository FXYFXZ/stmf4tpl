#ifndef  __BOARD_H__
#define __BOARD_H__

#include "main.h"

#include "stm32f4xx_ll_gpio.h"
#include "stm32f4xx_ll_bus.h"

// Светодиоды на плате
typedef enum {
    LEDD2,
    LEDD3
} TLED_Num;

// состояние светодиода
typedef enum {
  LED_ON,
  LED_OFF,
  LED_TOGGLE,
} TLEDState;

// Export
void LED_Init(void);
void LED_Switch( TLED_Num myNum , bool myState);

#endif