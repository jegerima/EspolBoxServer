#include "serialfile.h"

//http://stackoverflow.com/questions/13835197/serializing-my-custom-class-in-qt

SerialFile::SerialFile(QObject *parent) :
    QObject(parent)
{

}
/*
QDataStream &operator<<(QDataStream &ds, const SerialFile &obj)
{
    for(int i=0; i<obj.metaObject()->propertyCount(); ++i)
    {
        if(obj.metaObject()->property(i).isStored(&obj))
        {
            ds << obj.metaObject()->property(i).read(&obj);

        }
    }
    return ds;
}

QDataStream &operator>>(QDataStream &ds, SerialFile &obj)
{
    QVariant var;
        for(int i=0; i<obj.metaObject()->propertyCount(); ++i)
        {
            if(obj.metaObject()->property(i).isStored(&obj))
            {
                ds >> var;
                obj.metaObject()->property(i).write(&obj, var);
        }
   }
   return ds;
}
*/
