//输入字符串，判断是否回文。
//下面是使用的子函数及其功能的说明：
//下面给出数据结构和main函数的框架(以及提示)，实现子函数，完成整个程序。
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
int correct(char String[], int len); //对输入的字符串，判断是否为回文，需要调用pop和push函数

int main()
{
	int sign; //sign为标志，sign=1是回文，sign=0不是回文 
	int len;
	char str[100];
 //建立顺序栈
	S = (stack*)malloc(sizeof(stack));
 //调用setnull函数初始化栈
	gets(str);//输入字符串 
	len = strlen(str);
	sign = correct(str, len);
	if (sign)
		printf("right\n");
	else
		printf("wrong\n");
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
	int i, sign=1;
	setnull(S);		//初始化栈 
	for (i = 0; i < len / 2; i++) {
		push(S, String[i]);			//通过循环将数组元素的一半压入栈（奇数的话中心数不压入栈） 
	}
	for (i = len/2; i > 0; i--) {
//		printf("%c==%c",pop(S), String[len-i]); 	//这里调试完之后就要注释掉，否则会导致栈顶元素出栈 
		if(pop(S)==String[len-i]){		//要是每次出栈的元素和字符串后面的元素一样就是回文 
		}
		else {
			sign = 0;		//否则只要有一个不一样就为非回文，跳出循环 
			break;
		}
	}
	return sign;		//返回标志 
}
