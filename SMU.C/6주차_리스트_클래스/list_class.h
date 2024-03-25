#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

typedef struct
{
	int Data;
} LIST_NODE;

class List {

private:
	int Max;
	int A_position=-2;
	LIST_NODE* list;
	LIST_NODE list_node[100];
	LIST_NODE* list_node_dynamic;

public:
	
	void create(int max_num);
	void create_Dynamic(void);
	void destroy(void);
	void destroy_Dynamic(void);
	void insert(int Position, int data);
	void Delete(int Position);
	void isempty(void);
	void isfull(void);
	int get_item(int  Position);
	int Retrieve(int position);
	int Length(void);
};