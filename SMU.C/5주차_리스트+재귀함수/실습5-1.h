#include <stdio.h>
#define Max 100;

typedef struct mylist {
	int num = 0;
	int value[100];
};

/*
* count : 내가 입력할 번호
* data : 내가 입력할 문자
* num : 구조체에 저장될 번호
* value : 구조체에 사용할 문자
*/

void Insert(mylist* stlist, int count, int data) {
	/*
		구조체(my list)에 data를 넣었을때 count값은 몇이었고 몇이될까
	*/
	if ((stlist->num) > 100)
		printf("이미 list는 100개까지 꽉 차있습니다\n");

	else if ((stlist->num - count) < -1 || count < 1) {
		//만약 리스트가 3번까지 있는데 5에 삽입되었을 경우 ?
		printf("리스트를 순서대로 채워주십시오\n");
	}
	else if (stlist->num == 0) {
		//첫 번째 리스트 추가
		stlist->value[0] = data;
		printf("첫 번째 리스트입니다. %d를 입력합니다. \n", data);
		stlist->num = stlist->num + 1;
	}
	else {
		//n번째 리스트에 숫자x 추가
		for (int i = stlist->num; i > count-1; i--) {
			(stlist->value[i]) = (stlist->value[i - 1]);
		}
		stlist->value[count-1] = data;
		printf("%d 번째 리스트에 %d를 입력합니다. \n",count, stlist->value[count-1]);
		stlist->num = stlist->num + 1;
		}
	}

//삭제
void Delete(mylist * stlist, int count) {
	if (stlist->value[count-1]) {
		stlist->value[count-1] = 0;
		printf("%d번째 리스트를 비워둡니다.\n",count);
	}
	else {
		printf("이미 비어있는 번호 입니다.\n");
	}
}

//해당 위치 데이터를 item에 복사
void Retrieve(mylist* stlist, int count, int *item) {
	if ((stlist->num)>count-1) {
		*item = stlist->value[count-1];
		printf("%d번 리스트의 값 %d를 item에 복사합니다.\n",count,stlist->value[count-1]);
		
	}
	else {
		printf("값을 복사하지 못했습니다..\n");
	}
}

//빈 리스트 만들기
void Create(mylist* stlist, int count) {
		if ((stlist->num - count) < -1 || count < 1) {
		printf("올바른 번호를 입력하세요\n");
}
		else {
		for (int i = stlist->num; i > count-1; i--) {
			(stlist->value[i]) = (stlist->value[i - 1]);
		}
		stlist->value[count-1] =0;
		printf("%d번째에 빈 리스트를 생성합니다.\n", count);
		stlist->num = stlist->num + 1;
	}
}

//리스트 삭제하기
void Destroy(mylist* stlist, int count) {
	if ((stlist->num - count) < -1 || count < 1) {
		printf("올바른 번호를 입력하세요\n");
	}
	else {
		for (int i = count-1; i < stlist->num; i++) {
			printf("%d번의 리스트의 %d가 옮겨집니다..\n", i+1, stlist->value[i]);
			(stlist->value[i]) = (stlist->value[i + 1]);
		}
		printf("%d번의 리스트를 삭제합니다.",count);
		printf("%d번의 리스트에는 %d가 왔습니다.\n", count, stlist->value[count-1]);

		//맨 끝의 리스트는 초기화 되어야 함.
		stlist->value[stlist->num] = NULL; 

		stlist->num = stlist->num - 1;

	}
}

//리스트 공간 확인
void IsEmpty(mylist* stlist, int count) {
	if (stlist->value[count-1] == 0) {
		printf("%d번은 빈 리스트 입니다.TRUE \n",count);
	}
	else if (stlist->value[count - 1] == NULL) {
		printf("%d번은 없는 리스트 입니다.", count);
	}
	else {
		printf("%d번은 이미 있는 리스트 입니다.FALSE \n",count);
	}
}

//리스트 길이 확인
void Length(mylist* stlist) {
	printf("%d개의 리스트가 있습니다.\n", stlist->num);
}