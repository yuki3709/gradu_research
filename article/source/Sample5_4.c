#include <stdio.h>

int main(void)
{
   int res; 

   printf("��������͂��Ă��������B\n");
   scanf("%d", &res);

   if (res == 1){
      printf("1�����͂���܂����B\n");
   }
   else if(res == 2){
      printf("2�����͂���܂����B\n");
   }
   else{
      printf("1��2����͂��Ă��������B\n");
   }

   return 0;
}
