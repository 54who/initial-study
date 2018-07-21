#include <stdio.h>
int main ()
{
	int num, sum = 0, count = 0;
	
	/*do_while 实现*/
	// do{
	// 	printf("输入一个整数(以-1结束):");
	// 	scanf("%d", &num);
	// 	if (num != -1)
	// 	{
	// 		sum += num;
	// 		count++;
	// 		// printf("sum=%d, count=%d\n", sum, count);

	// 	}
	// }
	// while(num != -1);
	 
	 
	/*while实现*/
	 printf("输入一个整数(以-1结束):");
	 scanf("%d", &num);
	 while (num != -1)
	 {
	 	sum += num;
	 	count++;
	 	printf("输入一个整数(以-1结束):");
	 	scanf("%d", &num);
	 	printf("sum= %d, count= %d\n", sum, count);
	 }

	printf("平均值为:%f\n", 1.0 * sum / count);

	return 0;
}

