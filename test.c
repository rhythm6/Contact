#define _CRT_SECURE_NO_WARNINGS 1
#include"contact.h"
//测试
void menu() 
{
	printf("********************************************\n");
	printf("***********1.add       2.del  **************\n");
	printf("***********3.serach    4.modify  ***********\n");
	printf("***********5.show      6.sort  *************\n");
	printf("***********0.exit   *************************\n");
}

int main() 
{
	int input = 0;
	//创建通讯录
	struct Contact con;//con就是通讯录,里面包含:capacity容量 和size元素个数 data指针
	//初始化通讯录
	InitContact(&con);
	do 
	{
		menu();
		printf("请选择:>");
		scanf("%d", &input);
		switch (input) 
		{
		case ADD:
			AddContact(&con);//传地址可改变con
			break;
		case DEL:
			DelContact(&con);//删除肯定要改变con所以传地址
			break;
		case SEARCH:
			SearchContact(&con);
			break;
		case MODIFV:
			ModifyContact(&con);
			break;
		case SHOW:
			ShowContact(&con);//传地址可节省空间 
			break;
		case SORT:
			//SortContact(&con);
			QSortContact(&con);
			break;
		case EXIT:
			printf("退出通讯录");
			break;
		default:
			printf("没有该选项");
			break;

		}
	} while (input);
	return 0;
}