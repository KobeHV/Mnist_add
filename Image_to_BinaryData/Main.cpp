#include "Image_to_BinaryData.h"

int main()
{
	Image2BinaryData IBD(28,28);											//设置图片大小(Height,Width)
	
	/*------------生成训练集文件--------------------------*/
	printf("----------生成训练集文件-------------\n");
	string trainfilefolder = "D:\\mnist\\train_images";		//训练图片文件路径
	vector<string> trainfileLists = IBD.getFileLists(trainfilefolder);				//获得文件名列表

	const int train_size_list = trainfileLists.size();
	cout << "Images Number: " << train_size_list << endl;							//输出文件个数

	string trainimagebinfilepath = "D:\\mnist\\back\\train-images-idx3-ubyte";		//训练图片转换保存路径
	string trainlabelbinfilepath = "D:\\mnist\\back\\train-labels-idx1-ubyte";		//训练标签转换保存路径
	vector<cv::Mat> TrainImagesMat;															//用来存储训练图片像素值
	vector<int> train_image_labels(train_size_list);										//用来存储训练类标签列表
	IBD.ReadImage(trainfilefolder, trainfileLists, train_image_labels, TrainImagesMat);		//读取训练图片
	IBD.Image2BinaryFile(trainimagebinfilepath, TrainImagesMat, train_image_labels);		//训练图片转二进制文件
	IBD.Label2BinaryFile(trainlabelbinfilepath, train_image_labels);						//训练标签转二进制文件

	/*------------生成测试集文件--------------------------*/
	printf("\n\n----------生成测试集文件-------------\n");
	string testfilefolder = "D:\\mnist\\test_images";		//测试图片文件路径
	vector<string> testfileLists = IBD.getFileLists(testfilefolder);			//获得文件名列表
	
	const int test_size_list = testfileLists.size();
	cout << "Images Number: " << test_size_list << endl;									//输出文件个数
	string testimagebinfilepath = "D:\\mnist\\back\\t10k-images-idx3-ubyte";		//测试图片转换保存路径
	string testlabelbinfilepath  = "D:\\mnist\\back\\t10k-labels-idx1-ubyte";		//测试标签转换保存路径
	vector<cv::Mat> TestImagesMat;															//用来存储测试图片像素值
	vector<int> test_image_labels(test_size_list);											//用来存储测试类标签列表
	IBD.ReadImage(testfilefolder, testfileLists, test_image_labels, TestImagesMat);			//读取测试图片
	IBD.Image2BinaryFile(testimagebinfilepath, TestImagesMat, test_image_labels);			//测试图片转二进制文件
	IBD.Label2BinaryFile(testlabelbinfilepath, test_image_labels);							//测试标签转二进制文件

	return 0;
}