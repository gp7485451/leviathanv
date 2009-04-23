#include <kernel.h>

void mem_init()
{
	init_gdt();
	init_frame_alloc();
	
}

//////////////////////Frame Allocation////////////////////
pageframe_t pre_frames[20];
u8int frame_map[1048319];//enough frames for 1mb mark to 4gb
static u32int npages;//number of pages available
pageframe_t startframe;
extern mboot_info_t *mem_info;
extern u32int endkernel;

pageframe_t kalloc_frame_int()
{
	u32int i = 0;
	while(frame_map[i] != FREE)
	{
		i++;
		if(i == npages)
		{
			return(ERROR);
		}
	}
	frame_map[i] = USED;
	return(startframe + (i*0x1000));
}

pageframe_t kalloc_frame()
{

}

void init_frame_alloc()
{
	kprint("Memory Available: \0");
	print_int(mem_info->mem_high);
	kprint("\n");
	u32int num_pages = (mem_info->mem_high/4);//get number of available pages from 1mb mark
	num_pages = (num_pages-(((u32int)&endkernel)/0x1000))-2;
	npages = num_pages;
	u32int start_frame = ((((u32int)&endkernel/0x1000)*0x1000)+0x1000);
	startframe = start_frame;


	for(u32int i = num_pages; i<1048319; i++)//Mark Memory that is not available
	{
		frame_map[i] = DEAD_FRAME;
	}

	for(u32int i = 0; i<num_pages; i++)//Mark all pages as free
	{
		frame_map[i] = FREE;
	}
}


///////////////////GDT///////////////////////////////////////
void gdt_flush(u32int);

gdt_entry_t gdt_entries[5];
gdt_ptr_t   gdt_ptr;

void init_gdt()
{
   kprint("GDT INIT...\0");
   gdt_ptr.limit = (sizeof(gdt_entry_t) * 5) - 1;
   gdt_ptr.base  = (u32int)&gdt_entries;

   gdt_set_gate(0, 0, 0, 0, 0);                // Null segment
   gdt_set_gate(1, 0, 0xFFFFFFFF, 0x9A, 0xCF); // Code segment
   gdt_set_gate(2, 0, 0xFFFFFFFF, 0x92, 0xCF); // Data segment
   gdt_set_gate(3, 0, 0xFFFFFFFF, 0xFA, 0xCF); // User mode code segment
   gdt_set_gate(4, 0, 0xFFFFFFFF, 0xF2, 0xCF); // User mode data segment

   gdt_flush((u32int)&gdt_ptr);
   kprint("DONE\n\0");
}

// Set the value of one GDT entry.
void gdt_set_gate(s32int num, u32int base, u32int limit, u8int access, u8int gran)
{
   gdt_entries[num].base_low    = (base & 0xFFFF);
   gdt_entries[num].base_middle = (base >> 16) & 0xFF;
   gdt_entries[num].base_high   = (base >> 24) & 0xFF;

   gdt_entries[num].limit_low   = (limit & 0xFFFF);
   gdt_entries[num].granularity = (limit >> 16) & 0x0F;

   gdt_entries[num].granularity |= gran & 0xF0;
   gdt_entries[num].access      = access;
} 
////////////////////////////////////////////////////////////////////////////
void memcpy(u8int *dest, u8int *src, u32int count)
{
	for(u32int i = 0; i< count; i++)
	{
		*dest = *src;
		dest++;
		src++;
	}
}



