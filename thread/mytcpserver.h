#ifndef MYTCPSERVER_H
#define MYTCPSERVER_H

#include <QObject>
#include <QTcpServer>

class mytcpserver : public QTcpServer
{
    Q_OBJECT
public:
    explicit mytcpserver(QObject *parent = nullptr);

protected:
    void incomingConnection(qintptr handle);


signals:
    void signal_to_thread();


public slots:
};

#endif // MYTCPSERVER_H
