#include "espolboxserver.h"

EspolBoxServer::EspolBoxServer(QObject *parent) :
    QTcpServer(parent)
{
    getUsers();

}

void EspolBoxServer::StartServer()
{
    int port = 1042;

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

//---------------------------------------


