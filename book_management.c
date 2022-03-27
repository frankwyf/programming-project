#include"interface.h"
#include"user_management.h"
#include"book_management.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


#define CreateNode(p) p=(Book *)malloc(sizeof(Book));
#define Booklist(p) p=(BookList *)malloc(sizeof(BookList));
#define DeleteNode(p) free((void *)p);


void print_title(){
	printf("ID");
	printf("%*s",6," ");
	printf("Title");
	printf("%*s",35," ");
	printf("Author");
	printf("%*s",18," ");
	printf("Year");
	printf("%*s",12," ");
	printf("Copies\n");//title line are presented as above
}

void print_all_books(BookList *lpointer){
	print_title();
	Book *print;
	print=lpointer->list->next;
	while(print!=NULL){
			printf("%-2i\t%-39s\t%-22s\t%-8i\t%i\n",print->id,print->title,print->authors,print->year,print->copies);//output formates
		print=print->next;
	}
}

int load_books(FILE *file){
	file=fopen("books.txt","r");
	if (file==NULL){
		printf("File cannot open!\n");
		return -1;
	}
	else{
		Book *p,*last;
		Booklist(lpointer);//creat the header node
		CreateNode(lpointer->list);
		last=lpointer->list;
		char temp[1024];//read in a whole line form the text file
		memset(temp, '\0', 1024);//initialize the temp string
		char *frtn=fgets(temp,sizeof(temp),file);
		int i;
		for (i=0;i<=1024;i++){
			if (temp[i]=='\n'){
				temp[i]='\0';
			}
		}//delete the '/n' at the end of the line
		while (frtn != NULL){//read file till the end (an empty line)
		    CreateNode(p);//create the first real node
			char *ptr=strtok(temp,",");//cut the input string by comma
			int row=0;
			while (ptr != NULL){
				switch (row){//copying data into the data part in a node
					case 0:
					    p->id=atoi(ptr);
					    break;
					case 1:
					    p->title=ptr;
						int i;
						i=strlen(p->title);
						p->title=(char *)malloc(i*sizeof(char));
						strcpy(p->title,ptr);
					    break;
					case 2:
					    p->authors=ptr;
						int j;
						j=strlen(p->authors);
						p->authors=(char *)malloc(i*sizeof(char));
						strcpy(p->authors,ptr);
					    break;
					case 3:
					    p->year=atoi(ptr);
					    break;
					case 4:
					    p->copies=atoi(ptr);
					    break;
				}
				row+=1;
				ptr=strtok(NULL,",");
			}
			p->next=NULL;
			last->next=p;
			last=p;//iserting a new node into the linked list
		    memset(temp, '\0', 1024);
            frtn = fgets(temp,sizeof(temp),file);//read in the second line
		    int j;
		    for (j=0;j<=1024;j++){
			    if (temp[j]=='\n'){
				    temp[j]='\0';
			    }
		    }//delete the '/n' at the end of the line
		}
		lpointer->length=last->id;//the length of the booklist
		fclose(file);
		return 0;
	}	
}
BookList find_book_by_title (const char *title){
	BookList *find_book_by_title;
	Booklist(find_book_by_title);
	CreateNode(find_book_by_title->list);
	find_book_by_title->length=0;//initilaize
	printf("\nPlease enter the title: ");
	char *str=(char *)malloc(sizeof(char)*200);//the maxium length of a book author maybe 200 characters
	fgets(str,200,stdin);
	int i=strlen(str);
	str[i-1]='\0';//get rid of the '\n' at the last of the input
	title=str;
	int j;
	for (j=0;j<i-1;j++){
		if (isdigit(str[j])){
			printf("\nThis is an invalid book title!\n");
			find_book_by_title->list=NULL;
			return *find_book_by_title;
		}
		else{continue;}
	}
    find_book_by_title->list=lpointer->list->next;
	printf("\n");
    print_title();
	int try=0;//for loop around the whole list
	int flag=0;//to decide whether there's an out put or not
	while (try<lpointer->length){
        while (find_book_by_title->list!=NULL){
	        if (strcmp(find_book_by_title->list->title,str)==0){
	            printf("%-2i\t%-39s\t%-22s\t%-8i\t%i\n",find_book_by_title->list->id,find_book_by_title->list->title,find_book_by_title->list->authors,find_book_by_title->list->year,find_book_by_title->list->copies);//output formates
				find_book_by_title->length+=1;
	            find_book_by_title->list=find_book_by_title->list->next;
				flag=1;
				try+=1;
	        }
	        else{
			    find_book_by_title->list=find_book_by_title->list->next;
			    try+=1;
		    }
        }
	}
	if(try==lpointer->length && flag==0){
		printf("\nSorry! There's no such book you want.\n");
		find_book_by_title->list=NULL;
		return *find_book_by_title;
	}
	free(str);
	return *find_book_by_title;
}

