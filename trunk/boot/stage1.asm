;Copyright (C) Kristian Hart 2009
;Assemble with FASM
USE16 ;this is all 16 bit code
ORG 0x7C00
jmp 0x00:begin ;enforce address


begin:
xor ax,ax  ;zero ax
mov sp,stackstart
push ax; set all segments
pop ds
push ax
pop es    ;done setting segments
mov BYTE[drive],dl     ; store the boot drive




;;;;;;;;;;;;;;;;;DATA AREA;;;;;;;;;;;;;;;;;;;
stackend:
times 10 dw 0 ; we only need a small stack
stackstart:

drive: db 0 ;this is where we store the drive we booted from
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
times 510-($-$$) db 0 ;;make sure the file is 512 bytes
db 0xAA55;//magic number tells bios this is bootable