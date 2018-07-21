#include <stdio.h>
int main ()
{
	int x = 0;
	for (;x >= 0; x++){
		printf("x = %d\n", x);;
	}
	x = x - 1;
	printf("x= %d\n", x );
	return 0;
}