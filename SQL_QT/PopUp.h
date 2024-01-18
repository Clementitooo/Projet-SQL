#ifndef POPUP_H
#define POPUP_H

#include <QDialog>
#include <QtSql>
#include <QString>
#include <QSqlDatabase>
#include <QDebug>

#include <QInputDialog>
#include <QTimer>

using namespace std;
QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class PopUp : public QDialog
{
    Q_OBJECT
public:
    PopUp(QWidget *parent = nullptr);
private :
    Ui::Dialog *ui;
    QSqlDatabase db;
    int EtatConnexion;

signals:

private slots:
    void LaunchConnexion();
    void SetValue();
    void SetStatus();
    void Start();
};

#endif // POPUP_H
