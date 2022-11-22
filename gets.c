#!/usr/bin/c
#include <stdio.h>

int main ()
{
    char ch[100];
    FILE *fp;

    fp = fopen("test.txt", "w");
    
    printf("please input:\n");
    fgets(ch, sizeof(ch), stdin);

    fprintf(fp, "%s\n", ch);
    fclose(fp);
}
