#include <stdio.h>
#define NUM 5

int main(void)
{
      int test[NUM];
      int max;
      int i;
      int j;

      max = 0;

      printf("�e�X�g�̓_������͂��Ă��������B\n");
      for (i = 0; i < NUM; i++)
      {
            scanf("%d", &test[i]);

            if (max < test[i])
                  max = test[i];
      }

      for (j = 0; j < NUM; j++)
      {
            printf("%d�Ԗڂ̐l�̓_����%d�ł��B\n", j + 1, test[j]);
      }

      printf("�ō��_��%d�_�ł��B\n", max);

      return 0;
}
