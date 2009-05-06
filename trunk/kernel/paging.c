//this file handles virtual memory
#include <kernel.h>

pagedir_t pagedirectory;//self explanatory 

void paging_init()
{
	pagedirectory = kalloc_frame();//allocate a pageframe for a the pagedirectory
}
