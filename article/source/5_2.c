#include <stdio.h>
int main(void)
{
    int num1;
    int num2;
    printf("2つの整数を入力してください。\n");
    scanf("%d", &num1);
    scanf("%d", &num2);
    if (num1 < num2)
    {
        printf("%dより%dのほうが大きい値です。\n", num1, num2);
    }
    else if (num1 > num2)
    {
        printf("%dより%dのほうが大きい値です。\n", num2, num1);
    }
    else
    {
        printf("2つの数は同じ値です。\n");
    }
    return 0;
}