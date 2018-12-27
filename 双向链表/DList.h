#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
typedef int DLDataType;
 //定义链表结点结构
typedef struct DListNode{
	DLDataType value;
	struct DListNode *prev;//指向链表的前一个结点
	struct DListNode *next;//指向链表的后一个结点
}DListNode;

//定义双向链表结构
typedef struct DList{
	DListNode *head;    //定义链表的头结点

}DList;
//初始化
void DListInit(DList *dlist);
//销毁
//1.清空链表
void DlistClear(DList *dlist);
//2.彻底销毁链表
void DListDestroy(DList *dlist);
//增
//头插
void DListPushFront(DList *dlist, DLDataType value);
//尾插
void DListPushBack(DList *dlist, DLDataType value);
//在 pos 前面进行插入 value
void DListInsertFront(DListNode* pos, DLDataType value);
//删
//头删
void DListPopFront(DList *dlist);
//尾删
void DListPopBack(DList *dlist);
//删除 pos 位置的结点
void DListErase(DListNode* pos);
//改
void DListRemove(DListNode* pos, DLDataType value);
//查 
DListNode* DListFind(const DList* dlist, DLDataType value);
//打印
void DListPrint(DList *dlist);