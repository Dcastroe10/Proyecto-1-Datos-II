#ifndef GAME_WINDOW_H
#define GAME_WINDOW_H

#include <QMainWindow>
#include <thread>
#include <QPixmap>
#include <string.h>
#include <QDebug>
#include "client_socket.h"

QT_BEGIN_NAMESPACE
namespace Ui { class game_window; }
QT_END_NAMESPACE

class game_window : public QMainWindow
{
public:

    Q_OBJECT






    void change_button();
    void prueba();

public:
    game_window(QWidget *parent = nullptr);
    ~game_window();




private slots:
    void on_pushButton_clicked();

    void on_pushButton_1_clicked();

private:
    Client cliente;
    Ui::game_window *ui;


};
#endif // GAME_WINDOW_H
