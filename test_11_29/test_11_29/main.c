#include"address.h"
 
int main()
{
	count Con = {0};
	//sizeһ��Ҫ��ʼ��Ϊ 0��
	Con.size = 0;
	Con.capacity  = MEMBER_MAX ;
 
	Con.people  = (person *)malloc(MEMBER_MAX *sizeof(person));
	/*
	ע����malloc��Ӧ��free()��  ����ֱ�����Ƴ������н���free;
	*/
	if(Con.people == NULL)//�Ƿ񿪱ٳɹ����жϣ�
		printf("out of memory\n");
	else
	{
			while(1)
			{
				Check(&Con);
			}
	}
 
	system("pause");
	return 0;
}

