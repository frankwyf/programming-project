library:main.c
	gcc -c -O3 load.c
	gcc -o load load.o
all:library


clean:
	rm -f library *.o
