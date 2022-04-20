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
    jugador_1 = "Jugador 1";
    jugador_2 = "Jugador 2";

    for (int s=0; s<3;s++){  //le asigna los valores a las tarjetas en memoria
        tarjeta_en_memoria[s]->set_image(game_images_path[s]);
        tarjeta_en_memoria[s]->set_ID(s);
    }

    std::thread thread_logic(&Server::logic, this);
    thread_logic.detach();

    std::thread thread_labels(&Server::update_labels, this);
    thread_labels.detach();

    std::thread thread_check(&Server::hay_pareja, this);
    thread_check.detach();

    servidor.send_data("start");
    Sleep(100);
    QImage check ("Imagenes 100x100/yogi.png");
    int tamaño = check.sizeInBytes();
    memcpy(check_image,check.bits(),tamaño);
    servidor.send_data(check_image);


    /* //to print the matrix
    for(int x = 0 ; x<3;x++){
        for(int z = 0; z<6; z++){
            qDebug()<<matriz_posiciones[x][z]<<"   ";
        }
        qDebug()<<"\n";
    }
    */
}

Server::~Server()
{
    delete ui;
}

/**
 * @brief Server::random_array randomiza el array para crear la matriz de juego
 * @param playing_cards = un array con las cartas del juego
 */
void Server::random_array(int playing_cards[]){
    int new_array[18];
    bool used_element[18];
    int i = 0;
    srand(time(0));
    for(int x = 0; x<18;x++){
        used_element[x]=false;
        new_array[x]=1234; //número para realizar comparaciones
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

}

/**
 * @brief Server::create_matrix Crea una matriz a partir de un array
 *
 * @param mixed_list
 */

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
}

/**
 * @brief Server::logic Función principal del servidor
 * Obtiene que botón fue presionado en el cliente para así saber que posición en la matriz debe revisar
 */
