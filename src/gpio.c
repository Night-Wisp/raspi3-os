#include "utils.h"
#include "peripherals/gpio.h"
//#include "gpio.h"

void init_gpio ( unsigned char pin , unsigned char func_sel ) {
  unsigned long long selector_address;
  switch(pin) { // find the proper GPIO function select address
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
      selector_address = GPFSEL0;
      break;
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
    case 16:
    case 17:
    case 18:
    case 19:
      selector_address = GPFSEL1;
      break;
    case 20:
    case 21:
    case 22:
    case 23:
    case 24:
    case 25:
    case 26:
    case 27:
    case 28:
    case 29:
      selector_address = GPFSEL2;
      break;
    case 30:
    case 31:
    case 32:
    case 33:
    case 34:
    case 35:
    case 36:
    case 37:
    case 38:
    case 39:
      selector_address = GPFSEL3;
      break;
    case 40:
    case 41:
    case 42:
    case 43:
    case 44:
    case 45:
    case 46:
    case 47:
    case 48:
    case 49:
      selector_address = GPFSEL4;
      break;
    case 50:
    case 51:
    case 52:
    case 53:
      selector_address = GPFSEL5;
      break;
    default:
      return;
  }
  unsigned int selector = get32(selector_address); // load this variable with current GPIO settings
  unsigned char pin_id = pin % 10; // set pin between 0-9 for function location in it's bank
  pin_id = pin_id * 3; // multiply pin_id by 3 to find the shift left value for the masked func_sel value
  selector &= ~(0b111<<pin_id); // clear out old pin function data
  selector |= (func_sel&0b111)<<pin_id; // set new pin function
  put32(selector_address, selector); // update GPIO memory to allow for new pin function
}

unsigned char read_gpio ( unsigned char pin ) {
  unsigned char pin_id = 0b1<<(pin % 32);
  if (pin >= 0 && pin < 32) {
    return (get32(GPLEV0) & pin_id) >> pin_id;
  } else if (pin >= 32 && pin < 54) {
    return (get32(GPLEV1) & pin_id) >> pin_id;
  } else {
    return 0;
  }
}

void write_gpio ( unsigned char pin , unsigned char value ) {
  unsigned char pin_id = 0b1<<(pin % 32);
  if (value == 0) {
    if (pin >= 0 && pin < 32) {
      put32(GPSET0, pin_id);
    } else if (pin >= 32 && pin < 54) {
      put32(GPSET1, pin_id);
    } else {
      return;
    }
  } else {
    if (pin >= 0 && pin < 32) {
      put32(GPCLR0, pin_id);
    } else if (pin >= 32 && pin < 54) {
      put32(GPCLR1, pin_id);
    } else {
      return;
    }
  }
}
