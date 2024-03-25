#include <stdio.h>
#include <iostream>
#include "list_class.h"

int main() {
	List list;
	list.head=NULL;
	
	list.head = list.Create(5, list.head);
	list.List_view(list.head);
	list.head = list.Insert(1, 4, list.head);
	list.List_view(list.head);
	list.head = list.Insert(1, 5, list.head);
	list.List_view(list.head);
	list.head = list.Insert(3, 6, list.head);
	list.List_view(list.head);
	list.head = list.Insert(2, 7, list.head);
	list.List_view(list.head);
	list.head = list.Insert(3, 8, list.head); 
	list.List_view(list.head);
	list.Length();
	list.head = list.Delete(2, list.head);
	list.List_view(list.head);
	list.head = list.Delete(1, list.head);
	list.List_view(list.head);
	list.Destroy(list.head); 
	list.List_view(list.head);
	list.head = list.Create(5, list.head); 
	list.List_view(list.head);
	list.head = list.Insert(1, 4, list.head);
	list.List_view(list.head);
	list.head = list.Insert(1, 6, list.head); 
	list.List_view(list.head);
	list.Length();
	
	return 0;
}