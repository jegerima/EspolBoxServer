#ifndef LIBS_H
#define LIBS_H

#include <QFile>
#include <QList>
#include <QDebug>
#include <QString>
#include <QByteArray>

#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>


char *QStringToChar(QString str);
int PathExists(QString str);
void createFile(QString name, QByteArray ba);
void setCURRENT_DIR(QString qs);
void setCURRENT_USER(QString qs);
void setRELATIVE_DIR(QString qs);
void generateFiles(QByteArray ba);
QString getCURRENT_DIR();
QString getCURRENT_USER();
QString getRELATIVE_DIR();

#endif // LIBS_H
