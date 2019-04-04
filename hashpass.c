#include <stdio.h> 
#include <string.h>
// Contains free
#include <stdlib.h> 
#include <ctype.h>
#include "md5.h"

// " " in directory 
// < > another's file 

//Function Prototypes
void checkFiles(int n);
void checkOpen(FILE *f, char *fName);

int main(int argc, char *argv[])
{
    /*
    char *hash = md5(argv[1], strlen(argv[1])); 
    printf("Hash: %s\n", hash);
    free(hash);
    */
    
    //Function call to check files 
    checkFiles(argc); 
    
    char line[100];
    char *hash;
    
    //User must put it in this order: in.txt THEN out.txt
    //Open *in file
    FILE *in = fopen(argv[1], "r");
    FILE *out = fopen(argv[2], "w");
    
    //Checking if files can be opened, if not close program
    checkOpen(in, "INPUT");
    checkOpen(out, "OUTPUT");
    
    int count = 0;

    
    //Loop to get lines from file 
    while(fgets(line, 100, in) != NULL)
    {
        count++; 
        //printf("STRLength = %lu \n", strlen(line));
        hash = md5(line,strlen(line)-1);
        fprintf(out, "HASH[%d]: %s \n", count, hash);
        free(hash);
    }
    
    fclose(in);
    fclose(out);
    
}

void checkFiles(int n){
    if (n < 3){
        printf("You need to supply two filenames\n");
        exit(1);
    }
}

void checkOpen(FILE *f, char *fName){
    if(!f){
        printf("Cannot open %s for reading \n", fName);
        printf("Program will now close. . . \n");
        exit(1); 
    }
}