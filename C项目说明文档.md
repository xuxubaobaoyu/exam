# 项目描述
项目名称：C
项目用途：学习动态库的生成
# 需求分析
暂无
# 系统功能模型
暂无
# 系统设计
暂无
# 主要代码实现
**头文件**
```#ifndef _C_H
#define _C_H

#ifdef DLL_C
#define		DLL_IMPORT_EXPORT	 __declspec(dllexport)	
#else
#define		DLL_IMPORT_EXPORT	 __declspec(dllimport)		
#endif
extern "C"	DLL_IMPORT_EXPORT	double mul_C(double a, double b);


#endif
```
**C文件**
```c
#include "C.h"

double mul_C(double a, double b)
{
	return a * b;
}
```
# 测试：
黑盒测试，边沿测试包括：输入溢出测试、计算溢出测试、小数点精确点位数测试、输入过小测试：
![在这里插入图片描述](https://img-blog.csdnimg.cn/20200727095257803.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzM5ODI4NDcy,size_16,color_FFFFFF,t_70#pic_center)


# 参考文献
暂无
# 附录
暂无
