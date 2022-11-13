#include <stdio.h>
#define INF 65535

struct huffman {
	int weight;
	int parent, lchild, rchild;
}HT[1001]; 

void createHT(int n);
int main()
{
	int n; 
	scanf("%d", &n);
	int i, sum = 0;
	createHT(n);
	for (i = n; i < 2 * n - 1; i++)		//由于新节点序号是从n->2n-1，由此确定累加范围
		sum += HT[i].weight;
	printf("%d\n", sum);
	return 0;
}

void createHT(int n)
{
	int i, j;
	for (i = 0; i < 2 * n - 1; i++)
		HT[i].parent = HT[i].lchild = HT[i].rchild = -1;	//初始化 

	for (i = 0; i < n; i++)
		scanf("%d", &HT[i].weight);		//初始化 

	int a, b;		//表明第几个 
	int a1, b1;		//表明对应权重 
	for (i = 0; i < n - 1; i++)
	{
		a1 = b1 = INF;
		for (j = 0; j < n + i; j++)
		{
			if (HT[j].parent == -1 && HT[j].weight < a1)	//寻找比a1权重小，且没有双亲结点的结点 
			{
				b = a;		//如果有，将次小的顺序赋值给b 
				a = j;		//a变为最小的序号 
				b1 = a1;	//次小权重赋值b1
				a1 = HT[j].weight;	//最小权重赋值a1 
			}
			else if (HT[j].parent == -1 && HT[j].weight < b1)		//有可能是权重大于a小于b,再次进行判断 
			{
				b = j;
				b1 = HT[j].weight;
			}
		}

		HT[n + i].weight = HT[a].weight + HT[b].weight;		//选用两小造新树 
		HT[n + i].lchild = a;		//双亲的孩子结点 
		HT[n + i].rchild = b;
		HT[a].parent = HT[b].parent = n + i;  	//双亲结点的序号 
	}
}

