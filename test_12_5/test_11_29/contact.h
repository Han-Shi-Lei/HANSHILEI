#pragma warning(disable:4996)//消除scanf的警告；
 
#ifndef __CONTACT_H__//防止重定义；
#define __CONTACT_H__
 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
 
#define NAME_MAX 20
#define SEX_MAX 4
#define ADD_MAX 10
#define TEL_MAX 13
#define INIT 2//刚开始电话本的容量
//#define CONTACT_FILE "contant.txt"
 
//姓名、性别、年龄、电话、住址
typedef struct person
{
	char name[NAME_MAX ];
	char sex[SEX_MAX];
	int age;
	char tel[TEL_MAX ];
	char address[ADD_MAX ];
}person;
 
//通讯录成员结构体；
typedef struct cotact
{
	person *people;
	int size;//确定通讯录当前人数；
	int capacity ; //电话本容量；
}contact_t,*contact_p;//指针用来在函数内部接受结构体指针；
contact_p InitContact(const char *file);
void AddPeople(contact_p Con);//新增成员；
void DeletePeople(contact_p Con);//删除成员；
void SearchPeople(contact_p Con);//查找成员；
void UpdatePeople(contact_p Con);//修改成员；
void ListPeople(contact_p Con);//显示所有成员；
void EmptyContact(contact_p Con);//清空通讯录；
void SortPeople(contact_p Con);//排序所有成员；
void menu();//打印菜单；
 
void save(contact_p Con,const char *file);

 
#endif  //__CONTACT_H__

