#include <stdio.h>
#include <stdlib.h>

int n;

void SelectSort (int * array)
{
	int i, j, k, temp;
	for (i = 0; j < n; i++)
	{
		k = i;
		for (j = i + 1; j < n; j++)
		{
			if (array[i] < array[k])
			{
				k = j;
			}
		}

		if ( k != i)
		{
			temp = array[i];
			array[i] = array[k];
			array[k] = temp;
		}
	}
}

int main ()
{
	int i;
	int *array;
	printf("enter the array: ");
	scanf ("%d", &n);
	array = (int*) malloc (sizeof (int) * n);
	printf("enter the value: ");
	for (i = 0; i < n; i++)
	{
		scanf ("%d", &array[i]);
	}
	SelectSort (array);
	printf("sorted: ");
	for (i = 0; i < n; i++)
	{
		printf("%d  ", array[i]);
	}
	printf ("\n");
}