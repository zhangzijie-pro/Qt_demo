#include "mytcpserver.h"
#include "clienthandler.h"
#include <QThread>

mytcpserver::mytcpserver(QObject *parent) : QTcpServer(parent)
{

}


void mytcpserver::incomingConnection(qintptr handle){
    // 启动线程 2
    QThread *subThread = new QThread;               // 线程对象
    // socket不能跨线程使用
    ClientHandler *myclient = new ClientHandler(handle);    // 事件对象

    myclient->moveToThread(subThread);                      // !!important

    subThread->start();     // 启动

    connect(this,&mytcpserver::signal_to_thread, myclient, &ClientHandler::working);
    emit signal_to_thread();
}
