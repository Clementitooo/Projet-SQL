/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *TabMain;
    QWidget *centralwidget_2;
    QFrame *API;
    QPushButton *Quit;
    QFrame *Gestionnaire;
    QLabel *GestionnaireL;
    QFrame *BarDB;
    QLabel *EtatDBL;
    QFrame *BarRequete;
    QLabel *EtatRequeteL;
    QLabel *RegistreL;
    QLabel *IndicationRegistre;
    QPushButton *Log;
    QComboBox *Menu;
    QComboBox *Selection;
    QLineEdit *RequestLine;
    QPushButton *Drop;
    QTableView *AfficheSQL;
    QTableView *ListeTable;
    QLineEdit *CompleteInfo;
    QLabel *Topic;
    QLabel *TableSelectionner;
    QLabel *label;
    QWidget *TabLog;
    QTabWidget *MenuLog;
    QWidget *SQL;
    QTextEdit *LogSQL;
    QWidget *DataBase;
    QTextEdit *LogDB;
    QPushButton *Clear;
    QPushButton *Sauvegarder;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(844, 627);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(30, 20, 801, 591));
        TabMain = new QWidget();
        TabMain->setObjectName("TabMain");
        centralwidget_2 = new QWidget(TabMain);
        centralwidget_2->setObjectName("centralwidget_2");
        centralwidget_2->setGeometry(QRect(-720, -20, 805, 611));
        API = new QFrame(TabMain);
        API->setObjectName("API");
        API->setGeometry(QRect(0, 0, 781, 551));
        API->setFrameShape(QFrame::StyledPanel);
        API->setFrameShadow(QFrame::Raised);
        Quit = new QPushButton(API);
        Quit->setObjectName("Quit");
        Quit->setGeometry(QRect(700, 10, 71, 24));
        Gestionnaire = new QFrame(API);
        Gestionnaire->setObjectName("Gestionnaire");
        Gestionnaire->setGeometry(QRect(20, 10, 151, 101));
        Gestionnaire->setFrameShape(QFrame::StyledPanel);
        Gestionnaire->setFrameShadow(QFrame::Raised);
        GestionnaireL = new QLabel(Gestionnaire);
        GestionnaireL->setObjectName("GestionnaireL");
        GestionnaireL->setGeometry(QRect(10, 0, 131, 16));
        BarDB = new QFrame(Gestionnaire);
        BarDB->setObjectName("BarDB");
        BarDB->setGeometry(QRect(10, 20, 131, 21));
        BarDB->setFrameShape(QFrame::StyledPanel);
        BarDB->setFrameShadow(QFrame::Raised);
        EtatDBL = new QLabel(BarDB);
        EtatDBL->setObjectName("EtatDBL");
        EtatDBL->setGeometry(QRect(40, 0, 49, 16));
        BarRequete = new QFrame(Gestionnaire);
        BarRequete->setObjectName("BarRequete");
        BarRequete->setGeometry(QRect(10, 40, 131, 21));
        BarRequete->setFrameShape(QFrame::StyledPanel);
        BarRequete->setFrameShadow(QFrame::Raised);
        EtatRequeteL = new QLabel(BarRequete);
        EtatRequeteL->setObjectName("EtatRequeteL");
        EtatRequeteL->setGeometry(QRect(10, 0, 111, 16));
        RegistreL = new QLabel(Gestionnaire);
        RegistreL->setObjectName("RegistreL");
        RegistreL->setGeometry(QRect(10, 60, 51, 21));
        IndicationRegistre = new QLabel(Gestionnaire);
        IndicationRegistre->setObjectName("IndicationRegistre");
        IndicationRegistre->setGeometry(QRect(70, 60, 16, 20));
        Log = new QPushButton(Gestionnaire);
        Log->setObjectName("Log");
        Log->setGeometry(QRect(90, 70, 41, 24));
        Menu = new QComboBox(API);
        Menu->addItem(QString());
        Menu->addItem(QString());
        Menu->addItem(QString());
        Menu->addItem(QString());
        Menu->setObjectName("Menu");
        Menu->setGeometry(QRect(180, 10, 121, 41));
        Selection = new QComboBox(API);
        Selection->setObjectName("Selection");
        Selection->setGeometry(QRect(180, 60, 121, 41));
        RequestLine = new QLineEdit(API);
        RequestLine->setObjectName("RequestLine");
        RequestLine->setGeometry(QRect(310, 10, 381, 91));
        Drop = new QPushButton(API);
        Drop->setObjectName("Drop");
        Drop->setGeometry(QRect(700, 50, 71, 51));
        AfficheSQL = new QTableView(API);
        AfficheSQL->setObjectName("AfficheSQL");
        AfficheSQL->setGeometry(QRect(210, 160, 491, 321));
        ListeTable = new QTableView(API);
        ListeTable->setObjectName("ListeTable");
        ListeTable->setGeometry(QRect(10, 190, 191, 271));
        CompleteInfo = new QLineEdit(API);
        CompleteInfo->setObjectName("CompleteInfo");
        CompleteInfo->setGeometry(QRect(310, 10, 381, 91));
        Topic = new QLabel(API);
        Topic->setObjectName("Topic");
        Topic->setGeometry(QRect(310, 10, 381, 16));
        TableSelectionner = new QLabel(API);
        TableSelectionner->setObjectName("TableSelectionner");
        TableSelectionner->setGeometry(QRect(410, 100, 111, 20));
        label = new QLabel(API);
        label->setObjectName("label");
        label->setGeometry(QRect(310, 100, 91, 21));
        tabWidget->addTab(TabMain, QString());
        TabLog = new QWidget();
        TabLog->setObjectName("TabLog");
        MenuLog = new QTabWidget(TabLog);
        MenuLog->setObjectName("MenuLog");
        MenuLog->setGeometry(QRect(40, 30, 661, 431));
        SQL = new QWidget();
        SQL->setObjectName("SQL");
        LogSQL = new QTextEdit(SQL);
        LogSQL->setObjectName("LogSQL");
        LogSQL->setGeometry(QRect(10, 10, 631, 381));
        MenuLog->addTab(SQL, QString());
        DataBase = new QWidget();
        DataBase->setObjectName("DataBase");
        LogDB = new QTextEdit(DataBase);
        LogDB->setObjectName("LogDB");
        LogDB->setGeometry(QRect(10, 10, 631, 381));
        MenuLog->addTab(DataBase, QString());
        Clear = new QPushButton(TabLog);
        Clear->setObjectName("Clear");
        Clear->setGeometry(QRect(520, 470, 75, 24));
        Sauvegarder = new QPushButton(TabLog);
        Sauvegarder->setObjectName("Sauvegarder");
        Sauvegarder->setGeometry(QRect(610, 470, 75, 24));
        tabWidget->addTab(TabLog, QString());
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);
        MenuLog->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        Quit->setText(QCoreApplication::translate("MainWindow", "Quit", nullptr));
        GestionnaireL->setText(QCoreApplication::translate("MainWindow", "        State manager", nullptr));
        EtatDBL->setText(QCoreApplication::translate("MainWindow", "DataBase", nullptr));
        EtatRequeteL->setText(QCoreApplication::translate("MainWindow", "          Request", nullptr));
        RegistreL->setText(QCoreApplication::translate("MainWindow", "Register", nullptr));
        IndicationRegistre->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        Log->setText(QCoreApplication::translate("MainWindow", "Log", nullptr));
        Menu->setItemText(0, QCoreApplication::translate("MainWindow", "Choise selection", nullptr));
        Menu->setItemText(1, QCoreApplication::translate("MainWindow", "Affichage", nullptr));
        Menu->setItemText(2, QCoreApplication::translate("MainWindow", "Interaction", nullptr));
        Menu->setItemText(3, QCoreApplication::translate("MainWindow", "Autonomie", nullptr));

        Drop->setText(QCoreApplication::translate("MainWindow", "Drop", nullptr));
        Topic->setText(QString());
        TableSelectionner->setText(QString());
        label->setText(QCoreApplication::translate("MainWindow", "Table selection : ", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(TabMain), QCoreApplication::translate("MainWindow", "API", nullptr));
        MenuLog->setTabText(MenuLog->indexOf(SQL), QCoreApplication::translate("MainWindow", "Log SQL", nullptr));
        MenuLog->setTabText(MenuLog->indexOf(DataBase), QCoreApplication::translate("MainWindow", "Log DataBase", nullptr));
        Clear->setText(QCoreApplication::translate("MainWindow", "Clear", nullptr));
        Sauvegarder->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(TabLog), QCoreApplication::translate("MainWindow", "LOGS", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
