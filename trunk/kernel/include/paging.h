typedef u32int* pagedir_t;//page directory type
typedef u32int* pagetable_t;//page table type

typedef struct
{
}virtualaddress_t;//used to get the three parts of a 32 bit virtual address

void paging_init();//init paging
