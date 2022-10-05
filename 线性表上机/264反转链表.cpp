#include<iostream>
#include<cstdio>
#include<malloc.h>
using namespace std;

typedef struct LinkList{ 
	int num;
	LinkList *next;
}LinkList;

LinkList* creatList(int cnt){
	LinkList* head, * s, *r;
	head=(LinkList*)malloc(sizeof(LinkList));		//生成头节点head 
    r = head;	//尾指针指向头节点 
    for(int i=0; i<cnt;i++){	
    	s=(LinkList*)malloc(sizeof(LinkList));		//生成新节点*s 
		cin>>s->num;
    	r->next = s;	//新节点插入表尾 
    	r = s;			//尾指针指向新表尾 
	}
	r->next = NULL;
	return head;		//返回表头指针 
}

void reversal(LinkList *L){
    if(L->next == NULL)
        printf("error input!");
    //判断输入是否正确 
    LinkList *p = L->next;
    LinkList *r = p->next;
    //指针遍历 
    while(p->next != NULL){
    	p->next = r->next;
        r->next = L->next;
        L->next = r;
        r = p->next;
    }    
//    LinkList *p =  ULL
//    LinkList *cur = L; 
//	  while(cur) {
//		LinkList *r = cur->next;
//		//将cur头插到新链表
//        cur->next = p;
//        p = cur;
//        cur = r;
//	}
}

void print(LinkList *L){	//遍历整个链,输出结果 
	LinkList *p;
	p = L;
	while(p!=NULL){
		if(p->next){
			cout<<p->next->num<<' ';
		}
		p = p->next;	
	}
}

int main()
{
	int i, j;
	int cnt = 0;
    cin>>j;
    LinkList *L[j];
    for(i=0;i<j;i++){		//利用循环进行创建链表
    	cin>>cnt;
    	L[i] = creatList(cnt);
    	reversal(L[i]); 	//利用原来链表位置进行反转链表存储 
	}
	for(i=0;i<j;i++)
    {
    	print(L[i]);
    	if(i!=j-1) 
			cout<<'\n';
	}
    return 0;
}
