#include<stdio.h>

//1~100사이의 임의의 양의 정수에 대해 소수의 개수와 합을 출력하는 프로그램.
int main() {

    // for문을 나와서도 i, j 값을 사용할 수 있도록 선언
    int i = 0, j = 0;   

    int num;
    int result = 0;
    int amount = 0;

    printf("수를 입력해주세요 : ");

    scanf("%d", &num);
    printf("소수 : ");
    for (i = 2; i <= num; i++) {
        
        for (j = 2; j < i; j++) {
            if (i % j == 0)
                break;
        }
        if (i == j) {              
            printf("%d ", i);    
            result = result + i;
            amount++;
        }
    }

    printf("\n소수의 합 : %d",result);
    printf("\n소수의 개수 : %d", amount);

    return 0;
}