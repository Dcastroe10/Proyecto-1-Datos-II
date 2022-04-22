/********************************************************************************
** Form generated from reading UI file 'server.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERVER_H
#define UI_SERVER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Server
{
public:
    QWidget *centralwidget;
    QLabel *label_2;
    QLabel *labe_faults;
    QLabel *label_hits;
    QLabel *label;
    QLabel *label_3;
    QLabel *Tarjetas_memoria;
    QLabel *Tarjetas_disco;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *Memory_usage;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *puntaje1;
    QLabel *puntaje2;
    QLabel *label_8;
    QPushButton *ingresar_nombre;
    QLineEdit *lineEdit;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Server)
    {
        if (Server->objectName().isEmpty())
            Server->setObjectName(QString::fromUtf8("Server"));
        Server->resize(826, 532);
        centralwidget = new QWidget(Server);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(30, 120, 381, 71));
        QFont font;
        font.setPointSize(30);
        label_2->setFont(font);
        labe_faults = new QLabel(centralwidget);
        labe_faults->setObjectName(QString::fromUtf8("labe_faults"));
        labe_faults->setGeometry(QRect(300, 110, 221, 81));
        QFont font1;
        font1.setPointSize(20);
        labe_faults->setFont(font1);
        label_hits = new QLabel(centralwidget);
        label_hits->setObjectName(QString::fromUtf8("label_hits"));
        label_hits->setGeometry(QRect(300, 20, 221, 81));
        label_hits->setFont(font1);
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 10, 341, 101));
        label->setFont(font);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(30, 370, 241, 41));
        QFont font2;
        font2.setPointSize(15);
        label_3->setFont(font2);
        Tarjetas_memoria = new QLabel(centralwidget);
        Tarjetas_memoria->setObjectName(QString::fromUtf8("Tarjetas_memoria"));
        Tarjetas_memoria->setGeometry(QRect(270, 370, 541, 41));
        Tarjetas_memoria->setFont(font2);
        Tarjetas_disco = new QLabel(centralwidget);
        Tarjetas_disco->setObjectName(QString::fromUtf8("Tarjetas_disco"));
        Tarjetas_disco->setGeometry(QRect(270, 420, 541, 41));
        Tarjetas_disco->setFont(font2);
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(30, 420, 241, 41));
        label_4->setFont(font2);
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(30, 260, 211, 41));
        label_5->setFont(font2);
        Memory_usage = new QLabel(centralwidget);
        Memory_usage->setObjectName(QString::fromUtf8("Memory_usage"));
        Memory_usage->setGeometry(QRect(230, 260, 241, 41));
        Memory_usage->setFont(font2);
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(410, 240, 261, 41));
        label_6->setFont(font2);
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(410, 290, 261, 41));
        label_7->setFont(font2);
        puntaje1 = new QLabel(centralwidget);
        puntaje1->setObjectName(QString::fromUtf8("puntaje1"));
        puntaje1->setGeometry(QRect(700, 240, 51, 41));
        puntaje1->setFont(font2);
        puntaje2 = new QLabel(centralwidget);
        puntaje2->setObjectName(QString::fromUtf8("puntaje2"));
        puntaje2->setGeometry(QRect(700, 290, 51, 41));
        puntaje2->setFont(font2);
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(510, 30, 271, 22));
        QFont font3;
        font3.setBold(true);
        label_8->setFont(font3);
        ingresar_nombre = new QPushButton(centralwidget);
        ingresar_nombre->setObjectName(QString::fromUtf8("ingresar_nombre"));
        ingresar_nombre->setGeometry(QRect(600, 90, 89, 31));
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(500, 60, 281, 29));
        Server->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Server);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 826, 27));
        Server->setMenuBar(menubar);
        statusbar = new QStatusBar(Server);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Server->setStatusBar(statusbar);

        retranslateUi(Server);

        QMetaObject::connectSlotsByName(Server);
    } // setupUi

    void retranslateUi(QMainWindow *Server)
    {
        Server->setWindowTitle(QCoreApplication::translate("Server", "Server", nullptr));
        label_2->setText(QCoreApplication::translate("Server", "Page Faults:", nullptr));
        labe_faults->setText(QCoreApplication::translate("Server", "0", nullptr));
        label_hits->setText(QCoreApplication::translate("Server", "0", nullptr));
        label->setText(QCoreApplication::translate("Server", "Page Hits:", nullptr));
        label_3->setText(QCoreApplication::translate("Server", "Tarjetas en memoria:", nullptr));
        Tarjetas_memoria->setText(QString());
        Tarjetas_disco->setText(QString());
        label_4->setText(QCoreApplication::translate("Server", "Tarjetas en disco:", nullptr));
        label_5->setText(QCoreApplication::translate("Server", "Uso de memoria: ", nullptr));
        Memory_usage->setText(QString());
        label_6->setText(QCoreApplication::translate("Server", "Puntaje Jugador 1:", nullptr));
        label_7->setText(QCoreApplication::translate("Server", "Puntaje Jugador 2:", nullptr));
        puntaje1->setText(QCoreApplication::translate("Server", "0", nullptr));
        puntaje2->setText(QCoreApplication::translate("Server", "0", nullptr));
        label_8->setText(QCoreApplication::translate("Server", "Ingrese el nombre del jugador 1", nullptr));
        ingresar_nombre->setText(QCoreApplication::translate("Server", "Ingresar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Server: public Ui_Server {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERVER_H
