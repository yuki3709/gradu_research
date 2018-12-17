//尾崎　裕樹　1515015
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*BMIの定義*/
double BMI(double x, double y){
	return y / ((x * x) / 10000);
}
int main(void){
	double height, weight, bmi = 0;
	printf("身長と体重を入力してください。\n");
	scanf("%lf, %lf", &height, &weight);

	if (height <= 0 || weight <= 0) {
		printf("0より大きい値を入力してください。\n");
		return 0;
	}
	bmi = BMI(height, weight);

	printf("BMIは%fです。\n", bmi);

	if (bmi >= 25) {
		printf("あなたは肥満です。\n");
	}else if (bmi < 18.5) {
		printf("あなたは低体重です。\n");
	}else {
		printf("あなたは普通体重です。\n");
	}
	return 0;
}