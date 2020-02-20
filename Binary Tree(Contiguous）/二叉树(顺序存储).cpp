#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define Maxsize 100

void preorder(int bt[],int root,int n)
{
	if(bt[root]==0) return;
	printf("% d",bt[root]);
	if(2*root<n) preorder(bt,2*root,n);
	if(2*root+1<n) preorder(bt,2*root+1,n);
}

void Nopreorder(int bt[],int n)
{
	int p=1;
	int stack[Maxsize]; int top=0;
	stack[++top]=1;
	while(top!=0)
	{
		p=stack[top--];
		printf("% d",bt[p]);
		if(bt[2*p+1]!=0&&2*p+1<n){
			stack[++top]=2*p+1;
		}
		if(bt[2*p]!=0&&2*p<n){
			stack[++top]=2*p;
		}
	}
}



int main()
{                //1 2 3 4 5
	int bt[Maxsize]={16,1,2,3,4,5,6,7,0,0,8,9,0,0,0,10};
	int n;
	n=bt[0];
	int root=1;
    char opp;
    printf("请输入操作序号:\n");
    printf("1.先序遍历非递归算法.\n2.先序遍历非递归算法\n");
	while(opp!='0')
	{
		scanf("%c",&opp);
	switch(opp)
	{
		case '1':
			preorder(bt,root,n);
			printf("\n");
			break;
	    case '2':
	    	Nopreorder(bt,n);
	    	printf("\n");
	    	break;
	    case '3':
	    	printf("\n");
	    	break;
	    case '4':
	    	printf("\n");
	    	break;
	    case '5':
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
	    
