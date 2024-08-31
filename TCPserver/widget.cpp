#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    server = new QTcpServer;

    server->listen(QHostAddress::AnyIPv4, PORT);

    // 客户端发起连接，server发出信号
    connect(server,&QTcpServer::newConnection,this,&Widget::newClientHandler);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::newClientHandler()
{
    // 建立TCP连接
    QTcpSocket *socket = server->nextPendingConnection();

    socket->peerAddress();  // 获取客户端地址
    socket->peerPort();     // 获取客户端端口号

    ui->ip->setText(socket->peerAddress().toString());
    ui->port->setText(QString::number(socket->peerPort()));

    // 服务器收到客户端发送的消息，socket发出readyread信号
    //connect(socket,&QTcpSocket::readyRead,this,&Widget::clientInfoSlot);

    // 启动线程
    mythread *t = new mythread(socket);   // 创建线程对象
    t->start();                           // 开启线程

    connect(t,&mythread::sendToWidget,this,&Widget::threadSlot);
}

/*void Widget::clientInfoSlot(){
    // 获取信号的发出者
    QTcpSocket *s = (QTcpSocket *)sender();
    ui->mainmessage->setText(QString(s->readAll()));
}*/

void Widget::threadSlot(QByteArray b)
{
    ui->mainmessage->setText(QString(b));
}
