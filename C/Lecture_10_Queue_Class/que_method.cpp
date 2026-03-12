#include "que_class.h"

//Que생성
void queClass::Create() {
	printf("Que를 생성합니다.초기 Front값 : 0, 초기 Rear값 : -1\n");
	Front = 0;
	Rear = -1;
}

bool queClass::IsEmpty() {
	return (Front > Rear);
}

bool queClass::IsFull() {
	return (Rear+1 == MAX);
}

void queClass::Add(int item) {
	if (IsFull()==1) {
		printf("Add할 수 없습니다.\n");
	}
	else {
		Queue[++Rear] = item;
		printf("%d번째 Rear에 Queue를 삽입합니다.\n", Rear);
	}
}

void queClass::Remove() {
	printf("Remove합니다. Remove되는 수 : %d \n", Queue[Front++]);
}

void queClass::GetSize() {
	printf("현재 크기 : %d 입니다. \n", Rear+1);
}

void queClass::GetFront() {
	printf("현재 Front에 있는 수 : %d\n", Queue[Front]);
}

void queClass::Destroy() {
	for (int i = 0; i < Rear + 1; i++) {
		Queue[i] = NULL;
	}
	Front = NULL;
	Rear = NULL;
}