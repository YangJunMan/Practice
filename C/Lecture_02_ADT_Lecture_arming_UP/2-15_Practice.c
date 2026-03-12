#include <stdio.h>


//1~9까지 구구단 곱셈표를 출력하는 프로그램
int main() {

	for (int i = 0; i < 10; i++) {
		if (i == 0) {
			//좌측 상단은 *표시
			printf(" * ");

			for (int j = 1; j < 10; j++) {
				printf("%2d ", j);
			}
		}
		else {
			printf("%2d ", i);
			for (int j = 1; j < 10; j++) {
				printf("%2d ", i*j);
			}
		}
		

		printf("\n");
	}

	return 0;
}