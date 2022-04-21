#include "game_window.h"
#include "ui_game_window.h"
#include "client_socket.h"

#include <QDebug>


game_window::game_window(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::game_window)

{
    ui->setupUi(this);
    cliente.create_client();
    cliente.create_recieve_thread();

    std::thread thread_set(&game_window::start_image, this);
    thread_set.detach();

    std::thread thread_all(&game_window::change_button, this);
    thread_all.detach();
}

game_window::~game_window()
{
    delete ui;
}

/**
 * @brief game_window::current_player Actualiza el label que indica de quien es el turno de jugar
 */
void game_window::current_player(){
    Sleep(10);
    if(player_1_playing){
        ui->turno->setText(jugador_1);
    }else{
        ui->turno->setText(jugador_2);
    }
}

/**
 * @brief game_window::start_image le asigna la imagen inicial a todos los botones de juego
 */
void game_window::start_image(){
    Sleep(200);
    char* image_to_change = cliente.get_image();
    QImage recieved_image ((uchar*)image_to_change, 100, 100, QImage::Format_ARGB32);
    QPixmap pix_map (QPixmap::fromImage(recieved_image));

    ui->pushButton_1->setIcon(pix_map);
    ui->pushButton_1->setIconSize(QSize(100,100));

    ui->pushButton_2->setIcon(pix_map);
    ui->pushButton_2->setIconSize(QSize(100,100));

    ui->pushButton_3->setIcon(pix_map);
    ui->pushButton_3->setIconSize(QSize(100,100));

    ui->pushButton_4->setIcon(pix_map);
    ui->pushButton_4->setIconSize(QSize(100,100));

    ui->pushButton_5->setIcon(pix_map);
    ui->pushButton_5->setIconSize(QSize(100,100));

    ui->pushButton_6->setIcon(pix_map);
    ui->pushButton_6->setIconSize(QSize(100,100));

    ui->pushButton_7->setIcon(pix_map);
    ui->pushButton_7->setIconSize(QSize(100,100));

    ui->pushButton_8->setIcon(pix_map);
    ui->pushButton_8->setIconSize(QSize(100,100));

    ui->pushButton_9->setIcon(pix_map);
    ui->pushButton_9->setIconSize(QSize(100,100));

    ui->pushButton_10->setIcon(pix_map);
    ui->pushButton_10->setIconSize(QSize(100,100));

    ui->pushButton_11->setIcon(pix_map);
    ui->pushButton_11->setIconSize(QSize(100,100));

    ui->pushButton_11->setIcon(pix_map);
    ui->pushButton_11->setIconSize(QSize(100,100));

    ui->pushButton_12->setIcon(pix_map);
    ui->pushButton_12->setIconSize(QSize(100,100));

    ui->pushButton_13->setIcon(pix_map);
    ui->pushButton_13->setIconSize(QSize(100,100));

    ui->pushButton_14->setIcon(pix_map);
    ui->pushButton_14->setIconSize(QSize(100,100));

    ui->pushButton_15->setIcon(pix_map);
    ui->pushButton_15->setIconSize(QSize(100,100));

    ui->pushButton_16->setIcon(pix_map);
    ui->pushButton_16->setIconSize(QSize(100,100));

    ui->pushButton_17->setIcon(pix_map);
    ui->pushButton_17->setIconSize(QSize(100,100));

    ui->pushButton_18->setIcon(pix_map);
    ui->pushButton_18->setIconSize(QSize(100,100));


}

/**
 * @brief game_window::change_button Es la función principal del cliente
 * obtiene el valor de order del client_socket para así saber que debe hacer
 * cambia las imágenes, actualiza el turno del jugador, desactiva botones, entre otras.
 */
