#include <stdio.h>

int main(void)
{
   char res;

   printf("A�`C�܂ł̕�������͂��Ă��������B\n");
   res = getchar();
   
   if(res == 'A' || res == 'B' || res == 'C'){
      printf("�����ł��B\n");
   }
   else{
      printf("�ԈႢ�ł��B\n");
   }
   return 0;
}
