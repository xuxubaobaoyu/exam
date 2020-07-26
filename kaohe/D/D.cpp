#include "D.h"

double div_D(double a, double b,int* c)
{
	if (b == 0)
	{
		*c = 1;
		return 0;
	}
	else
	{
		return a/b;
	}
	
}
double mul_D(double a,double b)
{
	double result = 0;
	HINSTANCE handle = LoadLibrary("C.dll");//LoadLibrary填入ddl文件名赋值给句柄，你不懂句柄就拉倒了，这个不重要。
	if (handle) //判读句柄内dll是否可用
	{
		typedef double(*DLL_FUNCTION_ADD) (double, double); //typedef定义一下函数指针，你不懂的话就记住末尾两个是你需要函数的形参。
		DLL_FUNCTION_ADD mul_C = (DLL_FUNCTION_ADD)GetProcAddress(handle, "mul_C"); //使用GetProcAddress得到函数，参数是句柄名和函数名
		if (mul_C) //还是判断一下函数指针是否有效
		{
			result = mul_C(a, b); //终于可以用add了
			FreeLibrary(handle); //卸载句柄
			return result;
		}			
	}
	return a + b;
}