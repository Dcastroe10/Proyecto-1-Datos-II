#include "game_window.h"
#include "ui_game_window.h"
#include "client_socket.h"

#include <QtDebug>


game_window::game_window(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::game_window)
{
    ui->setupUi(this);
    cliente.create_client();
    cliente.create_recieve_thread();
}

game_window::~game_window()
{
    delete ui;
}



void game_window::on_pushButton_clicked()
{
    //std::cout <<"sirve el boton";
    QString text = ui->textEdit->toPlainText();
    qDebug()<<text;

    cliente.send_data();

    //game_window::on_label_de_prueba.text

    ui->label_de_prueba->setText(text); //para cambiar el texto de un label



}

