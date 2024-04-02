#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QDateTime>
#include <QMessageBox>
#include <QThread>
#include <QDebug>
#include "UART_tools.h"
#include "serialworker.h"
#include "CRC.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private:
    void SearchSerialPort(); // находим доступные COM порты

private slots:
    void on_btn_OpenCOMPort_clicked(); // подключаемся к COM порту
    void onLogRX(QByteArray data);



private:
    Ui::MainWindow *ui;
    SerialWorker* serialworker; // Инициализация serialworker
    QThread* m_thread; // Инициализация потока

    struct {
       uint16_t T_loop = 1000;  // период опроса прибора (мсек)
       uint8_t k_heater = 0;        // коэффициент термоанемометра 0..4 (0 - выключен)
       uint8_t k_lm = 1;            // коэффициент усиления сигнала локатора муфт 1..4
       uint8_t k_sh = 1;            // коэффициент усиления сигнала шумомера 1..4
       uint8_t qn_ch = 20;           // число каналов прибора
       uint8_t ch_array[20] = {0x06, 0x07, 0x08, 0x09, 0x0a,
                                0x0b, 0x0c, 0x0d, 0x0e, 0x0f,
                                0x10, 0x11, 0x12, 0x13, 0x14,
                                0x16, 0x40, 0x41, 0x42, 0x43};    // номера каналов прибора в hex
    } sSettings;

    struct {
        uint8_t cn;
        uint8_t step_load;
    } sPackRxLog;

    uint8_t zero_data=0x00;
    uint8_t start_loop=0x01;
    uint8_t stop_loop=0x00;
    int is_iniitalizeted;

    S_BufferUART sBufferRx;
    S_Pack sPackRx, sPackTx;

//    sLoopData_StrTypeDef sLoopData;
//    snQueData_StrTypeDef snQueData;

    void WriteBufferRx(uint8_t data);
    void CheckPackRx(void);
};
#endif // MAINWINDOW_H
