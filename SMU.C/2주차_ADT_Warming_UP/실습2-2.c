#include <stdio.h>

//영어 대문자, 소문자 변환
int main() {
	char alpha;
	printf("임의의 알파벳을 입력하세요 : ");
	scanf("%c", &alpha);

	//아스키코드표 참고
	if (alpha >= 'A' && alpha <= 'Z') {
		printf("변환결과 : %c", alpha + 32);
	}
	else if ((alpha >= 'a' && alpha <= 'z')) {
		printf("변환결과 : %c", alpha - 32);
	}
	else {
		printf("알파벳을 입력해주세요.");
	}

	return 0;
}