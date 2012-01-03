section	.text
  global close

close:
  push ebp
  mov	ebp, esp
  mov	ebx,[esp + 8]
  mov	eax,6
  int	0x80
  pop	ebp
  ret
