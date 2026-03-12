#include <stdio.h>

// 두 숫자의 절댓값의 합을 구하시오
int main() {
	
	printf("두 수를 입력하세요 : ");
	int num[2];
	int result=0;
	for (int i = 0; i < 2; i++) {
		scanf("%d", &num[i]);
		if (num[i] < 0) {
			num[i] = num[i] * (-1);
		}
		result = result + num[i];
	}
	printf("결과 : %d", result);
	
	return 0;

}