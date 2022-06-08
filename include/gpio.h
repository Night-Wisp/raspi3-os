#ifndef _GPIO_H
#define _GPIO_H

#define GPIO_PIN_INPUT    0b000
#define GPIO_PIN_OUTPUT   0b001
#define GPIO_PIN_ALT_0    0b100
#define GPIO_PIN_ALT_1    0b101
#define GPIO_PIN_ALT_2    0b110
#define GPIO_PIN_ALT_3    0b111
#define GPIO_PIN_ALT_4    0b011
#define GPIO_PIN_ALT_5    0b010

void init_gpio ( unsigned char pin , unsigned char func_sel );
unsigned char read_gpio ( unsigned char pin );
void write_gpio ( unsigned char pin );

#endif /*_GPIO_H*/
