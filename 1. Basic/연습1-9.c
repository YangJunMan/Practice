#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//두 정수를 입력받아.. 를 계산하는 프로그램

int main(void) {
	printf("두 정수를 입력 : ");
	int a, b;
	scanf("%d %d", &a, &b);
	int result = (a + b) / (a - b);
	printf("결과 : %d", result);

	return 0;
}