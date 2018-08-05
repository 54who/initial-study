#include <stdio.h>
#include <stdlib.h>

int n;

void HeapAdjust (int * array, int s, int m)
{
	int i;
	array[0] = array[s];
	for (i = s * 2; i <= m; i *= 2)
	{
		if (i < m && array[i] < array[i + 1])
		{
			i++;
		}
		if (!(array[0] < array[i]))
		{
			break;
		}
		array[s] = array[i];
		s = i;
	}

	array[s] = array[0];
}


void HeapSort (int * array)
{
	int i;
	for (i = n / 2; i > 0; i--)
	{
		HeapAdjust(array, i, n);
	}
	for (i = n; i > 1; i--)
	{
		array[0] = array[1];
		array[1] = array[i];
		array[i] = array[0];
		HeapAdjust (array, 1, i - 1);
	}
}

int main ()
{
	int i;
	int *array;
	printf("enter the array: ");
	scanf("%d", &n);
	array = (int*) malloc (sizeof (int) * (n + 1));
	printf("enter the value: ");
	for (i = 1; i <= n; i++)
	{
		scanf ("%d", &array[i]);
	}
	HeapSort (array);
	printf("sorted: ");
	for (i = 1; i <= n; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
}