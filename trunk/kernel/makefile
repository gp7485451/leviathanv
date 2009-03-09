CFLAGS = -nostdlib -nostartfiles -nodefaultlibs -m64 -c
LDFLAGS = -T linker.ld -m elf_x86_64 -nostdlib
OBJFILES = kernel.o loader.o textmode.o
CSOURCES = kernel.c textmode.c
ASSOURCES = loader.s

all: compile_c compile_as link cleanF install cleanS

compile_c: $(CSOURCES)
	gcc $(CFLAGS) $(CSOURCES)

compile_as: $(ASSOURCES)
	as $(ASSOURCES) -o loader.o --64

link: $(OBJFILES)
	ld $(LDFLAGS) $(OBJFILES) -o kernel

cleanF: kernel
	sudo rm *~ *.o

install: kernel
	sudo cp kernel /Leviathan

cleanS: /Leviathan/kernel
	sudo rm kernel