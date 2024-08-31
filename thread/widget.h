#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QHostAddress>
#include <QTcpSocket>
#include <QTcpServer>
#include "mytcpserver.h"

#define PORT 8000
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
//    void newClientHandler();
//    void clientInfoSlot();
    void threadSlot(QByteArray b);

private:
    Ui::Widget *ui;
    mytcpserver *server;
};

#endif // WIDGET_H