void game_window::change_button(){
    while (1){
        Sleep(8);
        if (cliente.get_order() == 0){    //actualiza la imagen enviada por el servidor a la hora de darle click al boton
            Sleep(200);
            char* image_to_change = cliente.get_image();
            QImage recieved_image ((uchar*)image_to_change, 100, 100, QImage::Format_ARGB32);
            QPixmap pix_map (QPixmap::fromImage(recieved_image));

            if(button_pressed_1 ==1 || button_pressed_2 ==1){
                ui->pushButton_1->setIcon(pix_map);
                ui->pushButton_1->setIconSize(QSize(100,100));

            }
            if(button_pressed_1 ==2 || button_pressed_2 ==2){
                ui->pushButton_2->setIcon(pix_map);
                ui->pushButton_2->setIconSize(QSize(100,100));

            }
            if(button_pressed_1 ==3 || button_pressed_2 ==3){
                ui->pushButton_3->setIcon(pix_map);
                ui->pushButton_3->setIconSize(QSize(100,100));

            }
            if(button_pressed_1 ==4 || button_pressed_2 ==4){
                ui->pushButton_4->setIcon(pix_map);
                ui->pushButton_4->setIconSize(QSize(100,100));

            }
            if(button_pressed_1 ==5 || button_pressed_2 ==5){
                ui->pushButton_5->setIcon(pix_map);
                ui->pushButton_5->setIconSize(QSize(100,100));

            }
            if(button_pressed_1 ==6 || button_pressed_2 ==6){
                ui->pushButton_6->setIcon(pix_map);
                ui->pushButton_6->setIconSize(QSize(100,100)); //change label

            }
            if(button_pressed_1 ==7 || button_pressed_2 ==7){
                ui->pushButton_7->setIcon(pix_map);
                ui->pushButton_7->setIconSize(QSize(100,100));

            }
            if(button_pressed_1 ==8 || button_pressed_2 ==8){
                ui->pushButton_8->setIcon(pix_map);
                ui->pushButton_8->setIconSize(QSize(100,100));

            }
            if(button_pressed_1 ==9 || button_pressed_2 ==9){
                ui->pushButton_9->setIcon(pix_map);
                ui->pushButton_9->setIconSize(QSize(100,100));

            }
            if(button_pressed_1 ==10 || button_pressed_2 ==10){
                ui->pushButton_10->setIcon(pix_map);
                ui->pushButton_10->setIconSize(QSize(100,100));
            }
            if(button_pressed_1 ==11 || button_pressed_2 ==11){
                ui->pushButton_11->setIcon(pix_map);
                ui->pushButton_11->setIconSize(QSize(100,100));
            }
            if(button_pressed_1 ==12 || button_pressed_2 ==12){
                ui->pushButton_12->setIcon(pix_map);
                ui->pushButton_12->setIconSize(QSize(100,100));
            }
            if(button_pressed_1 ==13 || button_pressed_2 ==13){
                ui->pushButton_13->setIcon(pix_map);
                ui->pushButton_13->setIconSize(QSize(100,100));
            }
            if(button_pressed_1 ==14 || button_pressed_2 ==14){
                ui->pushButton_14->setIcon(pix_map);
                ui->pushButton_14->setIconSize(QSize(100,100));
            }
            if(button_pressed_1 ==15 || button_pressed_2 ==15){
                ui->pushButton_15->setIcon(pix_map);
                ui->pushButton_15->setIconSize(QSize(100,100));
            }
            if(button_pressed_1 ==16 || button_pressed_2 ==16){
                ui->pushButton_16->setIcon(pix_map);
                ui->pushButton_16->setIconSize(QSize(100,100));
            }
            if(button_pressed_1 ==17 || button_pressed_2 ==17){
                ui->pushButton_17->setIcon(pix_map);
                ui->pushButton_17->setIconSize(QSize(100,100));
            }
            if(button_pressed_1 ==18 || button_pressed_2 ==18){
                ui->pushButton_18->setIcon(pix_map);
                ui->pushButton_18->setIconSize(QSize(100,100));
            }

            cliente.set_order(4);
            this->reset_pressed();
            this->current_player();
        }

        if(cliente.get_order()==1){  //Cambia la imagen cuando es par
            Sleep(200);
            char* image_to_change = cliente.get_image();
            QImage recieved_image ((uchar*)image_to_change, 100, 100, QImage::Format_ARGB32);
            QPixmap pix_map (QPixmap::fromImage(recieved_image));

            if(button_pressed_1 ==1 || button_pressed_2 ==1){
                ui->pushButton_1->setIcon(pix_map);
                ui->pushButton_1->setIconSize(QSize(100,100));
                ui->pushButton_1->setEnabled(false);
            }
            if(button_pressed_1 ==2 || button_pressed_2 ==2){
                ui->pushButton_2->setIcon(pix_map);
                ui->pushButton_2->setIconSize(QSize(100,100));
                ui->pushButton_2->setEnabled(false);
            }
            if(button_pressed_1 ==3 || button_pressed_2 ==3){
                ui->pushButton_3->setIcon(pix_map);
                ui->pushButton_3->setIconSize(QSize(100,100));
                ui->pushButton_3->setEnabled(false);
            }
            if(button_pressed_1 ==4 || button_pressed_2 ==4){
                ui->pushButton_4->setIcon(pix_map);
                ui->pushButton_4->setIconSize(QSize(100,100));
                ui->pushButton_4->setEnabled(false);
            }
            if(button_pressed_1 ==5 || button_pressed_2 ==5){
                ui->pushButton_5->setIcon(pix_map);
                ui->pushButton_5->setIconSize(QSize(100,100));
                ui->pushButton_5->setEnabled(false);
            }
            if(button_pressed_1 ==6 || button_pressed_2 ==6){
                ui->pushButton_6->setIcon(pix_map);
                ui->pushButton_6->setIconSize(QSize(100,100));
                ui->pushButton_6->setEnabled(false);
            }
            if(button_pressed_1 ==7 || button_pressed_2 ==7){
                ui->pushButton_7->setIcon(pix_map);
                ui->pushButton_7->setIconSize(QSize(100,100));
                ui->pushButton_7->setEnabled(false);
            }
            if(button_pressed_1 ==8 || button_pressed_2 ==8){
                ui->pushButton_8->setIcon(pix_map);
                ui->pushButton_8->setIconSize(QSize(100,100));
                ui->pushButton_8->setEnabled(false);
            }
            if(button_pressed_1 ==9 || button_pressed_2 ==9){
                ui->pushButton_9->setIcon(pix_map);
                ui->pushButton_9->setIconSize(QSize(100,100));
                ui->pushButton_9->setEnabled(false);
            }
            if(button_pressed_1 ==10 || button_pressed_2 ==10){
                ui->pushButton_10->setIcon(pix_map);
                ui->pushButton_10->setIconSize(QSize(100,100));
                ui->pushButton_10->setEnabled(false);
            }
            if(button_pressed_1 ==11 || button_pressed_2 ==11){
                ui->pushButton_11->setIcon(pix_map);
                ui->pushButton_11->setIconSize(QSize(100,100));
                ui->pushButton_11->setEnabled(false);
            }
            if(button_pressed_1 ==12 || button_pressed_2 ==12){
                ui->pushButton_12->setIcon(pix_map);
                ui->pushButton_12->setIconSize(QSize(100,100));
                ui->pushButton_12->setEnabled(false);
            }
            if(button_pressed_1 ==13 || button_pressed_2 ==13){
                ui->pushButton_13->setIcon(pix_map);
                ui->pushButton_13->setIconSize(QSize(100,100));
                ui->pushButton_13->setEnabled(false);
            }
            if(button_pressed_1 ==14 || button_pressed_2 ==14){
                ui->pushButton_14->setIcon(pix_map);
                ui->pushButton_14->setIconSize(QSize(100,100));
                ui->pushButton_14->setEnabled(false);
            }
            if(button_pressed_1 ==15 || button_pressed_2 ==15){
                ui->pushButton_15->setIcon(pix_map);
                ui->pushButton_15->setIconSize(QSize(100,100));
                ui->pushButton_15->setEnabled(false);
            }
            if(button_pressed_1 ==16 || button_pressed_2 ==16){
                ui->pushButton_16->setIcon(pix_map);
                ui->pushButton_16->setIconSize(QSize(100,100));
                ui->pushButton_16->setEnabled(false);
            }
            if(button_pressed_1 ==17 || button_pressed_2 ==17){
                ui->pushButton_17->setIcon(pix_map);
                ui->pushButton_17->setIconSize(QSize(100,100));
                ui->pushButton_17->setEnabled(false);
            }
            if(button_pressed_1 ==18 || button_pressed_2 ==18){
                ui->pushButton_18->setIcon(pix_map);
                ui->pushButton_18->setIconSize(QSize(100,100));
                ui->pushButton_18->setEnabled(false);
            }

            cliente.set_order(4);
            this->reset_pressed();
        }

        if(cliente.get_order()==2){
            this->start_image();
            cliente.reset_order();
        }

        if(cliente.get_order()==3){  //Para saber el nombre del jugar y el turno de los mismos
            jugador_1 = cliente.get_player1();
            Sleep(30);
            jugador_2 = cliente.get_player2();
            this->current_player();
            cliente.reset_order();
        }

        if(cliente.get_order()==4){  //Para los cambios de turno de jugadores
            if(player_1_playing){
                player_1_playing=false;
            }else{
                player_1_playing=true;
            }
            if(player_1_playing){
                ui->turno->setText(jugador_1);
            }
            if(!player_1_playing){
                ui->turno->setText(jugador_2);
            }
            this->current_player();
            cliente.reset_order();
            continue;
        }

    }
}


