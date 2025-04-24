#include <stdio.h>
#define MAXSIZE 100

typedef int elemType;
//����˳���ṹ�� 
typedef struct
{
	elemType * data;
	int length;
}SQL;

//��ǿ��ĳ�ʼ��˳���(���ڴ濪��) 
SQL *initList()
{
	SQL *L = (SQL *)malloc(sizeof(SQL));
	L->data = (elemType *)malloc(sizeof(elemType) * MAXSIZE);
	L->length = 0;
	return L;
} 

//����˳���
void showElem(SQL * L)
{
	if(getLength(L) == 0)
	{
		printf("��ǰ˳���Ϊ��");
		return;
	}
	printf("˳�����Ϊ%d��Ԫ��: ", L->length);
	for(int i = 0; i < getLength(L); i++)
	{
		printf("%d ", L->data[i]);
	}
	printf("\n");
} 

//���Ԫ��
//�ɹ�����1�����ɹ�����0
int appendElem(SQL *L, elemType e)
{
	if(L->length == MAXSIZE)
	{
		printf("˳������������Ԫ��ʧ��\n");
		return 0;
	}
	L->data[L->length] = e;
	L->length++;
	return 1;
}

//����Ԫ��
//�ɹ�����1�����ɹ�����0
int insertElem(SQL * L, int pos, elemType e)
{
	if(pos > L->length)
	{
		printf("����ʧ�ܣ�˳����Ȳ���\n");
		return 0;
	}
	if(L->length == MAXSIZE)
	{
		printf("˳�������������Ԫ��ʧ��\n");
		return 0;
	}
	for(int i = L->length; i > pos; i--)
	{
		L->data[i] = L->data[i-1];
	}
	L->data[pos] = e;
	L->length ++;
	return 1;
}

//ɾ��Ԫ��
//�ɹ�����1�����ɹ�����0
//�����ر�ɾ����Ԫ����e 
int deleteElem(SQL * L, int pos, elemType *e)
{
	if(L->length == 0)
	{
		printf("ɾ��ʧ�ܣ�˳�����Ϊ0");
		return 0;
	}
	*e = L->data[pos];
	for(int i = pos; i < L->length-1; i++)
	{
		L->data[i] = L->data[i+1];
	}
	L->length --;
	return 0;
} 

//����Ԫ��
//�ɹ�����Ԫ��index��ʧ�ܷ���-1
int findElem(SQL * L, elemType e)
{
	int index = -1;
	for(int i = 0; i < L->length; i++)
	{
		if(L->data[i] == e)
		{
			index = i;
			break;
		}
	}
	return index;
}

//������Ա���
int getLength(SQL *L)
{
 	return  L->length;	
} 

//������Ա�
void clearList(SQL *L)
{
	L->length = 0;
	printf("���˳���ɹ���\n");
} 

//���Դ��� 
int main(int args, const char argv[])
{
	//��ʼ�����Ա� 
	SQL *sList = initList();
	printf("��ʼ��˳���ɹ�!\nռ���ڴ�Ϊ%d�ֽ�\n", sizeof(sList));
	
	//β��Ԫ��1 2 3 4 
	appendElem(sList, 1);
	appendElem(sList, 2);
	appendElem(sList, 3);
	appendElem(sList, 4);
	showElem(sList);
	
	//��0������0 
	insertElem(sList, 0, 0);
	printf("��0������0����Ϊ");
	showElem(sList);
	
	//ɾ��0��Ԫ��0
	int a;
	deleteElem(sList, 0, &a);
	printf("ɾ��0����0���Ϊ");
	showElem(sList);
	
	//����1 2 3 4 0
	printf("�ҵ�Ԫ������Ϊ%d\n", findElem(sList, 1));
	printf("�ҵ�Ԫ������Ϊ%d\n", findElem(sList, 2));
	printf("�ҵ�Ԫ������Ϊ%d\n", findElem(sList, 3));
	printf("�ҵ�Ԫ������Ϊ%d\n", findElem(sList, 4));
	printf("�ҵ�Ԫ������Ϊ%d\n", findElem(sList, 0));
	
	//���˳���
	clearList(sList);
	showElem(sList); 
	
	//���س��� 
	free(sList->data);
	free(sList);
	return 0;
}
