#include <stdio.h>

//1에서 100까지 홀수의 합과, 짝수의 합을 출력하는 프로그램
int main() {
	int result = 0;

	for (int i = 1; i <= 100; i++) {
		result = result + i;
		i++;
	}
	printf("홀수의 합 : %d\n", result);

	result = 0;

	for (int i = 0; i <= 100; i++) {
		result = result + i;
		i++;
	}
	printf("짝수의 합 : %d", result);


	return 0;
}