#include "textparser.h"
#include <file.h>
#include <QDebug>

textparser::textparser(QString txt)
{
    //cs = new ClientSocket(0,QString("192.168.1.6"),QString("Vacila la mac"));
}

int textparser::parse(QString txt)
{
    QStringList argsList = txt.split(" ");

    if(argsList.at(0) == "cuser")      // cuser usuario hash
        return createUser(argsList.at(1));
    if(argsList.at(0) == "sync")       // sync usuario /ruta/del/archivo
        return syncDir(argsList.at(1), argsList.at(2));
    if(argsList.at(0) == "setboxdir")  // setboxdir usuario nombreCarpeta
        return setBoxDir(argsList.at(1),argsList.at(2));
    if(argsList.at(0) == "syncDONE")
    {
        qDebug() << "NO MAS ARCHIVOS";
        return 3;
    }
    //Default
    qDebug() << "Text not parsed";
    return 0;
}

int textparser::createUser(QString usr)
{
    qDebug() << "User "+usr+" created.";
    return 0;
}

int textparser::setBoxDir(QString usr, QString dir)
{
    qDebug() << "Dir "+dir+" setted for user "+usr;
    return 0;
}

int textparser::syncDir(QString usr, QString pth)
{
    qDebug() << "Sync "+pth+ "for user "+usr;
    return 2;
}

