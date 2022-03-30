#include"interface.h"
#include"user_management.h"
#include"book_management.h"
#include"management.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>



#define Createuser(p) p=(User *)malloc(sizeof(User));
#define Createlibrarian(p) p=(Librarian *)malloc(sizeof(Librarian));
#define Createloan(p) p=(Loan *)malloc(sizeof(Loan));
#define Createloanlist(p) p=(Loanlist *)malloc(sizeof(Loanlist));





//the funtion is used to load all loan information form the loan file
//used when user is returning book
//read out the whole loan file,returns 0 if success, else return 1
int load_all_loans(FILE *loan){
	loan=fopen("books.txt","r");
	if (loan==NULL){
		printf("File cannot open!\n");
		return -1;
	}
	else{
		Loan *p,*last;
        Createloanlist(all);
		Createloan(all->loanlist);//creat the header node
		last=all->loanlist;

        
		char temp[1024];//read in a whole line form the text file
		memset(temp, '\0', 1024);//initialize the temp string
		char *frtn=fgets(temp,sizeof(temp),file);
		int i=strlen(temp);
		temp[i-1]='\0';//delete the '/n' at the end of the line
		while (frtn != NULL){//read file till the end (an empty line)
		    Createloan(p);//create the first real node
			char *ptr=strtok(temp,",");//cut the input string by comma
			int row=0;
			while (ptr != NULL){
				switch (row){//copying data into the data part in a node
                    case 0:
                        p->user=atoi(ptr);
					case 1:
					    p->bookid=atoi(ptr);
					    break;
					case 2:
					    p->title=ptr;
						int i;
						i=strlen(p->title);
						p->title=(char *)malloc(i*sizeof(char));
						strcpy(p->title,ptr);
					    break;
					case 3:
					    p->authors=ptr;
						int j;
						j=strlen(p->authors);
						p->authors=(char *)malloc(i*sizeof(char));
						strcpy(p->authors,ptr);
					    break;
					case 4:
					    p->year=atoi(ptr);
					    break;
					case 5:
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
		    int j=strlen(temp);
			temp[j-1]='\0';//delete the '/n' at the end of the line
		}
		//the length of all
		fclose(file);
		return 0;
	}	
}