#include <kernel.h>

mboot_info_t* mem_info;
extern pageframe_t startframe;

void kmain(void* mbd, u32int magic)
{
	clear_screen();
	kprint("Leviathan x86 Copyright(C) 2009 Kristian Hart\n");
	mem_info = mbd;//initialize global multiboot info structure
	mem_init();
	kalloc_frame();
	kalloc_frame();
	for(u32int i = 0; i<22; i++)
	{
		print_hex((u32int)kalloc_frame());
		kprint("\n");
	}

	
}
