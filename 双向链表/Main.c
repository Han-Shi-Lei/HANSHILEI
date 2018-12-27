#include "DList.h"

void DListTest1()
{
	DList dlist;
	DListInit(&dlist);
	DListPushFront(&dlist, 10);
	DListPushFront(&dlist, 11);
	DListPushFront(&dlist, 12);
	DListPushFront(&dlist, 13);

	DListPushBack(&dlist, 21);
	DListPushBack(&dlist, 22);
	DListPushBack(&dlist, 23);

	DListNode  *n = DListFind(&dlist, 21);

	/*DListInsertFront(n, 103);*/

	/*DListErase(n);*/
	DListRemove(n, 1);
	DListPrint(&dlist);

	printf("³É¹¦£¡\n");
}
void main()
{
	DListTest1();
	system("pause");
}