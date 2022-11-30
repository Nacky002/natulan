#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define CHAR_QUA    100000       // 最大文字数
#define READ_FILE   "in.txt"     // 入力ファイル
#define WRITE_FILE  "out.txt"    // 出力ファイル

int main ()
{
    char in_buf = 0;
    char txt[CHAR_QUA] = {0};
    unsigned int in_max = 0;
    unsigned int i = 0;
    unsigned int j = 0;
    unsigned int fleq[27] = {0};
    FILE* read = NULL;
    FILE* write = NULL;


    /* 入力ファイルを開く ------------------------------*/
    read = fopen(READ_FILE, "r");

    /* 入力ファイルを開く失敗 */
    if (read == NULL)
    {
        perror("\n入力ファイルへのアクセスに失敗しました。\n");
        return 1;
    }

    /* 配列へ文字を格納 */
    while (1)
    {
        in_buf = fgetc(read);
        if (in_buf == EOF) break;
        else if ( isalpha(in_buf)  ||  in_buf == 32 )
        {
            txt[in_max] = in_buf;
            in_max ++;
        }
    }

    /* 入力ファイルを閉じる ----------------------------*/
    fclose(read);


    /* 文字の出現頻度を求める */
    for (j = 0; j <= in_max; j++)
    {
        for (i = 0; i <= 25; i++) if ( txt[j] == (65 + i)  ||  txt[j] == (97 + i) ) fleq[i] ++;
        if (txt[j] == 32) fleq[26] ++;
    }


    /* 出力ファイルを開く ------------------------------*/
    write = fopen(WRITE_FILE, "w");

    /* 出力ファイルを開く失敗 */
    if (write == NULL)
    {
        perror("\n出力ファイルへのアクセスに失敗しました。\n");
        return 1;
    }

    /* 文字の出現頻度を書き込む */
    for (i = 0; i <= 25; i++) fprintf (write, "%u %c found\n", fleq[i], (97 + i) );
    fprintf (write, "%u '%c' found\n", fleq[26], 32);

    /* 出力を閉じる ------------------------------------*/
    fclose(write);

    return 0;
}
