#include <stdio.h>
int main(void)
{
    int num1;
    int num2;
    printf("2�̐�������͂��Ă��������B\n");
    scanf("%d", &num1);
    scanf("%d", &num2);
    if (num1 < num2)
    {
        printf("%d���%d�̂ق����傫���l�ł��B\n", num1, num2);
    }
    else if (num1 > num2)
    {
        printf("%d���%d�̂ق����傫���l�ł��B\n", num2, num1);
    }
    else
    {
        printf("2�̐��͓����l�ł��B\n");
    }
    return 0;
}