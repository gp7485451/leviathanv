;Copyright (C) Kristian Hart 2009
;Assemble with FASM
USE16 ;this is all 16 bit code
ORG 0x7C00
jmp begin ;enforce address


begin:
xor ax,ax  ;zero ax
mov sp,stackstart
push ax; set all segments
pop ds
push ax
pop es    ;done setting segments
push ax
pop di ;;;;;;;set for getting drive information
mov BYTE[drive],dl     ; store the boot drive
;;;;;;;;;;;;;;;Load next 3 Sectors To complete stage1;;;;;;;;;;;;;;;;;;
mov ah,0x08
mov dl,BYTE [drive] 
int 0x13        ; get drive parameters
jc FAIL     ;did this faiL?
;else store info for LBA TO CHS
mov BYTE [HPC], dh ;//store heads per cylinder 

mov ax,0 ;; start counter for all the bits

testandset: ; tests and sets all the sector bits in cl
bt cx,ax     ; test bit
jc set       ; is the bit set? if yes set it in SPT
inc ax    ; if no go to next bit and test set
cmp ax,6
je continue ;if we are finished, continue with the rest of  the code
jmp testandset


set:
bts WORD [SPT],ax
inc ax
cmp ax,6
je continue ;if done setting, continue
jmp testandset ;we are not done
;CL = maximum sector number (bits 5-0)


continue: ;here is where the rest of the code comes in
mov si,randstring
call bios_print
hlt ; halt cpu for now

FAIL:
int 0x19 ;reboot


;;;;;;;;;;FUNCTIONS;;;;;;;;;;;;;;
readsector: ;ax = address to read to,   bx = lba, on the stack is an 16 bit number specifying number of sectors to read
push ax ;save address to  read to
mov ax,WORD [SPT]
mov cl,BYTE[HPC]
mul cx ; HPC *SPT
mov dx,ax
mov ax,bx
div dx  ;ax = LBA/ (HPC*SPT) dx = LBA % (HPC * SPT)
mov BYTE [CYL],al ;save  cylinder (dx is now the same as TEMP)
xor bx,bx  ;; bx = 0
mov bl, BYTE [SPT] ; bx = SPT
mov ax,dx
div bx   ; TEMP / SPT
mov BYTE [HEAD],al ; save head
inc dx ; TEMP % SPT +1
mov BYTE [SECTOR],dl
pop ax ; restore ax to read address
mov WORD [BUFFERPOINTER],ax ;save buffer
startread:; HERE IS WEAR WE START THE READ
xor bx,bx
push bx
pop es ; make sure es is 0
mov bx,WORD [BUFFERPOINTER] ;set data buffer for int 13h
mov dl, BYTE [drive]
mov dh, BYTE [HEAD]
mov cl, BYTE [SECTOR]
mov ch, BYTE [CYL]
pop ax ;set number of sectors to read
mov ah,0x02 ; int 0x13 read sector function
cmp BYTE [counter],4
je FAIL ;failed to read sectors
int 0x13
inc BYTE [counter]
jc startread ; try again if failed the first 3 times
ret ;on succeed, return to main code

;CYL = LBA / (HPC * SPT)
;TEMP = LBA % (HPC * SPT)
;HEAD = TEMP / SPT
;SECT = TEMP % SPT + 1


bios_print: ;I was too lazy too actually right this so thanks babystep2...
   lodsb
   or al, al  ;zero=end of str
   jz done    ;get out
   mov ah, 0x0E
   int 0x10
   jmp bios_print
done:
   ret
;;;;;;;;;;;;;;;;;DATA AREA;;;;;;;;;;;;;;;;;;;
stackend:
times 10 dw 0 ; we only need a small stack
stackstart:
counter: db 0
drive: db 0 ;this is where we store the drive we booted from
HPC: db 0     ;heads per cylinder
SPT: dw 0     ;sectors per track

CYL: db 0     ;cylinder to read from
HEAD: db 0 ;HEAD to read from
SECTOR: db 0 ;sector to read  from
BUFFERPOINTER: dw 0; address to read sectors to

randstring: db "I WIN BIZATCHES"
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
times 510-($-$$) db 0 ;;make sure the file is 512 bytes
dw 0xAA55;//magic number tells bios this is bootable