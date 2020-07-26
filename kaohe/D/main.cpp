#include <stdio.h>
#include <stdlib.h>
#include "A.h"
#include "B.h"
#include "D.h"
#include <Windows.h>
int main()
{
	HINSTANCE handle = LoadLibrary("C.dll");//LoadLibrary����ddl�ļ�����ֵ��������㲻������������ˣ��������Ҫ��
	if (handle) //�ж������dll�Ƿ����
	{
		typedef int(*DLL_FUNCTION_ADD) (int, int); //typedef����һ�º���ָ�룬�㲻���Ļ��ͼ�סĩβ����������Ҫ�������βΡ�
		DLL_FUNCTION_ADD mul_C = (DLL_FUNCTION_ADD)GetProcAddress(handle, "mul_C"); //ʹ��GetProcAddress�õ������������Ǿ�����ͺ�����
		if (mul_C) //�����ж�һ�º���ָ���Ƿ���Ч
		{
			int result = mul_C(10, 11); //���ڿ�����add��
			printf("%d\n", sum_A(1, 2));
			printf("%d\n", sub_B(1, 2));
			printf("%d\n", div_D(1, 2));
			printf("mul_C����ֵ��%d\n", result); //��ӡ��
		}
		FreeLibrary(handle); //ж�ؾ������
	}

	system("pause");
	return 0;
}