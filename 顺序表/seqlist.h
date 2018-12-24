#include <stdio.h>
#include <stdbool.h>

typedef int SLDataType;

typedef struct SeqList{
	SLDataType *array;   //ָ��̬���ٵ����飻
	size_t size;         //��Ч���ݵĸ�����
	size_t capacity;     //�����ռ�Ĵ�С��
}SeqList;
//��ʼ��������
//��ʼ��
//seqlist��һ�������ĵ�ַ
//capacity ��ʾ˳��������
void SeqListInit(SeqList* seqlist, size_t capicity);
//����
void SeqListDestory(SeqList* seqlist);

//��ɾ�Ĳ�

//����
//β��
void SeqListPushBack(SeqList *seqlist, SLDataType value);
//ͷ��
void SeqListPushFront(SeqList *seqlist, SLDataType value);
//�м����
void SeqListInsert(SeqList *seqlist, size_t pos, SLDataType value);

//ɾ��
//βɾ
void SeqListPopBack(SeqList *seqlist);
//ͷɾ
void SeqListPopFront(SeqList *seqlist);
//ɾ��pos���ڵ��±����ֵ��
void SeqListPopInsert(SeqList *seqlist, size_t pos);

//��ӡ
void SeqListPrint(const SeqList *seqlist);

//�޸� pos ���ڵ��±������Ϊ value
void SeqListModify(SeqList *seqlist, size_t pos, SLDataType value);

//����
//����ҵ����ص�һ���ҵ����±꣬���û�ҵ�����-1
size_t SeqListFind(const SeqList *seqlist, SLDataType value);

//�ҵ���ɾ����һ�������� value
void SeqListRemove(SeqList *seqlist, SLDataType value);

//�ж�˳����Ƿ�Ϊ��
bool SeqListEmpty(const SeqList *seqlist);

//�������ݸ���
size_t SeqListSize(const SeqList *seqlist);