/**
 * @brief game_window::update_button_pressed Modifica el botón presionado para saber que botón cambiar
 * tomando en cuenta la respuesta del server
 * @param num
 */
void game_window::update_button_pressed(int num){
    if(button_pressed_1==30){
        button_pressed_1 = num;
    }else{
        if(button_pressed_2 ==30){
            button_pressed_2 = num;
        }
    }
}

/**
 * @brief game_window::reset_pressed EL valor 30 es sinónimo de nada en este caso, es para reiniciar que botón
 * estaba presionado
 */
void game_window::reset_pressed(){
    button_pressed_1 = 30;
    button_pressed_2 = 30;
}


void game_window::on_pushButton_1_clicked()
{
    cliente.send_data("cero,cero");
    update_button_pressed(1);
    Sleep(100);
    char* image_to_change = cliente.get_image();
    QImage recieved_image ((uchar*)image_to_change, 100, 100, QImage::Format_ARGB32);
    QPixmap pix_map (QPixmap::fromImage(recieved_image));
    ui->pushButton_1->setIcon(pix_map);
    ui->pushButton_1->setIconSize(QSize(100,100));
}

void game_window::on_pushButton_2_clicked()
{
    cliente.send_data("cero,uno");
    update_button_pressed(2);
    Sleep(100);
    char* image_to_change = cliente.get_image();
    QImage recieved_image ((uchar*)image_to_change, 100, 100, QImage::Format_ARGB32);
    QPixmap pix_map (QPixmap::fromImage(recieved_image));
    ui->pushButton_2->setIcon(pix_map);
    ui->pushButton_2->setIconSize(QSize(100,100));
}

