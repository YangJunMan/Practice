
#include "list_class.h"

int main(void) {
	List A;
	A.create_Dynamic();
	A.insert(1,10);
	A.insert(2, 12);
	A.insert(3, 14);
	A.insert(1, 30);

	int B = A.Length();
	cout << B <<"aa" << endl;
	for (int i = 1; i < 6; i++)
		cout << A.get_item(i) << endl;
}