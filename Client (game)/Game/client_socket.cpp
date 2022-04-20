#include "client_socket.h"




/**
 * @brief Client::create_client: Creates the client socket and stablishes the conection
 */
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

/**
 * @brief Client::send_data: Send a message to the server socket for comunication between programs
 * @param mensaje
 */
void Client::send_data(char mensaje[]){
    memset(buffer,0,sizeof(buffer));
    memcpy(buffer,mensaje,sizeof(buffer));
    send(cliente_socket, buffer , sizeof(buffer), 0 );
    Sleep(1);
}

/**
 * @brief Client::recieve_data Obtiene los mensajes enviados por el servidor y dependiendo del mensaje
 * modifica la variable order que se usa en la clase principal para realizar validaciones
 */
void Client::recieve_data () {
    while (1) {
        Sleep(1);
        int answer = 0;
        memset(buffer, 0, sizeof(buffer));
        answer = recv(cliente_socket, buffer, sizeof(buffer), 0);
        if(answer !=-1){
            if(strcmp(buffer,"reset")==0){
                order = 0;
                continue;
            }else{
                if(strcmp(buffer,"check")==0){
                    order = 1;
                }else{
                    if(strcmp(buffer,"start")==0){
                        order=2;
                    }else{
                        if(strcmp(buffer,"set players")==0){
                            memset(buffer, 0, sizeof(buffer));
                            recv(cliente_socket, buffer, sizeof(buffer), 0);
                            jugador_1 = buffer;
                            Sleep(120);
                            memset(buffer, 0, sizeof(buffer));
                            recv(cliente_socket, buffer, sizeof(buffer), 0);
                            jugador_2 = buffer;
                            Sleep(120);
                            order = 3;
                        }else{
                            memcpy(image,buffer,sizeof(buffer));
                        }
                    }
                }
            }
        }
    }
}

/**
 * @brief Client::get_image
 * @return la imagen enviada por el servidor
 */
char* Client::get_image(){
    Sleep(4);
    return image;
}

/**
 * @brief Client::get_order
 * @return la variable order para validar los mensajes del servidor en game_window
 */
int Client::get_order(){
    return order;
}

/**
 * @brief Client::reset_order resetea la variable order a un valor de 30 el cual significa que no hay nada que hacer en game_window
 */
void Client::reset_order(){
    order = 30;
}

/**
 * @brief Client::create_recieve_thread Crea el thread de la función recieve para poder recibir mensajes indefinidamente
 */
void Client::create_recieve_thread(){
    std::thread thread_recieve(&Client::recieve_data, this);    
    thread_recieve.detach();
}

/**
 * @brief Client::get_player1
 * @return el nombre del jugador 1
 */
QString Client::get_player1(){
    return jugador_1;
}

/**
 * @brief Client::get_player1
 * @return el nombre del jugador 2
 */
QString Client::get_player2(){
    return jugador_2;
}

/**
 * @brief Client::set_order Permite cambiar el valor de order desde game_window para poder utilizar ciertos bloques de código
 * en caso de ser necesario
 * @param num
 */
void Client::set_order(int num){
    order = num;
}
