section	.text
  global open

open:
  push ebp
  mov ebp, esp
  mov	ebx,[esp + 8]
  mov	ecx,384
  mov	eax,5
  int	0x80
  pop	ebp
  ret
