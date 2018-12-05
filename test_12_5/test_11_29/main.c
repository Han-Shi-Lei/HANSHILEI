#include"contact.h"
 
int main()
{
	contact_t Con = {0};
	//size一定要初始化为0;
	Con.size = 0;
	Con.capacity  = INIT ;
 
	Con.people  = (person *)malloc(INIT *sizeof(person));
	/*
	注意与malloc对应的free();在退出功能进行free。
	*/
	if(Con.people == NULL)//是否开辟成功的判断；
	{
		perror("malloc");
		return 0;
	}
	else
	{
	  int quit = 0;
	  int input = -1;
	  while (!quit)
	  {
		menu();
		/*fread(&Con.people  ,sizeof(Con.people),1,fp);*/
		/*fclose(fp);*/
		scanf("%d", &input);
		switch (input)
		{
		case 0:
			quit = 1;
			free(Con.people);
			Con.people = NULL;
			break;
		case 1:
			AddPeople(&Con);
			break;
		case 2:
			DeletePeople(&Con);
			break;
		case 3:
			UpdatePeople(&Con);
			break;
		case 4:
			SearchPeople(&Con);
			break;
		case 5:
			ListPeople(&Con);
			break;
		case 6:
			EmptyContact(&Con);
			break;
		case 7:
			SortPeople(&Con);
			break;
		default:
			printf("Input error , Try again!\n");
			break;
		}
	  }
	}
	printf("Bye Bye!\n");

 
	system("pause");
	return 0;
}