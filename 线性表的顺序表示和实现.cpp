#include<iostream.h>
#define MAXSIZE 100
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define infeasible -1
#define OVERFLOW -2

typedef int Status;
typedef char ElemType;
typedef struct {
	EleType* elem;
	int length;
}SqList;//定义顺序表类型

Status InitList_Sq(Sqlist& L) {		//构造一个空表
	L.elem = new ElemType[MAXSIZE];	//为顺序表分配空间
	if (!L.elem) exit(OVERFLOW);	//存储分配失败
	L.length = 0;					//空表长度为0
	return OK;
}

void DestroyList(SqList& L) {	//销毁线性表
	if (L.elem) delete L.elem;	//释放存储空间
}

void ClearList(SqList& L) {		//清空线性表
	L.length = 0;				//将线性表的长度置为0
}

int GetLength(SqList L) {		//求线性表L的长度
	return(L.length);
}
int IsEmpty(SqList L) {			//判断线性表L是否为空
	if (L.length == 0) return 1;
	else return 0;
}