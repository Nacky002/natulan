#!/usr/bin/c
#include <stdio.h>
#include <stdlib.h>

/* 入力ファイル内の文字数 */
#define MEM_SIZE 100
/* 入力ファイル */
#define READ_FILE "in.txt"
/* 出力ファイル */
#define WRITE_FILE "out.txt"

int main()
{
    char c = 'g';
    char* txt;
    int i;
    FILE* read;
    FILE* write;

    /* 入力ファイル保存用の、配列の容量確保 */
    txt = (char*)malloc( sizeof(char) * MEM_SIZE );

    /* 配列のメモリ確保失敗 */
    if(txt == NULL)
    {
        perror("配列のメモリ確保に失敗しました。\n");
        return 1;
    }

    /* 入力ファイルを開く */
    read = fopen(READ_FILE, "r");

    /* 入力ファイルを開く失敗 */
    if(read == NULL)
    {
        perror("入力ファイルへのアクセスに失敗しました。\n");
        return 1;
    }

    /* 配列へテキストを格納 */
    for(i = 0; i < MEM_SIZE; i++)
    {
        if( (c = fgetc(read)) != EOF )
        {
            txt[i] = c;
        }
        else
        {
            txt[i] = '0';
        }
    }

    /* 入力ファイルを閉じる */
    fclose(read);

    /* 出力ファイルを開く */
    write = fopen(WRITE_FILE, "w");

    /* 出力ファイルを開く失敗 */
    if(write == NULL)
    {
        perror("出力ファイルへのアクセスに失敗しました。\n");
        return 1;
    }

    /* 出力ファイルへ配列を入力 */
    for(i = 0; i < MEM_SIZE; i++)
    {
        c = txt[i];
        fprintf(write, "%c", c);
    }

    /* 出力を閉じる */
    fclose(write);
}
