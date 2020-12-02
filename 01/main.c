#include <stdlib.h>
#include <stdio.h>

/////////////////////////////////////////////////////////////////////////////////////////
//                                                                                     //
//                           Function Declarations                                     //
//                                                                                     //
/////////////////////////////////////////////////////////////////////////////////////////
/* Open file and return file pointer */
FILE* open_file(char*);

int main(void) {
    printf("Running Day 1\n");

    FILE* fp = open_file("/home/amanda/AdventOfCode2020/01/expense_report.txt");
    if(!fp) return 1;

    int i = 0;
    if(fscanf(fp, "%d", &i) < 1){
		printf("Could not read an integer value!\n");
		return 1;
	}
	printf("%d\n", i);

    return 0;
}


FILE* open_file(char* filename){
    FILE *fp = fopen(filename, "r");

    if(!fp){
        printf("Failed to open file %s\n", filename);
        return NULL;
    }

    return fp;
}