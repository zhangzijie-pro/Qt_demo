#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QObject>
#include <QThread>
#include <QTcpSocket>

class mythread : public QThread
{
    Q_OBJECT
public:
    explicit mythread(QTcpSocket *s);
    void run();             // 线程处理函数

signals:
    void sendToWidget(QByteArray b);        // 自定义信号

public slots:
    void clientInfoSlot();

private:
    QTcpSocket *socket;
};

#endif // MYTHREAD_H
