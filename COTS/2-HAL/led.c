





#include "std_types.h"

#include "mcu_hw.h"



#include "gpio_driver.h"

#include "led.h"


GPIO_pin_config_t led_config;


/**
 * @brief initialize LED
 * @param  void description                                   
 * 
 * @return void
 */
void LED_Init(void)
{			
	      led_config.u8Pin    = LED_PIN;
				led_config.u8Mode   = GPIO_PIN_OUT_MODE;
				led_config.u8OutType = GPIO_PIN_SPD_MEDIUM;
				led_config.u8Pull    = GPIO_PIN_NO_PULL ;
				led_config.u8Speed   = GPIO_PIN_OUT_PUSH_PULL;
				led_config.u8Alt     = 0;
    
      	/* enable gpioa */
           AHBENR = 1;
	
        GPIO_init(LED_PORT ,  &led_config);
}

void LED_On(void)
{
    GPIO_write_pin_value(LED_PORT , LED_PIN , 1);
}

void LED_Off(void)
{
    GPIO_write_pin_value(LED_PORT , LED_PIN , 0);
}

