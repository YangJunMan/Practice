#include <iostream>
#include <windows.h>
#define max 10
int time = 1;

//피벗의 값보다 작은 값은 피벗 왼쪽으로. 피벗의 값보다 큰 값은 피벗 오른쪽으로.
int partition1(int arr[], int low, int high) {

	//높은 값을 피벗으로 설정
	int pivot = high;
	//피벗보다 작은 값의 마지막 위치
	int i = low - 1;

	//검사중인 값의 위치
	int j = low;
	int temp;

	while ((j < high)) {
		if (arr[j] < arr[pivot]) {
			i++;
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
		j++;


	}

	temp = arr[i + 1];
	arr[i + 1] = arr[pivot];
	arr[pivot] = temp;


	printf("<<%d단계>> ", time++);
	for (int k = 0; k < max; k++) {
		if ((k == low)) {
			printf("[%2d ", arr[k]);
		}
		else if (k == high) {
			printf(" %2d]", arr[k]);
		}
		else {
			printf(" %2d ", arr[k]);
		}


	}
	printf("     피벗 : %d", arr[i + 1]);
	printf("\n");

	//기존 피벗+1 최종위치 반환
	return i+1;
}
//파티션1 함수를 이용합니다
void quicksort1(int arr[],int low,int high) {
	if (low < high) {
		int pivot = partition1(arr,low,high);
		quicksort1(arr, low, pivot - 1);
		quicksort1(arr, pivot + 1, high);
	}
}

/*............................................. */

//피벗의 값보다 큰 값은 피벗 왼쪽으로. 피벗의 값보다 작은 값은 피벗 오른쪽으로.
int partition2(int arr[], int low, int high) {
	//작은 위치을 피벗으로 설정
	int pivot = low;
	//피벗보다 큰 값의 마지막 위치
	int i = high+1;
	//검사중인 값의 위치
	int j = high;
	int temp;
	
	while ((j >low)) {
		if (arr[j] > arr[pivot]) {
			i--;
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
		j--;
	}

	temp = arr[i - 1];
	arr[i - 1] = arr[pivot];
	arr[pivot] = temp;

	printf("<<%d단계>> ", time++);
	for (int k = 0; k < max; k++) {
		if ((k == low)) {
			printf("[%2d ", arr[k]);
		}
		else if (k == high) {
			printf(" %2d]", arr[k]);
		}
		else {
			printf(" %2d ", arr[k]);
		}
	}
	printf("     피벗 : %d", arr[i - 1]);
	printf("\n");
	//기존 피벗-1 위치 반환
	return i - 1;
}

//파티션2 함수를 이용합니다
void quicksort2(int arr[], int low, int high) {
	if (low < high) {
		int pivot = partition2(arr, low, high);
		quicksort2(arr, low, pivot - 1);
		quicksort2(arr, pivot + 1, high);
	}
}

/*............................................. */
// (범위를 좁혀가며..) 피벗의 값보다 작은 값은 왼쪽으로, 피벗의 값보다 큰 값은 오른쪽으로.
int partition3(int arr[], int low, int high) {
	int pivot_value = arr[low];
	int left = low+1;
	int right = high;
	int temp;

	while (left <= right) {
		
		while (arr[left] < pivot_value) { left++;}
		while (arr[right] > pivot_value) { right--;}
		if (left < right) {
			temp = arr[left];
			arr[left] = arr[right];
			arr[right] = temp;
		}
	}

		temp = arr[low];
		arr[low] = arr[right];
		arr[right] = temp;
	

		printf("<<%d단계>> ", time++);
		for (int k = 0; k < max; k++) {
			if ((k == low)) {
				printf("[%2d ", arr[k]);
			}
			else if (k == high) {
				printf(" %2d]", arr[k]);
			}
			else {
				printf(" %2d ", arr[k]);
			}
		}
		printf("     피벗 : %d", arr[right]);
		printf("\n");

		return right;

}

//파티션3 함수를 이용합니다
void quicksort3(int arr[], int low, int high) {
	if (low < high) {
		int pivot = partition3(arr, low, high);
		quicksort3(arr, low, pivot - 1);
		quicksort3(arr, pivot + 1, high);
	}
}


int main() {
	int num;
	while (1) {
		printf("--------------------------------------------------------------------------------\n");
		printf("1번 : 구간의 맨 마지막 위치의 값을 피봇으로 하고, 늘어남\n2번 : 구간의 맨 첫번째 위치의 값을 피봇으로 하고, 줄어듦\n3번 : 구간의 맨 첫번째 위치의 값을 피봇으로하고, 양쪽에서 좁아지는 \n");
		scanf_s("%d", &num);
		system("cls"); //콘솔화면 초기화
		printf("\n");
		printf("기존배열 : ");
		int arr[] = { 31,8,48,73,11,3,20,29,65,15 };
		for (int i = 0; i < max; i++) {
			printf("%d ", arr[i]);
		}
		printf("\n");
		if (num == 1) {
			quicksort1(arr, 0, max - 1);
		}
		if (num == 2) {
			quicksort2(arr, 0, max - 1);
		}
		if (num == 3) {
			quicksort3(arr, 0, max - 1);
		}

		printf("--------------------------------------------------------------------------------\n완료되었습니다.");
		printf("\n");
		time = 1;
	}
}