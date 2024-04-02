#include "serialworker.h"

SerialWorker::SerialWorker(QObject *parent) : QObject(parent)
{
    qDebug("Ctor SerialWorker");
    m_port = new QSerialPort(this);
    OpenCOMPort();
}

SerialWorker::~SerialWorker()
{
    qDebug("Dtor SerialWorker");
    delete m_port;
}

bool SerialWorker::OpenCOMPort()
{
    if (!m_port->isOpen()) {
        m_port->setPortName(QString(strPortName));
        m_port->setBaudRate(QSerialPort::Baud115200);
        m_port->setStopBits(QSerialPort::OneStop);
        m_port->setDataBits(QSerialPort::Data8);
        m_port->setFlowControl(QSerialPort::NoFlowControl);
        m_port->setParity(QSerialPort::NoParity);
    }
    if(!m_port->open(QIODevice::ReadWrite)) {
        qDebug() << "Do not connect to " << strPortName;
        return false;
    }
    else {
        qDebug() << "Connect to " << strPortName;
    }
//    init();
    return true;
}

void SerialWorker::CloseCOMPort()
{
    qDebug("SerialWorker::CloseCOMPort");
    if(m_port->isOpen()){
        m_port->close();
    }
}

void SerialWorker::init()
{
    qDebug("SerialWorker::Init");
    if(m_port->isOpen()){
        connect(m_port, &QSerialPort::readyRead, this, &SerialWorker::readData); // запуск приема данных с устройства
        qDebug("SerialWorker::Init::StartReadData");
    }
    else {
        qDebug("SerialWorker::Init::Something wrong, do not open port");
    }
}


void SerialWorker::readData()
{
    QByteArray data = m_port->readAll();
//    emit increaseRxCount(data.count());
    emit logRx(data);
}


//void SerialWorker::doDataSendWork(const QByteArray data)
//{
//    qDebug() <<  "Subline slot function sends data:" << data << "Thread ID:" << QThread::currentThreadId();

//    // send data
//    serialport->write(data);
//}

//void SerialWorker::doDataReciveWork()
//{
//    // 1. Receive data
//    QByteArray buffer = serialport->readAll();

//    // 2. Data processing
//    QString resultStr = buffer;
//    qDebug() <<  "Sub-thread received data:" << resultStr << "Thread ID:" << QThread::currentThreadId();

//    // 3. Send the result to the main thread
//    emit sendResultToGui(resultStr);
//}
