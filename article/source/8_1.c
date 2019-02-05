#include <stdio.h>

/* min関数の宣言 */
int min(int x, int y);

int main(void)
{
      int num1;
      int num2;
      int ans;

      printf("1番目の整数を入力してください。\n");
      scanf("%d", &num1);

      printf("2番目の整数を入力してください。\n");
      scanf("%d", &num2);

      ans = min(num1, num2);

      printf("最小値は%dです。\n", ans);

      return 0;
}

/* min関数の定義 */
int min(int x, int y)
{
      if (x < y)
            return x;
      else
            return y;
}
