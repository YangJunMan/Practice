#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//화씨온도, 섭씨온도 변환 프로그램
int main(void) {
	float hwa;
	float sup;
	printf("화씨온도를 입력하세요 : ");

	scanf("%f", &hwa);

	sup = ((float)5 / 9) * (hwa - 32);

	printf("섭씨온도는 %.2f도입니다.",sup);

	return 0;
}