//打印杨辉三角。
//#define _CRT_SECURE_NO_WARNINGS    1
//#include <stdio.h>
//#include <stdlib.h>
//
//void yhtp(int k)
//{s
//	int arr[100][100] = {0};
//	int i = 0;
//	int j = 0;
//	for(i=0; i<k; i++)
//	{
//		arr[i][0] = 1;
//		arr[i][i] = 1;
//	}
//	for(i=2; i<k; i++)
//	{
//		for(j=1; j<k; j++)
//		{
//			arr[i][j] = arr[i-1][j-1]+arr[i-1][j];
//		}
//	}
//	for(i=0; i<k; i++)
//	{
//		for(j=0; j<=i; j++)
//		{
//			printf("%3d",arr[i][j]);
//		}
//		putchar('\n');
//	}
//}
//int main()
//{
//	int n = 0;
//	printf("请输入n的值:>");
//	scanf("%d",&n);
//	yhtp(n);
//
//	system("pause");
//	return 0;
//}
//输出一个整数的每一位。

#include <stdio.h>
#include <stdlib.h>
//递归实现；
void print1(int k)
{
	if(k>9)
	{
	print1(k/10);
	}
	printf("%d ",k%10);

}
//非递归实现，倒着打印；
void print2(int num)
{
	while(num)
	{
		printf("%d ",num%10);
		num /= 10;
	}
}
int main()
{
	int n = 0;
	printf("请输入n的值:>");
	scanf("%d",&n);
	print1(n);
	putchar('\n');
	print2(n);
	putchar('\n');

	system("pause");
	return 0;
}