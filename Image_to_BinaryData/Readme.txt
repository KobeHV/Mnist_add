/*模仿mnist数据集制作自己的数据集代码*/

代码一共包含三个文件
	Image_to_BinaryData.h
	Image_to_BinaryData.cpp
	Main.cpp

其中：Image_to_BinaryData.h 和 Image_to_BinaryData.cpp 里面定义了相关的类和函数，可根据自己的数据集自行修改

使用方法：
	在Main.h文件中设置好自己的图片大小以及先关的文件路径，编译运行即可。

说明：
	此代码只适合所有图片大小一致的灰度图像，不适合彩色图像，可对相应位置自行进行修改。
	图片命名规则：0_00001.jpg：0表示对应图片的内容，即标签；
	00001表示标签为0的图片中第1张图片，00002为第2张图片，以此类推........
	

运行环境：win10 + VS2017 + Opencv3.4.2