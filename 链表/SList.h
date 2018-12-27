#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
typedef int SLDataType;
//�����е�һ�����
typedef struct SLNode{
	SLDataType value;
	//ָ�������еڶ������ĵ�ַ
	struct SLNode *next;
}   SLNode;
//һ������
typedef struct SList{
	//ָ�������е�һ�����ĵ�ַ
	SLNode *first;    //SLNode *head;
}	SList;


//��ʼ��
void SListInit(SList *list);

//����
void SlistDestory(SList *list);

//��
//ͷ��
void SListPushFront(SList *list, SLDataType value);
//β��
void SListPushBack(SList *list, SLDataType value);
//��pos�������value
void SListInsertAfter(SLNode *pos, SLDataType value);
//��posǰ�����value
void SListInsertBefore(SList *list, SLNode *pos,SLDataType value);

//ɾ
//ͷɾ
void SListPopFront(SList *list);
//βɾ
void SListPopBack(SList *list);
//ɾ�� pos ����� value
void SListEraseAfter(SLNode *pos);
//��
void SListModify(SLNode * pos, SLDataType value);

//��
//ȥ�ҵ������������ĵ�һ�� value�����û�ҵ�������NULL
SLNode * SListFind(const SList *list, SLDataType value);

//��ӡ
void SListPrint(const SList *list);