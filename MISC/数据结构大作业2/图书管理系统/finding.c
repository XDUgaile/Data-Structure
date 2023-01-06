#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<time.h>
 
#define N 10000 
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
typedef int Status;
typedef char *string ;
#define m 3 //B-树的阶

/*************书的结构体***********/
 struct Book{
  unsigned int key;                   //书的编号
  char bname[20];                     //书的名称
  char writter[20];                   //作者姓名
  char publish[20];                   //出版社
}b[N];        
 
/*************B-树的存储结构***********/
typedef Book KeyType;
typedef struct BTNode{    
  int keynum;                         //结点关键值
  struct BTNode *parent;              //指向父结点的指针
  KeyType key[m+1];                 //一个结点中最多存放的书的个数
  KeyType bname[m+1];
  KeyType writter[m+1];
  KeyType publish[m+1];
  struct BTNode *ptr[m + 1];          //指向孩子结点的指针
}BTNode,*BTree;
     
 
/*************查找结果的存储结构体***********/
typedef struct{
  BTNode *pt; 
  int i;  
  int tag; 
}Result;
BTree root = NULL;

/************************绘出面板*************************/
void PrintBookFind(){
  system("CLS");        //清空
  cout << "\n\n\n====================================查询图书功能================================\n\n\n\n" << endl;
  cout << "                              1、使用 书号 查询某种书籍\n\n";
  cout << "                              2、使用 书名 查询某种书籍\n\n";
  cout << "                              3、使用 作者 查询某种书籍\n\n";
  cout << "                              4、使用 出版社 查询某种书籍\n\n";
  cout << "                               \n\n\n请输入选项的序号，按回车键结束：";
}

/***************显示书的具体信息**********/
void ShowBookMess(Book book){
  printf("\t书号为:%3d\n", book.key);
  printf("\t书名为:%3s\n", book.bname);
  printf("\t作者为:%3s\n", book.writter);
  printf("\t出版社为:%s\n", book.publish);
  printf("\n");
}

int Search(BTree p, KeyType K) {  
  if(!p){
    return -1;
  }
  int i=0;
  for(i = 0; i < p->keynum && p->key[i+1].key <= K.key; i++);
  return i;
}

/*************在m阶B树T上查找关键字K，返回结果(pt,i,tag)***********/
Result SearchBTree(BTree T, KeyType K){ 
   BTree p, q;
   int found, i;
   Result R;
   p = T; 
   q = NULL; 
   found = FALSE; 
   i = 0; 
   while (p && !found) {
      i = Search(p, K);                
      if (i > 0 && p->key[i].key == K.key) 
		  found = TRUE;    
      else { 
		  q = p;  
		  p = p->ptr[i]; 
	  }
   }
   if (found) {  
     R.pt = p; 
  	 R.i = i;  
  	 R.tag = 1;  
   } 
   else {      
     R.pt = q;  
  	 R.i = i; 
  	 R.tag = 0; 
   }
   return R;              
}

int main()
{
  BTree L = NULL;
  BookType B;
  result res;
  ReaderType R;
  int num;
  PrintBookFind();
  scanf("%d",&num);
  switch(num){
    case 1:
      printf("\n\n");
      printf("请输入书号，按回车结束：");
      scanf("%d",&key);
      rs = SearchBTree(root,key);     
      if(rs.tag == 1){
        ShowBookMess(rs.pt->key[rs.i]);
      
      }
      else{
        printf("\t你要查找的书号%s不存在!\n\n",key); 
      
      }
      printf("\n\t------------------ 查找结束----------------\n");
      printf("\t按任意键返回");
      getch();
      break;
    case 2:
      printf("\n\n");
      printf("请输入书名，按回车结束：");
      scanf("%s",&bname);
      rs = SearchBTree(root,bname);     
      if(rs.tag == 1){
        ShowBookMess(rs.pt->bname[rs.i]);
      
      }
      else{
        printf("\t你要查找的书名%s不存在!\n\n",bname); 
      
      }
      printf("\n\t------------------ 查找结束----------------\n");
      printf("\t按任意键返回");
      getch();
      break;
    case 3:
      printf("\n\n");
      printf("请输入作者姓名，按回车结束：");
      scanf("%s",writter);
      rs = SearchBTree(root,writter);     
      if(rs.tag == 1){
        ShowBookMess(rs.pt->writter[rs.i]);
      
      }
      else{
        printf("\t你要查找的作者姓名%s不存在!\n\n",kwritter); 
      
      }
      printf("\n\t------------------ 查找结束----------------\n");
      printf("\t按任意键返回");
      getch();
      break;
    case 4:
      printf("\n\n");
      printf("请输入出版社，按回车结束：");
      scanf("%s",publish);
      rs = SearchBTree(root,publish);     
      if(rs.tag == 1){
        ShowBookMess(rs.pt->publish[rs.i]);
      
      }
      else{
        printf("\t你要查找的出版社%s不存在!\n\n",publish); 
      
      }
      printf("\n\t------------------ 查找结束----------------\n");
      printf("\t按任意键返回");
      getch();
      break;
  }
  return 0;
}