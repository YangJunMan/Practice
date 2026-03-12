#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//증가, 감소 연산자를 사용하여 x=5, y=0일때 ..  
int main(void) {
	int x = 5;
	int y = 0;

	//선 증가
	y = ++x;
	printf("y = ++x : y <-- %d, y = %d \n", x, y);
	
	//후 증가
	y = x++;
	printf("y = x++ : y <-- %d, y = %d \n", x, y);
	
	//선 감소
	y = --x;
	printf("y = --x : y <-- %d, y = %d \n", x, y);
	
	//후 감소
	y = x--;
	printf("y = x-- : y <-- %d, y = %d \n", x, y);

	return 0;
}