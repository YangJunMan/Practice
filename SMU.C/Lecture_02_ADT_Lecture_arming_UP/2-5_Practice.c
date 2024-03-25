#include <stdio.h>

//점수에 따른 성적 출력
int main() {
	printf("성적을 입력하세요 : ");

	int k, e, m;
	
	scanf("%d %d %d", &k, &e, &m);

	float result = (float)(k + e + m) / 3;

	printf(" 평균 : %/2f \n", result);

	if (result > 90) {
		printf("아주잘했어요");
	} 
	else if (result > 80) {
		printf("잘했어요");
	}
	else if (result > 70) {
		printf("노력해야겠어요");
	}
	else {
		printf("아주 많이 노력해야겠어요.");
	}

	return 0;

}