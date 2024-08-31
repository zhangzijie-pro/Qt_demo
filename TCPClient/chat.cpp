#include "chat.h"
#include "ui_chat.h"

chat::chat(QTcpSocket *s,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::chat)
{
    ui->setupUi(this);

    socket = s;
}

chat::~chat()
{
    delete ui;
}

void chat::on_canclebtn_clicked()
{
    ui->messagge->clear();
}

void chat::on_sendbtn_clicked()
{
    QByteArray ba;
    ba.append(ui->messagge->text());
    socket->write(ba);
}
