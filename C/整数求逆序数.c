#include <stdio.h>

int main ()
{
	int num, x;

	printf("请输入逆序的整数:");
	scanf("%d", &num);
	while(num != 0){
		x = num % 10;
		num = num / 10;
		printf("%d", x);
	}
	
	// int x, digit, ret=0;

	// printf("请输入逆序的整数：");
	// scanf ("%d", &x);

	// while( x>0 ){
	// 	digit = x % 10;
	// 	ret	= ret * 10 + digit;
	// 	x /= 10;
	// }

	// printf("逆序数为:%d\n", ret);

	return 0;

}