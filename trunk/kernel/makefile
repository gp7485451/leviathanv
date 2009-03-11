CC = gcc
AS = as
LD = ld
CFLAGS = -c -m32 -B /home/kristian/leviathanv/kernel -Wall -nostdlib -nostartfiles -nostdinc -fno-stack-protector -std=gnu99
CSOURCES = *.c
OBJFILES = startk.so *.o
ASFLAGS = --32
LDFLAGS = -m elf_i386 -T linker.ld

all: kernel install clean

kernel:
	$(CC) $(CFLAGS) $(CSOURCES)
	$(AS) $(ASFLAGS) startk.s -o startk.so
	$(LD) $(LDFLAGS) $(OBJFILES) -o kernel

install: kernel
	sudo cp kernel /Leviathan


clean:
	rm *.o *.so kernel
	rm *~ include/*~
	
