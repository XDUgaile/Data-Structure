#include <stdio.h>
#include <math.h> 
#include <string.h>
#include <stdlib.h> 

typedef struct student
{
	char *data;
	int m;
}*sqlist;

sqlist CreateList(int x);
void printfsqlist(sqlist Lb);
sqlist Reversal(sqlist Lb);

int main() 
{
	sqlist E=NULL;
	int x;
	printf("请输入你字符串字符个数：");
	scanf("%d", &x);
	E=CreateList(x);
	printfsqlist(E);
	E = Reversal(E);
	printfsqlist(E);
	return 0;
}

sqlist CreateList(int x)
{
	char ch, i;
	sqlist L;
	L = (sqlist)malloc(sizeof(sqlist));
	L->m = x;
	L->data = (char *)malloc((x * sizeof(char)));
	printf("请输入一字符串:\n",x);
	getchar();                                    //清除上次回车键
	for (i = 0; i < x; i++) {
		ch = getchar();
		L->data[i] = ch;
	}
	return L;
}

void printfsqlist(sqlist E1)
{
	for (int i = 0; i < E1->m; i++)
		printf("%c ", E1->data[i]);
	printf("\n");
}

sqlist Reversal(sqlist E1)
{
	int x = E1->m - 1;
	char t;
	for (int i = 0; i < (E1->m)/2; i++,x--)
	{
		t = E1->data[i];
		E1->data[i]= E1->data[x];
		E1->data[x] = t;

	}
	return E1;
}

