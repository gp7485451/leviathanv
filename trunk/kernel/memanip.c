
#define NULL (void*)0

unsigned char *memcpy(unsigned char *dest, const unsigned char *src, int count)
{
for(int i = 0;i<count;i++)
{
*dest = *src;
dest++;
src++;
}
return (dest);
}


