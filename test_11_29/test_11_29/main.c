#include"address.h"
 
int main()
{
	count Con = {0};
	//size一定要初始化为 0；
	Con.size = 0;
	Con.capacity  = MEMBER_MAX ;
 
	Con.people  = (person *)malloc(MEMBER_MAX *sizeof(person));
	/*
	注意与malloc对应的free()；  本题直接在推出功能中进行free;
	*/
	if(Con.people == NULL)//是否开辟成功的判断；
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

