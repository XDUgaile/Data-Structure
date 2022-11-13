#include<stdio.h>
#include<malloc.h>

typedef struct node {
	int data;	//数据项
	struct node* lchild, * rchild, * parent;	//左右子树，及双亲结点指针
}Bstnode;

Bstnode* InsertBst(Bstnode* t, Bstnode* s);
Bstnode* CreateBst(int num);
void InOrder(Bstnode*p);
void Search(Bstnode*p, int data);

/*此处设定全局变量的原因是需要将二叉排序树的顺序记录下来，并以此来输出前驱及后继结点
  PS：全局变量自动初始化为0*/

int sort[1000];
int g;

int main(){
	int N, M;
	int i, j;
	scanf("%d", &N);		//输入结点数
	Bstnode *tree = CreateBst(N);		//构造新树
	InOrder(tree);		//将顺序放入数组
//	for(i=0;i<N;i++){
//		printf("%d ",sort[i]);
//	}
	scanf("%d", &M);	//输入查询的个数
	int a[M];	
	for(i=0;i<M;i++){
		scanf("%d", &a[i]);		//输入查询的数据 
	}
	for(i=0;i<M;i++){
		Search(tree, a[i]);		
		for(j=0;j<N;j++){
			if(sort[j+1]==a[i]){	//当数组的下一个是要查询的数据，则此数就是前驱结点
				printf("%d ", sort[j]);
			}
			else if(sort[j]==a[i]&&j==0){	//如果第一个就是要查询的就是没有前驱结点
				printf("NIL ");
			}
			if(sort[j]==a[i]&&sort[j+1]!=0){	//如果此数就是要查询的，且后继节点不为0，那么就是有后继结点，输出
				printf("%d ",sort[j+1]);
			}
			else if(sort[j]==a[i]&&sort[j+1]==0){		//如果后继结点为0，那么就是没有后继
				printf("NIL ");				
			}
		} 
		printf("\n");
	}
	return 0;
} 

Bstnode* InsertBst(Bstnode* t, Bstnode* s) {
	Bstnode* p, * f;
	p = t;
	while (p != NULL) {		//目的是为了找到最后放入的位置 
		f = p;		//用f记录下要放到的位置 
		if (s->data == p->data)	return t;	//树中已有该节点，无需插入
		if (s->data < p->data)	p = p->lchild;	//在左子树上查找插入位置，如果根结点数值大于插入结点，就放入左子树，否则放右子树
		else
			p = p->rchild;
	}
	if (t == NULL){		//原树为空，返回s作为根结点
		s->parent = NULL; 
		return s;
	}
	if (s->data < f->data){		//如果根结点数值大于插入结点，就放入左子树，否则放右子树
		f->lchild = s;
		s->parent = f;
	}
	else
		f->rchild = s;
		s->parent = f;
	return t;
}

Bstnode* CreateBst(int num) {
	Bstnode* t, * s;
	int data;
	t = NULL;		//设置二叉排序树为空
	int i = 0;
	for (i; i < num; i++) {
		scanf("%d", &data);
		s = (Bstnode*)malloc(sizeof(Bstnode));	//分配新节点
		s->lchild = s->rchild = s->parent = NULL;	//左右子树，双亲结点初始化
		s->data = data;
		t = InsertBst(t, s);		//插入新节点
	}
	return t;
}

void InOrder(Bstnode*p){
	if(p!=NULL){
		InOrder(p->lchild);		//访问左子树	 
		sort[g]=p->data;		//将结点数据存入数组 
		g++;					//每次存一个就g++
		InOrder(p->rchild);		//访问右子树 
	}
}

void Search(Bstnode*p, int data){
	if(p!=NULL){
		Search(p->lchild, data);		//访问左子树，进行数据查找	 	
		if(p->data==data){		//如果找到了就进行输出 
			if(p->parent!=NULL){//输出双亲
				printf("%d ",p->parent->data);
			}
			else{
				printf("NIL ");		//如果为NULL就输出NIL
			}
			if((p->lchild!=NULL)){//输出左孩子
				printf("%d ",p->lchild->data);
			}
			else{
				printf("NIL ");
			}
			if((p->rchild!=NULL)){//输出右孩子
				printf("%d ",p->rchild->data);
			}
			else{	
				printf("NIL ");
			}			
		}
		Search(p->rchild, data);		//访问右子树，进行数据查找
	}
}

