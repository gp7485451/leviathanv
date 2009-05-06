#include <kernel.h>

mboot_info_t* mem_info;
extern pageframe_t startframe;

void kmain(void* mbd, u32int magic)
{
	clear_screen();
	kprint("Leviathan x86 Copyright(C) 2009 Kristian Hart\n");
	mem_info = mbd;//initialize global multiboot info structure
	mem_init();//initialize physical memory management 
	paging_init();//initialize paging

	
}
