#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//compare two files, printing the first line where they differ
int main(int argc, char *argv[]){
    FILE *fp1, *fp2;
    void filecmp(FILE *, FILE *);
    char *prog = argv[0];
    if(argc == 3){
        if((fp1 = fopen(argv[1], "r")) ==NULL || (fp2 = fopen(argv[2], "r")) ==NULL){
            fprintf(stderr, "%s: can't open %s\n", prog, argv[1]);
            exit(1);
        }
        else{
            filecmp(fp1, fp2);
            fclose(fp1);
            fclose(fp2);
        }
    }
    else{
        printf("%s", "Please enter two file names");
    }
    exit(0);
}

void filecmp(FILE *f1, FILE *f2){
	size_t size = 100;
	char *string;
	char *string1;
	
	while(!feof(f1) && !feof(f2)){
		string = (char *) malloc(size);
		getline(&string, &size, f1);
	 	string1 = (char *) malloc(size);
		getline(&string1, &size, f2);
        if(strcmp(string, string1)!= 0)
        {
            printf("%s", string);
            printf("%s", string1);
            return; 
        }
    }
}	
