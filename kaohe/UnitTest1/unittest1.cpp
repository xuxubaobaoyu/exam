#include "stdafx.h"
#include "CppUnitTest.h"
#include "../A/A.h"
#include "../B/B.h"
#include "../C/C.h"
#include "../D/D.h"
#include <math.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestA)
		{
			//double输入整数1.79769e+308 ~ 2.22507e-308
		//	Assert::AreEqual(2.0, sum_A(1.0, 1));//基本功能测试
			/*边沿测试包括：输入溢出测试、计算溢出测试、小数点精确点位数测试、输入过小测试*/
		//	Assert::AreEqual(10000000000000000.0, sum_A(9999999999999999.0, 1.0));//输入溢出测试
			Assert::AreEqual(1000000000000000000000000000000000000000.0, sum_A(999999999999999999999999999999999999999.0, 1.0));//输入溢出测试、计算溢出测试，结果正确
			//在程序中规定了小数位数，我规定的输入边界，为小数点后7位
			Assert::AreEqual(0.0000002, sum_A(0.0000001, 0.0000001), 1e-10);
			//Assert::AreEqual(0.00000002, sum_A(0.00000001, 0.00000001), 1e-10);
			Assert::AreEqual(1.08000000000000002, sum_A(1.0, 0.08000000000000002), 1e-10);//小数极限测试
		}
		TEST_METHOD(TestB)
		{
			//Assert::AreEqual(-1.0, sub_B(1.0, 2.0));//基本功能测试
			/*边沿测试包括：输入溢出测试、计算溢出测试、小数点精确点位数测试、输入过小测试*/
			Assert::AreEqual(999999999999999999999999999999999999998.0, sub_B(999999999999999999999999999999999999999.0, 1.0));//输入溢出测试、计算溢出测试，结果正确
			//在程序中规定了小数位数，我规定的输入边界，为小数点后7位
			Assert::AreEqual(0.0000001, sub_B(0.0000002, 0.0000001), 1e-10);
			//Assert::AreEqual(0.00000002, sub_B(0.00000001, 0.00000001), 1e-10);
			Assert::AreEqual(1.99999999999999998, sub_B(2.0, 0.00000000000000002), 1e-10);//小数极限测试
		}
		TEST_METHOD(TestC)
		{
			//Assert::AreEqual(2.0, mul_C(1.0, 2.0));//基本功能测试
			//Assert::AreEqual(2.0, mul_D(1.0, 2.0));//基本功能测试
			/*边沿测试包括：输入溢出测试、计算溢出测试、小数点精确点位数测试、输入过小测试*/
			Assert::AreEqual(1e40, mul_D(1e20, 1e20));//输入溢出测试、计算溢出测试，结果正确
			//在程序中规定了小数位数，我规定的输入边界，为小数点后7位
			//Assert::AreEqual(0.0000000000002, mul_D(0.0000002, 0.0000001), 1e-10);
			Assert::AreEqual(0.00000000000000004, mul_D(2.0, 0.00000000000000002), 1e-10);//小数极限测试
		}

		TEST_METHOD(TestD1)
		{
			Assert::AreEqual(1.0, div_D(1.0, 1));
		}
		TEST_METHOD(TestD2)
		{
			Assert::AreEqual(0.0, div_D(1.0, 0.0));
		}

	};
}