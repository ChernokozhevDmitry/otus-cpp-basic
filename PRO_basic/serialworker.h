#ifndef SERIALWORKER_H
#define SERIALWORKER_H

#include <QObject>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QThread>
#include <QDebug>
#include "UART_tools.h"

class SerialWorker : public QObject // для работы с ком портом и устройством, в процессе стало понятно, что желательно сделать 2 класса - чисто коп порты, чисто устройство
{
    Q_OBJECT
public:
    explicit SerialWorker(QObject *parent = nullptr);
    ~SerialWorker();
    bool OpenCOMPort();
    void CloseCOMPort();
    void init();

signals:
    void logRx(QByteArray data);

private slots:
    void readData(); // читаем данные


public:
    QSerialPort* m_port;

//public slots:
//    void doDataSendWork(const QByteArray data);
//    void doDataReciveWork();

//private:
//    QSerialPort* serialport;
};

#endif // SERIALWORKER_H
