#ifndef RGBCAMERA_H
#define RGBCAMERA_H

#include <QObject>
#include "QImage"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;
class RGBCamera : public QObject
{
    Q_OBJECT
private:
    cv::Mat _frameOriginale;

    VideoCapture cap;
  
public:
    explicit RGBCamera(QObject *parent = 0);
    ~RGBCamera();

signals:
    void sigFrame(QImage frameProcessed);


public slots:
	void slotGrabFrame();
    void slotSetup(const int device);
    

};

#endif // RGBCamera_H
