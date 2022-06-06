.globl put32
put32:
  str w1,[x0]     // put the 32-bit value in w1 at the address in x0
  ret

.globl get32
get32:
  ldr w0,[x0]     // store the 32-bit value at the address in x0 in w0
  ret

.globl delay
delay:
  subs x0,x0,#1   // subtract #1 from x0, and store the result in x0 while setting flags
  bne delay       // if result is = 0, return
  ret