void game_window::on_pushButton_3_clicked()
{
     cliente.send_data("cero,dos");
     update_button_pressed(3);
     Sleep(100);
     char* image_to_change = cliente.get_image();
     QImage recieved_image ((uchar*)image_to_change, 100, 100, QImage::Format_ARGB32);
     QPixmap pix_map (QPixmap::fromImage(recieved_image));
     ui->pushButton_3->setIcon(pix_map);
     ui->pushButton_3->setIconSize(QSize(100,100));

}

void game_window::on_pushButton_4_clicked()
{
     cliente.send_data("cero,tres");
     update_button_pressed(4);
     Sleep(100);
     char* image_to_change = cliente.get_image();
     QImage recieved_image ((uchar*)image_to_change, 100, 100, QImage::Format_ARGB32);
     QPixmap pix_map (QPixmap::fromImage(recieved_image));
     ui->pushButton_4->setIcon(pix_map);
     ui->pushButton_4->setIconSize(QSize(100,100));

}

void game_window::on_pushButton_5_clicked()
{
     cliente.send_data("cero,cuatro");
     update_button_pressed(5);
     Sleep(100);
     char* image_to_change = cliente.get_image();
     QImage recieved_image ((uchar*)image_to_change, 100, 100, QImage::Format_ARGB32);
     QPixmap pix_map (QPixmap::fromImage(recieved_image));
     ui->pushButton_5->setIcon(pix_map);
     ui->pushButton_5->setIconSize(QSize(100,100));
}

void game_window::on_pushButton_6_clicked()
{
     cliente.send_data("cero,cinco");
     update_button_pressed(6);
     Sleep(100);
     char* image_to_change = cliente.get_image();
     QImage recieved_image ((uchar*)image_to_change, 100, 100, QImage::Format_ARGB32);
     QPixmap pix_map (QPixmap::fromImage(recieved_image));
     ui->pushButton_6->setIcon(pix_map);
     ui->pushButton_6->setIconSize(QSize(100,100));
}

void game_window::on_pushButton_7_clicked()
{
     cliente.send_data("uno,cero");
     update_button_pressed(7);
     Sleep(100);
     char* image_to_change = cliente.get_image();
     QImage recieved_image ((uchar*)image_to_change, 100, 100, QImage::Format_ARGB32);
     QPixmap pix_map (QPixmap::fromImage(recieved_image));
     ui->pushButton_7->setIcon(pix_map);
     ui->pushButton_7->setIconSize(QSize(100,100));
}

void game_window::on_pushButton_8_clicked()
{
     cliente.send_data("uno,uno");
     update_button_pressed(8);
     Sleep(100);
     char* image_to_change = cliente.get_image();
     QImage recieved_image ((uchar*)image_to_change, 100, 100, QImage::Format_ARGB32);
     QPixmap pix_map (QPixmap::fromImage(recieved_image));
     ui->pushButton_8->setIcon(pix_map);
     ui->pushButton_8->setIconSize(QSize(100,100));
}

void game_window::on_pushButton_9_clicked()
{
    cliente.send_data("uno,dos");
    update_button_pressed(9);
    Sleep(100);
    char* image_to_change = cliente.get_image();
    QImage recieved_image ((uchar*)image_to_change, 100, 100, QImage::Format_ARGB32);
    QPixmap pix_map (QPixmap::fromImage(recieved_image));
    ui->pushButton_9->setIcon(pix_map);
    ui->pushButton_9->setIconSize(QSize(100,100));
}

