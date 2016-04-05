Copyright (C) 2009 Kristian Hart
# Introduction #

I believe that for operating systems to **truly** improve in this period in time,
there needs to be a new operating system created, that is not bloated and can be expanded upon easily. Adding new **Features** inside the kernel just adds more bugs. The only thing the kernel really needs to do is manage how software interacts with the hardware, nothing else.

# Kernel #

Leviathan achieves a lack of bloat through a Microkernel. This way if a feature is wanted it can be added in user land. This way the kernel is small and manageable, while being very extensible.

## Design Doc Sections ##
  * [RWFS Design](http://code.google.com/p/leviathanv/wiki/RWFS)
  * [General System Calls](http://code.google.com/p/leviathanv/wiki/GeneralSysCalls)
  * [Application System Calls](http://code.google.com/p/leviathanv/wiki/ApplicationSystemCalls)
  * [Device System](http://code.google.com/p/leviathanv/wiki/DeviceSystem)
  * [Memory Management](http://code.google.com/p/leviathanv/wiki/MemoryMangement)
# Intended OS Features #

**Planned For Version 1.0.0**

---

  * RWFS File System Server - 500 million exabytes of possible storage!
  * Virtual File System - many filesystems can be read
  * Virtual Disk System - allows for multiple disks to be treated as one
  * Complete Device Driver Interface
  * Preemptive Multitasking
  * Flat Executables
  * LEL Executables (Leviathan Executable Linkable)

**Planned For Version 1.5.0**

---

  * GUI
  * Assembler
  * Text Editor