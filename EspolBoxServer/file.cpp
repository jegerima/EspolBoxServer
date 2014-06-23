#include "file.h"
#include <QDebug>

//http://stackoverflow.com/questions/13835197/serializing-my-custom-class-in-qt

file::file()
{
}

/*
 * http://stackoverflow.com/questions/7430248/creating-a-new-directory-in-c
 */
int file::newDirectory(QString str)
{
    QString homePath = getenv("HOME");
    //qDebug() << homePath;

    QString splbxPath = homePath + "/EspolBoxServer";
    //qDebug() << splbxPath;

    if(PathExists(splbxPath) == -1)
    {
        mkdir(QStringToChar(splbxPath),0700);
        //qDebug() << "Creando directorio: " + splbxPath;
    }

    QString path = splbxPath + "/" + str;
    //qDebug() << path;

    if(PathExists(path) == -1)
    {
        //http://linux.die.net/man/2/stat

        mkdir(QStringToChar(path),0700);
        qDebug() << "Directorio " << path << "creado exitosamente";
        return 1;
    }
    else
    {
        qDebug("Directorio de usuario existente.\n");
    }
    return 0;
}



