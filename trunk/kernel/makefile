CC = g++
AS = nasm
LD = ld
SOURCEDIR = /home/kristian/Desktop/Leviathan/kernel
CFLAGS = -nostartfiles -nostdinc -fno-stack-protector -c -B $(SOURCEDIR) -m64 -fno-exceptions -fno-rtti -nostdlib -nodefaultlibs
LDFLAGS = -m elf_x86_64 -T linker.ld

CSOURCES = kmain.cpp
ASOURCES = loader.asm
OBJSOURCES = loader.o kmain.o

all: build clean

build:
	$(CC) $(CFLAGS) $(CSOURCES)
	$(AS) -f elf64 $(ASOURCES)
	$(LD) $(LDFLAGS) $(OBJSOURCES) -o kernel 

clean:
	rm *.o 
	rm *~
