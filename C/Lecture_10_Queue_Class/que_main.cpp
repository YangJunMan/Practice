#include "que_class.h"

int main() {
	queClass S;
	S.Create();
	printf("비어있나요? : %d (True=1,False=0)\n", S.IsEmpty());
	S.Add(8);
	printf("비어있나요? : %d (True=1,False=0)\n", S.IsEmpty());
	printf("꽉차있나요? : %d (True=1,False=0)\n", S.IsFull());
	S.Add(10);
	S.Add(12);
	S.Add(14);
	S.Add(16);
	S.GetSize();
	printf("꽉차있나요? : %d (True=1,False=0)\n", S.IsFull());
	S.Remove();
	S.GetFront();
	S.Destroy();
};
