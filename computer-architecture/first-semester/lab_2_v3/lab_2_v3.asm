DOSSEG
      .MODEL TINY                         
      .STACK 100h
      .DATA
A DB 155,11,22,33,44,55,66,125,88,101
B DB 10 DUP(0)
        .CODE
        START:

        mov ax, @data
        mov ds, ax 
        mov es, ax
        
        cld; 
        lea si, A; 
        lea di, B; 
        mov cx, 10
        rep movsb; 
        
        mov cx, 10; 
        mov bx, 10; 
        lea si, B

metka:  mov ax, [si] 
        mov ah, 00h
        mov di, 0

m1:     mov dx, 0
        div bx
        push dx
        inc di
        cmp ax, 0
        jnz m1


m2:     pop dx
        dec di
        add dx, 30h
        mov ah, 2 
        int 21h
        cmp di, 0 
        jnz m2
        
        mov dx, 20h
        mov ah, 2
        int 21h

        inc si
        loop metka

        mov ah, 4ch 
        int 21h                                                 
END START