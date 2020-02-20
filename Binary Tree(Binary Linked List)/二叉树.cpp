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
	if(bt==NULL) return;                            //递归出口结点节点为空时返回 
	printf("% d",bt->data);
	preorder(bt->lchild);                            //调用系统栈，入栈反序，左子树在前 
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

void Nopreorder(BTNode *bt)//先序遍历非递归算法 
{
	BTNode *stack[Maxsize];
	int top=-1;
	BTNode *p;
	stack[++top]=bt;
	while(top!=-1)
	{
		p=stack[top--];
		printf("% d",p->data);
		if(p->rchild!=NULL)//根左右，所以右孩子先入栈 
		stack[++top]=p->rchild;
		if(p->lchild!=NULL)
		stack[++top]=p->lchild;
	}
}

void levelorder(BTNode *bt)//层次遍历算法 
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
	while(p!=NULL||top!=-1)//注意循环条件要加上 P！=NULL 
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

//输出层次遍历的逆序列
//即将层次遍历的结果压入一个栈中，然后出栈 
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
		p=que[++front];//层次遍历队列中元素出队 
		stack[++top]=p;// 出队的元素进栈 
		if(p->lchild!=NULL)
		{
			que[++rear]=p->lchild;
		}
		if(p->rchild!=NULL)
		{
			que[++rear]=p->rchild;
		}
	}
	while(top!=-1)//栈中的元素全部出栈 
	{
		printf("% d",stack[top--]->data);
	}
}

//求二叉树的深度
//用层次遍历的方法，使用last变量与队尾指针front来实现层次的记录 
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
		if(p==last){//当工作指针指向last结点时，该层已经全部遍历，last指向下一层最后一个结点 
			last=que[rear];//下一层的最后一个结点已经入队，所以last直接指向队尾 
			count++;
		}
	}
	printf("二叉树一共有%d层",count);
}

//判断二叉树是否为完全二叉树
//用层次遍历的方法将所有的结点及其空或非空的孩子结点入队
//遍历该队列，当队列在某空结点之后不再出现非空结点，则为完全二叉树 
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
	while(front2<rear)//对列中已按完全二叉树的形式保存整棵树 
	{
		p=que[++front2];
		if(p!=NULL){
			printf("不是完全二叉树！\n");
			return 0;
		}
	}
}

void CountNotEmpty(BTNode *bt)                                                  //待调试 
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
	printf("一共有%d个双分支结点!\n",count);
}

void exchange(BTNode *bt,BTNode *temp)                                                       //待调试 
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
		printf("第%d个结点是%d!\n",k,p->data);
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
		printf("删除完成！\n");
		return;
	}
	BTNode *stack[Maxsize];
	int top=-1;
	BTNode *p;
	stack[++top]=bt;
	while(p!=NULL)                                                              //关键步骤先序遍历的非递归化 
	{
		p=stack[top--];
		if(p->rchild!=NULL)
		{
			if(p->rchild->data==x){
				DeleteTreeX(p->rchild);
				p->rchild=NULL;
				printf("删除完成！\n");
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
				printf("删除完成！\n");
				preorder(bt);
				return;
			}
			else{
				stack[++top]=p->lchild;
			}
		}
	}
	
}

void Nopostorder(BTNode *bt)												//输出根结点到X结点的路径 
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
		}//向左走 
		while(top!=-1&&s[top].tag==1) 
		{
			printf("% d",s[top].t->data);
			top--;
		}//右子树访问完才可出栈 
		if(top!=-1)
		{
			s[top].tag=1;
			p=s[top].t->rchild;//访问右子树并将标志位置为1 
		}
	}
}
																				//1.统计二叉树中的结点数 DONE!
																				//2.统计二叉树中的叶子结点数 DONE!
																				//3.统计二叉树中度为1的结点数 DONE!
																				//4.统计二叉树中度为2的结点 DONE!
																				//5.统计二叉树的高度 DONE!
																				//6.交换左右子树 
																				//7.设计算法复制二叉树
																				//8.使用顺序存储存储二叉树，设计非递归前序遍历
																				//9.顺序存储中序遍历
