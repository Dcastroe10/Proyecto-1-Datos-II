#include <iostream>
#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdio.h>
#include <thread>
#include <sys/types.h>

#include "Client.cpp"

#include <stdlib.h>
#include <stdio.h>


#pragma comment (lib, "Ws2_32")



class Server{
private:
    WSAData wsaData;
    int wsa_start = WSAStartup(MAKEWORD(2,2), &wsaData);


    struct sockaddr_in server_address;
    struct sockaddr_in client_address;


    int server_socket = socket(AF_INET,SOCK_STREAM, 0);


    SOCKET servidor = INVALID_SOCKET;
    SOCKET cliente = INVALID_SOCKET;


    char buffer [1024]; //size of messages

public:
    void Start (){ //put always to start de server
        server_address.sin_family=AF_INET;
        server_address.sin_addr.s_addr = htons(INADDR_ANY);
        server_address.sin_port = htons(3030);
        bind(server_socket, (SOCKADDR *) & server_address, sizeof (server_address));
        if (wsa_start != 0){
            printf("Error del WSAStartup");
        }else{
            printf("sirvio el WSAStartup \n");
        }
    }

    int get_server_socket(){ //maybe delete revisar si sirve al final
        return server_socket;
    }

    int connect (){
        listen(server_socket, 3);
        int size_client_addr = sizeof (client_address);
        socklen_t client_lenght = sizeof(client_address);

        if ((cliente = accept(servidor, (struct sockaddr*)&client_address, reinterpret_cast<int *>(client_lenght))) != 0){
            std::cout << "\n"; //se conectó
        }else{
            std::cout <<"error al conectarse lol :(";
        }


    }

    void recieve_data () { //cambiar el tipo de dato si quiero retornar algo!!!!!!!!

        recv(cliente,buffer, sizeof(buffer),0); //RECIBIR MENSAJE
        std::cout <<"El cliente dice: " << buffer;
        memset(buffer,0, sizeof(buffer));  //REINICIAR BUFFER CON LA ENTRADA!!!!

    }

    void send_data(){  //cambiar el tipo de dato si quiero retornar algo!!!!!!!!
        std::cout <<"QUE DESEA ENVIAR?? \n";
        std::cin >> this->buffer;
        std::cout << "\n"<<buffer << " este es su mensaje??? \n";
        send(cliente, buffer, sizeof(buffer), 0 );//revisar si aquí va server o client (del que se manda o al que se manda
        //memset(buffer,0, sizeof(buffer));  //REINICIAR BUFFER CON LA ENTRADA!!!!
        //std::cout << "el nuevo buffer es de: "<<buffer <<" no hay nada";

    }

    void close_all(){
        closesocket(cliente);
        closesocket(servidor);
        std::cout <<"se cerró todo";
    }
};


int main() {
    Server servidor;
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

