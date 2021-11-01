#pragma once
//#define MAX 1000
#define DEFAULT_SZ 3//起初容量
#define MAX_NAME 20
#define MAX_SEX 5
#define MAX_TELE 12
#define MAX_ADDR 30
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
enum Option 
{
	EXIT,//枚举默认从0开始
	ADD,//1
	DEL,//2
	SEARCH,
	MODIFV,
	SHOW,
	SORT
};
//声明函数
typedef struct PeoInfo //存放一个人的类型
{
	char name[MAX_NAME];//名字
	int age;//年龄
	char sex[MAX_SEX];//性别
	char tele[MAX_TELE];//电话
	char addr[MAX_ADDR];//住址
}PeoInfo;
//通讯录类型
typedef struct Contact
{
	struct PeoInfo *data;//指向一块空间用来存放通讯录信息
	int size;//记录当前已经有的元素个数
	int capacity;//当前通讯录的最大容量

}Contact;
//声明函数
//初始化通讯录的函数
void InitContact(struct Contact* ps);

//增加一个信息到通讯录
void AddContact(struct Contact* ps);

//打印通讯录中的信息
void ShowContact(const struct Contact* ps);//打印函数不改变con 加个const更安全

//删除通讯录中指定联系人的信息
void DelContact(struct Contact* ps);

//查找通讯录中指定联系人的信息
void SearchContact(const struct Contact* ps);

//修改指定联系人
void ModifyContact(struct Contact* ps);

//按照姓名排序 姓名必须是字符型 用冒泡排序实现
void SortContact(struct Contact* ps);

//按照姓名排序 用qsort函数实现
void QSortContact(struct Contact* ps);