#!/usr/bin/c
#include <stdio.h>
#include <stdlib.h>

#define MEM_SIZE 10

int main()
{
    char c = 'h';
    char* txt;
    int i;

    txt = (char*)malloc( sizeof(char) * MEM_SIZE );

    if(txt == NULL)
    {
        printf("failed to get memory size of txt...\n");
        return 1;
    }

    for(i = 0; i < MEM_SIZE; i++)
    {
        txt[i] = c;
        printf("txt[%d] = %c\n", i, txt[i]);
    }

}
