#include "client.h"
#include "./ui_client.h"
#include "iostream"
#include <QtCore>
#include <QtGui>
#include <QMessageBox>

#include "server.h"

using namespace std;

Client::Client(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Client)
{
    ui->setupUi(this);
}

Client::~Client()
{
    delete ui;
}


void Client::on_Boton_prueba_clicked()
{
    QMessageBox::information(this,"Hola","Prueba");
    printf("pepe");


}

