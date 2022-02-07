CODE SEGMENT
    ASSUME cs:CODE;
start:
    mov ax,200h;
    mov ds,ax;
    mov bx,0;
    mov cx,64;
    s:mov [bx],bx
      inc bx;
    loop s; 

    mov ax,4c00h;
    int 21h;
CODE ENDS
END start