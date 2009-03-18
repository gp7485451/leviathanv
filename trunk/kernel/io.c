#include <io.h>

__inline__ void outb(unsigned short port, unsigned char val)
{
   asm volatile("outb %0,%1"::"a"(val), "Nd" (port));
}

__inline__ unsigned char inb(unsigned short port)
{
   unsigned char ret;
   asm volatile ("inb %1,%0":"=a"(ret):"Nd"(port));
   return ret;
}

void cli()//clear interrupt flag
{
asm volatile("cli");
}

void sti()//set interrupt flag
{
asm volatile("sti");
}

unsigned int read_cr0()//read the value in cr0
{
unsigned int ret;
asm volatile ("mov %%cr0,%%eax":"=a"(ret));
return ret;
}

void write_cr0(unsigned int cr0)//write a value into cr0
{
asm volatile ("mov %%eax,%%cr0": : "a"(cr0));
}

unsigned int read_cr3()
{
unsigned int ret;
asm volatile ("mov %%cr3,%%eax":"=a" (ret));
return ret;
}

void write_cr3(unsigned int cr3)
{
asm volatile ("mov %%eax,%%cr3": : "a"(cr3));
}

void hlt()
{
asm volatile ("hlt");
}

unsigned int read_cr2()
{
unsigned int ret;
asm volatile ("mov %%cr2,%%eax":"=a" (ret));
return ret;
}

void write_cr2(unsigned int cr2)
{
asm volatile ("mov %%eax,%%cr2": : "a"(cr2));
}

unsigned int read_cr4()
{
unsigned int ret;
asm volatile ("mov %%cr4,%%eax":"=a" (ret));
return ret;
}

void write_cr4(unsigned int cr4)
{
asm volatile ("mov %%eax,%%cr4": : "a"(cr4));
}

