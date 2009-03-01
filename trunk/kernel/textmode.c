#include "include/types.h"
#include "include/textmode.h"

char *texmem = cast_u8p(0xB8000);
char *cline = cast_u8p(0xB8000);
unsigned char color = 0x07;//white

void kprint(char *s)
{
while(*s != '\0')
{
if(*s == '\n') newline();
if(texmem>= cast_charp(0xB8FFF))clear_screen();
kputc(*s);
s++;
}
}

void kputc(char c)
{

*texmem = c;
texmem++;
*texmem = color;
texmem++;



}

void newline()
{
cline += 0xA0;
texmem = cline;


}

void clear_screen()
{
}


