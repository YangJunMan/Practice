#include <stdio.h>

//재귀함수 이용하기
int Sum(int i) {
	if (i==1) {
		return 1;
	}
	else {
		return (i+Sum(i-1));
	}
}

int main() {
	printf("하나의 정수를 입력하세요 : ");
	int num;
	scanf("%d", &num);
	printf("5까지의 합 : %d",Sum(num));
}