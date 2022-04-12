#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//백 단위의 정수를 입력받아 각 자리값을 출력
int main(void) {
	int a;
	int hun;
	int ten;
	int one;
	printf("입력 : ");
	scanf("%d", &a);

	hun = a / 100;					//백의자리
	ten = (a % 100) / 10;			//10의자리
	one = (a % 100) % 10;			//1의자리
	 if (99 < a < 1000) {
		printf("백의자리 : %d \n십의자리 : %d \n일의자리 : %d",hun,ten,one);
	}
	else {
		printf("백 단위의 정수를 입력해주세요.");
	} 
	return 0;
}