//统计叶结点的个数 
int CountNode(BTNode *bt)
{
	if(bt==NULL) return 0;
	return CountNode(bt->lchild)+CountNode(bt->rchild)+1;//树的结点个数=左子树的结点个数+右子树的结点个数 
}

//统计叶结点的个数 
int CountLeafNode(BTNode *bt)
{
	if(bt==NULL) return 0;//空树无叶结点 
	if(bt->lchild==NULL&&bt->rchild==NULL) return 1;//二叉树无孩子，仅有一个叶结点 
	if(bt->lchild!=NULL&&bt->rchild!=NULL){
		return CountLeafNode(bt->lchild)+CountLeafNode(bt->rchild);//二叉树有左右孩子， 
	}                                                             //叶结点个数=左子树叶结点+右子树叶结点 
}

//统计度为一的结点个数 
int CountNode1(BTNode *bt)
{
	if(bt==NULL) return 0;//空树无度为一的结点 
	if(bt->lchild==NULL&&bt->rchild==NULL) return 0;//仅有根结点的树没有度为一的结点 
	if(bt->lchild!=NULL&&bt->rchild!=NULL)//有左右孩子的树中N1=左子树N1+右子树N1 
		return CountNode1(bt->lchild)+CountNode1(bt->rchild);
	else
		return CountNode1(bt->lchild)+CountNode1(bt->rchild)+1;//单子树的树N1=根结点+左子树N1+右子树N1 
}                                                              //左N1或右N1中有一个为0 


//统计二叉树中度为二的结点 
int CountNode2(BTNode *bt)
{
	if(bt==NULL) return 0;//若树为空，返回0个度为二的结点 
	if(bt->lchild!=NULL&&bt->rchild!=NULL) 
	return CountNode2(bt->lchild)+CountNode2(bt->rchild)+1;
	//度为二的结点个数=左子树中度为二的结点个数+右子树中度为二的结点个数+1个根结点 
}
//递归统计树的高度 
int CountHeight(BTNode *bt)
{
	if(bt==NULL) return 0;//若树为空，高度为0 
	return (CountHeight(bt->lchild)>CountHeight(bt->rchild)?CountHeight(bt->lchild):CountHeight(bt->rchild))+1;
	//树的高度=左子树和右子树较高者的高度+1 
}

//层次遍历求树的最大宽度 
int Width(BTNode *bt)
{
	BTNode *p;
	int last;//last指针用来判断一层是否遍历完毕 
	BTNode *que[Maxsize];//层次遍历队列 
	int rear=0,front=0;
	int b=0,maxb=0; 
	que[++rear]=bt;
	last=0;
	while(front<rear)//队列空时循环结束 
	{
		p=que[++front];//结点出队 
		if(p->lchild!=NULL){
			que[++rear]=p->lchild;
		}
		if(p->rchild!=NULL){
			que[++rear]=p->rchild;
		}
		b++;
		if(front>last)//front指针指向一层的最后一个结点 
		{
			last=rear;//last指向下一层最后一个结点 
			if(b>maxb){//如果该层结点数大于最大结点数，更新最大结点数 
				maxb=b;
			}
			b=0;
		}
	}
	return maxb;
}

//层次遍历求数的繁茂程度 
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
		if(front>last){//综合上两个函数的功能 
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

void printpathx(BTNode *bt,int x)												//输出根结点到X结点的路径 
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
		}//向左走 
		if(p->data==x){
			for(i=0;i<=top;i++){
				printf("% d",s[i].t->data);
			}
			break; 
		}
		while(top!=-1&&s[top].tag==1) 
		{
			top--;
		}//右子树访问完才可出栈 
		if(top!=-1)
		{
			s[top].tag=1;
			p=(s[top].t)->rchild;//访问右子树并将标志位置为1 
		}
	}
}

