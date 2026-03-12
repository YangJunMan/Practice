#include <stdio.h>
#include <iostream>
#include "5-1.h"
using namespace std;

int main() {

	struct mylist A;
	int item;
	//리스트를 1부터 받을 것이기 때문에 취소
	Insert(&A, 0, 10); 
	
	//리스트 1번에 11을 저장
	Insert(&A, 1, 11); 
	
	//리스트 2번에 12을 저장
	Insert(&A, 2, 12); 
	
	//리스트 1번에 13을 저장하여 리스트가 총 3개,기존의 리스트가 밀려남
	Insert(&A, 1, 10); 
	
	//중간 점검
	Retrieve(&A, 2, &item);
	
	//리스트 1번을 비워둠.
	Delete(&A,1); 
	
	// 리스트 1번이 비워졌는지 확인.
	IsEmpty(&A, 1); 
	
	// 리스트 1번을 삭제함
	Destroy(&A, 1); 
	
	// 리스트 1번 자리로 잘 이동했는지?
	IsEmpty(&A, 1); 

	// 10이 지워져 리스트는 2개로 판별
	Length(&A); 

	//리스트 1번에는 11, 리스트 2번에는 12가 저장되어있음.
	Retrieve(&A, 2, &item); 

	//item값이 잘 복사되었는지 확인

	printf("item값 : %d\n", item); 
	
	return 0;
}