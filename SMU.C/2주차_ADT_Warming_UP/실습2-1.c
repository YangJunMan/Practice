#include <stdio.h>

//24시간제 to 12시간제
int main() {
	printf("시간입력<24시간표기로> : ");
	int time;
	scanf("%d", &time);
	if (time < 0 || time>24) {
		printf("올바른 수를 입력해주세요.");
	}
	else {
		if (time < 12) {
			printf("오전 %d시 입니다.", time);
		}
		else {
			printf("오후 %d시 입니다.", time - 12);
		}
	}

	return 0;
	
}