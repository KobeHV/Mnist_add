#pragma once
#ifndef IMAGE_TO_BINARYDATA_H_
#define IMAGE_TO_BINARYDATA_H_
#include <iostream>
#include <vector>
#include <opencv2\opencv.hpp>
using namespace std;


class Image2BinaryData
{
public:
	int Height;
	int Width;
public:
	Image2BinaryData(int x, int y) :Height(x), Width(y) {} 
	~Image2BinaryData() {}

	void ReverseInt(ofstream &file, int i);
	vector<string> getFileLists(string file_folder);		//��ȡ�ļ����µ�ͼƬ����
	string getFileName(string &filename);					//���ļ��ľ���·�����еõ��ļ���

	void ReadImage(string filefolder, vector<string> &img_Lists, vector<int> &img_Labels, vector<cv::Mat> &ImagesMat);
	void Image2BinaryFile(string filefolder, vector<cv::Mat> &ImagesMat, vector<int> & img_Labels);
	void Label2BinaryFile(string filefolder,vector<int> &img_Labels);
};





#endif // !IMAGE_TO_BINARYDATA_H_