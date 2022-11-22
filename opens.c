#!/usr/bin/c
#include <stdio.h>

int main ()
{
    int i = 1202;
    int g = 0;
    FILE *open;
    FILE *read;

    open = fopen("num.txt", "w");
    fprintf(open, "%d\n", i);
    fclose(open);

    read = fopen("num.txt", "r");
    fscanf(read, "%d\n", &g);
    fclose(read);
    
    printf("%d\n", g);
}
