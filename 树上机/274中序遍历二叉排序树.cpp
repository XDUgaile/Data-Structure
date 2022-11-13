#include<stdio.h>
#include<malloc.h>

typedef struct node {
	int data;	//数据项
	struct node* lchild, * rchild;	//左右子树指针
}Bstnode;

void InOrder(Bstnode*p);
Bstnode* InsertBst(Bstnode* t, Bstnode* s);
Bstnode* CreateBst(int num);

int main(){
	int num;
	scanf("%d", &num);
	Bstnode *tree = CreateBst(num);
	InOrder(tree);
	return 0;
} 

void InOrder(Bstnode*p){
	if(p!=NULL){
		InOrder(p->lchild);		//访问左子树	 
		printf("%d ", p->data);	//访问根结点 
		InOrder(p->rchild);		//访问右子树 
	}
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
	if (t == NULL)		//原树为空，返回s作为根结点
		return s;
	if (s->data < f->data)		//如果根结点数值大于插入结点，就放入左子树，否则放右子树
		f->lchild = s;
	else
		f->rchild = s;
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
		s->lchild = s->rchild = NULL;	//左右子树初始化
		s->data = data;
		t = InsertBst(t, s);		//插入新节点
	}
	return t;
}
