#pragma warning(disable:4996)//����scanf�ľ��棻
 
#ifndef __CONTACT_H__//��ֹ�ض��壻
#define __CONTACT_H__
 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
 
#define NAME_MAX 20
#define SEX_MAX 4
#define ADD_MAX 10
#define TEL_MAX 13
#define INIT 2//�տ�ʼ�绰��������
//#define CONTACT_FILE "contant.txt"
 
//�������Ա����䡢�绰��סַ
typedef struct person
{
	char name[NAME_MAX ];
	char sex[SEX_MAX];
	int age;
	char tel[TEL_MAX ];
	char address[ADD_MAX ];
}person;
 
//ͨѶ¼��Ա�ṹ�壻
typedef struct cotact
{
	person *people;
	int size;//ȷ��ͨѶ¼��ǰ������
	int capacity ; //�绰��������
}contact_t,*contact_p;//ָ�������ں����ڲ����ܽṹ��ָ�룻
contact_p InitContact(const char *file);
void AddPeople(contact_p Con);//������Ա��
void DeletePeople(contact_p Con);//ɾ����Ա��
void SearchPeople(contact_p Con);//���ҳ�Ա��
void UpdatePeople(contact_p Con);//�޸ĳ�Ա��
void ListPeople(contact_p Con);//��ʾ���г�Ա��
void EmptyContact(contact_p Con);//���ͨѶ¼��
void SortPeople(contact_p Con);//�������г�Ա��
void menu();//��ӡ�˵���
 
void save(contact_p Con,const char *file);

 
#endif  //__CONTACT_H__

