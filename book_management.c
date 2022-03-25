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
void search_by_title(BookList *lpointer){
	printf("\nPlease enter the title: ");
	char *str=(char *)malloc(sizeof(char)*100);//the maxium length of a book author maybe 200 characters
	fgets(str,100,stdin);
	int i=strlen(str);
	str[i-1]='\0';
	Book *searhTitle;
	searhTitle=lpointer->list->next;
	print_title();
	while (searhTitle!=NULL){
		if (strcmp(searhTitle->title,str)==0){
			printf("%-2i\t%-39s\t%-22s\t%-8i\t%i\n",searhTitle->id,searhTitle->title,searhTitle->authors,searhTitle->year,searhTitle->copies);//output formates
			break;
		}
		else{searhTitle=searhTitle->next;}
	}
	
}

void search_by_author(BookList *lpointer){
	printf("\nPlease enter the author: ");
	char *str=(char *)malloc(sizeof(char)*200);//the maxium length of a book title maybe 200 characters
	fgets(str,200,stdin);
	int i=strlen(str);
	str[i-1]='\0';
	Book *searchAuthor;
	searchAuthor=lpointer->list->next;
	print_title();
	while (searchAuthor!=NULL){
		if (strcmp(searchAuthor->authors,str)==0){
			printf("%-2i\t%-39s\t%-22s\t%-8i\t%i\n",searchAuthor->id,searchAuthor->title,searchAuthor->authors,searchAuthor->year,searchAuthor->copies);//output formates
			break;
		}
		else{searchAuthor=searchAuthor->next;}
	}
	
}

void search_by_year(BookList *lpointer){
	printf("\nPlease enter the year: ");
	int year;
	scanf("%i",&year);
	getchar();
	Book *searchYear;
	searchYear=lpointer->list->next;
	print_title();
	while (searchYear!=NULL){
		if (searchYear->year==year){
			printf("%-2i\t%-39s\t%-22s\t%-8i\t%i\n",searchYear->id,searchYear->title,searchYear->authors,searchYear->year,searchYear->copies);//output formates
			break;
		}
		else{searchYear=searchYear->next;}
	}
}



int search_for_books(BookList *lpointer){
	printf("\nLoading Search Menu...\n");
	   int in = 5; //exit
	        do {
	        char * answer = user_input("\nPlease choose an option:\n1) Search by title\n2) Search by author \n3) Search by year\n4) Quit\nOption: ");
	        in = atoi(answer);
	        free(answer);
	        switch (in) {
		        case 1:
			        search_by_title(lpointer);
			        break;
			    case 2:
			        search_by_author(lpointer);
			        break;
			    case 3:
		            search_by_year(lpointer);
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

}