#ifndef SERIALFILE_H
#define SERIALFILE_H

#include <QObject>
#include <QVariant>
#include <QDataStream>

class SerialFile : public QObject
{
    Q_OBJECT
public:
    explicit SerialFile(QObject *parent = 0);

signals:

public slots:

};
/*
QDataStream &operator<<(QDataStream &ds, const SerialFile &obj);
QDataStream &operator>>(QDataStream &ds, SerialFile &obj);
*/
#endif // SERIALFILE_H
