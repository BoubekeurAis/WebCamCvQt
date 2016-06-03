#include "RGBCamera.h"
#include <opencv2/imgproc/imgproc.hpp>

#include <QThread>
using namespace cv;
RGBCamera::RGBCamera(QObject *parent) :
    QObject(parent)
{
	cap=  cv::VideoCapture();

}

RGBCamera::~RGBCamera()
{
    if(cap.isOpened()) cap.release();
   
}
void RGBCamera::slotGrabFrame()
{
  
	cap >> _frameOriginale;
	cvtColor(_frameOriginale, _frameOriginale, CV_BGR2RGB);
	QImage output((uchar *)_frameOriginale.data, _frameOriginale.cols, _frameOriginale.rows, _frameOriginale.step, QImage::Format_RGB888);
    emit sigFrame(output);

}



void RGBCamera::slotSetup(const int device)
{
	/*if (cap.isOpened())*/ cap.release();
	cap.open(device);
}
