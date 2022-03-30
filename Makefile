library:main.c 
	gcc -c -O3 main.c interface.c management.c book_management.c user_management.c
	gcc -o library main.o interface.o book_management.o user_management.o management.o
all:library


clean:
	rm -f library *.o
