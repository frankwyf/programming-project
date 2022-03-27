#include"interface.h"
#include"user_management.h"
#include"book_management.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define CreateNode(p) p=(Book *)malloc(sizeof(Book));
#define Booklist(p) p=(BookList *)malloc(sizeof(BookList));
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
        printf("\nWelcom to user system!\n\n");
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
//function to load the loan file
int load_loan(FILE *file, BookList *show){
	loan=fopen("loan.txt","r");
	if (loan==NULL){
		printf("Loan file cannot open!\n");
		return -1;
	}
	else{
		Book *p,*last;
		Booklist(show);//creat the header node
		CreateNode(show->list);
		last=show->list;
		char try[1024];//read in a whole line form the text file
		memset(try, '\0', 1024);//initialize the temp string
		char *f=fgets(try,sizeof(try),loan);
		int i;
		for (i=0;i<=1024;i++){
			if (try[i]=='\n'){
				try[i]='\0';
			}
		}//delete the '/n' at the end of the line
		while (f != NULL){//read file till the end (an empty line)
		    CreateNode(p);//create the first real node
			char *t=strtok(try,",");//cut the input string by comma
			int row=0;
			while (t != NULL){
				switch (row){//copying data into the data part in a node
					case 0:
					    break;
					case 1:
					    p->id=atoi(t);
					    break;
					case 2:
					    p->title=t;
						int i;
						i=strlen(p->title);
						p->title=(char *)malloc(i*sizeof(char));
						strcpy(p->title,t);
					    break;
					case 3:
					    p->authors=t;
						int j;
						j=strlen(p->authors);
						p->authors=(char *)malloc(i*sizeof(char));
						strcpy(p->authors,t);
					    break;
					case 4:
					    p->year=atoi(t);
					    break;
					case 5:
					    p->copies=atoi(t);
					    break;
				}
				row+=1;
				t=strtok(NULL,",");
			}
			p->next=NULL;
			last->next=p;
			last=p;//iserting a new node into the linked list
		    memset(try, '\0', 1024);
            f = fgets(try,sizeof(try),loan);//read in the second line
		    int j;
		    for (j=0;j<=1024;j++){
			    if (try[j]=='\n'){
				    try[j]='\0';
			    }
		    }//delete the '/n' at the end of the line
		}
		show->length=last->id;//the length of the booklist
		fclose(loan);
		return 0;
	}	
}


//funtion used for users to borrow a book
int borrow_book(User *borrowuser,FILE *loan){//borrow a book is user sensitive
    loan=fopen("loan.txt","a");
	printf("Enter the ID of the book you wish to borrow: ");
	char *str=(char *)malloc(sizeof(int)*5+sizeof(char));//the maxium length of a ID maybe is 4 digit(range from 0~99999) + one for the '\n'
	fgets(str,21,stdin);
	int i=strlen(str);
	str[i-1]='\0';//get rid of the '\n' at the last of the input
	int j;
	for (j=0;j<i-1;j++){
		if (!isdigit(str[j])){
			printf("\nThis is an invalid ID!\n");
			return 1;;
		}
		else{continue;}
	}
	int borrow_id=(int)atoi(str);//read in the ID for borrow operations 
	if (borrow_id>lpointer->length || borrow_id<1){
		printf("\nID out of range! Please re-enter.\n");
		return 1;
	}
	else{
		//check whether the user has borrowed a copy of the book
		if (borrowuser->borrowed->list->id==borrow_id){
			printf("\nSorry, you already have a copy of this book on loan!\n");
			return 1;
		}
	    int loop=0;//for loop around the whole list
		Book *p,*end;
		end=lpointer->list;
	    while (loop<lpointer->length){
			//borrow operations
			CreateNode(p);
			p=end->next;
			if (p->id==borrow_id){
				//copy the book to the user's loan file
				fprintf(loan,"%i,%i,%s,%s,%i,%i\n",borrowuser->id,p->id,p->title,p->authors,p->year,1);
               //since one user cna oy have one copy of ecah book,the copies is set to 1
				p->copies=p->copies-1;//cut one from the libraray
			    borrowuser->borrowed->length+=1;//record the length of loan
				loop+=1;
				printf("\nYou have successfuly borrowed this book!\n");
				return 0;
			}
			else{
				end=p;
			    p=p->next;
			    loop+=1;
		    }
	    }
	}
	fclose(loan);
}

