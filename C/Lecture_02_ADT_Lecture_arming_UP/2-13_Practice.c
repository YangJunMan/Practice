#include <stdio.h>
#include <string.h>

//입력받은 문자의 개수와, 공백의 개수를 구하는 프로그램
int main() {
	char str[1000]="";
	printf("입력한 문자열 : ");

	//scanf는 공백이 있으면 별도로 입력받아진다.
	gets(str);   
	
	int i = 0;
	int count = 0;
	while (str[i]!=NULL) {
		if (str[i] == ' ') {
			count++;
		}
		i++;
	}
	 
	printf("입력받은 문자의 개수 : %d\n", i);
	printf("공백 문자의 개수 : %d", count);

	return 0;
}