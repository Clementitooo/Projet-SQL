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
    connect(ui->Confirmation,SIGNAL(clicked()),this,SLOT(SetStatus()));
    connect(ui->Default,SIGNAL(clicked()),this,SLOT(SetValue()));
}


void PopUp::SetValue(){
    QString Verif = QInputDialog::getText(this, "Mot clef", "Entrez le mot clef :", QLineEdit::Password);

    if(Verif=="Garou"){
    ui->DbIP->setText("10.10.10.1");
    ui->DbMDP->setText("c.barjolle");
    ui->DbName->setText("c.barjolle");
    ui->DbUser->setText("c.barjolle");
    }
    else
    QMessageBox::critical(this, "Erreur", "Mot clef incorrect. Réessayez.");
}


void PopUp::SetStatus(){
    ui->EtatDBL->setFrameStyle(QFrame::Box | QFrame::Raised);
    ui->EtatDBL->setLineWidth(1);
    ui->EtatDBL->setMidLineWidth(0);

    if (EtatConnexion ==1){ui->EtatDBL->setStyleSheet("background-color:orange");ui->EtatDBL->setText("Connect..");QApplication::processEvents();Start();}
    if (EtatConnexion ==0){ui->EtatDBL->setStyleSheet("background-color:red");ui->EtatDBL->setText("Failure..");QApplication::processEvents();ui->Confirmation->setEnabled(true);}
}



void PopUp::LaunchConnexion() {
    ui->Confirmation->setEnabled(false);
    QApplication::processEvents();

    if (EtatConnexion == 0) {
    db = QSqlDatabase::addDatabase("QMYSQL");

    // Définition des paramètres de connexion à la base de données
    db.setHostName(ui->DbIP->text());
    db.setDatabaseName(ui->DbName->text());
    db.setUserName(ui->DbUser->text());
    db.setPassword(ui->DbMDP->text());

    // Connexion à la base de données

    if (db.open()) {
        EtatConnexion = 1;
    } else {
        EtatConnexion = 0;
    }
    }
    db.close();
}


void PopUp::Start(){
    QThread::msleep(2500);
    ui->EtatDBL->setStyleSheet("background-color:lightgreen");
    QApplication::processEvents();

    // Récupération des logins
    QString Ip = ui->DbIP->text();
    QString DbName = ui->DbName->text();
    QString User = ui->DbUser->text();
    QString DbMDP = ui->DbMDP->text();

    // Ouverture du logiciel
    MainWindow *w = new MainWindow;
    w->GetLogin(Ip, DbName, User, DbMDP);
    w->show();
    this->close();
    }




