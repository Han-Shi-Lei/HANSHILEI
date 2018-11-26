////模拟实现strncpy
#define _CRT_SECURE_NO_WARNINGS    1
#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <assert.h>

char *my_strncpy(char *str,const char* arr,size_t sz)
{
	//strncpy的返回指向str的指针；因为在实现过程中str的指针有变动，所以定义一个dst指针保存str的初始位置；
	char *p = str;
	//断言指针是否为空；
	assert(arr);
	while(sz--)
	{
		*str++ = *arr++;
	}
	//注意这个坑，字符串必须以‘\0'结尾，所有最后拷贝完必须加上'\0';
	*str = '\0';

	return p;
}

int main()
{
	const char arr[]="absdafsgdfg";
	char str[20];
	int len = strlen(arr);

	my_strncpy(str,arr,len);

	//打印；
	printf("%s\n",str);

	system("pause");
	return 0;
}

//模拟实现strncat
#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <assert.h>

char *my_strncat(char *arr1,const char *arr2,size_t sz)
{
	//保存arr1的初始位置；
	char *ret = arr1;
	//指针断言，判断是否为空；
	assert(arr1);
	assert(arr2);

	//字符串拼接，所以要从arr1‘\0'处开始拼接；
	while(*arr1)
	{
		arr1++;
	}

	while(sz--)
	{
		//考虑后置++，*，赋值运算符的优先级；
		*arr1++ = *arr2++;
	}
	return ret;
}
int main()
{
	char arr1[20] = "hello ";
	char arr2[] = "bit!";

	my_strncat(arr1,arr2,strlen(arr2));
	//打印；
	printf("%s\n",arr1);

	system("pause");
	return 0;
}

//模拟实现strncmp；
#include <stdio.h>
#include <windows.h>
#include <assert.h>
#include <string.h>

int my_strncmp(const char *dst,const char *str,size_t sz)
{
	//断言指针是否为空；
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
			//注意这一点，必须用指针相加减；
			return *dst - *str;
		}
	}
	return  0;
}


int main()
{ 
	char arr1[] = "abcd";
	char arr2[] = "abcf";

	//定义一个整形ret；
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