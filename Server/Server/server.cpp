#include "server.h"
#include "ui_server.h"
#include "tarjetas.h"

Server::Server(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Server)
{
    ui->setupUi(this);
    servidor.Start();
    servidor.connect();
    //servidor.create_recieve_thread();



}

Server::~Server()
{
    delete ui;
}


void Server::on_pushButton_clicked()
{
    servidor.send_data();
    qDebug()<<"data enviada \n";
}

