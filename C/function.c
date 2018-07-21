/*return_type function_name (parameter list)
{
  body of the function
}
*/

#include <stdio.h>

//函数声明
int max (int num1, int num2);//注意分号

int main（）
{
  int a = 100;
  int b = 200;
  int rec;
//调用函数
  ret = max (a,b);

  printf("Max value is : %d\n", ret);
  return 0;
}

//返回两个数中较大的那个数
int max (int num1,int num2){
  int result;

  if (num1 > num2)
    result = num1;
  else
    result = num2;

  return result;
}
