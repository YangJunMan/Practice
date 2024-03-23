#include <stdio.h>

int findKth(int* a, int k) {
	//1번째로 큰 수(제일 큰 수) 구하기는 일반 for문으로.
	if (k == 1) {
		int max = 0;
		//a[i]가 max보다 크다면, max값 변경
		for (int i = 0; i < 8; i++) {
			if (max < a[i]) {
				max = a[i];
			}
		}
		return max;
	}
	//n번째로 큰 수를 재귀함수를 이용해 구합니다.
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
	} //재귀함수를 쓰는 이유는? 더 알아볼것..
}

int main() {
	printf("하나의 정수를 입력하세요 : ");

	int A[8] = { 10,7,2,8,3,1,9,6 };
	int num;
	scanf("%d", &num);
	printf("%d번째 큰 수는 %d 입니다.\n", num, findKth(A, num));
}
