#ifndef MANAGEMENT_GUARD__H 
#define MANAGEMENT_GUARD__H
typedef struct _Loan {
    unsigned int user; //user ID
    unsigned int bookid; //Book ID
	char *title; //book title
	char *authors; //comma separated list of authors
	unsigned int year; // year of publication
	unsigned int copies; //number of copies the library has
	struct _Book *next; //pointer to the next book element
}Loan;

typedef struct _Loanlist {
    Loan *loanlist;//the list of loan informations
    unsigned int total;//the legth of loanlist
}Loanlist;

Loanlist *all;//the linked list use to load all users' borrowed books


#endif