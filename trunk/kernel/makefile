CC = gcc
AS = nasm
LD = ld
SOURCEDIR = /home/kristian/Desktop/leviathanv/kernel #replace with whatever the kernel directory is
CFLAGS = -nostartfiles -nostdinc -fno-stack-protector -c -B $(SOURCEDIR) -m32 -nostdlib -nodefaultlibs -std=gnu99
LDFLAGS = -m elf_i386 -T linker.ld

CSOURCES = kmain.c "video/textmode.c" mem.c paging.c
ASOURCES = loader.asm
OBJSOURCES = loader.o kmain.o textmode.o mem.o paging.o

all: build install clean

build:
	$(CC) $(CFLAGS) $(CSOURCES)
	$(AS) -f elf32 $(ASOURCES)
	$(LD) $(LDFLAGS) $(OBJSOURCES) -o kernel 

install:
	sudo cp kernel /Leviathan/kernel

clean:
	rm *.o 
	rm *~
