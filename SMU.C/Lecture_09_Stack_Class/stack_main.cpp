#include "stack_class.h"
#include <iostream>
//MAX는 5입니다.
int main() {
	Stack S;
	S.Create();
	S.Pop();
	S.Push(3);
	S.Push(4);
	printf("스택은 비었나요? : %d (1이면 True,0이면 False)\n", S.IsEmpty());
	S.Push(5);
	S.Push(6);
	S.GetTop();
	S.Pop();
	S.GetTop();
	S.Push(7);
	S.Push(8);
	printf("스택은 꽉 찼나요? : %d (1이면 True,0이면 False)\n", S.IsFull());
	S.Push(10);
	S.GetTop();
	S.GetSize();
	
	S.Destroy();

}
