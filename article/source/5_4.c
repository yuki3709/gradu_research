#include <stdio.h>

int main(void)
{
   char res;

   printf("A`C‚Ü‚Å‚Ì•¶š‚ğ“ü—Í‚µ‚Ä‚­‚¾‚³‚¢B\n");
   res = getchar();
   
   if(res == 'A' || res == 'B' || res == 'C'){
      printf("³‰ğ‚Å‚·B\n");
   }
   else{
      printf("ŠÔˆá‚¢‚Å‚·B\n");
   }
   return 0;
}
