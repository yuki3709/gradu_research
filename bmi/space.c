/* header files */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* functions */
int Trim(char *s);

/* main */
int main(void) {
    int ret;
    char snoopy[] = "   SNOOPY   ";

    ret = Trim(snoopy);
    printf("変換後: \"%s\"\n", snoopy);
    printf("削除した空白: %d文字\n", ret);

    return EXIT_SUCCESS;
}

/*
 * 文字列の先頭と末尾にある空白を削除する
 * @param[in] s 対象文字列
 * @return 削除した空白の数を返す
 */
int Trim(char *s) {
    int i;
    int count = 0;

    /* 空ポインタか? */
    if ( s == NULL ) { /* yes */
        return -1;
    }

    /* 文字列長を取得する */
    i = strlen(s);

    /* 末尾から順に空白でない位置を探す */
    while ( --i >= 0 && s[i] == ' ' ) count++;

    /* 終端ナル文字を付加する */
    s[i+1] = '\0';

    /* 先頭から順に空白でない位置を探す */
    i = 0;
    while ( s[i] != '\0' && s[i] == ' ' ) i++;
    strcpy(s, &s[i]);

    return i + count;
}