#include <iostream>
#include <iomanip>
using namespace std;

//요소의 개수가 20개인 2차원 배열 중 1행에 10명의 점수를 입력받고, 2행에 석차를 부여하는 프로그램

//클래스
class order {
public:
	int arr[2][10];

	void insert();
	void crank();
};

//입력받기
void order::insert(void) {
	cout << "입력 : ";
	for (int i = 0; i < 10; i++) {
		cin>>arr[0][i];
	}
	cout << "총점 : ";
	for (int i = 0; i < 10; i++) {
		cout.width(2);
		cout<<arr[0][i]<<" ";
	}
	cout << "\n";

}

//출력하기
void order::crank(void) {
	int rank[10] = { 1,1,1,1,1,1,1,1,1,1 };
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (arr[0][i] < arr[0][j]) {
				//자신보다 큰 수가 있다면, 등수가 밀린다.
				rank[i] = rank[i] + 1; 
			}
		}
	}
	cout << "석차 : ";
	for (int i = 0; i < 10; i++) {
		cout.width(2);
		cout << rank[i]<<" ";
	}
}

