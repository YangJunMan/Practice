#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
//양의 정수의 값을 받아 8진수와 16진수로 출력하는 프로그램
int eight(int a) { 
	int tempA = a;
	int count = 0;
	
	while (1) {

		tempA = tempA / 8;
		count++;
		if (tempA == 0) {
			break;
		}
	}													//배열의 크기를 알아내기 위한 count
	int* ejinsu = malloc(sizeof(int) * count);          //배열을 이용해서 모든 경우의 수의 양수를 입력받기 위해 동적할당

	for (int i = 0; i < count; i++) {
		ejinsu[i] = a % 8;
		a = a / 8;										//배열에 몫의 나머지값 저장
	}
	printf("8진수 : ");
	for (int i = count - 1; i >= 0; i--) {
		printf("%d", ejinsu[i]);						//몪의 나머지들을 역순으로 출력하면 진수 변환(배열의 끝값은 NULL이라 띔), 출력완료
	}
};		//8진수 출력	

int sixteen(int a) {
	char hex[17] = "0123456789ABCDEF";					//아하! 이런방법이!-구글참조
	int tempA = a;
	int count = 0;

	while (1) {

		tempA = tempA / 16;
		count++;
		if (tempA == 0) {
			break;
		}
	}													//배열의 크기를 알아내기 위한 count
	int* ejinsu = malloc(sizeof(int) * count);          //배열을 이용해서 모든 경우의 수의 양수를 입력받기 위해 동적할당

	for (int i = 0; i < count; i++) {	

			ejinsu[i] = hex[a%16];						//배열에 몫의 나머지값 16진수로 저장
		a = a / 16;										
	}
	printf("16진수 : ");
	for (int i = count - 1; i >= 0; i--) {
		printf("%c", ejinsu[i]);						//몪의 나머지들을 역순으로 출력하면 진수 변환(배열의 끝값은 NULL이라 띔), 출력완료
	}
};		//16진수 출력

int main(void) {
	printf("양의 정수 : ");
	int no;
	scanf("%d", &no);
	//%o와 %x를 사용하지 않았을 때.. 원시시대 방식으로
	eight(no);
	printf("\n");
	sixteen(no);
	

	return 0;
}  //%o랑 %x쓰면 간단하던데 그런걸 원하셨던 것 일까요..?