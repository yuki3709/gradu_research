#include <stdio.h>

int main(void)
{
   int res; 

   printf("整数を入力してください。\n");
   scanf("%d", &res);

   if (res == 1){
      printf("1が入力されました。\n");
   }
   else if(res == 2){
      printf("2が入力されました。\n");
   }
   else{
      printf("1か2を入力してください。\n");
   }

   return 0;
}
