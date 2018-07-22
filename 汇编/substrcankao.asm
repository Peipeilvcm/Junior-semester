data  	segment
	org	1000h
rlt	db	?			;
pos	dw	?			;匹配位置
mstrptr dw	?			;主串指针
	org	1010h
str	db	20 dup (30h),00h
	org	1100h
mstr	db	100h dup (50h),00h
data  	ends            
code  	segment 'code'
main  	proc  far
	assume cs:code,ds:data
	mov 	ax,data
	mov 	ds,ax
	mov	es,ax
	mov	di,offset str
	mov	si,di
	xor	al,al
	cld
lp1:	scasb
	jz	lp2
	jmp	lp1
lp2:	sub	di,si
	dec	di
	mov	bx,di			;计算子串长度（不含0）放入bx中
	mov	di,offset mstr
	mov	mstrptr,di		;主串指针指向首字符
	mov	cx,di
	xor	al,al
	cld
lp3:	scasb
	jz	lp4
	jmp	lp3
lp4:	sub	di,cx			
	dec	di			;计算出主串长度（不含0）放入di中
	sub	di,bx
	jc	lp7			;主串小于子串，匹配失败
	inc	di			;搜索次数
	mov	dx,di
	cld
lp5:	mov	si,offset str
	mov	di,mstrptr
	mov	cx,bx			;循环次数，子串长度
	repe	cmpsb
	jz	found
	inc	mstrptr			;主串指针指向下一字符
	dec	dx
	jnz	lp5
lp7:	mov	rlt,0
	jmp	lp6
found:	mov	rlt,0ffh
	sub	di,bx			;主串匹配首地址
	sub	di,offset mstr		;0参考的匹配位置
	mov	pos,di
lp6:	mov 	ax,4c00h
	int 	21h
	ret
main  	endp
code  	ends
	end 	main