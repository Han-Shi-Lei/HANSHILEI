//�ṹ���ڴ���롣

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

//�޸�Ĭ�϶�������
#include <stdio.h>
#include <stdlib.h>
//����Ĭ�϶�����8;
#pragma pack(8)    

struct S1
{
	char c1;
	int i;
	char c2;
};

//ȡ��Ĭ�϶�����,��ԭĬ�ϡ�

#pragma pack()

#pragma pack(1)

struct S2
{
	char c1;
	int i;
	char c2;
};
//ȡ�����õ�Ĭ�϶���������ԭĬ�ϡ�
#pragma pack()

int main()
{
	//��������

	printf("%d\n",sizeof(struct S1));  //12
	printf("%d\n",sizeof(struct S2));  //6

	system("pause");
	return 0;
}

//����:
//�ṹ���ڶ��뷽ʽ�����ʵ�ʱ�����ǿ����޸�Ĭ�϶�������


