#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
typedef int SLDataType;

typedef struct SLNode{
	SLDataType value;
	struct SLNode *next;
}   SLNode;

typedef struct SList{
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

//ɾ
//ͷɾ
void SListPopFront(SList *list);
//βɾ
void SListPopBack(SList *list);
//��

//��
//��ӡ
void SListPrint(const SList *list);