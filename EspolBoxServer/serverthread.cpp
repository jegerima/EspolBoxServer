#include "serverthread.h"

ServerThread::ServerThread(qintptr ID, QObject *parent):
    QThread(parent)
{
    this->scktDescriptor = ID;
    this->FileIN = false;
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
    int LetsFile = 0;
    QByteArray data = sckt->readAll();

    LetsFile = txtp->parse(data);



    if(LetsFile == 2)
    {
        this->FileIN = true;
        qDebug() << "setboxdir#GO";
        sckt->write("#setboxdir#go");
        return;
    }
    if(LetsFile==-2)
    {
        this->FileIN = false;
        qDebug() << getFileDataSize();
        generateFiles();
        qDebug() << "SetBoxDir#Sync#Done";
        return;
    }
    if(LetsFile==-4)
    {
        sckt->write("#setboxdir#nouser");
    }
    if(LetsFile==5)
    {
        sckt->write("#cuser#ok");
    }
    if(LetsFile==-5)
    {
        sckt->write("#cuser#fail");
    }
    if(LetsFile==-6)
    {
        sckt->write("#setboxdir#exists");
    }

    if(!FileIN)
        qDebug() << "IDClient: " << scktDescriptor << " Data in: " << data;
    else
        gettingFilesBytes(data);
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