int return_book(User *returnuser,FILE *loan){//borrow a book is user sensitive
		load_loan(loan,show);
		printf("\nBelow is the list of books you aer currently borrowing:\n");
		print_title();
		Book *print;
	    print=show->list->next;
	    while(print!=NULL){
			printf("%-2i\t%-39s\t%-22s\t%-8i\t%i\n",print->id,print->title,print->authors,print->year,print->copies);//output formates
		    print=print->next;
	    }
		printf("Enter the ID number you want to return: ");
		char *str=(char *)malloc(sizeof(int)*5+sizeof(char));//the maxium length of a ID maybe is 4 digit(range from 0~99999) + one for the '\n'
	    fgets(str,21,stdin);
	    int i=strlen(str);
	    str[i-1]='\0';//get rid of the '\n' at the last of the input
	    int j;
	    for (j=0;j<i-1;j++){
		    if (!isdigit(str[j])){
			    printf("\nThis is an invalid ID!\n");
			    return 1;;
		    }
		    else{continue;}
	    }
	    int return_id=(int)atoi(str);//read in the ID for borrow operations

}

//fucntion for user register
int user_regist(FILE *userfile){
	load_users(userfile);//reload the userfile in case anychages have been made 
	//get user's name
    printf("Please enter your name(no numbers):");
	char *name=(char *)malloc(sizeof(char)*50);//the maxium length of a name maybe is 50 letters
	fgets(name,50,stdin);
	int i=strlen(name);
	name[i-1]='\0';//get rid of the '\n' at the last of the input
	int j;
	for (j=0;j<i-1;j++){
		if (isdigit(name[j])){
			printf("\nThis is an invalid name!\n");
			return 1;
		}
		else{continue;}
	}//name should not contian any numbers

    //get username
	printf("Please enter your username: ");
	char *username=(char *)malloc(sizeof(char)*100);//the maxium length of a username maybe is 100 characters
	fgets(username,100,stdin);
	int m=strlen(username);
	username[m-1]='\0';//get rid of the '\n' at the last of the input
	
	//get password
	printf("Please enter your username(no more than 10 letters or 10 intergers): ");
	char *password=(char *)malloc(sizeof(char)*10+sizeof(int)*10);//the maxium length of a username maybe is 100 characters
	fgets(password,50,stdin);
	int k=strlen(password);
	password[k-1]='\0';//get rid of the '\n' at the last of the input

	int newid=admin->users+1;//set the new user ID

	//write in the new user's information to user.txt
	userfile=fopen("user.txt","a");
	if (userfile==NULL){
		printf("\nFail to open user file. Contact the librarian.\n");
		fclose(userfile);
		return 1;
	}
	else{
		fprintf(userfile,"%i,%s,%s,%s\n",newid,name,username,password);
		fclose(userfile);
		free(name);
		free(username);
		free(password);
		printf("\nYou have registered successfully!\n");
		return 0;
	}
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

        User *LoginCheck;//serve as a check for user login, also aused as the identity of the user in user system
        LoginCheck=admin->UserList->next;
		int success=0;//determin whether a user has successfully logged in or not
        while (LoginCheck!=NULL){
            if (strcmp(LoginCheck->username,username)==0 && strcmp(LoginCheck->password,password)==0 && LoginCheck->id!=1){//the first is the librarian
			    success=1;
				Booklist(LoginCheck->borrowed);//creat the bokklist of loan books embedded in the particular user
	            CreateNode(LoginCheck->borrowed->list);//creat the first node in the booklist struct as the head node of the loan list
	            LoginCheck->borrowed->list->id=0;//initialize the loan list by id
            	LoginCheck->borrowed->length=0;//initialize the length of the booklist
                printf("\n(Successfully logged in as: %s)\n",LoginCheck->username);
				//interface for normal user
                int choice = 5; //exit
	            do {
	                char * answer = user_input("\nPlease choose an option:\n1) Borrow book \n2) Return book \n3) Search for books\n4) Display all books\n5) Quit\nOption: ");
	                choice = atoi(answer);
	                free(answer);
		            switch (choice) {
		                case 1:
			                borrow_book(LoginCheck,loan);
			                break;
			            case 2:
			                return_book(LoginCheck,loan);
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
				printf("\n(Successfully logged in as Librarian: %s)\n",LoginCheck->username);
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
			                printf("\nThank you for managing the library!\nLoging you out...\n\n");
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
