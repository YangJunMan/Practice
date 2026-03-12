#include "list_class.h"

//정적 리스트 생성
void List::create(int max_num) {
	if (A_position != -2) {
		cout << "먼저 리스트를 destroy를 해주십시오" << endl;
		return;
	}
	A_position = 0;
	Max = max_num;
	list = list_node;
}

//동적 리스트 생성
void List::create_Dynamic(void) {
	if (A_position != -2) {
		cout << "먼저 리스트를 destroy를 해주십시오 : " << endl;
		return;
	}
	cout << "Max값을 입력하십시오";
	cin >> Max;
	list_node_dynamic = (LIST_NODE*)malloc(sizeof(LIST_NODE) * Max);
	A_position = 0;
	list = list_node_dynamic;
	for (int i = 0; i < Max; i++)
		list[i].Data = 0;
}

//정적 리스트 삭제
void List::destroy(void) {
	for (int i = 0; i < 100; i++)
		list_node[i].Data = 0;//-
	A_position = -2;
	cout << "리스트를 삭제했습니다." << endl;
	list = 0;
}

//동적 리스트 삭제
void List::destroy_Dynamic(void){
	list = 0;
	free(list_node_dynamic);
	A_position = -2;
	cout << "리스트를 삭제했습니다." << endl;
}

//리스트에 삽입
void List::insert(int position, int data) {
	if (A_position == -2) {
		cout << "리스트를 create 해주십시오" << endl;
			return;
	}
	

	if (A_position == Max)
		cout << "리스트가 모두 찼습니다." << endl;
	else if (position<1 || position>A_position + 1)
		cout << "현재 있는 리스트의 범위에 벗어나있습니다" << endl;
	else {
		if (position < A_position + 1) {
			for (int i = A_position - 1; i >= position - 1; i--)
				list[i + 1].Data = list[i].Data;
		}
		list[position - 1].Data = data;
		A_position++;
	}


}

//리스트의 수 삭제
void List::Delete(int position) {
	if (A_position == -2) {
		cout << "리스트를 create 해주십시오" << endl;
		return;
	}
	else if (position<1 || position>A_position)
		cout << "현재 있는 리스트의 범위에 벗어나있습니다" << endl;
	else {
		for (int i = position - 1; i <= A_position; i++)
			list[i].Data = list[i + 1].Data;
		list[A_position - 1].Data = 0;
		A_position--;
	}
}

//길이 반환
int List::Length(void) {
	int length=0;
	if (A_position == -2) {
		cout << "리스트를 create 해주십시오" << endl;
		return 0;
	}
	
	return A_position;
}

//리스트 공간 확인
void List::isempty(void) {
	if (A_position == -2) {
		cout << "리스트를 create 해주십시오" << endl;
		return;

	}
	if (A_position == 0)
		cout << "리스트는 비어있습니다." << endl;
}

//리스트 포화도 확인
void List::isfull(void) {
	if (A_position == -2) {
		cout << "리스트를 create 해주십시오" << endl;
		return;

	}
	if (A_position == Max)
		cout << "리스트는 가득 차있습니다." << endl;
}

//데이터 반환
int List::get_item(int position){
	return list[position-1].Data;
}
