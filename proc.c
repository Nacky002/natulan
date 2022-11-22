#include <stdio.h>
#include <stdlib.h>

#define MEM_SIZE 10

char* txt;

int out_of_mem_txt();

int out_of_mem_txt()
{
    if(txt == NULL)
    {
        perror("out of memory for text\n");
        return 1;
    }
}

int main()
{
    char c = 'h';
    int i;

    txt = (char*)malloc( sizeof(char) * MEM_SIZE );
    printf("%p\n", txt);

    out_of_mem_txt();

    for(i = 0; i < MEM_SIZE; i++)
    {
        txt[i] = c;
        printf("txt[%d] = %c\n", i, txt[i]);
    }

}
