__inline__ void outb(unsigned short port, unsigned char val);//write byte to port
__inline__ unsigned char inb(unsigned short port);//read byte to port port
void cli();//clear ints
void sti();//set ints
void hlt();//halt the cpu
unsigned int read_cr0();//read the value in cr0
void write_cr0(unsigned int cr0);//write a value into cr0
unsigned int read_cr3();//read cr3
void write_cr3(unsigned int cr3);//write a value int cr3
