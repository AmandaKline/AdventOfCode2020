#include "../util/utils.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(void) {
    FILE* fp = open_file("/home/amanda/AdventOfCode2020/01/expense_report.txt");
    if(!fp) return 1;

    return 0;
}