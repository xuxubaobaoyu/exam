#include <stdio.h>
#include <stdlib.h>
#include "A.h"
#include "B.h"
#include "D.h"
#include <string.h>

#define N 200
void pri(void);
int main()
{
	char num[N];
	double a, b,d;
	int shu = 0,c=0;
	pri();
	while (gets(num))
	{	
		if ((isdigit(num[0]) && num[0]> '0'&& num[0]  <'5' && num[1] == '\0') || num[0] == '-')//判断输入是否为非法字符
		{
			if (num[0] == '1')//A
			{
				printf("请输入两个数字，用空格隔开输入\n");
				printf("输入范围为-1000000000至1000000000");
				printf("若输入小数精确到后6位\n");
				printf("输入完成后，按回车继续\n");
				scanf("%lf%lf", &a, &b);
				printf("相+结果：%1.7lf\n", sum_A(a, b));
				printf("请再选择加减乘除\n");
			}
			else if (num[0] == '2')//B
			{
				printf("请输入两个数字，用空格隔开输入\n");
				printf("输入范围为-1000000000至1000000000");
				printf("输入完成后，按回车继续\n");
				scanf("%lf%lf", &a, &b);
				printf("相-结果：%.7lf\n", sub_B(a, b));
				printf("请再选择加减乘除\n");
			}
			else if (num[0] == '3')//C
			{
				printf("请输入两个数字，用空格隔开输入\n");
				printf("输入范围为-1000000000至1000000000");
				printf("输入完成后，按回车继续\n");
				scanf("%lf%lf", &a, &b);
				printf("相*结果：%.7lf\n", mul_D(a, b));
				printf("请再选择加减乘除\n");
			}
			else if (num[0] == '4')//D
			{
				printf("请输入两个数字，用空格隔开输入\n");
				printf("输入范围为-1000000000至1000000000");
				printf("输入完成后，按回车继续\n");
				scanf("%lf%lf", &a, &b);
				if (b == 0)
				{
					printf("除数不能为0\n");

				}
				else
				{
					d = div_D(a, b);
					printf("相/结果：%.7lf\n",d);
				}
				printf("请再选择加减乘除\n");
			}
		}
	}
	return 0;
}
void pri(void)
{
	printf("------------------------------------------------\n");
	printf("请输入1、2、3、4选择加减乘除:\n");
	printf("1、加\n");
	printf("2、减\n");
	printf("3、乘\n");
	printf("4、除\n");
	printf("输入完成后，按回车继续\n");
	printf("------------------------------------------------\n");
	return;
}