void Server::logic(){

    while(1){
        Sleep(30);
        int button_pressed = servidor.get_button_pressed();
        if(button_pressed==0){
            servidor.reset_button_pressed();
            int tarjeta_pedida = matriz_posiciones[0][0];
            int posicion_tarjeta = check_pages(tarjeta_pedida);
            if(posicion_tarjeta !=30){
                page_hits++;
                servidor.send_data(tarjeta_en_memoria[posicion_tarjeta]->get_image());
                qDebug()<<"PAGE HIT!";
            }else{
                this->add_tarjeta(tarjeta_pedida);
                page_faults++;
                posicion_tarjeta = 0;
                servidor.send_data(tarjeta_en_memoria[posicion_tarjeta]->get_image());
                qDebug()<<"PAGE FAULT";
            }
            if(pareja_1==30){
                pareja_1=tarjeta_pedida;

            }else{
                if(pareja_2==30){
                    pareja_2=tarjeta_pedida;
                }
            }
        }

        if(button_pressed==1){
            servidor.reset_button_pressed();
            int tarjeta_pedida = matriz_posiciones[0][1];
            int posicion_tarjeta = check_pages(tarjeta_pedida);
            if(posicion_tarjeta !=30){
                page_hits++;
                servidor.send_data(tarjeta_en_memoria[posicion_tarjeta]->get_image());
                qDebug()<<"PAGE HIT!";

            }else{
                this->add_tarjeta(tarjeta_pedida);
                 posicion_tarjeta = 0;
                 page_faults++;
                 servidor.send_data(tarjeta_en_memoria[posicion_tarjeta]->get_image());
                 qDebug()<<"PAGE FAULT";
            }
            if(pareja_1==30){
                pareja_1=tarjeta_pedida;

            }else{
                if(pareja_2==30){
                    pareja_2=tarjeta_pedida;
                }
            }
        }

        if(button_pressed==2){
            servidor.reset_button_pressed();
            int tarjeta_pedida = matriz_posiciones[0][2];
            int posicion_tarjeta = check_pages(tarjeta_pedida);
            if(posicion_tarjeta !=30){
                page_hits++;
                servidor.send_data(tarjeta_en_memoria[posicion_tarjeta]->get_image());
                qDebug()<<"PAGE HIT!";
            }else{
                this->add_tarjeta(tarjeta_pedida);
                posicion_tarjeta = 0;
                page_faults++;
                servidor.send_data(tarjeta_en_memoria[posicion_tarjeta]->get_image());
                qDebug()<<"PAGE FAULT";
            }

            if(pareja_1==30){
                pareja_1=tarjeta_pedida;

            }else{
                if(pareja_2==30){
                    pareja_2=tarjeta_pedida;
                }
            }
        }

        if(button_pressed==3){
            servidor.reset_button_pressed();
            int tarjeta_pedida = matriz_posiciones[0][3];
            int posicion_tarjeta = check_pages(tarjeta_pedida);
            if(posicion_tarjeta !=30){
                page_hits++;
                servidor.send_data(tarjeta_en_memoria[posicion_tarjeta]->get_image());
                qDebug()<<"PAGE HIT!";
            }else{
                this->add_tarjeta(tarjeta_pedida);
                posicion_tarjeta = 0;
                page_faults++;
                servidor.send_data(tarjeta_en_memoria[posicion_tarjeta]->get_image());
                qDebug()<<"PAGE FAULT";
            }
            if(pareja_1==30){
                pareja_1=tarjeta_pedida;
            }else{
                if(pareja_2==30){
                    pareja_2=tarjeta_pedida;
                }
            }
        }

        if(button_pressed==4){
            servidor.reset_button_pressed();
            int tarjeta_pedida = matriz_posiciones[0][4];
            int posicion_tarjeta = check_pages(tarjeta_pedida);
            if(posicion_tarjeta !=30){
                page_hits++;
                servidor.send_data(tarjeta_en_memoria[posicion_tarjeta]->get_image());
                qDebug()<<"PAGE HIT!";

            }else{
                this->add_tarjeta(tarjeta_pedida);
                posicion_tarjeta = 0;
                page_faults++;
                servidor.send_data(tarjeta_en_memoria[posicion_tarjeta]->get_image());
                qDebug()<<"PAGE FAULT";
            }
            if(pareja_1==30){
                pareja_1=tarjeta_pedida;
            }else{
                if(pareja_2==30){
                    pareja_2=tarjeta_pedida;
                }
            }
        }

        if(button_pressed==5){
            servidor.reset_button_pressed();
            int tarjeta_pedida = matriz_posiciones[0][5];
            int posicion_tarjeta = check_pages(tarjeta_pedida);
            if(posicion_tarjeta !=30){
                page_hits++;
                servidor.send_data(tarjeta_en_memoria[posicion_tarjeta]->get_image());
                qDebug()<<"PAGE HIT";

            }else{
                this->add_tarjeta(tarjeta_pedida);
                 posicion_tarjeta = 0;
                 page_faults++;
                 servidor.send_data(tarjeta_en_memoria[posicion_tarjeta]->get_image());
                   qDebug()<<"PAGE FAULT";
            }
            if(pareja_1==30){
                pareja_1=tarjeta_pedida;
            }else{
                if(pareja_2==30){
                    pareja_2=tarjeta_pedida;
                }
            }
        }

        if(button_pressed==6){
            servidor.reset_button_pressed();
            int tarjeta_pedida = matriz_posiciones[1][0];
            int posicion_tarjeta = check_pages(tarjeta_pedida);
            if(posicion_tarjeta !=30){
                page_hits++;
                servidor.send_data(tarjeta_en_memoria[posicion_tarjeta]->get_image());
                qDebug()<<"PAGE HIT";

            }else{
                this->add_tarjeta(tarjeta_pedida);
                 posicion_tarjeta = 0;
                 page_faults++;
                 servidor.send_data(tarjeta_en_memoria[posicion_tarjeta]->get_image());
                   qDebug()<<"PAGE FAULT";
            }
            if(pareja_1==30){
                pareja_1=tarjeta_pedida;
            }else{
                if(pareja_2==30){
                    pareja_2=tarjeta_pedida;
                }
            }
        }

        if(button_pressed==7){
            servidor.reset_button_pressed();
            int tarjeta_pedida = matriz_posiciones[1][1];
            int posicion_tarjeta = check_pages(tarjeta_pedida);
            if(posicion_tarjeta !=30){
                page_hits++;
                servidor.send_data(tarjeta_en_memoria[posicion_tarjeta]->get_image());
                qDebug()<<"PAGE HIT";

            }else{
                this->add_tarjeta(tarjeta_pedida);
                 posicion_tarjeta = 0;
                 page_faults++;
                 servidor.send_data(tarjeta_en_memoria[posicion_tarjeta]->get_image());
                   qDebug()<<"PAGE FAULT";
            }
            if(pareja_1==30){
                pareja_1=tarjeta_pedida;
            }else{
                if(pareja_2==30){
                    pareja_2=tarjeta_pedida;
                }
            }
        }

        if(button_pressed==8){
            servidor.reset_button_pressed();
            int tarjeta_pedida = matriz_posiciones[1][2];
            int posicion_tarjeta = check_pages(tarjeta_pedida);
            if(posicion_tarjeta !=30){
                page_hits++;
                servidor.send_data(tarjeta_en_memoria[posicion_tarjeta]->get_image());
                qDebug()<<"PAGE HIT";


            }else{
                this->add_tarjeta(tarjeta_pedida);
                 posicion_tarjeta = 0;
                 page_faults++;
                 servidor.send_data(tarjeta_en_memoria[posicion_tarjeta]->get_image());
                   qDebug()<<"PAGE FAULT";
            }
            if(pareja_1==30){
                pareja_1=tarjeta_pedida;
            }else{
                if(pareja_2==30){
                    pareja_2=tarjeta_pedida;
                }
            }
        }

        if(button_pressed==9){
            servidor.reset_button_pressed();
            int tarjeta_pedida = matriz_posiciones[1][3];
            int posicion_tarjeta = check_pages(tarjeta_pedida);
            if(posicion_tarjeta !=30){
                page_hits++;
                servidor.send_data(tarjeta_en_memoria[posicion_tarjeta]->get_image());
                qDebug()<<"PAGE HIT";


            }else{
                this->add_tarjeta(tarjeta_pedida);
                 posicion_tarjeta = 0;
                 page_faults++;
                 servidor.send_data(tarjeta_en_memoria[posicion_tarjeta]->get_image());
                   qDebug()<<"PAGE FAULT";
            }
            if(pareja_1==30){
                pareja_1=tarjeta_pedida;
            }else{
                if(pareja_2==30){
                    pareja_2=tarjeta_pedida;
                }
            }
        }

        if(button_pressed==10){
            servidor.reset_button_pressed();
            int tarjeta_pedida = matriz_posiciones[1][4];
            int posicion_tarjeta = check_pages(tarjeta_pedida);
            if(posicion_tarjeta !=30){
                page_hits++;
                servidor.send_data(tarjeta_en_memoria[posicion_tarjeta]->get_image());
                qDebug()<<"PAGE HIT";


            }else{
                this->add_tarjeta(tarjeta_pedida);
                 posicion_tarjeta = 0;
                 page_faults++;
                 servidor.send_data(tarjeta_en_memoria[posicion_tarjeta]->get_image());
                   qDebug()<<"PAGE FAULT";
            }
            if(pareja_1==30){
                pareja_1=tarjeta_pedida;

            }else{
                if(pareja_2==30){
                    pareja_2=tarjeta_pedida;

                }
            }
        }

        if(button_pressed==11){
            servidor.reset_button_pressed();
            int tarjeta_pedida = matriz_posiciones[1][5];
            int posicion_tarjeta = check_pages(tarjeta_pedida);
            if(posicion_tarjeta !=30){
                page_hits++;
                servidor.send_data(tarjeta_en_memoria[posicion_tarjeta]->get_image());
                qDebug()<<"PAGE HIT";


            }else{
                this->add_tarjeta(tarjeta_pedida);
                 posicion_tarjeta = 0;
                 page_faults++;
                 servidor.send_data(tarjeta_en_memoria[posicion_tarjeta]->get_image());
                   qDebug()<<"PAGE FAULT";
            }
            if(pareja_1==30){
                pareja_1=tarjeta_pedida;
            }else{
                if(pareja_2==30){
                    pareja_2=tarjeta_pedida;

                }
            }
        }

        if(button_pressed==12){
            servidor.reset_button_pressed();
            int tarjeta_pedida = matriz_posiciones[2][0];
            int posicion_tarjeta = check_pages(tarjeta_pedida);
            if(posicion_tarjeta !=30){
                page_hits++;
                servidor.send_data(tarjeta_en_memoria[posicion_tarjeta]->get_image());
                qDebug()<<"PAGE HIT";


            }else{
                this->add_tarjeta(tarjeta_pedida);
                 posicion_tarjeta = 0;
                 page_faults++;
                 servidor.send_data(tarjeta_en_memoria[posicion_tarjeta]->get_image());
                   qDebug()<<"PAGE FAULT";
            }
            if(pareja_1==30){
                pareja_1=tarjeta_pedida;
            }else{
                if(pareja_2==30){
                    pareja_2=tarjeta_pedida;
                }
            }
        }

        if(button_pressed==13){
            servidor.reset_button_pressed();
            int tarjeta_pedida = matriz_posiciones[2][1];
            int posicion_tarjeta = check_pages(tarjeta_pedida);
            if(posicion_tarjeta !=30){
                page_hits++;
                servidor.send_data(tarjeta_en_memoria[posicion_tarjeta]->get_image());
                qDebug()<<"PAGE HIT";


            }else{
                this->add_tarjeta(tarjeta_pedida);
                 posicion_tarjeta = 0;
                 page_faults++;
                 servidor.send_data(tarjeta_en_memoria[posicion_tarjeta]->get_image());
                   qDebug()<<"PAGE FAULT";
            }
            if(pareja_1==30){
                pareja_1=tarjeta_pedida;

            }else{
                if(pareja_2==30){
                    pareja_2=tarjeta_pedida;
                }
            }
        }

        if(button_pressed==14){
            servidor.reset_button_pressed();
            int tarjeta_pedida = matriz_posiciones[2][2];
            int posicion_tarjeta = check_pages(tarjeta_pedida);
            if(posicion_tarjeta !=30){
                page_hits++;
                servidor.send_data(tarjeta_en_memoria[posicion_tarjeta]->get_image());
                qDebug()<<"PAGE HIT";


            }else{
                this->add_tarjeta(tarjeta_pedida);
                 posicion_tarjeta = 0;
                 page_faults++;
                 servidor.send_data(tarjeta_en_memoria[posicion_tarjeta]->get_image());
                   qDebug()<<"PAGE FAULT";
            }
            if(pareja_1==30){
                pareja_1=tarjeta_pedida;
            }else{
                if(pareja_2==30){
                    pareja_2=tarjeta_pedida;
                }
            }
        }

        if(button_pressed==15){
            servidor.reset_button_pressed();
            int tarjeta_pedida = matriz_posiciones[2][3];
            int posicion_tarjeta = check_pages(tarjeta_pedida);
            if(posicion_tarjeta !=30){
                page_hits++;
                servidor.send_data(tarjeta_en_memoria[posicion_tarjeta]->get_image());
                qDebug()<<"PAGE HIT";


            }else{
                this->add_tarjeta(tarjeta_pedida);
                 posicion_tarjeta = 0;
                 page_faults++;
                 servidor.send_data(tarjeta_en_memoria[posicion_tarjeta]->get_image());
                   qDebug()<<"PAGE FAULT";
            }
            if(pareja_1==30){
                pareja_1=tarjeta_pedida;
            }else{
                if(pareja_2==30){
                    pareja_2=tarjeta_pedida;
                }
            }
        }

        if(button_pressed==16){
            servidor.reset_button_pressed();
            int tarjeta_pedida = matriz_posiciones[2][4];
            int posicion_tarjeta = check_pages(tarjeta_pedida);
            if(posicion_tarjeta !=30){
                page_hits++;
                servidor.send_data(tarjeta_en_memoria[posicion_tarjeta]->get_image());
                qDebug()<<"PAGE HIT";


            }else{
                this->add_tarjeta(tarjeta_pedida);
                 posicion_tarjeta = 0;
                 page_faults++;
                 servidor.send_data(tarjeta_en_memoria[posicion_tarjeta]->get_image());
                   qDebug()<<"PAGE FAULT";
            }
            if(pareja_1==30){
                pareja_1=tarjeta_pedida;
            }else{
                if(pareja_2==30){
                    pareja_2=tarjeta_pedida;
                }
            }
        }

        if(button_pressed==17){
            servidor.reset_button_pressed();
            int tarjeta_pedida = matriz_posiciones[2][5];
            int posicion_tarjeta = check_pages(tarjeta_pedida);
            if(posicion_tarjeta !=30){
                page_hits++;
                servidor.send_data(tarjeta_en_memoria[posicion_tarjeta]->get_image());
                qDebug()<<"PAGE HIT";


            }else{
                this->add_tarjeta(tarjeta_pedida);
                 posicion_tarjeta = 0;
                 page_faults++;
                 servidor.send_data(tarjeta_en_memoria[posicion_tarjeta]->get_image());
                   qDebug()<<"PAGE FAULT";
            }
            if(pareja_1==30){
                pareja_1=tarjeta_pedida;
            }else{
                if(pareja_2==30){
                    pareja_2=tarjeta_pedida;
                }
            }
        }

    }
}

