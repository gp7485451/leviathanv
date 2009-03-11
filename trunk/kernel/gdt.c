#include <gdt.h>
#include <types.h>
#include <tss.h>
#include <textmode.h>
struct gdt_ent gdt[5];
struct gdt_pntr gp;
struct tss_struc ktss;

void gdt_install()
{
   kprint("Installing GDT    ");
   gdt_set_gate(0, 0, 0, 0, 0);                // Null segment
   gdt_set_gate(1, 0, 0xFFFFFFFF, 0x9A, 0xCF); // Code segment
   gdt_set_gate(2, 0, 0xFFFFFFFF, 0x92, 0xCF); // Data segment
   gdt_set_gate(3, 0, 0xFFFFFFFF, 0xFA, 0xCF); // User mode code segment
   gdt_set_gate(4, 0, 0xFFFFFFFF, 0xF2, 0xCF); // User mode data segment
   gdt_set_gate(5, cast_uint(&ktss),sizeof(struct tss_struc), 0x89, 0xCF);	/* TSS */
   gp.limit = (sizeof(struct gdt_ent) * 6) - 1;
   gp.base = cast_uint(&gdt);
   gdt_flush();
   kprint("DONE\n");
}

void gdt_set_gate(int num, unsigned long base, unsigned long limit, unsigned char access, unsigned char gran)
{
    /* Setup the descriptor base address */
    gdt[num].base_low = (base & 0xFFFF);
    gdt[num].base_mid = (base >> 16) & 0xFF;
    gdt[num].base_high = (base >> 24) & 0xFF;

    /* Setup the descriptor limits */
    gdt[num].limit_low = (limit & 0xFFFF);
    gdt[num].gran = ((limit >> 16) & 0x0F);

    /* Finally, set up the granularity and access flags */
    gdt[num].gran |= (gran & 0xF0);
    gdt[num].access = access;
}
