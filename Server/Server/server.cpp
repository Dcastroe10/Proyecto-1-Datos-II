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

    std::thread thread_set(&Server::set_all_cards, this);
    thread_set.detach();

    for (int s=0; s<3;s++){  //for the initial cards in memory
        tarjeta_en_memoria[s]->set_image(game_images_path[s]);
        tarjeta_en_memoria[s]->set_ID(s);
    }

    std::thread thread_logic(&Server::logic, this);
    thread_logic.detach();

    std::thread thread_labels(&Server::update_labels, this);
    thread_labels.detach();

    std::thread thread_check(&Server::hay_pareja, this);
    thread_check.detach();


    servidor.send_data("start",sizeof("check"),30);
    Sleep(100);
    QImage check ("Imagenes 100x100/yogi.png"); //!!!!!!!!!!
    int tamaño = check.sizeInBytes();
    memcpy(check_image,check.bits(),tamaño);
    servidor.send_data(check_image,40000,30);


    for(int x = 0 ; x<3;x++){
        for(int z = 0; z<6; z++){
            qDebug()<<matriz_posiciones[x][z]<<"   ";
            //qDebug()<<matrix_created[x][z]<<"  ";
        }
        qDebug()<<"\n";
        //qDebug()<<"\n";
    }


}

Server::~Server()
{
    delete ui;
}


void Server::set_all_cards(){ //delete or revisar
    /*
    QImage check ("Imagenes 100x100/check.png");  //to put the image on all cards
    int tamaño = check.sizeInBytes();
    memcpy(check_image,check.bits(),tamaño);
    servidor.send_data(check_image,40000,30);
    qDebug()<<"CHECK SEND";
    */
}

