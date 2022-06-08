#include "mini_uart.h"
#include "gpio.h"
#include "utils.h"

#define ACT_GPIO 29

// This is the main C function of the kernel
void kernel_main(void) {
  uart_init(); // Initialize the mini uart
  uart_send_string("Hello, world!\r\n");  // The string to send
  init_gpio(ACT_GPIO, GPIO_PIN_OUTPUT)    // Set GPIO pin 29 (ACT LED on pi 3B+) to an output (See https://raspberrypi.stackexchange.com/questions/67431/cant-turn-on-act-led-on-baremetal-pi3)
  
  while (1) {
    uart_send(uart_recv());   // Send any received characters forever
    write_gpio(ACT_GPIO, 1);  // Turn the ACT LED on
    delay(31250000);            // Wait some time, assuming a frequency of 250 Megahertz and two cycles for each number in delay gives a .25s delay
    write_gpio(ACT_GPIO, 0);  // Turn the ACT LED off
  }
  // If the kernel ever gets here, something has gone horribly wrong. You should probably fix it, but who am I to say it should be fixed?
}
