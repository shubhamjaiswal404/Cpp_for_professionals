#include <QCoreApplication>
#include <QLocale>
#include <QTranslator>

#include "mytcpserver.h"
#include"myconnectrun.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "myQtTcpServer_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }




    //initialize Object of MyTcpServer
    MyTcpServer server;

    server.startServer();


    return a.exec();
}
