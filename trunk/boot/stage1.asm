;Copyright (C) Kristian Hart 2009
;Assemble with FASM
USE16 ;this is all 16 bit code
ORG 0x7C00
jmp 0x00:begin ;enforce address


begin:
mov sp,(0x7c00-1)
xor ax,ax
mov ds,ax
mov es,ax
mov BYTE[drive],dl     ; store the boot drive

mov ah,0x08
mov dl,BYTE [drive]
int 0x13 ; get drive parameters
jc FAIL ;did this faiL?
;else store info for LBA TO CHS
mov BYTE [HPC], dh ;//store heads per cylinder

mov ax,0 ;; start counter for all the bits

testandset: ; tests and sets all the sector bits in cl
bt cx,ax ; test bit
jc set ; is the bit set? if yes set it in SPT
inc ax ; if no go to next bit and test set
test ax,6
je continue ;if we are finished, continue with the rest of the code
jmp testandset


set:
bts WORD [SPT],ax
inc ax
test ax,6
je continue ;if done setting, continue
jmp testandset ;we are not done
;CL = maximum sector number (bits 5-0)

continue:
mov si,randstring
call bios_print
mov ax,SecondPart
mov bx,2
mov cx,1
push cx
call readsector
call SecondPart
hang:
jmp hang
 ; halt cpu for now

FAIL:
mov si,failone
call bios_print
hlt;

;;;;;;;;;;FUNCTIONS;;;;;;;;;;;;;;
readsector: ;ax = address to read to, bx = lba, on the stack is an 16 bit number specifying number of sectors to read TODO:REWRITE
mov WORD [BUFFERPOINTER],ax ; save buffer address
mov ax,bx
div WORD[SPT]
inc dx
mov BYTE [SECTOR],dl ;store sector to read from
mov cl,BYTE [HPC]
div cx
mov BYTE [CYL],dl ;store cylinder
mov BYTE [HEAD],al

mov ah,0x02
pop cx ;get number of sectors to read
mov al,cl
mov ch,BYTE [CYL]
mov cl,BYTE [SECTOR]
mov dh,BYTE [HEAD]
mov dl,BYTE [drive]
mov bx,WORD [BUFFERPOINTER]
int 0x13
jc FAIL

;Sector = (LBA/SectorsPerTrack) Remainder value + 1
;Cylinder = (LBA/SectorsPerTrack)/NumHeads (Take Remainder value)
;Head = (LBA/SectorsPerTrack)/NumHeads (Take quotient value)

bios_print: ;I was too lazy to actually write this so thanks babystep2...
lodsb
or al,al ;zero=end of str
jz done ;get out
mov ah, 0x0E
int 0x10
jmp bios_print
done:
ret
;;;;;;;;;;;;;;;;;DATA AREA;;;;;;;;;;;;;;;;;;;

counter: db 0
drive: db 0 ;this is where we store the drive we booted from
HPC: db 0 ;heads per cylinder
SPT: dw 0 ;sectors per track

CYL: db 0 ;cylinder to read from
HEAD: db 0 ;HEAD to read from
SECTOR: db 0 ;sector to read from
BUFFERPOINTER: dw 0; address to read sectors to

randstring: db 'LOADING STAGE1...',0
failone: db 'FAIL ONE',0
loadedtwo: db 'LOADING STAGE1 COMPLETE'
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
times 510-($-$$) db 0 ;;make sure the file is 512 bytes
dw 0xAA55;magic number tells bios this is bootable
SecondPart:
mov si,loadedtwo
call bios_print
hang2:
jmp hang2

