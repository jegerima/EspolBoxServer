#ifndef TEXTPARSER_H
#define TEXTPARSER_H


#include <QString>
#include <QRegularExpression>
#include <QThread>

class textparser
{
public:
    textparser(QString txt);
    int parse(QString txt);
    int firstParam(QString txt);
    int secondParam(QString txt);

private:
    //QThread *hilo;
};

#endif // TEXTPARSER_H
