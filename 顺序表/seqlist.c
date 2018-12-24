#include "seqlist.h"
#include <assert.h>
#include <stdlib.h>


//检查是否需要扩容，如果需要扩容则进行扩容
//保证函数结束后，容量一定够用
static void CheckCapacity(SeqList *seqlist)
{
	assert(seqlist != NULL);
	assert(seqlist->size <= seqlist->capacity);
	assert(seqlist->array != NULL);
	if (seqlist->size < seqlist->capacity){
		return;
	}
	//走到这里一定需要扩容
	size_t capacity = 2 * (seqlist->capacity);
	SLDataType *array = (SLDataType*)malloc(sizeof(SLDataType)*capacity);
	assert(array);
	//把老数据搬移过来
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


	//做数据搬移，i 代表空间下标
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
	
	//做数据搬移，i代表数据下标；
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

	//做数据搬移，i 代表数据下标；
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

	 //i代表数据
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
	return seqlist->size == 0;
}

size_t SeqListSize(const SeqList *seqlist)
{
	return seqlist->size;
}



