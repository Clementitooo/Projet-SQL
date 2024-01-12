#include "mainwindow.h"
#include "./ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //NOM DES FENETRES
    MainWindow::setWindowTitle("MySQL APP");
    Logs.setWindowTitle("Logs MySQL");

    QVBoxLayout *FenetreSecondaire=new QVBoxLayout(&Logs);
    FenetreSecondaire->addWidget(&TextLogs);

    //PAMETRAGE EN LECTURE SEULE DES LOGS
    TextLogs.setReadOnly(true);
    //AUTOMATISATION DES SAUTS DE LIGNES
    TextLogs.setLineWrapMode(QTextEdit::WidgetWidth);

    //INITIALISATION DES FRAMES----
    ui->BarRequete->setStyleSheet("border: 1px solid black;");
    ui->BarDB->setStyleSheet("border: 1px solid black;");
    ui->API->setStyleSheet("border: 1px solid black;");
    ui->Gestionnaire->setStyleSheet("border: 1px solid black;");

    //Retrait des bordures pour les labels
    ui->GestionnaireL->setStyleSheet("QLabel { border: none; }");
    ui->IndicationRegistre->setStyleSheet("QLabel { border: none; }");
    ui->RegistreL->setStyleSheet("QLabel { border: none; }");
    //ui->Affiche->setStyleSheet("QLabel { border: none; }");--->Cadre de lecture
    ui->EtatDBL->setStyleSheet("QLabel { border: none; }");
    ui->EtatRequeteL->setStyleSheet("QLabel { border: none; }");

    //Signaux Boutons---
    connect(ui->Quit,SIGNAL(clicked()),qApp,SLOT(quit()));

    //SIGNAUX SQL
    connect(ui->Drop,SIGNAL(clicked()),this,SLOT(SaveRequest()));
    connect(ui->Drop,SIGNAL(clicked()),this,SLOT(ExecuterRequete()));
    connect(ui->Log,SIGNAL(clicked()),this,SLOT(Openlog()));

    connect(ui->ListeTable, &QTableView::doubleClicked, this, [=](const QModelIndex &index) {
        SelectionTable(index);
    });


    //Signaux Menus---
    connect(ui->Menu,SIGNAL(currentTextChanged(QString)),this,SLOT(RecupMenu(QString)));
    connect(ui->Selection,SIGNAL(currentTextChanged(QString)),this,SLOT(RecupSelection(QString)));

    //Affichage du premier show table
    ui->BarDB->setStyleSheet("background-color:lightgreen");

}


MainWindow::~MainWindow()
{
    delete ui;
}


//[!]Chaques fonction a une description dans le fichier .h

//---------------------------------------------------
//------------------- Interface ---------------------
//---------------------------------------------------




void MainWindow::SelectionTable(const QModelIndex &index)
{
   if (index.isValid()) {
        QVariant selectedValue = ui->ListeTable->model()->data(index, Qt::DisplayRole);
            Table=selectedValue.toString();
            qDebug() << "Valeur sélectionnée : " << selectedValue.toString();
}
   //Actualisation de la table pour la requete ------->non utiliser
   //QString test = ui->Selection->currentText();
   //RecupSelection(test);

   //Affichage de la table selectionner
   if (Table.size()==NULL)
            QMessageBox::information(this,QString("InfoBox"),QString("DoubleCliquer sur une table pour utiliser les interactions"));
   else
            ui->TableSelectionner->setText(Table);

   VerificationTable=0;
}


void MainWindow::SaveRequest(){
    QDateTime Horodotage = QDateTime::currentDateTime();
    QString Converter = Horodotage.toString("dddd, d MMMM yyyy hh:mm:ss");

    TextLogs.append(Converter);
    TextLogs.append("Request : "+ Request);
}

void MainWindow::Openlog(){
    Logs.show();
}



//------------------------------------------------------------
//-----------------Identification de registre-----------------
//------------------------------------------------------------
void MainWindow::RecupMenu(QString Text){
    ui->Selection->clear();
    //Filtre des menus pour afficher les selections possibles
    if (Text =="Affichage") {
        ChoixMenu="Affichage";
        ui->Selection->addItem("Choisir Selection");
        ui->Selection->addItem("LIGNE COUNT");
        ui->Selection->addItem("DESCRIBE");
        ui->Selection->addItem("SELECT");
    }

    if (Text =="Interaction") {
        ChoixMenu="Interaction";
        ui->Selection->addItem("Choisir Selection");
        ui->Selection->addItem("Ajouter colonne");
        ui->Selection->addItem("Supprimer une table");
        ui->Selection->addItem("Supprimer colonne");

    }

    if (Text =="Autonomie") {
        ChoixMenu="Autonomie";
        ui->Selection->addItem("Choisir Selection");
        ui->Selection->addItem("Mode Developper");
    }

}



