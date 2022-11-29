#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define CHAR_QUA    10000        // 最大文字数
#define READ_FILE   "in.txt"     // 入力ファイル
#define WRITE_FILE  "out.txt"    // 出力ファイル

int main ()
{
    char one_buf = 0;
    char two_buf = 0;
    char txt[CHAR_QUA] = {};
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
            txt[in_max] = one_buf;
            in_max ++;
        }
    }

    /* 入力ファイルを閉じる ----------------------------*/
    fclose(read);


    /* 文字の出現頻度を求める */
    for (j = 0; j <= in_max; j++)   //all txt
    {
        for (i = 0; i <= 25; i++)   //txt f [i]
        {
            if ( txt[j] == (65 + i)  ||  txt[j] == (97 + i) )
            {
                for (k = 0; k <= 25; k++)   //one f [k]
                {
                    if ( one_buf == (65 + k)  ||  one_buf == (97 + k) )
                    {
                        for (l = 0; l <= 25; l++)   //two f [l]
                        {
                            if ( two_buf == (65 + l)  ||  two_buf == (97 + l) ) fleq[i][k][l] ++;
                        }
                        if (two_buf == 32)
                        {
                            fleq[i][k][26] ++;
                        }
                    }
                }
                if (one_buf == 32)
                {
                    for (l = 0; l <= 25; l++)   //two f [l]
                    {
                        if ( two_buf == (65 + l)  ||  two_buf == (97 + l) ) fleq[i][26][l] ++;
                    }
                    if (two_buf == 32)
                    {
                        fleq[i][26][26] ++;
                    }
                }
            }
        }
        if (txt[j] == 32)
        { 
            for (k = 0; k <= 25; k++)   //one f [k]
            {
                if ( one_buf == (65 + k)  ||  one_buf == (97 + k) )
                {
                    for (l = 0; l <= 25; l++)   //two f [l]
                    {
                        if ( two_buf == (65 + l)  ||  two_buf == (97 + l) ) fleq[26][k][l] ++;
                    }
                    if (two_buf == 32)
                    {
                        fleq[26][k][26] ++;
                    }
                }
            }
            if (one_buf == 32)
            {
                for (l = 0; l <= 25; l++)   //two f [l]
                {
                    if ( two_buf == (65 + l)  ||  two_buf == (97 + l) ) fleq[26][26][l] ++;
                }
                if (two_buf == 32)
                {
                    fleq[26][26][26] ++;
                }
            }
        }
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
