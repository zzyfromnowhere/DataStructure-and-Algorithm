#include <stdio.h>
#define MAXSIZE 100
typedef int elemType;

//定义顺序表结构体 
typedef struct
{
	int data[MAXSIZE];
	int length;
}SQL;

//初始化顺序表
void initList(SQL * p)
{
	p->length = 0;
}

//遍历顺序表
void showElem(SQL * L)
{
	if(L->length == 0)
	{
		printf("当前顺序表为空");
		return;
	}
	printf("顺序表长度为%d，元素: ", L->length);
	for(int i = 0; i < L->length; i++)
	{
		printf("%d ", L->data[i]);
	}
	printf("\n");
} 

//后插元素
//成功返回1，不成功返回0
int appendElem(SQL *L, elemType e)
{
	if(L->length == MAXSIZE)
	{
		printf("顺序表已满，添加元素失败\n");
		return 0;
	}
	L->data[L->length] = e;
	L->length++;
	return 1;
}

//插入元素
//成功返回1，不成功返回0
int insertElem(SQL * L, int pos, elemType e)
{
	if(pos > L->length)
	{
		printf("插入失败，顺序表长度不够\n");
		return 0;
	}
	if(L->length == MAXSIZE)
	{
		printf("顺序表已满，插入元素失败\n");
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

//删除元素
//成功返回1，不成功返回0
//并返回被删除的元素至e 
int deleteElem(SQL * L, int pos, elemType *e)
{
	if(L->length == 0)
	{
		printf("删除失败，顺序表长度为0");
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

//查找元素
//成功返回元素index，失败返回-1
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

//测试代码 
int main(int args, const char argv[])
{
	//初始化线性表 
	SQL sList;
	initList(&sList);
	printf("初始化顺序表成功!\n占用内存为%d字节\n", sizeof(sList));
	
	//尾插元素1 2 3 4 
	appendElem(&sList, 1);
	appendElem(&sList, 2);
	appendElem(&sList, 3);
	appendElem(&sList, 4);
	showElem(&sList);
	
	//在0处插入0 
	insertElem(&sList, 0, 0);
	printf("在0处插入0后结果为");
	showElem(&sList);
	
	//删除0处元素0
	int a;
	deleteElem(&sList, 0, &a);
	printf("删除0处的0结果为");
	showElem(&sList);
	
	//查找1 2 3 4 0
	printf("找到元素索引为%d\n", findElem(&sList, 1));
	printf("找到元素索引为%d\n", findElem(&sList, 2));
	printf("找到元素索引为%d\n", findElem(&sList, 3));
	printf("找到元素索引为%d\n", findElem(&sList, 4));
	printf("找到元素索引为%d\n", findElem(&sList, 0));
	return 0;
}
