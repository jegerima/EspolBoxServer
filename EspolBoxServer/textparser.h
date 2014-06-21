#ifndef TEXTPARSER_H
#define TEXTPARSER_H


#include <QString>
#include <QRegularExpression>
#include <QThread>
#include <QStringList>

class textparser
{
public:
    textparser(QString txt);
    int parse(QString txt);
    int createUser(QString usr);
    int syncDir(QString usr,QString pth);
    int setBoxDir(QString usr,QString dir);

private:
    //QThread *hilo;
};

#endif // TEXTPARSER_H
