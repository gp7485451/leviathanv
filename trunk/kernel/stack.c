#include <stack.h>

void pushas(SP_T *a,unsigned int val)
{
      SP_T b = *a;
      *b = val;
      *a = b++;//increment the stack pointer
}
unsigned int popas(SP_T *a)
{
      SP_T b = *a;
      b--;
      *a--;
      return(*b);
}