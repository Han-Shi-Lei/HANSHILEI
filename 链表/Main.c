#include "SList.h"

void SListTest1()
{
	SList list;
	SListInit(&list);
	assert(list.first == NULL);

	SListPushFront(&list, 1);
	SListPushFront(&list, 2);
	SListPushFront(&list, 3);
	//3,2,1
	SListPushBack(&list, 11);
	SListPushBack(&list, 12);
	SListPushBack(&list, 13);
	//3,2,1,11,12,13
	SLNode *n = SListFind(&list,2);
	/*SListModify(n, 90);*/
	//3,90,1,11,12,13
	SListEraseAfter(n);
	SListInsertAfter(n, 10);
	SListInsertBefore(&list,n, 20);
	SListPrint(&list);

	SListPopBack(&list);
	SListPopBack(&list);
	SListPopFront(&list);

	printf("³É¹¦£¡\n");
}
void main()
{
	SListTest1();
	system("pause");
}