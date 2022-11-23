#include <stdio.h>
#include <stdlib.h>

#define MEM_SIZE 10

int main()
{
    char c = 'h';
    char* txt;
    int i;

    /* テキストファイル保存用の、配列の容量確保 */
    txt = (char*)malloc( sizeof(char) * MEM_SIZE );

    /* 配列の容量確保失敗 */
    if(txt == NULL)
    {
        printf("failed to get memory size of txt...\n");
        return 1;
    }

    /* 配列へ、テキストを格納 */
    for(i = 0; i < MEM_SIZE; i++)
    {
        txt[i] = c;
        printf("txt[%d] = %c\n", i, txt[i]);
    }

}
