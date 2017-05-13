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
	Mat edges;
	while (1) {
		Mat frame;
		capture >> frame;//读取当前帧

		//将原图像转换为灰度图
		//cvtColor(frame, edges, CV_BGR2GRAY);//opencv2版代码
		cvtColor(frame, edges, COLOR_BGR2GRAY);//opencv3版代码
		blur(edges, edges, Size(7, 7));//使用3x3内核来降噪（2x3+1=7），模糊，Size内数字越大，线条越少，即模糊越厉害
		Canny(edges,edges,0,30,3);//进行Canny边缘检测并显示
		imshow("读取摄像头", frame);//显示当前帧
		imshow("边缘检测并高斯模糊的图像", edges);//显示经过处理的图像
		if(waitKey(30) >= 0) break;//延时30ms,超过时跳出循环读取摄像头（比如按下空格键）
	}
	return 0;
}