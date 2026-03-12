#include <stdio.h>

//재귀함수를 이용해 구구단 구현
void Gugu(int i, int j) {
	if (j == 10) {
		return;
	}
	else {
		printf("%d * %d = %d\n",i,j,j*5);
		return Gugu(i, j + 1);
	}
}

int main() {
	printf("하나의 정수를 입력하세요 : ");
	int num;
	scanf("%d",&num);
	Gugu(num,1);

}