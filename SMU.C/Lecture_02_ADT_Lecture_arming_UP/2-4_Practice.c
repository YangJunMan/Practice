#include <stdio.h>

//세 영문자의 아스키코드값 비교
int main() {
	
	printf("3개의 영문자를 입력하세요 : ");
	
	char alpha1, alpha2, alpha3;

	scanf("%c %c %c", &alpha1, &alpha2, &alpha3);
	

	//첫번째가 제일 작을경우
	if (alpha2 > alpha1 && alpha3 > alpha1) 
		printf("결과 : %c\n", alpha1);

	//두번째가 가장 작을경우
	if (alpha1 > alpha2 && alpha3 > alpha2) 
		printf("결과 : %c\n", alpha2);

	//세번째가 가장 작을경우
	if (alpha1 > alpha3 && alpha2 > alpha3) 
		printf("결과 : %c\n", alpha3);


	return 0;

}
