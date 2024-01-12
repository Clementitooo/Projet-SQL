#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>
#include <QtSql>
#include <QString>
#include <QSqlDatabase>
#include <QDebug>


#include "QDialog"
#include "QTextEdit"
#include "QVBoxLayout"
#include "QDateTimeEdit"
#include "QMessageBox"

using namespace std;
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void Connexion();
    void GetLogin(QString,QString,QString,QString);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QString Request;
    QSqlDatabase db;
    QString ChoixMenu;
    int Register;
    int VerificationTable;
    QDialog Logs;
    QTextEdit TextLogs;
    QString Table;
    QString RecupID;
    QString TypeVariable;

    QString test;
    QString setHostName; //ip serveur mysql
    QString DatabaseName; // nom de la base
    QString UserName; // nom utilisateur
    QString Password; // mot de passe



public slots:
    //void EnableConnexion(); //Connexion a la base de donnee
    //void LaunchConnexion(); //Lance la tentative de connexion

    void Openlog(); //Ouvre la fenêtre secondaire de log
    void SaveRequest(); //Genère une "sauvegarde" dans les logs

    void RecupMenu(QString); //Recupère la selection de la ComboBox Menu
    void RecupSelection(QString); //Affiche les options possibles en fonction de RecupMenu

    void SelectionTable(const QModelIndex&); //Recupere le nom de la table selectionner

    void ExecuterRequete(); //Execute la requete SQL
    void ActualiserShowTable(); //Effectue une requete Show Table pour le QTableView de gauche
};

#endif // MAINWINDOW_H


