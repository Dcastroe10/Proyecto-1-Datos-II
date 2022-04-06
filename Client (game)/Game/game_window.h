#ifndef GAME_WINDOW_H
#define GAME_WINDOW_H

#include <QMainWindow>
#include "client_socket.h"

QT_BEGIN_NAMESPACE
namespace Ui { class game_window; }
QT_END_NAMESPACE

class game_window : public QMainWindow
{
public:

    Q_OBJECT //MOVI ESTO PARA PODER PONER VARIABLES INICIALMENTE ESTABA AFUERA

public:


    game_window(QWidget *parent = nullptr);
    ~game_window();




private slots:


    void on_pushButton_clicked();


    void on_label_de_prueba_linkActivated(const QString &link);

private:
    Client cliente;
    Ui::game_window *ui;


};
#endif // GAME_WINDOW_H
