#include "stdafx.h"
#include "CppUnitTest.h"
#include "../A/A.h"
#include "../B/B.h"
#include "../C/C.h"
#include "../D/D.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestA)
		{
			Assert::AreEqual(10.0, sum_A(1.0,2.0));// TODO:  �ڴ�������Դ���
		}
		TEST_METHOD(TestB)
		{
			Assert::AreEqual(10.0, sub_B(1.0, 2.0));// TODO:  �ڴ�������Դ���
		}
		TEST_METHOD(TestC)
		{
			Assert::AreEqual(10.0, mul_C(1.0, 2.0));// TODO:  �ڴ�������Դ���
		}

		int c=0;
		TEST_METHOD(TestD1)
		{
			Assert::AreEqual(10.0, div_D(1.0, 1,&c));// TODO:  �ڴ�������Դ���
		}
		TEST_METHOD(TestD2)
		{
			Assert::AreEqual(10.0, div_D(1.0, 0, &c));// TODO:  �ڴ�������Դ���
		}

	};
}