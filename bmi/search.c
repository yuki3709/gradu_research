#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 256

int main(void) {
    FILE *fp;
    char *filename = "bmi.c";
    char readline[N] = {'\0'};
    char *condition;
    char con[N];
    char *left_parenthesis;
    char *right_parenthesis;
    fp = fopen(filename, "r");

    if (fp == NULL) {
        fprintf(stderr, "%sのオープンに失敗しました.\n", filename);
        exit(EXIT_FAILURE);
    }

    while ( fgets(readline, N, fp) != NULL ) {
        if(strstr(readline, "if")){
            left_parenthesis = strstr(readline, "(");
            condition = left_parenthesis;
            right_parenthesis = strstr(condition, ")");
            con = condition;
            printf("%s", condition);
            printf("%s", right_parenthesis);
        }
    }

    fclose(fp);

    return EXIT_SUCCESS;
}