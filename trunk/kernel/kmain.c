#include <textmode.h>
#include <io.h>
#include <memanip.h>
#include <types.h>
#include <gdt.h>
#include <idt.h>
#include <string.h>
#include <task.h>
#include <multiboot.h>
#include <paging.h>

MB_INFO_S* GMB_INFO;//global version of mbinfo

void kmain(MB_INFO_S* mbd, unsigned int magic)
{
GMB_INFO = mbd;//make it equal

clear_screen();
set_color(WHITE);
kprint("\nLeviathan (C) Kristian Hart 2009\n");
//let us know how much memory is available
kprint("Total Memory Amount: ");
print_int((mbd->mem_low+mbd->mem_high));
kprint(" KB\n");
kprint("Loading.........\n");
gdt_install();
kprint("Paging...\n");
mem_init();//initialize physical memory
kprint("IDT and ISRs..........\n");
init_idt();
print_hex((unsigned int) kalloc_frame());


}


