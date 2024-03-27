#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define max 11
int time;

//first부터 mid까지. mid부터 last까지 순환호출 정렬
void merge(int arr[], int first, int mid, int last) {
	int i = first;
	int j = mid + 1;
	int temp[max];
	int k = first;
	//왼쪽이나 오른쪽 부분 중 하나가 먼저 끝나면 
	while ((i <= mid) && (j <= last)) {
		if (arr[i] <= arr[j]) {
			temp[k++] = arr[i++];
		}
		else if (arr[j] < arr[i]) {
			temp[k++] = arr[j++];
		}
	}
	//남은 부분의 요소들을 임시배열 temp에 그대로 복사
	if (i > mid) {
		for (int l = j; l <= last; l++) {
			temp[k++] = arr[l];
		}
	}
	else {
		for (int l = i; l <= mid; l++) {
			temp[k++] = arr[l];
		}
	}
	//기존 arr배열에 다시 temp의 배열 복사
	for (int a = first; a <= last; a++) {
		arr[a] = temp[a];
	}

	printf("<<%2d단계>>  ", time++);
	for (int h = 0; h < max; h++) {
		if (h == first) {
			printf("[%d ", arr[h]);
		}
		else if (h == last) {
			printf("%d] ", arr[h]);
		}
		else
			printf("%d ", arr[h]);

	}

	printf("\n");

}

//재귀를 이용한 병합정렬
void mergeSort(int arr[], int first, int last) {
	if (first < last) {
		int mid = (first + last) / 2;
		mergeSort(arr, first, mid);
		mergeSort(arr, mid + 1, last);
		merge(arr, first, mid, last);
	}
}
int big;

//---------------------------
// 
//나뉘어진 배열들을 병합한다
void forge(int arr[], int temp[], int first, int mid, int last)
{
	int k = first, i = first, j = mid + 1;

	while (i <= mid && j <= last)
	{
		if (arr[i] < arr[j]) {
			temp[k++] = arr[i++];
		}
		else {
			temp[k++] = arr[j++];
		}
	}

	if (i > mid) {
		for (int l = j; l <= last; l++) {
			temp[k++] = arr[l];
		}
	}
	else {
		for (int l = i; l <= mid; l++) {
			temp[k++] = arr[l];
		}
	}

	for (int i = first; i <= last; i++) {
		arr[i] = temp[i];
		big = i;
	}

	printf("<<%2d단계>>  ", time++);
	for (int h = 0; h < max; h++) {
		if (h == first) {
			printf("[%d ", arr[h]);
		}
		else if (h == last) {
			printf("%d] ", arr[h]);
		}
		else
			printf("%d ", arr[h]);

	}
	printf("\n");
}


//반복문을 이용해서 병합정렬 실행
void forgesort(int arr[], int first, int last)
{
	int temp[max];
	for (int i = 0; i < max; i++) {
		temp[i] = arr[i];
	}

	for (int m = 1; m <= last - first; m = 2 * m)
	{
		for (int i = first; i < last; i += 2 * m)
		{
			int from = i;
			int mid = i + m - 1;
			int to;
			if (i + 2 * m - 1 < last) {
				to = i + 2 * m - 1;
			}
			else {
				to = last;
			}
			forge(arr, temp, from, mid, to);
		}
	}
}

int main() {
	while (1) {
		int arr[] = { 33,65,16,46,68,62,6,4,7,22,14 };
		int length = sizeof(arr) / sizeof(int);
		int num;
		time = 1;
		printf("\n- 현재 정렬 >> ");
		for (int i = 0; i < max; i++) {
			printf("%d ", arr[i]);
		}
		printf("\n");
		printf("1번 : 순환호출로 정렬하기\n2번 : 반복문으로 정렬하기\n");
		scanf("%d", &num);
		if (num == 1) {
			mergeSort(arr, 0, max - 1);
			printf("정렬이 완료되었습니다. \n");
		}
		else if (num == 2) {
			forgesort(arr, 0, max - 1);
			printf("정렬이 완료되었습니다. \n");
		}
		else if (num == 3) {
			printf("종료합니다.");
			return 0;
		}

	}


}