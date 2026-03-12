#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

typedef struct Node
{
	int data;
	Node* Next;
} ;
class node_list {
	typedef Node* Nptr;

private:
	Nptr head;
	
	int Max_num=-1;
public:
	void Node_display();
	void Node_create(int max);
	void Node_destroy();
	void Node_add(int position,int data);
	void Node_delete(int position);
	
};

