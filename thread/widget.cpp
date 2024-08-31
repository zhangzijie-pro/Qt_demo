#include "widget.h"
#include "ui_widget.h"
#include <QThread>
#include "clienthandler.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    server = new mytcpserver;

    server->listen(QHostAddress::AnyIPv4, PORT);

    // 客户端发起连接，server发出信号
    //connect(server,&QTcpServer::newConnection,this,&Widget::newClientHandler);
}

Widget::~Widget()
{
    delete ui;
}


//void Widget::newClientHandler()
//{
//    ui->ip->setText(socket->peerAddress().toString());
//    ui->port->setText(QString::number(socket->peerPort()));
//}

/*void Widget::clientInfoSlot(){
    // 获取信号的发出者
    QTcpSocket *s = (QTcpSocket *)sender();
    ui->mainmessage->setText(QString(s->readAll()));
}*/

void Widget::threadSlot(QByteArray b)
{
    ui->mainmessage->setText(QString(b));
}
