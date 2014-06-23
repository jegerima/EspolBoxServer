#include "libs.h"
#include <QThread>

QString CURRENT_DIR;
QString CURRENT_USER;
QString RELATIVE_DIR;
int xyz = 0;


char *QStringToChar(QString str)
{
    QByteArray ba = str.toLatin1();
    char *c = ba.data();
    return c;
}

/*
 * Devuelve -1 si la ruta no existe
 * Caso contrario devuelve 0
 */
int PathExists(QString str)
{
    //http://linux.die.net/man/2/mkdir

    struct stat st = {0};
    return stat(QStringToChar(str),&st);
}

void createFile(QString name, QByteArray ba)
{
    QFile fl(name);
    fl.open(QIODevice::WriteOnly);
    fl.write(ba);
    fl.close();
}

void setCURRENT_DIR(QString qs)
{
    CURRENT_DIR = qs;
}

void setCURRENT_USER(QString qs)
{
    CURRENT_DIR = qs;
}

void setRELATIVE_DIR(QString qs)
{
    CURRENT_DIR = qs;
}

QString getCURRENT_DIR()
{
    return CURRENT_DIR;
}

QString getCURRENT_USER()
{
    return CURRENT_USER;
}

QString getRELATIVE_DIR()
{
    return RELATIVE_DIR;
}

void generateFiles(QByteArray ba)
{
/*
    //QHash<QString,QString> FileProp;
    QString a;
    a.setNum(xyz);

    qDebug() << getCURRENT_DIR();
    QFile tmp(getCURRENT_DIR() + "/tmp"+a+".JPG");
    tmp.open(QIODevice::WriteOnly);
    tmp.write(ba);
    tmp.close();

    QFile archivo(tmp.fileName());
    archivo.open(QIODevice::WriteOnly);
    archivo.write(ba);
    //QThread::msleep(500);
    archivo.close();

    //QDataStream in(&tmp);
    //in>>FileProp;

    //if(FileProp.isEmpty())
    //    qDebug() << "Hash Vacio";
    //qDebug() << "Nombre: "+FileProp.value("NAME");
    //qDebug() << "Relative dir: "+FileProp.value("RELATIVEDIR");

    //qDebug("---------------------------------");
    xyz++;
*/
    QList<QByteArray> baList = ba.split('#');
    QString Fname(baList.at(0));
    qDebug() << "NAME: "+ Fname;
    QString Fdir(baList.at(1));
    qDebug() << "DIR: " + Fdir;
    qDebug() << "DATA: " + baList.at(2);
}
