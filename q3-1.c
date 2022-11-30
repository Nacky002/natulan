#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define CHAR_QUA    100000       // 最大文字数
#define READ_FILE   "in.txt"     // 入力ファイル
#define WRITE_FILE  "out.txt"    // 出力ファイル

unsigned char Get_freq (unsigned char elem);

int main ()
{
    char one_buf = 0;
    char txt[CHAR_QUA] = {};
    unsigned char x_buf = 0;
    unsigned char y_buf = 0;
    unsigned int in_max = 0;
    unsigned int i = 0;
    unsigned char j = 0;
    unsigned int freq[27][27] = {};
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
        one_buf = fgetc(read);
        if (one_buf == EOF) break;
        else if ( isalpha(one_buf)  ||  one_buf == 32 )
        {
            txt[in_max] = one_buf;
            in_max ++;
        }
    }

    /* 入力ファイルを閉じる ----------------------------*/
    fclose(read);


    /* 文字の出現頻度を求める */
    for (i = 0; i <= in_max; i++)
    {
        x_buf = Get_freq ( one_buf );
        y_buf = Get_freq ( txt[i] );

        if (one_buf != 0)
        {
            freq[ x_buf ][ y_buf ] ++ ;
        }

        one_buf = txt[i];
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
    for (i = 0; i <= 25; i++)
    {
        for (j = 0; j <= 25; j++)
        {
            fprintf(write, "[%c%c] =", (97 + i), (97 + j));
            fprintf(write, "%u\n", freq[i][j]);
        }
        fprintf(write, "[%c%c] =", (97 + i), 32);
        fprintf(write, "%u\n", freq[i][26]);
    }
    for (j = 0; j <= 25; j++)
    {
        fprintf(write, "[%c%c] =", 32, (97 + j));
        fprintf(write, "%u\n", freq[26][j]);
    }
    fprintf(write, "[%c%c] =", 32, 32);
    fprintf(write, "%u\n", freq[26][26]);

    /* 出力を閉じる ------------------------------------*/
    fclose(write);

    return 0;
}


unsigned char Get_freq (unsigned char elem)
{
    unsigned char i = 0;
    unsigned char ret = 0;

    for (i = 0; i <= 25; i++)
    {
        if ( elem == (65 + i)  ||  elem == (97 + i) ) ret = i;
    }
    if (elem == 32) ret = 26;
    
    return ret;
}


