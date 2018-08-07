#include <stdio.h>
#include <stdlib.h>

int n;
int bit_num;

int GetNumInPos (int num, int pos)
{
	int i, temp = 1;
	for (i = 0; i < pos - 1; i++)
	{
		temp *= 10;
	}
	return (num / temp) % 10;
}

void RadixSort (int * array)
{
	int radix = 10;
	int *count, *bucket, i, j, k;
	count = (int*) malloc (sizeof (int) * radix);
	bucket = (int*) malloc (sizeof (int) * n);

	for (k = 1; k <= bit_num; k++)
	{
		for (i = 0; i < radix; i++)
		{
			count[i] = 0;
		}
		
		for (i = 0; i < n; i++)
		{
			count[GetNumInPos (array[i], k)]++;
		}

		for (i = 1; i < radix; i++)
		{
			count[i] = count[i] + count[i - 1];
		}

		for (i = n - 1; i >= 0; i--)
		{
			j = GetNumInPos (array[i], k);
			bucket[count[j] - 1] = array[i];
			count[j]--;
		}

		for (i = 0, j = 0; i < n; i++, j++)
		{
			array[i] = bucket[j];
		}
	}
}

int main ()
{
	int i;
	int *array;
	printf("enter the biggest number: ");
	scanf ("%d", &bit_num);

	printf("enter the array: ");
	scanf("%d", &n);

	array = (int*) malloc (sizeof (int) * n);
	printf("enter the number: ");
	for (i = 0; i < n; i++)
	{
		scanf ("%d", &array[i]);
	}

	RadixSort (array);
	printf("sorted: ");
	for (i = 0; i < n; i++)
	{
		printf("%d ", array[i]);
	}

	printf("\n");
}