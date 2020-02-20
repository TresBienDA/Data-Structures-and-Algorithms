#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int ElemType;   // ElemType���͸���ʵ������������������Ϊint 
typedef int Status;     // Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��OK�� 

typedef struct Node
{
	ElemType data;
	struct Node *next;
}Node;
typedef struct Node *LinkList;

Status GetElem(LinkList L,int i,ElemType *e)
{
	int j;
	LinkList p;//�������ָ�룻 
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
	*L=(LinkList)malloc(sizeof(Node));//����ͷ�ڵ� ��
	(*L)->next=NULL;
	for(i=0;i<n;i++)
	{
		p=(Node*)malloc(sizeof(Node)); //�����ս�㣻 
		p->data=rand()%100+1;//���������������� 
		p->next=(*L)->next; 
		(*L)->next=p;//�½ڵ��������
	}//ͷ�巨(��ͷ�ڵ㣩�������� 
		printf("�������");
}

void CreateListTail(LinkList *L,int n)
{
	LinkList s,r;//�������ָ���βָ�룻 
	int i;
	srand(time(0));
	*L=(LinkList)malloc(sizeof(Node));
	r=*L;
	for(i=0;i<n;i++){
		s=(Node*)malloc(sizeof(Node));//������һ�����;
		s->data=rand()%100+1;//�������������������
		r->next=s;// ������ָ���򸳸�βָ��;
		r=s;
	}
	r->next=NULL;
	printf("�������"); 
}


void Traverse(LinkList L)
{
	int i;
	LinkList p;//�������ָ�� �� 
	p=L->next;//����ָ��ָ���һ����㣻 
	if(p==NULL)
	{
		printf("�����\n");
	}
	for(i=0;p!=NULL;i++) 
	{
		printf("% d",p->data);
		p=p->next;
	}//�����������Ԫ�أ� 
	printf("\n");
}

void ClearList(LinkList *L)
{
	int i;
	LinkList p,q;//��������ָ�� 
	p=(*L)->next;
	for(i=0;p!=NULL;i++)
	{
		q=p->next;
		free(p);
		p=q;
	}
	(*L)->next=NULL; 
	printf("������ɾ��\n");
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
	printf("1.ͷ�巨���������� \n2.β�巨���������� \n3.���ұ���Ԫ�� \n4.�������� \n5.ɾ������ \n6.�ݹ�ɾ��ֵΪe�Ľ��\n0.�˳� \n��ѡ����Ĳ�����\n");
	while(opp!='0'){
					scanf("%c",&opp);
		switch(opp){
		case '1':
			printf("��������Ľڵ���:");
			scanf("%d",&n);
			CreateListHead(&L,n); 
			printf("\n");
		break;
		
		case '2':
			printf("��������Ľڵ���:");
			scanf("%d",&n);
			CreateListTail(&L,n);
			printf("\n");
			break;
		case '3':
			printf("������Ԫ�ص�λ��:");
			scanf("%d",&i);
			GetElem(L,i,&e);
			printf("%d",e);
			printf("\n");
			break;
		case '4':
			printf("�����е����ݣ�"); 
			Traverse(L);
			break;
		case '0':
			exit(0);
		}
	}
	printf("\n");
	return 0;
}
