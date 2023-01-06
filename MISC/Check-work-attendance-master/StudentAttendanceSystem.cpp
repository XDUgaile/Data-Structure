#include<stdio.h>
#include<string.h>
#include<windows.h>          //windows图形界面相关

int opt;//功能选择变量
int count=0;//考勤记录条数

//单链表-》考情记录
typedef struct node *pointer;
struct node{
	char order[20];
	char id[20];
	char name[20];
	char week[20];
	char day[20];
	char part[20];
	char course[20];
	char reason[20];
	pointer next;
};
typedef pointer lklist;

lklist head;

typedef struct nnode *ppointer;
struct nnode{
	char id[20];
	char name[20];
	char week[20];
	int cishu;
	ppointer next;
};
typedef ppointer llklist;

//二叉树-》班级成员
typedef struct nodes * pointers;
struct nodes{
	char account[20];
	char password[20];
	char power[20];
	pointers lchild,rchild;
};
typedef pointers bitree;

bitree t;

//队列，辅助层序遍历
const int maxsize=100;
typedef struct{
	bitree data[maxsize];
	int front,rear;
}sqqueue;

//主要功能函数声明
bitree level_creat();
int login(char no[20],char pwd[20]);
int administrator();
void classattendance();
void classpeople();
int modifypeople(bitree t);
int deletepeople(bitree t);
int insertpeople();
void levelorder(bitree t);
int committee();
void sta(lklist head,int k);
void all(lklist head);
void modify(lklist head,int k);
int updata(pointer p);
int deletes(lklist head,int k);
int insert(lklist head,int i);
pointer get(lklist head,int i);
int student(char no[20]);
void stuweek();
void weekall();
void data();
void mwlocate(lklist head,char no[20],int week);
void swlocate(lklist head,char name[20],int week);
void walocate(lklist head,int week);
lklist creat();
lklist initlist();
int de_sqqueue(sqqueue *sq,bitree *x);
int empty_sqqueue(sqqueue *sq);
int en_sqqueue(sqqueue *sq,bitree x);
void init_sqqueue(sqqueue *sq);
void bubbleSort(llklist mylist);

//创建二叉树，保存班级成员信息
bitree level_creat(){
	char str[20];
	pointers Q[100];
	int front,rear;
	pointers root,s;
	root=NULL;
	front=rear=0;
	int dept=1;
	FILE *fp6;
	if ((fp6=fopen("用户信息文件.txt","r"))==NULL){	
        printf("用户信息文件不存在\n");
        return 0;
	}
	while(!feof(fp6)){
		s=new nodes;
		fscanf(fp6,"%s",str);
		strcpy(s->account,str);
		fscanf(fp6,"%s",str);
		strcpy(s->password,str);
		fscanf(fp6,"%s",str);
		strcpy(s->power,str);
		s->lchild=s->rchild=NULL;
		rear++;
		Q[rear]=s;
		if(rear==1){
			root=s;
			front=1;
		}
		else{
			if(s&&Q[front])
				if(rear%2==0)
					Q[front]->lchild=s;
				else
					Q[front]->rchild=s;
			if(rear%2==1)
				front++;
		}
	}
	fclose(fp6);
	return root;
}

//初始化队列
void init_sqqueue(sqqueue *sq){
	sq->front=sq->rear=0;
}

//进队
int en_sqqueue(sqqueue *sq,bitree x){
	if((sq->rear+1)%maxsize==sq->front){
		printf("队满，不能入队！\n");
		return 0;
	}
	sq->rear=(sq->rear+1)%maxsize;
	sq->data[sq->rear]=x;
	return 1;
}
//判空
int empty_sqqueue(sqqueue *sq){
	if(sq->rear==sq->front)
		return 1;
	else
		return 0;
}
//出队
int de_sqqueue(sqqueue *sq,bitree *x){
	if(sq->rear==sq->front){
		printf("队空，不能出队！\n");
		return 0;
	}
	sq->front=(sq->front+1)%maxsize;
	*x=sq->data[sq->front];
	return 1;
}

