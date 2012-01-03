%.o: %.asm
	nasm -g -f elf -o $@ $<

%.o: %.c
	gcc -m32 -g -nostdlib -fno-stack-protector -c -o $@ $<

.PHONY: clean all

all: bcmpasm

bcmpasm: start.o open.o readChar.o close.o puts.o length.o bcmpasm.o
	ld -melf_i386 -g -o $@ $^

length.o:length.c
puts.o: puts.asm
start.o: start.asm
open.o:open.asm
readChar.o:readChar.asm
close.o:close.asm
bcmpasm.o:bcmpasm.c

clean:
	rm *.o bcmpasm
