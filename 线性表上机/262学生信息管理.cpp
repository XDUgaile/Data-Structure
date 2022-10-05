#include<stdio.h>
#include<string.h>
#include<malloc.h>

typedef struct student {
    char name[20];
	int number;
	char gender;
}student;

typedef struct LinkList {
	student* data;
	LinkList* next;
}LinkList;

LinkList* creatList() {
    char ch[20];
    LinkList* head, * r, * s;
    head=(LinkList*)malloc(sizeof(LinkList));   //生成头节点head
    r = head; //尾指针指向头结点
    scanf("%s",ch);
    while (ch[0] != '#') {		//输入不是#就进入循环 
//    	cout<<"请输入第学生的学号、姓名和性别：\n";
        s = (LinkList*)malloc(sizeof(LinkList));		//动态分配空间大小 
        s->data=(student*)malloc(sizeof(student));		//注意，由于上面仅分配了s的空间，但是并没有分配data的空间，如果直接赋值就会越界 
        strcpy(s->data->name,ch);		//将ch的值赋值给s->data 
//		cin>>s->data->name>>s->data->gender;
        scanf("%d %c",&s->data->number,&s->data->gender);	
		r->next = s;		//尾指针的下一个指向s 
        r = s;				//尾指针的值赋为s 
        scanf("%s",ch);		//读入下一个字符串 
    }
    r->next = NULL;//链表的最后指向一个新地址
    return head;
}

int delete_point(LinkList* list, int n)
{
    LinkList* p;
    LinkList* q;
    int flag = 0;		//标志，如果没有该学生则输出0 
    p = list;
    q = list->next;
    while (true)
    {
    	if(q==NULL){		//如果q指针为空就跳出循环，否则下面会越界 
    		break;
		}
    	if(q->data->number==n){
    		flag = 1;		//如果找到了对应数字就将flag赋为1 
    		p->next = q->next;		//将指向p下一个的指针指向q的下一个 
    		free(q);		//将q指针的空间释放 
			break;
		}
		p=q;		
		q=q->next;		
    }
    return flag;
}

//LinkList* search_point(LinkList* list, int n)
//{
//    LinkList* p;
//    p = list;
//    for (int i = 0; i < n; i++)
//    {
//        p = p->next;
//    }
//    return p;
//}

void output_list(LinkList* point)
{
    LinkList* p;
    p = point;
//    cout << endl << endl << endl;
    while ((p = p->next) != NULL)		//如果p的下一个不为空就进入循环 
    {
        printf("%s %d %c\n",p->data->name,p->data->number,p->data->gender);		//打印输出 
    }
}

int main() 
{
    LinkList* head;		
//    output_list(head);			
    head =  creatList();		//创建一个链表 
    int num;
    scanf("%d", &num);
    int flag = delete_point(head, num);
    if(flag ==1){		//如果找到了就输出删除后的列表 
    	output_list(head);
	}
	else{
		printf("No"); 		//没有找到就输出NO 
	}
    return 0;
}
