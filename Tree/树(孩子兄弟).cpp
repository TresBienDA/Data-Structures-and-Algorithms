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

int CountLeaf(CSNode *T)                                                        //ͳ������Ҷ�ӽ����
{
	if(T==NULL) return 0;                                                        
	CSNode *p;
	CSNode *que[Maxsize];//��α������� 
	int rear=0,front=0;
	int Leaf=0;
	que[++rear]=T;
	while(front<rear)
	{
		p=que[++front];
		while(p!=NULL)
		{
		if(p->firstchild==NULL) Leaf++;//����������������α������������ 
			if(p->firstchild!=NULL){
			que[++rear]=p->firstchild;//�ڲ�α����㷨����ӵ�ֻ����һ���� 
		}
			p=p->nextsibling;//ͬ��η��ʣ�����Ƿ��к��ӣ��к�������� 
		}
	}
	return Leaf;
}

int CountWidth(CSNode *T)
{
	if(T==NULL) return 0;
	CSNode *p;
	CSNode *que[Maxsize];//��α������� 
	int rear=0,front=0;
	int width=0;
	int maxwidth=0;
	que[++rear]=T;//���ڵ���� 
	while(front<rear)//���п�ֹͣѭ�� 
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
		if(width>maxwidth){//�жϸò������Ƿ���������������������� 
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
	int last=0;//last��front�Ĺ�ϵ���ж��Ƿ������һ�� 
	while(front<rear)
	{
		p=que[++front];
		while(p!=NULL)
		{
			if(p->firstchild!=NULL)//��һ�㰴˳����� 
			{
				que[++rear]=p->firstchild;
			}
			p=p->nextsibling;
		}
		if(front>last){//�����������������һ����Ϊ��ʱfront��ָ����һ��Ľ�� 
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
		printf("���ҳɹ�!"); 
		return T;
	}
	if(Search(T->firstchild,x)==NULL){//�ݹ����Ԫ��ΪX�Ľ�� 
			Search(T->nextsibling,x);
	}
}

void PrintChildren(CSNode *T,int x)
{
	CSNode *p,*q;
	p=Search(T,x);
	if(p->firstchild!=NULL){//�������к��ӣ�����Ϊ��ż����ż����ָ���ϵĵ�����Ϊ���еĺ��� 
		q=p->firstchild;
		}
		else q=p;
	while(q!=NULL){//�������ӵ�������ʺ��ӽ�� 
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
	printf("������������:\n");
    printf("1.�ȸ�������.\n2.ͳ������Ҷ�ӽ����\n3.�����Ķ�\n4.���������\n5.���ĳ��ͥ��Ա��������Ů\n");
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
	    	printf("����%d��Ҷ�ӽ�㣡",CountLeaf(&A)); 
	    	printf("\n");
	    	break;
	    case '3':
	    	printf("���Ķ�Ϊ%d��",CountWidth(&A));
	    	printf("\n");
	    	break;
	    case '4':
	    	printf("�������Ϊ%d",Height(&A));
	    	printf("\n");
	    	break;
	    case '5':
	    	printf("������Ҫ���ҵĳ�Ա:");
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
