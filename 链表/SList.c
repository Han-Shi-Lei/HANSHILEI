#include "SList.h"

static SLNode *SListBuyNode(SLDataType value)
{
	SLNode *node = (SLNode*)malloc(sizeof(SLNode));
	assert(node);
	node->value = value;
	node->next = NULL;

	return node;

}
void SListInit(SList *list)
{
	assert(list != NULL);
	list->first = NULL;
}
void SlistDestory(SList *list)
{
	assert(list != NULL);

	SLNode *cur = list->first;
	SLNode *next;
	while (cur != NULL){
		next = cur->next;
		free(cur);
		cur = next;
	}
	list->first = NULL;
}

void SListPushFront(SList *list, SLDataType value)
{
	assert(list != NULL);
	SLNode *node = (SLNode *)malloc(sizeof(SLNode));
	assert(node != NULL);
	node->value = value;
	node->next = list->first;
	list->first = node;
}
void SListPopFront(SList *list)
{
	assert(list != NULL);   //保证链表是有的；
	assert(list->first != NULL); //保证链表不为空；
	SLNode *old_first = list->first;
	list->first = list->first->next;
	free(old_first);
}
void SListPushBack(SList *list, SLDataType value)
{
	assert(list != NULL);
	if (list->first == NULL){
		SListPushFront(list, value);
		return;
	}

	//链表中有结点的情况
	//找链表中的最后一个结点
	SLNode *cur;
	for (cur = list->first; cur->next != NULL; cur = cur->next){

	}
	//cur就是最后一个结点
	SLNode *node = SListBuyNode(value);
	cur->next = node;
}
void SListPopBack(SList *list)
{
	assert(list != NULL);
	assert(list->first != NULL);
	//如果只有一个结点
	if (list->first->next == NULL){
		SListPopFront(list);
		return;
	}

	SLNode *cur=list->first;
	while(cur->next->next != NULL){
		cur = cur->next;

	}
	//走到这里肯定就是倒数第二个结点了；
	free(cur->next);
	cur->next = NULL;

}

void SListPrint(const SList *list)
{
	assert(list != NULL);
	for (SLNode *cur = list->first; cur != NULL; cur = cur->next){
		printf("%d --> ", cur->value);
	}
	printf("NULL\n");
}