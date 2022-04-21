#include "server_socket.h"
#include "tarjetas.h"


/**
 * @brief Server_socket::Start Crea el server socket
 */
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
      //CHECH THE SOCKET START
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
                    std::cout << "error del listen!!!!!!!!!! \n";
                } else {
                    printf("Server Iniciado!!! \n");
                   }
               }
           }
       }
}

/**
 * @brief Server_socket::connect Acepta la conexión por parte del cliente
 */
void Server_socket::connect () {
    int client_lenght = sizeof(client_addr); //socket_lenth
    client_socket = accept(server_socket, (struct sockaddr*)&client_addr,&client_lenght);
   }

/**
 * @brief Server_socket::recieve_data Verifica el mensaje enviado por parte del cliente
 * y si es un butón presionado lo convierte en la variable del botón presionado para
 * utilizarlo en la logica
 */
void Server_socket::recieve_data () {
    while (1) {
        Sleep(30);
        int answer = 0;
        memset(buffer, 0, sizeof(buffer));
        answer = recv(client_socket, buffer, sizeof(buffer), 0);

        if(answer !=-1){            
            if(strcmp(buffer,"cero,cero")==0){
                button_pressed = 0;
            }
            if(strcmp(buffer,"cero,uno")==0){
                button_pressed = 1;
            }
            if(strcmp(buffer,"cero,dos")==0){
                button_pressed = 2;
            }
            if(strcmp(buffer,"cero,tres")==0){
                button_pressed = 3;
            }
            if(strcmp(buffer,"cero,cuatro")==0){
                button_pressed = 4;
            }
            if(strcmp(buffer,"cero,cinco")==0){
                button_pressed = 5;
            }
            /////////////////////////////////////SEGUNDA FILA//////////////////////////////////////////////////
            if(strcmp(buffer,"uno,cero")==0){
                button_pressed = 6;
            }
            if(strcmp(buffer,"uno,uno")==0){
                button_pressed = 7;
            }
            if(strcmp(buffer,"uno,dos")==0){
                button_pressed = 8;
            }
            if(strcmp(buffer,"uno,tres")==0){
                button_pressed = 9;
            }
            if(strcmp(buffer,"uno,cuatro")==0){
                button_pressed = 10;
            }
            if(strcmp(buffer,"uno,cinco")==0){
                button_pressed = 11;
            }
            /////////////////////////////////////TERCERA FILA//////////////////////////////////////////////////
            if(strcmp(buffer,"dos,cero")==0){
                button_pressed = 12;
            }
            if(strcmp(buffer,"dos,uno")==0){
                button_pressed = 13;
            }
            if(strcmp(buffer,"dos,dos")==0){
                button_pressed = 14;
            }
            if(strcmp(buffer,"dos,tres")==0){
                button_pressed = 15;
            }
            if(strcmp(buffer,"dos,cuatro")==0){
                button_pressed = 16;
            }
            if(strcmp(buffer,"dos,cinco")==0){
                button_pressed = 17;
            }
            continue;
        }else{
            continue;
        }

    }
}

/**
 * @brief Server_socket::send_data enviar mensajes hacia el cliente
 * @param path (puede ser una mensaje o el array de bits de la imagen de tarjeta)
 */
void Server_socket::send_data(char path[]){
    memset(buffer, 0, sizeof(buffer));
    memcpy(buffer,path,sizeof(path));
    send(client_socket,path,40000,0);
}

/**
 * @brief Server_socket::create_recieve_thread Crea el thread para recieve data
 */
void Server_socket::create_recieve_thread(){
    std::thread thread_recieve(&Server_socket::recieve_data, this);
    thread_recieve.detach();
}

/**
 * @brief Server_socket::get_button_pressed
 * @return  el botón presionado obtenido en el recieve_data
 */
int Server_socket::get_button_pressed(){
    return button_pressed;
}
/**
 * @brief Server_socket::reset_button_pressed resetea el botón presionado para evitar bugs
 */
void Server_socket::reset_button_pressed(){
    button_pressed = 30;
}




