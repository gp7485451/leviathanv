#define PAGEDIR_ADDR 0x200000      //default address of page directory.
#define PAGET_END  0x401000         //page table end
#define FREE_MEMS  0x402000        //start of free memory
#define N_PDES 1023                   //number of pagetable and directory entries
#define N_PTES 1023
#define FALLOC_FAIL 0xDEADBEEF
#define FREEF_FAIL 0xBA
//paging defines

#define FREE 0x00
#define USED 0x01
#define DEAD 0xDE     //non existant physical memory
typedef unsigned int PDE_T;//page directory entry type
typedef unsigned int PTE_T;//pagee table entry type



unsigned int get_tmem();//get total amount of available memory in kb
void* kalloc_frame();//allocates a single page frame for use
unsigned char kfree_frame(void* f);//frees a single page frame
void mem_init();//initialize paging physical memory allocation and such



