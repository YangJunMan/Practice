#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

/*
양의 정수의 값을 받아 8진수와 16진수로 출력하는 프로그램
%o랑 %x쓰면 간단하지만.. 해보자
*/
void Octal(int a) {
	int temp = a;
	int count = 0;

	while (1) {
		temp = temp / 8;

		//배열의 크기를 알아내기 위한 count
		count++;

		if (temp == 0) {
			break;
		}
	}

	//배열을 이용해서 8진수 값 저장. 필요한 배열의 길이는 동적할당.
	int* OctalNumber = (int*)malloc(sizeof(int) * count);

	for (int i = 0; i < count; i++) {

		//배열에 몫의 나머지값 저장
		OctalNumber[i] = a % 8;

		a = a / 8;
	}
	printf("8진수 : ");

	//몪의 나머지들을 역순으로 출력하면 진수 변환(배열의 끝값은 NULL이라 띔),
	for (int i = count - 1; i >= 0; i--) {

		//8진수 출력	
		printf("%d", OctalNumber[i]);
	}
	printf("\n");

	//메모리 해제
	free(OctalNumber);
};

void sixteen(int a) {

	//아하! 이런방법이!-구글참조
	char hex[17] = "0123456789ABCDEF";
	int temp = a;
	int count = 0;

	while (1) {

		temp = temp / 16;

		if (temp == 0) {
			break;
		}

		//배열의 크기를 알아내기 위한 count
		count++;
	}

	//배열을 이용해서 16진수 값 저장. 필요한 배열의 길이는 동적할당.
	int* HexaDecimal = (int*)malloc(sizeof(int) * count);

	for (int i = 0; i < count; i++) {

		//배열에 몫의 나머지값 16진수로 저장
		HexaDecimal[i] = hex[a % 16];

		a = a / 16;
	}
	printf("16진수 : ");

	//몪의 나머지들을 역순으로 출력하면 진수 변환(배열의 끝값은 NULL이라 띔),
	for (int i = count - 1; i >= 0; i--) {

		//16진수 출력
		printf("%c", HexaDecimal[i]);
	}
	printf("\n");

	//메모리 해제
	free(HexaDecimal);
};

int main(void) {
	printf("양의 정수를 입력하세요 : ");
	int number;
	scanf("%d", &number);

	//%o와 %x를 사용하지 않았을 때..
	if (number > 8) {
		Octal(number);
	}
	else {
		printf("%d", number);
	}

	if (number > 16) {
		sixteen(number);
	}
	else {
		printf("%d", number);
	}


	return 0;
}