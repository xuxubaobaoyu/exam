#include <stdio.h>
#include <stdlib.h>
#include "A.h"
#include "B.h"
#include "D.h"
#include <Windows.h>
int main()
{
	HINSTANCE handle = LoadLibrary("C.dll");//LoadLibrary填入ddl文件名赋值给句柄，你不懂句柄就拉倒了，这个不重要。
	if (handle) //判读句柄内dll是否可用
	{
		typedef int(*DLL_FUNCTION_ADD) (int, int); //typedef定义一下函数指针，你不懂的话就记住末尾两个是你需要函数的形参。
		DLL_FUNCTION_ADD mul_C = (DLL_FUNCTION_ADD)GetProcAddress(handle, "mul_C"); //使用GetProcAddress得到函数，参数是句柄名和函数名
		if (mul_C) //还是判断一下函数指针是否有效
		{
			int result = mul_C(10, 11); //终于可以用add了
			printf("%d\n", sum_A(1, 2));
			printf("%d\n", sub_B(1, 2));
			printf("%d\n", div_D(1, 2));
			printf("mul_C返回值：%d\n", result); //打印吧
		}
		FreeLibrary(handle); //卸载句柄，，
	}

	system("pause");
	return 0;
}