//дһ���������ز����������� 1 �ĸ��� 
//���磺 15 0000 1111 4 �� 1 
//����ԭ�ͣ� 
//int count_one_bits(unsigned int value) 
//{ 
//// ���� 1��λ�� 
//} 
#define _CRT_SECURE_NO_WARNINGS    1
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

unsigned int CountBits(unsigned int n)
{
	int count = 0;
	while(n)
	{
		n &= (n-1);
		count++;
	}
	return count;
}

int main()
{
	int num = 0;
	printf("������num:>");
	scanf("%d",&num);
	CountBits(num);
	printf("%d\n",CountBits(num));

	system("pause");
	return 0;
}
//��ȡһ�������������������е�ż��λ������λ�� 
//�ֱ�������������С�
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
typedef unsigned int u_int_t;
void CountBits(u_int_t date)
{
	u_int_t flag = 0x80000000;
	printf("ż��bits:> ");
	while(flag)
	{
		if(date & flag)
		{
			printf("1 ");
		}
		else
		{
			printf("0 ");
		}
		flag >>= 2;
	}
	printf("\n");
    flag = 0x40000000;
	printf("����bits:> ");
	while(flag)
	{
		if(date & flag)
		{
			printf("1 ");
		}
		else
		{
			printf("0 ");
		}
		flag >>= 2;
	}
	printf("\n");
}
int main()
{
	int num = 0;
	printf("������num:>");
	scanf("%d",&num);
	CountBits(num);

	system("pause");
	return 0;
}
//���һ��������ÿһλ�� 
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
typedef unsigned int u_int_t;
void print(u_int_t date)
{
	u_int_t flag = 0x80000000;
	while(flag)
	{
		if(date & flag)
		{
			printf("1 ");
		}
		else
		{
			printf("0 ");
		}
		flag >>= 1;
	}
	printf("\n");
}

int main()
{
	int num = 0;
	printf("������num:>");
	scanf("%d",&num);
    print(num);

	system("pause");
	return 0;
}
//���ʵ�֣� 
//����int��32λ������m��n�Ķ����Ʊ���У��ж��ٸ�λ(bit)��ͬ�� 
//��������: 
//1999 2299 
//�������:7	
#define _CRT_SECURE_NO_WARNINGS    1
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define NUM 8
typedef unsigned int u_int_t;

int DiffBits(u_int_t x, u_int_t y)
{
	u_int_t ret = x^y;
	u_int_t flag = 0x80000000;
	int count = 0;
	int top = sizeof(ret)*NUM;
	while(top)
	{
		if(ret & flag)
		{
			count++;
		}
		flag >>= 1;
		top--;
	}
	return count;

}
int main()
{
	int m = 0;
	int n = 0;
	printf("������m��n��ֵ:>");
	scanf("%d %d",&n,&m);
	DiffBits(m,n);
	printf("%d\n",DiffBits(m,n));

	system("pause");
	return 0;
}