void MainWindow::RecupSelection(QString Selec){
    //MISE EN PLACE DU REGISTRE AFFICHAGE-------------------
    ui->CompleteInfo->show();
    ui->Topic->show();
    ui->RequestLine->close();
    ui->Topic->setText("");
    if (ChoixMenu=="Affichage"){
        if (Selec=="LIGNE COUNT"){
            Request="SELECT COUNT(*) FROM "+ Table;
            Register=11;
        }
        else if(Selec=="DESCRIBE"){
            Request="DESCRIBE " + Table;
            Register=12;
        }
        else if(Selec=="SELECT"){
            Request="SELECT * FROM " + Table;
            Register=13;
        }
    }

    //MISE EN PLACE DU REGISTRE Interaction-------------------
    if (ChoixMenu=="Interaction"){
        if (Selec=="Ajouter colonne"){
            ui->Topic->setText("Renseignez le nom de la colonne et son type, ex : Prenom VARCHAR(80");
            Register=21;
        }

        if (Selec=="Supprimer une table"){
            Request="DROP TABLE " + Table;
            Register=22;
        }

        if (Selec=="Supprimer colonne"){
            ui->Topic->setText("Renseignez le nom de la colonne a supprimer");
            Register=23;
        }
    }

    //MISE EN PLACE DU REGSITRE Interaction-------------------
    if (ChoixMenu=="Autonomie"){
        if (Selec=="Mode Developper"){
            //Afficher la RequestLine
            ui->CompleteInfo->close();
            ui->Topic->close();
            ui->RequestLine->show();
            Register=31;
        }
    }
    //REGISTRE PAR DEFAUT
    if(Selec=="Choisir Selection"){
        Register=0;
    }

    //Afficheur de registre
    QString AfficheRegister="";
    AfficheRegister=QString::number(Register);
    ui->IndicationRegistre->setText(AfficheRegister);
}




//---------------------------------------------------
//---------------------- SQL ------------------------
//---------------------------------------------------

void MainWindow::GetLogin(QString Ip,QString DbName,QString User,QString MDP){
   setHostName=Ip;
   DatabaseName=DbName;
   UserName=User;
   Password=MDP;

   ActualiserShowTable();
}

void MainWindow::ExecuterRequete(){

    //Alerte de selection
    if (Table.size()==NULL)
        QMessageBox::information(this,QString("InfoBox"),QString("DoubleCliquer sur une table pour utiliser les interactions"));


    QString RecupTxt;
    //FILTRE REGISTRE SI NECESSAIRE (selon la requete)
    if (VerificationTable==0){
        Request=Request + " " + Table;
        VerificationTable=1;
    }
    if (Register==21){
        RecupTxt=ui->CompleteInfo->text();
        Request = "ALTER TABLE "+ Table +" ADD COLUMN " + RecupTxt;
        ui->Topic->setText("Ajout..");
        ui->Topic->setText(Request);
    }
    if (Register==23){
        RecupTxt=ui->CompleteInfo->text();
        Request = "ALTER TABLE "+ Table +" DROP COLUMN " + RecupTxt;
        ui->Topic->setText("Suppression..");
        ui->Topic->setText(Request);
    }
    if (Register==31){
        Request=ui->RequestLine->text();
    }


    // instanciation de la variable db
    db = QSqlDatabase::addDatabase("QMYSQL");

    // définition des paramètres de connexion à la base de données
    db.setHostName(setHostName); // @ip serveur mysql
    db.setDatabaseName(DatabaseName); // nom de la base
    db.setUserName(UserName); // nom utilisateur
    db.setPassword(Password); // mot de passe


    //CONNEXION DB

    //CONNECTER A LA DB------------
    if(db.open()) {

        qDebug() << "ok - ouverture de la base de donnée";
                    ui->BarDB->setStyleSheet("background-color:lightgreen");

        QSqlQueryModel *Requete=new QSqlQueryModel;
        Requete->setQuery(Request);

        ui->AfficheSQL->setModel(Requete);
        ui->AfficheSQL->show();

        ui->BarRequete->setStyleSheet("background-color:lightgreen");

        if (Requete->lastError().isValid()) {
            qDebug() << "echec de la requête";
                qDebug() << Requete->lastError();

            TextLogs.append("Error : " + Requete->lastError().text());
            ui->BarRequete->setStyleSheet("background-color:red");

            //Alerte sur l erreur
            QMessageBox::warning(this,QString("InfoBox"),Requete->lastError().text());
        }
        ui->ListeTable->reset();
        QSqlQueryModel *Affichage=new QSqlQueryModel;
        Affichage->setQuery("show tables;");

        ui->ListeTable->setModel(Affichage);
        ui->ListeTable->show();
        db.close();

    }

    //ERREUR CONNEXION DB-----------------------------------------------
    else {
        qDebug() << "echec d'ouverture de la base de donnée";
            qDebug() << db.lastError();

        //Actualisation status DB
        ui->BarDB->setStyleSheet("background-color:red");

        QString RecupErreur=db.lastError().text();
        TextLogs.append("ErreurDB : " + RecupErreur);

        qDebug() << QSqlDatabase::drivers();
        //Alerte sur l erreur
        QMessageBox::warning(this,QString("InfoBox"),RecupErreur);
    }

    TextLogs.append("--");
}


void MainWindow::ActualiserShowTable(){
    db = QSqlDatabase::addDatabase("QMYSQL");
    // définition des paramètres de connexion à la base de données
    db.setHostName(setHostName); // @ip serveur mysql
    db.setDatabaseName(DatabaseName); // nom de la base
    db.setUserName(UserName); // nom utilisateur
    db.setPassword(Password); // mot de passe

    if(db.open()) {
        ui->ListeTable->reset();
        QSqlQueryModel *Affichage=new QSqlQueryModel;
        Affichage->setQuery("show tables;");

        ui->ListeTable->setModel(Affichage);
        ui->ListeTable->show();

    }
    db.close();


}
