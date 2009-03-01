//type casting macros 
#define AMD64
#ifdef AMD64
#define cast_uchar(x) ((unsigned char) (x))
#define cast_ucharp(x) ((unsigned char*) (x))
#define cast_char(x) ((char) (x))
#define cast_charp(x) ((char*) (x))
#define cast_ushort(x) ((unsigned short) (x))
#define cast_ushortp(x) ((unsigned short*) (x))
#define cast_short(x) ((short) (x))
#define cast_shortp(x) ((short*) (x))
#define cast_uint(x) ((unsigned int) (x))
#define cast_uintp(x) ((unsigned int*) (x))
#define cast_int(x) ((int) (x))
#define cast_intp(x) ((int*) (x))
#define cast_voidp(x) ((void*) (x))

#define cast_u8(x) ((unsigned char) (x))
#define cast_u8p(x) ((unsigned char*) (x))
#define cast_8(x) ((char) (x))
#define cast_8p(x) ((char*) (x))
#define cast_u16(x) ((unsigned short) (x))
#define cast_u16p(x) ((unsigned short*) (x))
#define cast_16(x) ((short) (x))
#define cast_16p(x) ((short*) (x))
#define cast_u32(x) ((unsigned int) (x))
#define cast_u32p(x) ((unsigned int*) (x))
#define cast_32(x) ((int) (x))
#define cast_32p(x) ((int*) (x))
#define cast_u64(x) ((unsigned long) (x))
#define cast_u64p(x) ((unsigned long*) (x))
#endif


typedef unsigned char u8_t;
typedef unsigned short u16_t;
typedef unsigned int u32_t;
typedef unsigned long u64_t;