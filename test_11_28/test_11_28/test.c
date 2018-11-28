//�ļ��ı���
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#pragma warning(disable:4996)

int main()
{
	//ע�⣺int����char��Ҫ����EOF
	int c;
	FILE* fp = fopen("test.txt","r");
	if(!fp)
	{
		perror("File opening failed");
		return EXIT_FAILURE;
	}
	//fgetc ����ȡʧ�ܵ�ʱ����������ļ�������ʱ�򣬶��᷵��EOF
	//��׼c I/O��ȡ�ļ�ѭ����
	while((c = fgetc(fp)) != EOF)
	{
		putchar(c);
	}
	printf("\n");
	//�ж���ʲôԭ�������
	if(ferror(fp))
	{
		puts("I/O error when reading!");
	}
	else if(feof(fp))
	{
		puts("End of file reached successfully!");
	}
	fclose(fp);
	system("pause");
	return 0;
}

//�������ļ���
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#pragma warning(disable:4996)

#define SIZE 5
int main()
{
	double a[SIZE] = {1.0, 2.0, 3.0, 4.0, 5.0};
	double b[SIZE] = { 0.0 };
	int n = 0;

	size_t ret_code = 0;
	//������ö�����ģʽ��
	FILE *fp = fopen("test.bin", "wb");
	//дdouble�����飻
	fwrite(a, sizeof(*a),SIZE,fp);

	fclose(fp);

	fp = fopen("test.bin","rb");
	ret_code = fread( b, sizeof(*b), SIZE, fp);
	if(ret_code == SIZE)
	{
		puts("Array read successfully,contents:");
		for( n = 0; n < SIZE; n++)
		{
			printf("%f ",b[n]);
		}
		putchar('\n');
	}
	//error handling
	else
	{
		if(feof(fp))
		{
			printf("Error reading test.bin: unexpected end of file\n");
		}
		else if (ferror(fp))
		{
			perror("Error reading test.bin");
		}
	}
	fclose(fp);

	system("pause");
	return 0;
}



