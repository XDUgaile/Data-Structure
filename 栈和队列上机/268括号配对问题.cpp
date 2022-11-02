#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSIZE 100
//使用顺序栈
typedef struct node
{
	char elements[MAXSIZE];
	int Top;
} stack;
stack *S;

stack* setnull(stack* S); //初始化栈
char pop(stack* S); //出栈函数
stack* push(stack* S, char e); //进栈函数
int correct(char String[], int len); //对输入的括号，判断能否匹配，需要调用pop和push函数

int main()
{
	int len;
	char str[100];
	int n, i; 
	scanf("%d",&n);
	int a[n];	//建立用作记录每一条括号是否匹配
	for(i = 0;i < n;i++){
	 //建立顺序栈
		S = (stack*)malloc(sizeof(stack));
	 //调用setnull函数初始化栈
		scanf("%s", &str);//输入字符串 
		len = strlen(str);
		a[i] = correct(str, len);
	}
	for(i=0;i<n;i++){
		if (a[i])		//若为1则可以匹配，否则就不能
			printf("yes\n");
		else
			printf("no\n");
	}		
	return 0;
}

stack* setnull(stack* S) {
	S->Top= -1;		//初始化栈顶为-1 
	return S;
}

stack* push(stack* S, char e) {
	S->Top++;		//每次压入栈一个元素就将栈顶加一 
	S->elements[S->Top] = e;	
	return S;
}

char pop(stack* S) {
	char e=NULL;
	e = S->elements[S->Top];		 
	S->Top--;		//出栈一个元素就将栈顶向下移一位 
	return e;
}

int correct(char String[], int len) {
	int i;
	char temp = NULL;
	setnull(S);		//初始化栈 
	for (i = 0; i < len; i++) {
		if (String[i] == '(' || String[i] == '[') {		//当输入的括号为左括号时，就压入栈
			push(S, String[i]);
		}
		else {
			if (S->Top == -1) {			//如果是左括号，并且之前没有入栈元素时，就返回0表示不匹配
				return 0;
			}
			temp = pop(S);		//出栈一个元素，和字符串的括号进行匹配，只有两种情况为匹配失败。
			if (String[i] == ')' && temp != '(') {		
				return 0;
			}
			if (String[i] == ']' && temp != '[') {
				return 0;
			}
		}
	}
	if (S->Top == -1) {		//若S->Top为-1，则证明完全匹配
		return 1;		//返回标志 
	}
	else {			//否则即为未完全匹配
		return 0;
	}
}
