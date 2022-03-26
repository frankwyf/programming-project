#include"interface.h"
#include"user_management.h"
#include"book_management.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Createuser(p) p=(User *)malloc(sizeof(User));
#define Createlibrarian(p) p=(Librarian *)malloc(sizeof(Librarian));



//load the users into the linked list
//Librarian also serve as the head node of the user linked list
int load_users(FILE *userfile){
    userfile=fopen("user.txt","r");
    if (userfile==NULL){
        printf("Failed to load the user file! Please contact the librarian.\n");
        exit(-1);
    }
    else{
        printf("Welcom to user system!\n");
        User *p,*last;
        Createlibrarian(admin);//set the linked list node of librarain
        Createuser(admin->UserList);
        last=admin->UserList;
        char tem[1024];//read in a whole line form the text file
	    memset(tem, '\0', 1024);//initialize the temp string
	    char *pt=fgets(tem,sizeof(tem),userfile);
	    int i;
	    for (i=0;i<=1024;i++){
		    if (tem[i]=='\n'){
                tem[i]='\0';
		    }
	    }//delete the '/n' at the end of the line 
	    while (pt != NULL){
            Createuser(p);
            char *data=strtok(tem,",");//cut the input string by comma
            int attributes=0;
            while (data != NULL){
               switch (attributes){//copying data into the data part in a node
                    case 0:
					    p->id=atoi(data);
					    break;
					case 1:
					    p->name=data;
                        int i;
						i=strlen(p->name);
						p->name=(char *)malloc(i*sizeof(char));
						strcpy(p->name,data);
					    break;
					case 2:
					    p->username=data;
                        int k;
						k=strlen(p->username);
						p->username=(char *)malloc(i*sizeof(char));
						strcpy(p->username,data);
					    break;
					case 3:
					    p->password=data;
						int j;
						j=strlen(p->password);
						p->password=(char *)malloc(i*sizeof(char));
						strcpy(p->password,data);
					    break;
				}
				attributes+=1;
				data=strtok(NULL,",");
			}
          	p->next=NULL;
			last->next=p;
			last=p;//iserting a new node into the linked list
		    memset(tem, '\0', 1024);
            pt = fgets(tem,sizeof(tem),userfile);//read in the second line
		    int j;
		    for (j=0;j<=1024;j++){
			    if (tem[j]=='\n'){
				    tem[j]='\0';
			    }
		    }//delete the '/n' at the end of the line
		}
		admin->users=last->id;//the length of the booklist
		fclose(userfile);
		return 0;
	}
}

//funtion used for users to borrow a book
int borrow_book(User *borrowuser){
	printf("Enter the ID of the book you wish to borrow: ");
	int borrow_id;
	scanf("%i",&borrow_id);
	getchar();
	//borrow
	

	printf("\nYou have successfuly borrowed this book!\n");
	printf("\nSorry, you already have a copy of this book on loan!\n");
}

//fucntion for user register
int user_regist(FILE *userfile){
    //load_librarian(admin,userfile);
    printf("Please enter your name:");
    return 0;
}

void login(FILE *userfile){
    if (load_users(userfile)==0){
        printf("Please enter username: ");
        char *username=(char *)malloc(sizeof(char)*50);//the maxium length of a username maybe 50 characters
	    fgets(username,200,stdin);
	    int i=strlen(username);
	    username[i-1]='\0';//get rid of the '\n' at the last of the input
        printf("Please enter password: ");
        char *password=(char *)malloc(sizeof(char)*30);//the maxium length of a password maybe 30 characters
	    fgets(password,200,stdin);
	    int j=strlen(password);
	    password[j-1]='\0';//get rid of the '\n' at the last of the input

        //check whether the user is a normal user or librarian

        User *LoginCheck;
        LoginCheck=admin->UserList->next;
		int success=0;//determin whether a user has successfully logged in or not
        while (LoginCheck!=NULL){
            if (strcmp(LoginCheck->username,username)==0 && strcmp(LoginCheck->password,password)==0 && LoginCheck->id!=1){//the first is the librarian
			    success=1;
                printf("(\nSuccessfully logged in as: %s\n)",LoginCheck->username);
				//interface for normal user
                int choice = 5; //exit
	            do {
	                char * answer = user_input("\nPlease choose an option:\n1) Borrow book \n2) Return book \n3) Search for books\n4) Display all books\n5) Quit\nOption: ");
	                choice = atoi(answer);
	                free(answer);
		            switch (choice) {
		                case 1:
			                borrow_book(LoginCheck);
			                break;
			            case 2:
                            printf("2");
			                //return_book(lpointer);
			                break;
			            case 3:
			                search_for_books(lpointer);
			                break;
			            case 4:
			                print_all_books(lpointer);
			                break;
		                case 5:
			                printf("\nThank you for using the library!\n Loging you out...\n\n");
			                break;
		                default:
			                printf("\nSorry, the option you entered was invalid, please try agian.\n");
	                } 
                } while (choice != 5);
            }
		    if (strcmp(LoginCheck->username,username)==0 && strcmp(LoginCheck->password,password)==0 && LoginCheck->id==1){//librarian log in
			    success=1;
				printf("(\nSuccessfully logged in as Librarian: %s\n)",LoginCheck->username);
				//interface for librarian usage
                int lchoice = 5; //exit
	            do {
	                char * answer = user_input("\nPlease choose an option:\n1) Add book \n2) Remove book \n3) Search for books\n4) Display all books\n5) Quit\nOption: ");
	                lchoice = atoi(answer);
	                free(answer);
		            switch (lchoice) {
		                case 1:
						    printf("l1");
			                //add_book(Addbook);
			                break;
			            case 2:
						    printf("l2");
			                //remove_book(Removebook);
			                break;
			            case 3:
			                search_for_books(lpointer);
			                break;
			            case 4:
			                print_all_books(lpointer);
			                break;
		                case 5:
			                printf("\nThank you for managing the library!\n Loging you out...\n\n");
			                return;
		                default:
			                printf("\nSorry, the option you entered was invalid, please try agian.\n");
	                } 
                } while (lchoice != 5);
		    }
            else{
			    LoginCheck=LoginCheck->next;
		    }
        }
		if (success==0){
			printf("\nSorry, your username or password is invalid, please try again!\n");
			return;
		}
    }
    else{
        printf("\nFailed to laod users.\n EXITING...");
        return;
    }
}
