#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
화씨온도 <->섭씨온도 변환 프로그램
변환 공식은 구글에서..
*/
int main(void) {

	float Fahrenheit;
	float Celsius;
	printf("화씨온도를 입력하세요 : ");

	scanf("%f", &Fahrenheit);

	Celsius = ((float)5 / 9) * (Fahrenheit - 32);

	printf("섭씨온도는 %.2f도입니다.",Celsius);

	return 0;
}