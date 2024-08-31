#ifndef CHAT_H
#define CHAT_H

#include <QWidget>
#include <QTcpSocket>

namespace Ui {
class chat;
}

class chat : public QWidget
{
    Q_OBJECT

public:
    explicit chat(QTcpSocket *s,QWidget *parent = nullptr);
    ~chat();

private slots:
    void on_canclebtn_clicked();

    void on_sendbtn_clicked();

private:
    Ui::chat *ui;
    QTcpSocket *socket;
};

#endif // CHAT_H
