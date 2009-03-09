CFLAGS = -nostdlib -nostartfiles -nodefaultlibs -m32 -c
LDFLAGS = -T linker.ld -m elf_i386 -nostdlib
CC = gcc
SOURCES =

all: compile link install clean


compile: $(SOURCES)
	$(CC) $(CFLAGS) $(SOURCES)

link:

clean: