/*
Blink the onboard LED
*/

#include <libopencm3/stm32/rcc.h>   // Include the header for Reset and Clock Control
#include <libopencm3/stm32/gpio.h>  // Include the header for General Purpose I/O
#include <libopencm3/cm3/systick.h>  // Include the header for SysTick timer
#include <libopencm3/cm3/vector.h>   // Include the header for interrupt vector handling

#define LED_PORT    GPIOB  // Define the port for the LED
#define LED_PIN     GPIO0   // Define the pin for the LED

#define CPU_FREQ        80000000  // Define the CPU frequency (80 MHz)
#define SYSTICK_FREQ    1000  // Define the SysTick frequency (1000 Hz, or 1 ms)

volatile uint64_t ticks = 0;  // A volatile variable to keep track of the number of ticks (milliseconds) since the system started 
void sys_tick_handler(void)
{
    ticks++;  // Increment the tick count every time the SysTick interrupt occurs (every 1 ms)
}

/*
* Setup the Reset and Clock Control
* I make it static to limit its scope to this file, as it's only used here. And make sure that this is available only in the translation unit where it's defined, which can help prevent naming conflicts and improve encapsulation.
*/
static void rcc_setup(void)
{
    rcc_clock_setup_pll(&rcc_hsi16_configs[RCC_CLOCK_3V3_80MHZ]);   // Set up the clock using the HSI16 oscillator and PLL to achieve 80 MHz system clock
}

/*
* Setup the GPIO pin for the LED
*/
static void gpio_setup(void)
{
    rcc_periph_clock_enable(RCC_GPIOB);  // Enable the clock for GPIO port B
    gpio_mode_setup(LED_PORT, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, LED_PIN);  // Configure GPIO pin B0 as an output with no pull-up or pull-down resistors
}

/*
* Setup the SysTick timer to generate an interrupt every 1 ms (1000 Hz) based on the system clock. This will allow us to create a delay in the main loop without blocking the CPU.
*/
static void systick_setup(void)
{
    systick_set_frequency(SYSTICK_FREQ, CPU_FREQ);  // Set up the SysTick timer to generate an interrupt every 1 ms (1000 Hz) based on the system clock
    systick_counter_enable();  // Enable the SysTick counter
    systick_interrupt_enable();  // Enable the SysTick interrupt
}

/*
* A simple delay function that creates a delay by executing a loop with no operations (NOPs). The number of cycles determines the length of the delay.
*/
static void delay_cycles(uint32_t cycles)
{
    for (uint32_t i = 0; i < cycles; i++)
    {
        __asm__("nop");  // No Operation: This assembly instruction does nothing and is used to create a delay
    }
}

int main(void)
{

    rcc_setup();   // Call the function to set up the clock
    gpio_setup();  // Call the function to set up the GPIO pin

    // Create an infinite loop to keep the firmware running
    while (1)
    {
        gpio_toggle(LED_PORT, LED_PIN);  // Toggle the state of GPIO pin B0 (turn the LED on or off)
        delay_cycles(84000000/4);  // Call the delay function to create a delay
    }
    
    // Never return from main in an embedded firmware application, but we include this to satisfy the C11 standard
    return 0;
}