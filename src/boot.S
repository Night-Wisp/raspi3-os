#include "mm.h" // include a file with address definitions

// put boot code in the .text.boot section, placed at the beginning of the kernel by the linker
.section ".text.boot"

// define _start as global address to allow access from linker
.globl _start

// entry point
_start:               // see https://developer.arm.com/documentation/101779/0002/Register-descriptions/AArch64-system-registers/MPIDR-EL1--Multiprocessor-Affinity-Register--EL1?lang=en
  mrs x0, mpidr_el1   // move the value in mpidr_el1 (processor ID) to reg x0 for comparison
  and x0, x0,#0xFF    // check processor ID (lowest 8 bits) for 0
  cbz x0, master      // hang for non-primary cores (non-zero processor ID)
  b   proc_hang

proc_hang:
  b proc_hang // finish with an infinite loop, to prevent execution of memory

master:
  adr x0, bss_begin   // load x0 with .bss section beginning address
  adr x1, bss_end     // load x1 with .bss section ending address
  sub x1, x1, x0      // set x1 to .bss section size (bss_end - bss_begin)
  bl  memzero         // call function memzero with x0 and x1 as arguments to clean the .bss section (in ARMv8, x0-x6 are the first seven arguments of a function)
  
  mov sp, #LOW_MEMORY   // set sp (stack pointer) to the address in LOW_MEMORY
  bl  kernel_main       // begin the kernel_main function from C
  b proc_hang           // kernel main returned, which it shouldn't, so stop this core
