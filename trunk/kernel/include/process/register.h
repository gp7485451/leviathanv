//This file defines All Structures for processes gpr and system registers

struct regs
{
	u32int eax,ebx,ecx,edx,edi,esi,esp,ebp;//all the gpr's for long mode	
} __attribute__((packed));

typedef struct regs regs_t;

