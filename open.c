#!/usr/bin/c
#include <stdio.h>

int main ()
{
    FILE *open;
    open = fopen("test.txt", "w");
    fprintf(open, "Hello, world");
    fclose(open);
    printf("hhh\n");
}
