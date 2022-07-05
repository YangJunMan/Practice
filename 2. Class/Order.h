#include <iostream>
#include <iomanip>
using namespace std;

class order {
public:
	int arr[2][10];

	void insert();
	void crank();
};

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

void order::crank(void) {
	int rank[10] = { 1,1,1,1,1,1,1,1,1,1 };
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (arr[0][i] < arr[0][j]) {
				rank[i] = rank[i] + 1; //자기보다 큰 수가 있으면 등수가 밀림
			}
		}
	}
	cout << "석차 : ";
	for (int i = 0; i < 10; i++) {
		cout.width(2);
		cout << rank[i]<<" ";
	}
}

