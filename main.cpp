#include <QApplication>
#include <QPushButton>
#include <QWidget>
#include"fenetrenouvelleville.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    FenetreNouvelleVille fenetre;
    fenetre.show();


    return app.exec();
}
