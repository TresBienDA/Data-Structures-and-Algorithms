#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

void Insertsort(int A[],int n)
{
	int temp;
	int i,j;
	for(i=1;i<n;i++)
	{
		temp=A[i];
		j=i-1;
		while(j>=0&&temp<A[j])
		{
			A[j+1]=A[j];
			j--;
		}
		A[j+1]=temp;                                                            //�����j+1���׺��� 
	}
	printf("��������");
	for(i=0;i<n;i++)
	{
		printf("% d",A[i]);
	} 
}

void Popsort(int A[],int n)
{
	int i,j;
	int temp;
	int tag;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
		if(A[j+1]<A[j])
		{
			temp=A[j+1];
			A[j+1]=A[j];
			A[j]=temp;
		}
		}
	}
	printf("����Ľ����"); 
	for(i=0;i<n;i++)
	{
		printf("% d",A[i]);
	}
}

void Doublepopsort(int A[],int n)
{
	int i;
	int temp;
	int low=0;//ð���½� 
	int high=n-1;//ð���Ͻ�
	int change=0;
	while(low<high&&change==0)
	{
		change=0;
		for(i=low;i<high;i++)
		{
			if(A[i]>A[i+1]){
				temp=A[i];
				A[i+1]=A[i];
				A[i]=temp;
				change=1;
			}
		}
		high--;
		for(i=high;i>low;i--)
		{
			if(A[i-1]>A[i]){
				temp=A[i];
				A[i]=A[i-1];
				A[i-1]=temp;
				change=1;
			}
		}
		low++;
	}
	printf("˫��ð����������:");
	for(i=0;i<n;i++)
	{
		printf("% d",A[i]);
	}
}

void Countsort(int B[],int C[],int n)
{
	int i,j;
	int count=0;
	for(i=0;i<n;i++)
	{
		count=0;
		for(j=0;j<n;j++)
		{
			if(B[i]>B[j])
			{
				count++;
			}
		}
		C[count]=B[i];
	}
	printf("�����������У�");
	for(i=0;i<n;i++)
	{
		printf("% d",C[i]);
	}
}

void Quicksort(int A[],int low,int high)
{
	int temp;
	int i=low,j=high;
	if(low>=high) return;
	temp=A[i];
	while(i<j)
	{
		while(i<j&&A[j]>=temp) j--;
		if(i<j){
			A[i]=A[j];
			i++;
		}
		while(i<j&&A[i]<temp) i++;
		if(i<j){
			A[j]=A[i];
			j--;
		}
	}
	A[i]=temp;
	Quicksort(A,low,i-1);
	Quicksort(A,i+1,high);
}

void Noquicksort(int A[],int low,int high)
{
	int temp;
	int i=low,j=high;
	temp=A[i];
	while(i<j)
	{
		while(i<j&&A[j]>=temp) j--;
		if(i<j)
		{
			A[i]=A[j];
			i++;
	}
		while(i<j&&A[i]<=temp) i++;
		if(i<j)
		{
			A[j]=A[i];
			j--;
		}
	}
	A[i]=temp;
}

int main()
{
	char opp; 
	int i=0;
	int A[8]={49,38,65,97,76,13,27,49};
	int B[8]={49,38,65,97,76,13,27,48};
	int C[8];
	int n=8;
	printf("�����������ţ�\n");
	printf("1.ֱ�Ӳ�������\n2.ð������\n3.��������\n4.˫��ð������\n5.��������\n6.һ�˿�������\n");
	while(opp!='0')
	{
		scanf("%c",&opp);
	switch(opp)
	{
		case '1':
			Insertsort(A,n);
			printf("\n");
			break;
	    case '2':
	    	Popsort(A,n);
	    	printf("\n");
	    	break;
	    case '3':
	    	Quicksort(A,0,7);
	    	printf("����Ľ����"); 
	    	for(i=0;i<n;i++){
	    		printf("% d",A[i]);
	    	}
	    	printf("\n");
	    	break;
	    case '4':
	    	Doublepopsort(A,n);
	    	printf("\n");
	    	break;
	    case '5':
	    	Countsort(B,C,n);
	    	printf("\n");
	    	break;
	    case '6':
	    	Noquicksort(A,0,7);
	    	printf("һ�˿�������Ľ����");
	    	for(i=0;i<n;i++)
			{
				printf("% d",A[i]);
			} 
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
