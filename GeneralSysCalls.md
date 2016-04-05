# Introduction #
This section intends to explain how system calls are generally implemented in the kernel. There are two classes of system calls in the kernel:
  * [Application](http://code.google.com/p/leviathanv/wiki/ApplicationSystemCalls)
  * [Server](http://code.google.com/p/leviathanv/wiki/ServerSystemCalls)
All calls are done through interrupts, with one class corresponding to a single interrupt.

# Details #
Here are the interrupts that correspond to each class:
  * Application - 0x70
  * Server - 0x72