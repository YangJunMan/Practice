#include <stdio.h>

//재귀함수를 이용해 팩토리얼 구현
int Factorial(int i) {
	if (i == 1) {
		return 1;
	}
	else {
		return (i*Factorial(i-1));
	}
}

int main() {
	printf("하나의 정수를 입력하세요 : ");
	int num;

	scanf("%d", &num);
	printf("%d까지의 곱 : %d",num, Factorial(num));
}