#include <stdio.h>

/* min�֐��̐錾 */
int min(int x, int y);

int main(void)
{
      int num1;
      int num2;
      int ans;

      printf("1�Ԗڂ̐�������͂��Ă��������B\n");
      scanf("%d", &num1);

      printf("2�Ԗڂ̐�������͂��Ă��������B\n");
      scanf("%d", &num2);

      ans = min(num1, num2);

      printf("�ŏ��l��%d�ł��B\n", ans);

      return 0;
}

/* min�֐��̒�` */
int min(int x, int y)
{
      if (x < y)
            return x;
      else
            return y;
}
