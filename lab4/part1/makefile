compare: compare.o hsvmhr.o
	gcc -m32 -o compare compare.o hsvmhr.o
compares: comparesample.o hsvmhr.o
	gcc -m32 -o compares comparesample.o hsvmhr.o
comparesample.o: comparesample.c
	gcc -m32 -c -o comparesample.o comparesample.c
compare.o: compare.c
	gcc -m32 -c -o compare.o compare.c
%.o: %.asm
	nasm -g -f elf -o $@ $<