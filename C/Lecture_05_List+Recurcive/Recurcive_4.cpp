#include <stdio.h>

//재귀함수를 이용해 max값, n번째로 큰 수 구하기
int findKth(int* a, int k) {
	if (k == 1) {
		int max = 0;
		for (int i = 0; i < 8; i++) {
			if (max < a[i]) {
				max = a[i];
			}
		}
		return max;
	}

	/*
	왜 재귀함수를 공부해야 할까 ?
	(특히 현업에서) 코드를 심플하게 구현할 수 있게된다.
	*/
	else {
		int max = 0;
		for (int i = 0; i < 8; i++) {
			if (max < a[i]) {
				max = a[i];
			}
		}
		for (int i = 0; i < 8; i++) {
			if (max == a[i]) {
				a[i] = 0;
			}
		}
		return findKth(a, k - 1);
	}
}

int main() {
	printf("하나의 정수를 입력하세요 : ");

	int A[8] = { 10,7,2,8,3,1,9,6 };
	int num;
	scanf("%d", &num);
	printf("%d번째 큰 수는 %d 입니다.\n", num, findKth(A, num));
}