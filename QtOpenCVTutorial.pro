#-------------------------------------------------
#
# Project created by QtCreator 2016-05-27T09:03:27
#
#-------------------------------------------------

QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QtOpenCVTutorial
TEMPLATE = app


SOURCES += main.cpp\
        qcvwidget.cpp \
    opencvworker.cpp

HEADERS  += qcvwidget.h \
    opencvworker.h

FORMS    += qcvwidget.ui

INCLUDEPATH += C:\Software\build\opencv\install\include\x64\vc12\lib
#LIBS += C:\Software\build\opencv\install\include\x64\vc12\lib\opencv_calib3d310.lib
#LIBS +=  opencv_calib3d310.lib
#LIBS += C:/Software/build/opencv/install/include/x64/vc12/lib/opencv_calib3d310.lib