/**
 * @brief Server::check_pages Busca la tarjeta pedida en las tarjetas cargadas en memoria
 * @param num
 * @return la posición de la tarjeta si está cargada en memoria
 */
int Server::check_pages(int num){
    for (int f = 0; f < std::size(tarjeta_en_memoria); f++){
        if (tarjeta_en_memoria[f]->get_ID() == num){
            return f;
        }
    }
    return 30;
}
/**
 * @brief Server::hay_pareja revisa si entre los botones elegidos tiene el mismo ID para saber si es pareja o no
 */
void Server::hay_pareja(){
    while(1){
        Sleep(1000);
        if (pareja_1 ==30){
              continue;
          }else{
          if (pareja_2 ==30){
              continue;
          }else{
        if(pareja_1 !=30 && pareja_2 !=30 && pareja_1 == pareja_2){
            servidor.send_data("check");
            Sleep(100);
            pareja_1 = 30;
            pareja_2 = 30;
            if(jugador_1_playing){
                puntaje_player1++;
                jugador_1_playing = false;
            }else{
                puntaje_player2++;
                jugador_1_playing = true;
            }

         QImage check ("Imagenes 100x100/check.png");
         int tamaño = check.sizeInBytes();
         memcpy(check_image,check.bits(),tamaño);
         servidor.send_data(check_image);


    }else{
        pareja_1 = 30;
        pareja_2 = 30;

        if(jugador_1_playing){
            jugador_1_playing = false;
        }else{
           jugador_1_playing = true;
        }

        servidor.send_data("reset");
        Sleep(100);

        QImage check ("Imagenes 100x100/yogi.png");
        int tamaño = check.sizeInBytes();
        memcpy(check_image,check.bits(),tamaño);
        servidor.send_data(check_image);


    }
    }
}
}
}


