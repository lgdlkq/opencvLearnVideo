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
	Mat edges;
	while (1) {
		Mat frame;
		capture >> frame;//��ȡ��ǰ֡

		//��ԭͼ��ת��Ϊ�Ҷ�ͼ
		//cvtColor(frame, edges, CV_BGR2GRAY);//opencv2�����
		cvtColor(frame, edges, COLOR_BGR2GRAY);//opencv3�����
		blur(edges, edges, Size(7, 7));//ʹ��3x3�ں������루2x3+1=7����ģ����Size������Խ������Խ�٣���ģ��Խ����
		Canny(edges,edges,0,30,3);//����Canny��Ե��Ⲣ��ʾ
		imshow("��ȡ����ͷ", frame);//��ʾ��ǰ֡
		imshow("��Ե��Ⲣ��˹ģ����ͼ��", edges);//��ʾ���������ͼ��
		if(waitKey(30) >= 0) break;//��ʱ30ms,����ʱ����ѭ����ȡ����ͷ�����簴�¿ո����
	}
	return 0;
}