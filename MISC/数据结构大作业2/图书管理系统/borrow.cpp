#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<time.h>
#pragma warning(disable:4996)
/*************书的结构体***********/
typedef struct book {
	char number[4];     //编号
	char space = 32;    //空格符
	char author[15];  //作者
	char publisher[15];//出版社
	char name[15];
	int includer;        //该书的藏书量
	int borrow;        //借书量
	struct book *next;
}book;
typedef struct information {
	char SID[10];					//借书证号
	char number[4];					//书号
	int year;							//借书时间
	int mon;							//
	int day;							//
}information;
book* find_former(book*p,int find_key)//头结点为空，寻找前继
{
	book *f;
	f = p;
	p = p->next;
	while (p)
	{
		if (atoi(p->number) == find_key)
		{
			return f;
			break;
		}
		p = p->next;
		f = f->next;
	}
	if (!p)
		return 0;
}
book* book_borrow(int find_key, book*p)//调用了find_former（）
{
	 book*q;
	 book*left;
	 if (find_former(p, find_key))
	{
		 q = find_former(p, find_key);
		 left = q->next;
		 if (left->includer > 0)			//若现存量大于零，借出
		 {
			 left->borrow++;
			 left->includer--;
		 }
		 else
		 {
			 printf(" 现存量为零，不能借出");
		 }
		 return left;
	}
}
void information_insert_file(struct information new_reader)
{
	FILE*fp = NULL;
	fp = fopen("reader.txt", "a");
	fputs(new_reader.number, fp);
	fputs(" ", fp);
	fputs(new_reader.SID, fp);
	fputs("\n", fp);
	fclose(fp);
}
void record(book*left)//记录借书人信息以及借书时间（不清楚时间是否会随时间函数变化，
{									//则通过变量限制

	information* m;
	int year, mon, day;
	time_t t=time(0);
	struct tm p;
	localtime_s(&p,&t);
	year = p.tm_year+1900;
	mon = p.tm_mon+3;
	day = p.tm_mday;
	m = (information*)malloc(sizeof(information));
	m->day = day;
	m->mon = mon;
	m->year = year;
	printf("请输入你的借书证号：");
	scanf("%s", &m->SID);
	printf("完成登记，请收好图书");
	printf("请于%d年%d月%d日前归还图书!!",p.tm_year + 1900, p.tm_mon + 3, p.tm_mon + 3);
	strcpy_s(m->number, left->number);
	information_insert_file(*m);
}
int main()
{
	unsigned int find_key;
	book *p;//已存在的链表
	book *f;//借出的书
	printf("请输入你要借阅图书的书号：");
	scanf_s("%d", &find_key);
	f = book_borrow(find_key, p);
	if (f->includer > 0)
	{
		record(f);
	}
	return 0;
}