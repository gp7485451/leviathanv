#include <io.h>
#include <textmode.h>
#include <paging.h>
#include <multiboot.h>
#include <types.h>
#include <stack.h>

extern MB_INFO_S* GMB_INFO;
PDE_T* PD = (PDE_T*) PAGEDIR_ADDR;//pointer used to manipulate the page dir
unsigned int num_pages;//number of pages in free memory

SP_T freef_s = (SP_T)0x7C00;//free frame stack
SP_T usedf_s;//used frame stack

unsigned int get_tmem()
{
return((GMB_INFO->mem_low + GMB_INFO->mem_high));//return total memory
}
///////////////////////////////////////////////////////////////////////

void mem_init()
{
	num_pages = ((GMB_INFO->mem_high - FREE_MEMS)/0x1000);

}
/////////////////////////////////////////////////////////////////

void* kalloc_frame()//allocates a single page frame for use
{

}

//////////////////////////////////////////////////////////////////////

unsigned char kfree_frame(void* f)//frees a single page frame
{

}

///////////////////////////////////////////////////////////////////////
