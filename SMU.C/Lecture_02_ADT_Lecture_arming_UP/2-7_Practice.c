#include <stdio.h>


//물건 값과 개수를 입력받은 후, 10%를 할인한 금액을 구하는 프로그램
int main(){
	
	int price, number, result;

	printf("물건값 : ");
	scanf("%d", &price);

	printf("개  수 : ");
	scanf("%d", &number);

	result = price * number;

	if (result >= 5000)
		printf("금  액 : %d\n", result - (result / 10));

	else if (0<result < 5000)
		printf("금  액 : %d\n", result);
	else {
		printf("올바른 금액을 입력해주세요.");
	}

	return 0;
}
