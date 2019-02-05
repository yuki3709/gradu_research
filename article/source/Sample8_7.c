#include <stdio.h>

/* sum関数の定義 */
int sum(int x, int y)
{
    int z;

    z = x + y;

    return z;
}

int main(void)
{
    int num1;
    int num2;
    int ans;

    printf("1番目の整数を入力してください。\n");
    scanf("%d", &num1);

    printf("2番目の整数を入力してください。\n");
    scanf("%d", &num2);

    ans = sum(num1, num2);

    printf("合計は%dです。\n", ans);

    return 0;
}