/**
 * @brief Server::add_tarjeta en caso de page fault carga la nueva tarjeta en memoria
 * @param key
 */
void Server::add_tarjeta(int key){
    tarjetas* temp = new tarjetas;
    temp->set_ID(key);
    temp->set_image(game_images_path[key]);
    delete tarjeta_en_memoria[std::size(tarjeta_en_memoria)-1];

    for (int w = std::size(tarjeta_en_memoria)-1 ; w >0 ; w--){
        tarjeta_en_memoria[w] = tarjeta_en_memoria[w-1];
    }
    tarjeta_en_memoria[0]=temp;

    for (int z = 0 ; z < std::size(tarjeta_en_memoria) ; z++){
        qDebug()<<tarjeta_en_memoria[z]->get_ID()<<"ID";
    }
}

/**
 * @brief Server::update_labels Actualiza las labels de la UI del servidor
 */
void Server::update_labels(){
    while(1){
       ui->label_hits->setText(QString::number(page_hits));
       ui->labe_faults->setText(QString::number(page_faults));
       ui->Tarjetas_memoria->setText(tarjetas_memoria_to_string());
       ui->Tarjetas_disco->setText(tarjetas_disc_to_string());
       ui->Memory_usage->setText(memoria_en_uso());
       ui->puntaje1->setText(QString::number(puntaje_player1));
       ui->puntaje2->setText(QString::number(puntaje_player2));
       Sleep(30);
    }
}

