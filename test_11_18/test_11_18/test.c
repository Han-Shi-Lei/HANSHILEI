//实现strlen函数；
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int my_strlen1(const char* str)
{
	int count = 0;
  assert(str != NULL);
	while(*str)
	{
		count++;
		str++;
	}
	return count;
}

int my_strlen2(const char* dst)
{
   assert(dst != NULL);
	if(*dst == '\0')
	{
		return 0;
	}
	else
	{
		return 1+my_strlen2(dst+1);
	}
}

int my_strlen3(const char* src)
{
	const char *p = src;
 assert(src != NULL);
	while(*p != '\0')
	{
		p++;
	}
	return p - src;
}

int main()
{
	const char arr[] = "abcdefg";
	my_strlen1(arr);
	my_strlen2(arr);
	my_strlen3(arr);
	printf("%d %d %d\n",my_strlen1(arr),my_strlen2(arr),my_strlen3(arr));

	system("pause");
	return 0;
}
//模拟实现strcpy；
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


char *my_strcpy(char* dst, char* src)
{
	char* ret = dst;
	assert(src != NULL);
	assert(dst != NULL);
	while(*dst++ = *src++)
	{
		;
	}
	return ret;
}
int main()
{
	char arr1[] = "abcdefgh";
	char arr2[20];
	my_strcpy(arr2, arr1);
	printf("%s\n",arr2);

	system("pause");
	return 0;
}
//模拟实现strcat
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <assert.h>
#pragma warning(disable:4996)

void My_Strcat(char* arr2,const char* arr1)
{
	//断言；
	assert(arr2 != NULL);
	assert(arr1 != NULL);
	while(*arr2)
	{
		arr2++;
	}
	while(*arr2++ = *arr1++)
	{
		;
	}

}

int main()
{
	const char arr1[] = "Hello Bit!";
	char arr2[30] = "";
	strcpy(arr2,arr1);
	My_Strcat(arr2,arr1);
	printf("%s\n",arr2);


	system("pause");
	return 0;
}
//模拟实现strstr：
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <assert.h>

char* My_Strstr(const char* str1, const char* str2)
{
	char *cp = (char*)str1;
	char *substr = (char*)str2;
	char *s1 = NULL;
	assert(str1 != NULL);
	assert(str2 != NULL);
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
//实现strchr 
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <assert.h>
char* My_Strchr(char* arr1,char p)
{
	assert(arr1);
	while(*arr1)
	{
		if(*arr1 == p)
		{
			return arr1;
		}
		else
		{
			arr1++;
		}	
	}
	return NULL;
	
}

int main()
{
	char str1[] = "plsce";
	char p = 's';
    char* ret = My_Strchr(str1, p);
	printf("%s\n",ret);

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
//实现memcpy 
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <assert.h>
void* my_memcpy(void* dst,const void* src, int count)
{
	
	char* dst1 = (char*)dst;
	const char* src1 = (const char*)src;
	assert(dst != NULL);
	assert(src != NULL);
	
	while(count--)
	{
		*dst1 = *src1;
		dst1++,src1++;
	}
	return dst;
}
int main()
{
    char a[] ="abcde";
	char b[20];
	my_memcpy(b, a, sizeof(a));
	printf("%s\n",b);
	

	system("pause");
	return 0;
}
//模拟实现memmove;
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
void *my_memmove( char * dst, const char *src, int count)
{
	assert(dst != NULL);
	assert(src != NULL);
	if (src < dst && dst < (dst + count))
	{
		char* dst1 = (char*)dst + count - 1;
		const char* src1 = (char*)src + count - 1;
		while(count--)
		{
			*dst1-- = *src1--;
		}
	}

	else
	{
		//left -> right;
		char* dst1 = (char*)dst;
		const char* src1 = (const char*)src;
		assert(dst != NULL);
		assert(src != NULL);
		
		while(count--)
		{
			*dst1 = *src1;
			dst1++,src1++;
		}
	}
	return dst;
}
int main()
{
	char a[] = "abcdef1234high";
	char b[30];
	char c[] = "abcdef1234high";
	my_memmove( b, a, sizeof(a));
	printf("%s\n",b);
	my_memmove( a, a+1, sizeof(a));
	printf("%s\n",a);//bcdef1234high
	my_memmove( c+1, c, sizeof(c));
	printf("%s\n",c);//aabcdef1234high

	system("pause");
	return 0;
}

