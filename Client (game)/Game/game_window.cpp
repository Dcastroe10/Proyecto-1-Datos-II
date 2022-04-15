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

    qDebug() <<"JEJEJEJEJ";

}



void game_window::on_pushButton_1_clicked()
{
    char* image_to_change = cliente.get_image();
    QImage recieved_image ((uchar*)image_to_change, 100, 100, QImage::Format_ARGB32);
    QPixmap pix_map (QPixmap::fromImage(recieved_image));
    ui->pushButton_1->setIcon(pix_map);
    ui->pushButton_1->setIconSize(QSize(100,100));
    printf("%s\n", image_to_change);
    this->change_button();

/*   FOR THE INICIAL IMAGES ON THE BUTTONS
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






    //std::thread thread_changebutton(&game_window::change_button(),this);
    //thread_changebutton.detach();

}