void Server::on_pushButton_clicked() //DELETE
{
    qDebug()<<"EL BOTÓN PRESIONADO: "<<servidor.get_button_pressed();

    QImage check ("Imagenes 100x100/check.png");  //to put the image on all cards
    int tamaño = check.sizeInBytes();
    memcpy(check_image,check.bits(),tamaño);
    servidor.send_data(check_image,40000,30);
    qDebug()<<"CHECK SEND";
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

    while(1){
        Sleep(30);
        int button_pressed = servidor.get_button_pressed();
        /*
        matriz_posiciones[0][0]=8; //forzar el hit, luego quitar
        matriz_posiciones[0][1]=8; //forzar el hit, luego quitar

        matriz_posiciones[1][0]=1; //forzar el hit, luego quitar
        matriz_posiciones[1][1]=1; //forzar el hit, luego quitar
        */

        if(button_pressed==0){//////////////
            qDebug()<<"button 0";
            servidor.reset_button_pressed();
            int tarjeta_pedida = matriz_posiciones[0][0];//////
            int posicion_tarjeta = check_pages(tarjeta_pedida);

            if(posicion_tarjeta !=30){
                page_hits++;
                servidor.send_data(tarjeta_en_memoria[posicion_tarjeta]->get_image(),40000,30);
                qDebug()<<"PAGE HIIIT";
            }else{                                
                this->add_tarjeta(tarjeta_pedida);
                 posicion_tarjeta = 0;
                 servidor.send_data(tarjeta_en_memoria[posicion_tarjeta]->get_image(),40000,30);
                 qDebug()<<"PAGE FAULT";
            }

            if(pareja_1==30){
                pareja_1=tarjeta_pedida;
                //this->hay_pareja(posicion_tarjeta);

            }else{
                if(pareja_2==30){
                    pareja_2=tarjeta_pedida;
                    //this->hay_pareja(posicion_tarjeta);
                    qDebug()<<pareja_1 <<"    "<<pareja_2;
                }
            }
        }

        if(button_pressed==1){//////////////
            qDebug()<<"button 1";
            servidor.reset_button_pressed();
            int tarjeta_pedida = matriz_posiciones[0][1];//////
            int posicion_tarjeta = check_pages(tarjeta_pedida);
            qDebug()<<"Posicion de tarjeta"<<posicion_tarjeta;
            if(posicion_tarjeta !=30){
                page_hits++;
                servidor.send_data(tarjeta_en_memoria[posicion_tarjeta]->get_image(),40000,30);
                qDebug()<<"PAGE HIIIT";                
            }else{
                this->add_tarjeta(tarjeta_pedida);
                 posicion_tarjeta = 0;
                 servidor.send_data(tarjeta_en_memoria[posicion_tarjeta]->get_image(),40000,30);
                   qDebug()<<"PAGE FAULT";   
            }

            if(pareja_1==30){
                pareja_1=tarjeta_pedida;
                //this->hay_pareja(posicion_tarjeta);

            }else{
                if(pareja_2==30){
                    pareja_2=tarjeta_pedida;
                    //this->hay_pareja(posicion_tarjeta);

                    qDebug()<<pareja_1 <<"    "<<pareja_2;
                }
            }
        }

        if(button_pressed==2){
            qDebug()<<"button 2";
            servidor.reset_button_pressed();
            int tarjeta_pedida = matriz_posiciones[0][2];//////
            int posicion_tarjeta = check_pages(tarjeta_pedida);
            qDebug()<<"Posicion de tarjeta"<<posicion_tarjeta;
            if(posicion_tarjeta !=30){
                page_hits++;
                servidor.send_data(tarjeta_en_memoria[posicion_tarjeta]->get_image(),40000,30);
                qDebug()<<"PAGE HIIIT";
            }else{
                this->add_tarjeta(tarjeta_pedida);
                 posicion_tarjeta = 0;
                 servidor.send_data(tarjeta_en_memoria[posicion_tarjeta]->get_image(),40000,30);
                   qDebug()<<"PAGE FAULT";
            }

            if(pareja_1==30){
                pareja_1=tarjeta_pedida;
                //this->hay_pareja(posicion_tarjeta);

            }else{
                if(pareja_2==30){
                    pareja_2=tarjeta_pedida;
                    //this->hay_pareja(posicion_tarjeta);

                    qDebug()<<pareja_1 <<"    "<<pareja_2;
                }
            }
        }

        if(button_pressed==3){
            qDebug()<<"button 3";
            servidor.reset_button_pressed();
            int tarjeta_pedida = matriz_posiciones[0][3];//////
            int posicion_tarjeta = check_pages(tarjeta_pedida);
            if(posicion_tarjeta !=30){
                page_hits++;
                servidor.send_data(tarjeta_en_memoria[posicion_tarjeta]->get_image(),40000,30);
                qDebug()<<"PAGE HIT";
            }else{
                this->add_tarjeta(tarjeta_pedida);
                 posicion_tarjeta = 0;
                 servidor.send_data(tarjeta_en_memoria[posicion_tarjeta]->get_image(),40000,30);
                   qDebug()<<"PAGE FAULT";
            }
            if(pareja_1==30){
                pareja_1=tarjeta_pedida;
                //this->hay_pareja(posicion_tarjeta);
            }else{
                if(pareja_2==30){
                    pareja_2=tarjeta_pedida;
                    //this->hay_pareja(posicion_tarjeta);
                }
            }
        }

        if(button_pressed==4){
            qDebug()<<"button 4";
            servidor.reset_button_pressed();
            int tarjeta_pedida = matriz_posiciones[0][4];
            int posicion_tarjeta = check_pages(tarjeta_pedida);
            if(posicion_tarjeta !=30){
                page_hits++;
                servidor.send_data(tarjeta_en_memoria[posicion_tarjeta]->get_image(),40000,30);
                qDebug()<<"PAGE HIT";
            }else{
                this->add_tarjeta(tarjeta_pedida);
                 posicion_tarjeta = 0;
                 servidor.send_data(tarjeta_en_memoria[posicion_tarjeta]->get_image(),40000,30);
                   qDebug()<<"PAGE FAULT";
            }
            if(pareja_1==30){
                pareja_1=tarjeta_pedida;
                //this->hay_pareja(posicion_tarjeta);
            }else{
                if(pareja_2==30){
                    pareja_2=tarjeta_pedida;
                    //this->hay_pareja(posicion_tarjeta);
                }
            }
        }

        if(button_pressed==5){
            qDebug()<<"button 5";
            servidor.reset_button_pressed();
            int tarjeta_pedida = matriz_posiciones[0][5];
            int posicion_tarjeta = check_pages(tarjeta_pedida);
            if(posicion_tarjeta !=30){
                page_hits++;
                servidor.send_data(tarjeta_en_memoria[posicion_tarjeta]->get_image(),40000,30);
                qDebug()<<"PAGE HIT";
            }else{
                this->add_tarjeta(tarjeta_pedida);
                 posicion_tarjeta = 0;
                 servidor.send_data(tarjeta_en_memoria[posicion_tarjeta]->get_image(),40000,30);
                   qDebug()<<"PAGE FAULT";
            }
            if(pareja_1==30){
                pareja_1=tarjeta_pedida;
                //this->hay_pareja(posicion_tarjeta);
            }else{
                if(pareja_2==30){
                    pareja_2=tarjeta_pedida;
                    //this->hay_pareja(posicion_tarjeta);
                }
            }
        }

        if(button_pressed==6){
            qDebug()<<"button 6";
            servidor.reset_button_pressed();
            int tarjeta_pedida = matriz_posiciones[1][0];
            int posicion_tarjeta = check_pages(tarjeta_pedida);
            if(posicion_tarjeta !=30){
                page_hits++;
                servidor.send_data(tarjeta_en_memoria[posicion_tarjeta]->get_image(),40000,30);
                qDebug()<<"PAGE HIT";
            }else{
                this->add_tarjeta(tarjeta_pedida);
                 posicion_tarjeta = 0;
                 servidor.send_data(tarjeta_en_memoria[posicion_tarjeta]->get_image(),40000,30);
                   qDebug()<<"PAGE FAULT";
            }
            if(pareja_1==30){
                pareja_1=tarjeta_pedida;
                //this->hay_pareja(posicion_tarjeta);
            }else{
                if(pareja_2==30){
                    pareja_2=tarjeta_pedida;
                    //this->hay_pareja(posicion_tarjeta);
                }
            }
        }

        if(button_pressed==7){
            qDebug()<<"button 7";
            servidor.reset_button_pressed();
            int tarjeta_pedida = matriz_posiciones[1][1];
            int posicion_tarjeta = check_pages(tarjeta_pedida);
            if(posicion_tarjeta !=30){
                page_hits++;
                servidor.send_data(tarjeta_en_memoria[posicion_tarjeta]->get_image(),40000,30);
                qDebug()<<"PAGE HIT";
            }else{
                this->add_tarjeta(tarjeta_pedida);
                 posicion_tarjeta = 0;
                 servidor.send_data(tarjeta_en_memoria[posicion_tarjeta]->get_image(),40000,30);
                   qDebug()<<"PAGE FAULT";
            }
            if(pareja_1==30){
                pareja_1=tarjeta_pedida;
                //this->hay_pareja(posicion_tarjeta);
            }else{
                if(pareja_2==30){
                    pareja_2=tarjeta_pedida;
                    //this->hay_pareja(posicion_tarjeta);
                }
            }
        }

        if(button_pressed==8){
            qDebug()<<"button 8";
            servidor.reset_button_pressed();
            int tarjeta_pedida = matriz_posiciones[1][2];
            int posicion_tarjeta = check_pages(tarjeta_pedida);
            if(posicion_tarjeta !=30){
                page_hits++;
                servidor.send_data(tarjeta_en_memoria[posicion_tarjeta]->get_image(),40000,30);
                qDebug()<<"PAGE HIT";
            }else{
                this->add_tarjeta(tarjeta_pedida);
                 posicion_tarjeta = 0;
                 servidor.send_data(tarjeta_en_memoria[posicion_tarjeta]->get_image(),40000,30);
                   qDebug()<<"PAGE FAULT";
            }
            if(pareja_1==30){
                pareja_1=tarjeta_pedida;
                //this->hay_pareja(posicion_tarjeta);
            }else{
                if(pareja_2==30){
                    pareja_2=tarjeta_pedida;
                    //this->hay_pareja(posicion_tarjeta);
                }
            }
        }

        if(button_pressed==9){
            qDebug()<<"button 9";
            servidor.reset_button_pressed();
            int tarjeta_pedida = matriz_posiciones[1][3];
            int posicion_tarjeta = check_pages(tarjeta_pedida);
            if(posicion_tarjeta !=30){
                page_hits++;
                servidor.send_data(tarjeta_en_memoria[posicion_tarjeta]->get_image(),40000,30);
                qDebug()<<"PAGE HIT";
            }else{
                this->add_tarjeta(tarjeta_pedida);
                 posicion_tarjeta = 0;
                 servidor.send_data(tarjeta_en_memoria[posicion_tarjeta]->get_image(),40000,30);
                   qDebug()<<"PAGE FAULT";
            }
            if(pareja_1==30){
                pareja_1=tarjeta_pedida;
                //this->hay_pareja(posicion_tarjeta);
            }else{
                if(pareja_2==30){
                    pareja_2=tarjeta_pedida;
                    //this->hay_pareja(posicion_tarjeta);
                }
            }
        }

        if(button_pressed==10){
            qDebug()<<"button 10";
            servidor.reset_button_pressed();
            int tarjeta_pedida = matriz_posiciones[1][4];
            int posicion_tarjeta = check_pages(tarjeta_pedida);
            if(posicion_tarjeta !=30){
                page_hits++;
                servidor.send_data(tarjeta_en_memoria[posicion_tarjeta]->get_image(),40000,30);
                qDebug()<<"PAGE HIT";
            }else{
                this->add_tarjeta(tarjeta_pedida);
                 posicion_tarjeta = 0;
                 servidor.send_data(tarjeta_en_memoria[posicion_tarjeta]->get_image(),40000,30);
                   qDebug()<<"PAGE FAULT";
            }
            if(pareja_1==30){
                pareja_1=tarjeta_pedida;
                //this->hay_pareja(posicion_tarjeta);
            }else{
                if(pareja_2==30){
                    pareja_2=tarjeta_pedida;
                    //this->hay_pareja(posicion_tarjeta);
                }
            }
        }

        if(button_pressed==11){
            qDebug()<<"button 11";
            servidor.reset_button_pressed();
            int tarjeta_pedida = matriz_posiciones[1][5];
            int posicion_tarjeta = check_pages(tarjeta_pedida);
            if(posicion_tarjeta !=30){
                page_hits++;
                servidor.send_data(tarjeta_en_memoria[posicion_tarjeta]->get_image(),40000,30);
                qDebug()<<"PAGE HIT";
            }else{
                this->add_tarjeta(tarjeta_pedida);
                 posicion_tarjeta = 0;
                 servidor.send_data(tarjeta_en_memoria[posicion_tarjeta]->get_image(),40000,30);
                   qDebug()<<"PAGE FAULT";
            }
            if(pareja_1==30){
                pareja_1=tarjeta_pedida;
                //this->hay_pareja(posicion_tarjeta);
            }else{
                if(pareja_2==30){
                    pareja_2=tarjeta_pedida;
                    //this->hay_pareja(posicion_tarjeta);
                }
            }
        }

        if(button_pressed==12){
            qDebug()<<"button 12";
            servidor.reset_button_pressed();
            int tarjeta_pedida = matriz_posiciones[2][0];
            int posicion_tarjeta = check_pages(tarjeta_pedida);
            if(posicion_tarjeta !=30){
                page_hits++;
                servidor.send_data(tarjeta_en_memoria[posicion_tarjeta]->get_image(),40000,30);
                qDebug()<<"PAGE HIT";
            }else{
                this->add_tarjeta(tarjeta_pedida);
                 posicion_tarjeta = 0;
                 servidor.send_data(tarjeta_en_memoria[posicion_tarjeta]->get_image(),40000,30);
                   qDebug()<<"PAGE FAULT";
            }
            if(pareja_1==30){
                pareja_1=tarjeta_pedida;
                //this->hay_pareja(posicion_tarjeta);
            }else{
                if(pareja_2==30){
                    pareja_2=tarjeta_pedida;
                    //this->hay_pareja(posicion_tarjeta);
                }
            }
        }

        if(button_pressed==13){
            qDebug()<<"button 13";
            servidor.reset_button_pressed();
            int tarjeta_pedida = matriz_posiciones[2][1];
            int posicion_tarjeta = check_pages(tarjeta_pedida);
            if(posicion_tarjeta !=30){
                page_hits++;
                servidor.send_data(tarjeta_en_memoria[posicion_tarjeta]->get_image(),40000,30);
                qDebug()<<"PAGE HIT";
            }else{
                this->add_tarjeta(tarjeta_pedida);
                 posicion_tarjeta = 0;
                 servidor.send_data(tarjeta_en_memoria[posicion_tarjeta]->get_image(),40000,30);
                   qDebug()<<"PAGE FAULT";
            }
            if(pareja_1==30){
                pareja_1=tarjeta_pedida;
                //this->hay_pareja(posicion_tarjeta);
            }else{
                if(pareja_2==30){
                    pareja_2=tarjeta_pedida;
                    //this->hay_pareja(posicion_tarjeta);
                }
            }
        }

        if(button_pressed==14){
            qDebug()<<"button 14";
            servidor.reset_button_pressed();
            int tarjeta_pedida = matriz_posiciones[2][2];
            int posicion_tarjeta = check_pages(tarjeta_pedida);
            if(posicion_tarjeta !=30){
                page_hits++;
                servidor.send_data(tarjeta_en_memoria[posicion_tarjeta]->get_image(),40000,30);
                qDebug()<<"PAGE HIT";
            }else{
                this->add_tarjeta(tarjeta_pedida);
                 posicion_tarjeta = 0;
                 servidor.send_data(tarjeta_en_memoria[posicion_tarjeta]->get_image(),40000,30);
                   qDebug()<<"PAGE FAULT";
            }
            if(pareja_1==30){
                pareja_1=tarjeta_pedida;
                //this->hay_pareja(posicion_tarjeta);
            }else{
                if(pareja_2==30){
                    pareja_2=tarjeta_pedida;
                    //this->hay_pareja(posicion_tarjeta);
                }
            }
        }

        if(button_pressed==15){
            qDebug()<<"button 15";
            servidor.reset_button_pressed();
            int tarjeta_pedida = matriz_posiciones[2][3];
            int posicion_tarjeta = check_pages(tarjeta_pedida);
            if(posicion_tarjeta !=30){
                page_hits++;
                servidor.send_data(tarjeta_en_memoria[posicion_tarjeta]->get_image(),40000,30);
                qDebug()<<"PAGE HIT";
            }else{
                this->add_tarjeta(tarjeta_pedida);
                 posicion_tarjeta = 0;
                 servidor.send_data(tarjeta_en_memoria[posicion_tarjeta]->get_image(),40000,30);
                   qDebug()<<"PAGE FAULT";
            }
            if(pareja_1==30){
                pareja_1=tarjeta_pedida;
                //this->hay_pareja(posicion_tarjeta);
            }else{
                if(pareja_2==30){
                    pareja_2=tarjeta_pedida;
                    //this->hay_pareja(posicion_tarjeta);
                }
            }
        }

        if(button_pressed==16){
            qDebug()<<"button 16";
            servidor.reset_button_pressed();
            int tarjeta_pedida = matriz_posiciones[2][4];
            int posicion_tarjeta = check_pages(tarjeta_pedida);
            if(posicion_tarjeta !=30){
                page_hits++;
                servidor.send_data(tarjeta_en_memoria[posicion_tarjeta]->get_image(),40000,30);
                qDebug()<<"PAGE HIT";
            }else{
                this->add_tarjeta(tarjeta_pedida);
                 posicion_tarjeta = 0;
                 servidor.send_data(tarjeta_en_memoria[posicion_tarjeta]->get_image(),40000,30);
                   qDebug()<<"PAGE FAULT";
            }
            if(pareja_1==30){
                pareja_1=tarjeta_pedida;
                //this->hay_pareja(posicion_tarjeta);
            }else{
                if(pareja_2==30){
                    pareja_2=tarjeta_pedida;
                    //this->hay_pareja(posicion_tarjeta);
                }
            }
        }

        if(button_pressed==17){
            qDebug()<<"button 17";
            servidor.reset_button_pressed();
            int tarjeta_pedida = matriz_posiciones[2][5];
            int posicion_tarjeta = check_pages(tarjeta_pedida);
            if(posicion_tarjeta !=30){
                page_hits++;
                servidor.send_data(tarjeta_en_memoria[posicion_tarjeta]->get_image(),40000,30);
                qDebug()<<"PAGE HIT";
            }else{
                this->add_tarjeta(tarjeta_pedida);
                 posicion_tarjeta = 0;
                 servidor.send_data(tarjeta_en_memoria[posicion_tarjeta]->get_image(),40000,30);
                   qDebug()<<"PAGE FAULT";
            }
            if(pareja_1==30){
                pareja_1=tarjeta_pedida;
                //this->hay_pareja(posicion_tarjeta);
            }else{
                if(pareja_2==30){
                    pareja_2=tarjeta_pedida;
                    //this->hay_pareja(posicion_tarjeta);
                }
            }
        }

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

void Server::hay_pareja(){
    while(1){
        Sleep(1000);
    if (pareja_1 ==30){
        //qDebug()<<"NO HAY PAREJA";
        //return false;
    }else{
    if (pareja_2 ==30){
        //qDebug()<<"NO HAY PAREJA ";
        //return false;
    }else{
    if(pareja_1 !=30 && pareja_2 !=30 && pareja_1 == pareja_2){
         qDebug()<<"HAY PAREJA";
         servidor.send_data("check",sizeof("check"),30);
         Sleep(100);
         pareja_1 = 30;
         pareja_2 = 30;


         QImage check ("Imagenes 100x100/check.png"); //!!!!!!!!!!check!!!
         int tamaño = check.sizeInBytes();
         memcpy(check_image,check.bits(),tamaño);
         servidor.send_data(check_image,40000,30);

         //return true;
    }else{
        qDebug()<<"NO HAY PAREJA son diferentes";
        pareja_1 = 30;
        pareja_2 = 30;

        servidor.send_data("reset", sizeof("reset"), 0); //poner button pressed //el int al final es para saber que butón presionó
        Sleep(100);

        QImage check ("Imagenes 100x100/yogi.png"); //!!!!!!!!!!
        int tamaño = check.sizeInBytes();
        memcpy(check_image,check.bits(),tamaño);
        servidor.send_data(check_image,40000,30);

        //return false;

    }
    }
}
    }
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



