#include "book_management.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define CreateNode(p) p=(Book *)malloc(sizeof(Book));
#define Booklist(p) p=(BookList *)malloc(sizeof(BookList));
#define DeleteNode(p) free((void *)p);



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

int store_books(FILE *file){

}