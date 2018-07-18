#include "ReadMnistData.h"

int main()
{
	ReadMnistData rmd;

	/*读取训练文件并保存成图片格式*/
	string filename_train_images = "D:\\mnist\\train-images-idx3-ubyte";		//train images 文件路径
	string filename_train_labels = "D:\\mnist\\\train-labels-idx1-ubyte";			//train labels 文件路径
	string save_train_image_path = "D:\\mnist\\train_images\\";						//train images 保存路径
	
	vector<cv::Mat> vec_train_images;			//保存读取的train images
	vector<int> vec_train_labels;					//保存读取的train labels

	rmd.Read_Mnist_Images(filename_train_images, vec_train_images);			//读取train images
	cout << "-----------------------------" << endl;
	rmd.Read_Mnist_Labels(filename_train_labels, vec_train_labels);				//读取train labels
	cout << "-----------------------------" << endl;
	rmd.Save_Mnist_Images(save_train_image_path, vec_train_images, vec_train_labels);		//保存train_images

	//==================================================================================
	/*读取测试文件并保存成图片格式*/
	string filename_test_images = "D:\\mnist\\t10k-images-idx3-ubyte";		//test images 文件路径	
	string filename_test_labels = "D:\\mnist\\t10k-labels-idx1-ubyte";			//test labels 文件路径	
	string save_test_image_path = "D:\\mnist\\test_images\\";						//test images 保存路径	
	vector<cv::Mat> vec_test_images;			//保存读取的test images
	vector<int> vec_test_labels;					//保存读取的test labels
	
	rmd.Read_Mnist_Images(filename_test_images, vec_test_images);			//读取test images
	cout << "-----------------------------" << endl;
	rmd.Read_Mnist_Labels(filename_test_labels, vec_test_labels);				//读取test labels
	cout << "-----------------------------" << endl;
	rmd.Save_Mnist_Images(save_test_image_path, vec_test_images, vec_test_labels);		//保存test_images

	return 0;
}

