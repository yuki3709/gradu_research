#include <stdio.h>
int even(int num)
{
	return num % 2;
}
int main(void)
{
	int num;
	int mod2;
	printf("整数を入力してください。\n");
	scanf("%d", &num);

	mod2 = even(num);
	if (mod2 == 0)
	{
		printf("偶数です。\n");
	}
	else
	{
		printf("奇数です。\n");
	}
	return 0;
}