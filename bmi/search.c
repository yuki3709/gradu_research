#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 256

int main(void) {
    FILE *fp;
    char *filename = "bmi.c";
    char readline[N] = {'\0'};
    char condition;
    char con[N];
    int i;
    int left_parenthesis=0;
    int right_parenthesis=0;
    fp = fopen(filename, "r");

    if (fp == NULL) {
        fprintf(stderr, "%sのオープンに失敗しました.\n", filename);
        exit(EXIT_FAILURE);
    }

    while ( fgets(readline, N, fp) != NULL ) {
        // if(strstr(readline, "if")){
        //     left_parenthesis = strstr(readline, "(");
        //     condition = left_parenthesis;
        //     right_parenthesis = strstr(condition, ")");
        //     con = condition;
        //     printf("%s", condition);
        //     printf("%s", right_parenthesis);
        // }
        if(strstr(readline, "if")){
                for(i = 0; readline[i]; i++){
                    if(readline[i]=='(')left_parenthesis=i;
                    // printf("左%d",left_parenthesis);
                    if(readline[i]==')')right_parenthesis=i;
                    // printf("右%d",right_parenthesis);
            }
                // for(i=left_parenthesis+1; right_parenthesis-1; i++){
                //     printf("%c",readline[i]);            
                // }
                
        }
    }

    fclose(fp);

    return EXIT_SUCCESS;
}