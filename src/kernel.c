#include "mini_uart.h"

// This is the main C function of the kernel
void kernel_main(void) {
  uart_init(); // Initialize the mini uart
  uart_send_string("Hello, world!\r\n"); // The string to send
  
  while (1) {
    uart_send(uart_recv()); // Send any received characters forever
  }
  // If the kernel ever gets here, something has gone horribly wrong. You should probably fix it, but who am I to say it should be fixed?
}
