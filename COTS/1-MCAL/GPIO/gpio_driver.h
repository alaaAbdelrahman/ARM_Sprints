

#ifndef GPIO_DRIVER_H
#define GPIO_DRIVER_H

#include "std_types.h"
#include  "mcu_hw.h"



/********************************************************************************************************************************/
/*                                     																																													*/
/*                    1. Macros used for GPIO pin Inialiization                                                                 */                 
/*																																																															*/
/********************************************************************************************************************************/

/* GPIO Mode Settings values */
#define GPIO_PIN_IN_MODE           ((uint32_t)0x00)
#define GPIO_PIN_OUT_MODE          ((uint32_t)0x01)
#define GPIO_PIN_ALT_FUN_MODE      ((uint32_t)0x02)

 
/* GPIO Output Type Selection values */

#define GPIO_PIN_OUT_PUSH_PULL       ((uint32_t) 0x00)
#define GPIO_PIN_OUT_OPEN_DRAIN      ((uint32_t) 0x01)


/*GPIO Speed Selection Values */

#define GPIO_PIN_SPD_LOW              ((uint32_t)0x00)
#define GPIO_PIN_SPD_MEDIUM           ((uint32_t)0x01)
#define GPIO_PIN_SPD_HIGH             ((uint32_t)0x02)
#define GPIO_PIN_SPD_FAST             ((uint32_t)0x03)

/* GPIO pull up / pull down resistor selection values */

#define GPIO_PIN_NO_PULL             ((uint32_t)0x00)
#define GPIO_PIN_PULL_UP             ((uint32_t)0x01)
#define GPIO_PIN_PULL_DOWN           ((uint32_t)0x02)

/* MACROS to enable clock for different GPIO ports in RCC registers */

#define RCC_GPIOA_CLK_EN()            (RCC->AHB1ENR |=(1<<0))
#define RCC_GPIOB_CLK_EN()            (RCC->AHB1ENR |=(1<<1))
#define RCC_GPIOC_CLK_EN()            (RCC->AHB1ENR |=(1<<2))
#define RCC_GPIOD_CLK_EN()            (RCC->AHB1ENR |=(1<<3))
#define RCC_GPIOE_CLK_EN()            (RCC->AHB1ENR |=(1<<4))


/************************************************************************/
/*																														*/
/*  					Data structure for GPIO pin Initalization       */
/*																														*/
/************************************************************************/

/**
* @brief GPIO pin structure for configuration parameters
*        this structure will be filled and passed to driver by the user 
*         to initialize the gpio pin
*/
typedef struct 
{
	uint8_t u8Pin    ;   /*Specifies the gpio pin to be configured*/
	uint8_t u8Mode   ;   /*Specifies the operating mode for configured pin*/
	uint8_t u8OutType;   /*Specifies the output type */
	uint8_t u8Pull   ;   /*Specifies the pull up or pull dowm activation*/
	uint8_t u8Speed  ;   /*Specifies the speed */
	uint8_t u8Alt    ;   /* specifies the alternative function if the mode is set for alt function*/
}GPIO_pin_config_t;


/**
 * @brief interrupt mode selection for GPIO pin
 */
typedef enum{
		INT_MODE_RISE,
		INT_MODE_FALL,
		INT_MODE_RISE_FALL
} edg_sel_t;

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
void GPIO_init(GPIO_t  * GPIOx, GPIO_pin_config_t * gpio_pin_config);



/**
  * @brief write the gpio pin value
  * @param GPIOx: pointer to gpio peripheral
  * @param u8Pin: pin number to be set
  * @param u8Value: value to be set to the pin
  * @retval none
  */
void GPIO_write_pin_value(GPIO_t * GPIOx, uint8_t u8Pin, uint8_t u8Value);

/**
  * @brief read the gpio pin value
  * @param GPIOx: pointer to gpio peripheral
  * @param u8Pin: pin number to be get
  * @retval pin value
  */

uint8_t GPIO_read_pin_value(GPIO_t * GPIOx, uint8_t u8Pin);

/**
  * @brief toggle the gpio pin value
  * @param GPIOx: pointer to gpio peripheral
  * @param u8Pin: pin number to be toggled
  * @retval none
  */

void GPIO_toggle_pin_value(GPIO_t * GPIOx, uint8_t u8Pin);

/**
 * @brief write port value to the gpio port
 * @param GPIOx: pointer to gpio peripheral
 * @param u16Value: value to be written to the port
 * @retval none
 */
void GPIO_write_port_value(GPIO_t * GPIOx, uint16_t u16Value);

/**
 * @brief atomic write to the gpio PORT
 * @param GPIOx: pointer to gpio peripheral
 * @param u8Pin: pin to write to it
 * @param u8Val: value to be written to the pin
 * @retval none
 */
void GPIO_write_pin_value_atomic(GPIO_t * GPIOx,uint8_t u8Pin, uint8_t u8Val);

/**
 * @brief read port value from the gpio port
 * @param GPIOx: pointer to gpio peripheral
 * @retval port value
 */
uint16_t GPIO_read_port_value(GPIO_t * GPIOx);

/**
 * @brief write alternate function value to the gpio pin
 * @param GPIOx: pointer to gpio peripheral	
 * @param u8Pin: pin number to be set
 * @param u16Value: value to be set to the pin
 * @retval none
 */
void GPIO_write_pin_alt_value(GPIO_t * GPIOx, uint8_t u8Pin, uint16_t u16Value);

/**
 * @brief configure the interrupt for a given  gpio pin
 
 * @param u8Pin: pin number to be get
 * @param edg_sel: triggering edge selection from type  edg_sel_t
 * @retval None
 */

void GPIO_configure_interrupt( uint8_t u8Pin, edg_sel_t edg_sel);

/**
 * @brief enable the interrupt for a given  gpio pin
 * @param u8Pin: pin number to be get
 * @retval None
 */
void GPIO_enable_interrupt(uint8_t u8Pin);
/**
 * @brief disable the interrupt for a given  gpio pin	
 * @param u8Pin: pin number to be get
 * @retval None
 */

void GPIO_disable_interrupt( uint8_t u8Pin);
#endif

