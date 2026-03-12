#include "list_class.h"

//리스트 생성
nptr List::Create(int max,nptr p) {
	listmax = max;
	listcount = 0;
	p = (node*)malloc(sizeof(node));
	return p;
}

//리스트가 비었는가?
bool List::IsEmpty() {
	if (listcount == 0)
		return true;
	else
		return false;
}

//리스트가 포화상태인가?
bool List::IsFull() {
	if (listcount >= listmax)
		return true;
	else
		return false;
}

//리스트에 삽입 *위치*값*nptr
nptr List::Insert(int position, int data, nptr p) {
	nptr tmp = NULL, q = NULL;
	if (position > listmax)
		printf("포지션 리스트길이 초과.\n");
	if (IsFull())
		printf("리스트가 가득참.\n");
	else if ((position > listcount + 1) || position < 1)
		printf("이격된 위치 삽입 불허.\n");
	//리스트 처음 생성시
	else if (listcount == 0 && position == 1) {
		tmp = (node*)malloc(sizeof(node));
		tmp->data = data;
		p = tmp;
		p->next = NULL;
		listcount++;
	}
	//리스트의 끝에 삽입시
	else if (position > listcount) {
		tmp = p;
		for (int i = 1; i < position - 1; i++)
			tmp = tmp->next;
		tmp->next = (node*)malloc(sizeof(node));
		tmp->next->data = data;
		tmp->next->next = NULL;
		listcount++;
	}
	//리스트 중간에 삽입시
	else if (position <= listcount && position > 1) {
		//기존 노드 임시저장
		tmp = p;
		//새로운 노드 생성
		q = (node*)malloc(sizeof(node));
		q->data = data;

		for (int i = 1; i < position - 1; i++)

		//기존 노드의 next 주소 저장
		tmp = tmp->next;

		// 앞 -> 삽입 ( q->data, q->next )
		q->next = tmp->next;

		// 삽입 ( q->data, q->next ) -> 뒤
		tmp->next = q;

		listcount++;
	}
	//리스트 맨 앞에 생성
	else if (position == 1) {
		q = (node*)malloc(sizeof(node));
		q->data = data;
		tmp = p;
		q->next = tmp;
		p = q;

		listcount++;
	}

	return p;
}

//리스트의 값 삭제
nptr List::Delete(int position, nptr p) {
	nptr tmp = NULL, q = NULL;
	if (IsEmpty())
		printf("리스트가 비어있습니다.\n");
	else if (position > listcount || position < 0) {
		printf("잘못된 위치 지정.\n");
		return p;
	}
	else if (position > 1) {
		tmp = p;
		q = p;
		for (int i = 1; i < position; i++)
			tmp = tmp->next;
		for (int i = 1; i < position - 1; i++)
			q = q->next;
		q->next = tmp->next;
		free(tmp);
		listcount--;
	}
	else if (position == 1) {
		tmp = p;
		p = p->next;
		free(tmp);
		listcount--;
	}
	return p;
}

//리스트 값 출력
void List::List_view(nptr p) {
	nptr temp = p;
	if(IsEmpty())
		printf("리스트가 비어있습니다.\n");
	else{
	printf("리스트 : ");
	while (temp != NULL) {
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
	}
}

//리스트 삭제
void List::Destroy(nptr p) {
	if (listcount == 0)
		printf("리스트가 비어있습니다.\n");
	else {
		printf("리스트 모두 초기화.\n");
		listcount = 0; listmax = 0;
		free(p);
	}

}

//리스트 길이 반환
int List::Length() {
	printf("리스트의 길이 : %d\n", listcount);
	return listcount;
}