#include <stdio.h>

int main(void)
{
    int sum = 0;
    int num = 0;

    printf("�Ȗ�1�̓_������͂��Ă��������B\n");
    scanf("%d", &num);
    sum += num;

    printf("�Ȗ�2�̓_������͂��Ă��������B\n");
    scanf("%d", &num);
    sum += num;

    printf("�Ȗ�3�̓_������͂��Ă��������B\n");
    scanf("%d", &num);
    sum += num;

    printf("�Ȗ�4�̓_������͂��Ă��������B\n");
    scanf("%d", &num);
    sum += num;

    printf("�Ȗ�5�̓_������͂��Ă��������B\n");
    scanf("%d", &num);
    sum += num;

    printf("5�Ȗڂ̍��v�_��%d�_�ł��B\n", sum);
    printf("5�Ȗڂ̕��ϓ_��%f�_�ł��B\n", (double)sum / 5);

    return 0;
}
