//5λ�˶�Ա�μ���10��̨��ˮ����������������Ԥ�������� 
//Aѡ��˵��B�ڶ����ҵ����� 
//Bѡ��˵���ҵڶ���E���ģ� 
//Cѡ��˵���ҵ�һ��D�ڶ��� 
//Dѡ��˵��C����ҵ����� 
//Eѡ��˵���ҵ��ģ�A��һ�� 
//����������ÿλѡ�ֶ�˵����һ�룬����ȷ�����������Ρ� 
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
//�ձ�ĳ�ط�����һ��ıɱ��������ͨ���Ų�ȷ��ɱ�����ֱ�Ϊ4�� 
//���ɷ���һ��������Ϊ4�����ɷ��Ĺ��ʡ� 
//A˵�������ҡ� 
//B˵����C�� 
//C˵����D�� 
//D˵��C�ں�˵ 
//��֪3����˵���滰��1����˵���Ǽٻ��� 
//�����������Щ��Ϣ��дһ��������ȷ������˭�����֡�
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
//������������ƽ������
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
	printf("������a,b������:>");
	scanf("%d %d",&a,&b);
	Avg(a,b);
	printf("%d\n",Avg(a,b));

	system("pause");
	return 0;
}

