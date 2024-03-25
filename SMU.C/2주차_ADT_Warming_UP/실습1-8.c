#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//국어, 영어, 수학점수를 받아 평균을 구하는 프로그램
int main(void) {
	float korean,english,math;
	printf("국어 : ");
	scanf("%f", &korean);
	printf("영어 : ");
	scanf("%f", &english);
	printf("수학 : ");
	scanf("%f", &math);

	float result = (korean + english + math) / 3;
	printf("평균 : %.1f", result);

	return 0;
}