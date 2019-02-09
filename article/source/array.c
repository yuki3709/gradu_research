#include <stdio.h>

int main(void)
{
    int test[5];

    printf("1人目のテストの点数を整数で入力してください。\n");
    scanf("%d", &test[0]);
    printf("2人目のテストの点数を整数で入力してください。\n");
    scanf("%d", &test[1]);
    printf("3人目のテストの点数を整数で入力してください。\n");
    scanf("%d", &test[2]);
    printf("4人目のテストの点数を整数で入力してください。\n");
    scanf("%d", &test[3]);
    printf("5人目のテストの点数を整数で入力してください。\n");
    scanf("%d", &test[4]);

    for (int i = 0; i < 5; i++)
    {
        printf("%d番目の生徒は%d点です。\n", i + 1, test[i]);
    }
    return 0;
}