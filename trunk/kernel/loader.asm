global loader           ; making entry point visible to linker
extern kmain            ; kmain is defined elsewhere
extern ebss
extern text_start
extern end_data

; setting up the Multiboot header - see GRUB docs for details
MODULEALIGN equ  1<<0                   ; align loaded modules on page boundaries
MEMINFO     equ  1<<1                   ; provide memory map
FLAGS       equ  MODULEALIGN | MEMINFO ; this is the Multiboot 'flag' field
MAGIC       equ    0x1BADB002           ; 'magic number' lets bootloader find the header
CHECKSUM    equ -(MAGIC + FLAGS)        ; checksum required

section .text
align 4
MultiBootHeader:
   dd MAGIC
   dd FLAGS
   dd CHECKSUM
   dd MultiBootHeader
   dd text_start
   dd end_data
   dd ebss
   dd loader


; reserve initial kernel stack space
STACKSIZE equ 0x4000                  

use32
loader:
   mov esp, stack+STACKSIZE        ; set up the stack
   push eax                           ; pass Multiboot magic number
   push ebx                           ; pass Multiboot info structure
   call kmain
   hlt  


                           ; halt machine should kernel return
[GLOBAL gdt_flush]    ; Allows the C code to call gdt_flush().

gdt_flush:
   mov eax, [esp+4]  ; Get the pointer to the GDT, passed as a parameter.
   lgdt [eax]        ; Load the new GDT pointer

   mov ax, 0x10      ; 0x10 is the offset in the GDT to our data segment
   mov ds, ax        ; Load all data segment selectors
   mov es, ax
   mov fs, ax
   mov gs, ax
   mov ss, ax
   jmp 0x08:.flush   ; 0x08 is the offset to our code segment: Far jump!
.flush:
   ret

section .bss
align 32
stack:
   resb STACKSIZE                     ; reserve 16k stack on a quadword boundary





