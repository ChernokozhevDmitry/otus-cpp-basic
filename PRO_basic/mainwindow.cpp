#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_thread = new QThread(); // Создается поток
    serialworker = new SerialWorker(); // Создается объект класса SerialWorker
    serialworker->moveToThread(m_thread); // Помещается объект serialworker в поток

    connect(m_thread, &QThread::started, serialworker, &SerialWorker::init); // при старте потока init
    connect(m_thread, &QThread::finished, serialworker, &SerialWorker::deleteLater);
    connect(serialworker, &SerialWorker::logRx, this, &MainWindow::onLogRX);

    m_thread->start(); // Запускаем поток

}

MainWindow::~MainWindow()
{
    m_thread->quit(); // выходим из потока
//    delete serialworker; // здесь не нужно
    delete ui;
}

void MainWindow::on_btn_OpenCOMPort_clicked() // подключаемся к COM порту
{
    if (ui->btn_OpenCOMPort->text() == "Открыть COM порт") {
        serialworker->OpenCOMPort();
        ui->btn_OpenCOMPort->setText("Закрыть COM порт");
    }
    else {
        serialworker->CloseCOMPort();
        ui->btn_OpenCOMPort->setText("Открыть COM порт");
    }
}


void MainWindow::CheckPackRx(void) {
    uint8_t tmp;

    while ((sBufferRx.cn_in != sBufferRx.cn_out)) {
        *((uint8_t*)&sPackRx+sPackRxLog.cn)=sBufferRx.buf[sBufferRx.cn_out]; sPackRxLog.cn++;
        // инкремент счетчика считанных байт с контролем переходом через границу буфера
        sBufferRx.cn_out++; if (sBufferRx.cn_out >= SIZE_BUFF_UART) sBufferRx.cn_out=0;
        // формирование и распознавание пакета данных
        switch (sPackRxLog.step_load) {
    // поиск начала пакета
            case STEP_PREFIX:
                if (sPackRx.header.prefix==PREFIX)
                    sPackRxLog.step_load=STEP_HEADER;
                else
//                    ResetPackRxLog();
            break;
    // чтение заголовка пакета
            case STEP_HEADER:
                if (sPackRxLog.cn==HEADER_SIZE) {
// // // //                    if (sPackRx.header.qn_data > PACK_BUFFER_SIZE) ResetPackRxLog();
// // // //                    else {
                        if (sPackRx.header.qn_data) sPackRxLog.step_load=STEP_LOAD_PACK;
                        else {
//                            ParsePack();
//                            ResetPackRxLog();
                        }
//                    }
                }
            break;
     // чтение данных пакета
            case STEP_LOAD_PACK:
                if (sPackRxLog.cn == (sPackRx.header.qn_data + HEADER_SIZE)) {
                    tmp=CRC8(sPackRx.header.qn_data, sPackRx.data);
                    if (tmp==sPackRx.header.crc) {
//                        ParsePack();
//                        ResetPackRxLog();
                    }
//                    else ResetPackRxLog();
                }
            break;
        }
    }
}

void MainWindow::onLogRX(QByteArray data) {
        for(int i=0; i<data.size(); i++) {
            WriteBufferRx((uint8_t)data.at(i)) ;
        }

        CheckPackRx();

        QString s = "RxData <-   ";
        QDateTime tmp=QDateTime::currentDateTime();
        s += tmp.toString("HH:mm:ss.zzz")+ ": ";
        for(int i=0; i<data.size(); i++) {
            s+=QString::number((uint8_t)data.at(i), 16).toUpper().rightJustified(2,'0') + " ";
        }

        QTextEdit *te = MainWindow::ui->textedit_LogRX;
        //        QString s_log.append;
//        if (NewLine)
            te->append(s);
            te->append("----------------------");
//        else{

}

void MainWindow::WriteBufferRx(uint8_t data) {
    sBufferRx.buf[sBufferRx.cn_in]=data;
    sBufferRx.cn_in++;
    if (sBufferRx.cn_in>=SIZE_BUFF_UART) sBufferRx.cn_in=0;
}

