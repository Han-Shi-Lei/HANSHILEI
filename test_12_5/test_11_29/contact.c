#include"contact.h"


void menu()
{	
	printf("*****************************\n");
	printf("**1��add          2��delete**\n");
	printf("**3��update       4��search**\n");
	printf("**5��list         6��empty **\n");
	printf("**7��sort         0��exit  **\n");
	printf("*****************************\n");
	printf("Please Enter:");
}
 
static int find(contact_p Con, char* arr)//���ò��Һ�����
{
	int i =0;
	for(;i<Con->size;i++)
	{
		if(strcmp(Con->people [i].name,arr) == 0)
			return i;
	}
	return -1;
}

void save(contact_p Con,const char *file)
{
	FILE *fp = fopen(file,"wb");
	if(!fp)
	{
		printf("File fopen is error!\n");
		return;
	}
	fwrite(Con,sizeof(contact_t)+Con->size * sizeof(person),1,fp);
	fclose(fp);
}

 
void AddPeople(contact_p Con)//���ӳ�Ա��
{
	if(Con->size == Con->capacity )
	{
		/*
		��ǰ�����Ѿ��ﵽ���ͨѶ¼��������������ݣ���realloc������
		*/
		person *tmp = (person *)realloc (Con->people,(Con->capacity +3)*sizeof(person));
		if(tmp == NULL)
		{
			perror("realloc");
			return;
		}
		else
		{
			Con->people = tmp; 
		   (Con->capacity)  += 3;
		}
	}//�ж�ͨѶ¼�Ƿ������
	printf("Start adding!\n");
	printf("Please enter name:");
	scanf("%s",&(Con->people[Con->size].name ));
	printf("Please enter sex:");
	scanf("%s",&(Con->people[Con->size].sex ));
	printf("Please enter age:");
	scanf("%s",&(Con->people[Con->size].age));
	printf("Please enter telephone:");
	scanf("%s",&(Con->people[Con->size].tel));
	printf("Please enter address:");
	scanf(" %s",&(Con->people[Con->size].address));

	printf("Add a contact success!\n");
	Con->size++;//ע�⣺ÿ����һ����Ա��ͨѶ¼������size����+1��
}
 
void DeletePeople(contact_p Con)//ɾ����Ա��
{   
	
	int ret = 0;
	char name[20] = {0};
 
	if(Con->size == 0)
	{
		printf("Honey,the contacts is empty!\n");
		return ;
	}
 
	printf("PLease enter the name of the contact you want to delete:\n");
	scanf("%s",&name);
 
	ret = find(Con,name);
	/*
	ɾ���ķ����ǽ����һ����Ա�ŵ�ɾ���������Աλ���ϣ�
	ע��: ��������size--;
	*/
	if(ret>=0)
	{
		Con->people[ret] = Con->people[Con->size-1];
		(Con->size)--;
		printf("Dlete success!\n");
		
	}
	else
		printf("The contact you want to delete was not found!\n");
	
}
 
 
 
void SearchPeople(contact_p Con)//���ҳ�Ա��ֱ�ӵ���find������
{
	int ret = 0;
	char name[20] = {0};
 
	printf("Please enter the name of the contact you want to modify:\n");
	scanf("%s",&name);
 
	ret = find(Con,name);
	if(ret>=0)
	{
		printf("%10s\t%4s\t%3s\t%13s\t%10s\n","name","sex","age","tel","address");
		printf("%10s\t%4s\t%3d\t%13s\t%10s\n",Con->people [ret].name ,
	    Con->people [ret].sex  ,Con->people [ret].age,
	    Con->people [ret].tel ,Con->people [ret].address );
	}
	else
	{
		printf("The contact was not found!\n");
	}
}
 
void UpdatePeople(contact_p Con)//�ı��Ա��
{
	int i = 0;
	int ret = 0;
	char name[20] = {0};
	char *ptr[] = {"name","sex","age","tel","address"};
	//ÿ�θı��Ա�ĵ������ݣ�
	printf("Please enter the name of the contact you want to modify:\n");
	scanf("%s",&name);
 
	ret = find(Con,name);//���ò��Һ�����
	
	if(ret>=0)
	{
		int ages = 0;
		char mod[20] = {0};
		int sel = 0;
		printf("Please enter the options you want to modify:\n");
		printf("1.name\n2.sex\n3.age\n4.tel\n5.adress\n");
		printf("Please enter:");
		scanf("%d",&sel);
		printf("Please enter:");
		//���ѡ��switch��䣻�Ƚ����׿�������ʵ���Խ��з�װ��
		switch(sel)
		{
		case 1:
			scanf("%s",&mod);
			strcpy(Con->people [ret].name,mod);
			printf("Modify success!\n");
			break;
		case 2:
			scanf("%s",&mod);
			strcpy(Con->people [ret].sex ,mod);
			printf("Modify success!\n");
			break;
		case 3:
			scanf("%d",&ages);
			Con->people [ret].age  = ages;
			printf("Modify success!\n");
			break;
		case 4:
			scanf("%s",&mod);
			strcpy(Con->people [ret].tel ,mod);
			printf("Modify success!\n");
			break;
		case 5:
			scanf("%s",&mod);
			strcpy(Con->people [ret].address ,mod);
			printf("Modify success!\n");
			break;
		default:
			printf("Modify failed!\n");
			break;
		}
	}
	else
		printf("Without this contact!\n");
 
}
 
 
void ListPeople(contact_p Con)//��ʾ���г�Ա��
{
	int i = 0;
   printf("%10s\t%4s\t%3s\t%13s\t%10s\n","name","sex","age","tel","address");
	//ѭ����ӡÿ��ͨѶ¼��Ա��
	for(; i < Con->size ; i++)
	{
		printf("%10s\t%4s\t%3d\t%13s\t%10s\n",Con->people [i].name ,
	   Con->people [i].sex  ,Con->people [i].age,
	   Con->people [i].tel ,Con->people [i].address );
	}
 
}
 
void EmptyContact(contact_p Con)//�����ϵ�ˣ�
{
	/*
	���ͨѶ¼ֻ��Ҫ��ͨѶ¼�ܳ�Ա��size��Ϊ 0��
	*/
	Con->size = 0;
	printf("Contact is emoty!\n");
}
 
 
void SortPeople(contact_p Con)//����������ϵ�ˣ�
{
 /*
 ð���������г�Ա�����֣�
 */
	int flag = 0;
	int i = 0;
	int j = 0;
	for(i = 0; i < Con->size-1 ;i++)
	{
		flag = 1;
		for(j = 0;j <(Con->size) - i -1;j++)
		{
			if((strcmp(Con->people[j].name , Con->people [j+1].name))> 0)
			{
				person tmp = Con->people[j];
				Con->people[j] = Con->people[j+1];
				Con->people[j+1] = tmp;
				flag = 0;
			}
		}			
		if(flag==1)
		{
				break;
		}
	}
}

 
