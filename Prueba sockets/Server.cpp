#include <iostream>
#include <string>
#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdio.h>
#include <thread>
#include <string>



#include <sys/types.h>

//#include "Client.cpp"


#include <stdlib.h>
#include <stdio.h>


#pragma comment (lib, "Ws2_32.lib")


#define PORT_PORT 1337
class Server{
private:
    WSAData wsaData;
    int wsa_start;

    std::string ip = "127.0.0.1";


    struct sockaddr_in server_addr;     //STRUCTS
    struct sockaddr_in client_addr;


    std::string string_message;


    int revisar_bind = 0;
    int revisar_listen = 0;

    int server_socket = INVALID_SOCKET;
    int client_socket = 10; //CHANGE para poner varios maybeee o hacer otroo


    //SOCKET servidor = INVALID_SOCKET;
    SOCKET cliente_prueba = INVALID_SOCKET;//20;//valor de prueba a ver si cambiaba en el accept

    char buffer [5000]; //size of messages
    //creo que me lo volé por el string pero revisar mejor

public:
    void Start () { //put always to start de server
        wsa_start = WSAStartup(MAKEWORD(2, 2), &wsaData);
        server_socket = socket(AF_INET, SOCK_STREAM, 0);

        memset(&server_addr, 0, sizeof(server_addr));
        server_addr.sin_family = AF_INET;
        server_addr.sin_addr.s_addr = htons(INADDR_ANY);
        server_addr.sin_port = htons(9090);

        revisar_bind = bind(server_socket, (sockaddr *) &server_addr, sizeof(server_addr));

        revisar_listen = listen(server_socket, 20);
        //listen(server_socket, 3);






        if (wsa_start != 0) {
            printf("Error del WSASTARTUP");
            WSACleanup();
        } else {
            if (server_socket == INVALID_SOCKET) {
                std::cout << "no inicia el socket :((((((";
            } else {
                if (revisar_bind != 0) {
                    std::cout << "error del bind";
                    std::cout << revisar_bind << "  <----- ESTE ES EL BIND";
                    //closesocket(server_socket);
                    std::cout << WSAGetLastError() << " <------ this is the get error";

                } else {
                    if (revisar_listen != 0) {
                        std::cout << "error del listen!!!!!!!!!! \n";
                    } else {
                        printf("sirvio el incio!!! \n");
                    }
                }
            }
        }
    }

    int get_server_socket(){ //maybe delete revisar si sirve al final
        return server_socket;
    }

    int connect () {

        //int size_client_addr = sizeof (client_addr);
        int client_lenght = sizeof(client_addr); //socket_lenth
        //std::cout <<"cliente prueba antes de----> "<<cliente_prueba<< "\n";
        //cliente_prueba = accept(server_socket, (struct sockaddr*)&client_addr,&client_lenght);
        //std::cout <<"EL CLIENTE_PRUEBA DESPUES DEL ACCEPT----> "<<cliente_prueba;

        std::cout <<"cliente socket antes de----> "<<client_socket<< "\n";
        //std::cout << INVALID_SOCKET<< "SOCKET INVALIDO";
        client_socket = accept(server_socket, (struct sockaddr*)&client_addr,&client_lenght);
        std::cout<<"CODIGO DE ERROR:"<<WSAGetLastError();
        std::cout <<"EL CLIENTE_SOCKET DESPUES DEL ACCEPT----> "<<client_socket;


        /*
        if ((client_socket = accept(server_socket, (struct sockaddr*)&client_addr, reinterpret_cast<int *>(client_lenght))) != 0){
            std::cout << "\n se conecto \n"; //
            std::cout <<client_socket<<"ESTE ES EL CLIENTE";
        }else{
            std::cout <<"error al conectarse lol :(";
        }
*/


    }

    void recieve_data () {
        //cambiar el tipo de dato si quiero retornar algo!!!!!!!!
        //recv(cliente_prueba,buffer, sizeof(buffer),0); //RECIBIR MENSAJE
        //recv(client_socket,buffer, sizeof(buffer),0); //RECIBIR MENSAJE
        //std::cout <<"El cliente dice: " << buffer;
        //memset(buffer,0, sizeof(buffer));  //REINICIAR BUFFER CON LA ENTRADA!!!!
        int i = 0;
        int answer = 0;
        memset(buffer,0, sizeof(buffer));  //REINICIAR BUFFER CON LA ENTRADA!!!!
        std::cout << "ESTE DEBERIA SER EL BUFFER VACIO:  ";
        printf(buffer);


        answer = recv(client_socket,buffer, sizeof(buffer),0); //RECIBIR MENSAJE
        std::cout<<"EL CLIENTE DICE ----->: "<< answer;
        std::cout<<buffer<<" <------EL MENSAJE IOTAS!!!!!";


        //si recieve retorna -1 pegarse un tiro
        /*
        while (i!=1){
            answer = recv(client_socket,buffer, sizeof(buffer),0); //RECIBIR MENSAJE
            std::cout << "no esta sirviendo"<<"\n";
            if(answer == -1){
                printf("%c", buffer);
                //std::cout << buffer << "this is the message and the answer (number) is: "<<answer;
                i++;
            }
        }
        */

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


int main(int argc, const char* argv[]) {
    Server servidor;
    //Client cliente;
    //////////////////////
    servidor.Start();
   //cliente.create_client();
    //////////////////////
    servidor.connect();


    //cliente.send_data();
    servidor.recieve_data();
    servidor.recieve_data();








    //servidor.send_data();
    //cliente.recieve_data();
    //cliente.recieve_data();
    //servidor.recieve_data();

    return 0;
}

