#include <iostream>
using namespace std;

typedef struct node {
		int data;
		node* next;
}node;
typedef node* nptr;

class List {
private:
	
	int listmax = 0, listcount = 0;

public:
	nptr head;
	nptr Create(int max,nptr p);
	bool IsEmpty();
	bool IsFull();
	nptr Insert(int position, int data, nptr p);
	nptr Delete(int position, nptr p);
	void List_view(nptr p);
	void Destroy(nptr p);
	int Length();
};
