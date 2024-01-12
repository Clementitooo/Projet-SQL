#include "PopUp.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PopUp z;
    z.show();
    //w.show();
    return a.exec();
}
