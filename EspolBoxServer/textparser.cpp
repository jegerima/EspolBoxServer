#include "textparser.h"
#include <QDebug>

textparser::textparser(QString txt)
{
    //cs = new ClientSocket(0,QString("192.168.1.6"),QString("Vacila la mac"));
}

int textparser::parse(QString txt)
{
    QStringList argsList = txt.split("#");

    if(argsList.at(0) == "cuser")      // cuser usuario hash
        return createUser(argsList.at(1));
    if(argsList.at(0) == "sync")       // sync usuario /ruta/del/archivo
        return syncDir(argsList.at(1), argsList.at(2));
    if(argsList.at(0) == "setboxdir")  // setboxdir usuario nombreCarpeta
        return setBoxDir(argsList.at(1),argsList.at(2));
    if(argsList.at(0) == "syncDONE")
    {
        qDebug() << "NO MAS ARCHIVOS";
        return -2;
    }
    //Default
    //qDebug() << "Text not parsed";
    return 0;
}

int textparser::createUser(QString usr)
{
    if(UserExists(usr))
        qDebug() << "Usuario ya existe";
    else
    {
        qDebug() << "User "+usr+" created.";
        if(newUser(usr)==1)
        {
            addUser(usr);
            return 5;
        }

    }
    return -5;
}

int textparser::setBoxDir(QString usr, QString dir)
{
    //qDebug() << "Dir "+dir+" setted for user "+usr;

    if(UserExists(usr))
    {
        QString fullPath = getCURRENT_DIR()+"/"+usr+dir;
        qDebug() << fullPath;
        if(PathExists(fullPath)==0)
        {
            return -6;
        }
        else
        {
            newDirectory(fullPath);
            return 2;
        }
    }
    return -4;
}

int textparser::syncDir(QString usr, QString pth)
{
    qDebug() << "Sync "+pth+ " for user "+usr;
    return 0;
}

