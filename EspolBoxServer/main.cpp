#include <QCoreApplication>
#include <espolboxserver.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    EspolBoxServer msv;
    msv.StartServer();

    return a.exec();
}
