//ʵ��һ�����������������ַ����е�k���ַ��� 
//ABCD����һ���ַ��õ�BCDA 
//ABCD���������ַ��õ�CDAB 

#define _CRT_SECURE_NO_WARNINGS    1
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <assert.h>
//����һ��
//void LeftMove1(char str[], int size, int n)
//{
//	int num = n%size;
//	int i = 0;
//	for( ; i < num; i++)
//	{
//		int tmp = str[0];
//		int j = 1;
//		for( ; j < size; j++)
//		{
//			str[j-1] = str[j];
//		}
//		str[j-1] = tmp;
//	}
//
//}
//��������
void ReverseString(char* start, char* end)
{
	assert(start);
	assert(end);
	while(start<end)
	{
		*start ^= *end;
		*end ^= *start;
		*start ^= *end;
		start++;
		end--;
	}

}
void LeftMove2(char str[], int size, int n)
{
	int num = n%size;
	ReverseString(str, str+num-1);
	ReverseString(str+num, str+size-1);
	ReverseString(str, str+size-1);

}
int main()
{
	char arr[] = "ABCD";
	int len = strlen(arr);
	int k = 0;
	printf("������k�Ĵ�С:>");
	scanf("%d",&k);
	/*LeftMove1(arr, len, k);
	printf("%s\n",arr);*/
	LeftMove2(arr, len, k);
	printf("%s\n",arr);

	system("pause");
	return 0;
}