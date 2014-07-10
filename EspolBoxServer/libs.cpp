#include "libs.h"
#include <QThread>

QString CURRENT_DIR;
QString CURRENT_USER;
QString RELATIVE_DIR;
QByteArray FileData;
QStringList Users;

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

void gettingFilesBytes(QByteArray ba)
{
    qDebug() << "SIZE DATA ARRIVED :" + QString::number(ba.size());
    FileData.append(ba);
    qDebug() << "Listo";
/*
    for(int i = 0; i<baList.size(); i++)
    {
        baa = baList.at(i);
        baFile = baa.split('%');
        if(baFile.size()<2)
            return;
        qDebug() << "NAME: " + baFile.at(0);
        qDebug() << "DIR: " + baFile.at(1);
        qDebug() << "BYTES: " + QString::number(baFile.at(2).size());
    }
    /*
    QString Fname(baList.at(0));
    qDebug() << "NAME: "+ Fname;
    QString Fdir(baList.at(1));
    qDebug() << "DIR: " + Fdir;
    qDebug() << "BYTES: " + QString::number(baList.at(2).size());
    qDebug() << "Saving File "+Fname;
    QFile fl(getCURRENT_DIR() + Fdir + "/"+ Fname);
    fl.open(QIODevice::WriteOnly);
    fl.write(baList.at(2));
    //QThread::msleep(1000);
    fl.close();
    qDebug() << "File saved in " + getCURRENT_DIR() + Fdir + "/" + Fname;
    //qDebug() << "DATA: " + baList.at(2);
    */
}

void generateFiles()
{

    QList<QByteArray> PacketsList = FileData.split('~');
    QList<QByteArray> File;// = PacketsList.at(0).split('%');
    qDebug() << "Paquetes: "+QString::number(PacketsList.size()-1);
    for(int i = 0; i<(PacketsList.size()-1);i++)
    {
        File = PacketsList.at(i).split('%');
        //qDebug() << "Tokens: " + QString::number(File.size());
        if(File.size()==4)
        {
            /* 0 Usuario
             * 1 RutaRelativa
             * 2 NombreArchivo
             * 3 Data
             */
            qDebug() << "Archivo " + File.at(2) + " en " + File.at(1) + " de " + File.at(0);
            QString FullPath(getCURRENT_DIR()+"/"+ File.at(0) + File.at(1) +"/"+ File.at(2));
            qDebug() << FullPath;
            QFile tmp(FullPath);
            tmp.open(QIODevice::WriteOnly);
            tmp.write(File.at(3));
            tmp.close();
        }
        else
            qDebug() << PacketsList.at(i);
    }
    resetFileData();
}

int getFileDataSize()
{
    return FileData.size();
}

void resetFileData()
{
    FileData.clear();
}

QStringList getDirectoryDirs(QString dir)
{
    QDir dirFiles(dir);
    QStringList allDirs = dirFiles.entryList(QDir::NoDotAndDotDot | QDir::AllDirs);
    return allDirs;
}

void getUsers()
{
    Users = getDirectoryDirs(getCURRENT_DIR());
}

bool UserExists(QString name)
{
    getUsers();
    for(int i = 0; i < Users.size(); i++)
    {
        if(name == Users.at(i))
            return true;
    }
    return false;
}

int newDirectory(QString str)
{
    if(PathExists(str) == -1)
    {
        //http://linux.die.net/man/2/stat

        mkdir(QStringToChar(str),0700);
        printf("Directorio creado exitosamente\n");
        return 1;
    }
    else
    {
        printf("Directorio existente\n");
    }
    return 0;
}

int newUser(QString str)
{
    QString splbxPath = getCURRENT_DIR() + "/" + str;
    qDebug() << splbxPath;

    if(PathExists(splbxPath) == -1)
    {
        //http://linux.die.net/man/2/stat

        mkdir(QStringToChar(splbxPath),0700);
        printf("Directorio creado exitosamente\n");
        return 1;
    }
    else
    {
        printf("Directorio existente\n");
    }
    return 0;
}

void addUser(QString usr)
{
    Users.append(usr);
}
