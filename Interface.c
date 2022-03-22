#include"Interface.h"
#include"User_management.h"
#include"book_management.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CreateNode(p) p=(Book *)malloc(sizeof(Book));
#define DeleteNode(p) free((void *)p);


FILE *file;
int load_books(FILE *file){
	if (file==NULL){
		printf("File cannot open!\n");
		return -1;
	}
	else{
		Book *h,*p,*last;
		CreateNode(h);//create the head node
		last=h;
		CreateNode(p);
		char temp[1024];
        memset(temp, '\0', 1024);
		while (!feof(file)){
			
		}
		
		return 0;
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

int main(int argc, char **argv) {
	if (argc!=2){
        printf("Error\nExpected use: books.txt\n"); 
        exit(-1);
    }
	else{
		file=fopen(argv[1],"r");
		if (load_books(file)==0){
		int choice = 5; //exit
	        do {
	            char * answer = user_input("\nPlease choose an option:\n1) Register an account\n2) Login \n3) Search for books\n4) Display all books\n5) Quit\nOption: ");
	            choice = atoi(answer);
	            free(answer);
		        switch (choice) {
		            case 1:
			            printf("user register");
			            break;
			        case 2:
			            printf("login\n librain\n user\n");
			            break;
			        case 3:
			            printf("search requires login\n search by title, author, year\n");
			            break;
			        case 4:
			            printf("Dispaly");
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
	
	return 0;
}
