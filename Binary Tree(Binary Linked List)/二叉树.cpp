#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define Maxsize 100

typedef struct BTNode
{
	int data;
	struct BTNode *lchild;
	struct BTNode *rchild;
}BTNode;

typedef struct
{
	BTNode *t;
	int tag;
}TagStack;

void preorder(BTNode *bt)
{
	if(bt==NULL) return;                            //�ݹ���ڽ��ڵ�Ϊ��ʱ���� 
	printf("% d",bt->data);
	preorder(bt->lchild);                            //����ϵͳջ����ջ������������ǰ 
	preorder(bt->rchild);
}
                                                                                  
void midorder(BTNode *bt)
{
	if(bt==NULL) return;
	midorder(bt->lchild);
	printf("% d",bt->data);
	midorder(bt->rchild); 
}

void postorder(BTNode *bt)
{
	if(bt==NULL) return;
	postorder(bt->lchild);
	postorder(bt->rchild);
	printf("% d",bt->data);
}

void Nopreorder(BTNode *bt)//��������ǵݹ��㷨 
{
	BTNode *stack[Maxsize];
	int top=-1;
	BTNode *p;
	stack[++top]=bt;
	while(top!=-1)
	{
		p=stack[top--];
		printf("% d",p->data);
		if(p->rchild!=NULL)//�����ң������Һ�������ջ 
		stack[++top]=p->rchild;
		if(p->lchild!=NULL)
		stack[++top]=p->lchild;
	}
}

void levelorder(BTNode *bt)//��α����㷨 
{
	BTNode *p;
	BTNode *que[Maxsize];
	int rear=0;int front=0;
	que[++rear]=bt;
	while(rear>front) 
	{
		p=que[++front];
		printf("% d",p->data);
		if(p->lchild!=NULL){
			que[++rear]=p->lchild;
		}
		if(p->rchild!=NULL){
			que[++rear]=p->rchild;
		}
	}
}

void Nomidorder(BTNode *bt)
{
	BTNode *stack[Maxsize];
	int top=-1;
	BTNode *p;
	p=bt;
	while(p!=NULL||top!=-1)//ע��ѭ������Ҫ���� P��=NULL 
	{
		while(p!=NULL)
		{
			stack[++top]=p;
			p=p->lchild;
		} 
		if(top!=-1){
			p=stack[top--];
			printf("% d",p->data);
			p=p->rchild;
		}
	}
	
}

//�����α�����������
//������α����Ľ��ѹ��һ��ջ�У�Ȼ���ջ 
void Reverselevel(BTNode *bt) 
{
	BTNode *que[Maxsize];
	int rear=0,front=0;
	BTNode *stack[Maxsize];
	int top=-1;
	BTNode *p;
	que[++rear]=bt;
	while(rear>front)
	{
		p=que[++front];//��α���������Ԫ�س��� 
		stack[++top]=p;// ���ӵ�Ԫ�ؽ�ջ 
		if(p->lchild!=NULL)
		{
			que[++rear]=p->lchild;
		}
		if(p->rchild!=NULL)
		{
			que[++rear]=p->rchild;
		}
	}
	while(top!=-1)//ջ�е�Ԫ��ȫ����ջ 
	{
		printf("% d",stack[top--]->data);
	}
}

//������������
//�ò�α����ķ�����ʹ��last�������βָ��front��ʵ�ֲ�εļ�¼ 
void Height(BTNode *bt) 
{
	BTNode *que[Maxsize];
	int rear=0,front=0;
	int count=0;
	BTNode *p;
	BTNode *last;
	last=bt;
	que[++rear]=bt;
	while(rear>front)
	{
		p=que[++front];
		if(p->lchild!=NULL)
		{
			que[++rear]=p->lchild; 
		}
		if(p->rchild!=NULL)
		{
			que[++rear]=p->rchild;
		}
		if(p==last){//������ָ��ָ��last���ʱ���ò��Ѿ�ȫ��������lastָ����һ�����һ����� 
			last=que[rear];//��һ������һ������Ѿ���ӣ�����lastֱ��ָ���β 
			count++;
		}
	}
	printf("������һ����%d��",count);
}

