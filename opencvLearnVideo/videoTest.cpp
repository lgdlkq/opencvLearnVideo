#include<opencv2\opencv.hpp>
using namespace cv;

int main() {
	/*
	//��ȡ��������Ƶ
	VideoCapture capture("m.avi");//��ȡ��Ƶ
	while (1) {//ѭ����ʾÿһ֡��Ƶ����
		Mat frame;//���ڴ洢ÿһ֡��ͼ��
		capture >> frame;//��ȡ��ǰ֡
		imshow("��ȡ��Ƶ",frame);//��ʾ��ǰ֡
		waitKey(30);//��ʱ30ms
	}
	*/
	//��������ͷ�ɼ�ͼ��
	VideoCapture capture(0);//������ͷ������Ƶ
	while (1) {
		Mat frame;
		capture >> frame;//��ȡ��ǰ֡
		imshow("��ȡ����ͷ", frame);//��ʾ��ǰ֡
		waitKey(30);//��ʱ30ms
	}
	return 0;
}