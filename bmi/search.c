#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 256
typedef struct Var
{
    char type[10];
    char name[30];
} Var;
int main(void)
{
    FILE *fp;
    char *filename = "bmi.c";
    char temp;
    char data[N][N];
    char inputName[20][30];
    char conditon[20][N];
    char notCondition[20][N];
    int i = 0;
    int j = 0;
    int mainStart;
    int mainEnd;
    int varNum = 0;
    int varNameStart;
    int varNameEnd;
    int varNameRange;
    int inputNameNum = 0;
    int conditonNum = 0;
    int ampersand = 0;
    int camma;
    int inputNameRange;
    int inputFlag = 0;
    int leftBracesCount = 0;
    int rightBracesCount = 0;
    int leftParenthesis;
    int rightParenthesis;
    int condition_range;
    Var vars[30];
    fp = fopen(filename, "r");
    memset(data, 0, sizeof(data));
    if (fp == NULL)
    {
        fprintf(stderr, "%sのオープンに失敗しました.\n", filename);
        return -1;
    }
    while ((temp = fgetc(fp)) != EOF)
    {
        if (temp == '\n')
        {
            data[i][j] = '\n';
            i++;
            j = 0;
        }
        else
        {
            data[i][j] = temp;
            j++;
        }
    }
    fclose(fp);
    for (i = 0; i < N; i++)
    {
        if (strstr(data[i], "main("))
        {
            mainStart = i;
        }
    }
    for (i = mainStart + 1; i < N; i++)
    {
        if (strstr(data[i], "{"))
        {
            leftBracesCount++;
        }
        if (strstr(data[i], "}"))
        {
            rightBracesCount++;
        }
        if (leftBracesCount == rightBracesCount)
        {
            mainEnd = i;
            break;
        }
    }
    for (i = mainStart + 1; i < mainEnd; i++)
    {
        if (strstr(data[i], "double "))
        {
            for (j = 0; j < 40; j++)
            {
                if (data[i][j] == 'e' && data[i][j + 1] == ' ')
                {
                    varNameStart = j + 2;
                }
                if (data[i][j] == ';')
                {
                    varNameEnd = j;
                    break;
                }
            }
            varNameRange = varNameEnd - varNameStart;
            strcpy(vars[varNum].type, "double");
            strncpy(vars[varNum].name, data[i] + varNameStart, varNameRange);
            varNum++;
        }
        else if (strstr(data[i], "int "))
        {
            for (j = 0; j < 40; j++)
            {
                if (data[i][j] == 't' && data[i][j + 1] == ' ')
                {
                    varNameStart = j + 2;
                }
                if (data[i][j] == ';')
                {
                    varNameEnd = j;
                    break;
                }
            }
            varNameRange = varNameEnd - varNameStart;
            strcpy(vars[varNum].type, "int");
            strncpy(vars[varNum].name, data[i] + varNameStart, varNameRange);
            varNum++;
        }
        else if (strstr(data[i], "char "))
        {
            for (j = 0; j < 40; j++)
            {
                if (data[i][j] == 'r' && data[i][j + 1] == ' ')
                {
                    varNameStart = j + 2;
                }
                if (data[i][j] == ';')
                {
                    varNameEnd = j;
                    break;
                }
            }
            varNameRange = varNameEnd - varNameStart;
            strcpy(vars[varNum].type, "char");
            strncpy(vars[varNum].name, data[i] + varNameStart, varNameRange);
            varNum++;
        }
        else if (strstr(data[i], "float "))
        {
            for (j = 0; j < 40; j++)
            {
                if (data[i][j] == 't' && data[i][j + 1] == ' ')
                {
                    varNameStart = j + 2;
                }
                if (data[i][j] == ';')
                {
                    varNameEnd = j;
                    break;
                }
            }
            varNameRange = varNameEnd - varNameStart;
            strcpy(vars[varNum].type, "float");
            strncpy(vars[varNum].name, data[i] + varNameStart, varNameRange);
            varNum++;
        }
    }
    for (i = 0; i < varNum; i++)
    {
        if (i < varNum - 1)
        {
            printf("%s %s, ", vars[i].type, vars[i].name);
        }
        else
        {
            printf("%s %s\n", vars[i].type, vars[i].name);
        }
    }
    printf("%dから%dまで\n", mainStart, mainEnd);
    //scanfから入力変数を見つける
    // for (i = mainStart; i < mainEnd; i++)
    // {
    //     if (strstr(data[i], "scanf"))
    //     {
    //         for (j = 0; data[i][j]; j++)
    //         {
    //             if (data[i][j] == ',')
    //             {
    //                 camma = j;
    //             }
    //             if (data[i][j] == '&')
    //             {
    //                 ampersand = 1;
    //             }
    //             if (data[i][j] == ')')
    //             {
    //                 rightParenthesis = j;
    //             }
    //         }
    //         if (ampersand == 1)
    //         {
    //             inputNameRange = rightParenthesis - camma - 3;
    //             strncpy(inputName[inputNameNum],
    //                     data[i] + camma + 3, inputNameRange);
    //             inputName[inputNameNum][inputNameRange] = '\0';
    //             printf("%s\n", inputName[inputNameNum]);
    //             inputNameNum++;
    //         }
    //         else
    //         {
    //             inputNameRange = rightParenthesis - camma - 2;
    //             strncpy(inputName[inputNameNum],
    //                     data[i] + camma + 2, inputNameRange);
    //             inputName[inputNameNum][inputNameRange] = '\0';
    //             printf("%s\n", inputName[inputNameNum]);
    //             inputNameNum++;
    //         }
    //         ampersand = 0;
    //     }
    // }
    // for (i = mainStart; i < mainEnd; i++)
    // {
    //     for (j = 0; j < inputNameNum; j++)
    //     {
    //         if (strstr(data[i], inputName[j]) && inputFlag < inputNameNum)
    //         {
    //             printf("%s", data[i]);
    //             inputFlag++;
    //         }
    //     }
    // }
    for (i = mainStart; i < mainEnd; i++)
    {
        if (strstr(data[i], "if"))
        {
            for (j = 0; data[i][j]; j++)
            {
                if (data[i][j] == '(')
                    leftParenthesis = j;
                if (data[i][j] == ')')
                    rightParenthesis = j;
            }
            condition_range = rightParenthesis - leftParenthesis - 1;
            strncpy(conditon[conditonNum],
                    data[i] + leftParenthesis + 1, condition_range);
            conditon[conditonNum][condition_range] = '\0';
            notCondition[conditonNum][0] = '!';
            notCondition[conditonNum][1] = '(';
            strncpy(notCondition[conditonNum] + 2,
                    conditon[conditonNum], condition_range);
            notCondition[conditonNum][condition_range + 2] = ')';
            notCondition[conditonNum][condition_range + 3] = '\0';
            printf("%s\n", conditon[conditonNum]);
            printf("%s\n", notCondition[conditonNum]);
            conditonNum++;
        }
    }
    return 0;
}