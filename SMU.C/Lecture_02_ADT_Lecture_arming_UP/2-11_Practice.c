#include <stdio.h>

//1에서 10까지의 합을 정렬시켜 출력하는 프로그램
int main() {
	int sum = 0;
	for (int i = 1; i < 11; i++) {
		
		sum = sum + i;

		printf("%2d   ->   %2d\n", i, sum);
	}

	return 0;

}