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
		DLL_FUNCTION_ADD dll_chen = (DLL_FUNCTION_ADD)GetProcAddress(handle, "chen"); //ʹ��GetProcAddress�õ������������Ǿ�����ͺ�����
		if (dll_chen) //�����ж�һ�º���ָ���Ƿ���Ч
		{
			int result = dll_chen(10, 11); //���ڿ�����add��
			printf("%d\n", sum(1, 2));
			printf("%d\n", sub(1, 2));
			printf("%d\n", chu(1, 2));
			printf("dll_chen����ֵ��%d\n", result); //��ӡ��
		}
		FreeLibrary(handle); //ж�ؾ������
	}

	system("pause");
	return 0;
}