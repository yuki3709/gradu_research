#include <stdio.h>

int main(void)
{
    double height;
    double weight;

    printf("身長を入力してください。\n");
    scanf("%lf", &height);

    printf("体重を入力してください。\n");
    scanf("%lf", &weight);

    printf("身長は%fセンチです。\n", height);
    printf("体重は%fキロです。\n", weight);

    return 0;
}
