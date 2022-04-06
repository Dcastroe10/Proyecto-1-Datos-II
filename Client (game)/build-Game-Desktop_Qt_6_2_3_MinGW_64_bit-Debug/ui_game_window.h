/********************************************************************************
** Form generated from reading UI file 'game_window.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAME_WINDOW_H
#define UI_GAME_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_game_window
{
public:
    QWidget *centralwidget;
    QTextEdit *textEdit;
    QPushButton *pushButton;
    QLabel *label_de_prueba;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *game_window)
    {
        if (game_window->objectName().isEmpty())
            game_window->setObjectName(QString::fromUtf8("game_window"));
        game_window->resize(800, 600);
        centralwidget = new QWidget(game_window);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(20, 110, 461, 51));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(270, 220, 301, 111));
        label_de_prueba = new QLabel(centralwidget);
        label_de_prueba->setObjectName(QString::fromUtf8("label_de_prueba"));
        label_de_prueba->setGeometry(QRect(160, 310, 301, 71));
        game_window->setCentralWidget(centralwidget);
        menubar = new QMenuBar(game_window);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 27));
        game_window->setMenuBar(menubar);
        statusbar = new QStatusBar(game_window);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        game_window->setStatusBar(statusbar);

        retranslateUi(game_window);

        QMetaObject::connectSlotsByName(game_window);
    } // setupUi

    void retranslateUi(QMainWindow *game_window)
    {
        game_window->setWindowTitle(QCoreApplication::translate("game_window", "game_window", nullptr));
        pushButton->setText(QCoreApplication::translate("game_window", "Send message", nullptr));
        label_de_prueba->setText(QCoreApplication::translate("game_window", "Empty", nullptr));
    } // retranslateUi

};

namespace Ui {
    class game_window: public Ui_game_window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAME_WINDOW_H
