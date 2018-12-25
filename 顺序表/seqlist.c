#include "seqlist.h"
#include <assert.h>
#include <stdlib.h>


//����Ƿ���Ҫ���ݣ������Ҫ�������������
//��֤��������������һ������
static void CheckCapacity(SeqList *seqlist)
{
	assert(seqlist != NULL);
	assert(seqlist->size <= seqlist->capacity);
	assert(seqlist->array != NULL);
	if (seqlist->size < seqlist->capacity){
		return;
	}
	//�ߵ�����һ����Ҫ����
	size_t capacity = 2 * (seqlist->capacity);
	SLDataType *array = (SLDataType*)malloc(sizeof(SLDataType)*capacity);
	assert(array);
	//�������ݰ��ƹ���
	for (size_t i = 0; i < seqlist->size; i++){
		array[i] = seqlist->array[i];
	}
	free(seqlist->array);
	seqlist->array = array;
	seqlist->capacity = capacity;
}

void SeqListInit(SeqList *seqlist, size_t capacity)
{
	assert(seqlist != NULL);
	seqlist->array = (SLDataType*)malloc(sizeof(SLDataType)*capacity);
	assert(seqlist->array);
	seqlist->size = 0;
	seqlist->capacity = capacity;
}
void SeqListDestory(SeqList *seqlist)
{
	assert(seqlist != NULL);
	assert(seqlist->array != NULL);
	free(seqlist->array);
	seqlist->array = NULL;
	seqlist->size = 0;
	seqlist->capacity = 0;
}
void SeqListPushBack(SeqList *seqlist, SLDataType value)
{
	assert(seqlist != NULL);
	assert(seqlist->array != NULL);
	CheckCapacity(seqlist);

	seqlist->array[seqlist->size] = value;
	seqlist->size++;
}
void SeqListPopBack(SeqList *seqlist)
{
	assert(seqlist != NULL);
	assert(seqlist->array != NULL);
	assert(seqlist->size > 0);
	seqlist->size--;

}
void SeqListPushFront(SeqList *seqlist, SLDataType value)
{
	assert(seqlist != NULL);
	assert(seqlist->array != NULL);

	CheckCapacity(seqlist);


	//�����ݰ��ƣ�i ����ռ��±�
	for (int i = seqlist->size; i > 0; i--){
		seqlist->array[i] = seqlist->array[i - 1];
	}
	seqlist->array[0] = value;
	seqlist->size++;
}
void SeqListPopFront(SeqList *seqlist)
{
	assert(seqlist->array != NULL);
	assert(seqlist->size > 0);
	assert(seqlist != NULL);
	
	//�����ݰ��ƣ�i���������±ꣻ
	for (size_t i = 1; i <= seqlist->size-1; i++){
		seqlist->array[i-1] = seqlist->array[i];
	}
	seqlist->size--;
}
void SeqListInsert(SeqList *seqlist, size_t pos, SLDataType value)
{
	assert(seqlist != NULL);
	assert(seqlist->size > 0);
	assert(seqlist->array != NULL);
	assert(pos > 0 && pos <= seqlist->size);

	CheckCapacity(seqlist);

	//�����ݰ��ƣ�i ���������±ꣻ
	for (size_t i = seqlist->size - 1; i >= pos; i--){
		seqlist->array[i + 1] = seqlist->array[i];
	}
	seqlist->array[pos] = value;
	seqlist->size++;
}
void SeqListPopInsert(SeqList *seqlist, size_t pos)
{
	assert(seqlist != NULL);
	assert(seqlist->size > 0);
	assert(seqlist->array != NULL);
	assert(pos > 0 && pos <= seqlist->size);

	 //i��������
	for (size_t i = pos+1; i < seqlist->size; i++){
		seqlist->array[i-1] = seqlist->array[i];
	}
	seqlist->size--;
}
void SeqListPrint(const SeqList *seqlist)
{
	for (size_t i = 0; i < seqlist->size; i++){
		printf("%d ", seqlist->array[i]);
	}
	printf("\n");
}
void SeqListModify(SeqList *seqlist, size_t pos, SLDataType value)
{
	assert(pos >= 0 && pos < seqlist->size);

	seqlist->array[pos] = value;
}
size_t SeqListFind(const SeqList *seqlist, SLDataType value)
{
	for (size_t i = 0; i < seqlist->size; i++){
		if (seqlist->array[i] == value){
			return i;
		}
	}
	return -1;
}
void SeqListRemove(SeqList *seqlist, SLDataType value)
{
	size_t pos = SeqListFind(seqlist, value);
	if (pos != -1){
		SeqListPopInsert(seqlist, pos);
	}
}

bool SeqListEmpty(const SeqList *seqlist)
{
	return seqlist->size = 0;
}

size_t SeqListSize(const SeqList *seqlist)
{
	return seqlist->size;
}
void SeqListBubbleSort(SeqList *seqlist)
{
	size_t flag;
	for (size_t i = 0; i < seqlist->size - 1; i++){
		flag = 0;
		//һ��ð�ݹ���
		for (size_t j = 0; j < seqlist->size - 1 - i; j++){
			if (seqlist->array[j] > seqlist->array[j + 1]){
				Swap(seqlist->array + j, seqlist->array + j + 1);
				flag = 1;
			}
		}
		//һ��ð�ݽ���

		if (flag = 0){
			break;
		}
	}
}

size_t SeqListBinarySearch(const SeqList *seqlist, SLDataType value)
{
	size_t left = 0;
	size_t right = seqlist->size;

	while (left < right){
		size_t mid = (right - left) / 2 + left;
		if (seqlist->array[mid] == value){
			return mid;
		}
		else if (value < seqlist->array[mid]){
			right = mid;
		}
		else{
			left = mid + 1;
		}
	}
	return -1;
}
void SeqListRemoveAll(SeqList *seqlist, SLDataType value)
{
	assert(seqlist != NULL);
	assert(seqlist->size > 0);
#if 0  //O(n^2)     O(1)
	size_t pos;
	while ((pos = SeqListFind(seqlist, value)) != -1){
		SeqListPopInsert(seqlist, pos);
	}
#endif

#if 0
	SLDataType *array = (SLDataType*)malloc(sizeof(SLDataType)*seqlist->size);
	assert(array);

	size_t index = 0;
	for (size_t i = 0; i < seqlist->size; i++){
		if (seqlist->array[i] != value){
			array[index] = seqlist->array[i];
			index++;
		}
	}
	for (int j = 0; j < index; j++){
		seqlist->array[j] = array[j];
	}

	free(array);
	seqlist->size = index;
#endif
	size_t index = 0;
	for (size_t i = 0; i < seqlist->size; i++){
		if (seqlist->array[i] != value){
			seqlist->array[index] = seqlsit->array[i];
			index++;
		}
	}

	seqlist->size = index;

}



