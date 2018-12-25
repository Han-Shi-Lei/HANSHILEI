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
	SListPrint(&list);

	SListPopBack(&list);
	SListPopBack(&list);
	SListPopFront(&list);

	printf("�ɹ���\n");
}
void main()
{
	SListTest1();
	system("pause");
}