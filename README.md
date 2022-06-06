# raspi3-os
Loosely based on [this tutorial](https://github.com/bztsrc/raspi3-tutorial) by [bztsrc](https://github.com/bztsrc)
and on [this guide](https://github.com/s-matyukevich/raspberry-pi-os) by [s-matyukevich](https://github.com/s-matyukevich).

### ToDo List
- [ ] Create some basic starter code
  - [x] Start core 0
  - [x] Set the stack pointer
  - [x] Zero some memory
  - [x] Enable UART
  - [ ] Test in an emulator
  - [ ] Test on actual hardware
- [ ] Expand the functionality
  - [ ] Setup all processors
    - [ ] Add exception level functionality
    - [ ] Add some debug functions
    - [ ] Enable interrupts
    - [ ] Allow cores to run any code from scheduler
  - [ ] Enable hardware timer
  - [ ] Enable hardware random
  - [ ] Create process scheduler
  - [ ] Create mutex locks
  - [ ] Allow user processes to run
  - [ ] Allow system calls
  - [ ] Implement virtual memory
  - [ ] Enable complete interrupt handling
  - [ ] Disc Access

### Additional Resources
- [Arm Developer Documentation](https://developer.arm.com/)
- [Peter Cockerell's ARM Assembly Guide](http://www.peter-cockerell.net/aalp/html/ch-3.html)
- [BCM2837 Datasheet](https://www.albany.edu/faculty/dsaha/teach/2018Fall_CEN553/others/BCM2837_datasheet.pdf)
