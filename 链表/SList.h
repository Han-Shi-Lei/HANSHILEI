#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
typedef int SLDataType;
//链表中的一个结点
typedef struct SLNode{
	SLDataType value;
	//指向链表中第二个结点的地址
	struct SLNode *next;
}   SLNode;
//一个链表
typedef struct SList{
	//指向链表中第一个结点的地址
	SLNode *first;    //SLNode *head;
}	SList;


//初始化
void SListInit(SList *list);

//销毁
void SlistDestory(SList *list);

//增
//头插
void SListPushFront(SList *list, SLDataType value);
//尾插
void SListPushBack(SList *list, SLDataType value);
//在pos后面插入value
void SListInsertAfter(SLNode *pos, SLDataType value);
//在pos前面插入value
void SListInsertBefore(SList *list, SLNode *pos,SLDataType value);

//删
//头删
void SListPopFront(SList *list);
//尾删
void SListPopBack(SList *list);
//删除 pos 后面的 value
void SListEraseAfter(SLNode *pos);
//改
void SListModify(SLNode * pos, SLDataType value);

//查
//去找到链表中遇到的第一个 value，如果没找到，返回NULL
SLNode * SListFind(const SList *list, SLDataType value);

//打印
void SListPrint(const SList *list);