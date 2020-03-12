#ifndef CAPTURETHREAD_H
#define CAPTURETHREAD_H

#include <QThread>
#include <QImage>
#include "global.h"
#include "camconfig.h"
#include "imagebuffer.h"

class CaptureThread : public QThread
{
    Q_OBJECT
public:
    explicit CaptureThread(ImageBuffer* pImageBuffer = nullptr, QObject* parent = nullptr);
    ~CaptureThread();

signals:
    void            updateImage(QImage);
    void            updateAtmosphericLight(float, float, float);

protected:
    void            run();

private:
    CamConfig*      m_pConfig;
    ImageBuffer*    m_pImageBuffer;
    bool            m_bUpdateAtmosphericLight;

    std::tuple<bool,std::vector<uint8_t>,uint64_t,uint64_t,uint64_t>
        decodeJpeg2X(uint8_t* pJpegData,uint64_t JpegdataSize,const char* convrt_flag);

public slots:
    void calcAtmosphericLight();
};

#endif // CAPTURETHREAD_H
