#define _CRT_SECURE_NO_WARNINGS 1
#include"contact.h"
//����
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
	//����ͨѶ¼
	struct Contact con;//con����ͨѶ¼,�������:1000��Ԫ�ص��� ��size
	//��ʼ��ͨѶ¼
	InitContact(&con);
	do 
	{
		menu();
		printf("��ѡ��:>");
		scanf("%d", &input);
		switch (input) 
		{
		case ADD:
			AddContact(&con);//����ַ�ɸı�con
			break;
		case DEL:
			DelContact(&con);//ɾ���϶�Ҫ�ı�con���Դ���ַ
			break;
		case SEARCH:
			SearchContact(&con);
			break;
		case MODIFV:
			ModifyContact(&con);
			break;
		case SHOW:
			ShowContact(&con);//����ַ�ɽ�ʡ�ռ� 
			break;
		case SORT:
			break;
		case EXIT:
			printf("�˳�ͨѶ¼");
			break;
		default:
			printf("û�и�ѡ��");
			break;

		}
	} while (input);
	return 0;
}