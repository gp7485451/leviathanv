# Introduction #

Most microkernels take a heavy performance hit,because of the way they handle device I/O. All device drivers are separate processes that manage devices. Leviathan improves the performance of the system by only loading and running servers when requested by a process. After all processes release the device, it can be unloaded until the next request. Leviathan sees all devices as objects that can be accessed. Communication goes back and forth between processes and servers to manage the system.

---

## Servers ##

Like most microkernels servers go through the kernel to manage specific devices. Servers use the server class interrupts for this. Here are the server specific functions:

  * [Server](http://code.google.com/p/leviathanv/wiki/ServerSystemCalls)