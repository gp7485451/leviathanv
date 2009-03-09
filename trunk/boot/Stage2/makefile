CFLAGS = -nostdlib -nostartfiles -nodefaultlibs -m32 -c
LDFLAGS = -T linker.ld -m elf_i386 -nostdlib
CC = gcc
AS = as
SOURCES =
ASSOURCES =

all: compile link install clean


compile: $(SOURCES)
	$(CC) $(CFLAGS) $(SOURCES)

assemble: $(ASSOURCES)
	$(AS) $(ASSOURCES) -o loader.o --32

link: compile assemble
	ld $(LDFLAGS) *.o -o stage2

install: link
	sudo cp stage2 /Leviathan/boot

clean: install
	rm *~ *.o