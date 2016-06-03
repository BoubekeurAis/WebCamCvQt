#include "qcvwidget.h"
#include "ui_qcvwidget.h"
#include "RGBCamera.h"
#include <QTimer>
using namespace cv;
QCVWidget::QCVWidget(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::QCVWidget)
{
    ui->setupUi(this);
    //setup();
	thread = new QThread();
	RGBCamera *worker = new RGBCamera();
	QTimer *workerTrigger = new QTimer();
	workerTrigger->setInterval(1);

	connect(workerTrigger, SIGNAL(timeout()), worker, SLOT(slotGrabFrame()));
	connect(this, SIGNAL(sigSetup(int)), worker, SLOT(slotSetup(int)));
	connect(worker, SIGNAL(sigFrame(QImage)), this, SLOT(slotFrame(QImage)));

	workerTrigger->start();
	worker->moveToThread(thread);
	workerTrigger->moveToThread(thread);
	thread->start();

	emit sigSetup(0);
}

QCVWidget::~QCVWidget()
{
    thread->quit();
    while(!thread->isFinished());
    delete thread;
    delete ui;
}
void QCVWidget::setup()
{

	/*
    thread = new QThread();
	RGBCamera *worker = new RGBCamera();
    QTimer *workerTrigger = new QTimer();
    workerTrigger->setInterval(1);

    connect(workerTrigger,SIGNAL(timeout()),worker, SLOT(slotGrabFrame()));
    connect(this, SIGNAL(sigSetup(int )), worker, SLOT(slotSetup(int ))); 
	connect(worker, SIGNAL(sigFrame(QImage)), this, SLOT(slotFrame(QImage)));

    workerTrigger->start();
    worker->moveToThread(thread);
    workerTrigger->moveToThread(thread);
    thread->start();

    emit sigSetup(0);*/
}

void QCVWidget::slotFrame(QImage frame)
{
    ui->label->setPixmap(QPixmap::fromImage(frame));

}