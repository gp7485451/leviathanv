struct tss_struc
{
unsigned short PTL,R0;
unsigned int ESP0;
unsigned short SS0,R1;
unsigned int ESP1;
unsigned short SS1,R2;
unsigned int ESP2;
unsigned short SS3,R3;
unsigned int CR3,EIP,EFLAGS,EAX,ECX,EDX,EBX,ESP,EBP,ESI,EDI;
unsigned short ES,R4,CS,R5,SS,R6,DS,R7,FS,R8,GS,R9,LDTS,R10,R11,IO_MAP_BASE_ADDR;
}__attribute__((packed));
