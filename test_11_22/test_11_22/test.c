//λ��
//λ�ε������ͽṹ�����Ƶģ���������ͬ��
//1��λ�εĳ�Ա������int��unsigned int��char �� signed int��
//2��λ�εĳ�Ա�����һ��ð�ź�һ�����֡�
//
//���ӣ�
#include <stdio.h>
#include <windows.h>

struct A
{ 
	int _a:2;
	int _b:5;
	int _c:10;
	int _d:30;
};
struct B
{ 
	char _a:2;
	char _b:5;
	char _c:2;
	char _d:3;
};
struct C
{ 
	int _a:30;
	int _b:30;
	int _c:10;
	int _d:30;
};

   
int main()
{
    printf("%d\n",sizeof(struct A));//8
    printf("%d\n",sizeof(struct B));//4
    printf("%d\n",sizeof(struct C));//16
    
	system("pause");
	return 0;
}
//����������֤��
//1��λ�εĴ�С�ɳ�Ա���;����������㷨���ܷ��¾ͷ��£��Ų������ٵ������١�
//2��λ��ʹ�÷ǳ�������ƽ̨��
//3��ʹ��λ�α��뿼��λ�εĿ���ֲ�ԡ�
//λ�ε��ڴ����
//1��λ�εĳ�Ա������int��unsigned int ��signed int����
//char���������μ������ͣ����͡�
//2��λ�εĿռ��ǰ�����Ҫ��4���ֽڣ�int������һ���ֽڣ�char���ķ�ʽ���ٵġ�
//3��λ���ǲ���ƽ̨�ģ�����ֲ�ĳ������ʹ��λ�Ρ�
//���ӣ�
#include <stdio.h>
#include <windows.h>
 
struct S
{
	char a : 3;
	char b : 4;
	char c : 5;
	char d : 4;
};

int main()
{
	struct S s;

    memset(&s,0,sizeof(s));
	s.a = 10;
	s.b = 12;
	s.c = 3;
	s.d = 4;

	system("pause");
	return 0;
}


//λ�εĿ�ƽ̨����
//1��intλ�α������з��Ż����޷��Ų�ȷ���ġ�
//2��λ�������λ������Ŀ����ȷ������16λ�������16,32λ�������32��д��
//27��16λ������������⡣
//3��λ�εĳ�Ա���ڴ����ڴ����������һ��Ǵ���������δ���塣
//4����һ���ṹ���������λ�Σ��ڶ���λ�γ�Ա�Ƚϴ��޷������ڵ�һ��λ��
//ʣ��ʱ���������������õģ���Ҳ�ǲ�ȷ���ġ�

//
//���ϣ������壩
//���г�Ա����һ����Ա��
//�������ַ����һ���ġ�
//�����������С��
#include <stdio.h>
#include <windows.h>

union un
{
	char c;
	int i;
}x;

int main()
{
    x.i = 1;
	if( 1 == (x.c))
	{
		printf("С��\n");
	}
	else
	{
		printf("���\n");
	}

	system("pause");
	return 0;
}


