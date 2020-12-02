#include <stdlib.h>
#include <stdio.h>

int main{
    char* filename = "expense_report.txt"
	FILE *fp = fopen(filename, "r");

    if(!fp) return;

    int i = 0
    if(fscanf(fp, "%d", &i) < 1){
		printf("Could not read an integer value!\n");
		return EOF;
	}
	print(i);

    return 0;
}