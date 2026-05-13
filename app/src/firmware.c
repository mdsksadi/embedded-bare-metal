/*
Blink the onboard LED
*/

#include <libopencm3/stm32/rcc.h>   // Include the header for Reset and Clock Control
#include <libopencm3/stm32/gpio.h>  // Include the header for General Purpose I/O

/*
 * Setup the Reset and Clock Control
 * I make it static to limit its scope to this file, as it's only used here. And make sure that this is available only in the translation unit where it's defined, which can help prevent naming conflicts and improve encapsulation.
 */
static void rcc_setup(void)
{
    rcc_clock_setup_pll(&rcc_hsi16_configs[RCC_CLOCK_3V3_80MHZ]);   // Set up the clock using the HSI16 oscillator and PLL to achieve 80 MHz system clock
}

static void gpio_setup(void)
{
    gpio_mode_setup(GPIOB, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, GPIO0);  // Configure GPIO pin B0 as an output with no pull-up or pull-down resistors
}

int main(void)
{
    // Create an infinite loop to keep the firmware running
    while (1)
    {
        
    }
    
    // Never return from main in an embedded firmware application, but we include this to satisfy the C11 standard
    return 0;
}