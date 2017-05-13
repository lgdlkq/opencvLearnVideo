#include<opencv2\opencv.hpp>
using namespace cv;

int main() {
	/*
	//读取并播放视频
	VideoCapture capture("m.avi");//读取视频
	while (1) {//循环显示每一帧视频内容
		Mat frame;//用于存储每一帧的图像
		capture >> frame;//读取当前帧
		imshow("读取视频",frame);//显示当前帧
		waitKey(30);//延时30ms
	}
	*/
	//调用摄像头采集图像
	VideoCapture capture(0);//从摄像头读入视频
	while (1) {
		Mat frame;
		capture >> frame;//读取当前帧
		imshow("读取摄像头", frame);//显示当前帧
		waitKey(30);//延时30ms
	}
	return 0;
}