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
	printf("������1��2��3��4ѡ��Ӽ��˳�:\n");
	printf("1����\n");
	printf("2����\n");
	printf("3����\n");
	printf("4����\n");
	printf("������ɺ󣬰��س�����\n");
	while (gets(num),1)
	{	
		if ((isdigit(num[0]) && num[0]> '0'&& num[0]  <'5') && num[1] == '\0')
		{
			switch (num[0])
			{
			case '1':
				//printf("�������������֣��ÿո��������\n");
				//printf("������ɺ󣬰��س�����\n");

				printf("��ӽ����%lf\n", sum_A(1, 2)); break;
			case '2':printf("��������%d\n", sub_B(1, 2)); break;
			case '3':printf("��˽����%lf\n", mul_D(1, 3)); break;
			case '4':printf("��������%d\n", div_D(2, 2)); break;
			default:  break;
			}
		}
		else
		{
			printf("�����������������\n");
		}
	}
	return 0;
}