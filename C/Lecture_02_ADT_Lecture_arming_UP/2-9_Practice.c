#include <stdio.h>

//1에서 100까지의 합을 구하는 프로그램
int main() {
	int i, sum = 0;

	for (i = 1; i <= 100; i++) {
		sum = sum + i;

	}

	printf("합 : %d\n ", sum);

	return 0;
}

