#ifndef SERVER_H
#define SERVER_H

#include <QMainWindow>
#include<stdlib.h>
#include "server_socket.h"
#include "tarjetas.h"
#include <ctime>
#include<unistd.h>
#include <QString>

QT_BEGIN_NAMESPACE
namespace Ui { class Server; }
QT_END_NAMESPACE

class Server : public QMainWindow
{
    Q_OBJECT

public:
    Server(QWidget *parent = nullptr);
    ~Server();

    void random_array(int playing_cards[]);

    void create_matrix(int mixed_list[]);

    bool used(bool usados[]);

    void logic();

    int check_pages(int num);

    void add_tarjeta(int key);

    void update_labels();





private slots:
    void on_pushButton_clicked();

private:
    Ui::Server *ui;
    Server_socket servidor;

    char *game_images_path [9] = {"Imagenes 100x100/bear.png","Imagenes 100x100/fox.png",
                                   "Imagenes 100x100/leopard.png","Imagenes 100x100/lion.png",
                                   "Imagenes 100x100/mouse.png","Imagenes 100x100/panda.png",
                                  "Imagenes 100x100/pig.png","Imagenes 100x100/rabbit.png",
                                  "Imagenes 100x100/tiger.png"};


    int IDs[9] = {0,1,2,3,4,5,6,7,8};

    char *button_images [2]; //ADD IMAGES

    int matriz_posiciones[3][6]= {{30,30,30,30,30,30},
                                  {30,30,30,30,30,30},
                                  {30,30,30,30,30,30}};

    int ingame_card[18]={0,0,1,1,2,2,3,3,4,4,5,5,6,6,7,7,8,8};


    tarjetas* tarjeta_0 = new tarjetas;
    tarjetas* tarjeta_1 = new tarjetas;
    tarjetas* tarjeta_2 = new tarjetas;

    tarjetas tarjetas_matriz [6][3]; //no creo usarla para aplicar lo de memoria
    tarjetas* tarjeta_en_memoria[3]={tarjeta_0,tarjeta_1,tarjeta_2};  //tercera parte de la cantidad total de tarjeta

    int page_hits = 0;
    int page_faults = 0;


};
#endif // SERVER_H
