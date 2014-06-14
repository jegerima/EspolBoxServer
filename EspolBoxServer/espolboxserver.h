#ifndef ESPOLBOXSERVER_H
#define ESPOLBOXSERVER_H

//bogo.com/cplusplus/sockets_server_client_QT.php

#include <QObject>
#include <QDebug>
#include <QtNetwork/QTcpServer>
#include <QtNetwork/QTcpSocket>
#include <serverthread.h>

class EspolBoxServer : public QTcpServer
{
    Q_OBJECT
public:
    explicit EspolBoxServer(QObject *parent = 0);
    void StartServer();

signals:

public slots:
    //void incomingConnection(int scktID);

private:
   // QTcpServer *sv;

protected:
    void incomingConnection(qintptr scktID);
};

#endif // ESPOLBOXSERVER_H
