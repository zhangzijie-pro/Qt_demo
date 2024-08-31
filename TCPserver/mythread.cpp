#include "mythread.h"

mythread::mythread(QTcpSocket *s)
{
    socket = s;
}

void mythread::run()
{
    connect(socket,&QTcpSocket::readyRead,this,&mythread::clientInfoSlot);

}

// 不能在其他类里面操作界面
void mythread::clientInfoSlot()
{
    // qDebug() << socket->readAll();
    QByteArray ba = socket->readAll();
    emit sendToWidget(ba);      // 发送信号
}
