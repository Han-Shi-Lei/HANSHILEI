//结构体内存对齐。

#include <stdio.h>
#include <stdlib.h>
struct S1
{
	char c1;
	int i;
	char c2;
};

struct S2
{
	char c1;
	char c2;
	int i;
};

struct S3
{
	double d;
	char c;
	int i;
};

struct S4
{
	char c1;
	struct S3 s3;
	double d;
};

int main()
{
	
	printf("%d\n",sizeof(struct S1));  //12
	printf("%d\n",sizeof(struct S2));  //8
	printf("%d\n",sizeof(struct S3));  //16
	printf("%d\n",sizeof(struct S4));  //32


	system("pause");
	return 0;
}

//修改默认对齐数。
#include <stdio.h>
#include <stdlib.h>
//设置默认对齐数8;
#pragma pack(8)    

struct S1
{
	char c1;
	int i;
	char c2;
};

//取消默认对齐数,还原默认。

#pragma pack()

#pragma pack(1)

struct S2
{
	char c1;
	int i;
	char c2;
};
//取消设置的默认对齐数，还原默认。
#pragma pack()

int main()
{
	//输出结果。

	printf("%d\n",sizeof(struct S1));  //12
	printf("%d\n",sizeof(struct S2));  //6

	system("pause");
	return 0;
}

//结论:
//结构体在对齐方式不合适的时候，我们可以修改默认对齐数。


