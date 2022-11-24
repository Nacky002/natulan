#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MEM_SIZE 1000           // 読み込み可能最大文字数
#define READ_FILE "in.txt"      // 入力ファイル
#define WRITE_FILE "out.txt"    // 出力ファイル

int main()
{
    char c = 0;
    char* txt;
    unsigned short i;
    unsigned short c_num = 0;
    FILE* read;
    FILE* write;

    /* 入力ファイル保存用の、配列のメモリ確保 */
    txt = (char*)malloc( sizeof(char) * MEM_SIZE );

    /* 配列のメモリ確保失敗 */
    if(txt == NULL)
    {
        perror("\n配列のメモリ確保に失敗しました。\n");
        return 1;
    }



    /* 入力ファイルを開く ------------------------------*/
    read = fopen(READ_FILE, "r");

    /* 入力ファイルを開く失敗 */
    if(read == NULL)
    {
        perror("\n入力ファイルへのアクセスに失敗しました。\n");
        return 1;
    }

    /* 配列へ入力ファイルを格納 */
    while(1)
    {
        c = fgetc(read);
        if(c == EOF) break;
        txt[c_num] = c;
        c_num ++;
    }

    /* 入力ファイルを閉じる ----------------------------*/
    fclose(read);



    /* テキスト置換 */
    for(i = 0; i <= c_num; i++)
    {
        if( isalpha(txt[i]) );
        else if( txt[i] == ' ' );
        else if( txt[i] == '\n' );
        else txt[i] = ' ';
    }



    /* 出力ファイルを開く ------------------------------*/
    write = fopen(WRITE_FILE, "w");

    /* 出力ファイルを開く失敗 */
    if(write == NULL)
    {
        perror("\n出力ファイルへのアクセスに失敗しました。\n");
        return 1;
    }

    /* 出力ファイルへ配列を入力 */
    for(i = 0; i <= c_num; i++)
    {
        fprintf(write, "%c", txt[i]);
    }

    /* 出力を閉じる ------------------------------------*/
    fclose(write);



    printf("Succeeded !!\n");

    return 0;
}
