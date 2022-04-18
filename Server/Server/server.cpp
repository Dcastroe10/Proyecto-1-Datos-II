#include "server.h"
#include "ui_server.h"
#include "tarjetas.h"

#include <QtDebug>

Server::Server(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Server)
{
    ui->setupUi(this);
    servidor.Start();
    servidor.connect();
    servidor.create_recieve_thread();
    this->random_array(ingame_card);


    //tarjeta_0->set_ID(8);
    //qDebug()<<tarjeta_en_memoria[0]->get_ID();
    //delete tarjeta_en_memoria[0];                              //DELETEEE ITS JUST COMO HACERLO
    //qDebug()<<tarjeta_en_memoria[0]->get_ID();

    for (int s=0; s<3;s++){
        tarjeta_en_memoria[s]->set_image(game_images_path[s]);
        tarjeta_en_memoria[s]->set_ID(s);
    }
    //printf("%s\n", tarjeta_en_memoria[0]->get_image());

    std::thread thread_logic(&Server::logic, this);
    thread_logic.detach();

    std::thread thread_labels(&Server::update_labels, this);
    thread_labels.detach();




}

Server::~Server()
{
    delete ui;
}


void Server::on_pushButton_clicked() //DELETE
{
    qDebug()<<"EL BOTÓN PRESIONADO: "<<servidor.get_button_pressed();
}

void Server::random_array(int playing_cards[]){
    int new_array[18];
    bool used_element[18];
    int i = 0;
    srand(time(0));
    for(int x = 0; x<18;x++){
        used_element[x]=false;
        new_array[x]=1234;
    }


    while (new_array[17] == 1234){

        int num = rand()%18;
        if (!used_element[num]){
            new_array[i] = playing_cards[num];
            used_element[num]=true;
            i++;
        }
    }

    memcpy(ingame_card,new_array,sizeof(new_array));
    this->create_matrix(new_array);

/*
    //to print the array
    for( int f = 0; f < 18;f++){
       qDebug()<<ingame_card[f];
       //qDebug()<<used_element[f];
       //qDebug()<<new_array[0];
    }
*/

}

bool Server::used(bool *usados){
    for (int i = 0 ; i<18; i++){
        if (usados[i] == false){
            return true;
        }
    }
    return false;
   }

void Server::create_matrix(int mixed_list[]){
    int matrix_created[3][6];
    int num = 0;
    for(int i = 0 ; i<3;i++){
        for(int j = 0; j<6; j++){            
            matrix_created[i][j] = mixed_list[num];
            num++;
        }
    }
    memcpy(matriz_posiciones,matrix_created,sizeof(matrix_created));


    for(int x = 0 ; x<3;x++){
        for(int z = 0; z<6; z++){
            std::cout<<matriz_posiciones[x][z]<<"   ";
            //qDebug()<<matrix_created[x][z]<<"  ";
        }
        std::cout<<"\n";
        //qDebug()<<"\n";
    }
std::cout<<"\n";
}

void Server::logic(){
    //matriz_posiciones[0][0] = 0;
    //qDebug()<<matriz_posiciones[0][0];

    //int button_pressed=0;

    while(1){
        Sleep(30);
        int button_pressed = servidor.get_button_pressed();
        //matriz_posiciones[0][0]=2; //forzar el hit, luego quitar
        if(button_pressed==0){//////////////
            qDebug()<<"button 0";
            servidor.reset_button_pressed();
            int tarjeta_pedida = matriz_posiciones[0][0];//////
            int posicion_tarjeta = check_pages(tarjeta_pedida);
            qDebug()<<"Posicion de tarjeta"<<posicion_tarjeta;
            if(posicion_tarjeta !=30){
                //char to_send[40000];
                //memcpy(to_send,tarjeta_en_memoria[posicion_tarjeta]->get_image(),sizeof(tarjeta_en_memoria[posicion_tarjeta]));
                //printf("%s\n", to_send);
                //qDebug()<<to_send<<"to_send";
                //page_hits++;

                //printf("%s\n", tarjeta_en_memoria[posicion_tarjeta]->get_image());
                servidor.send_data(tarjeta_en_memoria[posicion_tarjeta]->get_image(),40000);

                //servidor.send_data(tarjeta_en_memoria[posicion_tarjeta]->get_image());

                //qDebug()<<tarjeta_en_memoria[posicion_tarjeta]->get_image(); //////AQUIIIIIIIIIIIIIIIIIIIIIIII
                //printf("%s\n", tarjeta_en_memoria[posicion_tarjeta]->get_image());
                qDebug()<<"PAGE HIIIT";

            }else{
                 qDebug()<<"PAGE FAULT";                 
                this->add_tarjeta(tarjeta_pedida);
                 posicion_tarjeta = 0;
                 servidor.send_data(tarjeta_en_memoria[posicion_tarjeta]->get_image(),40000);

            //qDebug()<<matriz_posiciones[0][0];
            }

        }
        this->random_array(ingame_card);
    }

}

int Server::check_pages(int num){
    for (int f = 0; f < std::size(tarjeta_en_memoria); f++){
        if (tarjeta_en_memoria[f]->get_ID() == num){
            return f;
        }
    }
    return 30;
}

void Server::add_tarjeta(int key){
    tarjetas* temp = new tarjetas;
    temp->set_ID(key);
    temp->set_image(game_images_path[key]);
    delete tarjeta_en_memoria[std::size(tarjeta_en_memoria)-1];

    for (int w = std::size(tarjeta_en_memoria)-1 ; w >0 ; w--){
        tarjeta_en_memoria[w] = tarjeta_en_memoria[w-1];
        //qDebug()<<tarjeta_en_memoria[w]->get_ID()<<"Id del array creándose";
    }
    tarjeta_en_memoria[0]=temp;
    //delete tarjeta_en_memoria[sizeof(tarjeta_en_memoria)-1];


    for (int z = 0 ; z < std::size(tarjeta_en_memoria) ; z++){
        qDebug()<<tarjeta_en_memoria[z]->get_ID()<<"ID";
    }
}

void Server::update_labels(){
    while(1){
       ui->label_hits->setText(QString::number(page_hits));
       Sleep(30);
    }
}



