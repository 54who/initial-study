#include <stdio.h>
 
int cal_sum(int a, int b);
 
int main(void)
{
	int result[10];
	result[0] =  cal_sum(1, 10);
	result[1] = cal_sum(1, 100);
	printf("cal(1, 10) = %d\n", result[0]);
	printf("cal(1, 100) = %d", result[1]);
 
	return 0;
}
 
int cal_sum(int a, int b)
{
	int i, sum = 0;
	for (i = a; i <= b; i++)
	{
		sum = sum + i;
	}
	return sum;
}