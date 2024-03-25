#include <iostream>
#define MAX 5

class Stack {
private:
	int Top = -1;
	int stack[MAX];

public:
	void Create();
	void Push(int item);
	void GetTop();
	void Pop();
	bool IsEmpty();
	bool IsFull();
	void GetSize();
	void Destroy();

};
