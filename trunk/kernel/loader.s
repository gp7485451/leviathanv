 
.global loader                 # making entry point visible to linker
.extern kmain

#I've decided not to use grub as a bootloader since I'm using my own RWFS filesystem

# reserve initial kernel stack space
.set STACKSIZE, 0x4000          # that is, 16k.
.comm stack, STACKSIZE, 32      # reserve 16k stack on a quadword boundary

.code32

loader:	
	hlt  # do nothing for now



#test comment