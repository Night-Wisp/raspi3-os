#include "utils.h"
#include "peripherals/mini_uart.h"
#include "peripherals/gpio.h"

void uart_send(char c) {
  while(1) {
    if(get32(AUX_MU_LSR_REG)&0x20) break; // exit loop if the transmit buffer has room for at least one byte
  }
  put32(AUX_MU_IO_REG, c);                // write the character byte to the transmit buffer
}

char uart_recv(void) {
  while(1) {
    if(get32(AUX_MU_LSR_REG)&0x01) break; // exit loop if there is something in the receive buffer
  }
  return (get32(AUX_MU_IO_REG)&0xFF);     // return the first byte in the receive buffer
}

void uart_send_string(char* str) {
  for (int i = 0; str[i] != '\0'; i ++) { // repeat until a null delimiter (\0) is reached in the character buffer
    uart_send((char)str[i]);              // send the current character to the transmit buffer
  }
}

void uart_init(void) {
  unsigned int selector;
  
  selector = get32(GPFSEL1);    // load the selector with the current GPIO pin settings
  selector &= ~(7<<12);         // clean gpio14
  selector |= 2<<12;            // set alt for gpio 14
  selector &= ~(7<<15);         // clean gpio15
  selector |= 2<<15;            // set alt for gpio15
  put32(GPFSEL1, selector);     // return the GPIO settings with the new changes
  
  put32(GPPUD, 0);                  // set pull-up/down resistors to off
  delay(150);
  put32(GPPUDCLK0, (<<14)|(1<<15)); // set pull-up/down resistors on gpio14/15 to the value in GPPUD
  delay(150);
  put32(GPPUDCLK0, 0);              // reset to remove the clock and prevent issues with future pull resistor changes
  
  put32(AUX_ENABLES, 1);        // enable mini uart and it's register access
  put32(AUX_MU_CNTL_REG, 0);    // disable auto flow control and disable receiver and transmitter (for now)
  put32(AUX_MU_IER_REG, 0);     // disable receive and transmit interrupts
  put32(AUX_MU_LCR_REG, 3);     // enable 8-bit mode
  put32(AUX_MU_MCR_REG, 0);     // set RTS line to be always high
  put32(AUX_MU_BAUD_REG, 270);  // set baud rate to 115200. baud rate = system_clock_freq / (8 * (baudrate_reg + 1)). You could also use baudrate_reg = (system_clock_freq / (baud * 8)) - 1
  
  put32(AUX_MU_CNTL_REG, 3);    // finally, enable transmitter and receiver
