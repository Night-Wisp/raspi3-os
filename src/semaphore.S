spinlock_lock:
  ldr w2, #0          // load w2 with the unlocked value
  ldr w3, #1          // load w3 with the locked value
  cas w2, w3, [x1]    // if [x1] is equal to w2 (unlocked), swap [x1] with w3 (locked)
  cmp w2, w3          // if they're equal, this process now owns the lock
  bne spinlock_fail   // if locked, loop until it's unlocked
  ret

spinlock_fail:
  wfe                 // wait for an event from sev
  ldr w2, [x1]        // load w2 with the current lock state
  cmp w2, #1          // compare the current lock state with the locked state
  beq spinlock_fail   // repeat if still locked
  b spinlock_lock     // if unlocked, try to get lock

spinlock_unlock:
  ldr w2, #0          // put the unlocked value in w2
  str w2, [x1]        // store w2 (unlocked) at [x1]
  sev                 // send an event, allowing waiting processors to attempt access
  ret

.globl sem_dec        // see https://developer.arm.com/documentation/dht0008/a/arm-synchronization-primitives/practical-uses/implementing-a-semaphore?lang=en
sem_dec:              // argument 1 (x0) is the semaphore pointer, argument 2 (x1) is the spinlock pointer
  bl spinlock_lock    // spinlock other processes to minimize trouble
  ldxr w2, [x0]       // load w2 exclusively with the value at [x0]
  cmp w2, #0          // test if semaphore holds the value 0
  beq sem_dec_fail    // if zero, block before retrying
  sub w2, #1          // if not, decrement temporary copy
  stxr w3, w2, [x0]   // attempt to exclusively store w2 at [x0], store result in w3
  cmp w3, #0          // check if stxr succeeded (returned 0)
  bne sem_dec         // if not, start from beginning
  dmb                 // data memory barrier, unsure what it does, but was included in Arm's guide
  bl spinlock_unlock  // unlock other processes
  ret

sem_dec_fail:
  wfe                 // wait for an event
  ldr w2, [x0]        // load the semaphore value into w2
  cmp w2, #0          // test if semaphore holds 0
  beq sem_dec_fail    // if it does, return here
  b sem_dec           // otherwise, try to get the semaphore again

.globl sem_inc
sem_inc:              // argument 1 (x0) is the semaphore pointer, argument 2 (x1) is the spinlock pointer
  bl spinlock_lock    // spinlock other processes to minimize trouble
  ldxr w2, [x0]       // load w2 exclusively with the value at [x0]
  add w2, #1          // increment temporary copy
  stxr w3, w2, [x0]   // attempt to exclusively store w2 at [x0], store result in w3
  cmp w3, #0          // check if stxr succeeded (returned 0)
  bne sem_inc         // it failed, restart from beginning
  dmb                 // data memory barrier, unsure what it does, but was included in Arm's guide
  bl spinlock_unlock  // unlock other processes, at both spinlock_fail and sem_dec_fail
  ret
