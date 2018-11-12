//5位运动员参加了10米台跳水比赛，有人让他们预测比赛结果 
//A选手说：B第二，我第三； 
//B选手说：我第二，E第四； 
//C选手说：我第一，D第二； 
//D选手说：C最后，我第三； 
//E选手说：我第四，A第一； 
//比赛结束后，每位选手都说对了一半，请编程确定比赛的名次。 
#define _CRT_SECURE_NO_WARNINGS    1
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
void PlayNo()
{
	int a = 1;
	int b = 1;
	int c = 1;
	int d = 1;
	int e = 1;
	unsigned int flag = 0;
	for(a = 1; a <= 5; a++)
	{
		for(b = 1; b <= 5; b++)
		{
			flag = 0;
			for(c = 1; c <= 5; c++)
			{
				for(d = 1; d <= 5; d++)
				{
					for(e = 1; e <= 5; e++)
					{
						if( (2 == b) + (3 == a) == 1 && \
							(2 == b) + (4 == e) == 1 && \
							(1 == c) + (2 == d) == 1 && \
							(5 == c) + (3 == d) == 1 && \
							(4 == e) + (1 == a) == 1)
						{
							flag = 0;
							flag |= (1 << (a-1));
							flag |= (1 << (b-1));
							flag |= (1 << (c-1));
							flag |= (1 << (d-1));
							flag |= (1 << (e-1));
							/*if( 1 == flag || 3 == flag || 7 == flag || 15 == flag || 31 == flag)
							{
							printf("a = %d b = %d c = %d d = %d e = %d",\
								a,b,c,d,e);
							printf("\n");
							}*/
							while(flag)
							{
								if(!(flag & 1))
								{
									break;
								}
								flag >>= 1;
							}
							if(flag == 0)
							{
							printf("a = %d b = %d c = %d d = %d e = %d",\
							a,b,c,d,e);
							printf("\n");
							}
						}
					}
				}
			}
		}
	}
}

int main()
{
	PlayNo();


	system("pause");
	return 0;
}
//日本某地发生了一件谋杀案，警察通过排查确定杀人凶手必为4个 
//嫌疑犯的一个。以下为4个嫌疑犯的供词。 
//A说：不是我。 
//B说：是C。 
//C说：是D。 
//D说：C在胡说 
//已知3个人说了真话，1个人说的是假话。 
//现在请根据这些信息，写一个程序来确定到底谁是凶手。
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
void FindKiller()
{
	char killer = 'A';
	for( ; killer <= 'D'; killer++)
	{
		if((killer != 'A') + (killer == 'C')+\
			(killer == 'D') + (killer != 'D') == 3)
		{
			printf("killer: %c\n",killer);
		}
	}

}
int main()
{
	FindKiller();

	system("pause");
	return 0;
}
//计算两个数的平均数；
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#pragma warning(disable:4996)
int Avg( int x,  int y)
{
	return (x & y) + ((x ^ y) >> 1);
}
int main()
{
	int a = 0;
	int b = 0;
	printf("请输入a,b两个数:>");
	scanf("%d %d",&a,&b);
	Avg(a,b);
	printf("%d\n",Avg(a,b));

	system("pause");
	return 0;
}

