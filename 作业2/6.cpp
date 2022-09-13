#include <stdio.h>
#include <math.h> 
#include <string.h>
#include <stdlib.h> 

int main()
{
	int n;
	char name[20];
	node student;
	sqlist *L;
	scanf("%d%s%c%s",&student.number, &student.name, &student.sex, &student.addr);
	L = Creat();
	Insert(L, student);
	printf("\n请输入要删除的学生学号：")；
	scanf("%d", &n);
	int flag;
	flag = Delete(L,n);
	if(flag) Output(L);
	printf("请输入要查询的学生姓名：")；
	scanf("%s", name);
	Locate(L, name); 
	return 0;
}
