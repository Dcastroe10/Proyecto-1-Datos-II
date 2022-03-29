#include "Client.h"
#include <iostream>
#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdio.h>
#include <stdlib.h>




class Client{
private:
    WSAData wsaData;
    SOCKET servidor;
    sockaddr_in direccion_client_socket;
    char buffer [1024]; //size of message
    std::string string_message;

    int wsa_start = WSAStartup(MAKEWORD(2,2), &wsaData);

    int client_socket = socket(AF_UNIX, SOCK_STREAM, 0); //AF_INET

public:
    void create_client(){
        servidor = socket(AF_INET, SOCK_STREAM,0);
        direccion_client_socket.sin_family = AF_UNIX; //AF_INET;
        direccion_client_socket.sin_addr.s_addr = inet_addr("127.0.0.1");
        direccion_client_socket.sin_port = htons(8080);
        std::cout <<wsa_start;
        std::cout <<"ESTE ES EL WSAAAAAA";
    }


    void send_data(){  //cambiar el tipo de dato si quiero retornar algo!!!!!!!!
        std::cout <<"Que desea enviar el CLIENTE? ";
        //std::cin >> this->buffer;  //para ingresar el mensaje
        std::cin >> this->string_message;
        std::cout << "\n";//std::cout << buffer << " CLIENTE, este es su mensaje???";
        send(servidor, buffer, sizeof(buffer), 0 );//revisar si aquí va server o client (del que se manda o al que se manda!!!
        //memset(buffer,0, sizeof(buffer));  //REINICIAR BUFFER CON LA ENTRADA!!!!

    }

    void recieve_data () { //cambiar el tipo de dato si quiero retornar algo!!!!!!!!
        //memset(buffer,0, sizeof(buffer));  //REINICIAR BUFFER CON LA ENTRADA!!!!
        char mensaje;
        mensaje = recv(servidor,buffer, sizeof(buffer),0);//RECIBIR MENSAJE   AQUI ESTÁ ERROR NO ESTÁ RECIBIENDOOO
        std::cout <<"El SERVER dice: " << buffer<< " <---\n";
        std::cout << "-> " <<mensaje<< " <- esto es el recieve";


    }


    void close_all(){
        closesocket(servidor);
        std::cout <<"se cerró todo";
    }

};



