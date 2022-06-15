#include "semaphore.h"

void semaphore_get(Semaphore* sem) {
  sem_dec(&(sem->d_semaphore), &(sem->d_spinlock));
}

void semaphore_release(Semaphore* sem) {
  sem_inc(&(sem->d_semaphore), &(sem->d_spinlock));
}
