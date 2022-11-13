#include<stdio.h>
#include<malloc.h>
#define MAXSIZE 1024

typedef struct node {
	char data;		//×Ö·ûÏî
	struct node* lchild, * rchild;	//×óÓÒ×ÓÊ÷
}Bitree;
Bitree root;

Bitree* CreateTree();
int CountLeaf(Bitree* p);

int main() {
	Bitree *tree = CreateTree();
	int sum = CountLeaf(tree);
	printf("\n");
	printf("%d", sum);
	return 0;
}
int CountLeaf(Bitree *p){
	if(!p)
		return 0;
	else if(p->lchild==NULL&&p->rchild==NULL){
		printf("%c ", p->data); 
		return 1;
	}
	else
		return CountLeaf(p->lchild)+CountLeaf(p->rchild);
}

Bitree* CreateTree() {
	char ch;
	Bitree* Q[MAXSIZE];
	int front = 1, rear = 0;
	Bitree* root, * s;
	root = NULL;
	while ((ch = getchar()) != '#') {
		s = NULL;
		if (ch != '@') {
			s = (Bitree*)malloc(sizeof(Bitree));
			s->data = ch;
			s->lchild = NULL;
			s->rchild = NULL;
		}
		rear++;
		Q[rear] = s;
		if (rear == 1)
			root = s;
		else {
			if (s && Q[front]) {
				if (rear % 2 == 0) {
					Q[front]->lchild = s;
				}
				else
					Q[front]->rchild = s;
			}
			if (rear % 2 == 1)
				front++;
		}
	}
	return root;
}
