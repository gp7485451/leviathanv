.global _loader                 # making entry point visible to linker

# setting up the Multiboot header - see GRUB docs for details
.set ALIGN,    1<<0             # align loaded modules on page boundaries
.set MEMINFO,  1<<1             # provide memory map
.set FLAGS,    ALIGN | MEMINFO  # this is the Multiboot 'flag' field
.set MAGIC,    0x1BADB002       # 'magic number' lets bootloader find the header
.set CHECKSUM, -(MAGIC + FLAGS) # checksum required

.align 4
.long MAGIC
.long FLAGS
.long CHECKSUM

# reserve initial kernel stack space
.set STACKSIZE, 0x4000          # that is, 16k.
.comm stack, STACKSIZE, 32      # reserve 16k stack on a quadword boundary

_loader:
   mov   $(stack + STACKSIZE), %esp # set up the stack
   push  %eax                       # Multiboot magic number
   push  %ebx                       # Multiboot data structure

   call  kmain            # call kernel proper
   hlt                    # halt machine should kernel retur

.global gdt_flush
gdt_flush:
lgdt (gp)
mov $0x10,%ax
mov %ax,%ds
mov %ax,%es
mov %ax,%gs
mov %ax,%fs
mov %ax,%ss
mov $0x28,%ax
ltr %ax
ljmp $0x8,$.flush_end
.flush_end:
ret



 