//�ж϶������Ƿ�Ϊ��ȫ������
//�ò�α����ķ��������еĽ�㼰��ջ�ǿյĺ��ӽ�����
//�����ö��У���������ĳ�ս��֮���ٳ��ַǿս�㣬��Ϊ��ȫ������ 
bool Iscomplished(BTNode *bt)
{
	BTNode *p;
	BTNode *que[Maxsize];
	int rear=0,front1=0,front2=0;
	que[++rear]=bt;
	while(rear>front1)
	{
		p=que[++front1];
		if(p!=NULL){
		que[++rear]=p->lchild;
		que[++rear]=p->rchild;
	}
	}
	p=que[front2];
	while(p!=NULL)
	{
		p=que[++front2];
	}
	while(front2<rear)//�������Ѱ���ȫ����������ʽ���������� 
	{
		p=que[++front2];
		if(p!=NULL){
			printf("������ȫ��������\n");
			return 0;
		}
	}
}

void CountNotEmpty(BTNode *bt)                                                  //������ 
{
	BTNode *p;
	BTNode *que[Maxsize];
	int count=0;
	int rear=0,front1=0,front2=0;
	que[++rear]=bt;
	while(rear>front1)
	{
		p=que[++front1];
		if(p->lchild!=NULL){
			que[++rear]=p->lchild;
		}
		if(p->rchild!=NULL){
			que[++rear]=p->rchild;
		}
	}
	p=que[front2];
	while(front2<rear)
	{
		if(p->lchild!=NULL&&p->rchild!=NULL){
			count++;
			p=que[++front2];
		}
		else{
			p=que[++front2];
		}
	}
	printf("һ����%d��˫��֧���!\n",count);
}

void exchange(BTNode *bt,BTNode *temp)                                                       //������ 
{
	if(bt=NULL) return;
	exchange(bt->lchild,temp);
	exchange(bt->rchild,temp);
	temp=bt->lchild;
	bt->lchild=bt->rchild;
	bt->rchild=temp;
	temp=NULL;
}

void Nodek(BTNode *bt,int k)
{
	BTNode *stack[Maxsize];
	int top=-1;
	int n=0; 
	BTNode *p;
	stack[++top]=bt;
	while(top!=-1)
	{
		p=stack[top--];
		n++;
		if(n==k){
		printf("��%d�������%d!\n",k,p->data);
	};
		if(p->rchild!=NULL)
		{
			stack[++top]=p->rchild;
		}
		if(p->lchild!=NULL)
		{
			stack[++top]=p->lchild;
		}
	}
}

void DeleteTreeX(BTNode *bt)
{
	if(bt==NULL) return;
	DeleteTreeX(bt->lchild);
	DeleteTreeX(bt->lchild);
	free(bt);
}

void SearchX(BTNode *bt,int x)
{
	if(bt->data==x){
		DeleteTreeX(bt);
		printf("ɾ����ɣ�\n");
		return;
	}
	BTNode *stack[Maxsize];
	int top=-1;
	BTNode *p;
	stack[++top]=bt;
	while(p!=NULL)                                                              //�ؼ�������������ķǵݹ黯 
	{
		p=stack[top--];
		if(p->rchild!=NULL)
		{
			if(p->rchild->data==x){
				DeleteTreeX(p->rchild);
				p->rchild=NULL;
				printf("ɾ����ɣ�\n");
				preorder(bt);
				return;
			}
			else{
				stack[++top]=p->rchild;
			}
		}
		if(p->lchild!=NULL)
		{
			if(p->lchild->data==x){
				DeleteTreeX(p->lchild);
				p->lchild=NULL;
				printf("ɾ����ɣ�\n");
				preorder(bt);
				return;
			}
			else{
				stack[++top]=p->lchild;
			}
		}
	}
	
}

void Nopostorder(BTNode *bt)												//�������㵽X����·�� 
{
	BTNode *p; 
	TagStack s[Maxsize];
	int top=-1;
	p=bt;
	while(top!=-1||p!=NULL)
	{
		while(p!=NULL){
			s[++top].t=p;
			s[top].tag=0;
			p=p->lchild;
		}//������ 
		while(top!=-1&&s[top].tag==1) 
		{
			printf("% d",s[top].t->data);
			top--;
		}//������������ſɳ�ջ 
		if(top!=-1)
		{
			s[top].tag=1;
			p=s[top].t->rchild;//����������������־λ��Ϊ1 
		}
	}
}
																				//1.ͳ�ƶ������еĽ���� DONE!
																				//2.ͳ�ƶ������е�Ҷ�ӽ���� DONE!
																				//3.ͳ�ƶ������ж�Ϊ1�Ľ���� DONE!
																				//4.ͳ�ƶ������ж�Ϊ2�Ľ�� DONE!
																				//5.ͳ�ƶ������ĸ߶� DONE!
																				//6.������������ 
																				//7.����㷨���ƶ�����
																				//8.ʹ��˳��洢�洢����������Ʒǵݹ�ǰ�����
																				//9.˳��洢�������
//ͳ��Ҷ���ĸ��� 
int CountNode(BTNode *bt)
{
	if(bt==NULL) return 0;
	return CountNode(bt->lchild)+CountNode(bt->rchild)+1;//���Ľ�����=�������Ľ�����+�������Ľ����� 
}

//ͳ��Ҷ���ĸ��� 
int CountLeafNode(BTNode *bt)
{
	if(bt==NULL) return 0;//������Ҷ��� 
	if(bt->lchild==NULL&&bt->rchild==NULL) return 1;//�������޺��ӣ�����һ��Ҷ��� 
	if(bt->lchild!=NULL&&bt->rchild!=NULL){
		return CountLeafNode(bt->lchild)+CountLeafNode(bt->rchild);//�����������Һ��ӣ� 
	}                                                             //Ҷ������=������Ҷ���+������Ҷ��� 
}

//ͳ�ƶ�Ϊһ�Ľ����� 
int CountNode1(BTNode *bt)
{
	if(bt==NULL) return 0;//�����޶�Ϊһ�Ľ�� 
	if(bt->lchild==NULL&&bt->rchild==NULL) return 0;//���и�������û�ж�Ϊһ�Ľ�� 
	if(bt->lchild!=NULL&&bt->rchild!=NULL)//�����Һ��ӵ�����N1=������N1+������N1 
		return CountNode1(bt->lchild)+CountNode1(bt->rchild);
	else
		return CountNode1(bt->lchild)+CountNode1(bt->rchild)+1;//����������N1=�����+������N1+������N1 
}                                                              //��N1����N1����һ��Ϊ0 


//ͳ�ƶ������ж�Ϊ���Ľ�� 
int CountNode2(BTNode *bt)
{
	if(bt==NULL) return 0;//����Ϊ�գ�����0����Ϊ���Ľ�� 
	if(bt->lchild!=NULL&&bt->rchild!=NULL) 
	return CountNode2(bt->lchild)+CountNode2(bt->rchild)+1;
	//��Ϊ���Ľ�����=�������ж�Ϊ���Ľ�����+�������ж�Ϊ���Ľ�����+1������� 
}
//�ݹ�ͳ�����ĸ߶� 
int CountHeight(BTNode *bt)
{
	if(bt==NULL) return 0;//����Ϊ�գ��߶�Ϊ0 
	return (CountHeight(bt->lchild)>CountHeight(bt->rchild)?CountHeight(bt->lchild):CountHeight(bt->rchild))+1;
	//���ĸ߶�=���������������ϸ��ߵĸ߶�+1 
}

//��α�������������� 
int Width(BTNode *bt)
{
	BTNode *p;
	int last;//lastָ�������ж�һ���Ƿ������� 
	BTNode *que[Maxsize];//��α������� 
	int rear=0,front=0;
	int b=0,maxb=0; 
	que[++rear]=bt;
	last=0;
	while(front<rear)//���п�ʱѭ������ 
	{
		p=que[++front];//������ 
		if(p->lchild!=NULL){
			que[++rear]=p->lchild;
		}
		if(p->rchild!=NULL){
			que[++rear]=p->rchild;
		}
		b++;
		if(front>last)//frontָ��ָ��һ������һ����� 
		{
			last=rear;//lastָ����һ�����һ����� 
			if(b>maxb){//����ò����������������������������� 
				maxb=b;
			}
			b=0;
		}
	}
	return maxb;
}

//��α��������ķ�ï�̶� 
int WidthHeight(BTNode *bt)
{
	BTNode *p;
	BTNode *que[Maxsize];
	int rear=0,front=0,last=0;
	int height=1,maxb=0,b=0;
	que[++rear]=bt;
	while(rear>front)
	{
		p=que[++front];
		b++;
		if(p->lchild!=NULL){
			que[++rear]=p->lchild;
		}
		if(p->rchild!=NULL){
			que[++rear]=p->rchild;
		}
		if(front>last){//�ۺ������������Ĺ��� 
			last=rear;
			height++;
			if(b>maxb){
				maxb=b;
			}
			b=0;
		}
	}
	return height*maxb;
}

void printpathx(BTNode *bt,int x)												//�������㵽X����·�� 
{
	int i;
	BTNode *p; 
	TagStack s[Maxsize];
	int top=-1;
	p=bt;
	while(top!=-1||p!=NULL)
	{
		while(p!=NULL&&p->data!=x){
			s[++top].t=p;
			s[top].tag=0;
			p=p->lchild;
		}//������ 
		if(p->data==x){
			for(i=0;i<=top;i++){
				printf("% d",s[i].t->data);
			}
			break; 
		}
		while(top!=-1&&s[top].tag==1) 
		{
			top--;
		}//������������ſɳ�ջ 
		if(top!=-1)
		{
			s[top].tag=1;
			p=(s[top].t)->rchild;//����������������־λ��Ϊ1 
		}
	}
}