void game_window::on_pushButton_10_clicked()
{
    cliente.send_data("uno,tres");
    update_button_pressed(10);
    Sleep(100);
    char* image_to_change = cliente.get_image();
    QImage recieved_image ((uchar*)image_to_change, 100, 100, QImage::Format_ARGB32);
    QPixmap pix_map (QPixmap::fromImage(recieved_image));
    ui->pushButton_10->setIcon(pix_map);
    ui->pushButton_10->setIconSize(QSize(100,100));
}

void game_window::on_pushButton_11_clicked()
{
    cliente.send_data("uno,cuatro");
    update_button_pressed(11);
    Sleep(100);
    char* image_to_change = cliente.get_image();
    QImage recieved_image ((uchar*)image_to_change, 100, 100, QImage::Format_ARGB32);
    QPixmap pix_map (QPixmap::fromImage(recieved_image));
    ui->pushButton_11->setIcon(pix_map);
    ui->pushButton_11->setIconSize(QSize(100,100));
}

void game_window::on_pushButton_12_clicked()
{
    cliente.send_data("uno,cinco");
    update_button_pressed(12);
    Sleep(100);
    char* image_to_change = cliente.get_image();
    QImage recieved_image ((uchar*)image_to_change, 100, 100, QImage::Format_ARGB32);
    QPixmap pix_map (QPixmap::fromImage(recieved_image));
    ui->pushButton_12->setIcon(pix_map);
    ui->pushButton_12->setIconSize(QSize(100,100));
}

void game_window::on_pushButton_13_clicked()
{
    cliente.send_data("dos,cero");
    update_button_pressed(13);
    Sleep(100);
    char* image_to_change = cliente.get_image();
    QImage recieved_image ((uchar*)image_to_change, 100, 100, QImage::Format_ARGB32);
    QPixmap pix_map (QPixmap::fromImage(recieved_image));
    ui->pushButton_13->setIcon(pix_map);
    ui->pushButton_13->setIconSize(QSize(100,100));
}

void game_window::on_pushButton_14_clicked()
{
    cliente.send_data("dos,uno");
    update_button_pressed(14);
    Sleep(100);
    char* image_to_change = cliente.get_image();
    QImage recieved_image ((uchar*)image_to_change, 100, 100, QImage::Format_ARGB32);
    QPixmap pix_map (QPixmap::fromImage(recieved_image));
    ui->pushButton_14->setIcon(pix_map);
    ui->pushButton_14->setIconSize(QSize(100,100));
}

void game_window::on_pushButton_15_clicked()
{
    cliente.send_data("dos,dos");
    update_button_pressed(15);
    Sleep(100);
    char* image_to_change = cliente.get_image();
    QImage recieved_image ((uchar*)image_to_change, 100, 100, QImage::Format_ARGB32);
    QPixmap pix_map (QPixmap::fromImage(recieved_image));
    ui->pushButton_15->setIcon(pix_map);
    ui->pushButton_15->setIconSize(QSize(100,100));
}

void game_window::on_pushButton_16_clicked()
{
    cliente.send_data("dos,tres");
    update_button_pressed(16);
    Sleep(100);
    char* image_to_change = cliente.get_image();
    QImage recieved_image ((uchar*)image_to_change, 100, 100, QImage::Format_ARGB32);
    QPixmap pix_map (QPixmap::fromImage(recieved_image));
    ui->pushButton_16->setIcon(pix_map);
    ui->pushButton_16->setIconSize(QSize(100,100));
}

void game_window::on_pushButton_17_clicked()
{
    cliente.send_data("dos,cuatro");
    update_button_pressed(17);
    Sleep(100);
    char* image_to_change = cliente.get_image();
    QImage recieved_image ((uchar*)image_to_change, 100, 100, QImage::Format_ARGB32);
    QPixmap pix_map (QPixmap::fromImage(recieved_image));
    ui->pushButton_17->setIcon(pix_map);
    ui->pushButton_17->setIconSize(QSize(100,100));
}

void game_window::on_pushButton_18_clicked()
{
    cliente.send_data("dos,cinco");
    update_button_pressed(18);
    Sleep(100);
    char* image_to_change = cliente.get_image();
    QImage recieved_image ((uchar*)image_to_change, 100, 100, QImage::Format_ARGB32);
    QPixmap pix_map (QPixmap::fromImage(recieved_image));
    ui->pushButton_18->setIcon(pix_map);
    ui->pushButton_18->setIconSize(QSize(100,100));

}
