.globl memzero
memzero:
  str xzr, [x0], #8   // store the value in xzr (the zero register) in the address contained in x0, then increase x0 by #8. This will zero 8 bytes (64 bits) at a time 
  subs x1, x1, #8     // subtract #8 from x1, and store the value back in x1, while setting all flags. This keeps track of the remaining bytes to zero
  b.gt memzero        // repeat with new values if x1 > 0
  ret                 // return from this function on completion