//单链表初始化
lklist initlist(){
	pointer head;
	head = new node;
	head->next = NULL;
	return head;
}

//创建单链表，保存学生考勤信息
lklist creat(){
	count=0;
	pointer rear,s;
	head = new node;
	rear = head;
	FILE *fp2;
    char str[20];
    if ((fp2=fopen("学生考勤情况.txt","r"))==NULL){	
        printf("学生考勤情况不存在\n");
        return 0;
	}
	while(!feof(fp2)){
		s = new node;
		fscanf(fp2,"%s",str);
		strcpy(s->order,str);
		fscanf(fp2,"%s",str);
		strcpy(s->id,str);
		fscanf(fp2,"%s",str);
		strcpy(s->name,str);
		fscanf(fp2,"%s",str);
		strcpy(s->week,str);
		fscanf(fp2,"%s",str);
		strcpy(s->day,str);
		fscanf(fp2,"%s",str);
		strcpy(s->part,str);
		fscanf(fp2,"%s",str);
		strcpy(s->course,str);
		fscanf(fp2,"%s",str);
		strcpy(s->reason,str);
		rear->next = s;
		rear = s;
		count++;
	}
	rear->next = NULL;
	fclose(fp2);
	return head;
}

//某周所有学生考勤
void walocate(lklist head,int week){
	printf("序号\t学号\t姓名\t周数\t星期\t节数\t课程\t原因\n");
	int sign=0;
	pointer p;
	p=head->next;
	char wk[20];
	sprintf(wk,"第%d周",week);
	while(p!=NULL){
		if(strcmp(p->week,wk)==0){
			printf("%s\t",p->order);
			printf("%s\t",p->id);
			printf("%s\t",p->name);
			printf("%s\t",p->week);
			printf("%s\t",p->day);
			printf("%s\t",p->part);
			printf("%s\t",p->course);
			printf("%s\n",p->reason);
			sign++;
		}
		p=p->next;
	}
	if(sign==0)
		printf("%s无考勤记录\n",wk);
}

//某学生某周考勤情况
void swlocate(lklist head,char name[20],int week){
	printf("序号\t学号\t姓名\t周数\t星期\t节数\t课程\t原因\n");
	int sign=0;
	pointer p;
	p=head->next;
	char wk[20];
	sprintf(wk,"第%d周",week);
	while(p!=NULL){
		if(strcmp(p->week,wk)==0&&strcmp(p->name,name)==0){
			printf("%s\t",p->order);
			printf("%s\t",p->id);
			printf("%s\t",p->name);
			printf("%s\t",p->week);
			printf("%s\t",p->day);
			printf("%s\t",p->part);
			printf("%s\t",p->course);
			printf("%s\n",p->reason);
			sign++;
		}
		p=p->next;
	}
	if(sign==0)
		printf("%s%s无考勤记录\n",name,wk);
}

//登录账号某周考勤
void mwlocate(lklist head,char no[20],int week){
	printf("序号\t学号\t姓名\t周数\t星期\t节数\t课程\t原因\n");
	int sign=0;
	pointer p;
	p=head->next;
	char wk[20];
	sprintf(wk,"第%d周",week);
	while(p!=NULL){
		if(strcmp(p->week,wk)==0&&strcmp(p->id,no)==0){
			printf("%s\t",p->order);
			printf("%s\t",p->id);
			printf("%s\t",p->name);
			printf("%s\t",p->week);
			printf("%s\t",p->day);
			printf("%s\t",p->part);
			printf("%s\t",p->course);
			printf("%s\n",p->reason);
			sign++;
		}
		p=p->next;
	}
	if(sign==0)
		printf("你%s无考勤记录\n",wk);
}

//初始化并建单链表，保存考勤
void data(){
	initlist();
	creat();
}

//某周所有学生考勤情况
void weekall(){
	printf("请输入需要查询的周数：");
	scanf("%d",&opt);
	walocate(head,opt);
}

//某学生某周考勤情况
void stuweek(){
	char name[20];
	printf("请输入需要查询的姓名：");
	scanf("%s",&name);
	printf("请输入需要查询的周数：");
	scanf("%d",&opt);
	swlocate(head,name,opt);
}

