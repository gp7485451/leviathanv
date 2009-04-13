CC = gcc
AS = nasm
LD = ld
SOURCEDIR = /home/kristian/leviathanv/kernel #replace with whatever the kernel directory is
CFLAGS = -nostartfiles -nostdinc -fno-stack-protector -c -B $(SOURCEDIR) -m64 -nostdlib -nodefaultlibs
LDFLAGS = -m elf_x86_64 -T linker.ld

CSOURCES = kmain.c
ASOURCES = loader.asm
OBJSOURCES = loader.o kmain.o

all: build install clean

build:
	$(CC) $(CFLAGS) $(CSOURCES)
	$(AS) -f elf64 $(ASOURCES)
	$(LD) $(LDFLAGS) $(OBJSOURCES) -o kernel 

install:
	sudo cp kernel /Leviathan/kernel

clean:
	rm *.o 
	rm *~
