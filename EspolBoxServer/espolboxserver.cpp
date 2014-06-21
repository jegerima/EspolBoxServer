#include "espolboxserver.h"

EspolBoxServer::EspolBoxServer(QObject *parent) :
    QTcpServer(parent)
{
    /*
    sv = new QTcpServer(this);
    connect(sv,SIGNAL(newConnection()),SLOT(newConnection()));

    if(!sv->listen(QHostAddress::Any,1021))
    {
        qDebug() << "Server could not start!";
    }
    else
    {
        qDebug() << "Server Started!";
    }
    */
}

void EspolBoxServer::StartServer()
{
    int port = 1023;

    if(!this->listen(QHostAddress::Any,port))
    {
        qDebug() << "Server could not start!";
    }
    else
    {
        qDebug() << "Listening... Port: " << port;
    }
    this->nextPendingConnection();
}

void EspolBoxServer::incomingConnection(qintptr scktID)
{
    qDebug() << scktID << " Connecting...";
    ServerThread *thread = new ServerThread(scktID, this);
    connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));
    thread->start();
}