void PrintpathRootToX(BTNode *bt,int x)												//�������㵽X����·�� 
{
	int i;
	TagStack s[Maxsize]; 
	int top=-1;
	while(bt!=NULL||top!=-1)
	{
		while(bt!=NULL&&bt->data!=x){
			s[++top].t=bt;
			s[top].tag=0;
			bt=bt->lchild;
		}//������ 
		if(bt!=NULL&&bt->data==x){
			for(i=0;i<=top;i++)
			printf("% d",s[i].t->data);
			break;
		}
		while(top!=-1&&s[top].tag==1)
		top--;
		if(top!=-1){
			s[top].tag=1;//������������1
			bt=s[top].t->rchild;
		}
		else break; 
	} 
}

void PrintPath(BTNode *bt,int x)                                                //������ 
{
	int tag[Maxsize];
	BTNode *p;
	BTNode *stack[Maxsize];
	int top;
	top=0;
	int i;
	p=bt;
	while(p!=NULL)
	{
		tag[top]=0;
		stack[top++]=p;
		p=p->lchild;
	}
	while(top>0)
	{
		p=stack[top-1];
		if(p->data==x){
			for(i=0;i<top;i++)
			printf("% d",stack[i]->data);
			break;
		}
		if(p->rchild==NULL||tag[top-1]==1)
		{
			p=stack[--top];
		}
		else{
			tag[top-1]=1;
			p=p->lchild;
		}
		p=p->rchild;
		while(p!=NULL)
		{
			tag[top]=0;
			stack[top++]=p;
			p=p->lchild;
		}
	}
	
} 

//��������ǵݹ��㷨�����Ҷ��㵽������·�� 
void PrintPathLeaf(BTNode *bt)
{
	int i;
	TagStack s[Maxsize];//��ǽ��ջ��tag=0��ʾ������δ�����ʣ�tag=1��ʾ�������ѱ����� 
	int top=-1;
	while(bt!=NULL||top!=-1)
	{
		while(bt!=NULL)
		{
			s[++top].t=bt;
			s[top].tag=0;
			bt=bt->lchild;
		}//�����ߣ�������˽���ѭ�� 
		if(s[top].t->lchild==NULL&&s[top].t->rchild==NULL&&s[top].tag!=1){
				for(i=0;i<top;i++){
					printf("% d",s[i].t->data);
				}
				printf("\n");
			}
		while(top!=-1&&s[top].tag==1)
		{
			top--;
		} 
		if(top!=-1){ 
			s[top].tag=1;
			bt=s[top].t->rchild;//ת�������� 
		}
	}
}

int Wpl(BTNode *bt)
{
	BTNode *p;
	BTNode *que[Maxsize];
	int front=0,rear=0;
	int last=0;//����ʶ�� 
	int level=0;
	int Wpl=0;
	que[++rear]=bt;
	while(front<rear)
	{
		if(front>=last){
			last=rear;
			level++;
		}
		p=que[++front];
		if(p->lchild==NULL&&p->rchild==NULL){
			Wpl=(level-1)*p->data+Wpl;//Wpl ��Ȩ·�����ȣ�WPL=Ҷ����Ȩֵ*��� 
		}
		if(p->lchild!=NULL){
			que[++rear]=p->lchild;
		}
		if(p->rchild!=NULL){
			que[++rear]=p->rchild;
		}

	}
	return Wpl;
}

