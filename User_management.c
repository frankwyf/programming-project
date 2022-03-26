#include"interface.h"
#include"user_management.h"
#include"book_management.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Createuser(p) p=(User *)malloc(sizeof(User));


int load_userfile(FILE *userfile){
    userfile=fopen("user.txt","r+");
    Createuser(admin);
    if (userfile==NULL){
        printf("Failed to load the usee file! Please contact the librarian.\n");
        exit(-1);
    }
    else{
        printf("Welcom to user system!\n");
        return 0;
    }
}

//set an account for the librarian
int load_librarian(User *admin,FILE *userfile){
    userfile=fopen("user.txt","r+");
    Createuser(admin);//set the linked list node of librarain
    char tem[1024];//read in a whole line form the text file
	memset(tem, '\0', 1024);//initialize the temp string
	char *frtn=fgets(tem,sizeof(tem),userfile);
	int i;
	for (i=0;i<=1024;i++){
		if (tem[i]=='\n'){
            tem[i]='\0';
		}
	}//delete the '/n' at the end of the line 
    char *pt=strtok(tem,",");//cut the input string by comma
    int attributes=0;
	while (pt != NULL){
		switch (attributes){
            case 0:
                admin->name=pt;
                int i;
                i=strlen(admin->name);
                admin->name=(char *)malloc(i*sizeof(char));
                strcpy(admin->name,pt);
            case 1:
                admin->username=pt;
                int j;
                j=strlen(admin->username);
                admin->username=(char *)malloc(j*sizeof(char));
                strcpy(admin->username,pt);
            case 2:
                admin->password=pt;
                int k;
                k=strlen(admin->password);
                admin->password=(char *)malloc(k*sizeof(char));
                strcpy(admin->password,pt);
        }//copying data into the data part in the librarian node
        attributes+=1;
		pt=strtok(NULL,",");
    }
    fclose(userfile);
    return 0;
}

//fucntion for user register
int user_regist(FILE *userfile){
    load_librarian(admin,userfile);
    printf("Please enter your name:");
    return 0;
}

void user_login(FILE *userfile){

}
