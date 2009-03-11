AS = fasm

all: build install clean

build:
	fasm kernel.asm kernel

install: build
	sudo cp kernel /Leviathan

clean: install
	sudo rm *~
	sudo rm kernel
	sudo rm include/*~
