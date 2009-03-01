 
.global loader                 # making entry point visible to linker

# setting up the Multiboot header - see GRUB docs for details
.set KLUDGE, 1<<16
.set ALIGN,    1<<0             # align loaded modules on page boundaries
.set MEMINFO,  1<<1             # provide memory map
.set FLAGS,    ALIGN | MEMINFO | KLUDGE  # this is the Multiboot 'flag' field
.set MAGIC,    0x1BADB002       # 'magic number' lets bootloader find the header
.set CHECKSUM, -(MAGIC + FLAGS) # checksum required

.code32
.align 4
header_addr:
.long MAGIC
.long FLAGS
.long CHECKSUM
.long header_addr
.long 0x00100000
.long 0
.long 0
.long loader

# reserve initial kernel stack space
.set STACKSIZE, 0x4000          # that is, 16k.
.comm stack, STACKSIZE, 32      # reserve 16k stack on a quadword boundary

.code32

loader:
   mov   $(stack + STACKSIZE), %esp # set up the stack
   push  %eax                       # Multiboot magic number
   push  %ebx                       # Multiboot data structure
   mov   $0xB8000,%ecx
   movw   $0x0AB4,(%ecx)		   #test writing a character
   hlt                    # halt machine should kernel retur

#test comment