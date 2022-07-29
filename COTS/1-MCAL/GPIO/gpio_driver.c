


#include "gpio_driver.h"

/**************************************************************/
/*																														*/
/*  					DRIVER APIS                                     */
/*																														*/
/**************************************************************/

/**
  * @brief initialize the gpio pin
  * @param GPIOx: pointer to gpio peripheral
  * @param gpio_pin_config: pionter to pin config structure sent 
  * @retval none
  */
void GPIO_init(GPIO_t  * GPIOx, GPIO_pin_config_t * gpio_pin_config)
{
    /* set the pin mode */
    GPIOx->MODER |= (gpio_pin_config->u8Mode << (gpio_pin_config->u8Pin * 2));

    /* set the pin speed */
    GPIOx->OSPEEDR |= (gpio_pin_config->u8Speed << (gpio_pin_config->u8Pin * 2));

    /* set the output type */
    GPIOx->OTYPER |= (gpio_pin_config->u8OutType << gpio_pin_config->u8Pin);

    /* set the pull up or pull down activation */
    GPIOx->PUPDR |= (gpio_pin_config->u8Pull << (gpio_pin_config->u8Pin * 2));

    /* set the alternative function */
    if (gpio_pin_config->u8Mode == GPIO_PIN_ALT_FUN_MODE)
    {
        if(gpio_pin_config->u8Pin < 8)
        {
            GPIOx->AFR[0] |= (gpio_pin_config->u8Alt << (gpio_pin_config->u8Pin * 4));
        }
        else
        {
            GPIOx->AFR[1] |= (gpio_pin_config->u8Alt << ((gpio_pin_config->u8Pin - 8) * 4));
        }
    }

}


/**
  * @brief write the gpio pin value
  * @param GPIOx: pointer to gpio peripheral
  * @param u8Pin: pin number to be set
  * @param u8Value: value to be set to the pin
  * @retval none
  */
void GPIO_write_pin_value(GPIO_t * GPIOx, uint8_t u8Pin, uint8_t u8Value)
{
    if (u8Value )
    {
        /* set the pin value */
        GPIOx->ODR |= (1 << u8Pin);
    }
    else
    {
        /* clear the pin value */
        GPIOx->ODR &= ~(1 << u8Pin);
    }

}

/**
  * @brief read the gpio pin value
  * @param GPIOx: pointer to gpio peripheral
  * @param u8Pin: pin number to be get
  * @retval pin value
  */

uint8_t GPIO_read_pin_value(GPIO_t * GPIOx, uint8_t u8Pin)
{
    return (GPIOx->IDR >> u8Pin) & 0x0001;
}

/**
  * @brief toggle the gpio pin value
  * @param GPIOx: pointer to gpio peripheral
  * @param u8Pin: pin number to be toggled
  * @retval none
  */

void GPIO_toggle_pin_value(GPIO_t * GPIOx, uint8_t u8Pin)
{
    GPIOx->ODR ^= (1 << u8Pin);
}

/**
 * @brief write port value to the gpio port
 * @param GPIOx: pointer to gpio peripheral
 * @param u16Value: value to be written to port
 * @retval none
 */
void GPIO_write_port_value(GPIO_t * GPIOx, uint16_t u16Value)
{
    GPIOx->ODR = u16Value;
    
}

/**
 * @brief atomic write to the gpio PORT
 * @param GPIOx: pointer to gpio peripheral
 * @param u8Pin: pin to write to it
 * @param u8Val: value to be written to the pin
 * @retval none
 */
void GPIO_write_pin_value_atomic(GPIO_t * GPIOx,uint8_t u8Pin, uint8_t u8Val)
{
    if (u8Val )
    {
        GPIOx->BSRR |= (1 << u8Pin);
    }
    else
    {
        GPIOx->BSRR |= (1 << (u8Pin +16));
    }
}

/**
 * @brief read port value from the gpio port
 * @param GPIOx: pointer to gpio peripheral
 * @retval port value
 */
uint16_t GPIO_read_port_value(GPIO_t * GPIOx)
{
	 uint16_t u16Val = GPIOx->IDR;
    return u16Val;
}

/**
 * @brief write alternate function value to the gpio pin
 * @param GPIOx: pointer to gpio peripheral	
 * @param u8Pin: pin number to be set
 * @param u16Value: value to be set to the pin
 * @retval none
 */
void GPIO_write_pin_alt_value(GPIO_t * GPIOx, uint8_t u8Pin, uint16_t u16Value)
{
    if (u8Pin < 8)
    {
        GPIOx->AFR[0] |= (u16Value << (u8Pin * 4));
    }
    else
    {
        GPIOx->AFR[1] |= (u16Value << ((u8Pin - 8) * 4));
    }
}


/**
 * @brief configure the interrupt for a given  gpio pin
 
 * @param u8Pin: pin number to be get
 * @param edg_sel: triggering edge selection from type  edg_sel_t
 * @retval None
 */

void GPIO_configure_interrupt( uint8_t u8Pin, edg_sel_t edg_sel)

{
    if(edg_sel == INT_MODE_RISE)
    {
        EXTI->RTSR |= (1 << u8Pin);
    }
    else if (edg_sel == INT_MODE_FALL)
    {
        EXTI->FTSR |= (1 << u8Pin);
    }
    else if (edg_sel == INT_MODE_RISE_FALL)
    {
        EXTI->RTSR |= (1 << u8Pin);
        EXTI->FTSR |= (1 << u8Pin);
    }
    else
    {
        EXTI->RTSR &= ~(1 << u8Pin);
        EXTI->FTSR &= ~(1 << u8Pin);
    }
}

/**
 * @brief enable the interrupt for a given  gpio pin
 * @param GPIOx: pointer to gpio peripheral	
 * @param u8Pin: pin number to be get
 * @retval None
 */
void GPIO_enable_interrupt(uint8_t u8Pin)
{
    EXTI->IMR |= (1 << u8Pin);
    // NVIC_EnableIRQ(EXTI0_IRQn + u8Pin);
}

/**
 * @brief disable the interrupt for a given  gpio pin
 * @param GPIOx: pointer to gpio peripheral	
 * @param u8Pin: pin number to be get
 * @retval None
 */

void GPIO_disable_interrupt( uint8_t u8Pin)
{
    EXTI->IMR &= ~(1 << u8Pin);
    // NVIC_DisableIRQ(EXTI0_IRQn + u8Pin);
}

/**
 * @brief clear the interrupt flag for a given  gpio pin
 * @param GPIOx: pointer to gpio peripheral	
 * @param u8Pin: pin number to be get
 * @retval None
 */

void GPIO_clear_interrupt_flag( uint8_t u8Pin)
{
    EXTI->PR |= (1 << u8Pin);
}



