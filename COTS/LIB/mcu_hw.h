

#ifndef MCU_HW_H
#define MCU_HW_H

#include<stdint.h>

/****************************************************************/
/* 																															*/             
/* 						         TYPE DEFINITION             							*/
/* 																															*/
/****************************************************************/

/** 
  *@brief Reset and Clock Control
  */

typedef struct
{volatile  uint32_t CR;
	volatile uint32_t CFGR;
	volatile uint32_t CIR;
	volatile uint32_t APB2RSTR;
	volatile uint32_t APB1RSTR;
	volatile uint32_t AHB1ENR;
	volatile uint32_t APB2ENR;
	volatile uint32_t APB1ENR;
	volatile uint32_t BDCR;
	volatile uint32_t CSR;
} RCC_t;

/**
	*@brief GPIO registers
	*/

typedef struct
{
  volatile uint32_t MODER;    /*!< GPIO port mode register,               Address offset: 0x00      */
  volatile uint32_t OTYPER;   /*!< GPIO port output type register,        Address offset: 0x04      */
  volatile uint32_t OSPEEDR;  /*!< GPIO port output speed register,       Address offset: 0x08      */
  volatile uint32_t PUPDR;    /*!< GPIO port pull-up/pull-down register,  Address offset: 0x0C      */
  volatile uint32_t IDR;      /*!< GPIO port input data register,         Address offset: 0x10      */
  volatile uint32_t ODR;      /*!< GPIO port output data register,        Address offset: 0x14      */
  volatile uint32_t BSRR;     /*!< GPIO port bit set/reset register,      Address offset: 0x18      */
  volatile uint32_t LCKR;     /*!< GPIO port configuration lock register, Address offset: 0x1C      */
  volatile uint32_t AFR[2];   /*!< GPIO alternate function registers,     Address offset: 0x20-0x24 */
} GPIO_t;


/** 
  *@brief External Interrupt/Event Controller
  */

typedef struct
{
  volatile  uint32_t IMR;    /*!< EXTI Interrupt mask register,            Address offset: 0x00 */
  volatile  uint32_t EMR;    /*!< EXTI Event mask register,                Address offset: 0x04 */
  volatile  uint32_t RTSR;   /*!< EXTI Rising trigger selection register,  Address offset: 0x08 */
  volatile  uint32_t FTSR;   /*!< EXTI Falling trigger selection register, Address offset: 0x0C */
  volatile  uint32_t SWIER;  /*!< EXTI Software interrupt event register,  Address offset: 0x10 */
  volatile  uint32_t PR;     /*!< EXTI Pending register,                   Address offset: 0x14 */
} EXTI_t;


/**
  *@brief SYSTICK  registers
  */

  typedef struct
  {
    volatile uint32_t CTRL;   /*!< SysTick control and status register, Address offset: 0x00 */
    volatile uint32_t LOAD;   /*!< SysTick reload value register,        Address offset: 0x04 */
    volatile uint32_t VAL;    /*!< SysTick value register,                Address offset: 0x08 */
    volatile uint32_t CALIB;  /*!< SysTick calibration value register,    Address offset: 0x0C */
  } SYSTICK_t;
  


/****************************************************************/
/* 																															*/             
/* 						          peripheral memory map      							*/
/* 																															*/
/****************************************************************/


#define PERIPH_BASE           0x40000000UL  /*< Peripheral base address in the alias region                                */
#define APB1PERIPH_BASE       PERIPH_BASE
#define APB2PERIPH_BASE       (PERIPH_BASE + 0x00010000UL)
#define AHB1PERIPH_BASE       (PERIPH_BASE + 0x00020000UL)
#define AHB2PERIPH_BASE       (PERIPH_BASE + 0x10000000UL)


/*< base address of  RCC peripheral */
#define RCC_BASE              (0x40023800)

/* RCC peripheral */
#define RCC                       ((RCC_t *)RCC_BASE )
#define AHBENR                    *((volatile uint32_t*) 0x40023830)



/**
 * @brief systick timer address
 * 
 */

#define SYSTICK_BASE							(0xE000E010)

#define SysTick                ((SYSTICK_t *)SYSTICK_BASE)


/*< base addresses of  GPIO peripherals  */
#define GPIOA_BASE            (AHB1PERIPH_BASE + 0x0000UL)
#define GPIOB_BASE            (AHB1PERIPH_BASE + 0x0400UL)
#define GPIOC_BASE            (AHB1PERIPH_BASE + 0x0800UL)
#define GPIOD_BASE            (AHB1PERIPH_BASE + 0x0C00UL)
#define GPIOE_BASE            (AHB1PERIPH_BASE + 0x1000UL)

/* GPIO peripherals */

#define GPIOA                 ((GPIO_t *)GPIOA_BASE)
#define GPIOB                 ((GPIO_t *)GPIOB_BASE)
#define GPIOC                 ((GPIO_t *)GPIOC_BASE)
#define GPIOD                 ((GPIO_t *)GPIOD_BASE)
#define GPIOE                 ((GPIO_t *)GGPIOE_BASE)

/*< base addresses of  EXTI peripherals  */
#define EXTI_BASE             (APB2PERIPH_BASE + 0x3C00UL)

#define EXTI                ((EXTI_t *) EXTI_BASE)

#endif
