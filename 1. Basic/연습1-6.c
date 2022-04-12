#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//두 정수를 입력받고 몫과 나머지 계산
int main(void) {
	int a, b;
	printf("두 수를 입력하세요 : ");
	scanf("%d %d", &a, &b);
	printf("몫 : %d \n", a / b);
	printf("나머지 : %d", a % b);

	return 0;
}