#ifndef CLIENT_SOCKET_H
#define CLIENT_SOCKET_H


#include <iostream>
#include <winsock2.h>
#include <windows.h>
#include <ws2tcpip.h>
#include <stdio.h>
#include <stdlib.h>

#include <thread>
#include <chrono>



class Client
{

private:
    WSAData wsaData;
    sockaddr_in direccion_client_socket;
    char buffer [1024]; //size of message
    std::string string_message;
    int wsa_start;
    int cliente_socket;
    int server_socket;



public:
    void create_client();
    void send_data();
    void recieve_data ();
    void create_recieve_thread();

};

#endif // CLIENT_SOCKET_H
