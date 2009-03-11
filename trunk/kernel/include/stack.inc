    macro setstack [address]
     {
        mov esp,address
     }

kstack: ;Reserve 1kb stack
rb 1024 