//登录账号某周考勤情况
void myweek(char no[20]){
	printf("请输入需要查询的周数：");
	scanf("%d",&opt);
	mwlocate(head,no,opt);
}

//学生界面
int student(char no[20]){
	printf("--------------------班级考勤管理系统----------------------\n");
	data();
	printf("学生界面\n");
	printf("1、某周全班考勤查询\n");
	printf("2、某学生某周考勤查询\n");
	printf("3、我的考勤查询\n");
	printf("其它任意字符退出\n");
	printf("请输入对应数字选择功能：");
	scanf("%d",&opt);
	switch(opt){
	case 1:{
		fflush(stdin);
		system("cls");
		printf("--------------------班级考勤管理系统----------------------\n");
		weekall();
		return 1;
		   }
	case 2:{
		fflush(stdin);
		system("cls");
		printf("--------------------班级考勤管理系统----------------------\n");
		stuweek();
		return 1;
		   }
	case 3:{
		fflush(stdin);
		system("cls");
		printf("--------------------班级考勤管理系统----------------------\n");
		myweek(no);
		return 1;
		   }
	default : return 0;
	}
}

//单链表定位
pointer get(lklist head,int i){
	int j;
	pointer p;
	if(i==0)
		return head;
	if(i<0)
		return NULL;
	j=0;
	p=head->next;
	while(p!=NULL){
		j++;
		if(j==i)
			break;
		p=p->next;
	}
	return p;
}

//增加考勤记录
int insert(lklist head,int i){
	FILE *fp3;
	if((fp3=fopen("学生考勤情况.txt","at+"))==NULL)
		fp3=fopen("学生考勤情况.txt","wb+");
    fclose(fp3);
	pointer q,s;
	q = get(head,i-1);
	if(q==NULL)
		printf("非法插入位置！\n");
	s = new node;
	printf("请输入学生学号：");
	scanf("%s",s->id);
	printf("请输入学生姓名：");
	scanf("%s",s->name);
	printf("请输入考勤周数：");
	scanf("%s",s->week);
	printf("请输入考勤星期：");
	scanf("%s",s->day);
	printf("请输入课程节数：");
	scanf("%s",s->part);
	printf("请输入课程名称：");
	scanf("%s",s->course);
	printf("请输入考勤原因：");
	scanf("%s",s->reason);
	if((fp3=fopen("学生考勤情况.txt","at+"))==NULL)
	{
		printf("不能打开该数据库！");
		return 0;
	}
	fprintf(fp3,"\r\n %d",++i);
	fprintf(fp3," %s",s->id);
	fprintf(fp3," %s",s->name);
	char connect[20];
	sprintf(connect,"第%s周",s->week);
	fprintf(fp3," %s",connect);
	sprintf(connect,"星期%s",s->day);
	fprintf(fp3," %s",connect);
	sprintf(connect,"第%s节",s->part);
	fprintf(fp3," %s",connect);
	fprintf(fp3," %s",s->course);
	fprintf(fp3," %s",s->reason);
	fclose(fp3);
	s->next = q->next;
	q->next = s;
	printf("增加考勤记录成功\n");
	return 1;
}

//删除考勤记录
int deletes(lklist head,int k){
	pointer p,q;
	q = get(head,k-1);
	if(q==NULL||q->next == NULL)
		printf("非法删除位置\n");
	p=q->next;
	q->next = p->next;
	delete p;
	FILE *fp4,*fp5;
	if ((fp4=fopen("学生考勤情况.txt","r"))==NULL){	
        printf("学生考勤情况不存在\n");
        return 0;
	}
	fp5=fopen("考勤临时文件.txt","w");
	p=head->next;
	while(p!=NULL){
		if(strcmp(p->order,"1")!=0)
			fprintf(fp5,"\r\n");
		int i,j;
		int sum=0;
		for(i=strlen(p->order)-1,j=1;i>=0;i--){ 
			p->order[i]=p->order[i]-'0'; 
			sum+=p->order[i]*j;
			j=j*10;
		}
		if(sum<k)
			fprintf(fp5," %d",sum);
		else
			fprintf(fp5," %d",--sum);
		fprintf(fp5," %s",p->id);
		fprintf(fp5," %s",p->name);
		fprintf(fp5," %s",p->week);
		fprintf(fp5," %s",p->day);
		fprintf(fp5," %s",p->part);
		fprintf(fp5," %s",p->course);
		fprintf(fp5," %s",p->reason);
		p=p->next;
	}
	fclose(fp4);
    fclose(fp5);
    remove("学生考勤情况.txt");
    rename("考勤临时文件.txt","学生考勤情况.txt");
	printf("删除考勤记录成功\n");
	return 1;
}

