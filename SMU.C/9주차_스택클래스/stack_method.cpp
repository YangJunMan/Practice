#include "stack_class.h"
#include <iostream>

//스택 생성
void Stack::Create() {
	Top = -1;
}

//스택 공간 확인
bool Stack::IsEmpty() {
	return Top == -1;
}

//스택 포화도 확인
bool Stack::IsFull() {
	return Top == MAX - 1;
}

//스택 쌓기
void Stack::Push(int item) {
	if (IsFull()) {
		printf("스택 쌓기에 실패했습니다.\n");
	}
	else {
		stack[++Top] = item;
		printf("스택을 쌓습니다.\n");
	}

}

//현재 스택의 top에 위치하는 값은?
void Stack::GetTop() {
	printf("현재 Top : %d \n", stack[Top]);
}

//스택 1단 추출
void Stack::Pop() {
	if (IsEmpty()) {
		printf("터트릴 스택이 없습니다.\n");
	}
	else {
		stack[Top] = NULL;
		Top--;
		printf("스택을 Pop합니다\n");
	}
}

//스택 크기 구하기
void Stack::GetSize() {
	printf("현재 스택은 %d개 만큼 쌓여있습니다.\n", Top + 1);
}

//스택 삭제하기
void Stack::Destroy() {
	printf("스택을 파기합니다.\n");
	for (int i = 0; i <= Top; i++) {
		stack[i] = NULL;
	}
	Top = NULL;
}
