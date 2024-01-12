#include "PopUp.h"
#include "./ui_PopUp.h"
#include "MainWindow.h"

PopUp::PopUp(QWidget *parent)
    : QDialog{parent}
    , ui(new Ui::Dialog)
{
        ui->setupUi(this);

    //Génération de la police
    QFont texte;
    texte.setBold(true);
    texte.setPointSize(texte.pointSize()+5);

    //Mise en place de la police
    ui->A->setFont(texte);
    ui->B->setFont(texte);
    ui->C->setFont(texte);
    ui->D->setFont(texte);

    //Camouflage des charactères de MDP
    ui->DbMDP->setEchoMode(QLineEdit::Password);

    //Initialisation de la variable de validation de connexion
    EtatConnexion=0;

    connect(ui->Confirmation,SIGNAL(clicked()),this,SLOT(LaunchConnexion()));
}






void PopUp::LaunchConnexion(){
    if (EtatConnexion==0){
    db = QSqlDatabase::addDatabase("QMYSQL");

    // définition des paramètres de connexion à la base de données
    db.setHostName(ui->DbIP->text()); // @ip serveur mysql
    db.setDatabaseName(ui->DbName->text()); // nom de la base
    db.setUserName(ui->DbUser->text()); // nom utilisateur
    db.setPassword(ui->DbMDP->text()); // mot de passe


    //CONNEXION DB

    if(db.open()) {
        ui->BarDB->setStyleSheet("background-color:lightgreen");
        ui->EtatDBL->setText("Connect..");
        EtatConnexion=1;
        }
        else {
        ui->BarDB->setStyleSheet("background-color:red");
        ui->EtatDBL->setText("Failure..");
        EtatConnexion=0;
        }
    db.close();
    }
    if (EtatConnexion==1){
    ui->BarDB->setStyleSheet("background-color:orange");

    //Recuperation des logins
    QString Ip=ui->DbIP->text();
    QString DbName=ui->DbName->text();
    QString User=ui->DbUser->text();
    QString DbMDP=ui->DbMDP->text();


    //Ouverture du logiciel
    MainWindow *w=new MainWindow;
    w->GetLogin(Ip,DbName,User,DbMDP);
    w->show();
    this->close();
    }
}





