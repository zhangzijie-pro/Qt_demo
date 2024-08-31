#include "clienthandler.h"

ClientHandler::ClientHandler(int sockfd,QObject *parent) : QObject(parent)
{
    this->handle = sockfd;

}

void ClientHandler::working(){
    socket = new QTcpSocket;
    socket->setSocketDescriptor(handle);

    connect(socket,&QTcpSocket::readyRead,this,&ClientHandler::receInfo);

}

void ClientHandler::receInfo(){
    qDebug() << socket->readAll();
}
