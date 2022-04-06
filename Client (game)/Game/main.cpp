#include "game_window.h"
#include "client_socket.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    game_window w;
    w.show();
    game_window x;
    x.show();
    //Client cliente;
    //cliente.create_client();
    //cliente.send_data();

    return a.exec();
}
