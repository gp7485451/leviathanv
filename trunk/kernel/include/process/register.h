//This file defines All Structures for processes gpr and system registers

struct regs
{
	u64int rax,rbx,rcx,rdx,rsi,rbp,rsp,rdi,r8,r9,r10,r11,r12,r13,r14,r15;//all the gpr's for long mode	
} __attribute__((packed));

typedef struct regs regs_t;

