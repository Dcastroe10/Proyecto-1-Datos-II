#include "client_socket.h"

#include <iostream>
#include <QDebug>




#include "game_window.h"



void Client::create_client(){
    wsa_start = WSAStartup(MAKEWORD(2,2), &wsaData);
    cliente_socket = socket(AF_INET, SOCK_STREAM,0);

    memset(&direccion_client_socket, 0, sizeof(direccion_client_socket));


    direccion_client_socket.sin_family = AF_INET;
    direccion_client_socket.sin_addr.s_addr = inet_addr("127.0.0.1");
    direccion_client_socket.sin_port = htons(9090);


    int conexion = connect(cliente_socket,(sockaddr*)&direccion_client_socket, sizeof (direccion_client_socket));
    //std::cout<<WSAGetLastError();
    //std::cout <<"\n"<<conexion<<"esta es el int conexion";
    if (wsa_start != 0){
        printf("Error del WSASTARTUP");
        WSACleanup();
    }else{
        if(cliente_socket == INVALID_SOCKET){
            std::cout <<"ERROR AL INICIAR EL CLIENTE SOCKET";
    }else{
           std::cout <<"TODO SE INICIO BIEN";
        }
    }

    std::cout <<wsa_start;
    std::cout <<" <----ESTE ES EL WSAAAAAA";
}


void Client::send_data(char mensaje[]){  //cambiar el tipo de dato si quiero retornar algo!!!!!!!!
    //std::cout <<"Que desea enviar el CLIENTE? ";
    //std::cin >> this->buffer;
    //std::cout <<"this is the message to be sent: "<<buffer<< "\n";//std::cout << buffer << " CLIENTE, este es su mensaje???";
    //send(cliente_socket, buffer, sizeof(buffer), 0 );//revisar si aquí va server o client (del que se manda o al que se manda!!!
    memset(buffer,0,sizeof(buffer));
    memcpy(buffer,mensaje,sizeof(buffer));
    send(cliente_socket, buffer , sizeof(buffer), 0 );
    Sleep(1);

    //memset(buffer,0, sizeof(buffer));  //REINICIAR BUFFER CON LA ENTRADA!!!!

}

void Client::recieve_data () { //cambiar el tipo de dato si quiero retornar algo!!!!!!!!
    while (1) {
                Sleep(30);
                int answer = 0;
                memset(buffer, 0, sizeof(buffer));  //REINICIAR BUFFER CON LA ENTRADA!!!!
                answer = recv(cliente_socket, buffer, sizeof(buffer), 0); //RECIBIR MENSAJE
                if(answer !=-1){
                    qDebug()<<"MENSAJE RECIBIDOO";
                    qDebug()<<answer << "ANSWER";
                    qDebug()<<"FUUuuuuuuCK";


                    printf("%s\n", buffer);
                    memcpy(image,buffer,sizeof(buffer));                    
                }else{
                    //memset(image,0,sizeof(image));
                    continue;
                }
}

}

char* Client::get_image(){
    Sleep(4);
    return image;
}

void Client::create_recieve_thread(){
    std::thread thread_recieve(&Client::recieve_data, this);    
    thread_recieve.detach();
}
