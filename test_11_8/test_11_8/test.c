//编写一个程序，从标准输入读取字符，并把它们写到标准输出中。所有非字母字符
//都完全按照它的输入形式输出，字母字符在输出前进行加密。

#define _CRT_SECURE_NO_WARNINGS    1
#include <stdio.h>
#include <stdlib.h>
 int main()
 {
	 int i = 0;
	 //创建两个一维数组；
	 char arr[128] = {0};
	 char brr[128] = {0};
	 //输入要加密的字符；
	 printf("请输入要加密的字母字符:>");
	 scanf("%s",&arr);
     //循环体；
	 for(i=0; i <= (sizeof(arr)/sizeof(arr[0])); i++)
	 {
		 //每个字母被修改为在字母表上距其13个位置（前或后）的字母；大小写字母都被转换；
		 if((arr[i] >= 'a' && arr[i] <= 'z') || (arr[i] >= 'A' && arr[i] <= 'Z'))
		 {
		 if((arr[i] >= 'a' && arr[i] <= 'm') || (arr[i] >= 'A' && arr[i] <= 'M'))
		 {
			 brr[i] = arr[i]+13;
		 }
		 else if((arr[i] >= 'n' && arr[i] <= 'z') || (arr[i] >= 'N' && arr[i] <= 'Z'))
		 {
			 brr[i] = arr[i]-13;
		 } 
		 }
		 //以上条件不符合，则不变，直接输出；
		 else
		 {
			 brr[i] = arr[i];
		 }
	 }
	 //brr[i] = '\0';
	 printf("%s\n",brr);

	 system("pause");
	 return 0;
 }