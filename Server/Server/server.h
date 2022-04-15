#ifndef SERVER_H
#define SERVER_H

#include <QMainWindow>
#include "server_socket.h"
#include "tarjetas.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Server; }
QT_END_NAMESPACE

class Server : public QMainWindow
{
    Q_OBJECT

public:
    Server(QWidget *parent = nullptr);
    ~Server();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Server *ui;
    Server_socket servidor;
    tarjetas tarjetas[];

};
#endif // SERVER_H
