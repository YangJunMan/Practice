#include <stdio.h>

//단순 반복 출력 프로그램
int main() {
	char a;
	while (1) {
		printf("한 문자를 입력하세요 : ");
		scanf_s(" %c", &a);

		//q 입력시 종료
		if (a == 'q' || a == 'Q') {
			break;
		}
		printf("입력한 문자 : %c\n", a);

	}

	return 0;
}