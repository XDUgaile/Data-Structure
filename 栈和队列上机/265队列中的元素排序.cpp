#include<iostream>
#include<cstdio>
#include<malloc.h>
#define MAXQSIZE 1000
#define INF 99999999
using namespace std;

typedef struct {
	int data[1000];	
	int front;		//头指针
	int rear;		//尾指针
}SqQueue;

void InitQueue(SqQueue& Q) {
	Q.front = Q.rear = 0;		//头指针尾指针置零，队列为空
}

int EnQueue(SqQueue& Q, int e) {		//进队
	if ((Q.rear + 1) % MAXQSIZE == Q.front) return 0;	//队满
	Q.data[Q.rear] = e;		//新元素加入队尾
	Q.rear = (Q.rear + 1) % MAXQSIZE;	//队尾指针+1
	return 1;
}

int DeQueue(SqQueue& Q) {		//出队
	if (Q.front == Q.rear) return 0;	//队空
	int e = Q.data[Q.front];		//保存队头元素
	Q.front = (Q.front + 1) % MAXQSIZE;	//队头指针+1
	return e;
}

int main(){
	SqQueue *Q1, *Q2;
	int n = 0, i, j, temp, min;
	cin >> n;			//读入有多少个
	Q1 = (SqQueue*)malloc(sizeof(SqQueue));
	Q2 = (SqQueue*)malloc(sizeof(SqQueue));
	for (i = 0; i < n; i++) {
		cin >> temp;
		EnQueue(*Q1, temp);		//输入进队列
	}
//	for(i=0;i<n;i++){
//		printf("%d",Q1->data[i]);
//	}
	for (i = 0; i < n; i++)
	{
		min = INF;	//使min最大 

		for (j = i; j < n; j++)//开始一轮循环，筛选出原队列中的最小元素，并将其取出放入新队列的队尾
		{

			int m = DeQueue(*Q1);//m为原队列的队头元素
			if (m < min)
			{//取队头元素，与最小值比较
				if (min != INF) EnQueue(*Q1, min);	//如果比最小值小，则用这个元素取代最小值，将原来的最小值入队
				min = m;
			}
			else
			{
				EnQueue(*Q1, m);	//如果比最小值大，则将取出来的元素放到原队列的队尾
			}
		}//经过一轮循环后，得到的最小值为队列中的最小值
		EnQueue(*Q2, min);//将这个最小值添加到辅助队列的队尾

	}//经过N轮循环，新队列的元素按增序排列
	printf("%d", DeQueue(*Q2));
	for (i = 0; i < n-1; i++)	
	{
		printf(" %d", DeQueue(*Q2));
	}
	printf("\n");
	return 0;
}
