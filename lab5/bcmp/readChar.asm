section	.text
	global readChar

readChar:
  push ebp
  mov ebp, esp
  mov	ebx,[esp + 8]
  mov	ecx,[esp + 12]
  mov	word edx,1
  mov	eax,3
  int	0x80
  movzx ecx, cl
  pop ebp
  ret

