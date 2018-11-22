//位段
//位段的声明和结构是类似的，有两个不同：
//1、位段的成员必须是int、unsigned int、char 或 signed int。
//2、位段的成员后边有一个冒号和一个数字。
//
//例子：
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
//经过代码验证：
//1、位段的大小由成员类型决定，它的算法是能放下就放下，放不下了再单独开辟。
//2、位段使用非常依赖于平台。
//3、使用位段必须考虑位段的可移植性。
//位段的内存分配
//1、位段的成员可以是int、unsigned int 、signed int或者
//char（属于整形家族类型）类型。
//2、位段的空间是按照需要以4个字节（int）或者一个字节（char）的方式开辟的。
//3、位段是不跨平台的，可移植的程序避免使用位段。
//例子：
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


//位段的跨平台问题
//1、int位段被当成有符号还是无符号不确定的。
//2、位段中最大位数的数目不能确定。（16位机器最大16,32位机器最大32，写成
//27在16位机器会出现问题。
//3、位段的成员在内存中内存分配从左向右还是从右向左尚未定义。
//4、当一个结构体包含两个位段，第二个位段成员比较大，无法容纳于第一个位段
//剩余时，是舍弃还是利用的，这也是不确定的。

//
//联合（公用体）
//所有成员共用一个成员。
//联合体地址都是一样的。
//用联合体检查大小端
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
		printf("小端\n");
	}
	else
	{
		printf("大端\n");
	}

	system("pause");
	return 0;
}


