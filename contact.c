#define _CRT_SECURE_NO_WARNINGS 1
#include"contact.h"
//ʵ�ֺ����Ĺ���
void InitContact(struct Contact* ps) 
{
	//��data���ռ�ȫ�����ó�0 data�Ĵ�С(�ֽ�)��sizeof���
	memset(ps->data, 0,sizeof(ps->data));
	ps->size = 0;//ͨѶ¼���ֻ��0��Ԫ��
}
void AddContact(struct Contact* ps)
{
	if (ps->size == MAX)
	{
		printf("ͨѶ¼�������޷�����\n");
	}
	else
	{
		printf("����������:>");
		scanf("%s", ps->data[ps->size].name);//name���������ŵ����������ǵ�ַ ����Ҫ����&
		//ps->data������[ps->size]�����±� ��ʱ�����±�Ϊsize��Ԫ��
		//���Ԫ����һ���ṹ�� ����.���ʾ���Ľṹ���Ա
		printf("����������:>");
		scanf("%d", &(ps->data[ps->size].age));//age��ֵ ����Ҫ��& �����õ���ַ
		printf("�������Ա�:>");
		scanf("%s", ps->data[ps->size].sex);
		printf("������绰:>");
		scanf("%s", ps->data[ps->size].tele);
		printf("�������ַ:>");
		scanf("%s", ps->data[ps->size].addr);

		//ͨѶ¼����һ���˺�
		ps->size++;//��ǰԪ�ظ���+1
		printf("��ӳɹ�\n");
	}
}
void ShowContact(const struct Contact* ps)
{
	if (ps->size == 0)
	{
		printf("ͨѶ¼Ϊ��\n");
	}
	else
	{
		int i = 0;
		//��ӡ����
		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n" ,"����","����","�Ա�","�绰","��ַ");
		//��ӡ����
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
static int FindByName(const struct Contact* ps,char name[MAX_NAME])//����static ���������ֻ��������ļ��ﱻʹ��
//static �ı�������
{
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		//������������i��Ԫ�ص��������Ա�
		if (0 == strcmp(ps->data[i].name, name))
		{
			return i;//�ҵ��������
		}
	}
	return -1;//δ�ҵ�
}
void DelContact(struct Contact* ps) 
{
	char name[MAX_NAME];
	printf("������Ҫɾ���˵�����");
	scanf("%s",name);
	//1.����Ҫɾ��������ʲôλ��
	//�ҵ������������ڵ��±�
	//�Ҳ�������-1
	int pos = FindByName(ps, name);//���ps�Ǵ�����������β����õ� test.c��&con���Ķ�����һ����
	if (pos == -1)
	{
		printf("Ҫɾ�����˲�����\n");
	}
	else
	{
		//2.ɾ������ �ú����Ԫ����ǰ��Ҫɾ�����Ǹ�λ�ø��ǣ�Ȼ������һ��Ԫ��ɾ����
		int j = 0;
		//1 2 3 4 5 6 7 ���һ��Ԫ����size sizeҪŲ��size-1��λ����ȥ ����size������±�Ϊ6
//�±���  0 1 2 3 4 5 6
		for (j = pos; j <ps->size-1; j++)//sizeΪ7 - 1 = 6  ��ôj�����ֵ����5
		{
			ps->data[j] = ps->data[j + 1];//�±�Ϊ5��Ԫ�� ���±�Ϊ6��Ԫ�� �������һ��Ԫ����ǰŲ
		}
		ps->size--;
		printf("ɾ���ɹ�\n");
	}

}

void SearchContact(const struct Contact* ps) 
{
	char name[MAX_NAME];
	printf("������Ҫ�����˵�����:>");
	scanf("%s",&name);
	FindByName(ps, name);//����:��ͬ��const�޶��� ��const���ε�ָ�봫����const���εĺ��� ���Ĵ� ��FindByName����Ҳ����const������
	int pos = FindByName(ps,name);
	if (pos == -1) 
	{
		printf("δ�ҵ�������");
	}
	else 
	{
		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n", "����", "����", "�Ա�", "�绰", "��ַ");
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
	printf("������Ҫ�޸��˵�����");
	scanf("%s",name);
	int pos = FindByName(ps, name);
	if (pos == -1) 
	{
		printf("Ҫ�޸��˵���Ϣ������");
	}
	else 
	{
		printf("����������:>");
		scanf("%s", ps->data[pos].name);//name���������ŵ����������ǵ�ַ ����Ҫ����&
		//ps->data������[pos]�����±� ��ʱ�����±�Ϊsize��Ԫ��
		//���Ԫ����һ���ṹ�� ����.���ʾ���Ľṹ���Ա
		printf("����������:>");
		scanf("%d", &(ps->data[pos].age));//age��ֵ ����Ҫ��& �����õ���ַ
		printf("�������Ա�:>");
		scanf("%s", ps->data[pos].sex);
		printf("������绰:>");
		scanf("%s", ps->data[pos].tele);
		printf("�������ַ:>");
		scanf("%s", ps->data[pos].addr);
		printf("�޸����");
	}
}
//ð������
void SortContact(struct Contact* ps) 
{
	int i = 0;
	//����
		for (i = 0; i < ps->size - 1; i++)
		{
			//ÿһ�˱ȽϵĶ���
			int j = 0;
			for (j = 0; j < ps->size - 1 - i; j++)
			{
				//����Ԫ�رȽ�
				if (memcmp(ps->data[j].name, ps->data[j + 1].name, MAX_NAME) > 0)
				{
					struct PeoInfo tmp;
					tmp = ps->data[j];
					ps->data[j] = ps->data[j + 1];//�ڲ��±�д��i�� �����������
					ps->data[j + 1] = tmp;
				}
			}
		}
}
int cmp_by_name(const void* e1,const void* e2) 
{
	return memcmp(((struct PeoInfo *)e1)->name,((struct PeoInfo*)e2)->name, MAX_NAME);
}
//qsort����
void QSortContact(struct Contact* ps) 
{
	qsort(ps->data,ps->size,sizeof(ps->data[0]),cmp_by_name);
}