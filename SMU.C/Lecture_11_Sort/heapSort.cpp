#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define max 11

//최대힙
void heapify(int arr[], int k, int N) {
	//가장 끝 노드의 부모노드를 기준(k)으로 잡고 두 자식노드 확인하기
	int left = 2 * k;
	int right = 2 * k + 1;
	int bigger;
	int temp;
	if (right <= N) {
		if (arr[left] > arr[right]) {
			bigger = left;

		}
		else {
			bigger = right;
		}
	}
	else if (left <= N) {
		bigger = left;
	}
	//끝의경우
	else return;

	//자식노드가 부모노드보다 크다면, SWAP 실시
	if (arr[bigger] > arr[k]) {
		temp = arr[k];
		arr[k] = arr[bigger];
		arr[bigger] = temp;
		heapify(arr, bigger, N);
	}

}

void buildHeap(int arr[], int N) {
	//배열 끝의 자식노드,의 부모노드 찾기
	for (int i = N / 2; i >= 1; i--) {
		heapify(arr, i, N);
	}
}

void heapSort(int arr[], int N) {
	int temp;
	/*
	1. buildHeap에서 배열 끝의 자식노드,의 부모노드 찾기
	2. buildHeap 내부의 heapify에서 힙(부모노드가 자식노드보다 큰 이진트리) 만들기 완료
	*/
	buildHeap(arr, N);
	/*
	3. 배열의 끝 값과 가장 큰 값의 자리를 바꾼다. (배열의 마지막 인덱스에 가장 큰 수가 저장된다)
	4. 가장 큰 값이 저장된 배열의 마지막 인덱스는 제외하고, 다시 headify 한다
	*/
	for (int i = N; i >= 2; i--) {
		temp = arr[1];
		arr[1] = arr[i];
		arr[i] = temp;
		heapify(arr, 1, i - 1);

		printf(" <<%d단계>> ", N - i + 1);
		for (int j = 1; j < max; j++) {
			if (arr[j] == arr[i]) {
				printf("[%2d", arr[j]);
			}
			else
				printf(" %2d", arr[j]);

		}
		printf("\n");
	}
}

int queue[max];
int front, rear;

void init_queue(void) {
	front = rear = 1;
}

int put(int k) {
	queue[rear] = k;
	rear = ++rear % max;
	return k;
}

int get(void) {
	int i;
	if (front == rear) {
		printf("\n Queue  underflow");
		return -1;
	}
	i = queue[front];
	front = ++front % max;
	return i;
}


void priority() {
	int i;
	int j = 1;
	init_queue();
	int num;
	printf("수를 입력하여주세요. 0은 출력입니다. \n");
	while (1) {
		scanf("%d", &num);
		if (num == 0) {
			buildHeap(queue, max - 1);
			printf("%d를 겟합니다.", queue[1]);
			queue[1] = NULL;
			j--;
	}
		else {
			put(num);
			j++;
		}
		buildHeap(queue, max - 1);
			for (int k = 1; k < j; k++) {
				printf("%d ", queue[k]);
			}
			printf("\n");
		
		}
}

void radixSort(int *arr, int n) {
	int result[max], maxValue = 0;
	int exp = 1;
	int many= 1;
	for (int i = 0; i < n; i++) { //가장 큰수 구하기
		if (arr[i] > maxValue) {
			maxValue = arr[i];}
	}
	// 가장 큰 수의 자릿수 계산!
	while (maxValue / exp > 0) { 
		int bucket[10] = { 0 };
		// 각각의 자릿수 배열 처리
		for (int i = 0; i < n; i++) { 
			bucket[arr[i] / exp % 10]++; 
		}
		// 누적 계산 : 결과 배열을 만들기 위해서!	
		for (int i = 1; i < 10; i++) { 
			bucket[i] += bucket[i - 1]; 
		} 
		//같은 자릿수 끼리는 순서를 유지
		for (int i = n - 1; i >= 0; i--) { 
			result[--bucket[arr[i] / exp % 10]] = arr[i];
		}
		// 기본 배열 다시 만들기
		for (int i = 0; i < n; i++) { 
			arr[i] = result[i];
		} 		
		
		//다음 자리수로 넘어가기
		exp *= 10; 
		
		printf("<<%d단계>>", many++);
		
		for (int i = 0; i < n; i++) {
			printf("%d ", arr[i]);
		}
		printf("\n");
	}
}

int main() {
	while (1) {
		int num;
		int arr[] = { 0,48,8,65,40,1,5,12,7,42,11 };
		printf("1번 : 힙정렬 구현하기 \n2번 : 우선순위 큐 만들기\n3번 : 기수정렬 하기");
		scanf("%d", &num);

		if (num == 1) {
			printf(" 기존배열 : ");
			for (int j = 1; j < max; j++) {
				printf("%2d ", arr[j]);
			}
			printf("\n");

			printf("  초기 힙 : ");
			buildHeap(arr, max - 1);
			for (int j = 1; j < max; j++) {
				printf("%2d ", arr[j]);
			}


			heapSort(arr, max - 1);
		}

		if (num == 2) {
			priority();
		}

		if (num == 3) {
			int arr3[] = { 42641,25741,53454,31546,21047,53116,46721,13674,75621,15376 };
			radixSort(arr3, max - 1);
		}

	}
}