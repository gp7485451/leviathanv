ORG 0x7C00

jmp 0x00:begin ;enforce address


begin:
xor ax,ax  ;zero ax
mov sp,stackstart







times 10 dw 0 ; we only need a small stack
stackstart: