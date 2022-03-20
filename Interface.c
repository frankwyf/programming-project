#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
void main() {

	int choice = 5; //exit

	do {
		char * answer = user_input("\nPlease choose an option:\n1) Register an account\n2) Login \n3) Search for books\n4) Display all books\n5) Quit\nOption: ");
		choice = atoi(answer);
		free(answer);

		switch (choice) {
			case 1:
				printf("ok1");
				break;
			case 2:
				printf("ok2");
				break;
			case 3:
				printf("ok3");
				break;
			case 4:
				printf("ok4");
				break;
			case 5:
				printf("goodbye");
				break;
			default:
				printf("Sorry, that doesn't seem to be an option\n");
		}
	} while (choice != 5);

	return;
}
