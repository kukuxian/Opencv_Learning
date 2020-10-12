#include <opencv2/opencv.hpp>
#include <iostream>
#include <math.h>

using namespace std;
using namespace cv;

int main(int argc, char** argv) {
	Mat src, dst;
	src = imread("F:/Learning_Proess/Opencv_Learning/images/1.png");
	if (!src.data) {
		printf("could not load image...\n");
		return -1;
	}
	namedWindow("input image", WINDOW_AUTOSIZE);
	imshow("input image", src);


	int cols = (src.cols - 1) * src.channels();//�ܹ�������
	int rows = src.rows;//�ܹ�������
	int offsetx = src.channels();
	dst = Mat::zeros(src.size(), src.type());
	for (int row = 1; row < (rows - 1); row++) {
		const uchar* previous = src.ptr<uchar>(row - 1);
		const uchar* current = src.ptr<uchar>(row);
		const uchar* next = src.ptr<uchar>(row + 1);
		uchar* output = dst.ptr<uchar>(row);
		for (int col = offsetx; col < cols; col++) {
			output[col] = saturate_cast<uchar>(5 * current[col] - (current[col - offsetx] + current[col + offsetx] + previous[col] + next[col]));
		}
	}
	namedWindow("�����ͼ��Ϊ", WINDOW_AUTOSIZE);
	imshow("�����ͼ��Ϊ", dst);

	waitKey(0);
	return 0;

}