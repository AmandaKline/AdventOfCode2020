#include "../util/utils.h"
#include <stdlib.h>
#include <stdio.h>

void set_map(char* map, int l, int h, int i, int j, char val){
    map[j*l + i] = val;
}

char get_map(char* map, int l, int h, int i, int j){
    //printf("At (%d, %d), %c\n", i % l, j, map[j*l + (i%l)]);
    return map[j*l + (i%l)];
}

char* load_map(char* map, int* l, int* h){
    FILE* fp = open_file("/home/amanda/AdventOfCode2020/03/map.txt");
    if(!fp){
        printf("Failed to open file");
        return NULL;
    } 

    *l = 0;
    *h = 0;
    map = (char*)malloc(sizeof(char));
    
    //Read in first line
    char c;
    fscanf(fp, "%c", &c);
    while(c != '\n'){
        map[*l] = c;
        *l += 1;
        map = (char*)realloc(map, *l+1);
        fscanf(fp, "%c", &c);
    }

    for(*h = 2; !feof(fp); *h += 1)
    { 
        map = (char*)realloc(map, (*l) * (*h));
        fscanf(fp, "%c", &c);
        for(int i = 0; c != '\n' && !feof(fp); i++){
            set_map(map, *l, *h, i, *h - 1, c);
            fscanf(fp, "%c", &c);
        }
    }
    *h -= 1;
    printf("Map read in with dimensions %d x %d\n", *l, *h);

    return map;
}

int main(void) {
    char* map;
    int l, h;
    map = load_map(map, &l, &h);
    printf("Main got map with dimensions %d x %d\n", l, h);

    /*Right 1, down 1. -- a
      Right 3, down 1. -- b
      Right 5, down 1. -- c
      Right 7, down 1. -- d
      Right 1, down 2. -- next loop
    */

    //Calculate # of trees encountered w/ above slopes
    int count_a = 0, count_b = 0, count_c = 0, count_d = 0, count_e = 0;
    for(int j = 0, a = 0, b = 0, c = 0, d = 0;
        j < h;
        j++, a++, b += 3, c += 5, d += 7){
        if(get_map(map, l, h, a, j) == '#') count_a++;
        if(get_map(map, l, h, b, j) == '#') count_b++;
        if(get_map(map, l, h, c, j) == '#') count_c++;
        if(get_map(map, l, h, d, j) == '#') count_d++;
    }

    for(int j = 0, i =0; j < h; j += 2, i++){
        if(get_map(map, l, h, i, j) == '#') count_e++;
    }

    printf("We'll hit %u trees.\n Separated: %d, %d, %d, %d, %d\n", count_a * count_b * count_c * count_d * count_e,
        count_a, count_b, count_c, count_d, count_e);

    //free(map);
    return 0;
}