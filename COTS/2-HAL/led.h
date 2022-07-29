
#ifndef LED_H_      
#define LED_H_

#define LED_PORT   GPIOA
#define LED_PIN      5

#define TIME_ON_S    1
#define TIME_OFF_S   1


void LED_Init(void);

void LED_On(void);

void LED_Off(void);

#endif /* LED_H_ */