//修改考勤，建临时文件保存后删除原文件，再改名
int updata(pointer p){
	FILE *fp4,*fp5;
	if ((fp4=fopen("学生考勤情况.txt","r"))==NULL){	
        printf("学生考勤情况不存在\n");
        return 0;
	}
	fp5=fopen("考勤临时文件.txt","w");
	p=head->next;
	while(p!=NULL){
		if(strcmp(p->order,"1")!=0)
			fprintf(fp5,"\r\n");
		fprintf(fp5," %s",p->order);
		fprintf(fp5," %s",p->id);
		fprintf(fp5," %s",p->name);
		fprintf(fp5," %s",p->week);
		fprintf(fp5," %s",p->day);
		fprintf(fp5," %s",p->part);
		fprintf(fp5," %s",p->course);
		fprintf(fp5," %s",p->reason);
		p=p->next;
	}
	fclose(fp4);
    fclose(fp5);
    remove("学生考勤情况.txt");
    rename("考勤临时文件.txt","学生考勤情况.txt");
	printf("修改考勤记录成功\n");
	return 1;
}

//修改考勤记录
void modify(lklist head,int k){
	pointer p,q;
	char connect[20];
	q = get(head,k-1);
	if(q==NULL||q->next == NULL)
		printf("非法修改位置\n");
	p=q->next;
	printf("1、学号\n");
	printf("2、姓名\n");
	printf("3、周数\n");
	printf("4、星期\n");
	printf("5、节数\n");
	printf("6、课程\n");
	printf("7、原因\n");
	printf("输入其他字符退出修改\n");
	printf("请选择需要修改的内容：");
	scanf("%d",&opt);
	switch(opt){
	case 1:{
		printf("请输入修改后的学号：");
		scanf("%s",p->id);
		updata(p);
		break;
		   }
	case 2:{
		printf("请输入修改后的姓名：");
		scanf("%s",p->name);
		updata(p);
		break;
		   }
	case 3:{
		printf("请输入修改后的周数：");
		scanf("%s",connect);
		sprintf(p->week,"第%s周",connect);
		updata(p);
		break;
		   }
	case 4:{
		printf("请输入修改后的星期：");
		scanf("%s",connect);
		sprintf(p->day,"星期%s",connect);
		updata(p);
		break;
		   }
	case 5:{
		printf("请输入修改后的节数：");
		scanf("%s",connect);
		sprintf(p->part,"第%s节",connect);
		updata(p);
		break;
		   }
	case 6:{
		printf("请输入修改后的课程：");
		scanf("%s",p->course);
		updata(p);
		break;
		   }
	case 7:{
		printf("请输入修改后的原因：");
		scanf("%s",p->reason);
		updata(p);
		break;
		   }
	default: break;
	}
}

