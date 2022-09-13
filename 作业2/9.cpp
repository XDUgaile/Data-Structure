#include<stdio.h>
#include <malloc.h>

typedef int ElemType;//定义ElemType为int类型
typedef struct{
    ElemType *elem; //存储空间基址
    int length; //当前长度
    int listsize; //当前分配的存储容量
}Sqlist;

void InitList_sq(Sqlist &A)
{
    A.elem = (ElemType *)malloc(100 * sizeof(ElemType));
    A.length = 0;
    A.listsize = 100;
}

int load_sq(Sqlist &L)
{
    int i;
    if (L.length == 0)
        printf("The List is empty!");
    else
    {
        for (i = 0; i < L.length; i++)
            printf("%d ",L.elem[i]);
    }
    printf("\n");
    return 0;
}

void merge( Sqlist A,Sqlist B, Sqlist &C)
{
    int i = 0, j = 0, k = 0;  // A B C三个数组指针 i,j,k;
    while (i < A.length&&j < B.length)  //循环退出的条件
    {
        if (A.elem[i]<B.elem[j])  //如果A的值比B的值小，那么把A的值赋给C
        {
            C.elem[k] = A.elem[i];
            i++;
            k++;
        }
        else// (A.elem[i]>B.elem[j])
        {
            C.elem[k] = B.elem[j];
            j++;
            k++;
        }
    }
    while (i<A.length) // 数组A还有元素，但是B已经没有  就将A剩下元素接在C表的表尾
    {
        C.elem[k] = A.elem[i]; 
        i++;
        k++;
    }
    while (j<B.length)
    {
        C.elem[k] = B.elem[j];
        j++;
        k++;
    }
    C.length = k;  //数组A B都完全接完，表C长度是A B表长之和

}

int main()
{
    Sqlist A;
    Sqlist B;
    Sqlist C;
    int m, n, c;
    int i = 0;
    InitList_sq(A);
    InitList_sq(B);
    InitList_sq(C);
    printf("输入A的长度：");
    scanf("%d",&m);
    for (i = 0; i < m; i++)
    {
        scanf("%d", &A.elem[i]);
    }
    A.length = m;
    printf("输入B的长度：");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &B.elem[i]);
    }
    B.length = n;
    c = m + n;//C的表长
    printf("List A:");
    load_sq(A);
    printf("List B:");
    load_sq(B);
    merge(A,B,C);
    printf("List C:");
    load_sq(C);
    return 0;
}
