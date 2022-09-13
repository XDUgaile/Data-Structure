#include <stdio.h>
#include <math.h> 
#include <string.h>
#include <stdlib.h> 
#define MAX 1024
typedef struct{
	int *elem;
	int length;
	int listsize;
}sqlist; 

int main()
{
	sqlist A, B;
	int a, m, i, x = 1;
	A.elem = (int *)malloc(100 * sizeof(int));
    A.length = 0;
    A.listsize = 100;
    B.elem = (int *)malloc(100 * sizeof(int));
    B.length = 0;
    B.listsize = 100;
    printf("输入A的长度：");
    scanf("%d",&a);
	printf("输入A：");
    for (i = 0; i < a; i++)
    {
        scanf("%d", &A.elem[i]);
    }
    A.length = a;
    printf("输入B的长度：");
    scanf("%d",&m);
	printf("输入B：");
    for (i = 0; i < m; i++)
    {
        scanf("%d", &B.elem[i]);
    }
    B.length = m;
    for(i=0;i<a;i++){
    	if(A.elem[i] == x){
    		for(int j=0;j<m;j++){
    			A.elem[i+j+1] = B.elem[j];
			}
			a = i + m + 1;
		}
	}
	for(i=0;i<a;i++){
		printf("%d ",A.elem[i]);
	}
	return 0;
}
