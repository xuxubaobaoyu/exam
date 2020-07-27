# 项目描述
项目名称：B  
项目用途：学习动态库的生成
# 需求分析
暂无
# 系统功能模型
暂无
# 系统设计
暂无
# 主要代码实现
**头文件**
文件说明：通过关键字__declspec实现动态库的生成，添加extern "C"的目的是强制使编译器以C语言的方式去编译函数， 若不添加会以C++的方式编译，对函数可能会加上一些标识符，导致函数调用失败
```#ifndef _B_H
#define _B_H

#ifdef DLL_B
#define		DLL_IMPORT_EXPORT	__declspec(dllexport)	
#else
#define		DLL_IMPORT_EXPORT	__declspec(dllimport)		
#endif
extern "C" DLL_IMPORT_EXPORT	double sub_B(double a, double b);

#endif
```
**C文件**
```c
#include "B.h"

DLL_IMPORT_EXPORT	double sub_B(double a, double b)
{
	return a - b;
}
```

# 测试：
黑盒测试，边沿测试包括：输入溢出测试、计算溢出测试、小数点精确点位数测试、输入过小测试：

![在这里插入图片描述](https://img-blog.csdnimg.cn/20200727095146599.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzM5ODI4NDcy,size_16,color_FFFFFF,t_70#pic_center)

# 参考文献
暂无
# 附录
## 动态库生成步骤
 1. 新建一个空项目->选中项目点击右键属性->配置类型改为动态库
 ![在这里插入图片描述](https://img-blog.csdnimg.cn/20200727011850801.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzM5ODI4NDcy,size_16,color_FFFFFF,t_70#pic_center)
 2. 添加.c与.h文件并编写函数，在头文件中加上关键字，并在函数什么前加上。有条件编译的原因是，dllexport是用于动态库生成，dllimport用于动态库的调用，若生成动态库，其中DLL_B的宏定义建议在属性->预处理器中进行定义
![在这里插入图片描述](https://img-blog.csdnimg.cn/2020072701211165.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzM5ODI4NDcy,size_16,color_FFFFFF,t_70#pic_center)
![在这里插入图片描述](https://img-blog.csdnimg.cn/20200727012716541.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzM5ODI4NDcy,size_16,color_FFFFFF,t_70#pic_center)


