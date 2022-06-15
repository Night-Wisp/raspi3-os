#ifndef _SEMAPHORE_S_H
#define _SEMAPHORE_S_H

typedef unsigned int SEMAPHORE;

extern void sem_dec ( SEMAPHORE* semaphore, SEMAPHORE* spinlock );
extern void sem_inc ( SEMAPHORE* semaphore, SEMAPHORE* spinlock );

#endif /*_SEMAPHORE_S_H*/
