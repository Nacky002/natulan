#!/usr/bin/c
#include <stdio.h>

int main ()
{
    int i = 333;

    FILE *open;
    open = fopen("test.txt", "w");
    
    fprintf(open, "Hello, world\n");
    fprintf(open, "%d\n", i);

    fclose(open);

    return 1;
}
