
# code details

EXE = ./code/LibrarySystem
SRC= Interface.c book_management.c  User_management.c

# generic build details

CC=      gcc
CFLAGS= -std=c99 -Wall
CLINK= 

# compile to object code

OBJ= $(SRC:.c=.o)

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $<

# build executable: type 'make'

$(EXE): $(OBJ)
	$(CC) $(OBJ) $(CLINK) -o $(EXE) 

# clean up and remove object code and executable: type 'make clean'

clean:
	rm -f $(OBJ) $(EXE)

# dependencies

Interface.o:      main.c library.h libraryStructures.h
book_management.o:   library.c library.h librarian.h user.h utility.h libraryStructures.h
User_management.o: librarian.c librarian.h libraryStructures.h
