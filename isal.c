#!/usr/bin/c
#include <stdio.h>
#include <ctype.h>

char x = 'a';

int main ()
{
    printf("%c\n", x);
    if( isalpha(x) )
    {
        printf("hhh\n");
    }
}