BookList find_book_by_author (const char *author){
	BookList *find_book_by_author;
	Booklist(find_book_by_author);
	printf("\nPlease enter the author: ");
	char *str=(char *)malloc(sizeof(char)*100);//the maxium length of a book title maybe 200 characters
	fgets(str,100,stdin);
	int i=strlen(str);
	str[i-1]='\0';//get rid of the '\n' at the last of the input
	author=str;//give in the attributes
	int j;
	for (j=0;j<i-1;j++){
		if (isdigit(str[j])){
			printf("\nThis is an invalid auathor name!\n");
			find_book_by_author->list=NULL;
			return *find_book_by_author;
		}
		else{continue;}
	}
	CreateNode(find_book_by_author->list);
	find_book_by_author->length=0;//initilaize
	find_book_by_author->list=lpointer->list->next;
	printf("\n");
	print_title();
	int try=0;//for loop around the whole list
	int flag=0;//to decide whether there's an out put or not
	while (try<lpointer->length){
	    while (find_book_by_author->list!=NULL){
		    if (strcmp(find_book_by_author->list->authors,str)==0){
		        printf("%-2i\t%-39s\t%-22s\t%-8i\t%i\n",find_book_by_author->list->id,find_book_by_author->list->title,find_book_by_author->list->authors,find_book_by_author->list->year,find_book_by_author->list->copies);//output formates
		        find_book_by_author->list=find_book_by_author->list->next;
				find_book_by_author->length+=1;
				flag=1;
				try+=1;
	        }
	        else{
			    find_book_by_author->list=find_book_by_author->list->next;
			    try+=1;
		    }
	    }
	}
	if(try==lpointer->length && flag==0){
	    printf("\nSorry! There's no such author in the library.\n");
		find_book_by_author->list=NULL;
		return *find_book_by_author;
    }
	free(str);
	return *find_book_by_author;
}

BookList find_book_by_year (unsigned int year){
	BookList *find_book_by_year;
	Booklist(find_book_by_year);
	printf("\nPlease enter the year: ");
	char *str=(char *)malloc(sizeof(int)*4+sizeof(char));//the maxium length of a year is 4 digit + one for the '\n'
	fgets(str,18,stdin);
	int i=strlen(str);
	str[i-1]='\0';//get rid of the '\n' at the last of the input
	int j;
	for (j=0;j<i-1;j++){
		if (!isdigit(str[j])){
			printf("\nThis is an invalid year!\n");
			find_book_by_year->list=NULL;
			return *find_book_by_year;
		}
		else{continue;}
	}
	year=(int)atoi(str);//give the attributes
	if (year>2022){
		printf("\nThis year is 2022! No futher year is possible!\n");
		find_book_by_year->list=NULL;
		return *find_book_by_year;
	}
	CreateNode(find_book_by_year->list);
	find_book_by_year->length=0;//initilaize
	find_book_by_year->list=lpointer->list->next;
	print_title();
	int flag=0;//to decide whether there's an out put or not
	int try=0;//for loop around the whole list
	while (try<lpointer->length){
		while (find_book_by_year->list!=NULL){
		    if (find_book_by_year->list->year==year){
			    printf("%-2i\t%-39s\t%-22s\t%-8i\t%i\n",find_book_by_year->list->id,find_book_by_year->list->title,find_book_by_year->list->authors,find_book_by_year->list->year,find_book_by_year->list->copies);//output formates
			    find_book_by_year->list=find_book_by_year->list->next;
				find_book_by_year->length+=1;
				flag=1;
				try+=1;
		    }
		    else{
			    find_book_by_year->list=find_book_by_year->list->next;
			    try+=1;
		    }
	    }
	}
	if(try==lpointer->length && flag==0){
	    printf("\nSorry! There's no book released in that year in the library.\n");
		find_book_by_year->list=NULL;
		return *find_book_by_year;
    }
	free(str);
	return *find_book_by_year;
}



int search_for_books(BookList *lpointer){
	printf("\nLoading Search Menu...\n");
	   int in = 5; //exit
	        do {
	        char * answer = user_input("\nPlease choose an option:\n1) Search by title\n2) Search by author \n3) Search by year\n4) Return to previous menu\nOption: ");
	        in = atoi(answer);
	        free(answer);
	        switch (in) {
		        case 1:
			        find_book_by_title(title);
			        break;
			    case 2:
			        find_book_by_author(author);
			        break;
			    case 3:
		            find_book_by_year(year);
		            break;
	            case 4:
		            printf("\nThank you for using search for books fucntion!\n");
		            break;
	            default:
		            printf("\nSorry, the option you entered was invalid, please try agian\n");
            } 
        } while (in != 4);
	return 0;
}

int store_books(FILE *file){
	file=fopen("books.txt","w");
	if (file==NULL){
		printf("\nFatal error! Book file is missing!\n");
		return 1;
	}
	else{
		Book *store,*final;
	    final=lpointer->list;
	    CreateNode(store);
	    store=final->next;
	    int list_long=0;
	    while (list_long<lpointer->length){
		    fprintf(file,"%i,%s,%s,%i,%i\n",store->id,store->title,store->authors,store->year,store->copies);
		    final=store;
		    store=store->next;
		    list_long+=1;
	    }
		return 0;//showing success of store books
	}
}