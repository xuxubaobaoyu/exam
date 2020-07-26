#include "D.h"

double div_D(double a, double b)
{
		return a/b;
}
double mul_D(double a,double b)
{
	double result = 0;
	HINSTANCE handle = LoadLibrary("C.dll");//LoadLibrary填入ddl文件名赋值给句柄
	if (handle) //判读句柄内dll是否可用
	{
		typedef double(*DLL_FUNCTION_ADD) (double, double); //typedef定义一下函数指针，末尾两个是函数的形参。
		DLL_FUNCTION_ADD mul_C = (DLL_FUNCTION_ADD)GetProcAddress(handle, "mul_C"); //使用GetProcAddress得到函数，参数是句柄名和函数名
		if (mul_C) //还是判断一下函数指针是否有效
		{
			result = mul_C(a, b); //终于可以用mul_C了
			FreeLibrary(handle); //卸载句柄
			return result;
		}			
	}
	return 0;
}