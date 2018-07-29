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


Status EnQueue (LinkQueue * Q, QElemType e)
{
	QueuePtr P = (QueuePtr) malloc (sizeof (QNode));
	if (!P)
	{
		return (OVERFLOW);
	}

	P -> data = e;
	P -> next = NULL;
	Q -> rear -> next = P;
	Q -> rear =P;

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


Status CreatGraph (ALGraph * G)
{
	int i, j, k;
	EdgeLink e;
	printf("ding_dian_shu_mu_bian_shu:\n");

	scanf ("%d", &G -> vexNum);
	scanf ("%d", &G -> edgeNum);

	getchar ();
	printf("the value, please:\n");

	for (i = 0; i < G -> vexNum; i++)
	{
		scanf ("%c", &G -> adjList[i].data);
		if (G -> adjList[i].data == '\n')
		{
			i--;
			continue;
		}

		G -> adjList[i].firstEdge = NULL;
	}

	printf("edge (vi,vj):\n");
	for (k =0; k < G -> edgeNum; k++)
	{
		scanf ("%d", &i);
		scanf ("%d", &j);

		e = (EdgeLink) malloc (sizeof (EdgeNode));
		e -> adjvex = j;
		e -> next = G -> adjList[i].firstEdge;
		G -> adjList[i].firstEdge = e;
		e = (EdgeLink) malloc (sizeof (EdgeNode));
		e -> adjvex = i;
		e -> next = G -> adjList[j].firstEdge;
		G -> adjList[j].firstEdge = e;
	}

	return OK;
}

int visited[MAX_NUM];

void DFS (ALGraph G, int i)
{
	EdgeLink P;
	visited[i] = TRUE;
	printf("%c", G.adjList[i].data);
	P = G.adjList[i].firstEdge;
	while (P)
	{
		if (!visited[P -> adjvex])
		{
			DFS (G, P -> adjvex);
		}

		P = P -> next;
	}
}


Status DFSTraverse (ALGraph G)
{
	int i;
	for (i = 0; i < MAX_NUM; i++)
	{
		visited[i] = FALSE;
	}
	for (i = 0; i < G.vexNum; i++)
	{
		if (!visited[i])
		{
			DFS (G, i);
		}
	}

	return OK;
}


Status BFSTraverse (ALGraph G)
{
	int i;
	EdgeLink P;
	LinkQueue Q;
	InitQueue (&Q);

	for (i = 0; i < MAX_NUM; i++)
	{
		visited[i] = FALSE;
	}
	for (i = 0; i < G.vexNum; i++)
	{
		if (!visited[i])
		{
			visited[i] = TRUE;
			printf("%c", G.adjList[i].data);
			EnQueue (&Q, i);
			while (!IsEmpty (Q))
			{
				DeQueue (&Q, &i);
				P = G.adjList[i].firstEdge;
				while (P)
				{
					if (!visited[P -> adjvex])
					{
						visited[P -> adjvex] = TRUE;
						printf("%c", G.adjList[P -> adjvex].data);
						EnQueue (&Q, P -> adjvex);	
					}

					P = P -> next;
				}
			}
		}
	}

	return OK;
}


int main ()
{
	ALGraph G;
	CreatGraph (&G);
	printf("shen_du_you_xian:");
	DFSTraverse (G);
	printf("\nguang_du_you_xian:");
	BFSTraverse (G);
	printf("\n");
}