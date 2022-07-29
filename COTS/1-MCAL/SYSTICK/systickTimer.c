

#include "mcu_hw.h"

#include "systickTimer.h"


/**
 * @brief global function pionter to pass to it callback function
 * 
 */
 static void ( * STK_CallBack ) ( void );


/**
 * @brief initialize systick timer with
 *                                      - clock source from processor clock
 *                                      - interrupt enable / disable                   
 *  @param  void description                                   
 * 
 * @return void
 */
void STK_Init(void)
{
    /* enable systick  and select internal clk source */
    SysTick->CTRL |= CTRL_CLKSRC | CTRL_TICKINT;
}

/**
 * @brief enable systick timer
 * @param  void                                   
 * 
 * @return void
 */

void STK_1S_Start(void)

{
    /* set reload value */
    SysTick->LOAD = (SYSTICK_LOAD_VALUE- 1);
    

    /* clear the counter register value */
    SysTick->VAL = 0;
   
    /* enable systick */
    SysTick->CTRL |= CTRL_EN;
}

/**
 * @brief disable systick timer
 * @param  void description                                   
 * 
 * @return void
 */

void STK_Disable(void)
{
    /* disable systick */
    SysTick->CTRL &= ~CTRL_EN;
}

/**
    * @brief get current value of systick timer
    * @param  void description                                   
    * 
    * @return current value of systick timer
    */

uint32_t SYSTICK_GetCurrentValue(void)
{
    return SysTick->VAL;
}


/**
 * @brief set delay with milliseconds
 * @param  u8Delay in milliseconds
 * 
 * @return void
 */
void STK_SetDelay(uint8_t u8Delay)
{
    /* set reload value */
    SysTick->LOAD = (u8Delay) *(16000- 1);

    /* clear the counter register value */
    SysTick->VAL = 0;

    /* disable interrupt */
    SysTick->CTRL &= ~CTRL_EN;

    /* wait for flag to raise */
    while ((SysTick->CTRL & CTRL_COUNTFLAG) == 0);
    
    



}

/**
 * @brief callback the function that will be called when interrupt occurs
 *  
 * @param ptr  pionter to function that will be called when interrupt occurs
 * 
 * @return void
 */


void STK_SetCallBack( void (*ptr)(void) )
{
    STK_CallBack = ptr;
}
 

/**
 * @brief ISR for systick timer
 * @param  void description                                   
 * 
 * @return void
 */
void SysTick_Handler(void){

	STK_CallBack();

}