void PrintpathRootToX(BTNode *bt,int x)												//输出根结点到X结点的路径 
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
		}//向左走 
		if(bt!=NULL&&bt->data==x){
			for(i=0;i<=top;i++)
			printf("% d",s[i].t->data);
			break;
		}
		while(top!=-1&&s[top].tag==1)
		top--;
		if(top!=-1){
			s[top].tag=1;//左子树走完置1
			bt=s[top].t->rchild;
		}
		else break; 
	} 
}

void PrintPath(BTNode *bt,int x)                                                //待调试 
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

//后序遍历非递归算法，输出叶结点到根结点的路径 
void PrintPathLeaf(BTNode *bt)
{
	int i;
	TagStack s[Maxsize];//标记结点栈，tag=0表示左子树未被访问，tag=1表示左子树已被访问 
	int top=-1;
	while(bt!=NULL||top!=-1)
	{
		while(bt!=NULL)
		{
			s[++top].t=bt;
			s[top].tag=0;
			bt=bt->lchild;
		}//向左走，到最左端结束循环 
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
			bt=s[top].t->rchild;//转向右子树 
		}
	}
}

int Wpl(BTNode *bt)
{
	BTNode *p;
	BTNode *que[Maxsize];
	int front=0,rear=0;
	int last=0;//层数识别 
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
			Wpl=(level-1)*p->data+Wpl;//Wpl 带权路径长度，WPL=叶结点的权值*深度 
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
	printf("请输入操作代号：\n") ;
	printf("1.前序遍历二叉树\n2.中序遍历二叉树\n3.后序遍历二叉树\n4.层次遍历二叉树\n5.先序遍历非递归算法\n6.中序遍历非递归算法\n");
	printf("7.自下而上，自右而左层次遍历序列\n8.求二叉树的高度\n9.判断是否为完全二叉树\na.统计双分支结点的个数\nb.交换二叉树的左右子树\n");
	printf("c.求先序遍历中第k个结点的值\nd.删除根为X的子树\ne.后序遍历非递归化\nf.统计二叉树的结点个数\ng.统计二叉树的叶子结点数\n");
	printf("h.统计二叉树中度为1的结点\ni.统计二叉树中的双分支结点(递归算法)\nj.统计二叉树的高度\nk.求二叉树的宽度\nl.求二叉树的繁茂程度\n");
	printf("m.输出值为X的结点的所有祖先\nn.输出根结点到叶子结点的路径\no.求二叉树的带权路径长度\n");
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
	    	printf("请输入k的值:");
	    	scanf("%d",&k);
	    	Nodek(&A,k);
	    	printf("\n");
	    	break;
	    case 'd':
	    	printf("请输入X的值:");
	    	scanf("%d",&x);
	    	SearchX(&A,x);
	    	printf("\n");
	    	break;
	    case 'e':
			Nopostorder(&A);
			printf("\n");
			break;
		case 'f':
			printf("二叉树一共有%d个结点!",CountNode(&A));
			printf("\n");
			break; 
		case 'g':
			printf("二叉树一共有%d个叶子结点!",CountLeafNode(&A));
			printf("\n");
			break;
		case 'h':
			printf("二叉树中一共有%d个度为1的结点!",CountNode1(&A)); 
			printf("\n");
			break;
		case 'i':
			printf("二叉树中一共有%d个双分支结点!",CountNode2(&A));
			printf("\n");
			break;
		case 'j':
			printf("二叉树的高度为%d!",CountHeight(&A));
			printf("\n");
			break;
		case 'k':
			printf("二叉树的宽度为%d!",Width(&A));
			printf("\n");
			break;
		case 'l':
			printf("二叉树的繁茂程度为%d!",WidthHeight(&A));
			printf("\n");
			break;
		case 'm':
		    printf("请输入x的值:");
			scanf("%d",&x);
			PrintpathRootToX(&A,x);
			printf("\n");
			break;
		case 'n':
			printf("根结点到叶子结点的路径:\n");
			PrintPathLeaf(&A);
			printf("\n");
			break;
	    case 'o':
	    	printf("二叉树的带权路径长度为%d",Wpl(&A));
	    	printf("\n");
	    	break;
	    	exit(0);
	}
}
}

