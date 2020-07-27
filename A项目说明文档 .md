# 项目描述
项目名称：A  
项目用途：学习静态库的生成与调用，并实现两数相加
# 需求分析
暂无
# 系统功能模型
暂无
# 系统设计
暂无
# 主要代码实现
**头文件**
```#ifndef _A_H
#define _A_H
double	sum_A(double a, double b);

#endif
```
**C文件**
```c
#include "A.h"

double	sum_A(double a, double b)
{
	return a + b;
}
```
# 测试：
黑盒测试，边沿测试包括：输入溢出测试、计算溢出测试、小数点精确点位数测试、输入过小测试：
![在这里插入图片描述](https://img-blog.csdnimg.cn/20200727095028271.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzM5ODI4NDcy,size_16,color_FFFFFF,t_70#pic_center)
# 参考文献
暂无
# 附录
## 静态库生成步骤

 1. 新建一个空项目->选中项目点击右键属性->配置类型改为静态库
 ![静态库配置1](https://img-blog.csdnimg.cn/20200727005913432.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzM5ODI4NDcy,size_16,color_FFFFFF,t_70#pic_center)
 
 2.添加头文件和c文件 ->写入程序
 ![在这里插入图片描述](https://img-blog.csdnimg.cn/2020072701012841.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzM5ODI4NDcy,size_16,color_FFFFFF,t_70#pic_center)
 ##  静态库调用VS配置步骤
1. 在需要调用静态库的项目中，选中项目点击右键属性->选择VC++目录->在包含目录中添加静态库头文件的路径，在库目录中添加.lib文件的路径
![在这里插入图片描述](https://img-blog.csdnimg.cn/20200727010523290.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzM5ODI4NDcy,size_16,color_FFFFFF,t_70#pic_center)
 2. 再在属性界面选择链接器->输入->附加依赖项->输入调用.lib文件的名字
 ![在这里插入图片描述](https://img-blog.csdnimg.cn/20200727010848522.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzM5ODI4NDcy,size_16,color_FFFFFF,t_70#pic_center)


 




 

