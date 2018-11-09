//写一个函数返回参数二进制中 1 的个数 
//比如： 15 0000 1111 4 个 1 
//程序原型： 
//int count_one_bits(unsigned int value) 
//{ 
//// 返回 1的位数 
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
	printf("请输入num:>");
	scanf("%d",&num);
	CountBits(num);
	printf("%d\n",CountBits(num));

	system("pause");
	return 0;
}
//获取一个数二进制序列中所有的偶数位和奇数位， 
//分别输出二进制序列。
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
typedef unsigned int u_int_t;
void CountBits(u_int_t date)
{
	u_int_t flag = 0x80000000;
	printf("偶数bits:> ");
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
	printf("奇数bits:> ");
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
	printf("请输入num:>");
	scanf("%d",&num);
	CountBits(num);

	system("pause");
	return 0;
}
//输出一个整数的每一位。 
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
	printf("请输入num:>");
	scanf("%d",&num);
    print(num);

	system("pause");
	return 0;
}
//编程实现： 
//两个int（32位）整数m和n的二进制表达中，有多少个位(bit)不同？ 
//输入例子: 
//1999 2299 
//输出例子:7	
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
	printf("请输入m和n的值:>");
	scanf("%d %d",&n,&m);
	DiffBits(m,n);
	printf("%d\n",DiffBits(m,n));

	system("pause");
	return 0;
}



