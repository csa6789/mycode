
#include <stdio.h>
#include <stdlib.h>

#define Length 15

typedef struct d{
	int data;
	struct d *left;
	struct d *right;
}tree;

tree *CreateTree(int len,int &n)
{
	if(n>len)
	{
		return NULL;
	}
	tree *s=(tree *)malloc(sizeof(tree));
	s->data=n;
	if(s->data!=Length)
	{
		printf("%d\t",n);	
	}
	s->left=CreateTree(len,++n);
	s->right=CreateTree(len,++n);
	return s;
}

void LatTree(tree *t)
{
	if(t!=NULL)
	{
		tree *stack1[Length];
		tree *stack2[Length];
		int top1=0,top2=0;
		while(top1!=0||t!=NULL)
		{
			while(t!=NULL)
			{
				stack1[top1++]=t;
				stack2[top2++]=t;
				t=t->right;
			}
			if(top1!=0)
			{
				t=stack1[--top1];
				t=t->left;
			}
		}
		while(top2!=0)
		{
			printf("%d\t",stack2[--top2]->data);
		}
	}else 
	{
		return;
	}	
}

int main()
{
	int n=1;
	tree *t=CreateTree(Length,n);
	LatTree(t);
	return 0;
}