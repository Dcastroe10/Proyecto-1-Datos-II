#include "server.h"
#include "ui_server.h"

Server::Server(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Server)
{
    ui->setupUi(this);
    servidor.Start();
    servidor.connect();
    servidor.create_recieve_thread();



}

Server::~Server()
{
    delete ui;
}


void Server::on_pushButton_clicked()
{
    std::cout<<"alala";
    servidor.send_data();

}

