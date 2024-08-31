#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_canclebtn_clicked()
{
    this->close();
}

void Widget::on_btnconnect_clicked()
{
    // IP
    QString ip = ui->ip->text();
    // Port
    QString port = ui->port->text();

    // 连接服务器
    socket->connectToHost(QHostAddress(ip),port.toShort());

    // 连接成功
    connect(socket,&QTcpSocket::connected,[this](){
        QMessageBox::information(this,"提示","连接成功");

        this->hide();
        chat *c = new chat(socket);
        c->show();
    });

    // 连接断开异常提示
    connect(socket,&QTcpSocket::disconnected,[this](){
        QMessageBox::warning(this,"warning","网络异常 连接断开");
    });



}
