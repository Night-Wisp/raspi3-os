#ifndef _GPIO_H
#define _GPIO_H

void init_gpio ( unsigned char pin , unsigned char func_sel );
unsigned char read_gpio ( unsigned char pin );
void write_gpio ( unsigned char pin );

#endif /*_GPIO_H*/
