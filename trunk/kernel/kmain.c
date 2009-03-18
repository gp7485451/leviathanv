#include <textmode.h>
#include <io.h>
#include <memanip.h>
#include <types.h>
#include <gdt.h>
#include <string.h>
#include <task.h>
#include <multiboot.h>


void kmain(MB_INFO_S* mbd, unsigned int magic)
{

clear_screen();
set_color(WHITE);
kprint("\nLeviathan (C) Kristian Hart 2009\n");
kprint("Loading.........\n");
gdt_install();
//let us know how much memory is available
kprint("Upper Memory Amount: ");
print_int(mbd->mem_high);
kprint(" KB\n");

kprint("Paging...\n");

}


