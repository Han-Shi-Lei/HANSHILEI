#include "DList.h"
static DListNode* DListBuyNode(DLDataType value)
{
	DListNode *node = (DListNode*)malloc(sizeof(DListNode));
	assert(node);
	node->value = value;
	node->next = NULL;
	node->prev = NULL;
	return node;
}
void DListInit(DList *dlist)
{
	dlist->head = DListBuyNode(0);//这里的0其实没有意义
	                               //这里是头结点
	dlist->head->prev = dlist->head;
	dlist->head->next = dlist->head;
}

void DlistClear(DList *dlist)
{
	DListNode *cur, *next;
	cur = dlist->head->next;
	while (cur != dlist->head){
		next = cur->next;
		free(cur);
		cur = next;
	}
	dlist->head->next = dlist->head->prev=dlist->head;
}

void DListDestroy(DList *dlist)
{
	DlistClear(dlist);
	free(dlist->head);
	dlist->head = NULL;
}

void DListPushFront(DList *dlist, DLDataType value)
{

	DListNode *node = DListBuyNode(value);
	node->prev = dlist->head;
	node->next = dlist->head->next;
	dlist->head->next->prev = node;
	dlist->head->next = node;

	/*DListInsertFront(dlist->head->next, value);*/
}
void DListPopFront(DList *dlist)
{
	assert(dlist->head->next!= dlist->head);
	DListNode *node = dlist->head->next;
	dlist->head->next = node->next;
	node->next->prev = dlist->head;
	free(node);
}
void DListPushBack(DList *dlist, DLDataType value)
{

	DListNode *node = DListBuyNode(value);
	node->prev = dlist->head->prev;
	node->next = dlist->head;
	dlist->head->prev->next = node;
	dlist->head->prev = node;

	/*DListInsertFront(dlist->head->prev, value);*/
}
void DListPopBack(DList *dlist)
{
	assert(dlist->head->next != dlist->head);    //判断链表不为空
	DListNode *node = dlist->head->prev;
	dlist->head->prev = node->prev;
	node->prev->next = dlist->head;
	free(node);
}
void DListInsertFront(DListNode* pos, DLDataType value)
{
	DListNode *node = DListBuyNode(value);
	node->prev = pos->prev;
	node->next = pos;
	node->prev->next = node;
	pos->prev = node;
}
void DListErase(DListNode* pos)
{
	pos->next->prev = pos->prev;
	pos->prev->next = pos->next;
	free(pos);
}
void DListRemove(DListNode* pos, DLDataType value)
{
	pos->value = value;
}

DListNode* DListFind(const DList* dlist, DLDataType value)
{
	assert(dlist->head->next != dlist->head);    //判断链表不为空
	DListNode *node;
	node = dlist->head->next;
	while (node != dlist->head)
	{
		node = node->next;

		if (node->value == value){
			return node;
		}
	}
	return NULL;
}
//打印
void DListPrint(DList *dlist)
{
	printf(" %d --> ", dlist->head->value);
	DListNode *node = dlist->head->next;
	for (; node != dlist->head; node = node->next){
		printf("%d --> ", node->value);
	}
	printf(" %d", dlist->head->value);
	printf("\n");
}