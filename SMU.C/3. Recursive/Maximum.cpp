#include <stdio.h>

int findKth(int* a, int k) {
	if (k == 1) {
		int max = 0;
		for (int i = 0; i < 8; i++) {
			if (max < a[i]) {
				max = a[i];
			}
		}
		return max;
	} //이것도 재귀함수는 맞겠지?그런데 이렇게 쓰면 재귀함수를 쓰는 이유가 있나?

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