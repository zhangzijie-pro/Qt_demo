#ifndef CLIENTHANDLER_H
#define CLIENTHANDLER_H

#include <QObject>
#include <QTcpSocket>

class ClientHandler : public QObject
{
    Q_OBJECT
public:
    explicit ClientHandler(int sockfd,QObject *parent = nullptr);


private slots:
    void receInfo();

signals:

public slots:
    void working();

private:
    qintptr handle;
    QTcpSocket *socket;
};

#endif // CLIENTHANDLER_H
