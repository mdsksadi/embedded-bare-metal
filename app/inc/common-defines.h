#ifndef COMMON_DEFINES_H
#define COMMON_DEFINES_H

#include <stdint.h>
#include <stdbool.h>

/*
 * Board: NUCLEO-L432KC
 * MCU:   STM32L432KC
 *
 * User LED LD3 is connected to Arduino Nano D13,
 * which corresponds to STM32 pin PB3 on Nucleo-32 boards.
 */
#define LED_PORT_RCC_EN_BIT   (1U << 1)   /* GPIOB clock enable bit in RCC_AHB2ENR */
#define LED_PIN               (3U)        /* PB3 */

/* STM32L4 register base addresses used in this beginner example */
#define PERIPH_BASE           (0x40000000UL)
#define AHB2PERIPH_BASE       (PERIPH_BASE + 0x08000000UL)
#define RCC_BASE              (0x40021000UL)
#define GPIOB_BASE            (AHB2PERIPH_BASE + 0x00000400UL)

/* RCC registers */
#define RCC_AHB2ENR           (*(volatile uint32_t *)(RCC_BASE + 0x4CUL))

/* GPIO registers */
#define GPIOB_MODER           (*(volatile uint32_t *)(GPIOB_BASE + 0x00UL))
#define GPIOB_OTYPER          (*(volatile uint32_t *)(GPIOB_BASE + 0x04UL))
#define GPIOB_OSPEEDR         (*(volatile uint32_t *)(GPIOB_BASE + 0x08UL))
#define GPIOB_PUPDR           (*(volatile uint32_t *)(GPIOB_BASE + 0x0CUL))
#define GPIOB_ODR             (*(volatile uint32_t *)(GPIOB_BASE + 0x14UL))

#endif /* COMMON_DEFINES_H */
