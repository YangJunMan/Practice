#include <iostream>
#define MAX 5
class queClass {
private:
	int Front;
	int Rear;
	int Queue[MAX];
public:
	void Create();
	bool IsEmpty();
	bool IsFull();
	void Add(int a);
	void Remove();
	void GetSize();
	void GetFront();
	void Destroy();
};