/**
 * @brief Server::tarjetas_memoria_to_string crea el string para poner en la label de
 * la UI del servidor para mostrar las tarjetas cargadas
 * @return
 */
QString Server::tarjetas_memoria_to_string(){
    QString aux ="";
    for(int i = 0; i<std::size(tarjeta_en_memoria); i++){
        aux.append("Tarjeta ");
        aux.append(QString::number(tarjeta_en_memoria[i]->get_ID()));
        aux.append("   ");
    }

    return aux;
}

/**
 * @brief Server::tarjetas_disc_to_string crea el string para poner en la label de
 * la UI del servidor y así mostrar las tarjetas en disco
 * @return
 */
QString Server::tarjetas_disc_to_string(){
    QString aux ="";
    int num1 = tarjeta_en_memoria[0]->get_ID();
    int num2 = tarjeta_en_memoria[1]->get_ID();
    int num3 = tarjeta_en_memoria[2]->get_ID();
    for(int i = 0; i < 9; i++){

        if(num1 == i || num2==i || num3==i){
            continue;
        }else{
            aux.append("Tarjeta ");
            aux.append(QString::number(i));
            aux.append("  ");
        }
    }

    return aux;
}

/**
 * @brief Server::memoria_en_uso obtiene la memoria utilizada del proceso actual
 * @return
 */
