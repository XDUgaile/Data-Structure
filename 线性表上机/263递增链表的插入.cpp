#include<iostream>
#include<cstdio>
#include<malloc.h>
using namespace std;

typedef struct LinkList{
	int height;
	LinkList *next;
}LinkList;

LinkList* creatList(int num){
	LinkList* head, * s, *r;
	head=(LinkList*)malloc(sizeof(LinkList));		//生成头节点head 
    r = head;	//尾指针指向头节点 
    for(int i=0; i<num;i++){	
    	s=(LinkList*)malloc(sizeof(LinkList));		//生成新节点*s 
		cin>>s->height;
    	r->next = s;	//新节点插入表尾 
    	r = s;			//尾指针指向新表尾 
	}
	r->next = NULL;
	return head;		//返回表头指针 
} 

int main(){
	int num = 0, h;
	cin>>num>>h;
	if(num==0){		//特殊情况下，没有小朋友，不用排序，直接输入输出 
		printf("%d", h);
	}
	else{			//一般情况下，已经排好队了 
		LinkList *L = creatList(num);
		LinkList *p, *r;
		p=(LinkList*)malloc(sizeof(LinkList));
		p->height = h;
		r = L->next;
		for(int i=0;i<num;i++){		//三种情况 
			if(h<r->height){		//当插入的比第一个小时，插到链表第一个 
				p->next = r;
				L->next = p;
				break;
			}else if((h>r->height)&&(r->next==NULL)) {		//当插入的比最后一个大时，插到链表尾 
				r->next = p;
				break; 
			}else if((h>=r->height)&&(h<r->next->height)&&(r->next!=NULL)){		//一般情况下，插入表中 
				p->next = r->next;
				r->next = p;
				break;
			}
			else{
				r = r->next;
			}
		} 
		LinkList *q = L->next;
		for(int j = 0;j<=num;j++){
//			cout<<q->height<<' ';
			printf("%d ",q->height);
			q = q->next;
		} 
	}
	return 0;
} 
