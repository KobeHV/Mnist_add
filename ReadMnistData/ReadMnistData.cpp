#include "ReadMnistData.h"

ReadMnistData::ReadMnistData(){}

ReadMnistData::~ReadMnistData(){}

int ReadMnistData::ReverseInt(int i)
{
	unsigned char ch1, ch2, ch3, ch4;
	ch1 = i & 255;
	ch2 = (i >> 8) & 255;
	ch3 = (i >> 16) & 255;
	ch4 = (i >> 24) & 255;
	//cout << "ch1= " << ch1 << "    (int)ch1= " << (int)ch1 << endl;
	//cout << "ch2= " << ch2 << "    (int)ch2= " << (int)ch2 << endl;
	//cout << "ch3= " << ch3 << "    (int)ch3= " << (int)ch3 << endl;
	//cout << "ch4= " << ch4 << "    (int)ch4= " << (int)ch4 << endl;
	return ((int)ch1<<24)+((int)ch2<<16)+((int)ch3<<8)+ch4;
}

string ReadMnistData::GetImageName(int number, int arr[])
{
	string str1, str2;
	for (int i = 0; i < 10; ++i) {
		if (number == i) {
			arr[i]++;
			str1 = to_string(arr[i]);
			if (arr[i] < 10)
				str1 = "0000" + str1;
			else if (arr[i] < 100)
				str1 = "000" + str1;
			else if (arr[i] < 1000)
				str1 = "00" + str1;
			else if (arr[i] < 10000)
				str1 = "0" + str1;
			break;
		}
	}
	str2 = to_string(number) + "_" + str1;
	return str2;
}

void ReadMnistData::Read_Mnist_Images(string filename, vector<cv::Mat> &vec)
{
	ifstream file(filename, ios::binary);
	int idx = filename.find_last_of("\\") + 1;
//	cout << "idx= " << idx << endl;
	string subName = filename.substr(idx);
	if (file.is_open()) {
		cout << subName << " 文件已打开.\n包含信息如下：" << endl;

		int magic_number = 0;
		int number_of_images = 0;
		int n_rows = 0;
		int n_cols = 0;

		//读取magic_number
		file.read((char*)&magic_number, sizeof(magic_number));
		magic_number = ReverseInt(magic_number);
		cout << "magic_number= " << magic_number << endl;
		//读取number_of_images
		file.read((char*)&number_of_images, sizeof(number_of_images));
		number_of_images = ReverseInt(number_of_images);
		cout << "number_of_images= " << number_of_images << endl;
		//读取n_rows
		file.read((char*)&n_rows, sizeof(n_rows));
		n_rows = ReverseInt(n_rows);
		cout << "n_rows= " << n_rows << endl;
		//读取n_cols
		file.read((char*)&n_cols, sizeof(n_cols));
		n_cols = ReverseInt(n_cols);
		cout << "n_cols= " << n_cols << endl;

		//读取image的像素值
		for (int i = 0; i < number_of_images; i++) {
			cv::Mat tp = cv::Mat::zeros(n_rows, n_cols, CV_8UC1);
			for (int r = 0; r < n_rows; r++) {
				for (int c = 0; c < n_cols; c++) {
					unsigned char temp = 0;
					file.read((char*)&temp, sizeof(temp));
					tp.at<uchar>(r, c) = (int)temp;
				}
			}
			vec.push_back(tp);
//			imshow("Test", tp);
//			waitKey(0);
			printf("正在读取图片，请稍等......%.2lf%%\r", i * 100.0 / (number_of_images - 1));
		}
		printf("\n图片读取完成!\n\n");
	}
	else
		cout <<subName<< " 文件打开失败." << endl;
	if (file.is_open())
		file.close();
	return;
}

void ReadMnistData::Read_Mnist_Labels(string filename, vector<int>& vec)
{
	ifstream file(filename, ios::binary);
	int idx = filename.find_last_of("\\") + 1;
	string subName = filename.substr(idx);
	if (file.is_open()) {
		cout << subName << " 文件已打开.\n包含信息如下：" << endl;

		int magic_number = 0;
		int number_of_labels = 0;

		//读取magic_number
		file.read((char*)&magic_number, sizeof(magic_number));
		magic_number = ReverseInt(magic_number);
		cout << "magic_number= " << magic_number << endl;
		//读取number_of_labels
		file.read((char*)&number_of_labels, sizeof(number_of_labels));
		number_of_labels = ReverseInt(number_of_labels);
		cout << "number_of_labels= " << number_of_labels << endl;

		//读取label的值
		for (int i = 0; i < number_of_labels; i++) {
			unsigned char temp = 0;
			file.read((char*)&temp, sizeof(temp));
			vec.push_back((int)temp);
//			cout << "label= " << (int)temp << endl;
			printf("正在读取标签，请稍等......%.2lf%%\r", i*100.0 / (number_of_labels - 1));
		}
		printf("\n标签读取完成!\n\n");
	}
	else
		cout << subName << " 文件打开失败." << endl;
	if (file.is_open())
		file.close();
	return;
}

void ReadMnistData::Save_Mnist_Images(string filename, vector<cv::Mat> vec_img, vector<int> vec_lab)
{
	int count_digits[10];
	fill(&count_digits[0], &count_digits[0] + 10, 0);
	if (vec_img.size() == vec_lab.size()) {
		for (int i = 0; i < vec_img.size(); i++) {
			int number = vec_lab[i];
			string image_name = GetImageName(number, count_digits);
			image_name = filename + image_name + ".jpg";
			cv::imwrite(image_name, vec_img[i]);
			printf("图片正在保存，请稍等：%.2lf%%\r", i * 100.0 / (vec_img.size()-1));
		}
	}
	cout << "\n图片保存完成！" << endl;
}


