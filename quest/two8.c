#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define CHAR_QUA    10000        // 最大文字数
#define READ_FILE   "in.txt"     // 入力ファイル
#define WRITE_FILE  "out.txt"    // 出力ファイル

unsigned char Get_freq (unsigned char elem);
void Print (unsigned char 1d, unsigned char 2d, unsigned char 3d);

int main ()
{
    char one_buf = 0;
    char two_buf = 0;
    char txt[CHAR_QUA] = {};
    unsigned char 1d_buf = 0;
    unsigned char 2d_buf = 0;
    unsigned char 3d_buf = 0;
    unsigned int in_max = 0;
    unsigned int i = 0;
    unsigned int j = 0;
    unsigned int k = 0;
    unsigned int l = 0;
    unsigned int fleq[27][27][27] = {};
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
            txt[in_max] = one_buf;kk
            in_max ++;
        }
    }

    /* 入力ファイルを閉じる ----------------------------*/
    fclose(read);


    /* 文字の出現頻度を求める */
    for (i = 0; i <= in_max; i++)
    {
        1d_buf = Get_freq ( two_buf );
        2d_buf = Get_freq ( one_buf );
        3d_buf = Get_freq ( txt[i] );

        if (one_buf != 0 && two_buf != 0)
        {
            freq[ 1d_buf ][ 2d_buf ][ 3d_buf ] ++ ;
        }

        one_buf = txt[i];
        two_buf = one_buf;
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

    for (i = 0; i <= 25; i++)
    {
        for (j = 0; j <= 25; j++)
        {
            Print (i, j);:
        }


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


void Print (unsigned char 1d, unsigned char 2d)
{
    unsigned char i = 0;

    for (i = 0; i <= 26; i++)
    {
        if (i == 26) fprintf( write, "%c", (6 + i) );
        else fprintf( write, "%c", (97 + i) );
    }
}


