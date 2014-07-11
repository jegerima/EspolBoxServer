#include <QCoreApplication>
#include <espolboxserver.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString homePath = getenv("HOME");
    homePath = homePath + "/ESPOLBOXSERVER";
    newDirectory(homePath);
    setCURRENT_DIR(homePath);
    EspolBoxServer msv;
    msv.StartServer();

    return a.exec();
}
