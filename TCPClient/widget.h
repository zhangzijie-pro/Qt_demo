#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QHostAddress>
#include <QTcpSocket>
#include <QMessageBox>
#include <chat.h>

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
    void on_canclebtn_clicked();

    void on_btnconnect_clicked();

private:
    Ui::Widget *ui;
    QTcpSocket *socket;
};

#endif // WIDGET_H
