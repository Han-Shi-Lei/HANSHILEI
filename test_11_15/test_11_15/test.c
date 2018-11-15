////一个数组中只有两个数字是出现一次， 
////其他所有数字都出现了两次。 
////找出这两个数字，编程实现。 
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <assert.h>

void Find_Dif_Num( int* str, int sz)
{
	int num = 0;
	int i = 0;
	int count = 0;
	int px = 0;
	int py = 0;
	int flag = 1;
	assert(*str != NULL);

	for( i = 0; i < sz; i++)
	{
	   num = num^str[i];
	}
	while(num)
	{
		if((num & flag) == 1)
		{
			break;
		}
		flag <<= 1;
	}
	for( i = 0; i < sz; i++)
	{
		if( str[i] & 1)
		{
			px ^= str[i];
		}
		else
		{
			py ^= str[i];
		}
	}
	printf("%d %d\n",px,py);
}

int main()
{
	int arr[] = { 1,2,3,4,5,6,1,2,3,4};
	int sz = sizeof(arr)/sizeof(arr[0]);

	Find_Dif_Num(arr, sz);

	system("pause");
	return 0;
}
////模拟实现strstr：
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <assert.h>

char* My_Strstr(const char* str1, const char* str2)
{
	char *cp = (char*)str1;
	char *substr = (char*)str2;
	char *s1 = NULL;
	assert(*str1 != NULL);
	assert(*str2 != NULL);
	if(*str2 == '\0')
	{
		return NULL;
	}
	while(*str2)
	{
		s1 = cp;
		substr  = str2;
		while(*s1 && *substr && *s1 == *substr)
		{
			s1++;
			substr++;
		}
		if(*substr == '\0')
		{
			return cp;
		}
		cp++;
	}
	return 0;
}

int main()
{
	const char arr1[] = "This is a simple string!";
	const char arr2[] = "simple";
	 printf("%s\n",My_Strstr(arr1, arr2));

	system("pause");
	return 0;
}
//实现strcmp
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int My_Strcmp(const char* src, const char* dst)
{
	int ret = 0;
	while(!(ret = *(unsigned char*)src - *(unsigned char*)dst) && *dst)
	{
		++src;
		++dst;
	}
	if(ret < 0)
	{
		ret = -1;
	}
	else if(ret > 0)
	{
		ret = 1;
	}
	return ret;
}
int main()
{
	char arr1[] = "hello,bit!";
	char arr2[] = "z";

	My_Strcmp(arr1, arr2);
	printf("%d\n",My_Strcmp(arr1,arr2));

	system("pause");
	return 0;
}
