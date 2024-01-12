/********************************************************************************
** Form generated from reading UI file 'PopUp.ui'
**
** Created by: Qt User Interface Compiler version 6.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_POPUP_H
#define UI_POPUP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QMenuBar *menubar;
    QStatusBar *statusbar;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLineEdit *DbIP;
    QLineEdit *DbUser;
    QLineEdit *DbMDP;
    QLineEdit *DbName;
    QLabel *D;
    QLabel *C;
    QLabel *A;
    QLabel *B;
    QPushButton *Confirmation;
    QLabel *EtatDBL;
    QPushButton *Default;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName("Dialog");
        Dialog->resize(263, 264);
        menubar = new QMenuBar(Dialog);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 22));
        statusbar = new QStatusBar(Dialog);
        statusbar->setObjectName("statusbar");
        statusbar->setGeometry(QRect(0, 0, 3, 21));
        gridLayoutWidget = new QWidget(Dialog);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(20, 30, 221, 201));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        DbIP = new QLineEdit(gridLayoutWidget);
        DbIP->setObjectName("DbIP");

        gridLayout->addWidget(DbIP, 2, 1, 1, 1);

        DbUser = new QLineEdit(gridLayoutWidget);
        DbUser->setObjectName("DbUser");

        gridLayout->addWidget(DbUser, 0, 1, 1, 1);

        DbMDP = new QLineEdit(gridLayoutWidget);
        DbMDP->setObjectName("DbMDP");

        gridLayout->addWidget(DbMDP, 1, 1, 1, 1);

        DbName = new QLineEdit(gridLayoutWidget);
        DbName->setObjectName("DbName");

        gridLayout->addWidget(DbName, 3, 1, 1, 1);

        D = new QLabel(gridLayoutWidget);
        D->setObjectName("D");

        gridLayout->addWidget(D, 3, 0, 1, 1);

        C = new QLabel(gridLayoutWidget);
        C->setObjectName("C");

        gridLayout->addWidget(C, 1, 0, 1, 1);

        A = new QLabel(gridLayoutWidget);
        A->setObjectName("A");

        gridLayout->addWidget(A, 2, 0, 1, 1);

        B = new QLabel(gridLayoutWidget);
        B->setObjectName("B");

        gridLayout->addWidget(B, 0, 0, 1, 1);

        Confirmation = new QPushButton(gridLayoutWidget);
        Confirmation->setObjectName("Confirmation");

        gridLayout->addWidget(Confirmation, 5, 1, 1, 1);

        EtatDBL = new QLabel(gridLayoutWidget);
        EtatDBL->setObjectName("EtatDBL");

        gridLayout->addWidget(EtatDBL, 5, 0, 1, 1);

        Default = new QPushButton(Dialog);
        Default->setObjectName("Default");
        Default->setGeometry(QRect(160, 230, 81, 21));

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "MainWindow", nullptr));
        D->setText(QCoreApplication::translate("Dialog", "DatabaseName", nullptr));
        C->setText(QCoreApplication::translate("Dialog", "Password", nullptr));
        A->setText(QCoreApplication::translate("Dialog", "DatabaseIP", nullptr));
        B->setText(QCoreApplication::translate("Dialog", "Username", nullptr));
        Confirmation->setText(QCoreApplication::translate("Dialog", "Valider", nullptr));
        EtatDBL->setText(QString());
        Default->setText(QCoreApplication::translate("Dialog", "Default Value", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_POPUP_H
