#include <stdio.h>

int main(void)
{
   int res;

   printf("��������͂��Ă��������B\n");
   scanf("%d", &res);
   
   if((res % 2) == 0)
      printf("%d�͋����ł��B\n", res);
   else
      printf("%d�͊�ł��B\n", res);

   return 0;
}
