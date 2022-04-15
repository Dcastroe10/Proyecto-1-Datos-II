#include "game_window.h"
#include "client_socket.h"
#include "operation_center.h"

#include <QApplication>

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
        game_window w;
        w.show();
        return a.exec();

}
