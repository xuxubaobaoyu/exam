# 项目描述
项目名称：D 
项目用途：学习静态库、动态库的调用
# 需求分析
暂无
# 系统功能模型
暂无
# 系统设计
暂无
# 主要代码实现
**头文件**
```#ifndef _D_H
#define _D_H

#include <Windows.h>
#include <stdio.h>

double div_D(double a, double b);
double mul_D(double a,double b);
#endif
```
**C文件**
```c
#include "D.h"
//实现减法
double div_D(double a, double b)
{
		return a/b;
}

//实现对动态库的显示调用
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
```
# 测试：
白盒测试，四个库的代码覆盖度：

![在这里插入图片描述](https://img-blog.csdnimg.cn/20200727081540419.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzM5ODI4NDcy,size_16,color_FFFFFF,t_70#pic_center)

# 参考文献
暂无
# 附录
## 动态库的第一种调用方式：静态加载
 1. 在需要调用动态库的项目中，选中项目点击右键属性->选择VC++目录->在包含目录中添加动态库头文件的路径，在库目录中添加.lib文件的路径
![在这里插入图片描述](https://img-blog.csdnimg.cn/20200727014228646.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzM5ODI4NDcy,size_16,color_FFFFFF,t_70#pic_center)
 2. 再在属性界面选择链接器->输入->附加依赖项->输入调用.lib文件的名字
![在这里插入图片描述](https://img-blog.csdnimg.cn/20200727014254909.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzM5ODI4NDcy,size_16,color_FFFFFF,t_70#pic_center)
 3. 在调用.c文件中添加动态库的头文件
## 动态库的第二种调用方式：显示调用
这种方式不用添加任何路径与文件，因为这种方式是在程序运行的时候在内存中实现对函数的调用，主要是使用三个函数LoadLibrary、GetProcAddress、FreeLibrary，例子如下

```c
	HINSTANCE handle = LoadLibrary("C.dll");//LoadLibrary填入ddl文件名赋值给句柄，你不懂句柄就拉倒了，这个不重要。
	if (handle) //判读句柄内dll是否可用
	{
		typedef int(*DLL_FUNCTION_ADD) (int, int); //typedef定义一下函数指针，你不懂的话就记住末尾两个是你需要函数的形参。
		printf("AAA\n");
		DLL_FUNCTION_ADD dll_chen = (DLL_FUNCTION_ADD)GetProcAddress(handle, "chen"); //使用GetProcAddress得到函数，参数是句柄名和函数名
		if (dll_chen) //还是判断一下函数指针是否有效
		{
			int result = dll_chen(10, 11); //终于可以用add了
			printf("dll_chen返回值：%d\n", result); //打印吧
		}
		FreeLibrary(handle); //卸载句柄，，
	}

	system("pause");
```

