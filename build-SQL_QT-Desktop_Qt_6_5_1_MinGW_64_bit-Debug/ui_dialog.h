/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 6.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

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

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *Confirmation;
    QTextEdit *User;
    QTextEdit *Passwd;
    QTextEdit *DbName;
    QTextEdit *DbIp;
    QLabel *A;
    QLabel *B;
    QLabel *C;
    QLabel *D;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        Confirmation = new QPushButton(centralwidget);
        Confirmation->setObjectName("Confirmation");
        Confirmation->setGeometry(QRect(570, 450, 121, 51));
        User = new QTextEdit(centralwidget);
        User->setObjectName("User");
        User->setGeometry(QRect(453, 30, 271, 51));
        Passwd = new QTextEdit(centralwidget);
        Passwd->setObjectName("Passwd");
        Passwd->setGeometry(QRect(450, 100, 271, 51));
        DbName = new QTextEdit(centralwidget);
        DbName->setObjectName("DbName");
        DbName->setGeometry(QRect(450, 170, 271, 51));
        DbIp = new QTextEdit(centralwidget);
        DbIp->setObjectName("DbIp");
        DbIp->setGeometry(QRect(450, 240, 271, 51));
        A = new QLabel(centralwidget);
        A->setObjectName("A");
        A->setGeometry(QRect(290, 30, 111, 51));
        B = new QLabel(centralwidget);
        B->setObjectName("B");
        B->setGeometry(QRect(300, 100, 111, 51));
        C = new QLabel(centralwidget);
        C->setObjectName("C");
        C->setGeometry(QRect(300, 170, 111, 51));
        D = new QLabel(centralwidget);
        D->setObjectName("D");
        D->setGeometry(QRect(310, 240, 111, 51));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        Confirmation->setText(QCoreApplication::translate("MainWindow", "Valider", nullptr));
        A->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        B->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        C->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        D->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
