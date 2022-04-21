#ifndef CLIENT_SOCKET_H
#define CLIENT_SOCKET_H


#include <iostream>
#include <winsock2.h>
#include <windows.h>
#include <ws2tcpip.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <thread>
#include <chrono>
#include <unistd.h>
#include <QString>
#include <QDebug>



class Client
{

private:
    WSAData wsaData;
    sockaddr_in direccion_client_socket;
    char buffer [200000]; //More than the size of the images to prevention
    char image [200000]; //More than the size of the images for prevention
    QString jugador_1;
    QString jugador_2;
    int wsa_start;
    int cliente_socket;
    int server_socket;
    int order = 30;



public:
    void create_client();
    void send_data(char mensaje[1000]);
    void recieve_data ();
    void create_recieve_thread();
    void reset_order();
    void set_order(int num);
    char* get_image();
    int get_order();
    QString get_player1();
    QString get_player2();

};

#endif // CLIENT_SOCKET_H
