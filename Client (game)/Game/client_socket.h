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



class Client
{

private:
    WSAData wsaData;
    sockaddr_in direccion_client_socket;
    char buffer [200000]; //because of the size of the images  40000
    char image [200000]; //because of the size of the images
    std::string string_message;
    int wsa_start;
    int cliente_socket;
    int server_socket;
    int order = 30;




public:
    void create_client();

    void send_data(char mensaje[1000
    ]);


    void recieve_data ();
    void create_recieve_thread();
    char* get_image();
    int get_order();
    void reset_order();

};

#endif // CLIENT_SOCKET_H
