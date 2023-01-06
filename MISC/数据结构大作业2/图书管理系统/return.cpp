#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<time.h>
/*************书的结构体***********/
typedef struct book {
	char number[4];     //编号
	char space [32];    //空格符
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
	int moon;							
	int day;	
	struct information *next;						
}information; 
book* find_former(book*p1,int find_key)//头结点为空，寻找前继
{
	book *f1;
	f1 = p1;
	p1 = p1->next;
	while (p1)
	{
		if (atoi(p1->number) == find_key)
		{
			return f1;
			break;
		}
		p1 = p1->next;
		f1 = f1->next;
	}
	if (!p1)
		return 0;
}
information* find_former(information*p2,int find_key)//头结点为空，寻找前继
{
	information *f2;
	f2 = p2;
	p2 = p2->next;
	while (p2)
	{
		if (atoi(p2->number) == find_key)
		{
			return f2;
			break;
		}
		p2 = p2->next;
		f2 = f2->next;
	}
	if (!p2)
		return 0;
}
book* book_return(int find_key, book*p1)//调用了find_former（）
{
	 book*q;
	 book*left;
	 if (find_former(p1, find_key))
	{
		q = find_former(p1, find_key);
		left = q->next;
		left->borrow++;
		left->includer--;
		return left;
		printf("归还成功");
	}
	else
	{
		printf("未找到该书");
	}
}
void cancel(information*p2,int find_key)
{			
	information*f2;				
	if(find_former(p2,find_key)) 
	{
		f2=find_former(p2,find_key);
		f2=f2->next;
		free(f2);
	}
	else
	{
		printf("未找到借书人");
	}
}
int main()
{
	unsigned int find_key;
	book*p1;//已存在的链表
	information*p2;
	book*f1;//借出的书
	information*f2;
	printf("请输入你要归还的图书的书号：");
	scanf("%d", &find_key);
	book_return(find_key, p1);
	cancel(p2,find_key);
	return 0;
}
