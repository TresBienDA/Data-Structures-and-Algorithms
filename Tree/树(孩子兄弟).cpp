#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define Maxsize 100

typedef struct CSNode
{
	int data;
	struct CSNode *firstchild;
	struct CSNode *nextsibling;
}CSNode;

void preorder(CSNode *T)
{
	if(T==NULL) return;
	printf("% d",T->data);
	preorder(T->firstchild);
	preorder(T->nextsibling); 
}

int CountLeaf(CSNode *T)                                                        //统计树的叶子结点数
{
	if(T==NULL) return 0;                                                        
	CSNode *p;
	CSNode *que[Maxsize];//层次遍历队列 
	int rear=0,front=0;
	int Leaf=0;
	que[++rear]=T;
	while(front<rear)
	{
		p=que[++front];
		while(p!=NULL)
		{
		if(p->firstchild==NULL) Leaf++;//这里入队与二叉树层次遍历入队有区别 
			if(p->firstchild!=NULL){
			que[++rear]=p->firstchild;//在层次遍历算法中入队的只有下一层结点 
		}
			p=p->nextsibling;//同层次访问，检查是否有孩子，有孩子则入队 
		}
	}
	return Leaf;
}

int CountWidth(CSNode *T)
{
	if(T==NULL) return 0;
	CSNode *p;
	CSNode *que[Maxsize];//层次遍历队列 
	int rear=0,front=0;
	int width=0;
	int maxwidth=0;
	que[++rear]=T;//根节点入队 
	while(front<rear)//队列孔停止循环 
	{
		p=que[++front];
		while(p!=NULL)
		{
		if(p->firstchild!=NULL){
			que[++rear]=p->firstchild;
			}
			p=p->nextsibling;
			width++;
		}
		if(width>maxwidth){//判断该层结点数是否比最大结点大，如是则更新最大结点 
			maxwidth=width;
			width=0;
		}
	}
	return maxwidth; 
}

int Height(CSNode *T)
{
	if(T==NULL) return 0;
	CSNode *que[Maxsize];
	int rear=0,front=0;
	que[++rear]=T; 
	CSNode *p;
	int height=1;
	int last=0;//last与front的关系来判断是否进入下一层 
	while(front<rear)
	{
		p=que[++front];
		while(p!=NULL)
		{
			if(p->firstchild!=NULL)//下一层按顺序入队 
			{
				que[++rear]=p->firstchild;
			}
			p=p->nextsibling;
		}
		if(front>last){//若满足条件则层数加一，因为此时front已指向下一层的结点 
			last=rear; 
			height++;
		}
	}
	return height;
}

CSNode *Search(CSNode *T,int x)
{
	if(T==NULL) return NULL;
	if(T->data==x){
		printf("查找成功!"); 
		return T;
	}
	if(Search(T->firstchild,x)==NULL){//递归查找元素为X的结点 
			Search(T->nextsibling,x);
	}
}

void PrintChildren(CSNode *T,int x)
{
	CSNode *p,*q;
	p=Search(T,x);
	if(p->firstchild!=NULL){//结点如果有孩子，孩子为配偶，配偶的右指针上的单链表为所有的孩子 
		q=p->firstchild;
		}
		else q=p;
	while(q!=NULL){//遍历孩子单链表访问孩子结点 
		printf("% d",q->data);
		q=q->nextsibling;
	}
}

int main()
{
	CSNode A,B,C,D,E,F,G;
	A.firstchild=&B;
	A.nextsibling=NULL;
	B.firstchild=&E;
	B.nextsibling=&C;
	C.firstchild=&G;
	C.nextsibling=&D;
	D.firstchild=NULL;
	D.nextsibling=NULL;
	E.firstchild=NULL;
	E.nextsibling=&F;
	F.firstchild=NULL;
	F.nextsibling=NULL;
	G.firstchild=NULL;
	G.nextsibling=NULL; 
	A.data=1;B.data=2;C.data=3;D.data=4;E.data=5;F.data=6;G.data=7;
	char opp;
	int x;
	printf("请输入操作序号:\n");
    printf("1.先根遍历树.\n2.统计树的叶子结点数\n3.求树的度\n4.求树的深度\n5.输出某家庭成员的所有子女\n");
	while(opp!='0')
	{
		scanf("%c",&opp);
	switch(opp)
	{
		case '1':
			preorder(&A);
			printf("\n");
			break;
	    case '2':
	    	printf("树有%d个叶子结点！",CountLeaf(&A)); 
	    	printf("\n");
	    	break;
	    case '3':
	    	printf("树的度为%d！",CountWidth(&A));
	    	printf("\n");
	    	break;
	    case '4':
	    	printf("树的深度为%d",Height(&A));
	    	printf("\n");
	    	break;
	    case '5':
	    	printf("请输入要查找的成员:");
	    	scanf("%d",&x);
	    	PrintChildren(&A,x);
	    	printf("\n");
	    	break;
	    case '6':
	    	printf("\n");
	    	break;
	    case '7':
	    	printf("\n");
	    	break;
	    		
	    case '8':
			printf("\n");
			break; 
	    case '9':
			printf("\n");
			break;
	    case 'a':
	    	printf("\n");
	    	break;
	    case 'b':
	    	printf("\n");
	    	break;
	    case 'c':
	    	printf("\n");
	    	break;
	    case 'd':
	    	printf("\n");
	    	break;
	    case 'e':
			printf("\n");
			break;
		case 'f':
			break; 
		case 'g':
			break;
		case 'h':
			break;
		case 'i':
			break;
		case 'j':
			break;
		case 'k':
			printf("\n");
			break;
		case 'l':
			printf("\n");
			break;
		case 'm':
	    case '0':
	    	exit(0);
	}
	}
} 
