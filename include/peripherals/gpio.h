#ifndef _P_GPIO_H
#define _P_GPIO_H

#include "peripherals/base.h"

// all locations are 32-bit unless otherwise specified

#define GPFSEL0       (PBASE+0x00200000)
#define GPFSEL1       (PBASE+0x00200004)  // Required for mini uart
#define GPFSEL2       (PBASE+0x00200008)
#define GPFSEL3       (PBASE+0x0020000C)
#define GPFSEL4       (PBASE+0x00200010)
#define GPFSEL5       (PBASE+0x00200014)
#define GPSET0        (PBASE+0x0020001C)  // Required for mini uart
#define GPSET1        (PBASE+0x00200024)
#define GPCLR0        (PBASE+0x00200028)  // Required for mini uart
#define GPCLR1        (PBASE+0x0020002C)
#define GPLEV0        (PBASE+0x00200034)
#define GPLEV1        (PBASE+0x00200038)
#define GPEDS0        (PBASE+0x00200040)
#define GPEDS1        (PBASE+0x00200044)
#define GPREN0        (PBASE+0x0020004C)
#define GPREN1        (PBASE+0x00200050)
#define GPFEN0        (PBASE+0x00200058)
#define GPFEN1        (PBASE+0x0020005C)
#define GPHEN0        (PBASE+0x00200064)
#define GPHEN1        (PBASE+0x00200068)
#define GPLEN0        (PBASE+0x00200070)
#define GPLEN1        (PBASE+0x00200074)
#define GPAREN0       (PBASE+0x0020007C)
#define GPAREN1       (PBASE+0x00200080)
#define GPAFEN0       (PBASE+0x00200088)
#define GPAFEN1       (PBASE+0x0020008C)
#define GPPUD         (PBASE+0x00200094)  // Required for mini uart
#define GPPUDCLK0     (PBASE+0x00200098)  // Required for mini uart
#define GPPUDCLK1     (PBASE+0x0020009C)

#endif /*_P_GPIO_H*/
