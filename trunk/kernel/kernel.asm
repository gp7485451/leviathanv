USE32
ORG 0x10000
include 'include/stack.inc'
include 'include/gdt.inc'

kmain:
setstack kstack ; setup the kernel stack

hlt; halt if we even get to this point
 
