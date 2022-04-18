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

    this->change_button(); //revisar que hace, rn no sirve de nada

}

game_window::~game_window()
{
    delete ui;
}


void game_window::change_button(){

    //std::thread pleh(&game_window::prueba,this); //SIN PARÉNTESIS
    //pleh.detach();

    //std::thread button_thread(&game_window::change_button, this);
    //button_thread.detach();



}



void game_window::on_pushButton_1_clicked()
{
    cliente.send_data("cero,cero");
    Sleep(100);
    char* image_to_change = cliente.get_image();
    QImage recieved_image ((uchar*)image_to_change, 100, 100, QImage::Format_ARGB32);
    QPixmap pix_map (QPixmap::fromImage(recieved_image));
    ui->pushButton_1->setIcon(pix_map);
    ui->pushButton_1->setIconSize(QSize(100,100));
    printf("%s\n", image_to_change);
    //this->change_button();

    /*
    char* image_to_change = cliente.get_image();
    QImage recieved_image ((uchar*)image_to_change, 100, 100, QImage::Format_ARGB32);
    QPixmap pix_map (QPixmap::fromImage(recieved_image));
    ui->pushButton_1->setIcon(pix_map);
    ui->pushButton_1->setIconSize(QSize(100,100));
    printf("%s\n", image_to_change);
    this->change_button();
    */

/*
    FOR THE INICIAL IMAGES ON THE BUTTONS
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

*/
}

void game_window::on_pushButton_2_clicked()
{
    cliente.send_data("cero,uno");
    /*
    char* image_to_change = cliente.get_image();
    QImage recieved_image ((uchar*)image_to_change, 100, 100, QImage::Format_ARGB32);
    QPixmap pix_map (QPixmap::fromImage(recieved_image));
    ui->pushButton_2->setIcon(pix_map);
    ui->pushButton_2->setIconSize(QSize(100,100));
    printf("%s\n", image_to_change);
    */

}


void game_window::on_pushButton_3_clicked()
{
     cliente.send_data("cero,dos");

}

void game_window::on_pushButton_4_clicked()
{
     cliente.send_data("cero,tres");
}

void game_window::on_pushButton_5_clicked()
{
     cliente.send_data("cero,cuatro");
}

void game_window::on_pushButton_6_clicked()
{
     cliente.send_data("cero,cinco");
}

void game_window::on_pushButton_7_clicked()
{
     cliente.send_data("uno,cero");
}

void game_window::on_pushButton_8_clicked()
{
     cliente.send_data("uno,uno");
}

void game_window::on_pushButton_9_clicked()
{
    cliente.send_data("uno,dos");
}

void game_window::on_pushButton_10_clicked()
{
    cliente.send_data("uno,tres");
}

void game_window::on_pushButton_11_clicked()
{
    cliente.send_data("uno,cuatro");
}

void game_window::on_pushButton_12_clicked()
{
    cliente.send_data("uno,cinco");
}

void game_window::on_pushButton_13_clicked()
{
    cliente.send_data("dos,cero");
}

void game_window::on_pushButton_14_clicked()
{
    cliente.send_data("dos,uno");
}

void game_window::on_pushButton_15_clicked()
{
    cliente.send_data("dos,dos");
}

void game_window::on_pushButton_16_clicked()
{
    cliente.send_data("dos,tres");
}

void game_window::on_pushButton_17_clicked()
{
    cliente.send_data("dos,cuatro");
}

void game_window::on_pushButton_18_clicked()
{
    cliente.send_data("dos,cinco");
}
