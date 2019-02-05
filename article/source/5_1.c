#include <stdio.h>

int main(void)
{
   int res;

   printf("®”‚ğ“ü—Í‚µ‚Ä‚­‚¾‚³‚¢B\n");
   scanf("%d", &res);
   
   if((res % 2) == 0)
      printf("%d‚Í‹ô”‚Å‚·B\n", res);
   else
      printf("%d‚ÍŠï”‚Å‚·B\n", res);

   return 0;
}
