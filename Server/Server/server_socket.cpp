#include "server_socket.h"
#include "tarjetas.h"



void Server_socket::Start () {
    wsa_start = WSAStartup(MAKEWORD(2,2), &wsaData);
    server_socket = socket(AF_INET, SOCK_STREAM,0);
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htons(INADDR_ANY);
    server_addr.sin_port = htons(9090);
    revisar_bind = bind(server_socket, (sockaddr *) &server_addr, sizeof(server_addr));
    revisar_listen = listen(server_socket, 20);
    if (wsa_start != 0) {
        printf("Error del WSASTARTUP");
        WSACleanup();
    }

    /*
     * CHECH THE SOCKET START
    else {
        if (server_socket == INVALID_SOCKET) {
            std::cout << "no inicia el socket :((((((";
        } else {
            if (revisar_bind != 0) {
                std::cout << "error del bind";
                std::cout << revisar_bind << "  <----- ESTE ES EL BIND";
                std::cout << WSAGetLastError() << " <------ this is the get error";
            } else {
                if (revisar_listen != 0) {
                    std::coutf << "error del listen!!!!!!!!!! \n";
                } else {
                    printf("Server Iniciado!!! \n");
                   }
               }
           }
       }
       */
   }


void Server_socket::connect () {
    int client_lenght = sizeof(client_addr); //socket_lenth
    client_socket = accept(server_socket, (struct sockaddr*)&client_addr,&client_lenght);
    //std::cout <<"cliente 1: "<<client_socket<<"\n";

   }

void Server_socket::recieve_data () {
    while (1) {
        //std::cout << "CICLO";
        Sleep(30);
        int answer = 0;
        memset(buffer, 0, sizeof(buffer));  //REINICIA BUFFER CON LA ENTRADA!!!!
        answer = recv(client_socket, buffer, sizeof(buffer), 0); //RECIBIR MENSAJE

        if(answer !=-1){            
            if(strcmp(buffer,"cero,cero")==0){  //TO KNOW WHAT BUTTON IS CLICKED
                button_pressed = 0;
                //send_data(0);
            }
            if(strcmp(buffer,"cero,uno")==0){
                button_pressed = 1;
                //send_data(1);
            }
            if(strcmp(buffer,"cero,dos")==0){
                button_pressed = 2;
                //send_data(2);
            }
            if(strcmp(buffer,"cero,tres")==0){
                button_pressed = 3;
                //send_data(3);
            }
            if(strcmp(buffer,"cero,cuatro")==0){
                button_pressed = 4;
                //send_data(4);

            }
            if(strcmp(buffer,"cero,cinco")==0){
                button_pressed = 5;
                //send_data(5);
            }
            /////////////////////////////////////SEGUNDA FILA//////////////////////////////////////////////////
            if(strcmp(buffer,"uno,cero")==0){
                button_pressed = 6;
                //send_data(6);
            }
            if(strcmp(buffer,"uno,uno")==0){
                button_pressed = 7;
                //send_data(7);
            }
            if(strcmp(buffer,"uno,dos")==0){
                button_pressed = 8;
                //send_data(8);
            }
            if(strcmp(buffer,"uno,tres")==0){
                button_pressed = 9;
                //send_data(9);
            }
            if(strcmp(buffer,"uno,cuatro")==0){
                button_pressed = 10;
                //send_data(10);
            }
            if(strcmp(buffer,"uno,cinco")==0){
                button_pressed = 11;
                //send_data(11);
            }
            /////////////////////////////////////TERCERA FILA//////////////////////////////////////////////////
            if(strcmp(buffer,"dos,cero")==0){
                button_pressed = 12;
                //send_data(12);
            }
            if(strcmp(buffer,"dos,uno")==0){
                button_pressed = 13;
                //send_data(13);
            }
            if(strcmp(buffer,"dos,dos")==0){
                button_pressed = 14;
                //send_data(14);
            }
            if(strcmp(buffer,"dos,tres")==0){
                button_pressed = 15;
                //send_data(15);
            }
            if(strcmp(buffer,"dos,cuatro")==0){
                button_pressed = 16;
                //send_data(16);
            }
            if(strcmp(buffer,"dos,cinco")==0){
                button_pressed = 17;
                //send_data(17);
            }
            continue;
        }else{
            continue;
        }

    }
}

void Server_socket::send_data(char path[], int size, int card){  //cambiar el tipo de dato si quiero retornar algo!!!!!!!!
    memset(buffer, 0, sizeof(buffer));
    memcpy(buffer,path,sizeof(path));
    send(client_socket,path,40000,0);
}


void Server_socket::create_recieve_thread(){
    std::thread thread_recieve(&Server_socket::recieve_data, this);
    thread_recieve.detach();
}





int Server_socket::get_button_pressed(){
    return button_pressed;
}
void Server_socket::reset_button_pressed(){
    button_pressed = 30;
}




