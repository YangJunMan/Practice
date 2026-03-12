#include "list_class.h"

//리스트 생성
void node_list::Node_create(int max) {
	if (Max_num != -1) {
		cout << "기존에 있는 리스트를 destroy 해주십시오" << endl;
		return;
	}
	else if (max < 1) {
		cout << "올바른 최대값을 입력해주십시오" << endl;
		return;
	}
	
	head = (Node*)malloc(sizeof(Node));
	head->Next=NULL;
	head->data = 0;
	Max_num = max;
}

//리스트 삽입
void node_list::Node_add(int position, int data) {
	Nptr head_temp=head;
	
	if (Max_num == -1) {
		cout << "리스트를 create 해주십시오" << endl;
		return;
	}
	else if (position > head->data + 1 || position < 1) {
		cout << "position이 초과하였습니다" << endl;
		return ;
	}
	for (int i = 0; i < position; i++) {
		if (i + 1 == position) {
			cout << "리스트가 없습니다" << endl;
			return;
		}
			Nptr temp;
			temp = (Node*)malloc(sizeof(Node));
		
			temp->data = data;
			//temp 노드의 Next 필드에 head_temp 노드의 Next 필드 값을 할당하여 새로운 노드를 리스트에 연결
			temp->Next = head_temp->Next;
			//head_temp 노드의 Next 필드에 temp 노드를 할당하여 새로운 노드를 리스트에 삽입
			head_temp->Next = temp;
		}
		//head 포인터를 다음 노드로 이동
		head_temp = head_temp->Next;
		head->data++;
}
	
	
//리스트 삭제
void node_list::Node_destroy() {
	if (Max_num == -1) {
		cout << "리스트를 create 해주십시오" << endl;
		return;
	}
	Nptr head_temp = head;

	while (head_temp != NULL) {
		Nptr temp;
		temp = head_temp;
		head_temp = head->Next;
		free(temp);
	}
	head = NULL;
	Max_num = -1;
}

//리스트의 값 삭제
void node_list::Node_delete(int position) {
	Nptr head_temp = head;
	
	if (Max_num == -1) {
		cout << "리스트를 create 해주십시오" << endl;
		return;
	}
	else if (position > head->data  || position < 1) {
		cout << "position이 이상해용!" << endl;
		return;
	}

	for (int i = 0; i < position; i++) {
		if (i + 1 == position) {
			Nptr temp;
			temp = head_temp->Next;
			head_temp->Next = head_temp->Next->Next;
			free(temp);
		}
		head_temp = head_temp->Next;
	}
	
	head->data--;
}

//리스트 출력
void node_list::Node_display() {
	Nptr head_temp = head->Next;
	while (head_temp!=NULL) {
		cout << head_temp->data<<" ";
		head_temp = head_temp->Next;
	}
}