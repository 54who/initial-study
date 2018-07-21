#include <stdio.h>
int main ()
{
	int x, n = 0;
	scanf ("%d", &x);
	do
	{
		n++;
		x /=10;
	}while (x > 0);
	printf("n = %d\n", n);
}