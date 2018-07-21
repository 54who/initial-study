#include <stdio.h>
int main ()
{
	int x, n = 0;
	scanf ("%d", &x);

	n++;
	x /= 10;   //输入0依然可以判断


	while (x > 0)
	{
		printf("hr\n");      //循环起点
		n++;
		x/= 10;
		printf("n = %d, x = %d\n", n, x);  //手动debug
	}
	printf("n = %d\n", x, n);
	return 0;
}