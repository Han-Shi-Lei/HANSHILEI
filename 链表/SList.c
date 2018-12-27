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
	assert(list != NULL);   //��֤�������еģ�
	assert(list->first != NULL); //��֤����Ϊ�գ�
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

	//�������н������
	//�������е����һ�����
	SLNode *cur;
	for (cur = list->first; cur->next != NULL; cur = cur->next){

	}
	//cur�������һ�����
	SLNode *node = SListBuyNode(value);
	cur->next = node;
}
void SListPopBack(SList *list)
{
	assert(list != NULL);
	assert(list->first != NULL);
	//���ֻ��һ�����
	if (list->first->next == NULL){
		SListPopFront(list);
		return;
	}

	SLNode *cur=list->first;
	while(cur->next->next != NULL){
		cur = cur->next;

	}
	//�ߵ�����϶����ǵ����ڶ�������ˣ�
	free(cur->next);
	cur->next = NULL;

}
void SListInsertAfter(SLNode *pos, SLDataType value)
{
	//�� value ������
	SLNode *node = SListBuyNode(value);
	node->next = pos->next;
	pos->next = node;
}
void SListEraseAfter(SLNode *pos)
{
	SLNode *next = pos->next;
	pos->next = next->next;
	free(next);
}
void SListInsertBefore(SList *list, SLNode *pos, SLDataType value)
{
	assert(list != NULL);
	SLNode *cur = list->first;
	while (cur->next != pos){
		cur = cur->next;
	}
	// cur ָ�� pos ��ǰһ�����
	SLNode *node = SListBuyNode(value);
	cur->next = node;
	node->next = pos;
}

SLNode * SListFind(const SList *list, SLDataType value)
{
	assert(list != NULL);
	for (SLNode *cur = list->first; cur != NULL; cur = cur->next){
		if (cur->value == value){
			return cur;
		}
	}
	return NULL;

}

void SListPrint(const SList *list)
{
	assert(list != NULL);
	for (SLNode *cur = list->first; cur != NULL; cur = cur->next){
		printf("%d --> ", cur->value);
	}
	printf("NULL\n");
}
void SListModify( SLNode * pos, SLDataType value)
{
	pos->value = value;
}