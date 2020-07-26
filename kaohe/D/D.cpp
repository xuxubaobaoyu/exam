#include "D.h"

double div_D(double a, double b)
{
		return a/b;
}
double mul_D(double a,double b)
{
	double result = 0;
	HINSTANCE handle = LoadLibrary("C.dll");//LoadLibrary����ddl�ļ�����ֵ�����
	if (handle) //�ж������dll�Ƿ����
	{
		typedef double(*DLL_FUNCTION_ADD) (double, double); //typedef����һ�º���ָ�룬ĩβ�����Ǻ������βΡ�
		DLL_FUNCTION_ADD mul_C = (DLL_FUNCTION_ADD)GetProcAddress(handle, "mul_C"); //ʹ��GetProcAddress�õ������������Ǿ�����ͺ�����
		if (mul_C) //�����ж�һ�º���ָ���Ƿ���Ч
		{
			result = mul_C(a, b); //���ڿ�����mul_C��
			FreeLibrary(handle); //ж�ؾ��
			return result;
		}			
	}
	return 0;
}