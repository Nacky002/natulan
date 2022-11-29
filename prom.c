#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#define MEM_SIZE    1000         // 読み込み可能最大文字数
#define READ_FILE   "in.txt"     // 入力ファイル
#define WRITE_FILE  "out.txt"    // 出力ファイル
#define RANDOM_NUM  1000          // ランダムに生成する文字数

unsigned int Get_random (unsigned int get_min, unsigned int get_max);

unsigned int Get_random (unsigned int get_min, unsigned int get_max)
{
    return get_min + (unsigned int)( rand() * (get_max - get_min + 1.0) / (RAND_MAX + 1.0) );
}



int main ()
{
    char in_buf = 0;
    char* txt = {0};
    unsigned int in_max = 0;
    unsigned int i = 0;
    unsigned int j = 0;
    unsigned int fleq[27] = {0};
    FILE* read = NULL;
    FILE* write = NULL;



    /* 入力ファイル保存用の、配列のメモリ確保 */
    txt = (char*)malloc( sizeof(char) * MEM_SIZE );

    /* 配列のメモリ確保失敗 */
    if (txt == NULL)
    {
        perror("\n配列のメモリ確保に失敗しました。\n");
        return 1;
    }



    /* 入力ファイルを開く ------------------------------*/
    read = fopen(READ_FILE, "r");

    /* 入力ファイルを開く失敗 */
    if (read == NULL)
    {
        perror("\n入力ファイルへのアクセスに失敗しました。\n");
        return 1;
    }

    /* 配列へ入力ファイルを格納 */
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



    /* 頻度を求める */
    for (j = 0; j <= in_max; j++)
    {
        for (i = 0; i <= 25; i++) if ( txt[j] == (65 + i)  ||  txt[j] == (97 + i) ) fleq[i] ++;
        if (txt[j] == 32) fleq[26] ++;
    }



    /* 乱数 */
    srand( (unsigned int)time(NULL) );



    /* 出力ファイルを開く ------------------------------*/
    write = fopen(WRITE_FILE, "w");

    /* 出力ファイルを開く失敗 */
    if (write == NULL)
    {
        perror("\n出力ファイルへのアクセスに失敗しました。\n");
        return 1;
    }

    /* 出力ファイルに入力 */
    for (i = 0; i <= RANDOM_NUM; i++)
    {
        in_buf = txt[ Get_random(0, in_max) ];
        fprintf(write, "%c", in_buf);

        printf("%u = random, %u = in_max\n", Get_random(0, in_max), in_max);
    }

    /* 出力を閉じる ------------------------------------*/
    fclose(write);

    return 0;
}
