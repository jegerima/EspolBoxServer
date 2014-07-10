#ifndef LIBS_H
#define LIBS_H

#include <QDir>
#include <QFile>
#include <QList>
#include <QDebug>
#include <QString>
#include <QByteArray>
#include <QStringList>

#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>


char *QStringToChar(QString str);
int PathExists(QString str);
int newUser(QString str);
int newDirectory(QString str);
void createFile(QString name, QByteArray ba);
void setCURRENT_DIR(QString qs);
void setCURRENT_USER(QString qs);
void setRELATIVE_DIR(QString qs);
void generateFiles();
void gettingFilesBytes(QByteArray ba);
void resetFileData();
int getFileDataSize();

void addUser(QString usr);
bool UserExists(QString name);
void getUsers();

QString getCURRENT_DIR();
QString getCURRENT_USER();
QString getRELATIVE_DIR();

QStringList getDirectoryDirs(QString dir);

#endif // LIBS_H
