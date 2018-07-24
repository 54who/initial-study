#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -2

typedef int ElemType;
typedef int Status;

/*
 * store structure
*/

 typedef struct LNode
 {
 	ElemType data;
 	struct LNode * next;
 }LNode, * LinkList;


 /*
  * initialize List
  */

  void InitList (LinkList * L)
  {
  	*L = (LinkList) malloc (sizeof (LNode));

  	if (!L)
  	{
  		exit (OVERFLOW);
  	}

  	(*L) -> next = NULL;
  }



/*
 * destroy LIst
 */

 void DestroyList (LinkList * L)
 {
 	LinkList temp;
 	while (*L)
 	{
 		temp = (*L) -> next;
 		free (*L);
 		*L = temp;
 	}
 }


 /*
  * clear List
  */

  void ClearList (LinkList L)
  {
  	LinkList p = L -> next;
  	L -> next = NULL;
  	DestroyList(&p);
  }

  /*
   * determine the linglist whether is empty
   */

   Status isEmpty (LinkList L)
   {
   	if (L -> next)
   	{
   		return FALSE;
   	}
   	else 
   	{
   		return TRUE;
   	}
   }


   /*
    * get length
    */

int  GetLength (LinkList L)
{
	int i = 0;
	LinkList p = L -> next;
	while (p)
	{
		i++;
		p = p -> next;
	}

	return i;
}


/*
 * get element by location
 */

 Status GetElem (LinkList L, int i, ElemType * e)
{
 	int j = 1;
 	LinkList p = L -> next;
 	while (p && j < i)
 	{
 		j++;
 		p = p -> next;
 	}

 	if (!p || j > i)
 	{
 		return ERROR;
 	}
 	*e = p -> data;

 	return OK;
 }


 /*
  * compare 2 element whether is equal
  */

  Status compare (ElemType e1, ElemType e2)
  {
  	if (e1 == e2)
  	{
  		return 0;
  	}
  	else if (e1 < e2)
  	{
  		return -1;
  	}
  	else
  	{
  		return 1;
  	}
  }


  /* 
   * find the element's location
   */

   int FindElem (LinkList L, ElemType e, Status (* compare)(ElemType, ElemType))
   {
   	int i = 0;
   	LinkList p = L -> next;
   	while (p)
   	{
   		i++;
   		if (!compare (p -> data, e))
   		{
   			return i;
   		}

   		p = p -> next;
   	}

   	return 0;
   }

   /*
    * get previous element
    */

    Status PreElem (LinkList L, ElemType cur_e, ElemType * pre_e)
    {
    	LinkList q, p = L -> next;
    	while (p -> next)
    	{
    		q = p -> next;
    		if (q -> data == cur_e)
    		{
    			*pre_e = p -> data;

    			return OK;
    		}
    		p = q;
    	}

    	return ERROR;
    }

    /*
     * get next element
     */

     Status NextElem (LinkList L, ElemType cur_e, ElemType * next_e)
     {
     	LinkList p = L -> next;
     	while (p -> next)
     	{
     		if (p -> data == cur_e)
     		{
     			*next_e = p -> next -> data;
     			return OK;
     		}

     		p = p -> next;
     	}

     	return ERROR;
     }


     /* 
      * insert element
      */

      Status InsertElem (LinkList L, int i, ElemType e)
      {
      	int j = 0;
      	LinkList s, p = L;
      	while (p && j < i -1)
      	{
      		j++;
      		p = p -> next;
      	}

      	if (!p || j > i - 1)
      	{
      		return ERROR;
      	}

      	s = (LinkList) malloc (sizeof (LNode));
      	s -> data = e;
      	s -> next = p -> next;
      	p -> next = s;

      	return OK;
      }

      /*
       * delete element and return the value
       */
       Status DeleteElem (LinkList L, int i, ElemType * e)
   {
   		int j = 0;
   		LinkList q, p = L;
   		while (p -> next && j < i - 1)
   		{
   			j++;
   			p = p -> next;
   		}

   		if (!p -> next || j > i - 1)
   		{
   			return ERROR;
   		}
   		q = p -> next;
   		p -> next = q -> next;
   		*e = q -> data;
   		free (q);

   		return OK;
   }


   /*
    * visit element
    */

    void visit (ElemType e)
    {
    	printf("%d\n", e);
    }

    /*
     * traverse list
     */

     void TraverseList (LinkList L, void (* visit)(ElemType))
     {
     	LinkList p = L -> next;
     	while (p)
     	{
     		visit(p -> data);
     		p = p -> next;
     	}
     }

     int main ()
     {
     	LinkList L;
     	InitList (&L);
     	ElemType e;
     	int i;
     	if (L)
     	{
     		printf(" init success\n");
     	}

     	if (isEmpty (L))
     	{
     		printf("list is empty\n");
     	}

     	for (i = 0; i < 10; i++)
     	{
     		InsertElem (L, i + 1, i);
     	}

     	if (GetElem (L, 1, &e))
     	{
     		printf("the first element is %d\n", e);
     	}

     	printf(" length is %d\n", GetLength(L));

     	printf(" The 5 at %d\n", FindElem(L, 5, *compare));

     	PreElem (L, 6, &e);
     	printf(" The 6's previous element is %d\n", e);

     	DeleteElem (L, 1, &e);
     	printf(" delete first element is %d\n", e);

     	printf(" list:");
     	TraverseList(L, visit);

     	DestroyList (&L);
     	if (!L)
     	{
     		printf(" \ndestory success\n");
     	}
     }