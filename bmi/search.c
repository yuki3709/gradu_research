#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 256

int main(void) {
    FILE *fp;
    char *filename = "bmi.c";
    char readline[N] = {'\0'};
    char condition;
    char variable1[20],variable2[20];
    int i;
    int var1_type_check, var2_type_check = 0;
    int variable_count = 0;
    int left_parenthesis;
    int right_parenthesis;
    int comma_num;
    int address_num;
    fp = fopen(filename, "r");

    if (fp == NULL) {
        fprintf(stderr, "%sのオープンに失敗しました.\n", filename);
        return -1;
    }
    while ( fgets(readline, N, fp) != NULL ) {
        //入力される変数を見つける
         if(strstr(readline, "scanf")){
            variable_count++;
                for(i = 0; readline[i]; i++){
                    if(readline[i]==',')comma_num=i;
                    if(readline[i]=='&')address_num=i;
                    if(readline[i]==')')right_parenthesis=i;
                }
                if(variable_count==1){
                    for(i=comma_num+3; i<right_parenthesis; i++){
                        if(i!=address_num)variable1[i-(comma_num+3)]=readline[i];
                }
                printf("%s\n",variable1);
                }
                if(variable_count==2){
                    for(i=comma_num+3; i<right_parenthesis; i++){
                        if(i!=address_num)variable2[i-(comma_num+3)]=readline[i]; 
                }
                printf("%s\n",variable2);
                }
        }
    }
    fclose(fp);
    fp = fopen(filename, "r");

    if (fp == NULL) {
        fprintf(stderr, "%sのオープンに失敗しました.\n", filename);
        return -1;
    }
    while ( fgets(readline, N, fp) != NULL ) {
        //入力のデータ構造
        if(strstr(readline, variable1)){
            if(var1_type_check==0){
                // printf("a");
            }
        }
        if(strstr(readline, "scanf")){
                for(i = 0; readline[i]; i++){
                    if(readline[i]==',')comma_num=i;
                    if(readline[i]=='&')address_num=i;
                    if(readline[i]==')')right_parenthesis=i;
                }
                for(i=comma_num+1; i<right_parenthesis; i++){
                    if(i==comma_num+1)printf("(");
                    if(i!=address_num)printf("%c",readline[i]);
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

    return 0;
}