#include <stdio.h>

int main(void)
{
    double height;
    double weight;

    printf("�g������͂��Ă��������B\n");
    scanf("%lf", &height);

    printf("�̏d����͂��Ă��������B\n");
    scanf("%lf", &weight);

    printf("�g����%f�Z���`�ł��B\n", height);
    printf("�̏d��%f�L���ł��B\n", weight);

    return 0;
}