//所有考勤纪律
void all(lklist head){
	printf("序号\t学号\t姓名\t周数\t星期\t节数\t课程\t原因\n");
	int sign=0;
	char connect[20];
	char input[20];
	pointer p;
	p=head->next;
	while(p!=NULL){
		printf("%s\t",p->order);
		printf("%s\t",p->id);
		printf("%s\t",p->name);
		printf("%s\t",p->week);
		printf("%s\t",p->day);
		printf("%s\t",p->part);
		printf("%s\t",p->course);
		printf("%s\n",p->reason);
		sign++;
		p=p->next;
	}
	if(sign==0)
		printf("无考勤记录\n");
	printf("1、增加考勤记录\n");
	printf("2、删除考勤记录\n");
	printf("3、修改考勤记录\n");
	printf("4、查找考勤记录\n");
	printf("其它任意字符返回\n");
	printf("请输入对应数字选择功能：");
	scanf("%d",&opt);
	switch(opt){
	case 1:{
		insert(head,count);
		break;
		   }
	case 2:{
		printf("请输入删除考勤的序号：");
		scanf("%d",&opt);
		deletes(head,opt);
		break;
		   }
	case 3:{
		printf("请输入修改考勤的序号：");
		scanf("%d",&opt);
		modify(head,opt);
		break;
		   }
	case 4:{
		printf("1、学号\n");
		printf("2、姓名\n");
		printf("3、周数\n");
		printf("4、星期\n");
		printf("5、节数\n");
		printf("6、课程\n");
		printf("7、原因\n");
		printf("请输入查询考勤的条件：");
		scanf("%d",&opt);
		switch(opt){
		case 1:{
			printf("请输入学号：");
			scanf("%s",input);
			printf("序号\t学号\t姓名\t周数\t星期\t节数\t课程\t原因\n");
			pointer p;
			p=head->next;
			while(p!=NULL){
				if(strcmp(input,p->id)==0){
					printf("%s\t",p->order);
					printf("%s\t",p->id);
					printf("%s\t",p->name);
					printf("%s\t",p->week);
					printf("%s\t",p->day);
					printf("%s\t",p->part);
					printf("%s\t",p->course);
					printf("%s\n",p->reason);
				}
				p=p->next;
			}
			break;
			   }
		case 2:{
			printf("请输入姓名：");
			scanf("%s",input);
			printf("序号\t学号\t姓名\t周数\t星期\t节数\t课程\t原因\n");
			pointer p;
			p=head->next;
			while(p!=NULL){
				if(strcmp(input,p->name)==0){
					printf("%s\t",p->order);
					printf("%s\t",p->id);
					printf("%s\t",p->name);
					printf("%s\t",p->week);
					printf("%s\t",p->day);
					printf("%s\t",p->part);
					printf("%s\t",p->course);
					printf("%s\n",p->reason);
				}
				p=p->next;
			}
			break;
			   }
		case 3:{
			printf("请输入周数：");
			scanf("%s",input);
			sprintf(connect,"第%s周",input);
			printf("序号\t学号\t姓名\t周数\t星期\t节数\t课程\t原因\n");
			pointer p;
			p=head->next;
			while(p!=NULL){
				if(strcmp(connect,p->week)==0){
					printf("%s\t",p->order);
					printf("%s\t",p->id);
					printf("%s\t",p->name);
					printf("%s\t",p->week);
					printf("%s\t",p->day);
					printf("%s\t",p->part);
					printf("%s\t",p->course);
					printf("%s\n",p->reason);
				}
				p=p->next;
			}
			break;
		   }
		case 4:{
			printf("请输入星期：");
			scanf("%s",input);
			sprintf(connect,"星期%s",input);
			printf("序号\t学号\t姓名\t周数\t星期\t节数\t课程\t原因\n");
			pointer p;
			p=head->next;
			while(p!=NULL){
				if(strcmp(connect,p->day)==0){
					printf("%s\t",p->order);
					printf("%s\t",p->id);
					printf("%s\t",p->name);
					printf("%s\t",p->week);
					printf("%s\t",p->day);
					printf("%s\t",p->part);
					printf("%s\t",p->course);
					printf("%s\n",p->reason);
				}
				p=p->next;
			}
			break;
			   }
		case 5:{
			printf("请输入节数：");
			scanf("%s",input);
			sprintf(connect,"第%s节",input);
			printf("序号\t学号\t姓名\t周数\t星期\t节数\t课程\t原因\n");
			pointer p;
			p=head->next;
			while(p!=NULL){
				if(strcmp(connect,p->part)==0){
					printf("%s\t",p->order);
					printf("%s\t",p->id);
					printf("%s\t",p->name);
					printf("%s\t",p->week);
					printf("%s\t",p->day);
					printf("%s\t",p->part);
					printf("%s\t",p->course);
					printf("%s\n",p->reason);
				}
				p=p->next;
			}
			break;
			   }
		case 6:{
			printf("请输入课程：");
			scanf("%s",input);
			printf("序号\t学号\t姓名\t周数\t星期\t节数\t课程\t原因\n");
			pointer p;
			p=head->next;
			while(p!=NULL){
				if(strcmp(input,p->course)==0){
					printf("%s\t",p->order);
					printf("%s\t",p->id);
					printf("%s\t",p->name);
					printf("%s\t",p->week);
					printf("%s\t",p->day);
					printf("%s\t",p->part);
					printf("%s\t",p->course);
					printf("%s\n",p->reason);
				}
				p=p->next;
			}
			break;
			   }
		case 7:{
			printf("请输入原因：");
			scanf("%s",input);
			printf("序号\t学号\t姓名\t周数\t星期\t节数\t课程\t原因\n");
			pointer p;
			p=head->next;
			while(p!=NULL){
				if(strcmp(input,p->reason)==0){
					printf("%s\t",p->order);
					printf("%s\t",p->id);
					printf("%s\t",p->name);
					printf("%s\t",p->week);
					printf("%s\t",p->day);
					printf("%s\t",p->part);
					printf("%s\t",p->course);
					printf("%s\n",p->reason);
				}
				p=p->next;
			}
			break;
			   }
		default: break;
		}
		break;
		   }
	default : break;
	}
}

