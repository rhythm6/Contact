#pragma once
#define MAX 1000
#define MAX_NAME 20
#define MAX_SEX 5
#define MAX_TELE 12
#define MAX_ADDR 30
#include<stdio.h>
#include<string.h>
enum Option 
{
	EXIT,//ö��Ĭ�ϴ�0��ʼ
	ADD,//1
	DEL,//2
	SEARCH,
	MODIFV,
	SHOW,
	SORT
};
//��������
struct PeoInfo //���һ���˵�����
{
	char name[MAX_NAME];//����
	int age;//����
	char sex[MAX_SEX];//�Ա�
	char tele[MAX_TELE];//�绰
	char addr[MAX_ADDR];//סַ
};
//ͨѶ¼����
struct Contact
{
	struct PeoInfo data[MAX];//���һ����Ϣ
	int size;//��¼��ǰ�Ѿ��е�Ԫ�ظ���

};
//��������
//��ʼ��ͨѶ¼�ĺ���
void InitContact(struct Contact* ps);

//����һ����Ϣ��ͨѶ¼
void AddContact(struct Contact* ps);

//��ӡͨѶ¼�е���Ϣ
void ShowContact(const struct Contact* ps);//��ӡ�������ı�con �Ӹ�const����ȫ

//ɾ��ͨѶ¼��ָ����ϵ�˵���Ϣ
void DelContact(struct Contact* ps);

//����ͨѶ¼��ָ����ϵ�˵���Ϣ
void SearchContact(const struct Contact* ps);

//�޸�ָ����ϵ��
void ModifyContact(struct Contact* ps);