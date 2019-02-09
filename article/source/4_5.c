#include <stdio.h>

int main(void)
{
    int sum = 0;
    int num = 0;

    printf("科目1の点数を入力してください。\n");
    scanf("%d", &num);
    sum += num;

    printf("科目2の点数を入力してください。\n");
    scanf("%d", &num);
    sum += num;

    printf("科目3の点数を入力してください。\n");
    scanf("%d", &num);
    sum += num;

    printf("科目4の点数を入力してください。\n");
    scanf("%d", &num);
    sum += num;

    printf("科目5の点数を入力してください。\n");
    scanf("%d", &num);
    sum += num;

    printf("5科目の合計点は%d点です。\n", sum);
    printf("5科目の平均点は%f点です。\n", (double)sum / 5);

    return 0;
}
