#include "server_socket.h"
#include "server.h"

#include <iostream>

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Server w;
    w.show();
    return a.exec();

}
