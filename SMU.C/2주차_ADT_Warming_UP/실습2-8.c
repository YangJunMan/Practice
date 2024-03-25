#include <stdio.h>

//500원, 100원, 50원, 10원의 잔돈 반환 계산 프로그램.
int main(){
	
	int a, b, result;

	printf("입금액 : ");
	scanf("%d", &a);

	printf("물건값 : ");
	scanf("%d", &b);

	result = a - b;

	printf("잔  돈 : %d원\n", result);

	if (result < a)
		printf("500원짜리 %d개\n", result / 500);
		printf("100원짜리 %d개\n", (result % 500) / 100);
		printf("50원짜리 %d개\n", ((result % 100) / 50);
		printf("10원짜리 %d개\n", (((result % 50) / 10);

	return 0;
}
