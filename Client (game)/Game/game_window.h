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
    Q_OBJECT

public:
    game_window(QWidget *parent = nullptr);
    ~game_window();
    void change_button();
    void update_button_pressed(int num);
    void reset_pressed();
    void start_image();
    void current_player();


private slots:
    void on_pushButton_1_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_7_clicked();
    void on_pushButton_8_clicked();
    void on_pushButton_9_clicked();
    void on_pushButton_10_clicked();
    void on_pushButton_11_clicked();
    void on_pushButton_12_clicked();
    void on_pushButton_13_clicked();
    void on_pushButton_14_clicked();
    void on_pushButton_15_clicked();
    void on_pushButton_16_clicked();
    void on_pushButton_17_clicked();
    void on_pushButton_18_clicked();

private:
    Client cliente;
    Ui::game_window *ui;
    int button_pressed_1=30; //30 means nothing its just a number to make validations
    int button_pressed_2=30;
    QString jugador_1;
    QString jugador_2;
    bool player_1_playing = true;



};
#endif // GAME_WINDOW_H
