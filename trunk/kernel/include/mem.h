//page frame allocation defines
#define DEAD_FRAME 0xDA
#define FREE 0x00
#define USED 0x01
#define ERROR 0x00


struct gdt_ptr_struct
{
   u16int limit;               // The upper 16 bits of all selector limits.
   u32int base;                // The address of the first gdt_entry_t struct.
}
 __attribute__((packed));
typedef struct gdt_ptr_struct gdt_ptr_t;//yes I took these structures out of jamesm's tut

struct gdt_entry_struct
{
   u16int limit_low;           // The lower 16 bits of the limit.
   u16int base_low;            // The lower 16 bits of the base.
   u8int  base_middle;         // The next 8 bits of the base.
   u8int  access;              // Access flags, determine what ring this segment can be used in.
   u8int  granularity;
   u8int  base_high;           // The last 8 bits of the base.
} __attribute__((packed));
typedef struct gdt_entry_struct gdt_entry_t; 

typedef void* pageframe_t;//pointer to a pageframe

void gdt_set_gate(s32int num, u32int base, u32int limit, u8int access, u8int gran);
void init_gdt();
void mem_init();

void init_frame_alloc();//initialize page frame allocation
static pageframe_t kalloc_frame_int();//returns the address of an allocated page frame
pageframe_t kalloc_frame();//pops off a pre frame
void kfree_frame(pageframe_t a);

void memcpy(u8int *dest, u8int *src, u32int count);//general memory function
