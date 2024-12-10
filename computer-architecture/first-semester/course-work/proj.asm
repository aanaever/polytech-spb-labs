DOSSEG
.MODEL small
.STACK 100h
.DATA

fam dw ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','$'
a db 13,10,'Net ','$'
.CODE
start:
mov  ax, @DATA
mov  ds, ax

lea si, fam

m:
    mov ah, 01h
    int 21h

    mov [si], al
    mov di, si
    add si, 2
    cmp byte ptr [di], ' '

    jne m 

    sub si, 4
    sub di, 4

    cmp byte ptr [si], 'y'
    jne m1 ; переход елсли не равно 

    cmp byte ptr [di], 'i'
    jne m2

    mov byte ptr [di], 'o'
    add di, 2
    mov byte ptr [di], 'g'
    add di, 2
    mov byte ptr [di], 'o'
    jmp n 

m2:
    add si, 2
    mov byte ptr [si], 'a'
    jmp n 

m1:
cmp byte ptr [si], 'a'
jne m3 
jmp n 

m3:
cmp byte ptr [si], 'u'
jne m4
jmp n 

m4: 
cmp byte ptr [si], 'o'
jne m5
jmp n 

m5: 
cmp byte ptr [si], 'e'
jne m6
    jmp n 

m6:
cmp byte ptr [si], 'h'
jne m7 
    jmp n 

m7:
add si, 2
mov byte ptr [si], 'a'

n: 
    mov ah, 9h
    lea dx, a
    int 21h 

    lea si, fam 

mm:
    mov ah, 2h 
    mov dx, [si]
    int 21h 

    add si, 2
    cmp byte ptr [si], ' '
    jne mm 

    mov ah, 4ch
    int 21h
END start     