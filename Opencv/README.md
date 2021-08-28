# opencv组织关系
![组织结构](C:\Users\logic-life\Desktop\Markdown\1-1Q026141623M5.jpg "组织结构")           

模块|说明
---|---
Core|该模块包含Opencv库的基础结构以及基本操作
Improc|图像处理模块包含基本的图像装换，包含滤波以及类似的卷积操作
Highgui|在Opencv 3.0中，分割为imcodecs、videoio以及highgui三部分。这个模块包含可以用来显示图像或者简单的输入的用户交互函数。这可以看做是一个非常轻量级的windows UI工具包。
video|该模块包含读取和写视频流的函数。
Calib3d|这个模块包含校准单个、双目以及多个相机的算法实现。
Feature2d|这个模块包含检测、描述以及匹配特征点的算法。
Objectect|这个模块包含检测特定目标，比如人脸或者行人的算法。也可以训练检测器并用来检测其他物体。
MI|机器学习模块本上是一个非常完备的模块，包含大量的机器学习算法实现并且这些算法都能和Opencv的数据类型自然交互。
Flan|Flan的意思是“快速最邻近库”。这个库包含一些你也许不会直接使用方法，但是其他模块中的函数会调用在数据集中进行最邻近搜索。
Gpu|在Opencv中被分割为多个cuda模块。GPU模块主要是函数在CUDA GPU上的优化实现，此外，还有一些仅用于GPU的功能。其中的一些函数能够返回很好的结果，但是需要足够好的计算资源，如果硬件没有GPU,则不会有什么提升。
Photo|这是一个相当新的模块，包含计算摄影学的一些函数工具。
Stitching|本模块是一个精巧的图像拼接流程实现。这是库中的新功能，但是，就像Photo模块一样，这个领域未来预计有很大的增长。
Nonfree|在Opencv3.0中，被移opencv_contrib/xfeatures2d。opencv包含一些受到专利的或者受到使用限制（比如SIFT算法）算法。这些算法被隔离到它们自己的模块中，以表明你需要做一些特殊的工作，才可以在商用产品中使用它们。
Contrib|在Opencv3.0中，融合进了opencv_contrib。这个模块包含一些新的、还没有被集成进Opencv库的东西。
Legacy|在opencv3.0中，被取消。这个模块包含一些老的尚未被完全取消的东西。
ocl|在opencv3.0被取消，取而代之的是T-api。这是一个较新的模块，可以认为它和GPU模块相似，它实现了开放并行编程的Khronos OPencl标准。虽然现在模块的特性比Gpu模块少很多，但ocl模块的目标是提供可以运行在任何GPU或者其他可以搭载khronos的并行设备。这与GPU模块形成了鲜明的对比，后者使用Nividia CUDA工具包进行开发，因此只能在Nividia GPU设备上班工作。

# opencv 安装说明(visual studio 15)
**1、首先下载opencv-4.5.1-vc14-vc15.exe**

**2、安装后配置用户环境变量**

**3、在项目属性中分别添加vc++目录的include Directorie：~\opencv\build\include和Library Directories:~\opencv\build\x64\vc15\lib**

**4、链接器中添加opencv_world451d.lib**

**5、添加库函数声明：**
```
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace cv;
```
**6、调用资源文件时，可以将文件直接复制到项目中**

