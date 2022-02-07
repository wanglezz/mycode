CODE SEGMENT
    ASSUME cs:CODE;
start:
    mov ax,0ffffh;
    mov ds,ax;
    mov cx,12;
    mov bx,0;
    mov dx,0;
    s:add al,[bx]
      mov ah,0
      add dx,ax
      inc bx;
    loop s;

    mov ax,4c00h;
    INT 21h;
CODE ENDS
END start;