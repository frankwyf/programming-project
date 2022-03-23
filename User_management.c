#include"User_management.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
Librarian *admin;

static void setlibrarian(Librarian *admin){//set an account for the librarian 
    admin->librarian_name="Admin";
    admin->librarian_password="Admin123";
}

int user_regist(FILE *userfile){//fucntion for user register
    
}