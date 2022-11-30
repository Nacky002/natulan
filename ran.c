#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#define CHAR_QUA    100000        // 最大文字数
#define READ_FILE   "in.txt"     // 入力ファイル
#define WRITE_FILE  "out.txt"    // 出力ファイル
#define OUT_QUA     1000

unsigned int Get_random (unsigned int min, unsigned int max);
unsigned char Get_freq (unsigned char elem);

int main ()
{
    char A = 0;
    char one_buf = 0;
    char txt[CHAR_QUA] = {};
    unsigned int in_max = 0;
    unsigned int i = 0;
    unsigned int j = 0;
    unsigned short k = 0;
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


    /* 乱数の初期値設定 */
    srand( (unsigned int)time(NULL) );


    /* 出力ファイルを開く ------------------------------*/
    write = fopen(WRITE_FILE, "w");

    /* 出力ファイルを開く失敗 */
    if (write == NULL)
    {
        perror("\n出力ファイルへのアクセスに失敗しました。\n");
        return 1;
    }

    i = Get_random(0, in_max);
    fprintf(write, "%c", txt[i]);
    A = txt[(i + 1)];
    fprintf(write, "%c", A);

    while (k <= OUT_QUA)
    {
        i = Get_random(0, in_max);

        for (j = (i +  1); j <= in_max; j++)
        {
            if (txt[j] == A)
            {
                A = txt[j + 1];
                fprintf(write, "%c", A);
                break;
            }
        }

        k++;
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


unsigned int Get_random (unsigned int min, unsigned int max)
{
    return min + (unsigned int)( rand() * (max - min + 1.0) / (RAND_MAX + 1.0) );
}


