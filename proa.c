#!/usr/bin/c
#include <stdio.h>

int main ()
{
    char c;
    char txt[];
    FILE *read;
    FILE *write;

    read = fopen("in.txt", "r");

    while( (c = fgetc(read)) != EOF )
    {
        

    fclose(read);

    write = fopen("out.txt", "w");
    fprintf(write, "%s", ch);
    fclose(write);
}
