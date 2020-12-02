#include "../util/utils.h"
#include <stdlib.h>
#include <stdio.h>

int main(void) {
    FILE* fp = open_file("/home/amanda/AdventOfCode2020/01/expense_report.txt");
    if(!fp) return 1;

    int length = 5;
    int *array = NULL;
    array = (int *)malloc(length * sizeof(int));

    int i = 0;
    int count = 0;
    while(fscanf(fp, "%d", &i) != EOF){
        if(count == length){
            length *= 2;
            array = (int *)realloc(array, length * sizeof(int));
        }
        
        array[count++] = i;
    }

    //Part 1
    for(i = 0; i < count; i++){
        for(int j = i+1; j < count; j++){
            if(array[i] + array[j] == 2020){
                printf("%d + %d = 2020. * = %d\n", array[i], array[j], array[i]*array[j]);
            }
        }
    }

    //Part 2
    for(i = 0; i < count; i++){
        for(int j = i+1; j < count; j++){
            for(int k = j+1; k < count; k++){
                if(array[i] + array[j] + array[k] == 2020){
                    printf("%d + %d + %d = 2020. * = %d\n", array[i], array[j], array[k], array[i]*array[j]*array[k]);
                }
            }
        }
    }

    free(array);
    return 0;
}