QString Server::memoria_en_uso(){
    QString result="";
    GetProcessMemoryInfo(GetCurrentProcess(), (PROCESS_MEMORY_COUNTERS*)&process_memory,sizeof(process_memory));
    result = QString::number(process_memory.WorkingSetSize);
    return result;
}

/**
 * @brief Server::on_ingresar_nombre_clicked función para el ingreso de los nombres
 * de los jugadores en la UI del server y luego ser enviados por sockets al cliente
 */
void Server::on_ingresar_nombre_clicked()
{
    if(jugador_1 == "Jugador 1"){
        jugador_1=ui->lineEdit->text();
        ui->label_8->setText("Ingrese el nombre del jugador 2");
        ui->lineEdit->clear();
        ui->label_6->setText("Puntaje de "+jugador_1+":");
    }else{
        if(jugador_2 == "Jugador 2"){
            jugador_2=ui->lineEdit->text();
            ui->lineEdit->clear();
            ui->label_7->setText("Puntaje de "+jugador_2+":");
            ui->ingresar_nombre->setEnabled(false);
            servidor.send_data("set players");
            Sleep(30);

            QByteArray list = jugador_1.toLocal8Bit();
            char* to_send = list.data();
            servidor.send_data(to_send);

            Sleep(30);
            QByteArray list2 = jugador_2.toLocal8Bit();
            char* to_send2 = list2.data();
            servidor.send_data(to_send2);
        }
    }
}
