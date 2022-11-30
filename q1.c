// SPDX-FileCopyrightText: 2022 NAGAKI Yuki
// SPDX-License-Identifier: BSD-3-Clause

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MEM_SIZE    100000       // 読み込み可能最大バイト数
#define READ_FILE   "in.txt"     // 入力ファイル
#define WRITE_FILE  "out.txt"    // 出力ファイル

int main()
{
    char c_buf = 0;
    char txt[MEM_SIZE] = {};
    unsigned int i;
    unsigned int in_max = 0;
    FILE* read;
    FILE* write;

    /* 入力ファイルを開く ------------------------------*/
    read = fopen(READ_FILE, "r");

    /* 入力ファイル認識失敗 */
    if (read == NULL)
    {
        perror("\n入力ファイルへのアクセスに失敗しました。\n");
        return 1;
    }

    /* 配列へ文字データを格納 */
    while(1)
    {
        c_buf = fgetc(read);
        if (c_buf == EOF) break;
        else if ( isalpha(c_buf)  ||  c_buf == 32  ||  c_buf == 10 ) txt[in_max] = c_buf;
        else txt[in_max] = 32;
        in_max ++;
    }

    /* 入力ファイルを閉じる ----------------------------*/
    fclose(read);

    /* 出力ファイルを開く ------------------------------*/
    write = fopen(WRITE_FILE, "w");

    /* 出力ファイル認識失敗 */
    if(write == NULL)
    {
        perror("\n出力ファイルへのアクセスに失敗しました。\n");
        return 1;
    }

    /* 出力ファイルへ配列を入力 */
    for(i = 0; i <= in_max; i++) fprintf(write, "%c", txt[i]);

    /* 出力を閉じる ------------------------------------*/
    fclose(write);

    return 0;
}
