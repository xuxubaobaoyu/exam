#include <stdio.h>
#include <stdlib.h>
#include "A.h"
#include "B.h"
#include "D.h"
#include <string.h>

#define N 200
int main()
{
	char num[N];
	printf("请输入1、2、3、4选择加减乘除:\n");
	printf("1、加\n");
	printf("2、减\n");
	printf("3、乘\n");
	printf("4、除\n");
	printf("输入完成后，按回车继续\n");
	while (gets(num),1)
	{	
		if ((isdigit(num[0]) && num[0]> '0'&& num[0]  <'5') && num[1] == '\0')
		{
			switch (num[0])
			{
			case '1':
				//printf("请输入两个数字，用空格隔开输入\n");
				//printf("输入完成后，按回车继续\n");

				printf("相加结果：%lf\n", sum_A(1, 2)); break;
			case '2':printf("相减结果：%d\n", sub_B(1, 2)); break;
			case '3':printf("相乘结果：%lf\n", mul_D(1, 3)); break;
			case '4':printf("相除结果：%d\n", div_D(2, 2)); break;
			default:  break;
			}
		}
		else
		{
			printf("输入错误，请重新输入\n");
		}
	}
	return 0;
}