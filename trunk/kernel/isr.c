#include <textmode.h>
#include <io.h>

void div_zero()//divide by zero exception handler
{
kprint("ERROR: Divide By 0, CPU HALTED");
hlt();
}

void debug_ex()//debug exception
{
kprint("ERROR: Debug Exception, CPU HALTED");
hlt();
}

void nmi()
{
kprint("ERROR: NMI, CPU HALTED");
hlt();
}

void breakp_ex()
{
kprint("TRAP: BREAKPOINT EXCEPTION, CPU HALTED");
hlt();
}
