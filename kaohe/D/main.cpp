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
		if ((isdigit(num[0]) && num[0]> '0'&& num[0]  <'5' && num[1] == '\0') || num[0] == '-')//�ж������Ƿ�Ϊ�Ƿ��ַ�
		{
			if (num[0] == '1')//A
			{
				printf("�������������֣��ÿո��������\n");
				printf("���뷶ΧΪ-1000000000��1000000000");
				printf("������С����ȷ����6λ\n");
				printf("������ɺ󣬰��س�����\n");
				scanf("%lf%lf", &a, &b);
				printf("��+�����%1.7lf\n", sum_A(a, b));
				printf("����ѡ��Ӽ��˳�\n");
			}
			else if (num[0] == '2')//B
			{
				printf("�������������֣��ÿո��������\n");
				printf("���뷶ΧΪ-1000000000��1000000000");
				printf("������ɺ󣬰��س�����\n");
				scanf("%lf%lf", &a, &b);
				printf("��-�����%.7lf\n", sub_B(a, b));
				printf("����ѡ��Ӽ��˳�\n");
			}
			else if (num[0] == '3')//C
			{
				printf("�������������֣��ÿո��������\n");
				printf("���뷶ΧΪ-1000000000��1000000000");
				printf("������ɺ󣬰��س�����\n");
				scanf("%lf%lf", &a, &b);
				printf("��*�����%.7lf\n", mul_D(a, b));
				printf("����ѡ��Ӽ��˳�\n");
			}
			else if (num[0] == '4')//D
			{
				printf("�������������֣��ÿո��������\n");
				printf("���뷶ΧΪ-1000000000��1000000000");
				printf("������ɺ󣬰��س�����\n");
				scanf("%lf%lf", &a, &b);
				if (b == 0)
				{
					printf("��������Ϊ0\n");

				}
				else
				{
					d = div_D(a, b);
					printf("��/�����%.7lf\n",d);
				}
				printf("����ѡ��Ӽ��˳�\n");
			}
		}
	}
	return 0;
}
void pri(void)
{
	printf("------------------------------------------------\n");
	printf("������1��2��3��4ѡ��Ӽ��˳�:\n");
	printf("1����\n");
	printf("2����\n");
	printf("3����\n");
	printf("4����\n");
	printf("������ɺ󣬰��س�����\n");
	printf("------------------------------------------------\n");
	return;
}