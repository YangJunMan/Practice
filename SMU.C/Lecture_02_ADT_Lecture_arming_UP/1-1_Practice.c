#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//정수형 변수에 값을 받아 합을 출력하는 프로그램
int main(void) {

	int FirstNumber, SecondNumber, result;
	printf("정수 입력 : ");

	//scanf로 입력 받기
	scanf_s("%d %d", &FirstNumber, &SecondNumber); 
	result = FirstNumber + SecondNumber;

	//printf으로 출력
	printf("%d와 %d의 합은 %d입니다.", FirstNumber, SecondNumber, result); 

	return 0;	
}