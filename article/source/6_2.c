#include <stdio.h>

int main(void)
{
   int num = 0;
   int sum = 0;

   do{
      printf("�e�X�g�̓_������͂��Ă��������B(0�ŏI��)\n");
      scanf("%d", &num);
      sum += num;
   }while(num);

   printf("�e�X�g�̍��v�_��%d�_�ł��B\n", sum);

   return 0;
}
