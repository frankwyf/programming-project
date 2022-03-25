#include"interface.h"
#include"user_management.h"
#include"book_management.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CreateNode(p) p=(Book *)malloc(sizeof(Book));
#define Booklist(p) p=(BookList *)malloc(sizeof(BookList));
#define DeleteNode(p) free((void *)p);



static void print_all_books(BookList *lpointer){
	printf("ID");
	printf("%*s",6," ");
	printf("Title");
	printf("%*s",35," ");
	printf("Author");
	printf("%*s",18," ");
	printf("Year");
	printf("%*s",12," ");
	printf("Copies\n");
	Book *print;
	print=lpointer->list->next;
	while(print!=NULL){
			printf("%-2i\t%-39s\t%-22s\t%-8i\t%i\n",print->id,print->title,print->authors,print->year,print->copies);
		print=print->next;
	}
}


static char *user_input(const char *input) {

	printf("%s",input);//print the interface choices 1,2,3...

	const int size_step = 2;
	char *answer = malloc(size_step);// memory allocation for user input
	answer[0] = 0; //now it's a string of length 0.

	//read until a new line in blocks of size_step  bytes at at time
	char *next_input = answer;
	int iteration = 0;
	do {
		answer = realloc(answer, size_step + iteration*size_step);
		next_input = answer + strlen(answer); //answer may have moved.
		fgets(next_input, size_step, stdin);

		next_input = answer + strlen(answer); //take the new read into account
		++iteration;
	} while (* (next_input-1) != '\n');

	*(next_input-1) = 0; //truncate the string eliminating the new line.

	return answer;
}

void run_system(){
	file=fopen("books.txt","r");
	if (file==NULL){
        printf("Error1\nPlease contact the librarian for help\n"); 
        exit(-1);
    }
	else{
		if (load_books(file)==0){
		int choice = 5; //exit
	        do {
	            char * answer = user_input("\nPlease choose an option:\n1) Register an account\n2) Login \n3) Search for books\n4) Display all books\n5) Quit\nOption: ");
	            choice = atoi(answer);
	            free(answer);
		        switch (choice) {
		            case 1:
			            user_regist(userfile);
			            break;
			        case 2:
			            printf("login\n librain\n user\n");
			            break;
			        case 3:
			            printf("search requires login\n search by title, author, year\n");
			            break;
			        case 4:
			            print_all_books(lpointer);
			            break;
		            case 5:
			            printf("Thank you for using the library!\nGoodbye!");
			            break;
		            default:
			            printf("Sorry, the option you entered was invalid, please try agian\n");
	            } 
            } while (choice != 5);
	    }
	    else{
		    printf("Failed to load book data!\nPlease try agian.\n");
			exit(-1);
	    }
	}
}
