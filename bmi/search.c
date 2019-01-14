#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 256

int main(void) {
    FILE *fp;
    char *filename = "bmi.c";
    char readline[N] = {'\0'};
    char condition;
    int i;
    int left_parenthesis;
    int right_parenthesis;
    int comma;
    int address;
    fp = fopen(filename, "r");

    if (fp == NULL) {
        fprintf(stderr, "%sのオープンに失敗しました.\n", filename);
        exit(EXIT_FAILURE);
    }
    // while ( fgets(readline, N, fp) != NULL ) {
        
    // }
    while ( fgets(readline, N, fp) != NULL ) {
        //入力のデータ構造
        if(strstr(readline, "scanf")){
                for(i = 0; readline[i]; i++){
                    if(readline[i]==',')comma=i;
                    if(readline[i]=='&')address=i;
                    if(readline[i]==')')right_parenthesis=i;
                }
                for(i=comma+1; i<right_parenthesis; i++){
                    if(i==comma+1)printf("(");
                    if(i!=address)printf("%c",readline[i]);
                    if(i==right_parenthesis-1)printf(")\n");
                }
        }
        //条件文の抜き出し
        if(strstr(readline, "if")){
                for(i = 0; readline[i]; i++){
                    if(readline[i]=='(')left_parenthesis=i;
                    if(readline[i]==')')right_parenthesis=i;
                }
                for(i=left_parenthesis+1; i<right_parenthesis; i++){
                    printf("%c",readline[i]);
                    if(i==right_parenthesis-1)printf("\n");
                }
                printf("!(");
                for(i=left_parenthesis+1; i<right_parenthesis; i++){
                    printf("%c",readline[i]);
                    if(i==right_parenthesis-1)printf(")\n");
                }
        }
    }

    fclose(fp);

    return EXIT_SUCCESS;
}