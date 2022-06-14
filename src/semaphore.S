spinlock_lock:
  ldr w2, #0          // load w2 with the unlocked value
  ldr w3, #1          // load w3 with the locked value
  cas w2, w3, [x1]    // if [x1] is equal to w2 (unlocked), swap [x1] with w3 (locked)
  cmp w2, w3          // if they're equal, this process now owns the lock
  bne spinlock_fail // if locked, loop until it's unlocked
  ret

spinlock_fail:
  ldr w2, [x1]        // load w2 with the current lock state
  cmp w2, #1          // compare the current lock state with the locked state
  beq spinlock_fail // repeat if still locked
  b spinlock_lock        // if unlocked, try to get lock

spinlock_unlock:
  ldr w2, #0    // put the unlocked value in w2
  str w2, [x1]  // store w2 (unlocked) at [x1]
  ret

.globl sem_dec      // see https://developer.arm.com/documentation/dht0008/a/arm-synchronization-primitives/practical-uses/implementing-a-semaphore?lang=en
sem_dec:            // argument 1 is the semaphore pointer, argument 2 is the spinlock pointer
  bl spinlock_lock
  ret
