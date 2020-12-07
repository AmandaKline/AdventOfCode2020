#include "../util/utils.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(void) {
    FILE* fp = open_file("/home/amanda/AdventOfCode2020/02/passwords.txt");
    if(!fp) return 1;

    int low = 0, high = 0, valid1 = 0, valid2 = 0;
    char c = 'a';
    char password[100];

    while(!feof(fp))
    {     
        fscanf(fp, "%d-%d %c: %s\n", &low, &high, &c, password);

        // Policy 1
        int count = 0;
        for (int i=0; i < strlen(password); i++){
            if(password[i] == c) count++;
        }

        if(count >= low && count <= high) valid1++;

        //Policy 2
        if(password[low-1] == c ^ password[high-1] == c) valid2++;
    }

    printf("There are %d valid passwords according to policy 1, and %d according to policy 2\n", valid1, valid2);
    fclose (fp);

    return 0;
}