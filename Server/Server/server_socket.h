#ifndef SERVER_SOCKET_H
#define SERVER_SOCKET_H

#include <iostream>
#include <string>
#include <winsock2.h>
#include <windows.h>
#include <ws2tcpip.h>
#include <stdio.h>
#include <thread>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>


#include <QImage>

#include <QtDebug>


#include <unistd.h>
#include <cstdlib>


#pragma comment (lib, "Ws2_32.lib")
#define PORT_PORT 1337




class Server_socket {
public:
    WSAData wsaData;
    int wsa_start;
    std::string ip = "127.0.0.1";
    struct sockaddr_in server_addr;     //STRUCTS
    struct sockaddr_in client_addr;
    //std::string string_message;
    int revisar_bind = 0;
    int revisar_listen = 0;

    int server_socket;
    int client_socket = 10;
    char buffer [40000]; //for the images


    int button_pressed = 30;



public:
    void Start ();

    void connect();

    void recieve_data ();

    void send_data(char path[], int size);             ///////////////

    void create_recieve_thread();

    int get_button_pressed();

    void reset_button_pressed();


};



#endif // SERVER_SOCKET_H
