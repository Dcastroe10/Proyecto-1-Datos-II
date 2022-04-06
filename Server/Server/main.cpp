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



    //Client cliente;

    //cliente.create_client();


    //////////////////////


    //////////////////////

    //servidor.send_data();


    //servidor.recieve_data();
    //servidor.send_data();


    //servidor.recieve_data();
    //servidor.send_data();




    //servidor.create_recieve_thread();
    //std::cout <<"SERÁ QUE LLEGA HASTA AQUÍ??";


}
