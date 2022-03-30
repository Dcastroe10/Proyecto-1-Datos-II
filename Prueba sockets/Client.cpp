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
    sockaddr_in direccion_client_socket;
    //SOCKET servidor;

    char buffer [1024]; //size of message
    std::string string_message;

    int wsa_start;
    int cliente_socket;
    int server_socket;

public:
    void create_client(){
        wsa_start = WSAStartup(MAKEWORD(2,2), &wsaData);
        cliente_socket = socket(AF_INET, SOCK_STREAM,0);

        memset(&direccion_client_socket, 0, sizeof(direccion_client_socket));


        direccion_client_socket.sin_family = AF_INET;
        direccion_client_socket.sin_addr.s_addr = inet_addr("127.0.0.1");
        direccion_client_socket.sin_port = htons(9090);


        int conexion = connect(cliente_socket,(sockaddr*)&direccion_client_socket, sizeof (direccion_client_socket));
        std::cout<<WSAGetLastError();
        std::cout <<"\n"<<conexion<<"esta es el int conexion";
        if (wsa_start != 0){
            printf("Error del WSASTARTUP");
            WSACleanup();
        }else{
            if(cliente_socket == INVALID_SOCKET){
                std::cout <<"ERROR AL INICIAR EL CLIENTE SOCKET";
        }else{
               std::cout <<"PARECE QUE TODO SE INICIO BIEN";
            }
        }

        std::cout <<wsa_start;
        std::cout <<" <----ESTE ES EL WSAAAAAA";
    }


    void send_data(){  //cambiar el tipo de dato si quiero retornar algo!!!!!!!!
        std::cout <<"Que desea enviar el CLIENTE? ";
        //std::cin >> this->buffer;  //para ingresar el mensaje
        std::cin >> this->buffer;
        std::cout <<"this is the message to be sent: "<<buffer<< "\n";//std::cout << buffer << " CLIENTE, este es su mensaje???";
        send(cliente_socket, buffer, sizeof(buffer), 0 );//revisar si aquí va server o client (del que se manda o al que se manda!!!
        //memset(buffer,0, sizeof(buffer));  //REINICIAR BUFFER CON LA ENTRADA!!!!

    }

    void recieve_data () { //cambiar el tipo de dato si quiero retornar algo!!!!!!!!
        //memset(buffer,0, sizeof(buffer));  //REINICIAR BUFFER CON LA ENTRADA!!!!
        char mensaje;
        mensaje = recv(server_socket,buffer, sizeof(buffer),0);//CAMBIAR EL SERVEEEEER QUE SOLO ESTÁ EN UNA VARIABLE INT PROVISIONAL
        std::cout <<"El SERVER dice: " << buffer<< " <---\n";
        std::cout << "-> " <<mensaje<< " <- esto es el recieve";


    }


    void close_all(){
        closesocket(cliente_socket);
        std::cout <<"se cerró todo";
    }

};

int main() {
    Client cliente;
    cliente.create_client();
    cliente.send_data();
    cliente.send_data();



    return 0;
}




