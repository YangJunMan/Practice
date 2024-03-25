#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//임의의 실수를 입력받아 2로 나눈 값을 출력하는 프로그램
int main(void) {
	float number;
	printf("실수값을 입력하세요 : ");
	scanf("%f", &number);
	float result = number / 2;

	//.2f로 소수점 2째자리까지
	printf("결과 : %.2f", result);  
	return 0;
}