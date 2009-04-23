
#include <types.h>
#include <video/textmode.h>
#include <mem.h>

typedef struct//multiboot info structure
{
	u32int flags;
	u32int mem_low;
	u32int mem_high;
}mboot_info_t;


