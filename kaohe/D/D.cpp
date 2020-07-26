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
	HINSTANCE handle = LoadLibrary("C.dll");//LoadLibrary����ddl�ļ�����ֵ��������㲻������������ˣ��������Ҫ��
	if (handle) //�ж������dll�Ƿ����
	{
		typedef double(*DLL_FUNCTION_ADD) (double, double); //typedef����һ�º���ָ�룬�㲻���Ļ��ͼ�סĩβ����������Ҫ�������βΡ�
		DLL_FUNCTION_ADD mul_C = (DLL_FUNCTION_ADD)GetProcAddress(handle, "mul_C"); //ʹ��GetProcAddress�õ������������Ǿ�����ͺ�����
		if (mul_C) //�����ж�һ�º���ָ���Ƿ���Ч
		{
			result = mul_C(a, b); //���ڿ�����add��
			FreeLibrary(handle); //ж�ؾ��
			return result;
		}			
	}
	return a + b;
}