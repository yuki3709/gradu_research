/* header files */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* macros */
#define N 256

/* main */
int main(void) {
    FILE *fp;
    char *filename = "bmi.c";
    char readline[N] = {'\0'};
    char condition[N] = {'\0'};

    /* ファイルのオープン */
    if ((fp = fopen(filename, "r")) == NULL) {
        fprintf(stderr, "%sのオープンに失敗しました.\n", filename);
        exit(EXIT_FAILURE);
    }

    /* ファイルの終端まで文字を読み取り表示する */
    while ( fgets(readline, N, fp) != NULL ) {
        if(strstr(readline, "else if")){
            strncpy(condition, readline+11, strlen(readline));
            printf("%s", condition);
            printf(" \n");
        }
        else if(strstr(readline, "if")){
            strncpy(condition, readline+5, strlen(readline));
            printf("%s", condition);
            printf(" \n");
        }
    }

    /* ファイルのクローズ */
    fclose(fp);

    return EXIT_SUCCESS;
}