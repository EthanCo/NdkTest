// OpenCVTest.cpp: 定义应用程序的入口点。
//

#include "OpenCVTest.h"
#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

int main()
{
	cout << "Hello CMake。" << endl;
	//Mat img = imread("D:/image/img.jpg");
	Mat img = imread("D:/bg.jpg");
	imshow("img", img); //显示原图
	cvtColor(img, img, COLOR_BGR2GRAY);
	imshow("img2", img); //显示灰色图片
	waitKey();
	return 0;
}