int main()
{
	BTNode *bt;
	BTNode *temp;
	BTNode A;
	BTNode B;
	BTNode C;
	BTNode D;
	BTNode E;
	BTNode F;
	BTNode G;
	BTNode H;
	BTNode I;
	BTNode J; 
	bt=&A;
	A.lchild=&B;
	A.rchild=&C;
	B.lchild=&D;
	B.rchild=&E;
	C.lchild=&F;
	C.rchild=&G;
	D.lchild=NULL;
	D.rchild=NULL;
	E.lchild=&H;
	E.rchild=&I;
	F.lchild=NULL;
	F.rchild=NULL;
	G.lchild=NULL;
	G.rchild=&J;
	H.lchild=NULL;
	H.rchild=NULL;
	I.lchild=NULL;
	I.rchild=NULL;
	J.lchild=NULL;
	J.rchild=NULL;
	A.data=1;
	B.data=2;
	C.data=3;
	D.data=4;
	E.data=5;
	F.data=6;
	G.data=7;
	H.data=8;
	I.data=9;
	J.data=10; 
	int Preorder[7]={-1,1,2,3,4,5,6};
	int Midorder[7]={-1,3,2,1,5,4,6};
	int Postorder[7]={-1,3,2,5,6,4,1};
	int l1=1,l2=1,h1=6,h2=6;
	int llen,rlen;
	int i;
	int k;
	int x;
	printf("������������ţ�\n") ;
	printf("1.ǰ�����������\n2.�������������\n3.�������������\n4.��α���������\n5.��������ǵݹ��㷨\n6.��������ǵݹ��㷨\n");
	printf("7.���¶��ϣ����Ҷ����α�������\n8.��������ĸ߶�\n9.�ж��Ƿ�Ϊ��ȫ������\na.ͳ��˫��֧���ĸ���\nb.��������������������\n");
	printf("c.����������е�k������ֵ\nd.ɾ����ΪX������\ne.��������ǵݹ黯\nf.ͳ�ƶ������Ľ�����\ng.ͳ�ƶ�������Ҷ�ӽ����\n");
	printf("h.ͳ�ƶ������ж�Ϊ1�Ľ��\ni.ͳ�ƶ������е�˫��֧���(�ݹ��㷨)\nj.ͳ�ƶ������ĸ߶�\nk.��������Ŀ��\nl.��������ķ�ï�̶�\n");
	printf("m.���ֵΪX�Ľ�����������\nn.�������㵽Ҷ�ӽ���·��\no.��������Ĵ�Ȩ·������\n");
	char opp;
	while(opp!='0'){
		scanf("%c",&opp);
	switch(opp)
	{
		case '1':
			preorder(&A);
			printf("\n");
			break;
	    case '2':
	    	midorder(&A);
	    	printf("\n");
	    	break;
	    case '3':
	    	postorder(&A);
	    	printf("\n");
	    	break;
	    case '4':
	    	levelorder(&A);
	    	printf("\n");
	    	break;
	    case '5':
	    	Nopreorder(&A);
	    	printf("\n");
	    	break;
	    case '6':
	    	Nomidorder(&A);
	    	printf("\n");
	    	break;
	    case '7':
	    	Reverselevel(&A);
	    	printf("\n");
	    	break;
	    		
	    case '8':
	    	Height(&A);
			printf("\n");
			break; 
	    case '9':
	    	Iscomplished(&A);
			printf("\n");
			break;
	    case 'a':
	    	CountNotEmpty(&A);
	    	printf("\n");
	    	break;
	    case 'b':
	    	exchange(&A,temp);
	    	preorder(&A);
	    	printf("\n");
	    	break;
	    case 'c':
	    	printf("������k��ֵ:");
	    	scanf("%d",&k);
	    	Nodek(&A,k);
	    	printf("\n");
	    	break;
	    case 'd':
	    	printf("������X��ֵ:");
	    	scanf("%d",&x);
	    	SearchX(&A,x);
	    	printf("\n");
	    	break;
	    case 'e':
			Nopostorder(&A);
			printf("\n");
			break;
		case 'f':
			printf("������һ����%d�����!",CountNode(&A));
			printf("\n");
			break; 
		case 'g':
			printf("������һ����%d��Ҷ�ӽ��!",CountLeafNode(&A));
			printf("\n");
			break;
		case 'h':
			printf("��������һ����%d����Ϊ1�Ľ��!",CountNode1(&A)); 
			printf("\n");
			break;
		case 'i':
			printf("��������һ����%d��˫��֧���!",CountNode2(&A));
			printf("\n");
			break;
		case 'j':
			printf("�������ĸ߶�Ϊ%d!",CountHeight(&A));
			printf("\n");
			break;
		case 'k':
			printf("�������Ŀ��Ϊ%d!",Width(&A));
			printf("\n");
			break;
		case 'l':
			printf("�������ķ�ï�̶�Ϊ%d!",WidthHeight(&A));
			printf("\n");
			break;
		case 'm':
		    printf("������x��ֵ:");
			scanf("%d",&x);
			PrintpathRootToX(&A,x);
			printf("\n");
			break;
		case 'n':
			printf("����㵽Ҷ�ӽ���·��:\n");
			PrintPathLeaf(&A);
			printf("\n");
			break;
	    case 'o':
	    	printf("�������Ĵ�Ȩ·������Ϊ%d",Wpl(&A));
	    	printf("\n");
	    	break;
	    	exit(0);
	}
}
}

