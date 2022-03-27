// This is the head file for the functions of user register and login
#ifndef USER_MANAGEMENT_GUARD__H 
#define USER_MANAGEMENT_GUARD__H

#include <stdio.h>
#include"book_management.h"

typedef struct _User {//data stucture of registed users
    unsigned int id; //user ID
    char *name;//real name
    char *username;//username
    char *password;//password
    struct _User *next; //pointer to the next user element
    BookList *borrowed;//pointer to a new list of books thtat the suser borrowed
}User;

typedef struct _Librarian{//data stucture of registed users
    User *UserList;//pointer to the user list
    unsigned int users; // number of elements in the (user*) List    
}Librarian;

typedef struct _ShowList{//used in return books
    unsigned int userid;//to store which user borrowed this book
    Book* loan;//to store the book information
}ShowList;


int user_regist(FILE *userfile);//the function for users to register
//returns 0 if success, else return 1

FILE *userfile;//file pointer for the user(librarian file)
Librarian *admin;//craet the librarian account

int set_librarian(User *admin,FILE *userfile);//set the librarian account
int load_userfile(FILE *userfile);//load the fixed user file
void login(FILE *userfile);//the login function


int borrow_book(User *borrowuser,FILE *loan);//funtion for users to borrow a book
//returns 0 if the borrow is successful, 1 otherwias

int return_book(User *returnuser,FILE *loan);//funtion for users to return a book
//returns 0 if the borrow is successful, 1 otherwias

FILE *loan;//the file used to record user loans
ShowList *show;//the booklist struct used to show the user all the loan books he/she has
User *LoginCheck;//the user data when a user is logged in
#endif