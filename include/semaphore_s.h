#ifndef _SEMAPHORE_S_H
#define _SEMAPHORE_S_H

typedef unsigned int Semaphore;

extern void sem_dec ( Semaphore* semaphore, Semaphore* spinlock );
extern void sem_inc ( Semaphore* semaphore, Semaphore* spinlock );

#endif /*_SEMAPHORE_S_H*/
