#include <string.h>

unsigned int strln(string *s)
{
unsigned int length=0;
while(*s != '\0')
{
s++;
length++;
}
return (length);
}
