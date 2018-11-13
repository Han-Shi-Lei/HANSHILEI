//在屏幕上打印杨辉三角。 
//1 
//1 1 
//1 2 1 
//1 3 3 1 

#define _CRT_SECURE_NO_WARNINGS    1
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>

void Yang(int n)
{
	int **p = (int**)malloc(sizeof(int*) * n);
	int i = 0;
	for( ; i < n; i++)
	{
		p[i] = (int*)malloc(sizeof(int) * n);
	}
	for( i = 0; i < n; i++)
	{
		p[i][0] = 1;
		p[i][i] = 1;
	}
    i = 2;
	for( ; i < n; i++)
	{
		int j = 1;
		for( ; j < i; j++)
		{
			p[i][j] = p[i-1][j-1]+p[i-1][j];
		}
	}
	for( i = 0; i < n; i++)

	{
		int j = 0;
		for( ; j < n-i; j++)
		{
			printf("%2c",' ');
		}

		j = 0;
		for( ; j <= i; j++)
		{
			printf("%3d ",p[i][j]);
		}
		printf("\n");
	}
	for(i = 0; i < n; i++)
	{
		free(p[i]);
	}
	free(p);

}
int main()
{
	int n = -1;
	printf("Please Enter:");
	scanf("%d",&n);

	Yang(n);

	system("pause");
	return 0;
}
//编写函数： 
//unsigned int reverse_bit(unsigned int value); 
//这个函数的返回值value的二进制位模式从左到右翻转后的值。 
//
//如： 
//在32位机器上25这个值包含下列各位： 
//00000000000000000000000000011001 
//翻转后：（2550136832） 
//10011000000000000000000000000000 
//程序结果返回： 
//2550136832 
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
int Reverse(const int x)
{
	int top = sizeof(int)*8;
	int flag = 1;
	int y = 0;
	int i = 0;
	while(i<top)
	{
		if(x & (flag<<i))
		{
			y |=  flag<<(31 - i);
		}
		i++;
	}
	return y;
}
int main()
{
	int x = 25;
	int y = Reverse(x);

	printf("%u : %u\n",x,y);

	system("pause");
	return 0;
}