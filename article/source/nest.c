#include <stdio.h>
int main(void)
{
    int num1;
    int num2;
    printf("2つの整数を入力してください。\n");
    scanf("%d", &num1);
    scanf("%d", &num2);
    if (num1 > num2)
    {
        printf("%dは%dより大きい値です。\n", num1, num2);
        if (num1 == 0)
        {
            printf("1つ目の値は0です。\n");
        }
    }
    else
    {
        printf("%dは%d以下です。\n", num1, num2);
    }
    return 0;
}