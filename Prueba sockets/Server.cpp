#include <iostream>
#include <string>
#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdio.h>
#include <thread>
#include <sys/types.h>

#include "Client.cpp"

#define PORT_PORT 9090;

#include <stdlib.h>
#include <stdio.h>


#pragma comment (lib, "Ws2_32.lib")


#define PORT_PORT 1337
class Server{
private:
    WSAData wsaData;
    int wsa_start;


    struct sockaddr_in server_addr;     //STRUCTS
    struct sockaddr_in client_addr;


    std::string string_message;


    int revisar_bind = 0;

    int server_socket = INVALID_SOCKET;
    int client_socket = 0; //CHANGE para poner varios maybeee o hacer otro


    //SOCKET servidor = INVALID_SOCKET;
    //SOCKET cliente = INVALID_SOCKET;


    char buffer [1024]; //size of messages
    //creo que me lo volé por el string pero revisar mejor

public:
    void Start () { //put always to start de server
        wsa_start = WSAStartup(MAKEWORD(2, 2), &wsaData);
        server_socket =  socket(AF_INET,SOCK_STREAM, 0); //AF_UNIX

        server_addr.sin_family = AF_UNIX;//AF_INET;
        server_addr.sin_addr.s_addr = htons(INADDR_ANY);//inet_addr("127.0.0.1");//INADDR_ANY
        server_addr.sin_port = htons(9090);
        revisar_bind = bind(server_socket, (sockaddr *)&server_addr, sizeof(server_addr));
        if (wsa_start != 0) {
            printf("Error del WSASTARTUP");
            WSACleanup();
        } else {
            if (server_socket == INVALID_SOCKET) {
                std::cout << "no inicia el socket :((((((";
            } else {
                if(revisar_bind!=0){
                    std::cout << "error del bind";
                    std::cout << revisar_bind<< "  <----- ESTE ES EL BIND";
                    closesocket(server_socket);
                    std::cout<<WSAGetLastError()<<" <------ this is the get error";

                }else{
                printf("sirvio el incio!!! \n");
            }
        }
    }
    }

    int get_server_socket(){ //maybe delete revisar si sirve al final
        return server_socket;
    }

    int connect (){
        listen(server_socket, 3);
        int size_client_addr = sizeof (client_addr);
        socklen_t client_lenght = sizeof(client_addr);

        if ((client_socket = accept(server_socket, (struct sockaddr*)&client_addr, reinterpret_cast<int *>(client_lenght))) != 0){
            std::cout << "\n se conecto \n"; //
        }else{
            std::cout <<"error al conectarse lol :(";
        }


    }

    void recieve_data () { //cambiar el tipo de dato si quiero retornar algo!!!!!!!!

        recv(client_socket,buffer, sizeof(buffer),0); //RECIBIR MENSAJE
        std::cout <<"El cliente dice: " << buffer;
        memset(buffer,0, sizeof(buffer));  //REINICIAR BUFFER CON LA ENTRADA!!!!

    }

    void send_data(){  //cambiar el tipo de dato si quiero retornar algo!!!!!!!!
        std::cout <<"QUE DESEA ENVIAR?? \n";
        //std::cin >> this->buffer;
        std::cin >> this->string_message;
        std::cout << "\n"<<string_message << " este es su mensaje??? \n";
        send(server_socket, buffer, sizeof(buffer), 0 );//revisar si aquí va server o client (del que se manda o al que se manda
        //memset(buffer,0, sizeof(buffer));  //REINICIAR BUFFER CON LA ENTRADA!!!!
        //std::cout << "el nuevo buffer es de: "<<buffer <<" no hay nada";

    }

    void close_all(){
        closesocket(client_socket);
        closesocket(server_socket);
        std::cout <<"se cerró todo";
    }

};


int main() {
    Server servidor;
    //servidor.close_all();

    servidor.Start();
    //std::cout<<(Servidor.get_server_socket());
    //std::cout<<"Num de socket";
    servidor.connect();



    Client cliente;
    cliente.create_client();


    servidor.send_data();
    cliente.recieve_data();
    //cliente.recieve_data();
    //servidor.recieve_data();

    return 0;
}