//出勤率计算
void sta(lklist head,int k){
	printf("学号\t姓名\t周数\t出勤率\n");
	pointer p,s;
	p=head->next;
	s=head->next;
	char wk[20];
	char add[20];
	char refuse[20][20];
	ppointer rear,ss;
	llklist hhead = new nnode;
	rear = hhead;
	sprintf(wk,"第%d周",k);
	int n=0,m=0;
	while(p!=NULL){
		int k=0;
		for(int i=0;i<=m;i++){
			if(strcmp(refuse[i],p->name)!=0)
				k++;
		}
		if(k-1==m){
			if(strcmp(wk,p->week)==0){
				strcpy(add,p->id);
				while(s!=NULL){
					if(strcmp(add,s->id)==0&&strcmp(wk,s->week)==0){
						if(n==0){
							ss = new nnode;
							strcpy(ss->id,s->id);
							strcpy(ss->name,s->name);
							strcpy(refuse[m],s->name);
							strcpy(ss->week,s->week);
							rear->next = ss;
							rear = ss;
						}
						n++;
						s=s->next;
					}
					else
						s=s->next;
				}
				m++;
				ss->cishu = n;
				n=0;
			}
		}
		rear->next = NULL;
		s=head->next;
		p=p->next;
	}
	//排序次数
	bubbleSort(hhead);
	int sign=0;
	ppointer pp;
	pp=hhead->next;
	while(pp!=NULL){
		printf("%s\t",pp->id);
		printf("%s\t",pp->name);
		printf("%s\t",pp->week);
		printf("%.0f%%\n",(1-pp->cishu/5.0)*100);
		sign++;
		pp=pp->next;
	}
	if(sign==0)
		printf("无考勤记录\n");
}

//冒泡排序
void bubbleSort(llklist mylist)
{
    if((mylist -> next == NULL) || (mylist -> next -> next == NULL))
    {
        return;
    }

    nnode *hhead, * pre, * cur, *next, * end, * temp;
    hhead = mylist;
    end = NULL;
    //从链表头开始将较大值往后沉
    while(hhead -> next != end)
    {
        for(pre = hhead, cur = pre -> next, next = cur -> next; next != end; pre = pre -> next, cur = cur -> next, next = next -> next)
        {
            //相邻的节点比较
            if(cur -> cishu < next -> cishu)
            {
                cur -> next = next -> next;
                pre -> next = next;
                next -> next = cur;
                temp = next;
                next = cur;
                cur = temp;
            }
        }
        end = cur;
    }
}

