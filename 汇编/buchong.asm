data 	  segment
string 	  db 'hello world',00h
substring db 'll',00h
len1      dw 0
len2      dw 0
pos       dw 0
found     db 0
data      ends
stack     segment stack
          dw 100h dup(?)
stack     ends
code      segment
          assume cs:code,ds:data,ss:stack
start:	  mov ax,data
		  mov ds,ax
		  mov ax,stack
		  mov ss,ax
		  lea si,string
		  xor ax,ax
		  sub ax,1
		  sub si,1
leng1:    inc ax
		  inc si
		  mov bl,[si]
		  cmp bl,00h
		  jnz leng1
		  jz  next1
next1: 	  mov [len1],ax
		  lea di,substring
		  xor ax,ax
		  sub ax,1
		  sub di,1
leng2:    inc ax
		  inc di
		  mov bl,[di]
		  cmp bl,00h
		  jnz leng2
		  jz  next2
next2:	  mov dx,[len1]
		  mov [len1],ax
		  sub dx,ax
		  inc dx
		  mov [len2],dx
		  mov cx,dx
		  lea si,string		  
		  lea di,substring
loop2:	  push cx
		  push si
		  mov cx,[len1]
		  dec si
		  dec di
loop1:    inc si
          inc di
		  mov al,[si]
		  mov bl,[di]
		  cmp al,bl
          jnz notz
		  loop loop1
		  jmp stop
notz:	  pop si
		  inc si
		  pop cx
		  loop loop2
		  mov found,00h
		  ;mov dl,'N'
		  ;mov ah,2h
		  ;int 21h
		  mov ax,4c00h
		  int 21h
stop:     pop si
		  inc si
		  mov pos,si
		  mov found,0ffh
		  ;mov al,[pos]
		  ;add al,30h
		  ;mov dl,al
		  ;mov ah,2h
		  ;int 21h
		  mov ax,4c00h
		  int 21h  
code      ends
          end start
		  
		  
