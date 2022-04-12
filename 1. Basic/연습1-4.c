#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//정수 5개를 입력받아 일렬로 출력하고 그 평균을 출력하는 프로그램
int main(void) {
	int num1, num2, num3, num4, num5;					//정수만 받아야한다면 if문 상용해도..

	printf("다섯개의 정수를 입력하세요 : ");
	
	scanf("%d %d %d %d %d", &num1, &num2, &num3, &num4, &num5);

	int sum = (num1 + num2 + num3 + num4 + num5);
	float result = sum / 5.0f;

	printf("%10d\n%10d\n%10d\n%10d\n%10d\n", num1, num2, num3, num4, num5);     //숫자가 10자리를 넘길때는...모르겠..
	printf("------------\n");
	printf("%10.2f", result);

}