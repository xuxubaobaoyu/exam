#include <stdio.h>
#include <stdlib.h>
#include "A.h"
#include "B.h"
#include "D.h"


int main()
{
	printf("%d\n", sum_A(1, 2));
	printf("%d\n", sub_B(1, 2));
	printf("%lf\n", mul_D(1,3)); //md
	printf("%d\n", div_D(2, 2));

	system("pause");
	return 0;
}