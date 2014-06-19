#include "serverthread.h"

ServerThread::ServerThread(qintptr ID, QObject *parent):
    QThread(parent)
{
    this->scktDescriptor = ID;
    txtp = new textparser("");
}

void ServerThread::run()
{
    char msj[30];
    //El hilo empieza desde aqui
    qDebug() << "Thread Started";
    sckt = new QTcpSocket();

    if(!sckt->setSocketDescriptor(this->scktDescriptor))
    {
        emit error(sckt->error());
        return;
    }

    connect(sckt,SIGNAL(readyRead()),this,SLOT(readyRead()),Qt::DirectConnection);
    connect(sckt,SIGNAL(disconnected()),this,SLOT(disconnected()));

    qDebug() << scktDescriptor << "Client connected";
    sprintf(msj,"Conexion establecida. ID = %d.",scktDescriptor);
    sckt->write(msj);

    //Con esto, el hilo se mantiene
    exec();
}

void ServerThread::readyRead()
{
    QByteArray data = sckt->readAll();

    qDebug() << "IDClient: " << scktDescriptor << ".Data in: " << data;

    txtp->parse(data);
    //sckt->write(data);
}

void ServerThread::disconnected()
{
    qDebug() << scktDescriptor << " Disconnected";
    sckt->deleteLater();
    exit(0);
}

/*void ServerThread::SendString(QString qs)
{
    sckt->write(QStringToChar(qs));
}*/


