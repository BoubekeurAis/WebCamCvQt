#ifndef QCVWIDGET_H
#define QCVWIDGET_H

#include <QMainWindow>
#include <QThread>
#include "RGBCamera.h"
namespace Ui {
class QCVWidget;
}

class QCVWidget : public QMainWindow
{
    Q_OBJECT
private:
    Ui::QCVWidget *ui;
    QThread *thread;
	
	RGBCamera *worker;
	QTimer *workerTrigger;
    void setup();


public:
    explicit QCVWidget(QWidget *parent = 0);
    ~QCVWidget();
signals:
    void sigSetup(int device);
private slots:
    void slotFrame(QImage frame);
};

#endif // QCVWIDGET_H
