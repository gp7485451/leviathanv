struct gdt_ent
{
unsigned short limit_low;
unsigned short base_low;
unsigned char  base_mid;
unsigned char  access;
unsigned char  gran;
unsigned char  base_high;
}__attribute__((packed));

struct gdt_pntr
{
unsigned short limit;
unsigned int base;
}__attribute__((packed));

void gdt_set_gate(int num, unsigned long base, unsigned long limit, unsigned char access, unsigned char gran);
void gdt_install();//install the gdt
void gdt_flush();
