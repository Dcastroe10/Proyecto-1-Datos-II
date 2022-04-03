#include "client.h"
#include "server.cpp"


#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include <iostream>

int main(int argc, char *argv[])
{
    std::cout << "holas holas";
    QApplication a(argc, argv);
    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "Proyecto-1-Datos-II-Daniel-C_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }
   Client w;
   w.show();

    return a.exec();
}
