#include <stdio.h>

int main(void)
{
   int res;
   char ans;

   printf("���Ԗڂ�I�т܂����H\n");
   printf("��������͂��Ă��������B\n");

   scanf("%d", &res);

   ans = (res==1) ? 'A' : 'B'; 

   printf("%c�R�[�X��I�����܂����B\n", ans);

   return 0;
}
