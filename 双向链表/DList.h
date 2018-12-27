#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
typedef int DLDataType;
 //����������ṹ
typedef struct DListNode{
	DLDataType value;
	struct DListNode *prev;//ָ�������ǰһ�����
	struct DListNode *next;//ָ������ĺ�һ�����
}DListNode;

//����˫������ṹ
typedef struct DList{
	DListNode *head;    //���������ͷ���

}DList;
//��ʼ��
void DListInit(DList *dlist);
//����
//1.�������
void DlistClear(DList *dlist);
//2.������������
void DListDestroy(DList *dlist);
//��
//ͷ��
void DListPushFront(DList *dlist, DLDataType value);
//β��
void DListPushBack(DList *dlist, DLDataType value);
//�� pos ǰ����в��� value
void DListInsertFront(DListNode* pos, DLDataType value);
//ɾ
//ͷɾ
void DListPopFront(DList *dlist);
//βɾ
void DListPopBack(DList *dlist);
//ɾ�� pos λ�õĽ��
void DListErase(DListNode* pos);
//��
void DListRemove(DListNode* pos, DLDataType value);
//�� 
DListNode* DListFind(const DList* dlist, DLDataType value);
//��ӡ
void DListPrint(DList *dlist);