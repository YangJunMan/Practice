#include <stdio.h>
#include <iostream>
//선택정렬
void select(int arr[], int length) {


	int j;
	//최솟값의 지점
	int dotPoint;
	//임시 최솟값
	int temp;
	int countCompare = 0;
	int countAccumulate = 0;
	printf("--------------------------------------------------------------------\n");
	printf(" 선택정렬\n");
	printf(" 배열 : ");
	for (int k = 0; k < length; k++) {
		printf("%d ", arr[k]);
	}
	printf("\n--------------------------------------------------------------------");
	printf(" /  비교회수  누적변경회수");
	printf("\n");

	for (int i = 0; i < length - 1; i++) {
		//맨 앞을 기준으로 최솟값을 판별하기 시작
		int min = arr[i];
		printf("%2d단계 : ", i + 1);
		for (j = i + 1; j < length; j++) {
			if (arr[j] < min) {
				//최소값
				min = arr[j];
				//맨 앞의 값
				temp = arr[i];
				//지점
				dotPoint = j;
			}
			countCompare++;
		}
		countAccumulate += countCompare;
		//앞에 위치하는 값과 최솟값의 위치 변경
		arr[i] = min;
		arr[dotPoint] = temp;

		for (int k = 0; k < length; k++) {
			if (min == arr[k]) {
				printf("%d]", min);
			}
			else if (arr[dotPoint] == arr[k]) {
				printf("%d]", arr[k]);
			}
			else
				printf("%d ", arr[k]);

		} //출력
		printf("/ %6d", countCompare);
		printf("  %10d", countAccumulate);
		printf("\n");
		countCompare = 0;
	}
	printf("--------------------------------------------------------------------\n");
}
//삽입정렬
void insert(int arr[], int length) {
	int j;
	//최솟값의 지점
	int dotPoint;
	//임시 최솟값
	int temp = 0;
	int countCompare = 1;
	int countAccumulate = 0;
	printf("--------------------------------------------------------------------\n");
	printf(" 삽입정렬\n");
	printf(" 배열 : ");
	for (int k = 0; k < length; k++) {
		printf("%d ", arr[k]);
	}
	printf("\n--------------------------------------------------------------------");
	printf(" /  비교회수  누적비교회수");
	printf("\n");

	for (int i = 0; i < length - 1; i++) {
		printf("%2d단계 : ", i + 1);
		if (arr[i] > arr[i + 1]) {
			int min = arr[i + 1];
			temp = min;
			for (int j = i + 1; j >= 0; j--) {
				if (arr[j] > min) {
					arr[j + 1] = arr[j];
					arr[j] = min;
					countCompare++;
				}
			}
			countAccumulate += countCompare;


		}
		for (int k = 0; k < length; k++) {
			if ((arr[i] == arr[k])) {
				printf("%d]", arr[i]);
			}
			else
				printf("%d ", arr[k]);

		}
		printf("/ %6d", countCompare);
		printf("  %10d", countAccumulate);
		printf("\n");
		countCompare = 0;

	}
}
//버블정렬
void bubble(int arr[], int length) {
	int temp;
	int countCompare = 0;

	printf("--------------------------------------------------------------------\n");
	printf(" 버블정렬\n");
	printf(" 배열 : ");
	for (int k = 0; k < length; k++) {
		printf("%d ", arr[k]);
	}
	printf("\n--------------------------------------------------------------------\n");


	for (int i = 0; i < length - 1; i++) {
		int min = 0;
		printf("<<%d단계>>\n", i + 1);
		for (int j = 0; j < length - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				temp = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = temp;
				countCompare++;
			}
			for (int k = 0; k < length; k++) {
				printf("%d ", arr[k]);
			}
			printf("\n");
		}
		if (countCompare == 0) {
			printf("\n%d단계에서 이미 정렬이 완료되었습니다. \n\n", i);
			break;
		}

		countCompare = 0;
	}
}

int main() {

	int num;
	while (1) {
		printf("\n--------------------------------------------------------------------\n");
		printf("1번 : 선택정렬\n2번 : 삽입정렬\n3번 : 버블정렬\n");
		printf("--------------------------------------------------------------------\n");
		scanf_s("%d", &num);
		if (num == 1) {
			int arr[] = { 31,62,17,63,55,47,26,48,59,20,23,43,49,27,53,35,22,33,50,64 };
			int length = sizeof(arr) / sizeof(int);
			select(arr, length);
		}
		if (num == 2) {
			int arr2[] = { 31,62,17,55,63,47,26,48,59,20,23,43,49,27,53,35,22,33,50,64 };
			int length2 = sizeof(arr2) / sizeof(int);
			insert(arr2, length2);
		}
		if (num == 3) {
			int arr3[] = { 31,62,17,82,93,47,26,50,59,48 };
			int length3 = sizeof(arr3) / sizeof(int);
			bubble(arr3, length3);
		}
	}

}
