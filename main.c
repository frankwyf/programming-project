#include"interface.h"


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv){
    if (argc<4){
        printf("Please resatrt and enter the name of the bookfile,userfile and loanfile.\n");
        exit(1);
    }
    else{
        int i,j,k;
        i=strlen(argv[1]);
        j=strlen(argv[2]);
        k=strlen(argv[3]);
        bookfile=(char *)malloc(sizeof(char)*i);
        Userfile=(char *)malloc(sizeof(char)*j);
        loanfile=(char *)malloc(sizeof(char)*k);
        strcpy(bookfile,argv[1]);
        strcpy(Userfile,argv[2]);
        strcpy(loanfile,argv[3]);
    }
    printf("Welcome to the librbay system!\n");
    run_system();
    return 0;
}