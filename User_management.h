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


int user_regist(FILE *userfile);//the function for users to register

FILE *userfile;//file pointer for the user(librarian file)
Librarian *admin;//craet the librarian account

int set_librarian(User *admin,FILE *userfile);//set the librarian account
int load_userfile(FILE *userfile);//load the fixed user file
void login(FILE *userfile);//the login function

#endif