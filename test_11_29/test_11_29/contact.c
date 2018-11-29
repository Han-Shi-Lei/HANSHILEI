#include"address.h"

//姓名、性别、年龄、电话、住址
void _Print()
{	
	printf("*************************\n");
	printf("1.	添加联系人信息\n");
    printf("2.	删除指定联系人信息\n");
    printf("3.	查找指定联系人信息\n");
    printf("4.	修改指定联系人信息\n");
    printf("5.	显示所有联系人信息\n");
	printf("6.	排序所有联系人信息\n");
    printf("7.	清空所有联系人\n");
	printf("0.      退出\n");
	printf("*************************\n");
	printf("请选择功能 (0-7):>\n");
}
 
/*
因为好几个函数都会用到查找函数，所以单独封住一个find函数；
*/
int find(con Con, char arr[])//公用查找函数；
{
	int i =0;
	for(;i<Con->size;i++)
	{
		if(strcmp(Con->people [i].name,arr) == 0)
			return i;
	}
	return -1;
}
 
void Add(con Con)//增加成员；
{
	if(Con->size == Con->capacity )
	{
		/*
		当前人数已经达到最大通讯录容量，则进行扩容，用realloc函数；
		*/
		person *tmp = (person *)realloc (Con->people,(Con->capacity +3)*sizeof(person));
		if(tmp == NULL)
			printf("out of memory\n");
		else
			Con->people = tmp; 
 
		(Con->capacity)  += 3;
	}//判断通讯录是否溢出；
 
	printf("准备添加一个新成员：>\n");
	printf("请输入姓名：\n");
	scanf("%s",&(Con->people[Con->size].name ));
		printf("请输入性别：\n");
	scanf("%s",&(Con->people[Con->size].sex ));
		printf("请输入年龄：\n");
	scanf("%d",&(Con->people[Con->size].age));
		printf("请输入电话：\n");
	scanf("%s",&(Con->people[Con->size].tel));
		printf("请输入地址：\n");
	scanf("%s",&(Con->people[Con->size].home));
 
	printf("保存成功！\n");
 
	Con->size++;//注意：每增加一个成员，通讯录总人数size都得+1；
}
 
void Del(con Con)//删除成员；
{   
	
	int ret = 0;
	char name[20] = {0};
 
	if(Con->size == 0)
	{
		printf("亲！当前通讯录是空的！\n");
		return ;
	}
 
	printf("请输入需要删除人的姓名：\n");
	scanf("%s",&name);
 
	ret = find(Con,name);
	/*
	删除的方法是将最后一个成员放到删除的这个成员位置上；
	注意: 不能忘记size--;
	*/
	if(ret>=0)
	{
		Con->people[ret] = Con->people[Con->size-1];
		(Con->size)--;
		printf("删除成功！\n");
		
	}
	else
		printf("没有找到要删除的对象！\n");
	
}
 
 
 
void Search(con Con)//查找成员；直接调用find函数；
{
	int ret = 0;
	char name[20] = {0};
 
	printf("请输入要查询人的姓名：\n");
	scanf("%s",&name);
 
	ret = find(Con,name);
	if(ret>=0)
	{
		printf("%10s\t%4s\t%3s\t%13s\t%10s\n","name","sex","age","tel","address");
		printf("%10s\t%4s\t%3d\t%13s\t%10s\n",Con->people [ret].name ,
	    Con->people [ret].sex  ,Con->people [ret].age,
	    Con->people [ret].tel ,Con->people [ret].home );
	}
	else
	{
		printf("没找到该通讯录好友！\n");
	}
}
 
void Mod(con Con)//改变成员；
{
	int i = 0;
	int ret = 0;
	char name[20] = {0};
	char *ptr[] = {"name","sex","age","tel","address"};
	//每次改变成员的单个内容；
	printf("请输入需要修改的联系人：\n");
	scanf("%s",&name);
 
	ret = find(Con,name);//调用查找函数；
	
	if(ret>=0)
	{
		int ages = 0;
		char mod[20] = {0};
		int sel = 0;
		printf("请输入需要修改的选项：\n");
		printf("1.name\n2.sex\n3.age\n4.tel\n5.adress\n");
		scanf("%d",&sel);
		printf("请输入\n");
		//这块选用switch语句；比较容易看懂；其实可以进行封装；
		switch(sel)
		{
		case 1:
			scanf("%s",&mod);
			strcpy(Con->people [ret].name,mod);
			printf("修改成功！\n");
			break;
		case 2:
						scanf("%s",&mod);
			strcpy(Con->people [ret].sex ,mod);
			printf("修改成功！\n");
			break;
		case 3:
						scanf("%d",&ages);
			Con->people [ret].age  = ages;
			printf("修改成功！\n");
			break;
		case 4:
						scanf("%s",&mod);
			strcpy(Con->people [ret].tel ,mod);
			printf("修改成功！\n");
			break;
		case 5:
						scanf("%s",&mod);
			strcpy(Con->people [ret].home ,mod);
			printf("修改成功！\n");
			break;
		default:
			printf("修改失败！\n");
			break;
		}
	}
	else
		printf("没有该成员!\n");
 
}
 
 
void Show(con Con)//显示所有成员；
{
	int i = 0;
   printf("%10s\t%4s\t%3s\t%13s\t%10s\n","name","sex","age","tel","address");
	//循环打印每个通讯录成员；
	for(; i < Con->size ; i++)
	{
		printf("%10s\t%4s\t%3d\t%13s\t%10s\n",Con->people [i].name ,
	   Con->people [i].sex  ,Con->people [i].age,
	   Con->people [i].tel ,Con->people [i].home );
	}
 
}
 
void Empty(con Con)//清空联系人；
{
	/*
	清空通讯录只需要将通讯录总成员数size改为 0；
	*/
	Con->size = 0;
	printf("通讯录已空！\n");
}
 
 
void Sort(con Con)//排序所有联系人；
{
 /*
 冒泡排序所有成员的名字；
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
				break;
	}
}
 
void Exit(con Con)//退出函数；
{
	free(Con->people );
	Con->people = NULL;
	exit(0);
}
 
//定义一个函数指针数组，方便对函数的调用！
void (*str[8])(con Con) = {Exit,Add,Del,Search,Mod,Show,Sort,Empty};
 
 
void Check(con Con)//选择函数；
{	
	int select = '0';
	//if(Con->size == Con->capacity )
	//{
	//	person *tmp = (person *)realloc (Con->people ,Con->capacity +3);
	//	if(tmp == NULL)
	//		printf("out of memory\n");
	//	else
	//		Con->people = tmp; 
 
	//	Con->capacity  += 3;
	//}
	_Print();
	scanf("%d",&select);
 
 
	if(select==0 || select==1|| select==2|| select==3|| select==4|| select==5|| select==6 || select==7)
	         str[select](Con);
	/*
	如果在main函数中不进行while循环直接在Check函数中调用自己；
	缺陷是：反复递归调用Check函数，会导致栈溢出；
	Check(Con);
	*/
	else
	{
		printf("输入格式错误！\n");
	}
}

