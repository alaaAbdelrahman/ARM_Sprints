/**************************************************************
 **
 * @file main.c
 * @brief Main file for LED control program.
 * @author Alaa Abdelrahman 
 * @date 29/07/2022
 * @version 1.0
 * @mcu  STM32F11ceu
 * 
 * 
 **************************************************************/








#include "mcu_hw.h"
#include "std_types.h"
#include "systickTimer.h"
#include "led.h"


static  uint8_t u8Counter = 0;

static uint8_t u8Led_OnTime = TIME_ON_S ;
static uint8_t u8Period = TIME_OFF_S + TIME_ON_S ;





void LED_Control(void)
{
	/* increement counter */
	u8Counter++;
	
	if(u8Counter == u8Led_OnTime )
	{
		LED_On();
	}
	
	else if(u8Counter == u8Period )
	{
		LED_Off();
		
		u8Counter =  0 ;
	}
	
	
}



int main()
{
	
	/* Initalize the LED */
	LED_Init();
	
	/* initalize SysTick Timer */
	STK_Init();
	
	/* set callback */
	STK_SetCallBack( LED_Control );
	
	
	/* start timer*/
	STK_1S_Start();
	
	while(1);
	
	return 0;
}

