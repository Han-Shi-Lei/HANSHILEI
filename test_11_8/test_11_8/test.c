//��дһ�����򣬴ӱ�׼�����ȡ�ַ�����������д����׼����С����з���ĸ�ַ�
//����ȫ��������������ʽ�������ĸ�ַ������ǰ���м��ܡ�

#define _CRT_SECURE_NO_WARNINGS    1
#include <stdio.h>
#include <stdlib.h>
 int main()
 {
	 int i = 0;
	 //��������һά���飻
	 char arr[128] = {0};
	 char brr[128] = {0};
	 //����Ҫ���ܵ��ַ���
	 printf("������Ҫ���ܵ���ĸ�ַ�:>");
	 scanf("%s",&arr);
     //ѭ���壻
	 for(i=0; i <= (sizeof(arr)/sizeof(arr[0])); i++)
	 {
		 //ÿ����ĸ���޸�Ϊ����ĸ���Ͼ���13��λ�ã�ǰ��󣩵���ĸ����Сд��ĸ����ת����
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
		 //�������������ϣ��򲻱䣬ֱ�������
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