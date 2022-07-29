
#ifndef SYSTICKTIMER_H_
#define SYSTICKTIMER_H_

#include"std_types.h"



/**
 * @brief load value of systick to overflow after 1ms
 */
 
#define SYSTICK_LOAD_VALUE       16000000

#define CTRL_EN                  (1UL << 0)

#define CTRL_TICKINT             (1UL << 1)

#define CTRL_CLKSRC              (1UL << 2)

#define CTRL_COUNTFLAG           (1UL << 16)






/**
 * @brief initialize systick timer with
 *                                      - clock source from processor clock
 *                                      - interrupt enable / disable                   
 *  @param  void description                                   
 * 
 * @return void
 */
void STK_Init(void);

/**
 * @brief enable systick timer
 * @param  void                                   
 * 
 * @return void
 */

void STK_1S_Start(void);

/**
 * @brief disable systick timer
 * @param  void description                                   
 * 
 * @return void
 */

void STK_Disable(void);

/**
    * @brief get current value of systick timer
    * @param  void description                                   
    * 
    * @return current value of systick timer
    */

 uint32_t SYSTICK_GetCurrentValue(void);


/**
 * @brief set delay with milliseconds
 * @param  u8Delay in milliseconds
 * 
 * @return void
 */
void STK_SetDelay(uint8_t u8Delay);

/**
 * @brief callback the function that will be called when interrupt occurs
 *  
 * @param ptr  pionter to function that will be called when interrupt occurs
 * 
 * @return void
 */


void STK_SetCallBack( void (*ptr)(void) );
 



#endif /* SYSTICKTIMER_H_ */
