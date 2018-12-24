#include <stdio.h>
#include <stdbool.h>

typedef int SLDataType;

typedef struct SeqList{
	SLDataType *array;   //指向动态开辟的数组；
	size_t size;         //有效数据的个数；
	size_t capacity;     //容量空间的大小；
}SeqList;
//初始化、销毁
//初始化
//seqlist是一个变量的地址
//capacity 表示顺序表的容量
void SeqListInit(SeqList* seqlist, size_t capicity);
//销毁
void SeqListDestory(SeqList* seqlist);

//增删改查

//插入
//尾插
void SeqListPushBack(SeqList *seqlist, SLDataType value);
//头插
void SeqListPushFront(SeqList *seqlist, SLDataType value);
//中间插入
void SeqListInsert(SeqList *seqlist, size_t pos, SLDataType value);

//删除
//尾删
void SeqListPopBack(SeqList *seqlist);
//头删
void SeqListPopFront(SeqList *seqlist);
//删除pos所在的下标的数值；
void SeqListPopInsert(SeqList *seqlist, size_t pos);

//打印
void SeqListPrint(const SeqList *seqlist);

//修改 pos 所在的下标的数据为 value
void SeqListModify(SeqList *seqlist, size_t pos, SLDataType value);

//查找
//如果找到返回第一个找到的下标，如果没找到返回-1
size_t SeqListFind(const SeqList *seqlist, SLDataType value);

//找到并删除第一个遇到的 value
void SeqListRemove(SeqList *seqlist, SLDataType value);

//判断顺序表是否为空
bool SeqListEmpty(const SeqList *seqlist);

//返回数据个数
size_t SeqListSize(const SeqList *seqlist);



