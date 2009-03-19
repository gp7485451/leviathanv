#define PAGEDIR_ADDR 0x200000      //default address of page directory.
#define N_PDES 1023                   //number of pagetable and directory entries
#define N_PTES 1023

typedef unsigned int PT_ADDR;//page table address loaded in cr3
typedef unsigned int PDE_T;//page directory entry type
typedef unsigned int PTE_T;//pagee table entry type

unsigned int get_tmem();//get total amount of available memory in kb

