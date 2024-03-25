#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//백 단위의 정수를 입력받아 각 자리값을 출력
int main(void) {
	int number;
	int hun;
	int ten;
	int one;
	printf("입력 : ");
	scanf("%d", &number);

	hun = number / 100;					//백의자리
	ten = (number % 100) / 10;			//10의자리
	one = (number % 100) % 10;			//1의자리
	 if (99 < number < 1000) {
		printf("백의자리 : %d \n십의자리 : %d \n일의자리 : %d",hun,ten,one);
	}
	else {
		printf("백 단위의 정수를 입력해주세요.\n");
	} 
	return 0;
}