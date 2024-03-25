#include <stdio.h>

//연산기호와 숫자를 입력받아 계산하는 프로그램
int main(){

	char giho;
	
	int a, b;

	printf("입력(연산기호, 숫자1, 숫자2) : ");
	scanf("%c %d %d", &giho, &a, &b);

	if (giho == '+') {
		printf("연산결과 : %d\n", a + b);
	}
	else if (giho == '-') {
		printf("연산결과 : %d\n", a - b);
	}
	else if (giho == '*') {
		printf("연산결과 : %d\n", a * b);
	}
	else if (giho == '/') {
		printf("연산결과 : %d\n", a / b);
	}
	else {
		printf("올바른 기호를 입력해주세요.");
	}
	
	return 0;

}

