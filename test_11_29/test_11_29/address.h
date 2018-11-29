#pragma warning(disable:4996)//消除scanf的警告；
 
#ifndef __ADDRESS_H__//防止重定义；
#define __ADDRESS_H__
 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
 
#define NAME_MAX 20
#define SEX_MAX 4
#define HOME_MAX 10
#define TEL_MAX 13
#define MEMBER_MAX 2//刚开始电话本的容量
 
//姓名、性别、年龄、电话、住址
typedef struct person
{
	char name[NAME_MAX ];
	char sex[SEX_MAX];
	int age;
	char tel[TEL_MAX ];
	char home[HOME_MAX ];
}person;
 
//通讯录成员结构体；
typedef struct count
{
	person *people;
	int size;//确定通讯录当前人数；
	int capacity ; //电话本容量；
}count,*con;//指针用来在函数内部接受结构体指针；
 
enum op
{
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MOD,
	SHOW,
	SORT,
	EMPTY
};
void Exit(con Con);//退出函数；
void Add(con Con);//新增成员；
void Del(con Con);//删除成员；
void Search(con Con);//查找成员；
void Mod(con Con);//修改成员；
void Show(con Con);//显示所有成员；
void Empty(con Con);//清空通讯录；
void Sort(con Con);//排序所有成员；
void Check(con Con);//选择函数；
void _Print();
 
//void (*str[8])(con Con) = {Exit,Add,Del,Search,Mod,Show,Sort,Empty};
//函数指针数组，比switch语句方便很多！
 
#endif  //__ADDRESS_H__

