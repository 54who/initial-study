#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define OVERFLOW -2
#define OK 1
#define ERROR 0


typedef int Stautus;
typedef int TelemType;

typedef struct BiTree
{
	TelemType data;
	struct BiTree *lchild, *rchild;
} BiNode, *BiTree;


Stautus CreatBiTree (BiTree * T)
{
	TelemType e;
	scanf ("%d", &e);

	if (e == 0)
	{
		*T = NULL;
	}
	else
	{
		*T = (BiTree) malloc (sizeof (BiTree));
		if (!T)
		{
			exit (OVERFLOW);
		}

		(*T) -> data = e;

		CreatBiTree (&(*T) -> lchild);
		CreatBiTree (&(*T) -> rchild);
	}

	return OK;
}


void visit (TelemType e)
{
	printf("%d", e);
}

Stautus PreOrderTraverse (BiTree T, void (*visit)(TelemType))
{
	if (T)
	{
		visit (T -> data);
		PreOrderTraverse (T -> lchild, visit);
		PreOrderTraverse (T -> rchild, visit);
	}
}


Stautus  InOrderTraverse (BiTree T, void (*visit)(TelemType))
{
	if (T)
	{
		InOrderTraverse (T -> lchild, visit);
		visit (T -> data);
		InOrderTraverse (T -> rchild, visit);
	}
}


Stautus PostOrderTraverse (BiTree T, void (*visit)(TelemType))
{
	if (T)
	{
		PostOrderTraverse (T -> lchild, visit);
		PostOrderTraverse (T -> rchild, visit);
		visit (T -> data);
	}
}


int main ()
{
	BiTree T;
	printf ("creat the tree, enter 0 to NULL tree\n");
	CreatBiTree (&T);
	
	printf("xian_xu_pai_lie\n");
	PreOrderTraverse (T, *visit);

	printf("\nzhong_xu_pai_lie\n");
	InOrderTraverse (T, *visit);

	printf("\nhou_xu_pai_lie\n");
	PostOrderTraverse (T, *visit);

	printf("\n");

	return 0;

}