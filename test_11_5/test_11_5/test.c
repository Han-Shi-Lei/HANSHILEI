#define _CRT_SECURE_NO_WARNINGS    1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
int	Judge(char* arr1, char* arr2)
{
	int i = 0;
	int j = 0;
	int len = strlen(arr1);
	  for(j=0; j<len; j++)
    	{
    		{
    			char tmp = arr1[0];
    			for(i=0; i<len-1; i++)
    			{
    				arr1[i] = arr1[i+1];
    			}
    			arr1[len-1] = tmp;
    		}
    		if(0 == strcmp(arr1, arr2))
    		{
    		return 1;
    		}
    	}
	  return 0;

}

 
int main()
{
	char str1[10] = "";
	char str2[10] = "";
	printf("ÇëÊäÈë×Ö·û´®str1:");
	scanf("%s",&str1);
	printf("ÇëÊäÈë×Ö·û´®str2:");
	scanf("%s",&str2);
	printf("str1:%s\n",str1);
	printf("str2:%s\n",str2);
	Judge(str1, str2);
	if(1 == Judge(str1, str2))
	{
		printf("ÊÇÐý×ªºóµÄ×Ö·û´®£¡\n");
	}
	if(0 == Judge(str1, str2))
	{
		printf("²»ÊÇÐý×ªºóµÄ×Ö·û´®£¡\n");
	}


	system("pause");
	return 0;

}
