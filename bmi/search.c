
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 256

typedef struct Var
{
    char type[10];
    char name[30];
} Var;
int loadData(char *filename, char **data);
int mallocF(char **function);
int mallocCF(char **callFunction);
void loadVar(char *line, Var *var);
void loadVars(char **data, int start, int end, Var *vars, int *varsCount);
void loadFunction(char **data, char **function, char *functionName, int *functionCount);
int countMainStartIndex(char **data);
int countMainEndIndex(char **data, int startIndex);
int main(void)
{
    char *filename = "bmi.c";
    int i = 0;
    int j = 0;
    int inputNameNum = 0;
    int conditionNum = 0;
    int ampersand = 0;
    int camma;
    int inputNameRange;
    int inputFlag = 0;
    int leftParenthesis;
    int rightParenthesis;
    int conditionRange;
    int functionCount = 0;
    int varsCount = 0;
    int varsCheck[30];
    int noInputVarsNum = 0;
    int callFunctionNum = 0;
    int unknownVarsCount = 0;
    int *unknownVarsNum = (int *)malloc(sizeof(int) * 10);
    char noInputVars[10][30];
    char inputName[10][30];
    char conditon[20][N];
    char notCondition[20][N];
    char **data = malloc(sizeof(char *) * N);
    char **function = malloc(sizeof(char *) * N);
    char *functionName = (char *)malloc(sizeof(char) * 20);
    char **callFunction = malloc(sizeof(char *) * N);
    Var vars[20];
    if (loadData(filename, data) == -1)
    {
        free(data);
        return -1;
    }
    if (mallocF(function) == -1)
    {
        free(function);
        return -1;
    }
    if (mallocCF(callFunction) == -1)
    {
        free(callFunction);
        return -1;
    }
    int mainStart = countMainStartIndex(data);
    int mainEnd = countMainEndIndex(data, mainStart);
    loadVars(data, mainStart + 1, mainEnd, vars, &varsCount);
    loadFunction(data, function, functionName, &functionCount);

    for (i = mainStart; i < mainEnd; i++)
    {
        if (!strstr(data[i], "scanf"))
        {
            continue;
        }

        for (j = 0; data[i][j]; j++)
        {
            if (data[i][j] == ',')
            {
                camma = j;
            }
            if (data[i][j] == '&')
            {
                ampersand = 1;
            }
            if (data[i][j] == ')')
            {
                rightParenthesis = j;
            }
        }
        inputNameRange = rightParenthesis - camma - 2 - ampersand;
        strncpy(inputName[inputNameNum], data[i] + camma + 2 + ampersand, inputNameRange);
        inputName[inputNameNum][inputNameRange] = '\0';
        printf("%s\n", inputName[inputNameNum]);
        inputNameNum++;
        ampersand = 0;
    }
    for (i = mainStart; i < mainEnd; i++)
    {
        if (strstr(data[i], "if"))
        {
            for (j = 0; data[i][j]; j++)
            {
                if (data[i][j] == '(')
                {
                    leftParenthesis = j;
                }
                if (data[i][j] == ')')
                {
                    rightParenthesis = j;
                }
            }
            conditionRange = rightParenthesis - leftParenthesis - 1;
            strncpy(conditon[conditionNum],
                    data[i] + leftParenthesis + 1, conditionRange);
            conditon[conditionNum][conditionRange] = '\0';
            notCondition[conditionNum][0] = '!';
            notCondition[conditionNum][1] = '(';
            strncpy(notCondition[conditionNum] + 2,
                    conditon[conditionNum], conditionRange);
            notCondition[conditionNum][conditionRange + 2] = ')';
            notCondition[conditionNum][conditionRange + 3] = '\0';
            printf("%s\n", conditon[conditionNum]);
            printf("%s\n", notCondition[conditionNum]);
            conditionNum++;
        }
    }
    for (i = 0; i < varsCount; i++)
    {
        varsCheck[i] = 0;
        for (j = 0; j < inputNameNum; j++)
        {
            if (strcmp(vars[i].name, inputName[j]) == 0)
            {
                varsCheck[i]++;
            }
        }
        if (varsCheck[i] == 0)
        {
            strcpy(noInputVars[noInputVarsNum], vars[i].name);
            noInputVarsNum++;
        }
    }
    for (i = 0; i < conditionNum; i++)
    {
        for (j = 0; j < noInputVarsNum; j++)
        {
            if (strstr(conditon[i], noInputVars[j]))
            {
                if (unknownVarsCount != 0)
                {
                    unknownVarsCount++;
                }
                unknownVarsNum[unknownVarsCount] = j;
            }
        }
    }
    if (functionCount != 0)
    {
        for (i = mainStart; i < mainEnd; i++)
        {
            for (j = 0; j < unknownVarsCount + 1; j++)
            {
                if (strstr(data[i], noInputVars[unknownVarsNum[j]]) &&
                    strstr(data[i], functionName) && !strstr(data[i], "printf"))
                {
                    strcpy(callFunction[callFunctionNum], data[i]);
                    callFunctionNum++;
                }
            }
        }
        for (i = 0; i < callFunctionNum; i++)
        {
            printf("a");
            printf("%s", callFunction[i]);
        }
    }
    free(data);
    free(function);
    free(callFunction);
    free(unknownVarsNum);
    free(functionName);
    return 0;
}
int loadData(char *filename, char *data[N])
{
    FILE *fp = fopen(filename, "r");
    if (fp == NULL)
    {
        fprintf(stderr, "%sのオープンに失敗しました.\n", filename);
        return -1;
    }
    char *arr = malloc(sizeof(int) * N * N);

    for (int i = 0; i < N; i++)
    {
        data[i] = arr + i * N;
    }
    // free(arr);
    char temp;
    int i = 0, j = 0;
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
    return 0;
}
int mallocF(char *function[N])
{
    char *arr = malloc(sizeof(int) * N * N);
    for (int i = 0; i < N; i++)
    {
        function[i] = arr + i * N;
    }
}
int mallocCF(char *callFunction[N])
{
    char *arr = malloc(sizeof(int) * N * N);
    for (int i = 0; i < N; i++)
    {
        callFunction[i] = arr + i * N;
    }
}
void loadVar(char *line, Var *var)
{
    int i;
    int varNameStart = 0;
    int varNameRange;
    if (strstr(line, "int "))
    {
        for (i = 0; i < N - 1; i++)
        {
            if (line[i] == 't' && line[i + 1] == ' ')
            {
                varNameStart = i + 2;
            }
            if (line[i] == ';')
            {
                varNameRange = i - varNameStart;
                break;
            }
        }
        strcpy(var->type, "int");
        strncpy(var->name, line + varNameStart, varNameRange);
    }
    if (strstr(line, "char "))
    {
        for (i = 0; i < N - 1; i++)
        {
            if (line[i] == 'r' && line[i + 1] == ' ')
            {
                varNameStart = i + 2;
            }
            if (line[i] == ';')
            {
                varNameRange = i - varNameStart;
                break;
            }
        }
        strcpy(var->type, "char");
        strncpy(var->name, line + varNameStart, varNameRange);
    }
    if (strstr(line, "float "))
    {
        for (i = 0; i < N - 1; i++)
        {
            if (line[i] == 't' && line[i + 1] == ' ')
            {
                varNameStart = i + 2;
            }
            if (line[i] == ';')
            {
                varNameRange = i - varNameStart;
                break;
            }
        }
        strcpy(var->type, "float");
        strncpy(var->name, line + varNameStart, varNameRange);
    }
    if (strstr(line, "double "))
    {
        for (i = 0; i < N - 1; i++)
        {
            if (line[i] == 'e' && line[i + 1] == ' ')
            {
                varNameStart = i + 2;
            }
            if (line[i] == ';')
            {
                varNameRange = i - varNameStart;
                break;
            }
        }
        strcpy(var->type, "double");
        strncpy(var->name, line + varNameStart, varNameRange);
    }
}
void loadVars(char **data, int start, int end, Var *vars, int *varsCount)
{
    int i;
    int count = 0;
    for (i = start; i < end; i++)
    {
        loadVar(data[i], (vars + count));
        if (vars[count].name[0] != '\0')
        {
            count++;
            *varsCount = count;
        }
    }
    for (i = 0; i < count; i++)
    {
        if (i < count - 1)
        {
            printf("%s %s, ", vars[i].type, vars[i].name);
        }
        else
        {
            printf("%s %s\n", vars[i].type, vars[i].name);
        }
    }
}
void loadFunction(char **data, char **function, char *functionName, int *functionCount)
{
    int functionNum = 0;
    int i;
    int j;
    int k = 0;
    int functionFlag = 0;
    int braceCount = 0;
    int nameFlag;
    int nameStart;
    int nameRange;
    for (i = 0; i < N; i++)
    {
        if (data[i][0] != ' ' && data[i][0] != '\t' && data[i][0] != '\v' && data[i][0] != '\f' &&
            data[i][0] != '\r' && data[i][0] != '{' && data[i][0] != '}' && data[i][0] != '\0' &&
            data[i][0] != '#' && data[i][0] != '\n' && data[i][0] != '/' && !strstr(data[i], "main(") &&
            !strstr(data[i], "struct") && !strstr(data[i], "typedef"))
        {
            *functionCount++;
        }
    }
    if (*functionCount == 0)
    {
        return;
    }
    for (i = 0; i < N; i++)
    {
        if (data[i][0] != ' ' && data[i][0] != '\t' && data[i][0] != '\v' && data[i][0] != '\f' &&
            data[i][0] != '\r' && data[i][0] != '{' && data[i][0] != '}' && data[i][0] != '\0' &&
            data[i][0] != '#' && data[i][0] != '\n' && data[i][0] != '/' && !strstr(data[i], "main(") &&
            !strstr(data[i], "struct") && !strstr(data[i], "typedef"))
        {
            nameFlag = 0;
            functionFlag = 1;
            for (j = 0; j < N; j++)
            {
                if (data[i][j] == ' ' && nameFlag == 0)
                {
                    nameStart = j + 1;
                    nameFlag++;
                }
                if (data[i][j] == '(' && nameFlag == 1)
                {
                    nameRange = j - nameStart;
                    strncpy(functionName, data[i] + nameStart, nameRange);
                    printf("%s\n", functionName);
                    nameFlag++;
                    break;
                }
            }
        }
        if (functionFlag == 1 && strstr(data[i], "{"))
        {
            braceCount++;
        }
        if (functionFlag == 1)
        {
            strcpy(function[k], data[i]);
            printf("%s", function[k]);
        }

        k++;

        if (functionFlag == 1 && strstr(data[i], "}"))
        {
            braceCount--;
            if (braceCount == 0)
            {
                functionFlag = 0;
                return;
            }
        }
    }
}
int countMainStartIndex(char **data)
{
    int i = 0;
    int mainStart = 0;
    for (i = 0; i < N; i++)
    {
        if (strstr(data[i], "main("))
        {
            return i;
        }
    }
    return 0;
}
int countMainEndIndex(char **data, int startIndex)
{
    int i;
    int braceCount = 0;
    for (i = startIndex; i < N; i++)
    {
        if (strstr(data[i], "{"))
        {
            braceCount++;
        }
        if (strstr(data[i], "}"))
        {
            braceCount--;
            if (braceCount == 0)
            {
                return i;
            }
        }
    }
    return startIndex;
}
