#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int ElemType;   // ElemType类型根据实际情况而定，这里假设为int 
typedef int Status;     // Status是函数的类型,其值是函数结果状态代码，如OK等 

typedef struct Node
{
	ElemType data;
	struct Node *next;
}Node;
typedef struct Node *LinkList;

Status GetElem(LinkList L,int i,ElemType *e)
{
	int j;
	LinkList p;//定义控制指针； 
	p=L->next;
	j=1;
	while(p&&j<i)
	{
		p=p->next;
		j++;
	}
	if(!p||j>i)
	return ERROR;
	*e=p->data;
	return OK;
} 

void CreateListHead(LinkList *L,int n)
{
	LinkList p;
	int i;
	srand(time(0));
	*L=(LinkList)malloc(sizeof(Node));//创建头节点 ；
	(*L)->next=NULL;
	for(i=0;i<n;i++)
	{
		p=(Node*)malloc(sizeof(Node)); //创建空结点； 
		p->data=rand()%100+1;//数据域填充随机数； 
		p->next=(*L)->next; 
		(*L)->next=p;//新节点插入链表；
	}//头插法(有头节点）创建链表； 
		printf("创建完成");
}

void CreateListTail(LinkList *L,int n)
{
	LinkList s,r;//定义控制指针和尾指针； 
	int i;
	srand(time(0));
	*L=(LinkList)malloc(sizeof(Node));
	r=*L;
	for(i=0;i<n;i++){
		s=(Node*)malloc(sizeof(Node));//创建第一个结点;
		s->data=rand()%100+1;//用随机数填充结点的数据域；
		r->next=s;// 将结点的指针域赋给尾指针;
		r=s;
	}
	r->next=NULL;
	printf("创建完成"); 
}


void Traverse(LinkList L)
{
	int i;
	LinkList p;//定义控制指针 ； 
	p=L->next;//控制指针指向第一个结点； 
	if(p==NULL)
	{
		printf("链表空\n");
	}
	for(i=0;p!=NULL;i++) 
	{
		printf("% d",p->data);
		p=p->next;
	}//依次输出链表元素； 
	printf("\n");
}

void ClearList(LinkList *L)
{
	int i;
	LinkList p,q;//创建控制指针 
	p=(*L)->next;
	for(i=0;p!=NULL;i++)
	{
		q=p->next;
		free(p);
		p=q;
	}
	(*L)->next=NULL; 
	printf("链表已删除\n");
}

DeleteE(LinkList *L)
{
	
}

int main()
{
	LinkList L;
	int n,i;
	char opp;
	ElemType e;
	printf("1.头插法创建单链表 \n2.尾插法创建单链表 \n3.查找表中元素 \n4.遍历链表 \n5.删除链表 \n6.递归删除值为e的结点\n0.退出 \n请选择你的操作：\n");
	while(opp!='0'){
					scanf("%c",&opp);
		switch(opp){
		case '1':
			printf("输入链表的节点数:");
			scanf("%d",&n);
			CreateListHead(&L,n); 
			printf("\n");
		break;
		
		case '2':
			printf("输入链表的节点数:");
			scanf("%d",&n);
			CreateListTail(&L,n);
			printf("\n");
			break;
		case '3':
			printf("请输入元素的位置:");
			scanf("%d",&i);
			GetElem(L,i,&e);
			printf("%d",e);
			printf("\n");
			break;
		case '4':
			printf("链表中的数据："); 
			Traverse(L);
			break;
		case '0':
			exit(0);
		}
	}
	printf("\n");
	return 0;
}
