#include "seqlist.h"

void SeqListTest1()
{
	SeqList seqlist;
	SeqListInit(&seqlist,2);
	SeqListPushBack(&seqlist, 1);
	SeqListPushBack(&seqlist, 2);
	SeqListPushBack(&seqlist, 3);
	//1,2,3

	SeqListPushFront(&seqlist, 2);
	SeqListPushFront(&seqlist, 4);
	SeqListPushFront(&seqlist, 6);
	//6,4,2,1,2,3

	
	SeqListInsert(&seqlist, 4, 10);
	//6,4,2,1,10,2,3
	SeqListPopInsert(&seqlist, 4);
	//6,4,2,1,2,3

	SeqListPopBack(&seqlist);
	//6,4,2,1,10,2

	SeqListPopFront(&seqlist);
	//4,2,1,10,2
    SeqListDestory(&seqlist);

}
int main()
{
	SeqListTest1();

}