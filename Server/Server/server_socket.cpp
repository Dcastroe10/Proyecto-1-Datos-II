#include "server_socket.h"



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
    } else {
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




void Server_socket::connect () {
    int client_lenght = sizeof(client_addr); //socket_lenth
    client_socket = accept(server_socket, (struct sockaddr*)&client_addr,&client_lenght);
    std::cout <<"cliente 1: "<<client_socket<<"\n";
    client_socket2 = accept(server_socket, (struct sockaddr*)&client_addr,&client_lenght);
    std::cout <<"cliente 2: "<<client_socket2<<"\n";
    //std::cout <<"Cliente 1: "<< client_socket << "Cliente 2: "<< client_socket2;
    //std::cout<<"CODIGO DE ERROR:"<<WSAGetLastError();
       /*
       if ((client_socket = accept(server_socket, (struct sockaddr*)&client_addr, reinterpret_cast<int *>(client_lenght))) != 0){
           std::cout << "\n se conecto \n"; //
           std::cout <<client_socket<<"ESTE ES EL CLIENTE";
       }else{
           std::cout <<"error al conectarse lol :(";
       }
*/


   }

void Server_socket::recieve_data () {
    while (1) {
        //std::cout << "CICLO";
        int answer = 0;
        memset(buffer, 0, sizeof(buffer));  //REINICIA BUFFER CON LA ENTRADA!!!!
        answer = recv(client_socket, buffer, sizeof(buffer), 0); //RECIBIR MENSAJE
        if(answer !=-1){
            //std::cout << "EL Cliente DICE ----->: " << answer;

            std::cout <<" Mensaje del Cliente: "<<buffer<< "<--  \n";
            send_data();
            std::cout <<"data enviada \n";
            continue;
        }else{
            continue;
        }
       //std::cout <<"\n"<<"el thread llamó a la función!!"<<"\n";

    }
}









void Server_socket::send_data(){  //cambiar el tipo de dato si quiero retornar algo!!!!!!!!
    memset(buffer, 0, sizeof(buffer));  //REINICIAR BUFFER CON LA ENTRADA!!!!
    send(client_socket, "RECIBIDO", 8,  0 );//revisar si aquí va server o client (del que se manda o al que se manda
}


void Server_socket::create_recieve_thread(){
    //std::thread recieve_thread = std::thread (&Client::recieve_data, this);
    //tacpt = std::thread (&Client :: recieve_data, this)
    std::thread thread_recieve(&Server_socket::recieve_data, this);
    //thread_recieve.join(); //"NO METER POR INTERFAZ" -Elba2022
    thread_recieve.detach();
}








/*
int main(int argc, const char* argv[]) {
    Server_socket servidor;
    //Client cliente;
    //////////////////////
    servidor.Start();
   //cliente.create_client();
    //////////////////////
    servidor.connect();
    //servidor.send_data();


    //servidor.recieve_data();
    //servidor.send_data();


    servidor.recieve_data();
    servidor.send_data();


    servidor.create_recieve_thread();
    //std::cout <<"SERÁ QUE LLEGA HASTA AQUÍ??";
}
*/