//班委界面
int committee(){
	printf("--------------------班级考勤管理系统----------------------\n");
	data();
	printf("班委界面\n");
	printf("1、班级考勤记录\n");
	printf("2、周出勤率排序\n");
	printf("其它任意字符退出\n");
	printf("请输入对应数字选择功能：");
	scanf("%d",&opt);
	switch(opt){
	case 1:{
		fflush(stdin);
		system("cls");
		printf("--------------------班级考勤管理系统----------------------\n");
		all(head);
		return 1;
		   }
	case 2:{
		fflush(stdin);
		system("cls");
		printf("--------------------班级考勤管理系统----------------------\n");
		printf("请输入出勤率排序的周数：");
		scanf("%d",&opt);
		sta(head,opt);
		return 1;
		   }
	default : return 0;
	}
}

//层序遍历，打印班级成员信息
void levelorder(bitree t){
	pointers p;
	sqqueue Q;
	if(t==NULL)
		return;
	init_sqqueue(&Q);
	en_sqqueue(&Q,t);
	while(!empty_sqqueue(&Q)){
		de_sqqueue(&Q,&p);
		printf("%s\t",p->account);
		printf("%s\t",p->password);
		printf("%s\n",p->power);
		if(p->lchild!=NULL)
			en_sqqueue(&Q,p->lchild);
		if(p->rchild!=NULL)
			en_sqqueue(&Q,p->rchild);
	}
}

//增加班级成员
int insertpeople(){
	FILE *fp7;
	if((fp7=fopen("用户信息文件.txt","ab+"))==NULL)
		fp7=fopen("用户信息文件.txt","wb+");
    fclose(fp7);
	if((fp7=fopen("用户信息文件.txt","ab+"))==NULL)
	{
		printf("不能打开该数据库！");
		return 0;
	}
	char account[20];
	char password[20];
	char power[20];
	printf("请输入账号：");
	scanf("%s",&account);
	printf("请输入密码：");
	scanf("%s",&password);
	printf("请输入权限：");
	scanf("%s",&power);
	fprintf(fp7,"\r\n %s",account);
	fprintf(fp7," %s",password);
	fprintf(fp7," %s",power);
	fclose(fp7);
	printf("增加班级成员成功\n");
	return 1;
}

//删除班级成员
int deletepeople(bitree t){
	char str[20];
	bool k=false;
	printf("请输入需要删除的账号：");
	scanf("%s",&str);
	FILE *fp10,*fp11;
	if ((fp10=fopen("用户信息文件.txt","r"))==NULL){	
        printf("用户信息文件不存在\n");
        return 0;
	}
	fp11=fopen("用户临时文件.txt","w");
	pointers p;
	sqqueue Q;
	if(t==NULL)
		return 1;
	init_sqqueue(&Q);
	en_sqqueue(&Q,t);
	while(!empty_sqqueue(&Q)){
		de_sqqueue(&Q,&p);
		if(strcmp(p->account,str)==0){
			k=true;
		}
		else{
			if(strcmp(p->account,"000")!=0)
				fprintf(fp11,"\r\n");
			fprintf(fp11," %s",p->account);
			fprintf(fp11," %s",p->password);
			fprintf(fp11," %s",p->power);
		}
		if(p->lchild!=NULL)
			en_sqqueue(&Q,p->lchild);
		if(p->rchild!=NULL)
			en_sqqueue(&Q,p->rchild);
	}
	if(k==false)
		printf("没有此账户\n");
	fclose(fp10);
    fclose(fp11);
    remove("用户信息文件.txt");
    rename("用户临时文件.txt","用户信息文件.txt");
	printf("删除班级成员成功\n");
	return 1;
}

