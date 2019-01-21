#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 256

int main(void) {
    FILE *fp;
    char *filename = "bmi.c";
    char temp, data[N][N],conditon[20][N],NOT_condition[20][N];
    int i, j = 0;
    int conditon_num = 0;
    int left_parenthesis;
    int right_parenthesis;
    int condition_range;
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
    fclose(fp);
    for (i = 0; i < N; i++) {
        if(strstr(data[i],"if")){
            for(j = 0; data[i][j]; j++){
                    if(data[i][j]=='(')left_parenthesis=j;
                    if(data[i][j]==')')right_parenthesis=j;
                }
            condition_range = right_parenthesis-left_parenthesis-1;
            strncpy(conditon[conditon_num],
            data[i]+left_parenthesis+1,condition_range);
            conditon[conditon_num][condition_range] = '\0';
            NOT_condition[conditon_num][0] = '!';
            NOT_condition[conditon_num][1] = '(';
            strncpy(NOT_condition[conditon_num]+2,
            conditon[conditon_num],condition_range);
            NOT_condition[conditon_num][condition_range+2] = ')';
            NOT_condition[conditon_num][condition_range+3] = '\0';
            printf("%s\n",conditon[conditon_num]);
            printf("%s\n",NOT_condition[conditon_num]);
            conditon_num++;
        }
    }
    return 0;
}