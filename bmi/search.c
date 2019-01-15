#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 256

int main(void) {
    FILE *fp;
    char *filename = "bmi.c";
    char readline[N] = {'\0'};
    int i, j = 0;
    char temp, data[N][N];
    fp = fopen(filename, "r");
    memset(data, 0, sizeof(data));
    if (fp == NULL) {
        fprintf(stderr, "%sのオープンに失敗しました.\n", filename);
        return -1;
    }
    while((temp = fgetc(fp)) != EOF){
        if (temp == '\n') {
            data[i][j] = '\n';
            i++;
            j = 0;
        } else {
            data[i][j] = temp;
            j++;
        }
    }
    for (i = 0; i < N; i++) {
        printf("%s", data[i]);
    }
    fclose(fp);
    return 0;
}