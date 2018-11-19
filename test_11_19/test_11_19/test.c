#define _CRT_SECURE_NO_WARNINGS    1
#include <stdio.h>
#include <stdlib.h>
int main()
{
	char a[5]={'A','B','C','D'};
    char(*p3)[2]= &a;
    char(*p4)[2]= a;

	system("pause");
	return 0;
}
//回调函数就是一个通过函数指针调用的函数。如果你把函数的指针（地址）
//作为参数传递给另一个函数，当这个指针被用来调用其指向的函数时，我们
//就说这是回调函数。回调函数不是由该函数的实现方直接调用，而是在特定
//的事件或条件发生时由另外的一方调用的，用于对该事件或条件进行响应。
//首先演示一下qsort函数的使用：
#include <stdio.h>
#include <stdlib.h>

int int_cmp(const void* p1, const void* p2)
{
	return (*(int*)p1 > *(int*)p2);
}

int main()
{

	int arr[] = {1,3,5,7,9,2,4,6,8,10};
	int i = 0;
	qsort(arr, sizeof(arr)/sizeof(arr[0]),sizeof(int),int_cmp);
	for(i = 0;i < sizeof(arr)/sizeof(arr[0]);i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");


	system("pause");
	return 0;

}
//使用回调函数，模拟实现qsort（采用冒泡的方式）。
#include <stdio.h>
#include <stdlib.h>

int int_cmp(const void* p1, const void* p2)
{
	return (*(int*)p1 > *(int*)p2);
}

void _swap(void *p1,void *p2, int size)
{
	int i = 0;
	for(i = 0; i < size; i++)
	{
		char tmp = *((char*)p1+i);
		*((char*)p1 + i) = *((char*)p2 + i);
		*((char*)p2 + i) = tmp;
	}
}

void bubble(void *base, int count,int size,int(*cmp)(void *,void *))
{
	int i = 0;
	int j = 0;
	for(i = 0; i < count-1; i++)
	{
		for( j = 0; j < count-1-i; j++)
		{
			if(cmp((char*)base + j*size, (char*)base + (j+1)*size)> 0)
			{
				_swap((char*)base + j*size, (char*)base + (j+1)*size, size);
			}
		}
	}
}

int main()
{
	int arr[] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 10, 0 };
	int i = 0;
	bubble(arr, sizeof(arr)/sizeof(arr[0]),sizeof(int),int_cmp);
	for(i = 0; i < sizeof(arr)/sizeof(arr[0]);i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");

	system("pause");
	return 0;
}

//一维数组
#include <stdio.h>
#include <stdlib.h>
int main()
{
	int a[] = { 1, 2 ,3, 4 };

	printf("%d\n",sizeof(a));       //16			
	printf("%d\n",sizeof(a+0));     //4
	printf("%d\n",sizeof(*a));      //4
	printf("%d\n",sizeof(a+1));     //4
	printf("%d\n",sizeof(a[1]));    //4
	printf("%d\n",sizeof(&a));      //4
	printf("%d\n",sizeof(*&a));     //16
	printf("%d\n",sizeof(&a+1));    //4
	printf("%d\n",sizeof(&a[0]));   //4
	printf("%d\n",sizeof(&a[0]+1)); //4
	


	system("pause");
	return 0;
}

//字符数组

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f'};
	char arr1[] = "abcdef";
	char *p = "abcdef";

	printf("%d\n",sizeof(arr));          //6
	printf("%d\n",sizeof(arr+0));        //4
	printf("%d\n",sizeof(*arr));         //1
	printf("%d\n",sizeof(arr[1]));       //1
	printf("%d\n",sizeof(&arr));         //4
	printf("%d\n",sizeof(&arr+1));       //4
	printf("%d\n",sizeof(&arr[0]+1));    //4

	/*printf("%d\n",strlen(arr));  
	printf("%d\n",strlen(arr+0));
	printf("%d\n",strlen(*arr));
	printf("%d\n",strlen(arr[1]));
	printf("%d\n",strlen(&arr));
	printf("%d\n",strlen(&arr+1));
	printf("%d\n",strlen(&arr[0]+1));*/

	printf("%d\n",sizeof(arr1));       //7
	printf("%d\n",sizeof(arr1+0));     //4   
	printf("%d\n",sizeof(*arr1));      //1  
	printf("%d\n",sizeof(arr1[1]));    //1    
	printf("%d\n",sizeof(&arr1));      //4  
	printf("%d\n",sizeof(&arr1+1));    //4    
	printf("%d\n",sizeof(&arr1[0]+1)); //4  

	//printf("%d\n",strlen(arr1));       //6      
	//printf("%d\n",strlen(arr1+0));     //6  
	//printf("%d\n",strlen(*arr1));      //报错
	//printf("%d\n",strlen(arr1[1]));    //报错  
	//printf("%d\n",strlen(&arr1));      //6
	//printf("%d\n",strlen(&arr1+1));    //不确定 
	//printf("%d\n",strlen(&arr1[0]+1)); //5

	printf("%d\n",sizeof(p));          //4
	printf("%d\n",sizeof(p+1));        //4 
	printf("%d\n",sizeof(*p));         //1
	printf("%d\n",sizeof(p[0]));       //1
	printf("%d\n",sizeof(&p));         //4
	printf("%d\n",sizeof(&p+1));       //4
	printf("%d\n",sizeof(&p[0]+1));    //4
 
	//printf("%d\n",strlen(p));        //6    
	//printf("%d\n",strlen(p+1));      //5    
	//printf("%d\n",strlen(*p));       //错误
	//printf("%d\n",strlen(p[0]));     //错误
	//printf("%d\n",strlen(&p));       //不确定 
	//printf("%d\n",strlen(&p+1));     //不确定
	//printf("%d\n",strlen(&p[0]+1));  //5  

	system("pause");
	return 0;
}

//二维数组

#include <stdio.h>
#include <stdlib.h>
int main()
{
	int arr[3][4] = {0};

	printf("%d\n",sizeof(arr));             //48
	printf("%d\n",sizeof(arr[0][0]));       //4
	printf("%d\n",sizeof(arr[0]));          //16
	printf("%d\n",sizeof(arr[0]+1));        //4
	printf("%d\n",sizeof(*(arr[0]+1)));     //4
	printf("%d\n",sizeof(arr+1));           //4
	printf("%d\n",sizeof(*(arr+1)));        //16
	printf("%d\n",sizeof(&arr[0]+1));       //4
	printf("%d\n",sizeof(*(&arr[0]+1)));    //16
	printf("%d\n",sizeof(*arr));            //16
	printf("%d\n",sizeof(arr[3]));          //16


	system("pause");
	return 0;
}