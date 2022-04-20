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


    if (wsa_start != 0){
        qDebug()<<"Error del WSASTARTUP";
        WSACleanup();
    }else{
        if(cliente_socket == INVALID_SOCKET){
            qDebug()<<"ERROR AL INICIAR EL CLIENTE SOCKET";
    }else{
            qDebug() <<"TODO SE INICIO BIEN";
        }
    }
}

void Client::send_data(char mensaje[]){
    memset(buffer,0,sizeof(buffer));
    memcpy(buffer,mensaje,sizeof(buffer));
    send(cliente_socket, buffer , sizeof(buffer), 0 );
    Sleep(1);

    //memset(buffer,0, sizeof(buffer));  //REINICIAR BUFFER CON LA ENTRADA!!!!

}

void Client::recieve_data () { //cambiar el tipo de dato si quiero retornar algo!!!!!!!!
   image[0]=123;
    while (1) {
                Sleep(1);
                int answer = 0;
                memset(buffer, 0, sizeof(buffer));  //REINICIAR BUFFER CON LA ENTRADA!!!!
                answer = recv(cliente_socket, buffer, sizeof(buffer), 0); //RECIBIR MENSAJE
                if(answer !=-1){                    
                    if(strcmp(buffer,"reset")==0){  //==0!!  //meter el sleep ipara que llegue la otra imagen
                        order = 0;                        
                        qDebug()<<"CARTAS RESETEADA";
                        //order=30;

                    }else{
                        if(strcmp(buffer,"check")==0){ //==0!!
                            order = 1;
                            qDebug()<<"CHEECK";


                        }else{
                            if(strcmp(buffer,"start")==0){
                                order=2;
                                qDebug()<<"startttt";
                                //Sleep(100);
                                //order = 30;
                            }else{
                         memcpy(image,buffer,sizeof(buffer));
                            }
                        }
                    }
                }
    }
}

char* Client::get_image(){
    Sleep(4);
    return image;
}

int Client::get_order(){
    return order;
}

void Client::reset_order(){
    order = 30;
}

void Client::create_recieve_thread(){
    std::thread thread_recieve(&Client::recieve_data, this);    
    thread_recieve.detach();
}
