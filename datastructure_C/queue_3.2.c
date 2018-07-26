#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -2

typedef int QElemType;
typedef int Status;



typedef struct QNode
{
	QElemType data;
	struct QNode *next;
}QNode, *QueuePtr;

typedef struct
{
	QueuePtr front;
	QueuePtr rear;
}LinkQueue;


Status InitQueue (LinkQueue * Q)
{
	Q -> front = Q -> rear = (QueuePtr) malloc (sizeof (QNode));
	if (!Q -> front)
	{
		exit (OVERFLOW);
	} 

	Q -> front -> next = NULL;

	return OK;
}



Status DestoryQueue (LinkQueue * Q)
{
	DestoryQueue (Q);
	InitQueue (Q);

	return OK;
}



Status IsEmpty (LinkQueue Q)
{
	if (Q.front -> next == NULL)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}



int GetLength (LinkQueue Q)
{
	int i = 0;
	QueuePtr P = Q.front;
	while (Q.rear != P)
	{
		i++;
		P = P -> next;
	}

	return i;
}




Status GetHead (LinkQueue Q, QElemType * e)
{
	QueuePtr P;
	if (Q.front == Q.rear)
	{
		return ERROR;
	}

	P = Q.front -> next;
	*e = P -> data;

	return OK;
}




Status EnQueue (LinkQueue * Q, QElemType e)
{
	QueuePtr P = (QueuePtr) malloc (sizeof (QNode));
	if (!P)
	{
		exit (OVERFLOW);
	}

	P -> data = e;
	P -> next = NULL;
	Q -> rear -> next = P;
	Q -> rear = P;

	return OK;
}


Status DeQueue (LinkQueue * Q, QElemType * e)
{
	QueuePtr P;
	if (Q -> front == Q -> rear)
	{
		return ERROR;
	}

	P = Q -> front -> next;
	*e = P -> data;
	Q -> front -> next = P -> next;

	if (Q -> rear == P)
	{
		Q -> rear = Q -> front;
	}

	free (P);

	return OK;
}



void visit (QElemType e)
{
	printf("%d", e);
}



Status TraverseQueue (LinkQueue Q, void (*visit)(QElemType))
{
	QueuePtr P = Q.front -> next;
	while (P)
	{
		visit (P -> data);
		P = P -> next;
	}

	return OK;
}



int main ()
{
	LinkQueue Q;
	if (InitQueue (&Q))
	{
		QElemType e;
		int i;

		printf("init_success\n");

		if (IsEmpty (Q))
		{
			printf("queue is empty\n");
		}

		for (i = 0; i < 10; i++)
		{
			EnQueue (&Q, i);
		}


		GetHead (Q, &e);
		printf("first element is %d\n", e);

		printf("length is %d\n", GetLength (Q));

		DeQueue (&Q, &e);
		printf("delete element is %d\n", e);

		TraverseQueue (Q, *visit);

		if (DestoryQueue (&Q))
		{
			printf("\ndestory_success\n");
		}
	}
}