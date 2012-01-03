section	.text
	global puts
	
	extern length
puts:
  push ebp
  mov ebp, esp
  push dword [esp + 8]
  call	length
  mov	edx,eax
  add	esp,4
  mov dword ecx,[esp + 8]
  mov	ebx,1
  mov	eax,4
  int	0x80
  pop	ebp
  ret




