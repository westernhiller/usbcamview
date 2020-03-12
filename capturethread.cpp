#include "capturethread.h"
#include "global.h"
#include "camdialog.h"
#include "darkchannel.h"

//#define USE_OPENCV_V4L2

#ifndef USE_OPENCV_V4L2
#include "v4l2capture.h"
#include "turbojpeg.h"
#include "jpegdecode.h"
#endif

using namespace std;
using namespace cv;

CaptureThread::CaptureThread(ImageBuffer* pImageBuffer, QObject* parent)
    : QThread(parent)
    , m_pImageBuffer(pImageBuffer)
    , m_bUpdateAtmosphericLight(true)
{
    m_pConfig = static_cast<CamDialog*>(parent)->getConfig();
}

CaptureThread::~CaptureThread()
{
    requestInterruption();
    quit();
    wait();
}

void CaptureThread::calcAtmosphericLight()
{
    m_bUpdateAtmosphericLight = true;
}

void CaptureThread::run()
{
    if(!m_pConfig || !m_pImageBuffer)
        return;

#ifdef USE_OPENCV_V4L2
    VideoCapture vcap(m_pConfig->camId().toStdString(), CAP_V4L2);
    if(!vcap.isOpened())
    {
        qDebug() << "failed openning camera";
        return;
    }
    vcap.set(cv::CAP_PROP_FRAME_WIDTH, IMAGEWIDTH);
    vcap.set(cv::CAP_PROP_FRAME_HEIGHT, IMAGEHEIGHT);
#else
    V4L2Capture *vcap = new V4L2Capture((char *)m_pConfig->camId().toStdString().data(), IMAGEWIDTH, IMAGEHEIGHT);
    vcap->openDevice();
    if(-1 == vcap->initDevice())
    {
        qDebug() << "failed init camera " << m_pConfig->camId();
        return;
    }
    vcap->startCapture();
    unsigned char *yuv422frame = nullptr;
    unsigned long yuvframeSize = 0;
#endif
    while (!isInterruptionRequested())
    {
#ifdef USE_OPENCV_V4L2
        Mat imgFrame;
        vcap >> imgFrame;
#else
        if(-1 != vcap->getFrame((void **) &yuv422frame, (int *)&yuvframeSize))
        {
            Mat imgFrame = Jpeg2Mat(yuv422frame, yuvframeSize);
#endif
            if(imgFrame.data)
            {
                FRAMEINFO frame;
                frame.matImg = imgFrame;
                frame.timeStamp = QDateTime::currentDateTime();
                m_pImageBuffer->writeImage(frame);
//                if(m_pImageBuffer->writeImage(frame))
//                    qDebug() << "capture write image ok";
//                else {
//                    qDebug() << "capture write image failed";
//                }

                if(m_bUpdateAtmosphericLight)
                {
                    m_bUpdateAtmosphericLight = false;
                    cv::Vec3f atmosphericLight = estimateAtmosphericLight(imgFrame);
                    emit updateAtmosphericLight(atmosphericLight[0], atmosphericLight[1], atmosphericLight[2]);
                }
                imgFrame.release();
            }
#ifndef USE_OPENCV_V4L2
        vcap->backFrame();
        }
#endif
        usleep(20000);
    }
}

