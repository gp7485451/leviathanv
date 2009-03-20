#include <io.h>
#include <textmode.h>
#include <paging.h>
#include <multiboot.h>
#include <types.h>

extern MB_INFO_S* GMB_INFO;
PDE_T* PD = (PDE_T*) PAGEDIR_ADDR;//pointer used to manipulate the page dir
unsigned int num_pages;//number of pages in free memory
unsigned char PF_MAP[1048575];//page frame byte map

unsigned int get_tmem()
{
return((GMB_INFO->mem_low + GMB_INFO->mem_high));//return total memory
}

void mem_init()
{
	num_pages = ((GMB_INFO->mem_high - FREE_MEMS)/0x1000);

	for(int i = 0; i<(num_pages-1); i++)
	{
		PF_MAP[i] = FREE;//set free memory
	}

	PF_MAP[num_pages] = DEAD;//set start of dead memory
}

void* kalloc_frame()//allocates a single page frame for use
{
	int i = 0;
	while(PF_MAP[i] != FREE && PF_MAP[i] != DEAD)
	{
		i++;
	}

	if(PF_MAP[i] == DEAD)
	{
		return (FALLOC_FAIL);
	}
	PF_MAP[i] = USED;
	return (void*)(FREE_MEMS + (i*0x1000));
}

unsigned char kfree_frame(void* f)//frees a single page frame
{
	if(((unsigned int) f%0x1000)!= 0)
	{
		return (FREEF_FAIL);//failed to free not page aligned
	}

	if(f == FREE_MEMS)
	{
		PF_MAP[0] = FREE;
	}
	
	PF_MAP[(((unsigned int) f - FREE_MEMS)/0x1000)] = FREE;
}


