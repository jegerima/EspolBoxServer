#ifndef SERVERTHREAD_H
#define SERVERTHREAD_H

#include <QThread>
#include <QTcpSocket>
#include <QDebug>
#include <textparser.h>
#include <libs.h>

class ServerThread : public QThread
{
    Q_OBJECT
public:
    explicit ServerThread(qintptr ID, QObject *parent = 0);
    void run();

signals:
    void error(QTcpSocket::SocketError scktError);
    //void SendString(QString qs);

public slots:
    void readyRead();
    void disconnected();

private:
    QTcpSocket *sckt;
    textparser *txtp;
    int scktDescriptor;
    bool FileIN;
};

#endif // SERVERTHREAD_H
