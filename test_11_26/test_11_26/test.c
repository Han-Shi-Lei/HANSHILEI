////ģ��ʵ��strncpy
#define _CRT_SECURE_NO_WARNINGS    1
#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <assert.h>

char *my_strncpy(char *str,const char* arr,size_t sz)
{
	//strncpy�ķ���ָ��str��ָ�룻��Ϊ��ʵ�ֹ�����str��ָ���б䶯�����Զ���һ��dstָ�뱣��str�ĳ�ʼλ�ã�
	char *p = str;
	//����ָ���Ƿ�Ϊ�գ�
	assert(arr);
	while(sz--)
	{
		*str++ = *arr++;
	}
	//ע������ӣ��ַ��������ԡ�\0'��β��������󿽱���������'\0';
	*str = '\0';

	return p;
}

int main()
{
	const char arr[]="absdafsgdfg";
	char str[20];
	int len = strlen(arr);

	my_strncpy(str,arr,len);

	//��ӡ��
	printf("%s\n",str);

	system("pause");
	return 0;
}

//ģ��ʵ��strncat
#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <assert.h>

char *my_strncat(char *arr1,const char *arr2,size_t sz)
{
	//����arr1�ĳ�ʼλ�ã�
	char *ret = arr1;
	//ָ����ԣ��ж��Ƿ�Ϊ�գ�
	assert(arr1);
	assert(arr2);

	//�ַ���ƴ�ӣ�����Ҫ��arr1��\0'����ʼƴ�ӣ�
	while(*arr1)
	{
		arr1++;
	}

	while(sz--)
	{
		//���Ǻ���++��*����ֵ����������ȼ���
		*arr1++ = *arr2++;
	}
	return ret;
}
int main()
{
	char arr1[20] = "hello ";
	char arr2[] = "bit!";

	my_strncat(arr1,arr2,strlen(arr2));
	//��ӡ��
	printf("%s\n",arr1);

	system("pause");
	return 0;
}

//ģ��ʵ��strncmp��
#include <stdio.h>
#include <windows.h>
#include <assert.h>
#include <string.h>

int my_strncmp(const char *dst,const char *str,size_t sz)
{
	//����ָ���Ƿ�Ϊ�գ�
	assert(dst);
	assert(str);

	while(sz--)
	{
		if((*str != '\0') && (*dst != '\0') && (*dst == *str))
		{
			str++;
			dst++;
		}
		else
		{
			//ע����һ�㣬������ָ����Ӽ���
			return *dst - *str;
		}
	}
	return  0;
}


int main()
{ 
	char arr1[] = "abcd";
	char arr2[] = "abcf";

	//����һ������ret��
	int ret = my_strncmp(arr1,arr2,strlen(arr2));

	if(ret>0)
	{
		printf("string1 greater than string2\n");
	}
	if(ret<0)
	{
		printf("string1 smaller than string2\n");
	}
	if(ret==0)
	{
		printf("string1 equal than string2\n");
	}

	system("pause");
	return 0;
}