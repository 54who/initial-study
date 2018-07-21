#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	srand (time(0));
	int num = rand() % 100 + 1;
	int count = 0;
	int a = 0;
	printf("数字（1-100）准备好了！\n");
	do {
		printf("猜一猜这个1-100之间的数\n");
		scanf ("%d", &a);
		count++;
		if (a > num)
		{
			printf("大了\n");
		}else if (a < num){
			printf("小了\n");
		}
	}while (a != num);

	printf("你用了%d次猜对了答案\n", count);
	return 0;
}