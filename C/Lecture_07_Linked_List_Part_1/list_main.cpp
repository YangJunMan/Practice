
#include "list_class.h"

int main(void) {
	node_list A;
	A.Node_create(5);
	A.Node_add(1, 10);
	A.Node_add(1, 11);
	A.Node_add(1, 12);
	A.Node_add(1, 13);
	A.Node_add(1, 20);
	A.Node_delete(5);
	A.Node_display();
	A.Node_destroy();
	printf()
}