//修改班级成员
int modifypeople(bitree t){
	char str[20];
	bool k=false;
	printf("请输入需要更改的账号：");
	scanf("%s",&str);
	FILE *fp8,*fp9;
	if ((fp8=fopen("用户信息文件.txt","r"))==NULL){	
        printf("用户信息文件不存在\n");
        return 0;
	}
	fp9=fopen("用户临时文件.txt","w");
	pointers p;
	sqqueue Q;
	if(t==NULL)
		return 1;
	init_sqqueue(&Q);
	en_sqqueue(&Q,t);
	while(!empty_sqqueue(&Q)){
		de_sqqueue(&Q,&p);
		if(strcmp(p->account,str)==0){
			printf("请输入更改后的账号：");
			scanf("%s",p->account);
			printf("请输入更改后的密码：");
			scanf("%s",p->password);
			printf("请输入更改后的权限：");
			scanf("%s",p->power);
			k=true;
		}
		if(strcmp(p->account,"000")!=0)
			fprintf(fp9,"\r\n");
		fprintf(fp9," %s",p->account);
		fprintf(fp9," %s",p->password);
		fprintf(fp9," %s",p->power);
		if(p->lchild!=NULL)
			en_sqqueue(&Q,p->lchild);
		if(p->rchild!=NULL)
			en_sqqueue(&Q,p->rchild);
	}
	if(k==false)
		printf("没有此账户\n");
	fclose(fp8);
    fclose(fp9);
    remove("用户信息文件.txt");
    rename("用户临时文件.txt","用户信息文件.txt");
	printf("修改班级成员成功\n");
	return 1;
}

//班级成员
void classpeople(){
	printf("用户名\t密码\t权限\n");
	levelorder(t);
	printf("1、增加班级成员\n");
	printf("2、删除班级成员\n");
	printf("3、修改成员权限\n");
	printf("其它任意字符返回\n");
	printf("请输入对应数字选择功能：");
	scanf("%d",&opt);
	switch(opt){
	case 1:{
		insertpeople();
		break;
		   }
	case 2:{
		deletepeople(t);
		break;
		   }
	case 3:{
		modifypeople(t);
		break;
		   }
	default : break;
	}
}

void classattendance(){
	all(head);
}

//管理员页面
int administrator(){
	printf("--------------------班级考勤管理系统----------------------\n");
	data();
	t=level_creat();
	printf("管理员界面\n");
	printf("1、班级成员管理\n");
	printf("2、班级出勤管理\n");
	printf("其它任意字符退出\n");
	printf("请输入对应数字选择功能：");
	scanf("%d",&opt);
	switch(opt){
	case 1:{
		fflush(stdin);
		system("cls");
		printf("--------------------班级考勤管理系统----------------------\n");
		classpeople();
		return 1;
		   }
	case 2:{
		fflush(stdin);
		system("cls");
		printf("--------------------班级考勤管理系统----------------------\n");
		classattendance();
		return 1;
		   }
	default : return 0;
	}
}

//登录判断用户信息
int login(char no[20],char pwd[20]){
	fflush(stdin);
    FILE *fp1;
	int ok=1;
    char str[20];
    if ((fp1=fopen("用户信息文件.txt","r"))==NULL){	
        printf("用户信息文件不存在\n");
        return 0;
	}
	while(!feof(fp1)){
		fscanf(fp1,"%s",str);
		if(strcmp(str,no)==0){
			fscanf(fp1,"%s",str);
			if(strcmp(str,pwd)==0){
				system("cls");
				fscanf(fp1,"%s",str);
				if(strcmp(str,"1")==0){
					fclose(fp1);
					while(ok){
						ok=administrator();
					}
					return 1;
				}
				if(strcmp(str,"2")==0){
					fclose(fp1);
					while(ok){
						ok=committee();
					}
					return 2;
				}
				if(strcmp(str,"3")==0){
					fclose(fp1);
					while(ok){
						ok=student(no);
					}
					return 3;
				}
			}
			else{
				fclose(fp1);
				return 0;
			}
		}
		fscanf(fp1,"%s",str);
		fscanf(fp1,"%s",str);
	}
	fclose(fp1);
	return 0;
}

//欢迎页面
void welcome(){
	printf("--------------------班级考勤管理系统----------------------\n");
	char no[20];
	char pwd[20];
	printf("请输入账号：");
	scanf("%s",&no);
	printf("请输入密码：");
	scanf("%s",&pwd);
	if((login(no,pwd))==0){
		printf("密码输入错误或用户名，请重启应用\n",pwd);
	}
}

int main(){
	system("color B0"); //软件颜色
	welcome();
	return 0;
}
