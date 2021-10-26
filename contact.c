#define _CRT_SECURE_NO_WARNINGS 1
#include"contact.h"
//实现函数的功能
void InitContact(struct Contact* ps) 
{
	//将data这块空间全部设置成0 data的大小(字节)用sizeof算出
	memset(ps->data, 0,sizeof(ps->data));
	ps->size = 0;//通讯录最初只有0个元素
}
void AddContact(struct Contact* ps)
{
	if (ps->size == MAX)
	{
		printf("通讯录已满，无法增加\n");
	}
	else
	{
		printf("请输入名字:>");
		scanf("%s", ps->data[ps->size].name);//name是用数组存放的数组名就是地址 不需要再用&
		//ps->data数组名[ps->size]数组下标 此时找他下标为size的元素
		//这个元素是一个结构体 再用.访问具体的结构体成员
		printf("请输入年龄:>");
		scanf("%d", &(ps->data[ps->size].age));//age是值 必须要用& 才能拿到地址
		printf("请输入性别:>");
		scanf("%s", ps->data[ps->size].sex);
		printf("请输入电话:>");
		scanf("%s", ps->data[ps->size].tele);
		printf("请输入地址:>");
		scanf("%s", ps->data[ps->size].addr);

		//通讯录放入一个人后
		ps->size++;//当前元素个数+1
		printf("添加成功\n");
	}
}
void ShowContact(const struct Contact* ps)
{
	if (ps->size == 0)
	{
		printf("通讯录为空\n");
	}
	else
	{
		int i = 0;
		//打印标题
		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n" ,"名字","年龄","性别","电话","地址");
		//打印数据
		for ( i = 0; i < ps->size; i++)
		{
			printf("%-20s\t%-4d\t%-5s\t%-12s\t%-20s\n",
				ps->data[i].name,
				ps->data[i].age,
				ps->data[i].sex,
				ps->data[i].tele,
				ps->data[i].addr);
		}
	}
}
static int FindByName(const struct Contact* ps,char name[MAX_NAME])//加了static 让这个函数只能在这个文件里被使用
//static 改变作用域
{
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		//输入的名字与第i个元素的名字作对比
		if (0 == strcmp(ps->data[i].name, name))
		{
			return i;//找到这个名字
		}
	}
	return -1;//未找到
}
void DelContact(struct Contact* ps) 
{
	char name[MAX_NAME];
	printf("请输入要删除人的名字");
	scanf("%s",name);
	//1.查找要删除的人在什么位置
	//找到返回名字所在的下标
	//找不到返回-1
	int pos = FindByName(ps, name);//这个ps是从这个函数的形参里拿的 test.c的&con传的东西是一样的
	if (pos == -1)
	{
		printf("要删除的人不存在\n");
	}
	else
	{
		//2.删除数据 用后面的元素往前面要删除的那个位置覆盖，然后把最后一个元素删除；
		int j = 0;
		//1 2 3 4 5 6 7 最后一个元素是size size要挪到size-1的位置上去 所以size的最大下标为6
//下标是  0 1 2 3 4 5 6
		for (j = pos; j <ps->size-1; j++)//size为7 - 1 = 6  那么j的最大值就是5
		{
			ps->data[j] = ps->data[j + 1];//下标为5的元素 和下标为6的元素 就是最后一个元素往前挪
		}
		ps->size--;
		printf("删除成功\n");
	}

}

void SearchContact(const struct Contact* ps) 
{
	char name[MAX_NAME];
	printf("请输入要查找人的名字:>");
	scanf("%s",&name);
	FindByName(ps, name);//警告:不同的const限定符 把const修饰的指针传给无const修饰的函数 报的错 给FindByName声明也加上const就行了
	int pos = FindByName(ps,name);
	if (pos == -1) 
	{
		printf("未找到该名字");
	}
	else 
	{
		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n", "名字", "年龄", "性别", "电话", "地址");
		printf("%-20s\t%-4d\t%-5s\t%-12s\t%-20s\n",
				ps->data[pos].name,
				ps->data[pos].age,
				ps->data[pos].sex,
				ps->data[pos].tele,
				ps->data[pos].addr);
	}
}

void ModifyContact(struct Contact* ps) 
{
	char name[MAX_NAME];
	printf("请输入要修改人的名字");
	scanf("%s",name);
	int pos = FindByName(ps, name);
	if (pos == -1) 
	{
		printf("要修改人的信息不存在");
	}
	else 
	{
		printf("请输入名字:>");
		scanf("%s", ps->data[pos].name);//name是用数组存放的数组名就是地址 不需要再用&
		//ps->data数组名[pos]数组下标 此时找他下标为size的元素
		//这个元素是一个结构体 再用.访问具体的结构体成员
		printf("请输入年龄:>");
		scanf("%d", &(ps->data[pos].age));//age是值 必须要用& 才能拿到地址
		printf("请输入性别:>");
		scanf("%s", ps->data[pos].sex);
		printf("请输入电话:>");
		scanf("%s", ps->data[pos].tele);
		printf("请输入地址:>");
		scanf("%s", ps->data[pos].addr);
		printf("修改完成");
	}
}
//冒泡排序
void SortContact(struct Contact* ps) 
{
	int i = 0;
	//趟数
		for (i = 0; i < ps->size - 1; i++)
		{
			//每一趟比较的对数
			int j = 0;
			for (j = 0; j < ps->size - 1 - i; j++)
			{
				//俩个元素比较
				if (memcmp(ps->data[j].name, ps->data[j + 1].name, MAX_NAME) > 0)
				{
					struct PeoInfo tmp;
					tmp = ps->data[j];
					ps->data[j] = ps->data[j + 1];//内层下标写成i了 真蠢啊！！！
					ps->data[j + 1] = tmp;
				}
			}
		}
}
int cmp_by_name(const void* e1,const void* e2) 
{
	return memcmp(((struct PeoInfo *)e1)->name,((struct PeoInfo*)e2)->name, MAX_NAME);
}
//qsort排序
void QSortContact(struct Contact* ps) 
{
	qsort(ps->data,ps->size,sizeof(ps->data[0]),cmp_by_name);
}