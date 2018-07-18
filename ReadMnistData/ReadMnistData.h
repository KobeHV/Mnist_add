#pragma once
#ifndef READMNISTDATA_H_
#define READMNISTDATA_H_
#include <iostream>
#include <fstream>
#include <vector>
#include <opencv2\opencv.hpp>
using namespace std;
using namespace cv;

class ReadMnistData
{
public:
	ReadMnistData();
	~ReadMnistData();
	static int ReverseInt(int i);
	static string GetImageName(int number, int arr[]);
	void Read_Mnist_Images(string filename, vector<cv::Mat> &vec);
	void Read_Mnist_Labels(string filename, vector<int> &vec);
	void Save_Mnist_Images(string filename, vector < cv:: Mat > vec_img, vector<int> vec_lab);

private:

};
#endif // !READMNISTDATA_H_
