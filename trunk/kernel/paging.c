#include <io.h>
#include <textmode.h>
#include <paging.h>
#include <multiboot.h>
extern MB_INFO_S* GMB_INFO;

PDE_T* PD = (PDE_T*) PAGEDIR_ADDR;//pointer used to manipulate the page dir


unsigned int get_tmem()
{
return((GMB_INFO->mem_low + GMB_INFO->mem_high));//return total memory
}



