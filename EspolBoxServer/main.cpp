#include <QCoreApplication>
#include <espolboxserver.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    setCURRENT_DIR("/home/jegerima/Server");
    EspolBoxServer msv;
    msv.StartServer();

    return a.exec();
}
