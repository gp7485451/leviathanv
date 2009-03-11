#include <textmode.h>
#include <io.h>
#include <memanip.h>
#include <types.h>
#include <gdt.h>
#include <string.h>
#include <task.h>

void kmain(void* mbd, unsigned int magic)
{
clear_screen();
set_color(WHITE);
kprint("\nLeviathan (C) Kristian Hart 2009\n");
kprint("Loading.........\n");
gdt_install();

}


