#include "game.h"
#include "ui_game.h"

#include <QMessageBox>

game::game(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::game)
{
    ui->setupUi(this);
}

game::~game()
{
    delete ui;
}


void game::on_pushButton_2_clicked()
{
  QMessageBox::information(this,"Hola","Prueba");

}

