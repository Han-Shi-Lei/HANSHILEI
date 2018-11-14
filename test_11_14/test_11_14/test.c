//喝汽水，1瓶汽水1元，2个空瓶可以换一瓶汽水， 
//给20元，可以喝多少汽水。 
//编程实现。
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>

#pragma warning(disable:4996)


int Drink_Soda(int money)
{
	const int price = 1;
	int bottle = money/price;
	int sum = bottle;
	while(bottle != 1)
	{
		sum = sum + bottle/2;
		if(bottle%2 == 1)
		{
			bottle = bottle/2 + 1;
		}
		else
		{
			bottle = bottle/2;
		}
	}
	return sum;
}

int main()
{
	int money = 0;

	printf("money = ");
	scanf("%d",&money);

	printf("%d\n",Drink_Soda(money));

	system("pause");
	return 0;
}
/*模拟实现strcpy*/ 
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <assert.h>
void My_Strcpy(char* arr2, const char* arr1)
{
	int len  = strlen(arr1);
	int i = 0;
	assert(arr2 != NULL);
	while(arr1[i] != '\0')
	{
		arr2[i] = arr1[i];
		i++;
	}
}
int main()
{
	char arr1[] = "Hello Bit！";
	char arr2[20] = "";
	int len = strlen(arr1);
	My_Strcpy(arr2, arr1);

	printf("arr1 : %s \narr2 : %s\n ",arr1,arr2);

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