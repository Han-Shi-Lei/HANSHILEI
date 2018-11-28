//文件文本。
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#pragma warning(disable:4996)

int main()
{
	//注意：int，非char，要求处理EOF
	int c;
	FILE* fp = fopen("test.txt","r");
	if(!fp)
	{
		perror("File opening failed");
		return EXIT_FAILURE;
	}
	//fgetc 当读取失败的时候或者遇到文件结束的时候，都会返回EOF
	//标准c I/O读取文件循环。
	while((c = fgetc(fp)) != EOF)
	{
		putchar(c);
	}
	printf("\n");
	//判断是什么原因结束的
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

//二进制文件；
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
	//必须采用二进制模式；
	FILE *fp = fopen("test.bin", "wb");
	//写double的数组；
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



