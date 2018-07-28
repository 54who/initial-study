#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define MAX_NUM 20


typedef int Status;
typedef int QElemType;
typedef char VexType;


typedef struct EdgeNode
{
	int adjvex;
	struct EdgeNode *next;
}EdgeNode, *EdgeLink;

typedef struct VexNode
{
	VexType data;
	EdgeNode *firstEdge;
}VexNode, AdjList[MAX_NUM];

typedef struct{
	AdjList adjList;
	int vexNum, edgeNum;
}ALGraph;


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

	Q ->  front -> next = NULL;

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