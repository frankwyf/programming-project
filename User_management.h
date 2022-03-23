// This is the head file for the functions of user register and login
#ifndef USER_MANAGEMENT_GUARD__H 
#define USER_MANAGEMENT_GUARD__H

#include <stdio.h>

typedef struct _User {//data stucture of registed users
    char *name;//real name
    char *username;//username
    char *password;//password
}User;

typedef struct _Librarian {//data structure for librarian
    char *librarian_name;
    char *librarian_password;
}Librarian;

int user_regist(FILE *userfile);//the function for users to register

FILE *userfile;

#endif