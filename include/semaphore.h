#ifndef _SEMAPHORE_H
#define _SEMAPHORE_H

#include "semaphore_s.h"

struct Semaphore {
  SEMAPHORE d_semaphore;
  SEMAPHORE d_spinlock;
}

void semaphore_get ( Semaphore* sem );
void semaphore_release ( Semaphore* sem );

#endif /*_SEMAPHORE_H*/
