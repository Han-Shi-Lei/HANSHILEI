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
//�ص���������һ��ͨ������ָ����õĺ����������Ѻ�����ָ�루��ַ��
//��Ϊ�������ݸ���һ�������������ָ�뱻����������ָ��ĺ���ʱ������
//��˵���ǻص��������ص����������ɸú�����ʵ�ַ�ֱ�ӵ��ã��������ض�
//���¼�����������ʱ�������һ�����õģ����ڶԸ��¼�������������Ӧ��
//������ʾһ��qsort������ʹ�ã�
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
//ʹ�ûص�������ģ��ʵ��qsort������ð�ݵķ�ʽ����
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

//һά����
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

//�ַ�����

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
	//printf("%d\n",strlen(*arr1));      //����
	//printf("%d\n",strlen(arr1[1]));    //����  
	//printf("%d\n",strlen(&arr1));      //6
	//printf("%d\n",strlen(&arr1+1));    //��ȷ�� 
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
	//printf("%d\n",strlen(*p));       //����
	//printf("%d\n",strlen(p[0]));     //����
	//printf("%d\n",strlen(&p));       //��ȷ�� 
	//printf("%d\n",strlen(&p+1));     //��ȷ��
	//printf("%d\n",strlen(&p[0]+1));  //5  

	system("pause");
	return 0;
}

//��ά����

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